%skeleton "lalr1.cc" //c++
%require "3.8.2"
%debug
%defines
%define api.value.type variant
%define parse.assert
%define api.namespace {CS}
%define api.parser.class {CS_Parser}
%locations

%code requires{
    #include <string>
    #include <string>
    #include <vector>
    #include "datatypes.h"
    #include "program.h"
    #include "interpreter.h"

        
    namespace CS
    {
        class CS_Scanner;
    }


    // The following definitions is missing when %locations isn't used
    # ifndef YY_NULLPTR
    #  if defined __cplusplus && 201103L <= __cplusplus
    #   define YY_NULLPTR nullptr
    #  else
    #   define YY_NULLPTR 0
    #  endif
    # endif
}

%parse-param { CS::CS_Scanner  &scanner  }

%code{

    #include <memory>
    #include <map>
    #include <iostream>
    #include <string>
    #include <string>
    #include <utility>


    using namespace std;

    #include "CS_Scanner.hpp"

    Interpreter interpreter;

    #undef yylex
    #define yylex scanner.yylex

}

%token<string> DEC
%token<string> STR
%token PLUS MINUS TIMES DIVIDE POWER ASSIGN MOD
%token EQUAL LESS_THAN GREATER_THAN LESS_THAN_EQ GREATER_THAN_EQ NOT NOT_EQUAL
%token CONST
%token AND OR XOR NEITHER
%token ADVANCE BREAK CONTINUE BREAK_ALL REPEAT
%token TRUE FALSE NULL_TOKEN INF
%token LEFT_PARENTHESES RIGHT_PARENTHESES
%token EOL
%token STOP
%token<string> ID
%token IF ELSE ELIF ENDIF PRINT FOR BY TO ENDFOR FUNC ENDFUNC 
%token COLUMN, COMMA

%type<shared_ptr<Expression>> expr
%nterm<shared_ptr<Statement>> statement
%nterm<shared_ptr<Program>> program;
%nterm<vector<pair<shared_ptr<Expression>, shared_ptr<Program>>>> elif_branch
%nterm<shared_ptr<IfStatement>> if_statement
%nterm<shared_ptr<ForCounterLoop>> for_counter_loop
%nterm<shared_ptr<AssignStatement>> assignment
%type<shared_ptr<Function>> function
%type<vector<string>> id_list

/*
    Darbību secība
*/ 

%left IF ELSE ELIF ENDIF FOR BY TO COLUMN CONST ADVANCE
%left ASSIGN
%left OR XOR NEITHER
%left AND
%left EQUAL LESS_THAN GREATER_THAN LESS_THAN_EQ GREATER_THAN_EQ NOT_EQUAL
%left NOT
%left PLUS MINUS
%left TIMES DIVIDE MOD
%left POWER
%left LEFT_PARENTHESES RIGHT_PARENTHESES


//Gramatika un likumi 

%%
 
input: program STOP EOL { 
    $1->run();
    return 0;
    }
;

program: %empty {
    $$ = make_shared<Program>(interpreter.get_scope_number());
}
| program statement EOL{
    if($2 != nullptr)
    {
        $1->attach_statement($2);
    }
    $$ = $1;
}
;

statement: %empty { $$ = nullptr; }
| assignment {
    $$ = $1;
}
| PRINT expr {
    $$ = make_shared<PrintStatement>($2);
}
| if_statement {
    $$ = $1;
}
|for_counter_loop{
    $$ = $1;
}
| BREAK{
    if(!interpreter.in_loop())
    {
        cout << "ERROR: BREAK statement outside loop" << endl;
    }
    $$ = make_shared<BreakStatement>();
}
| BREAK_ALL{
    if(!interpreter.in_loop())
    {
        cout << "ERROR: BREAK ALL statement outside loop" << endl;
    }
    $$ = make_shared<BreakAll>();
}
| ADVANCE expr{
    if(!interpreter.in_loop())
    {
        cout << "ERROR: ADVANCE statement outside loop" << endl;
    }
    $$ = make_shared<Advance>($2);
}
| CONTINUE{
    if(!interpreter.in_loop())
    {
        cout << "ERROR: ADVANCE statement outside loop" << endl;
    }
    $$ = make_shared<Advance>(make_shared<ValueExpression> (make_shared<Data> (make_shared<Number>(1))));
}
| REPEAT{
    if(!interpreter.in_loop())
    {
        cout << "ERROR: REPEAT statement outside loop" << endl;
    }
    $$ = make_shared<Advance>(make_shared<ValueExpression> (make_shared<Data> (make_shared<Number>(0))));
}
;

assignment: ID ASSIGN expr{
    bool non_declared;
    auto var = interpreter.get_variable($1, non_declared);
    if(!non_declared)
    {
        if(var.is_const)
        {
            cout << "ERROR: variable declared CONST in this scope, cannot be altered" <<endl;
            return 1;
        }
    }
    else
    {
        var = interpreter.declare_variable($1, false);
    }
    $$ = make_shared<AssignStatement>(var.mem_location, $3);
}
| CONST ID ASSIGN expr{
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {
        cout << "ERROR: variable was already declared in this scope." << endl;
        return 1;
    }
    else
    {
        var = interpreter.declare_variable($2, true);
    }
    $$ = make_shared<AssignStatement>(var.mem_location, $4);
}
;

if_statement: IF expr COLUMN EOL program elif_branch ENDIF {
    $6.push_back(make_pair($2, $5));
    $$ = make_shared<IfStatement>(move($6));
}
| IF expr COLUMN EOL program elif_branch ELSE COLUMN EOL program ENDIF {
    $6.push_back(make_pair($2, $5));
    $$ = make_shared<IfStatement>(move($6), $10);
}
| IF expr COLUMN statement elif_branch ENDIF {
    $5.push_back(make_pair($2, make_shared<Program>($4, interpreter.get_scope_number())));
    $$ = make_shared<IfStatement>(move($5));
}
| IF expr COLUMN statement elif_branch ELSE COLUMN EOL program ENDIF {
    $5.push_back(make_pair($2, make_shared<Program>($4, interpreter.get_scope_number())));
    $$ = make_shared<IfStatement>(move($5), $9);
}
| IF expr COLUMN EOL program elif_branch ELSE COLUMN statement ENDIF {
    $6.push_back(make_pair($2, $5));
    $$ = make_shared<IfStatement>(move($6), make_shared<Program>($9, interpreter.get_scope_number()));
}
| IF expr COLUMN statement elif_branch ELSE COLUMN statement ENDIF {
    $5.push_back(make_pair($2, make_shared<Program>($4, interpreter.get_scope_number())));
    $$ = make_shared<IfStatement>(move($5), make_shared<Program>($8, interpreter.get_scope_number()));
}
;

for_counter_loop: FOR ID ASSIGN expr TO expr BY expr COLUMN EOL
<Interpreter::Variable>{
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {
        $$ = var;
    }
    else
    {
        $$ = interpreter.declare_variable($2, false);
    }
}
 program ENDFOR{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($11.mem_location, $4, $6, $8, $12);
    interpreter.mark_is_in_loop(false);
}
| FOR ID ASSIGN expr TO expr BY expr COLUMN
<Interpreter::Variable>{
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {
        $$ = var;
    }
    else
    {
        $$ = interpreter.declare_variable($2, false);
    }
}
 statement ENDFOR{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($10.mem_location, $4, $6, $8, make_shared<Program>($11, interpreter.get_scope_number()));
    interpreter.mark_is_in_loop(false);
}
| FOR ID ASSIGN expr TO expr COLUMN EOL
<Interpreter::Variable>{
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {
        $$ = var;
    }
    else
    {
        $$ = interpreter.declare_variable($2, false);
    }
}
program ENDFOR{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($9.mem_location, $4, $6, make_shared<ValueExpression> (make_shared<Data> (make_shared<Number>(1))), $10);
    interpreter.mark_is_in_loop(false);
}
| FOR ID ASSIGN expr TO expr COLUMN
<Interpreter::Variable>{
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {
        $$ = var;
    }
    else
    {
        $$ = interpreter.declare_variable($2, false);
    }
}
statement ENDFOR{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($8.mem_location, $4, $6, make_shared<ValueExpression> (make_shared<Data> (make_shared<Number>(1))), make_shared<Program>($9, interpreter.get_scope_number()));
    interpreter.mark_is_in_loop(false);
}
| FOR ID TO expr COLUMN EOL
<Interpreter::Variable>{
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {                
        $$ = var;
    }
    else
    {        
        $$ = interpreter.declare_variable($2, false);
    }
}
program ENDFOR{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($7.mem_location, make_shared<ValueExpression>(make_shared<Data> (make_shared<Number>(0))), $4, make_shared<ValueExpression> (make_shared<Data> (make_shared<Number>(1))), $8);
    interpreter.mark_is_in_loop(false);
}
| FOR ID TO expr COLUMN 
<Interpreter::Variable>{
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {
        $$ = var;
    }
    else
    {
        $$ = interpreter.declare_variable($2, false);
    }
}
statement ENDFOR{
    
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($6.mem_location, make_shared<ValueExpression>(make_shared<Data> (make_shared<Number>(0))), $4, make_shared<ValueExpression> (make_shared<Data> (make_shared<Number>(1))), make_shared<Program>($7, interpreter.get_scope_number()));
    interpreter.mark_is_in_loop(false);
}
| FOR ID TO expr BY expr COLUMN EOL
<Interpreter::Variable>{
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {
        $$ = var;
    }
    else
    {
        $$ = interpreter.declare_variable($2, false);
    }
}
program ENDFOR{

    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($9.mem_location, make_shared<ValueExpression>(make_shared<Data> (make_shared<Number>(0))), $4, $6, $10);
    interpreter.mark_is_in_loop(false);
}
| FOR ID TO expr BY expr COLUMN
<Interpreter::Variable>{
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {
        $$ = var;
    }
    else
    {
        $$ = interpreter.declare_variable($2, false);
    }
}
 statement ENDFOR{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($8.mem_location, make_shared<ValueExpression>(make_shared<Data> (make_shared<Number>(0))), $4, $6, make_shared<Program>($9, interpreter.get_scope_number()));
    interpreter.mark_is_in_loop(false);
}
;

elif_branch: %empty {$$ = vector<pair<shared_ptr<Expression>, shared_ptr<Program>>>(); }
| ELIF expr COLUMN EOL program elif_branch {
    $6.push_back(make_pair($2, $5));
    $$ = move($6);
}
| ELIF expr COLUMN statement elif_branch {
    $5.push_back(make_pair($2, make_shared<Program>($4, interpreter.get_scope_number())));
    $$ = move($5);
}
;

expr: DEC { $$ = make_shared<ValueExpression> (make_shared<Data> (make_shared<Number>($1))); }
| STR { $$ = make_shared<ValueExpression> (make_shared<Data> (make_shared<String>(move($1)))); }
| TRUE { $$ = make_shared<ValueExpression> (make_shared<Data> (make_shared<Boolean>(true))); }
| FALSE { $$ = make_shared<ValueExpression> (make_shared<Data> (make_shared<Boolean>(false))); }
| NULL_TOKEN { $$ = make_shared<ValueExpression> (make_shared<Data> (make_shared<NullType>())); }
| INF { $$ = make_shared<ValueExpression> (make_shared<Data> (make_shared<InfType>())); }
| ID {
    bool non_declared;
    auto var = interpreter.get_variable($1, non_declared);
    if(!non_declared)
    {
        $$ = make_shared<ValueExpression>(var.mem_location, string($1));
    }
    else
    {
        cout << "ERROR: variable not declared in this scope." <<endl;
        return 1;
    }
}
| expr PLUS expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::ADD);}
| expr MINUS expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::SUB);}
| expr TIMES expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::MULT);}
| expr MOD expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::MOD);}
| expr DIVIDE expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::DIV);}
| expr POWER expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::POW);}
| expr EQUAL expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::EQ);}
| expr NOT_EQUAL expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::NEQ);}
| expr GREATER_THAN expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::GT);}
| expr LESS_THAN expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::LT);}
| expr GREATER_THAN_EQ expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::EQ_GT);}
| expr LESS_THAN_EQ expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::EQ_LT);}
| expr AND expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::AND);}
| expr OR expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::OR);}
| expr XOR expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::XOR);}
| expr NEITHER expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::NEITHER);}
| MINUS expr {$$ = make_shared<UnaryExpression> ($2, UnaryExpression::INV);}
| NOT expr {$$ = make_shared<UnaryExpression> ($2, UnaryExpression::NOT);}
| LEFT_PARENTHESES expr RIGHT_PARENTHESES {$$ = $2;}
;

function: FUNC ID LEFT_PARENTHESES id_list RIGHT_PARENTHESES COLUMN EOL
<vector<DataPtr>>
{
    interpreter.make_new_scope();
    $$ = vector<DataPtr>();
    for(const auto& id_name : $4)
    {
        $$.push_back(interpreter.declare_variable(id_name, false).mem_location);
    }
}
program ENDFUNC{
    $$ = make_shared<Function>($8, $9);
}
| FUNC ID LEFT_PARENTHESES id_list RIGHT_PARENTHESES COLUMN
{

}
statement ENDFUNC{

}
;

id_list: ID { $$ = {$1}; }
| id_list COMMA ID{
    $1.push_back($3);
    $$ = move($1);
}
;

%%

void 
CS::CS_Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}

int main()
{
    auto lexer = make_unique<CS::CS_Scanner>(&cin);
    auto parser = make_unique<CS::CS_Parser>(*lexer);
    interpreter.make_new_scope(); //Globālais
    if(parser->parse() == 0) //Nav kļūdu
    {
        /* curr_program->run(); */
    }
    interpreter.pop_scope();
}