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
    #include <fstream>
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

    vector<Data> const_stack; // tukšs steks, ko pielieto callstack vietā konstantām operācijām

    int get_variable(string name, bool declare = true) 
    {
        bool non_declared;
        auto index = interpreter.get_variable(name, non_declared);
        if(!non_declared || interpreter.is_const(name))
        {
            if(interpreter.is_const(name))
            {
                cout << "ERROR: variable declared CONST in this scope, cannot be altered" <<endl;
                return -1;
            }
        }
        else
        {
            if(!declare) 
            {
                cout << "ERROR: variable must be declared" << endl;
                return -1;
            }
            return interpreter.declare_variable(name);
        }

        return index;
    } 
}

%token<string> DEC
%token<string> STR
%token ONE_LINE_COMMENT
%token PLUS MINUS TIMES DIVIDE POWER ASSIGN MOD PLUS_ASSIGN MINUS_ASSIGN TIMES_ASSIGN DIVIDE_ASSIGN MOD_ASSIGN
%token EQUAL LESS_THAN GREATER_THAN LESS_THAN_EQ GREATER_THAN_EQ NOT NOT_EQUAL
%token CONST SELF
%token AND OR XOR NEITHER
%token ADVANCE BREAK CONTINUE BREAK_ALL REPEAT RETURN
%token TRUE FALSE NULL_TOKEN INF
%token LEFT_PARENTHESES RIGHT_PARENTHESES
%token EOL
%token END_OF_FILE
%token<string> ID
%token IF ELSE ELIF ENDIF PRINT FOR BY TO ENDFOR FUNC ENDFUNC WHILE ENDWHILE READ
%token COLUMN COMMA
%token AS NumType BoolType StrType

%type<shared_ptr<Expression>> expr
%type<shared_ptr<Expression>> expr_val
%nterm<shared_ptr<Statement>> statement
%nterm<shared_ptr<Program>> program;
%nterm<vector<pair<shared_ptr<Expression>, shared_ptr<Program>>>> elif_branch
%nterm<shared_ptr<IfStatement>> if_statement
%nterm<shared_ptr<ForCounterLoop>> for_counter_loop
%nterm<shared_ptr<WhileLoop>> while_loop
%nterm<shared_ptr<AssignStatement>> assignment
%nterm<shared_ptr<FunctionStatement>> function_call
%type<shared_ptr<Function>> function
%type<vector<string>> id_list
%type<vector<shared_ptr<Expression>>> expr_list
/*
    Darbību secība
*/ 

%nonassoc COLUMN
%nonassoc IF ELSE ELIF ENDIF FOR BY TO CONST ADVANCE RETURN GIVE LEN
%left ASSIGN PLUS_ASSIGN MINUS_ASSIGN TIMES_ASSIGN DIVIDE_ASSIGN MOD_ASSIGN
%left OR XOR NEITHER
%left AND
%left EQUAL LESS_THAN GREATER_THAN LESS_THAN_EQ GREATER_THAN_EQ NOT_EQUAL
%left NOT
%left PLUS MINUS
%left TIMES DIVIDE MOD
%right AS
%left POWER
%left LEFT_PARENTHESES RIGHT_PARENTHESES LEFT_BRACKET RIGHT_BRACKET


//Gramatika un likumi 

%%
 
input: program END_OF_FILE { 
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
| expr LEFT_BRACKET expr RIGHT_BRACKET ASSIGN expr {
    $$ = make_shared<IndexAssignStatement>($1, $3, $6);
}
| PRINT expr_val {
    $$ = make_shared<PrintStatement>($2);

}
| READ id_list {
    vector<int> arg_inds;
    for(const auto& id_name : $2)
    {
        arg_inds.push_back(get_variable(id_name));
    }
    $$ = make_shared<ReadStatement>(arg_inds);
}
| if_statement {
    $$ = $1;
}
|for_counter_loop{
    $$ = $1;
}
| while_loop {
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

function_call: expr_val LEFT_PARENTHESES expr_list RIGHT_PARENTHESES { 
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
    $$ = get_variable($1);
    if($$ == -1) { // Error
        return 1;
    }
}
expr_val{
    $$ = make_shared<AssignStatement>($3, $4);
}
| ID PLUS_ASSIGN 
<int>{
    $$ = get_variable($1, false);
    if($$ == -1) { // Error
        return 1;
    }
}
expr_val{
    $$ = make_shared<AssignStatement>($3, $4, make_shared<PlusAssignmentOperation>());
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
expr_val{
    if(!$5->is_const())
    {
        cout << "ERROR: CONST assignment requires a CONST expression." <<endl;
        return 1;
    }

    *$4 = $5->eval(const_stack);
    $$ = nullptr;
}
;

if_statement: IF expr_val COLUMN EOL program elif_branch ENDIF {
    $6.push_back(make_pair($2, $5));
    $$ = make_shared<IfStatement>(move($6));
}
| IF expr_val COLUMN EOL program elif_branch ELSE COLUMN EOL program ENDIF {
    $6.push_back(make_pair($2, $5));
    $$ = make_shared<IfStatement>(move($6), $10);
}
| IF expr_val COLUMN statement elif_branch ENDIF {
    $5.push_back(make_pair($2, make_shared<Program>($4, interpreter.get_scope_number(), 1)));
    $$ = make_shared<IfStatement>(move($5));
}
| IF expr_val COLUMN statement elif_branch ELSE COLUMN EOL program ENDIF {
    $5.push_back(make_pair($2, make_shared<Program>($4, interpreter.get_scope_number(), 1)));
    $$ = make_shared<IfStatement>(move($5), $9);
}
| IF expr_val COLUMN EOL program elif_branch ELSE COLUMN statement ENDIF {
    $6.push_back(make_pair($2, $5));
    $$ = make_shared<IfStatement>(move($6), make_shared<Program>($9, interpreter.get_scope_number(), 1));
}
| IF expr_val COLUMN statement elif_branch ELSE COLUMN statement ENDIF {
    $5.push_back(make_pair($2, make_shared<Program>($4, interpreter.get_scope_number(), 1)));
    $$ = make_shared<IfStatement>(move($5), make_shared<Program>($8, interpreter.get_scope_number(), 1));
}
| IF expr_val COLUMN statement ELSE COLUMN statement{
    vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> ifs = {make_pair($2, make_shared<Program>($4, interpreter.get_scope_number(), 1))};
    $$ = make_shared<IfStatement>(move(ifs), make_shared<Program>($7, interpreter.get_scope_number(), 1));
}
| IF expr_val COLUMN statement{
    vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> ifs = {make_pair($2, make_shared<Program>($4, interpreter.get_scope_number(), 1))};
    $$ = make_shared<IfStatement>(move(ifs));
}
;

while_loop: WHILE expr_val COLUMN EOL
<void*> {
    interpreter.mark_is_in_loop(true);
} 
program ENDWHILE {
    //Izveido ciklu
    $$ = make_shared<WhileLoop>($2, $6);
    interpreter.mark_is_in_loop(false);
}
| WHILE expr_val COLUMN 
<void*> {
    interpreter.mark_is_in_loop(true);
} 
statement {
    //Izveido ciklu
    $$ = make_shared<WhileLoop>($2, make_shared<Program>($5, interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}

for_counter_loop: FOR ID ASSIGN expr_val TO expr_val BY expr_val COLUMN EOL
<int>{
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
        $$ = interpreter.declare_variable($2);
    }
}
 program ENDFOR{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($11, $4, $6, $8, $12);
    interpreter.mark_is_in_loop(false);
}
| FOR ID ASSIGN expr_val TO expr_val BY expr_val COLUMN
<int>{
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
        $$ = interpreter.declare_variable($2);
    }
}
 statement{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($10, $4, $6, $8, make_shared<Program>($11, interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
| FOR ID ASSIGN expr_val TO expr_val COLUMN EOL
<int>{
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
        $$ = interpreter.declare_variable($2);
    }
}
program ENDFOR{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($9, $4, $6, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), $10);
    interpreter.mark_is_in_loop(false);
}
| FOR ID ASSIGN expr_val TO expr_val COLUMN
<int>{
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
        $$ = interpreter.declare_variable($2);
    }
}
statement{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($8, $4, $6, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), make_shared<Program>($9, interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
| FOR ID TO expr_val COLUMN EOL
<int>{
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
        $$ = interpreter.declare_variable($2);
    }
}
program ENDFOR{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($7, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), $4, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), $8);
    interpreter.mark_is_in_loop(false);
}
| FOR ID TO expr_val COLUMN 
<int>{
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
        $$ = interpreter.declare_variable($2);
    }
}
statement{
    
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($6, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), $4, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), make_shared<Program>($7, interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
| FOR ID TO expr_val BY expr_val COLUMN EOL
<int>{
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
        $$ = interpreter.declare_variable($2);
    }
}
program ENDFOR{

    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($9, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), $4, $6, $10);
    interpreter.mark_is_in_loop(false);
}
| FOR ID TO expr_val BY expr_val COLUMN
<int>{
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
        $$ = interpreter.declare_variable($2);
    }
}
 statement{
    //Izveido ciklu
    $$ = make_shared<ForCounterLoop>($8, make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), $4, $6, make_shared<Program>($9, interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
;

elif_branch: %empty {$$ = vector<pair<shared_ptr<Expression>, shared_ptr<Program>>>(); }
| ELIF expr_val COLUMN EOL program elif_branch {
    $6.push_back(make_pair($2, $5));
    $$ = move($6);
}
| ELIF expr_val COLUMN statement elif_branch {
    $5.push_back(make_pair($2, make_shared<Program>($4, interpreter.get_scope_number(), 1)));
    $$ = move($5);
}
;

expr: DEC { $$ = make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>($1))); }
| STR { $$ = make_shared<LiteralExpression>( make_shared<Data>(make_shared<String>(move($1)))); }
| TRUE { $$ =  make_shared<LiteralExpression>(make_shared<Data>(make_shared<Boolean>(true))); }
| FALSE { $$ = make_shared<LiteralExpression>( make_shared<Data>(make_shared<Boolean>(false))); }
| NULL_TOKEN { $$ =  make_shared<LiteralExpression>(make_shared<Data>(make_shared<NullType>())); }
| INF { $$ =  make_shared<LiteralExpression>(make_shared<Data>(make_shared<InfType>())); }
| ID {
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
| function { $$ =  make_shared<LiteralExpression>(make_shared<Data>($1)); }
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
| expr AS NumType {$$ = make_shared<UnaryExpression>($1, UnaryExpression::TO_NUM);}
| expr AS BoolType {$$ = make_shared<UnaryExpression>($1, UnaryExpression::TO_BOOL);}
| expr AS StrType {$$ = make_shared<UnaryExpression>($1, UnaryExpression::TO_STR);}
| MINUS expr {$$ = make_shared<UnaryExpression> ($2, UnaryExpression::INV);}
| NOT expr {$$ = make_shared<UnaryExpression> ($2, UnaryExpression::NOT);}
| if_statement { $$ = make_shared<StatementExpression> ($1); }
| function_call { $$ = make_shared<StatementExpression> ($1); }
| assignment { $$ = make_shared<StatementExpression> ($1);}
| LEFT_PARENTHESES expr RIGHT_PARENTHESES {$$ = $2;}
| LEFT_BRACKET expr_list RIGHT_BRACKET { $$ = make_shared<InititializerListExpression>($2); }
| expr LEFT_BRACKET expr RIGHT_BRACKET { $$ = make_shared<BinaryExpression>($1, $3, BinaryExpression::INDEX); }
| LEN LEFT_PARENTHESES expr RIGHT_PARENTHESES { $$ = make_shared<LengthExpression>($3); }
;

expr_val: expr {
    $$ = $1->reduce_const();
}
;

expr_list: %empty { $$ = vector<shared_ptr<Expression>>(); }
| expr_val COMMA expr_list {
    $3.push_back($1);
    $$ = move($3);
}
| expr_val { $$ = {$1}; }
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
statement{
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

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cout << "ERROR: No program file provided" << endl;
        return 1;
    } 

    std::ifstream ifs(argv[1], std::ifstream::in);

    Program::output_stream = &cout;
    Program::input_stream = &cin;

    for(int i = 2; i < argc; i++) {
        char* arg = argv[i];

        if(strcmp(arg, "-i") == 0) {
            if(i++ == argc) {
                std::cerr << "Error: input parameter specified but file not provided" << endl;
                return 1;
            }
            
            Program::input_stream = new ifstream(argv[i]);
            if(Program::input_stream->fail()) {
                std::cerr << "Error: failed to read input file" << endl;
                return 1;
            }
        }
        else if(strcmp(arg, "-o") == 0) {
            if(i++ == argc) {
                std::cerr << "Error: output parameter specified but file not provided" << endl;
                return 1;
            }
            
            Program::output_stream = new ofstream(argv[i]);
        } else {
            std::cerr << "Error: unrecognized parameter " << argv[i] << endl;
            return 1;
        }
    }

    auto lexer = make_unique<CS::CS_Scanner>(&ifs);
    auto parser = make_unique<CS::CS_Parser>(*lexer);
    interpreter.make_new_scope(); //Globālais
    parser->parse();
    interpreter.pop_scope();

    return 0;
}