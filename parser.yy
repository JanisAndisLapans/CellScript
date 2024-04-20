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
%token TRUE FALSE
%token PLUS MINUS TIMES DIVIDE ASSIGN
%token EQUAL LESS_THAN GREATER_THAN LESS_THAN_EQ GREATER_THAN_EQ NOT NOT_EQUAL NOT
%token AND OR
%token LEFT_PARENTHESES RIGHT_PARENTHESES
%token EOL SCOL
%token END_OF_FILE
%token<string> ID
%token IF THEN ELSE ENDIF PRINT READ WHILE DO OD
%token COLUMN COMMA

%type<shared_ptr<Expression>> expr
%nterm<shared_ptr<Statement>> statement
%nterm<shared_ptr<Program>> program;
%nterm<shared_ptr<IfStatement>> if_statement
%nterm<shared_ptr<WhileLoop>> while_loop
%nterm<shared_ptr<AssignStatement>> assignment
%type<vector<string>> id_list
/*
    Darbību secība
*/ 

%nonassoc THEN DO
%nonassoc IF ENDIF
%left ASSIGN
%left OR
%left AND
%left EQUAL LESS_THAN GREATER_THAN LESS_THAN_EQ GREATER_THAN_EQ NOT_EQUAL
%left NOT
%left PLUS MINUS
%left TIMES DIVIDE
%left LEFT_PARENTHESES RIGHT_PARENTHESES


//Gramatika un likumi 

%%
 
input: program END_OF_FILE { 
    $1->run();
    return 0;
    }
;

program: statement SCOL program {
    $$ = $3;

    if($1 != nullptr) {
        $$->attach_statement($1);
    }

    $$->set_callstack_size(interpreter.get_top_scope_size());      
}
| EOL program {
    $$ = $2;
}
| statement {
    if(interpreter.is_sep_scope())
        $$ = make_shared<Program>(interpreter.get_scope_number(),interpreter.get_top_scope_size());
    else
        $$ = make_shared<Program>(interpreter.get_scope_number());

    if($1 != nullptr) {
        $$->attach_statement($1);
    }

    $$->set_callstack_size(interpreter.get_top_scope_size());      
}
| statement EOL {
    if(interpreter.is_sep_scope())
        $$ = make_shared<Program>(interpreter.get_scope_number(),interpreter.get_top_scope_size());
    else
        $$ = make_shared<Program>(interpreter.get_scope_number());

    if($1 != nullptr) {
        $$->attach_statement($1);
    }

    $$->set_callstack_size(interpreter.get_top_scope_size());      
}

statement: assignment {
    $$ = $1;
}
| PRINT expr {
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
| while_loop {
    $$ = $1;
}
;

assignment: ID ASSIGN 
<int>{
    $$ = get_variable($1);
    if($$ == -1) { // Error
        return 1;
    }
}
expr{
    $$ = make_shared<AssignStatement>($3, $4);
}
;

if_statement: IF expr THEN program ENDIF{
    vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> ifs = {make_pair($2, $4)};
    $$ = make_shared<IfStatement>(move(ifs));
}
| IF expr THEN program ELSE program ENDIF{
    vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> ifs = {make_pair($2, $4)};
    $$ = make_shared<IfStatement>(move(ifs), $6);
}
;

while_loop: WHILE expr DO
<void*> {
    interpreter.mark_is_in_loop(true);
} 
program OD {
    //Izveido ciklu
    $$ = make_shared<WhileLoop>($2, $5);
    interpreter.mark_is_in_loop(false);
}

expr: DEC { $$ = make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>($1))); }
| TRUE { $$ =  make_shared<LiteralExpression>(make_shared<Data>(make_shared<Boolean>(true))); }
| FALSE { $$ = make_shared<LiteralExpression>( make_shared<Data>(make_shared<Boolean>(false))); }
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
| expr PLUS expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::ADD);}
| expr MINUS expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::SUB);}
| expr TIMES expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::MULT);}
| expr DIVIDE expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::DIV);}
| expr EQUAL expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::EQ);}
| expr NOT_EQUAL expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::NEQ);}
| expr GREATER_THAN expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::GT);}
| expr LESS_THAN expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::LT);}
| expr GREATER_THAN_EQ expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::EQ_GT);}
| expr LESS_THAN_EQ expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::EQ_LT);}
| expr AND expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::AND);}
| expr OR expr {$$ = make_shared<BinaryExpression> ($1,$3, BinaryExpression::OR);}
| MINUS expr {$$ = make_shared<UnaryExpression> ($2, UnaryExpression::INV);}
| NOT expr {$$ = make_shared<UnaryExpression> ($2, UnaryExpression::NOT);}
| if_statement { $$ = make_shared<StatementExpression> ($1); }
| assignment { $$ = make_shared<StatementExpression> ($1);}
| LEFT_PARENTHESES expr RIGHT_PARENTHESES {$$ = $2;}
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