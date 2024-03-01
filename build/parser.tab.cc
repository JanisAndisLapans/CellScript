// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 41 "../parser.yy"


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

#line 68 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 7 "../parser.yy"
namespace CS {
#line 161 "parser.tab.cc"

  /// Build a parser object.
  CS_Parser::CS_Parser (CS::CS_Scanner  &scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  CS_Parser::~CS_Parser ()
  {}

  CS_Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  CS_Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_66_2: // @2
        value.copy< DataPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_65_1: // @1
      case symbol_kind::S_69_3: // @3
      case symbol_kind::S_70_4: // @4
      case symbol_kind::S_71_5: // @5
      case symbol_kind::S_72_6: // @6
      case symbol_kind::S_73_7: // @7
      case symbol_kind::S_74_8: // @8
      case symbol_kind::S_75_9: // @9
      case symbol_kind::S_76_10: // @10
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment: // assignment
        value.copy< shared_ptr<AssignStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_val: // expr_val
        value.copy< shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        value.copy< shared_ptr<ForCounterLoop> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_82_11: // @11
      case symbol_kind::S_83_12: // @12
        value.copy< shared_ptr<Function> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.copy< shared_ptr<FunctionStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.copy< shared_ptr<IfStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.copy< shared_ptr<Program> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
        value.copy< shared_ptr<Statement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DEC: // DEC
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_ID: // ID
        value.copy< string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_elif_branch: // elif_branch
        value.copy< vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.copy< vector<shared_ptr<Expression>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id_list: // id_list
        value.copy< vector<string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  CS_Parser::symbol_kind_type
  CS_Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  CS_Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  CS_Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_66_2: // @2
        value.move< DataPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_65_1: // @1
      case symbol_kind::S_69_3: // @3
      case symbol_kind::S_70_4: // @4
      case symbol_kind::S_71_5: // @5
      case symbol_kind::S_72_6: // @6
      case symbol_kind::S_73_7: // @7
      case symbol_kind::S_74_8: // @8
      case symbol_kind::S_75_9: // @9
      case symbol_kind::S_76_10: // @10
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_assignment: // assignment
        value.move< shared_ptr<AssignStatement> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_val: // expr_val
        value.move< shared_ptr<Expression> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        value.move< shared_ptr<ForCounterLoop> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_82_11: // @11
      case symbol_kind::S_83_12: // @12
        value.move< shared_ptr<Function> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.move< shared_ptr<FunctionStatement> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.move< shared_ptr<IfStatement> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_program: // program
        value.move< shared_ptr<Program> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement: // statement
        value.move< shared_ptr<Statement> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_DEC: // DEC
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_ID: // ID
        value.move< string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_elif_branch: // elif_branch
        value.move< vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.move< vector<shared_ptr<Expression>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_id_list: // id_list
        value.move< vector<string> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  CS_Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  CS_Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  CS_Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  CS_Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  CS_Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  CS_Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  CS_Parser::symbol_kind_type
  CS_Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  CS_Parser::symbol_kind_type
  CS_Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  CS_Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  CS_Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  CS_Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  CS_Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  CS_Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  CS_Parser::symbol_kind_type
  CS_Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  CS_Parser::stack_symbol_type::stack_symbol_type ()
  {}

  CS_Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_66_2: // @2
        value.YY_MOVE_OR_COPY< DataPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_65_1: // @1
      case symbol_kind::S_69_3: // @3
      case symbol_kind::S_70_4: // @4
      case symbol_kind::S_71_5: // @5
      case symbol_kind::S_72_6: // @6
      case symbol_kind::S_73_7: // @7
      case symbol_kind::S_74_8: // @8
      case symbol_kind::S_75_9: // @9
      case symbol_kind::S_76_10: // @10
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment: // assignment
        value.YY_MOVE_OR_COPY< shared_ptr<AssignStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_val: // expr_val
        value.YY_MOVE_OR_COPY< shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        value.YY_MOVE_OR_COPY< shared_ptr<ForCounterLoop> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_82_11: // @11
      case symbol_kind::S_83_12: // @12
        value.YY_MOVE_OR_COPY< shared_ptr<Function> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.YY_MOVE_OR_COPY< shared_ptr<FunctionStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.YY_MOVE_OR_COPY< shared_ptr<IfStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.YY_MOVE_OR_COPY< shared_ptr<Program> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
        value.YY_MOVE_OR_COPY< shared_ptr<Statement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DEC: // DEC
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_ID: // ID
        value.YY_MOVE_OR_COPY< string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_elif_branch: // elif_branch
        value.YY_MOVE_OR_COPY< vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.YY_MOVE_OR_COPY< vector<shared_ptr<Expression>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id_list: // id_list
        value.YY_MOVE_OR_COPY< vector<string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  CS_Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_66_2: // @2
        value.move< DataPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_65_1: // @1
      case symbol_kind::S_69_3: // @3
      case symbol_kind::S_70_4: // @4
      case symbol_kind::S_71_5: // @5
      case symbol_kind::S_72_6: // @6
      case symbol_kind::S_73_7: // @7
      case symbol_kind::S_74_8: // @8
      case symbol_kind::S_75_9: // @9
      case symbol_kind::S_76_10: // @10
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment: // assignment
        value.move< shared_ptr<AssignStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_val: // expr_val
        value.move< shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        value.move< shared_ptr<ForCounterLoop> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_82_11: // @11
      case symbol_kind::S_83_12: // @12
        value.move< shared_ptr<Function> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.move< shared_ptr<FunctionStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.move< shared_ptr<IfStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.move< shared_ptr<Program> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
        value.move< shared_ptr<Statement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DEC: // DEC
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_ID: // ID
        value.move< string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_elif_branch: // elif_branch
        value.move< vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.move< vector<shared_ptr<Expression>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id_list: // id_list
        value.move< vector<string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  CS_Parser::stack_symbol_type&
  CS_Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_66_2: // @2
        value.copy< DataPtr > (that.value);
        break;

      case symbol_kind::S_65_1: // @1
      case symbol_kind::S_69_3: // @3
      case symbol_kind::S_70_4: // @4
      case symbol_kind::S_71_5: // @5
      case symbol_kind::S_72_6: // @6
      case symbol_kind::S_73_7: // @7
      case symbol_kind::S_74_8: // @8
      case symbol_kind::S_75_9: // @9
      case symbol_kind::S_76_10: // @10
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_assignment: // assignment
        value.copy< shared_ptr<AssignStatement> > (that.value);
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_val: // expr_val
        value.copy< shared_ptr<Expression> > (that.value);
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        value.copy< shared_ptr<ForCounterLoop> > (that.value);
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_82_11: // @11
      case symbol_kind::S_83_12: // @12
        value.copy< shared_ptr<Function> > (that.value);
        break;

      case symbol_kind::S_function_call: // function_call
        value.copy< shared_ptr<FunctionStatement> > (that.value);
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.copy< shared_ptr<IfStatement> > (that.value);
        break;

      case symbol_kind::S_program: // program
        value.copy< shared_ptr<Program> > (that.value);
        break;

      case symbol_kind::S_statement: // statement
        value.copy< shared_ptr<Statement> > (that.value);
        break;

      case symbol_kind::S_DEC: // DEC
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_ID: // ID
        value.copy< string > (that.value);
        break;

      case symbol_kind::S_elif_branch: // elif_branch
        value.copy< vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > (that.value);
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.copy< vector<shared_ptr<Expression>> > (that.value);
        break;

      case symbol_kind::S_id_list: // id_list
        value.copy< vector<string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  CS_Parser::stack_symbol_type&
  CS_Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_66_2: // @2
        value.move< DataPtr > (that.value);
        break;

      case symbol_kind::S_65_1: // @1
      case symbol_kind::S_69_3: // @3
      case symbol_kind::S_70_4: // @4
      case symbol_kind::S_71_5: // @5
      case symbol_kind::S_72_6: // @6
      case symbol_kind::S_73_7: // @7
      case symbol_kind::S_74_8: // @8
      case symbol_kind::S_75_9: // @9
      case symbol_kind::S_76_10: // @10
        value.move< int > (that.value);
        break;

      case symbol_kind::S_assignment: // assignment
        value.move< shared_ptr<AssignStatement> > (that.value);
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_val: // expr_val
        value.move< shared_ptr<Expression> > (that.value);
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        value.move< shared_ptr<ForCounterLoop> > (that.value);
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_82_11: // @11
      case symbol_kind::S_83_12: // @12
        value.move< shared_ptr<Function> > (that.value);
        break;

      case symbol_kind::S_function_call: // function_call
        value.move< shared_ptr<FunctionStatement> > (that.value);
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.move< shared_ptr<IfStatement> > (that.value);
        break;

      case symbol_kind::S_program: // program
        value.move< shared_ptr<Program> > (that.value);
        break;

      case symbol_kind::S_statement: // statement
        value.move< shared_ptr<Statement> > (that.value);
        break;

      case symbol_kind::S_DEC: // DEC
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_ID: // ID
        value.move< string > (that.value);
        break;

      case symbol_kind::S_elif_branch: // elif_branch
        value.move< vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > (that.value);
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.move< vector<shared_ptr<Expression>> > (that.value);
        break;

      case symbol_kind::S_id_list: // id_list
        value.move< vector<string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  CS_Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  CS_Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  CS_Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  CS_Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  CS_Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  CS_Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  CS_Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  CS_Parser::debug_level_type
  CS_Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  CS_Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  CS_Parser::state_type
  CS_Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  CS_Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  CS_Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  CS_Parser::operator() ()
  {
    return parse ();
  }

  int
  CS_Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_66_2: // @2
        yylhs.value.emplace< DataPtr > ();
        break;

      case symbol_kind::S_65_1: // @1
      case symbol_kind::S_69_3: // @3
      case symbol_kind::S_70_4: // @4
      case symbol_kind::S_71_5: // @5
      case symbol_kind::S_72_6: // @6
      case symbol_kind::S_73_7: // @7
      case symbol_kind::S_74_8: // @8
      case symbol_kind::S_75_9: // @9
      case symbol_kind::S_76_10: // @10
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_assignment: // assignment
        yylhs.value.emplace< shared_ptr<AssignStatement> > ();
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_val: // expr_val
        yylhs.value.emplace< shared_ptr<Expression> > ();
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        yylhs.value.emplace< shared_ptr<ForCounterLoop> > ();
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_82_11: // @11
      case symbol_kind::S_83_12: // @12
        yylhs.value.emplace< shared_ptr<Function> > ();
        break;

      case symbol_kind::S_function_call: // function_call
        yylhs.value.emplace< shared_ptr<FunctionStatement> > ();
        break;

      case symbol_kind::S_if_statement: // if_statement
        yylhs.value.emplace< shared_ptr<IfStatement> > ();
        break;

      case symbol_kind::S_program: // program
        yylhs.value.emplace< shared_ptr<Program> > ();
        break;

      case symbol_kind::S_statement: // statement
        yylhs.value.emplace< shared_ptr<Statement> > ();
        break;

      case symbol_kind::S_DEC: // DEC
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_ID: // ID
        yylhs.value.emplace< string > ();
        break;

      case symbol_kind::S_elif_branch: // elif_branch
        yylhs.value.emplace< vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ();
        break;

      case symbol_kind::S_expr_list: // expr_list
        yylhs.value.emplace< vector<shared_ptr<Expression>> > ();
        break;

      case symbol_kind::S_id_list: // id_list
        yylhs.value.emplace< vector<string> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // input: program END_OF_FILE
#line 114 "../parser.yy"
                           { 
    yystack_[1].value.as < shared_ptr<Program> > ()->run();
    return 0;
    }
#line 1136 "parser.tab.cc"
    break;

  case 3: // program: %empty
#line 120 "../parser.yy"
                {
    if(interpreter.is_sep_scope())
        yylhs.value.as < shared_ptr<Program> > () = make_shared<Program>(interpreter.get_scope_number(),interpreter.get_top_scope_size());
    else
        yylhs.value.as < shared_ptr<Program> > () = make_shared<Program>(interpreter.get_scope_number());  
}
#line 1147 "parser.tab.cc"
    break;

  case 4: // program: program statement EOL
#line 126 "../parser.yy"
                       {
    if(yystack_[1].value.as < shared_ptr<Statement> > () != nullptr)
    {
        yystack_[2].value.as < shared_ptr<Program> > ()->attach_statement(yystack_[1].value.as < shared_ptr<Statement> > ());
    }
    yylhs.value.as < shared_ptr<Program> > () = yystack_[2].value.as < shared_ptr<Program> > ();
    yystack_[2].value.as < shared_ptr<Program> > ()->set_callstack_size(interpreter.get_top_scope_size());
}
#line 1160 "parser.tab.cc"
    break;

  case 5: // program: program statement ONE_LINE_COMMENT EOL
#line 134 "../parser.yy"
                                        {
    if(yystack_[2].value.as < shared_ptr<Statement> > () != nullptr)
    {
        yystack_[3].value.as < shared_ptr<Program> > ()->attach_statement(yystack_[2].value.as < shared_ptr<Statement> > ());
    }
    yylhs.value.as < shared_ptr<Program> > () = yystack_[3].value.as < shared_ptr<Program> > ();
    yystack_[3].value.as < shared_ptr<Program> > ()->set_callstack_size(interpreter.get_top_scope_size());
}
#line 1173 "parser.tab.cc"
    break;

  case 6: // program: program EOL
#line 142 "../parser.yy"
             {
    yylhs.value.as < shared_ptr<Program> > () = yystack_[1].value.as < shared_ptr<Program> > ();
}
#line 1181 "parser.tab.cc"
    break;

  case 7: // program: program ONE_LINE_COMMENT EOL
#line 145 "../parser.yy"
                              {
    yylhs.value.as < shared_ptr<Program> > () = yystack_[2].value.as < shared_ptr<Program> > ();
}
#line 1189 "parser.tab.cc"
    break;

  case 8: // statement: assignment
#line 150 "../parser.yy"
                      {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<AssignStatement> > ();
}
#line 1197 "parser.tab.cc"
    break;

  case 9: // statement: PRINT expr_val
#line 153 "../parser.yy"
                 {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<PrintStatement>(yystack_[0].value.as < shared_ptr<Expression> > ());

}
#line 1206 "parser.tab.cc"
    break;

  case 10: // statement: if_statement
#line 157 "../parser.yy"
               {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<IfStatement> > ();
}
#line 1214 "parser.tab.cc"
    break;

  case 11: // statement: for_counter_loop
#line 160 "../parser.yy"
                 {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<ForCounterLoop> > ();
}
#line 1222 "parser.tab.cc"
    break;

  case 12: // statement: BREAK
#line 163 "../parser.yy"
       {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: BREAK statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<BreakStatement>();
}
#line 1234 "parser.tab.cc"
    break;

  case 13: // statement: BREAK_ALL
#line 170 "../parser.yy"
           {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: BREAK ALL statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<BreakAll>();
}
#line 1246 "parser.tab.cc"
    break;

  case 14: // statement: ADVANCE expr
#line 177 "../parser.yy"
              {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: ADVANCE statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Advance>(yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1258 "parser.tab.cc"
    break;

  case 15: // statement: CONTINUE
#line 184 "../parser.yy"
          {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: ADVANCE statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Advance>(make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))));
}
#line 1270 "parser.tab.cc"
    break;

  case 16: // statement: REPEAT
#line 191 "../parser.yy"
        {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: REPEAT statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Advance>(make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))));
}
#line 1282 "parser.tab.cc"
    break;

  case 17: // statement: RETURN
#line 198 "../parser.yy"
        {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Return>(make_shared<LiteralExpression>(make_shared<Data>(make_shared<NullType>())));
}
#line 1290 "parser.tab.cc"
    break;

  case 18: // statement: RETURN expr
#line 201 "../parser.yy"
             {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Return>(yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1298 "parser.tab.cc"
    break;

  case 19: // statement: GIVE expr
#line 204 "../parser.yy"
           {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Give>(yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1306 "parser.tab.cc"
    break;

  case 20: // statement: function_call
#line 207 "../parser.yy"
               {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<FunctionStatement> > ();
}
#line 1314 "parser.tab.cc"
    break;

  case 21: // function_call: expr_val LEFT_PARENTHESES expr_list RIGHT_PARENTHESES
#line 212 "../parser.yy"
                                                                     { 
    yylhs.value.as < shared_ptr<FunctionStatement> > () = make_shared<FunctionStatement>(yystack_[1].value.as < vector<shared_ptr<Expression>> > (), yystack_[3].value.as < shared_ptr<Expression> > ()); 
}
#line 1322 "parser.tab.cc"
    break;

  case 22: // function_call: SELF LEFT_PARENTHESES expr_list RIGHT_PARENTHESES
#line 215 "../parser.yy"
                                                   {
    if(auto func = interpreter.get_curr_function())
    {
        yylhs.value.as < shared_ptr<FunctionStatement> > () = make_shared<FunctionStatement>(yystack_[1].value.as < vector<shared_ptr<Expression>> > (), make_shared<LiteralExpression>(make_shared<Data>(func))); 
    }
    else
    {
        cout << "Attempt to call SELF in global scope" << endl;
        return 1;
    }

}
#line 1339 "parser.tab.cc"
    break;

  case 23: // @1: %empty
#line 230 "../parser.yy"
     {
    bool non_declared;
    yylhs.value.as < int > () = interpreter.get_variable(yystack_[1].value.as < string > (), non_declared);
    if(!non_declared)
    {
        if(interpreter.is_const(yystack_[1].value.as < string > ()))
        {
            cout << "ERROR: variable declared CONST in this scope, cannot be altered" <<endl;
            return 1;
        }
    }
    else
    {
        yylhs.value.as < int > () = interpreter.declare_variable(yystack_[1].value.as < string > ());
    }
}
#line 1360 "parser.tab.cc"
    break;

  case 24: // assignment: ID ASSIGN @1 expr_val
#line 246 "../parser.yy"
        {
    yylhs.value.as < shared_ptr<AssignStatement> > () = make_shared<AssignStatement>(yystack_[1].value.as < int > (), yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1368 "parser.tab.cc"
    break;

  case 25: // @2: %empty
#line 250 "../parser.yy"
         {
    bool non_declared;
    interpreter.get_variable(yystack_[1].value.as < string > (), non_declared);
    if(!non_declared || interpreter.is_const(yystack_[1].value.as < string > ()))
    {
        cout << "ERROR: variable was already declared in this scope." << endl;
        return 1;
    }
    else
    {
        yylhs.value.as < DataPtr > () = interpreter.declare_const_variable(yystack_[1].value.as < string > ());
    }
}
#line 1386 "parser.tab.cc"
    break;

  case 26: // assignment: CONST ID ASSIGN @2 expr_val
#line 263 "../parser.yy"
        {
    if(!yystack_[0].value.as < shared_ptr<Expression> > ()->is_const())
    {
        cout << "ERROR: CONST assignment requires a CONST expression." <<endl;
        return 1;
    }

    *yystack_[1].value.as < DataPtr > () = yystack_[0].value.as < shared_ptr<Expression> > ()->eval(const_stack);
    yylhs.value.as < shared_ptr<AssignStatement> > () = nullptr;
}
#line 1401 "parser.tab.cc"
    break;

  case 27: // if_statement: IF expr_val COLUMN EOL program elif_branch ENDIF
#line 275 "../parser.yy"
                                                               {
    yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[2].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()));
}
#line 1410 "parser.tab.cc"
    break;

  case 28: // if_statement: IF expr_val COLUMN EOL program elif_branch ELSE COLUMN EOL program ENDIF
#line 279 "../parser.yy"
                                                                           {
    yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[9].value.as < shared_ptr<Expression> > (), yystack_[6].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), yystack_[1].value.as < shared_ptr<Program> > ());
}
#line 1419 "parser.tab.cc"
    break;

  case 29: // if_statement: IF expr_val COLUMN statement elif_branch ENDIF
#line 283 "../parser.yy"
                                                 {
    yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[4].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[2].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()));
}
#line 1428 "parser.tab.cc"
    break;

  case 30: // if_statement: IF expr_val COLUMN statement elif_branch ELSE COLUMN EOL program ENDIF
#line 287 "../parser.yy"
                                                                         {
    yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[8].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[6].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), yystack_[1].value.as < shared_ptr<Program> > ());
}
#line 1437 "parser.tab.cc"
    break;

  case 31: // if_statement: IF expr_val COLUMN EOL program elif_branch ELSE COLUMN statement ENDIF
#line 291 "../parser.yy"
                                                                         {
    yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[8].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
}
#line 1446 "parser.tab.cc"
    break;

  case 32: // if_statement: IF expr_val COLUMN statement elif_branch ELSE COLUMN statement ENDIF
#line 295 "../parser.yy"
                                                                       {
    yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[7].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[5].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
}
#line 1455 "parser.tab.cc"
    break;

  case 33: // if_statement: IF expr_val COLUMN statement ELSE COLUMN statement
#line 299 "../parser.yy"
                                                    {
    vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> ifs = {make_pair(yystack_[5].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[3].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1))};
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(ifs), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
}
#line 1464 "parser.tab.cc"
    break;

  case 34: // if_statement: IF expr_val COLUMN statement
#line 303 "../parser.yy"
                              {
    vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> ifs = {make_pair(yystack_[2].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1))};
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(ifs));
}
#line 1473 "parser.tab.cc"
    break;

  case 35: // @3: %empty
#line 310 "../parser.yy"
     {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[8].value.as < string > (), non_declared);
    if(!non_declared)
    {
        yylhs.value.as < int > () = var;
    }
    else
    {
        yylhs.value.as < int > () = interpreter.declare_variable(yystack_[8].value.as < string > ());
    }
}
#line 1492 "parser.tab.cc"
    break;

  case 36: // for_counter_loop: FOR ID ASSIGN expr_val TO expr_val BY expr_val COLUMN EOL @3 program ENDFOR
#line 324 "../parser.yy"
               {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), yystack_[9].value.as < shared_ptr<Expression> > (), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1502 "parser.tab.cc"
    break;

  case 37: // @4: %empty
#line 330 "../parser.yy"
     {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[7].value.as < string > (), non_declared);
    if(!non_declared)
    {
        yylhs.value.as < int > () = var;
    }
    else
    {
        yylhs.value.as < int > () = interpreter.declare_variable(yystack_[7].value.as < string > ());
    }
}
#line 1521 "parser.tab.cc"
    break;

  case 38: // for_counter_loop: FOR ID ASSIGN expr_val TO expr_val BY expr_val COLUMN @4 statement
#line 344 "../parser.yy"
          {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[1].value.as < int > (), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1531 "parser.tab.cc"
    break;

  case 39: // @5: %empty
#line 350 "../parser.yy"
     {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[6].value.as < string > (), non_declared);
    if(!non_declared)
    {
        yylhs.value.as < int > () = var;
    }
    else
    {
        yylhs.value.as < int > () = interpreter.declare_variable(yystack_[6].value.as < string > ());
    }
}
#line 1550 "parser.tab.cc"
    break;

  case 40: // for_counter_loop: FOR ID ASSIGN expr_val TO expr_val COLUMN EOL @5 program ENDFOR
#line 364 "../parser.yy"
              {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1560 "parser.tab.cc"
    break;

  case 41: // @6: %empty
#line 370 "../parser.yy"
     {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[5].value.as < string > (), non_declared);
    if(!non_declared)
    {
        yylhs.value.as < int > () = var;
    }
    else
    {
        yylhs.value.as < int > () = interpreter.declare_variable(yystack_[5].value.as < string > ());
    }
}
#line 1579 "parser.tab.cc"
    break;

  case 42: // for_counter_loop: FOR ID ASSIGN expr_val TO expr_val COLUMN @6 statement
#line 384 "../parser.yy"
         {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[1].value.as < int > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1589 "parser.tab.cc"
    break;

  case 43: // @7: %empty
#line 390 "../parser.yy"
     {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[4].value.as < string > (), non_declared);
    if(!non_declared)
    {                
        yylhs.value.as < int > () = var;
    }
    else
    {        
        yylhs.value.as < int > () = interpreter.declare_variable(yystack_[4].value.as < string > ());
    }
}
#line 1608 "parser.tab.cc"
    break;

  case 44: // for_counter_loop: FOR ID TO expr_val COLUMN EOL @7 program ENDFOR
#line 404 "../parser.yy"
              {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[5].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1618 "parser.tab.cc"
    break;

  case 45: // @8: %empty
#line 410 "../parser.yy"
     {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[3].value.as < string > (), non_declared);
    if(!non_declared)
    {
        yylhs.value.as < int > () = var;
    }
    else
    {
        yylhs.value.as < int > () = interpreter.declare_variable(yystack_[3].value.as < string > ());
    }
}
#line 1637 "parser.tab.cc"
    break;

  case 46: // for_counter_loop: FOR ID TO expr_val COLUMN @8 statement
#line 424 "../parser.yy"
         {
    
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[1].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1648 "parser.tab.cc"
    break;

  case 47: // @9: %empty
#line 431 "../parser.yy"
     {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[6].value.as < string > (), non_declared);
    if(!non_declared)
    {
        yylhs.value.as < int > () = var;
    }
    else
    {
        yylhs.value.as < int > () = interpreter.declare_variable(yystack_[6].value.as < string > ());
    }
}
#line 1667 "parser.tab.cc"
    break;

  case 48: // for_counter_loop: FOR ID TO expr_val BY expr_val COLUMN EOL @9 program ENDFOR
#line 445 "../parser.yy"
              {

    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1678 "parser.tab.cc"
    break;

  case 49: // @10: %empty
#line 452 "../parser.yy"
     {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[5].value.as < string > (), non_declared);
    if(!non_declared)
    {
        yylhs.value.as < int > () = var;
    }
    else
    {
        yylhs.value.as < int > () = interpreter.declare_variable(yystack_[5].value.as < string > ());
    }
}
#line 1697 "parser.tab.cc"
    break;

  case 50: // for_counter_loop: FOR ID TO expr_val BY expr_val COLUMN @10 statement
#line 466 "../parser.yy"
          {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[1].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1707 "parser.tab.cc"
    break;

  case 51: // elif_branch: %empty
#line 473 "../parser.yy"
                    {yylhs.value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > () = vector<pair<shared_ptr<Expression>, shared_ptr<Program>>>(); }
#line 1713 "parser.tab.cc"
    break;

  case 52: // elif_branch: ELIF expr_val COLUMN EOL program elif_branch
#line 474 "../parser.yy"
                                               {
    yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[4].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > () = move(yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ());
}
#line 1722 "parser.tab.cc"
    break;

  case 53: // elif_branch: ELIF expr_val COLUMN statement elif_branch
#line 478 "../parser.yy"
                                             {
    yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > () = move(yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ());
}
#line 1731 "parser.tab.cc"
    break;

  case 54: // expr: DEC
#line 484 "../parser.yy"
          { yylhs.value.as < shared_ptr<Expression> > () = make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(yystack_[0].value.as < string > ()))); }
#line 1737 "parser.tab.cc"
    break;

  case 55: // expr: STR
#line 485 "../parser.yy"
      { yylhs.value.as < shared_ptr<Expression> > () = make_shared<LiteralExpression>( make_shared<Data>(make_shared<String>(move(yystack_[0].value.as < string > ())))); }
#line 1743 "parser.tab.cc"
    break;

  case 56: // expr: TRUE
#line 486 "../parser.yy"
       { yylhs.value.as < shared_ptr<Expression> > () =  make_shared<LiteralExpression>(make_shared<Data>(make_shared<Boolean>(true))); }
#line 1749 "parser.tab.cc"
    break;

  case 57: // expr: FALSE
#line 487 "../parser.yy"
        { yylhs.value.as < shared_ptr<Expression> > () = make_shared<LiteralExpression>( make_shared<Data>(make_shared<Boolean>(false))); }
#line 1755 "parser.tab.cc"
    break;

  case 58: // expr: NULL_TOKEN
#line 488 "../parser.yy"
             { yylhs.value.as < shared_ptr<Expression> > () =  make_shared<LiteralExpression>(make_shared<Data>(make_shared<NullType>())); }
#line 1761 "parser.tab.cc"
    break;

  case 59: // expr: INF
#line 489 "../parser.yy"
      { yylhs.value.as < shared_ptr<Expression> > () =  make_shared<LiteralExpression>(make_shared<Data>(make_shared<InfType>())); }
#line 1767 "parser.tab.cc"
    break;

  case 60: // expr: ID
#line 490 "../parser.yy"
     {
    bool non_declared;
    if(interpreter.is_const(yystack_[0].value.as < string > ()))
    {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<LiteralExpression>(interpreter.get_const_val(yystack_[0].value.as < string > (), non_declared));
    }
    else
    {
        auto var = interpreter.get_variable(yystack_[0].value.as < string > (), non_declared);
        if(!non_declared)
        {
            yylhs.value.as < shared_ptr<Expression> > () = make_shared<VariableExpression>(var, string(yystack_[0].value.as < string > ()));
        }
        else
        {
            cout << "ERROR: variable " << yystack_[0].value.as < string > () << " not declared in this scope." <<endl;
            return 1;
        }
    }
}
#line 1792 "parser.tab.cc"
    break;

  case 61: // expr: function
#line 510 "../parser.yy"
           { yylhs.value.as < shared_ptr<Expression> > () =  make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < shared_ptr<Function> > ())); }
#line 1798 "parser.tab.cc"
    break;

  case 62: // expr: expr PLUS expr
#line 511 "../parser.yy"
                 {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::ADD);}
#line 1804 "parser.tab.cc"
    break;

  case 63: // expr: expr MINUS expr
#line 512 "../parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::SUB);}
#line 1810 "parser.tab.cc"
    break;

  case 64: // expr: expr TIMES expr
#line 513 "../parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::MULT);}
#line 1816 "parser.tab.cc"
    break;

  case 65: // expr: expr MOD expr
#line 514 "../parser.yy"
                {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::MOD);}
#line 1822 "parser.tab.cc"
    break;

  case 66: // expr: expr DIVIDE expr
#line 515 "../parser.yy"
                   {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::DIV);}
#line 1828 "parser.tab.cc"
    break;

  case 67: // expr: expr POWER expr
#line 516 "../parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::POW);}
#line 1834 "parser.tab.cc"
    break;

  case 68: // expr: expr EQUAL expr
#line 517 "../parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::EQ);}
#line 1840 "parser.tab.cc"
    break;

  case 69: // expr: expr NOT_EQUAL expr
#line 518 "../parser.yy"
                      {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::NEQ);}
#line 1846 "parser.tab.cc"
    break;

  case 70: // expr: expr GREATER_THAN expr
#line 519 "../parser.yy"
                         {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::GT);}
#line 1852 "parser.tab.cc"
    break;

  case 71: // expr: expr LESS_THAN expr
#line 520 "../parser.yy"
                      {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::LT);}
#line 1858 "parser.tab.cc"
    break;

  case 72: // expr: expr GREATER_THAN_EQ expr
#line 521 "../parser.yy"
                            {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::EQ_GT);}
#line 1864 "parser.tab.cc"
    break;

  case 73: // expr: expr LESS_THAN_EQ expr
#line 522 "../parser.yy"
                         {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::EQ_LT);}
#line 1870 "parser.tab.cc"
    break;

  case 74: // expr: expr AND expr
#line 523 "../parser.yy"
                {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::AND);}
#line 1876 "parser.tab.cc"
    break;

  case 75: // expr: expr OR expr
#line 524 "../parser.yy"
               {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::OR);}
#line 1882 "parser.tab.cc"
    break;

  case 76: // expr: expr XOR expr
#line 525 "../parser.yy"
                {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::XOR);}
#line 1888 "parser.tab.cc"
    break;

  case 77: // expr: expr NEITHER expr
#line 526 "../parser.yy"
                    {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::NEITHER);}
#line 1894 "parser.tab.cc"
    break;

  case 78: // expr: expr AS NumType
#line 527 "../parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression>(yystack_[2].value.as < shared_ptr<Expression> > (), UnaryExpression::TO_NUM);}
#line 1900 "parser.tab.cc"
    break;

  case 79: // expr: expr AS BoolType
#line 528 "../parser.yy"
                   {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression>(yystack_[2].value.as < shared_ptr<Expression> > (), UnaryExpression::TO_BOOL);}
#line 1906 "parser.tab.cc"
    break;

  case 80: // expr: expr AS StrType
#line 529 "../parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression>(yystack_[2].value.as < shared_ptr<Expression> > (), UnaryExpression::TO_STR);}
#line 1912 "parser.tab.cc"
    break;

  case 81: // expr: MINUS expr
#line 530 "../parser.yy"
             {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression> (yystack_[0].value.as < shared_ptr<Expression> > (), UnaryExpression::INV);}
#line 1918 "parser.tab.cc"
    break;

  case 82: // expr: NOT expr
#line 531 "../parser.yy"
           {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression> (yystack_[0].value.as < shared_ptr<Expression> > (), UnaryExpression::NOT);}
#line 1924 "parser.tab.cc"
    break;

  case 83: // expr: if_statement
#line 532 "../parser.yy"
               { yylhs.value.as < shared_ptr<Expression> > () = make_shared<StatementExpression> (yystack_[0].value.as < shared_ptr<IfStatement> > ()); }
#line 1930 "parser.tab.cc"
    break;

  case 84: // expr: function_call
#line 533 "../parser.yy"
                { yylhs.value.as < shared_ptr<Expression> > () = make_shared<StatementExpression> (yystack_[0].value.as < shared_ptr<FunctionStatement> > ()); }
#line 1936 "parser.tab.cc"
    break;

  case 85: // expr: assignment
#line 534 "../parser.yy"
             { yylhs.value.as < shared_ptr<Expression> > () = make_shared<StatementExpression> (yystack_[0].value.as < shared_ptr<AssignStatement> > ());}
#line 1942 "parser.tab.cc"
    break;

  case 86: // expr: LEFT_PARENTHESES expr RIGHT_PARENTHESES
#line 535 "../parser.yy"
                                          {yylhs.value.as < shared_ptr<Expression> > () = yystack_[1].value.as < shared_ptr<Expression> > ();}
#line 1948 "parser.tab.cc"
    break;

  case 87: // expr_val: expr
#line 538 "../parser.yy"
               {
    yylhs.value.as < shared_ptr<Expression> > () = yystack_[0].value.as < shared_ptr<Expression> > ()->reduce_const();
}
#line 1956 "parser.tab.cc"
    break;

  case 88: // expr_list: %empty
#line 543 "../parser.yy"
                  { yylhs.value.as < vector<shared_ptr<Expression>> > () = vector<shared_ptr<Expression>>(); }
#line 1962 "parser.tab.cc"
    break;

  case 89: // expr_list: expr_val COMMA expr_list
#line 544 "../parser.yy"
                           {
    yystack_[0].value.as < vector<shared_ptr<Expression>> > ().push_back(yystack_[2].value.as < shared_ptr<Expression> > ());
    yylhs.value.as < vector<shared_ptr<Expression>> > () = move(yystack_[0].value.as < vector<shared_ptr<Expression>> > ());
}
#line 1971 "parser.tab.cc"
    break;

  case 90: // expr_list: expr_val
#line 548 "../parser.yy"
           { yylhs.value.as < vector<shared_ptr<Expression>> > () = {yystack_[0].value.as < shared_ptr<Expression> > ()}; }
#line 1977 "parser.tab.cc"
    break;

  case 91: // @11: %empty
#line 553 "../parser.yy"
{
    interpreter.make_new_scope();
    vector<int> arg_inds;
    for(const auto& id_name : yystack_[3].value.as < vector<string> > ())
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
    yylhs.value.as < shared_ptr<Function> > () = make_shared<Function>(arg_inds);
    interpreter.push_function(yylhs.value.as < shared_ptr<Function> > ());
}
#line 2004 "parser.tab.cc"
    break;

  case 92: // function: FUNC LEFT_PARENTHESES id_list RIGHT_PARENTHESES COLUMN EOL @11 program ENDFUNC
#line 575 "../parser.yy"
               {
    yystack_[2].value.as < shared_ptr<Function> > ()->attach_program(yystack_[1].value.as < shared_ptr<Program> > ());
    yylhs.value.as < shared_ptr<Function> > () = yystack_[2].value.as < shared_ptr<Function> > ();
    interpreter.pop_scope();
    interpreter.pop_function();
}
#line 2015 "parser.tab.cc"
    break;

  case 93: // @12: %empty
#line 583 "../parser.yy"
{
    interpreter.make_new_scope();
    vector<int> arg_inds;
    for(const auto& id_name : yystack_[2].value.as < vector<string> > ())
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
    yylhs.value.as < shared_ptr<Function> > () = make_shared<Function>(arg_inds);
    interpreter.push_function(yylhs.value.as < shared_ptr<Function> > ());
}
#line 2042 "parser.tab.cc"
    break;

  case 94: // function: FUNC LEFT_PARENTHESES id_list RIGHT_PARENTHESES COLUMN @12 statement
#line 605 "../parser.yy"
         {
    yystack_[1].value.as < shared_ptr<Function> > ()->attach_program(make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1 + yystack_[1].value.as < shared_ptr<Function> > ()->arg_count()));
    yylhs.value.as < shared_ptr<Function> > () = yystack_[1].value.as < shared_ptr<Function> > ();
    interpreter.pop_scope();
    interpreter.pop_function();
}
#line 2053 "parser.tab.cc"
    break;

  case 95: // id_list: %empty
#line 613 "../parser.yy"
                { yylhs.value.as < vector<string> > () = vector<string>(); }
#line 2059 "parser.tab.cc"
    break;

  case 96: // id_list: ID COMMA id_list
#line 614 "../parser.yy"
                  {
    yystack_[0].value.as < vector<string> > ().push_back(yystack_[2].value.as < string > ());
    yylhs.value.as < vector<string> > () = move(yystack_[0].value.as < vector<string> > ());
}
#line 2068 "parser.tab.cc"
    break;

  case 97: // id_list: ID
#line 618 "../parser.yy"
     { yylhs.value.as < vector<string> > () = {yystack_[0].value.as < string > ()}; }
#line 2074 "parser.tab.cc"
    break;


#line 2078 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  CS_Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  CS_Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  CS_Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // CS_Parser::context.
  CS_Parser::context::context (const CS_Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  CS_Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  CS_Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  CS_Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char CS_Parser::yypact_ninf_ = -101;

  const signed char CS_Parser::yytable_ninf_ = -1;

  const short
  CS_Parser::yypact_[] =
  {
    -101,     8,   283,  -101,  -101,  -101,    -8,   936,   936,   -21,
       1,   936,  -101,  -101,  -101,  -101,   936,  -101,  -101,  -101,
    -101,   936,  -101,  -101,    34,   936,   936,    47,    23,   936,
      15,  -101,  -101,  -101,  -101,   243,    52,  -101,  -101,  -101,
    -101,  -101,     6,    -3,    81,   936,   243,   243,    19,  -101,
      28,    52,     0,    58,   243,    63,  -101,   936,   936,   936,
     936,   936,   936,   936,   936,   936,   936,   936,   936,   936,
     936,   936,   936,    39,   936,  -101,   -14,    79,  -101,   936,
     696,   936,   936,    72,    91,  -101,     6,     6,     7,     7,
    -101,     7,    -3,    -3,    -3,    -3,    -3,    -3,   919,    96,
      96,    96,  -101,  -101,  -101,    94,   936,   936,  -101,    52,
    -101,   -19,    41,    83,    58,    90,  -101,    52,  -101,   327,
      92,   936,    24,   936,   936,    95,  -101,   105,    82,   872,
      29,    99,  -101,    85,    71,  -101,   872,  -101,   872,   102,
    -101,  -101,   740,   784,   936,   109,   117,  -101,  -101,  -101,
    -101,   828,  -101,   114,  -101,   118,    86,  -101,   872,  -101,
     872,   371,   419,  -101,   120,   327,  -101,   468,  -101,   128,
    -101,  -101,  -101,  -101,  -101,  -101,   512,  -101,  -101,  -101,
    -101,   872,   556,   604,  -101,  -101,  -101,  -101,  -101,   652,
    -101
  };

  const signed char
  CS_Parser::yydefact_[] =
  {
       3,     0,     0,     1,    54,    55,     0,     0,     0,     0,
       0,     0,    12,    15,    13,    16,    17,    56,    57,    58,
      59,     0,     6,     2,    60,     0,     0,     0,     0,     0,
       0,    20,     8,    10,    11,    87,     0,    61,     7,    84,
      85,    83,    81,    82,     0,    88,    14,    18,    87,    23,
       0,     9,     0,    95,    19,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    25,    90,     0,    86,     0,
       0,     0,     0,    97,     0,     5,    62,    63,    64,    66,
      67,    65,    68,    71,    70,    73,    72,    69,    74,    75,
      76,    77,    78,    79,    80,     0,     0,    88,    22,    24,
       3,    34,     0,     0,    95,     0,    21,    26,    89,    51,
       0,     0,     0,     0,     0,    45,    96,    93,     0,     0,
       0,     0,    29,     0,     0,    43,     0,    91,     0,     0,
      27,    33,     0,     0,     0,    41,    49,     3,    46,     3,
      94,     0,     3,    51,     3,     0,     0,    39,     0,    47,
       0,     0,     0,     3,     0,    51,    53,     0,    32,    37,
       3,    42,     3,    50,    44,    92,     0,    31,    52,    30,
      35,     0,     0,     0,    28,     3,    38,    40,    48,     0,
      36
  };

  const short
  CS_Parser::yypgoto_[] =
  {
    -101,  -101,  -100,   -67,    -2,    10,  -101,  -101,    65,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,   -79,   213,
     -24,   -28,  -101,  -101,  -101,    53
  };

  const unsigned char
  CS_Parser::yydefgoto_[] =
  {
       0,     1,     2,    30,    39,    40,    79,   106,    41,    34,
     185,   181,   170,   158,   147,   136,   172,   160,   122,    35,
      36,    77,    37,   149,   138,    84
  };

  const unsigned char
  CS_Parser::yytable_[] =
  {
      31,    50,    51,    57,    58,    59,    60,    61,     3,    62,
     119,    81,    32,   111,    59,    60,    61,    61,    62,    44,
      55,    76,    74,   120,   121,    57,    58,    59,    60,    61,
      38,    62,    63,    64,    65,    66,    67,    45,    68,   107,
     128,    69,    70,    71,    72,    49,   105,   161,    82,   162,
      76,    73,   165,    56,   167,   109,    78,   112,   113,    53,
      73,    73,   141,   176,    74,    74,   131,    33,   132,   148,
     182,   150,   183,    73,   166,   153,   155,    74,    31,   118,
      80,   142,   117,    76,   164,   189,   178,    52,    74,   123,
      32,   171,    75,   173,   102,   103,   104,   130,    83,   133,
     134,    85,    57,    58,    59,    60,    61,    74,    62,    63,
      64,    65,    66,    67,   186,    68,   108,    31,    69,    74,
     156,    74,    74,   146,   139,   114,   140,    31,   115,    32,
     124,   116,   144,   135,    31,   125,    31,   145,   169,    32,
      31,    31,   127,   137,   129,    33,    32,   157,    32,    31,
      73,   143,    32,    32,   151,   159,    31,   121,    31,    31,
      31,    32,   168,    31,   177,    31,   180,   126,    32,     0,
      32,    32,    32,     0,    31,    32,     0,    32,     0,    31,
      31,    31,     0,     0,    33,     0,    32,    31,     0,     0,
       0,    32,    32,    32,    33,     0,     0,     0,     0,    32,
       0,    33,     0,    33,     0,     0,     0,    33,    33,     0,
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
      42,    43,     0,    33,    46,    33,    33,    33,     0,    47,
      33,     0,    33,     0,    48,     0,     0,     0,     0,     0,
       0,    33,    54,     0,     0,     0,    33,    33,    33,    57,
      58,    59,    60,    61,    33,    62,    63,    64,    65,    66,
      67,     0,    68,     0,     0,    69,    70,    71,    72,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,     4,     5,     6,     0,
       7,     0,     0,     0,     0,     0,     0,    73,     0,     0,
       0,     8,     0,     9,    10,     0,     0,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,    22,    23,    24,    25,     0,     0,     0,    26,    27,
       4,     5,     6,    28,     7,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,     8,     0,     9,    10,     0,
       0,     0,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,    22,     0,    24,    25,     0,
     121,     0,    26,    27,     4,     5,     6,    28,     7,     0,
       0,     0,     0,     0,     0,    29,     0,     0,     0,     8,
       0,     9,    10,     0,     0,     0,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    22,
       0,    24,    25,     0,     0,     0,    26,    27,     0,     0,
     174,    28,     4,     5,     6,     0,     7,     0,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     8,     0,     9,
      10,     0,     0,     0,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,    22,     0,    24,
      25,     0,     0,     0,    26,    27,     0,     0,     0,    28,
     175,     4,     5,     6,     0,     7,     0,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     0,     9,    10,
       0,     0,     0,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,    22,     0,    24,    25,
       0,     0,   179,    26,    27,     4,     5,     6,    28,     7,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
       8,     0,     9,    10,     0,     0,     0,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
      22,     0,    24,    25,     0,     0,   184,    26,    27,     4,
       5,     6,    28,     7,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    22,     0,    24,    25,     0,     0,
       0,    26,    27,     0,     0,   187,    28,     4,     5,     6,
       0,     7,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     8,     0,     9,    10,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,    22,     0,    24,    25,     0,     0,     0,    26,
      27,     0,     0,   188,    28,     4,     5,     6,     0,     7,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     9,    10,     0,     0,     0,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
      22,     0,    24,    25,     0,     0,     0,    26,    27,     4,
       5,   190,    28,     7,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,   110,     0,    24,    25,     0,     0,
       0,    26,    27,     4,     5,     0,    28,     7,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,     8,     0,
       9,    10,     0,     0,     0,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,   152,     0,
      24,    25,     0,     0,     0,    26,    27,     4,     5,     0,
      28,     7,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     8,     0,     9,    10,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,   154,     0,    24,    25,     0,     0,     0,    26,
      27,     4,     5,     0,    28,     7,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     8,     0,     9,    10,
       0,     0,     0,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,   163,     0,    24,    25,
       0,     0,     0,    26,    27,     4,     5,     0,    28,     7,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
       8,     0,     9,    10,     0,     0,     0,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,    24,    25,     0,     0,     0,    26,    27,     0,
       0,     0,    28,     0,     0,    57,    58,    59,    60,    61,
      29,    62,    63,    64,    65,    66,    67,     0,    68,     4,
       5,     0,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,    20,    21,    73,     0,     0,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,    28
  };

  const short
  CS_Parser::yycheck_[] =
  {
       2,    25,    26,     6,     7,     8,     9,    10,     0,    12,
     110,    11,     2,    80,     8,     9,    10,    10,    12,    40,
       5,    45,    36,    42,    43,     6,     7,     8,     9,    10,
      38,    12,    13,    14,    15,    16,    17,    36,    19,    53,
     119,    22,    23,    24,    25,    11,    74,   147,    48,   149,
      74,    54,   152,    38,   154,    79,    37,    81,    82,    36,
      54,    54,   129,   163,    36,    36,    42,     2,    44,   136,
     170,   138,   172,    54,   153,   142,   143,    36,    80,   107,
      52,    52,   106,   107,   151,   185,   165,    40,    36,    48,
      80,   158,    11,   160,    55,    56,    57,   121,    40,   123,
     124,    38,     6,     7,     8,     9,    10,    36,    12,    13,
      14,    15,    16,    17,   181,    19,    37,   119,    22,    36,
     144,    36,    36,    52,    42,    53,    44,   129,    37,   119,
      47,    37,    47,    38,   136,    52,   138,    52,    52,   129,
     142,   143,    52,    38,    52,    80,   136,    38,   138,   151,
      54,    52,   142,   143,    52,    38,   158,    43,   160,   161,
     162,   151,    44,   165,    44,   167,    38,   114,   158,    -1,
     160,   161,   162,    -1,   176,   165,    -1,   167,    -1,   181,
     182,   183,    -1,    -1,   119,    -1,   176,   189,    -1,    -1,
      -1,   181,   182,   183,   129,    -1,    -1,    -1,    -1,   189,
      -1,   136,    -1,   138,    -1,    -1,    -1,   142,   143,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
       7,     8,    -1,   158,    11,   160,   161,   162,    -1,    16,
     165,    -1,   167,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      -1,   176,    29,    -1,    -1,    -1,   181,   182,   183,     6,
       7,     8,     9,    10,   189,    12,    13,    14,    15,    16,
      17,    -1,    19,    -1,    -1,    22,    23,    24,    25,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     3,     4,     5,    -1,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    -1,    -1,    -1,    45,    46,
       3,     4,     5,    50,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    38,    -1,    40,    41,    -1,
      43,    -1,    45,    46,     3,     4,     5,    50,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    18,
      -1,    20,    21,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    38,
      -1,    40,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,
      49,    50,     3,     4,     5,    -1,     7,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,
      21,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    38,    -1,    40,
      41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,
      51,     3,     4,     5,    -1,     7,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    -1,    40,    41,
      -1,    -1,    44,    45,    46,     3,     4,     5,    50,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    46,     3,
       4,     5,    50,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    -1,    40,    41,    -1,    -1,
      -1,    45,    46,    -1,    -1,    49,    50,     3,     4,     5,
      -1,     7,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    -1,    40,    41,    -1,    -1,    -1,    45,
      46,    -1,    -1,    49,    50,     3,     4,     5,    -1,     7,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    -1,    40,    41,    -1,    -1,    -1,    45,    46,     3,
       4,    49,    50,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    -1,    40,    41,    -1,    -1,
      -1,    45,    46,     3,     4,    -1,    50,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    -1,
      40,    41,    -1,    -1,    -1,    45,    46,     3,     4,    -1,
      50,     7,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    -1,    40,    41,    -1,    -1,    -1,    45,
      46,     3,     4,    -1,    50,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    18,    -1,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    -1,    40,    41,
      -1,    -1,    -1,    45,    46,     3,     4,    -1,    50,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    50,    -1,    -1,     6,     7,     8,     9,    10,
      58,    12,    13,    14,    15,    16,    17,    -1,    19,     3,
       4,    -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    54,    -1,    -1,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50
  };

  const signed char
  CS_Parser::yystos_[] =
  {
       0,    60,    61,     0,     3,     4,     5,     7,    18,    20,
      21,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    38,    39,    40,    41,    45,    46,    50,    58,
      62,    63,    64,    67,    68,    78,    79,    81,    38,    63,
      64,    67,    78,    78,    40,    36,    78,    78,    78,    11,
      79,    79,    40,    36,    78,     5,    38,     6,     7,     8,
       9,    10,    12,    13,    14,    15,    16,    17,    19,    22,
      23,    24,    25,    54,    36,    11,    79,    80,    37,    65,
      52,    11,    48,    40,    84,    38,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    55,    56,    57,    80,    66,    53,    37,    79,
      38,    62,    79,    79,    53,    37,    37,    79,    80,    61,
      42,    43,    77,    48,    47,    52,    84,    52,    77,    52,
      79,    42,    44,    79,    79,    38,    74,    38,    83,    42,
      44,    62,    52,    52,    47,    52,    52,    73,    62,    82,
      62,    52,    38,    62,    38,    62,    79,    38,    72,    38,
      76,    61,    61,    38,    62,    61,    77,    61,    44,    52,
      71,    62,    75,    62,    49,    51,    61,    44,    77,    44,
      38,    70,    61,    61,    44,    69,    62,    49,    49,    61,
      49
  };

  const signed char
  CS_Parser::yyr1_[] =
  {
       0,    59,    60,    61,    61,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    65,    64,    66,    64,    67,    67,    67,
      67,    67,    67,    67,    67,    69,    68,    70,    68,    71,
      68,    72,    68,    73,    68,    74,    68,    75,    68,    76,
      68,    77,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    80,    80,
      80,    82,    81,    83,    81,    84,    84,    84
  };

  const signed char
  CS_Parser::yyr2_[] =
  {
       0,     2,     2,     0,     3,     4,     2,     3,     1,     2,
       1,     1,     1,     1,     2,     1,     1,     1,     2,     2,
       1,     4,     4,     0,     4,     0,     5,     7,    11,     6,
      10,    10,     9,     7,     4,     0,    13,     0,    11,     0,
      11,     0,     9,     0,     9,     0,     7,     0,    11,     0,
       9,     0,     6,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     1,     1,     1,     3,     1,     0,     3,
       1,     0,     9,     0,     7,     0,     3,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const CS_Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "DEC", "STR",
  "ONE_LINE_COMMENT", "PLUS", "MINUS", "TIMES", "DIVIDE", "POWER",
  "ASSIGN", "MOD", "EQUAL", "LESS_THAN", "GREATER_THAN", "LESS_THAN_EQ",
  "GREATER_THAN_EQ", "NOT", "NOT_EQUAL", "CONST", "SELF", "AND", "OR",
  "XOR", "NEITHER", "ADVANCE", "BREAK", "CONTINUE", "BREAK_ALL", "REPEAT",
  "RETURN", "TRUE", "FALSE", "NULL_TOKEN", "INF", "LEFT_PARENTHESES",
  "RIGHT_PARENTHESES", "EOL", "END_OF_FILE", "ID", "IF", "ELSE", "ELIF",
  "ENDIF", "PRINT", "FOR", "BY", "TO", "ENDFOR", "FUNC", "ENDFUNC",
  "COLUMN", "COMMA", "AS", "NumType", "BoolType", "StrType", "GIVE",
  "$accept", "input", "program", "statement", "function_call",
  "assignment", "@1", "@2", "if_statement", "for_counter_loop", "@3", "@4",
  "@5", "@6", "@7", "@8", "@9", "@10", "elif_branch", "expr", "expr_val",
  "expr_list", "function", "@11", "@12", "id_list", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  CS_Parser::yyrline_[] =
  {
       0,   114,   114,   120,   126,   134,   142,   145,   150,   153,
     157,   160,   163,   170,   177,   184,   191,   198,   201,   204,
     207,   212,   215,   230,   229,   250,   249,   275,   279,   283,
     287,   291,   295,   299,   303,   310,   309,   330,   329,   350,
     349,   370,   369,   390,   389,   410,   409,   431,   430,   452,
     451,   473,   474,   478,   484,   485,   486,   487,   488,   489,
     490,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   538,   543,   544,
     548,   553,   551,   583,   581,   613,   614,   618
  };

  void
  CS_Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  CS_Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  CS_Parser::symbol_kind_type
  CS_Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
    };
    // Last valid token kind.
    const int code_max = 313;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 7 "../parser.yy"
} // CS
#line 2885 "parser.tab.cc"

#line 620 "../parser.yy"


void CS::CS_Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}

int main(int argc, char *argv[])
{
    cout << "test" << argc << argv[1] << endl;
    /*std::ifstream ifs(argv[0], std::ifstream::in);
    auto lexer = make_unique<CS::CS_Scanner>(&ifs);
    auto parser = make_unique<CS::CS_Parser>(*lexer);
    interpreter.make_new_scope(); //Globālais
    if(parser->parse() == 0) //Nav kļūdu
    {
        //
    }
    interpreter.pop_scope();*/
}
