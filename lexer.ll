%option noyywrap nounput noinput debug
%option c++
%option yyclass="CS::CS_Scanner"

%{
    /* Definīcijas */
    using namespace std;

    #include <string>

    #include "CS_Scanner.hpp"
    #include "parser.tab.hh"


    /* Implementation of yyFlexScanner */ 
    #undef  YY_DECL
    #define YY_DECL int CS::CS_Scanner::yylex( CS::CS_Parser::semantic_type * const lval, CS::CS_Parser::location_type *location )

    /* using "token" to make the returns for the tokens shorter to type */
    using token = CS::CS_Parser::token;

    /* define yyterminate as this instead of NULL */
    // #define yyterminate() return( token::END )

    /* msvc2010 requires that we exclude this header file. */
    #define YY_NO_UNISTD_H

    /* update location on matching */
    #define YY_USER_ACTION loc->step(); loc->columns(yyleng);


%}

/* Likumi */

white [ \t]+
digit [0-9]
alpha [A-Za-z_] 
alphanum [A-Za-z0-9_]
integer {digit}+
exponent [eE][+-]?{integer}
real ({digit}*("."{integer}))|({integer}("."{integer})?){exponent}?
id {alpha}{alphanum}*

%% 

%{        
    /** Code executed at the beginning of yylex **/
    yylval = lval;
%}


{white} {}

"write" return token::PRINT;
"read" return token::READ;

"if" return token::IF;
"fi" return token::ENDIF;
"else" return token::ELSE;
"then" return token::THEN;
"while" return token::WHILE;
"do" return token::DO;
"end" return token::OD;
";" return token::SCOL;

"," return token::COMMA;
"+" return token::PLUS;
"-" return token::MINUS;
"*" return token::TIMES;
"/" return token::DIVIDE;
"(" return token::LEFT_PARENTHESES;
")" return token::RIGHT_PARENTHESES;
":=" return token::ASSIGN;
"=" return token::EQUAL;
"<" return token::LESS_THAN;
">" return token::GREATER_THAN;
"=<" return token::LESS_THAN_EQ;
">=" return token::GREATER_THAN_EQ;
"<>" return token::NOT_EQUAL;
"!=" return token::NOT_EQUAL;
"&&" return token::AND;
"||" return token::OR;

"\n" return token::EOL;

<<EOF>> return token::END_OF_FILE;

{id} {yylval->build<string>(yytext); return token::ID;}
{real} {yylval->build<string>(yytext); return token::DEC;}

%%

