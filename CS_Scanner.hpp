#pragma once

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "parser.tab.hh"
#include "location.hh"

using namespace std;

namespace CS{

class CS_Scanner : public yyFlexLexer{
public:
   
   CS_Scanner(istream *in) : yyFlexLexer(in)
   {
      loc = new CS::CS_Parser::location_type();
   };
  
   //get rid of override virtual function warning
   using FlexLexer::yylex;

   virtual
   int yylex( CS::CS_Parser::semantic_type * const lval, 
              CS::CS_Parser::location_type *location );
   // YY_DECL defined in CS_lexer.l
   // Method body created by flex in CS_lexer.yy.cc


private:
   /* yyval ptr */
   CS::CS_Parser::semantic_type *yylval = nullptr;
   /* location ptr */
   CS::CS_Parser::location_type *loc    = nullptr;
};

} /* end namespace CS */
