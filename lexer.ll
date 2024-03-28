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
str_dqoute \"[^\"]*\"
str_sqoute \'[^\']*\'
str {str_dqoute}|{str_sqoute}
one_line_comment #.*

%% 

%{        
    /** Code executed at the beginning of yylex **/
    yylval = lval;
%}


{white} {}
{one_line_comment} return token::ONE_LINE_COMMENT; 

"Number" return token::NumType;
"Boolean" return token::BoolType;
"Bool" return token::BoolType;
"String" return token::StrType;

"AS" return token::AS;
"SELF" return token::SELF;
"GIVE" return token::GIVE;
"RETURN" return token::RETURN; 
"FUNC" return token::FUNC;
"ENDFUNC" return token::ENDFUNC;
"INF" return token::INF;
"REPEAT" return token::REPEAT;
"BREAK ALL" return token::BREAK_ALL;
"BREAK" return token::BREAK;
"CONTINUE" return token::CONTINUE;
"ADVANCE" return token::ADVANCE;
"NULL" return token::NULL_TOKEN;
"CONST" return token::CONST;
"PRINT" return token::PRINT;
"IF" return token::IF;
"ELIF" return token::ELIF;
"ELSE" return token::ELSE;
"ENDIF" return token::ENDIF;
"FOR" return token::FOR;
"TO" return token::TO;
"BY" return token::BY;
"ENDFOR" return token::ENDFOR;
"LEN" return token::LEN;
"WHILE" return token::WHILE;
"ENDWHILE" return token::ENDWHILE;
"READ" return token::READ;

"," return token::COMMA;
":" return token::COLUMN;
"+" return token::PLUS;
"-" return token::MINUS;
"*" return token::TIMES;
"/" return token::DIVIDE;
"^" return token::POWER;
"%" return token::MOD;
"(" return token::LEFT_PARENTHESES;
")" return token::RIGHT_PARENTHESES;
"[" return token::LEFT_BRACKET;
"]" return token::RIGHT_BRACKET;
"=" return token::ASSIGN;
"==" return token::EQUAL;
"<" return token::LESS_THAN;
">" return token::GREATER_THAN;
"<=" return token::LESS_THAN_EQ;
">=" return token::GREATER_THAN_EQ;
"!=" return token::NOT_EQUAL;
"+=" return token::PLUS_ASSIGN;
"-=" return token::MINUS_ASSIGN;
"*=" return token::TIMES_ASSIGN;
"/=" return token::DIVIDE_ASSIGN;
"%=" return token::MOD_ASSIGN;
"NOT" return token::NOT;
"AND" return token::AND;
"OR" return token::OR;
"XOR" return token::XOR;
"NEITHER" return token::NEITHER;
"TRUE" return token::TRUE;
"FALSE" return token::FALSE;
"\n" return token::EOL;

<<EOF>> return token::END_OF_FILE;

{id} {yylval->build<string>(yytext); return token::ID;}
{real} {yylval->build<string>(yytext); return token::DEC;}
{str} { string str = yytext; str.erase(0,1); /*Noņem sākuma " */ str.erase(str.size() - 1); /* Noņem beigu "*/ yylval->build<string>(move(str)); return token::STR;}

%%

