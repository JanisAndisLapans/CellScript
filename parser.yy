%skeleton "lalr1.cc" //c++
%require "3.8.2"
%debug
%defines
%define api.value.type variant
%define parse.assert
%define api.namespace {CS}
%define api.parser.class {CS_Parser}
%locations

%define parse.error verbose

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

    vector<Data> const_stack;

}

%token<string> DEC
%token<string> STR
%token ONE_LINE_COMMENT
%token PLUS MINUS TIMES DIVIDE POWER ASSIGN MOD
%token EQUAL LESS_THAN GREATER_THAN LESS_THAN_EQ GREATER_THAN_EQ NOT NOT_EQUAL
%token CONST SELF
%token AND OR XOR NEITHER
%token ADVANCE BREAK CONTINUE BREAK_ALL REPEAT RETURN
%token TRUE FALSE NULL_TOKEN INF
%token LEFT_PARENTHESES RIGHT_PARENTHESES
%token EOL
%token STOP
%token<string> ID
%token IF ELSE ELIF ENDIF PRINT FOR BY TO ENDFOR FUNC ENDFUNC
%token COLUMN COMMA

%type<shared_ptr<Expression>> expr
%type<Data> const_expr;
%nterm<shared_ptr<Statement>> statement
%nterm<shared_ptr<Program>> program;
%nterm<vector<pair<shared_ptr<Expression>, shared_ptr<Program>>>> elif_branch
%nterm<shared_ptr<IfStatement>> if_statement
%nterm<shared_ptr<ForCounterLoop>> for_counter_loop
%nterm<shared_ptr<AssignStatement>> assignment
%nterm<shared_ptr<FunctionStatement>> function_call
%type<shared_ptr<Function>> function
%type<vector<string>> id_list
%type<vector<shared_ptr<Expression>>> expr_list

/*
    Darb??bu sec??ba
*/ 

%left IF ELSE ELIF ENDIF FOR BY TO COLUMN CONST ADVANCE RETURN GIVE
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
    if(interpreter.is_sep_scope())
        $$ = make_shared<Program>(interpreter.get_scope_number(),interpreter.get_top_scope_size());
    else
      $$ = make_shared<Program>(interpreter.get_scope_number());  
}
| program statement EOL{
    if($2 != nullptr)
    {
        $1->attach_statement($2);
    }
    $$ = $1;
    $1->set_callstack_size(interpreter.get_top_scope_size());
}
| program statement ONE_LINE_COMMENT EOL{
    if($2 != nullptr)
    {
        $1->attach_statement($2);
    }
    $$ = $1;
    $1->set_callstack_size(interpreter.get_top_scope_size());
}
| program EOL{
    $$ = $1;
}
| program ONE_LINE_COMMENT EOL{
    $$ = $1;
}
;

statement: assignment {
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
    $$ = make_shared<Advance>(make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))));
}
| REPEAT{
    if(!interpreter.in_loop())
    {
        cout << "ERROR: REPEAT statement outside loop" << endl;
    }
    $$ = make_shared<Advance>(make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))));
}
| RETURN{
    $$ = make_shared<Return>(make_shared<LiteralExpression>(make_shared<Data>(make_shared<NullType>())));
}
| RETURN expr{
    $$ = make_shared<Return>($2);
}
| GIVE expr{
    $$ = make_shared<Give>($2);
}
| function_call{
    $$ = $1;
}
;

function_call: expr LEFT_PARENTHESES expr_list RIGHT_PARENTHESES { 
    $$ = make_shared<FunctionStatement>($3, $1); 
}
| SELF LEFT_PARENTHESES expr_list RIGHT_PARENTHESES{
    if(auto func = interpreter.get_curr_function())
    {
        $$ = make_shared<FunctionStatement>($3, make_shared<LiteralExpression>(make_shared<Data>(func))); 
    }
    else
    {
        cout << "Attempt to call SELF in global scope" << endl;
        return 1;
    }

}
;

assignment: ID ASSIGN 
<int>{
    bool non_declared;
    $$ = interpreter.get_variable($1, non_declared);
    if(!non_declared)
    {
        if(interpreter.is_const($1))
        {
            cout << "ERROR: variable declared CONST in this scope, cannot be altered" <<endl;
            return 1;
        }
    }
    else
    {
        $$ = interpreter.declare_variable($1);
    }
}
expr{
    $$ = make_shared<AssignStatement>($3, $4);
}
| CONST ID ASSIGN
<DataPtr>{
    bool non_declared;
    interpreter.get_variable($2, non_declared);
    if(!non_declared || interpreter.is_const($2))
    {
        cout << "ERROR: variable was already declared in this scope." << endl;
        return 1;
    }
    else
    {
        $$ = interpreter.declare_const_variable($2);
    }
}
const_expr{
    *$4 = $5;
    $$ = nullptr;
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
    $5.push_back(make_pair($2, make_shared<Program>($4, interpreter.get_scope_number(), 1)));
    $$ = make_shared<IfStatement>(move($5));
}
| IF expr COLUMN statement elif_branch ELSE COLUMN EOL program ENDIF {
    $5.push_back(make_pair($2, make_shared<Program>($4, interpreter.get_scope_number(), 1)));
    $$ = make_shared<IfStatement>(move($5), $9);
}
| IF expr COLUMN EOL program elif_branch ELSE COLUMN statement ENDIF {
    $6.push_back(make_pair($2, $5));
    $$ = make_shared<IfStatement>(move($6), make_shared<Program>($9, interpreter.get_scope_number(), 1));
}
| IF expr COLUMN statement elif_branch ELSE COLUMN statement ENDIF {
    $5.push_back(make_pair($2, make_shared<Program>($4, interpreter.get_scope_number(), 1)));
    $$ = make_shared<IfStatement>(move($5), make_shared<Program>($8, interpreter.get_scope_number(), 1));
}
;

for_counter_loop: FOR ID ASSIGN expr TO expr BY expr COLUMN EOL
<int>{
    //Deklar?? skait??t??ja main??go, ja neeksist??
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {
        $$ = var;
    }
    else
    {
        $$ = interpreter.declare_variable($2);
    }
}
 program ENDFOR{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($11, $4, $6, $8, $12);
    interpreter.mark_is_in_loop(false);
}
| FOR ID ASSIGN expr TO expr BY expr COLUMN
<int>{
    //Deklar?? skait??t??ja main??go, ja neeksist??
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {
        $$ = var;
    }
    else
    {
        $$ = interpreter.declare_variable($2);
    }
}
 statement ENDFOR{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($10, $4, $6, $8, make_shared<Program>($11, interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
| FOR ID ASSIGN expr TO expr COLUMN EOL
<int>{
    //Deklar?? skait??t??ja main??go, ja neeksist??
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {
        $$ = var;
    }
    else
    {
        $$ = interpreter.declare_variable($2);
    }
}
program ENDFOR{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($9, $4, $6, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), $10);
    interpreter.mark_is_in_loop(false);
}
| FOR ID ASSIGN expr TO expr COLUMN
<int>{
    //Deklar?? skait??t??ja main??go, ja neeksist??
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {
        $$ = var;
    }
    else
    {
        $$ = interpreter.declare_variable($2);
    }
}
statement ENDFOR{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($8, $4, $6, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), make_shared<Program>($9, interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
| FOR ID TO expr COLUMN EOL
<int>{
    //Deklar?? skait??t??ja main??go, ja neeksist??
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {                
        $$ = var;
    }
    else
    {        
        $$ = interpreter.declare_variable($2);
    }
}
program ENDFOR{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($7, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), $4, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), $8);
    interpreter.mark_is_in_loop(false);
}
| FOR ID TO expr COLUMN 
<int>{
    //Deklar?? skait??t??ja main??go, ja neeksist??
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {
        $$ = var;
    }
    else
    {
        $$ = interpreter.declare_variable($2);
    }
}
statement ENDFOR{
    
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($6, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), $4, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), make_shared<Program>($7, interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
| FOR ID TO expr BY expr COLUMN EOL
<int>{
    //Deklar?? skait??t??ja main??go, ja neeksist??
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {
        $$ = var;
    }
    else
    {
        $$ = interpreter.declare_variable($2);
    }
}
program ENDFOR{

    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($9, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), $4, $6, $10);
    interpreter.mark_is_in_loop(false);
}
| FOR ID TO expr BY expr COLUMN
<int>{
    //Deklar?? skait??t??ja main??go, ja neeksist??
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable($2, non_declared);
    if(!non_declared)
    {
        $$ = var;
    }
    else
    {
        $$ = interpreter.declare_variable($2);
    }
}
 statement ENDFOR{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($8, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), $4, $6, make_shared<Program>($9, interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
;

elif_branch: %empty {$$ = vector<pair<shared_ptr<Expression>, shared_ptr<Program>>>(); }
| ELIF expr COLUMN EOL program elif_branch {
    $6.push_back(make_pair($2, $5));
    $$ = move($6);
}
| ELIF expr COLUMN statement elif_branch {
    $5.push_back(make_pair($2, make_shared<Program>($4, interpreter.get_scope_number(), 1)));
    $$ = move($5);
}
;

expr: ID {
    bool non_declared;
    if(interpreter.is_const($1))
    {
        $$ = make_shared<LiteralExpression>(interpreter.get_const_val($1, non_declared));
    }
    else
    {
        auto var = interpreter.get_variable($1, non_declared);
        if(!non_declared)
        {
            $$ = make_shared<VariableExpression>(var, string($1));
        }
        else
        {
            cout << "ERROR: variable " << $1 << " not declared in this scope." <<endl;
            return 1;
        }
    }
}
| const_expr { $$ = make_shared<LiteralExpression>(make_shared<Data>($1)); }
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
| if_statement { $$ = make_shared<StatementExpression> ($1); }
| function_call { $$ = make_shared<StatementExpression> ($1); }
| assignment { $$ = make_shared<StatementExpression> ($1); }
;

const_expr: DEC { $$ = make_shared<Number>($1); }
| STR { $$ = make_shared<String>(move($1)); }
| TRUE { $$ = make_shared<Boolean>(true); }
| FALSE { $$ = make_shared<Boolean>(false); }
| NULL_TOKEN { $$ = make_shared<NullType>(); }
| INF { $$ = make_shared<InfType>(); }
| ID{
    bool non_declared;
    if(interpreter.is_const($1))
    {
        $$ = *interpreter.get_const_val($1, non_declared);
    }
    else{
        cout << "Variable " << $1 << " is not declared CONST" << ", only CONST values may be assigned to CONST variables." <<endl;
        return 1;
    }
} 
|function { $$ = $1; }
| const_expr PLUS const_expr {$$ = BinaryExpression(make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::ADD).eval(const_stack);}
| const_expr MINUS const_expr {$$ = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::SUB).eval(const_stack);}
| const_expr TIMES const_expr {$$ = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::MULT).eval(const_stack);}
| const_expr MOD const_expr {$$ = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::MOD).eval(const_stack);}
| const_expr DIVIDE const_expr {$$ = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::DIV).eval(const_stack);}
| const_expr POWER const_expr {$$ = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::POW).eval(const_stack);}
| const_expr EQUAL const_expr {$$ = BinaryExpression(make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::EQ).eval(const_stack);}
| const_expr NOT_EQUAL const_expr {$$ = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::NEQ).eval(const_stack);}
| const_expr GREATER_THAN const_expr {$$ = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::GT).eval(const_stack);}
| const_expr LESS_THAN const_expr {$$ = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::LT).eval(const_stack);}
| const_expr GREATER_THAN_EQ const_expr {$$ = BinaryExpression(make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::EQ_GT).eval(const_stack);}
| const_expr LESS_THAN_EQ const_expr {$$ = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::EQ_LT).eval(const_stack);}
| const_expr AND const_expr {$$ = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::AND).eval(const_stack);}
| const_expr OR const_expr {$$ = BinaryExpression(make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::OR).eval(const_stack);}
| const_expr XOR const_expr {$$ = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::XOR).eval(const_stack);}
| const_expr NEITHER const_expr {$$ = BinaryExpression(make_shared<LiteralExpression>(make_shared<Data>($1)),make_shared<LiteralExpression>(make_shared<Data>($3)), BinaryExpression::NEITHER).eval(const_stack);}
| MINUS const_expr {$$ = UnaryExpression (make_shared<LiteralExpression>(make_shared<Data>($2)), UnaryExpression::INV).eval(const_stack);}
| NOT const_expr {$$ = UnaryExpression (make_shared<LiteralExpression>(make_shared<Data>($2)), UnaryExpression::NOT).eval(const_stack);}
| LEFT_PARENTHESES const_expr RIGHT_PARENTHESES {$$ = $2;}
;

expr_list: %empty { $$ = vector<shared_ptr<Expression>>(); }
| expr COMMA expr_list {
    $3.push_back($1);
    $$ = move($3);
}
| expr { $$ = {$1}; }
;

function: FUNC LEFT_PARENTHESES id_list RIGHT_PARENTHESES COLUMN EOL
<shared_ptr<Function>>
{
    interpreter.make_new_scope();
    vector<int> arg_inds;
    for(const auto& id_name : $3)
    {
        if(interpreter.is_const(id_name))
        {
            cout << id_name << " declared const, cannot be used as an argument name." << endl;
            return 1;
        }
        bool non_declared;
        interpreter.get_variable(id_name, non_declared);
        if(!non_declared)
        {
            cout << id_name << " reused in function argument names" <<endl;
            return 1;
        }
        arg_inds.push_back(interpreter.declare_variable(id_name));
    }
    $$ = make_shared<Function>(arg_inds);
    interpreter.push_function($$);
}
program ENDFUNC{
    $7->attach_program($8);
    $$ = $7;
    interpreter.pop_scope();
    interpreter.pop_function();
}
| FUNC LEFT_PARENTHESES id_list RIGHT_PARENTHESES COLUMN
<shared_ptr<Function>>
{
    vector<int> arg_inds;
    for(const auto& id_name : $3)
    {
        if(interpreter.is_const(id_name))
        {
            cout << id_name << " declared const, cannot be used as an argument name." << endl;
            return 1;
        }
        bool non_declared;
        interpreter.get_variable(id_name, non_declared);
        if(!non_declared)
        {
            cout << id_name << " reused in function argument names" <<endl;
            return 1;
        }
        arg_inds.push_back(interpreter.declare_variable(id_name));
    }
    $$ = make_shared<Function>(arg_inds);
    interpreter.push_function($$);
}
statement ENDFUNC{
    $6->attach_program(make_shared<Program>($7, interpreter.get_scope_number(), 1 + $6->arg_count()));
    $$ = $6;
    interpreter.pop_scope();
    interpreter.pop_function();
}
;

id_list: %empty { $$ = vector<string>(); } 
| ID COMMA id_list{
    $3.push_back($1);
    $$ = move($3);
}
| ID { $$ = {$1}; }
;
%%

void CS::CS_Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}

int main()
{
    auto lexer = make_unique<CS::CS_Scanner>(&cin);
    auto parser = make_unique<CS::CS_Parser>(*lexer);
    interpreter.make_new_scope(); //Glob??lais
    if(parser->parse() == 0) //Nav k????du
    {
        //
    }
    interpreter.pop_scope();
}