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
#line 40 "parser.yy"


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


#line 69 "parser.tab.cc"


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

#line 7 "parser.yy"
namespace CS {
#line 162 "parser.tab.cc"

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
      case symbol_kind::S_const_expr: // const_expr
        value.copy< Data > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_62_2: // @2
        value.copy< DataPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_61_1: // @1
      case symbol_kind::S_65_3: // @3
      case symbol_kind::S_66_4: // @4
      case symbol_kind::S_67_5: // @5
      case symbol_kind::S_68_6: // @6
      case symbol_kind::S_69_7: // @7
      case symbol_kind::S_70_8: // @8
      case symbol_kind::S_71_9: // @9
      case symbol_kind::S_72_10: // @10
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment: // assignment
        value.copy< shared_ptr<AssignStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.copy< shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        value.copy< shared_ptr<ForCounterLoop> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_78_11: // @11
      case symbol_kind::S_79_12: // @12
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
      case symbol_kind::S_const_expr: // const_expr
        value.move< Data > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_62_2: // @2
        value.move< DataPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_61_1: // @1
      case symbol_kind::S_65_3: // @3
      case symbol_kind::S_66_4: // @4
      case symbol_kind::S_67_5: // @5
      case symbol_kind::S_68_6: // @6
      case symbol_kind::S_69_7: // @7
      case symbol_kind::S_70_8: // @8
      case symbol_kind::S_71_9: // @9
      case symbol_kind::S_72_10: // @10
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_assignment: // assignment
        value.move< shared_ptr<AssignStatement> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expr: // expr
        value.move< shared_ptr<Expression> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        value.move< shared_ptr<ForCounterLoop> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_78_11: // @11
      case symbol_kind::S_79_12: // @12
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
      case symbol_kind::S_const_expr: // const_expr
        value.YY_MOVE_OR_COPY< Data > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_62_2: // @2
        value.YY_MOVE_OR_COPY< DataPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_61_1: // @1
      case symbol_kind::S_65_3: // @3
      case symbol_kind::S_66_4: // @4
      case symbol_kind::S_67_5: // @5
      case symbol_kind::S_68_6: // @6
      case symbol_kind::S_69_7: // @7
      case symbol_kind::S_70_8: // @8
      case symbol_kind::S_71_9: // @9
      case symbol_kind::S_72_10: // @10
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment: // assignment
        value.YY_MOVE_OR_COPY< shared_ptr<AssignStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        value.YY_MOVE_OR_COPY< shared_ptr<ForCounterLoop> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_78_11: // @11
      case symbol_kind::S_79_12: // @12
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
      case symbol_kind::S_const_expr: // const_expr
        value.move< Data > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_62_2: // @2
        value.move< DataPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_61_1: // @1
      case symbol_kind::S_65_3: // @3
      case symbol_kind::S_66_4: // @4
      case symbol_kind::S_67_5: // @5
      case symbol_kind::S_68_6: // @6
      case symbol_kind::S_69_7: // @7
      case symbol_kind::S_70_8: // @8
      case symbol_kind::S_71_9: // @9
      case symbol_kind::S_72_10: // @10
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment: // assignment
        value.move< shared_ptr<AssignStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.move< shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        value.move< shared_ptr<ForCounterLoop> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_78_11: // @11
      case symbol_kind::S_79_12: // @12
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
      case symbol_kind::S_const_expr: // const_expr
        value.copy< Data > (that.value);
        break;

      case symbol_kind::S_62_2: // @2
        value.copy< DataPtr > (that.value);
        break;

      case symbol_kind::S_61_1: // @1
      case symbol_kind::S_65_3: // @3
      case symbol_kind::S_66_4: // @4
      case symbol_kind::S_67_5: // @5
      case symbol_kind::S_68_6: // @6
      case symbol_kind::S_69_7: // @7
      case symbol_kind::S_70_8: // @8
      case symbol_kind::S_71_9: // @9
      case symbol_kind::S_72_10: // @10
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_assignment: // assignment
        value.copy< shared_ptr<AssignStatement> > (that.value);
        break;

      case symbol_kind::S_expr: // expr
        value.copy< shared_ptr<Expression> > (that.value);
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        value.copy< shared_ptr<ForCounterLoop> > (that.value);
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_78_11: // @11
      case symbol_kind::S_79_12: // @12
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
      case symbol_kind::S_const_expr: // const_expr
        value.move< Data > (that.value);
        break;

      case symbol_kind::S_62_2: // @2
        value.move< DataPtr > (that.value);
        break;

      case symbol_kind::S_61_1: // @1
      case symbol_kind::S_65_3: // @3
      case symbol_kind::S_66_4: // @4
      case symbol_kind::S_67_5: // @5
      case symbol_kind::S_68_6: // @6
      case symbol_kind::S_69_7: // @7
      case symbol_kind::S_70_8: // @8
      case symbol_kind::S_71_9: // @9
      case symbol_kind::S_72_10: // @10
        value.move< int > (that.value);
        break;

      case symbol_kind::S_assignment: // assignment
        value.move< shared_ptr<AssignStatement> > (that.value);
        break;

      case symbol_kind::S_expr: // expr
        value.move< shared_ptr<Expression> > (that.value);
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        value.move< shared_ptr<ForCounterLoop> > (that.value);
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_78_11: // @11
      case symbol_kind::S_79_12: // @12
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
      case symbol_kind::S_const_expr: // const_expr
        yylhs.value.emplace< Data > ();
        break;

      case symbol_kind::S_62_2: // @2
        yylhs.value.emplace< DataPtr > ();
        break;

      case symbol_kind::S_61_1: // @1
      case symbol_kind::S_65_3: // @3
      case symbol_kind::S_66_4: // @4
      case symbol_kind::S_67_5: // @5
      case symbol_kind::S_68_6: // @6
      case symbol_kind::S_69_7: // @7
      case symbol_kind::S_70_8: // @8
      case symbol_kind::S_71_9: // @9
      case symbol_kind::S_72_10: // @10
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_assignment: // assignment
        yylhs.value.emplace< shared_ptr<AssignStatement> > ();
        break;

      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< shared_ptr<Expression> > ();
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        yylhs.value.emplace< shared_ptr<ForCounterLoop> > ();
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_78_11: // @11
      case symbol_kind::S_79_12: // @12
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
  case 2: // input: program STOP EOL
#line 112 "parser.yy"
                        { 
    yystack_[2].value.as < shared_ptr<Program> > ()->run();
    return 0;
    }
#line 1158 "parser.tab.cc"
    break;

  case 3: // program: %empty
#line 118 "parser.yy"
                {
    if(interpreter.is_sep_scope())
        yylhs.value.as < shared_ptr<Program> > () = make_shared<Program>(interpreter.get_scope_number(),interpreter.get_top_scope_size());
    else
      yylhs.value.as < shared_ptr<Program> > () = make_shared<Program>(interpreter.get_scope_number());  
}
#line 1169 "parser.tab.cc"
    break;

  case 4: // program: program statement EOL
#line 124 "parser.yy"
                       {
    if(yystack_[1].value.as < shared_ptr<Statement> > () != nullptr)
    {
        yystack_[2].value.as < shared_ptr<Program> > ()->attach_statement(yystack_[1].value.as < shared_ptr<Statement> > ());
    }
    yylhs.value.as < shared_ptr<Program> > () = yystack_[2].value.as < shared_ptr<Program> > ();
    yystack_[2].value.as < shared_ptr<Program> > ()->set_callstack_size(interpreter.get_top_scope_size());
}
#line 1182 "parser.tab.cc"
    break;

  case 5: // program: program statement ONE_LINE_COMMENT EOL
#line 132 "parser.yy"
                                        {
    if(yystack_[2].value.as < shared_ptr<Statement> > () != nullptr)
    {
        yystack_[3].value.as < shared_ptr<Program> > ()->attach_statement(yystack_[2].value.as < shared_ptr<Statement> > ());
    }
    yylhs.value.as < shared_ptr<Program> > () = yystack_[3].value.as < shared_ptr<Program> > ();
    yystack_[3].value.as < shared_ptr<Program> > ()->set_callstack_size(interpreter.get_top_scope_size());
}
#line 1195 "parser.tab.cc"
    break;

  case 6: // program: program EOL
#line 140 "parser.yy"
             {
    yylhs.value.as < shared_ptr<Program> > () = yystack_[1].value.as < shared_ptr<Program> > ();
}
#line 1203 "parser.tab.cc"
    break;

  case 7: // program: program ONE_LINE_COMMENT EOL
#line 143 "parser.yy"
                              {
    yylhs.value.as < shared_ptr<Program> > () = yystack_[2].value.as < shared_ptr<Program> > ();
}
#line 1211 "parser.tab.cc"
    break;

  case 8: // statement: assignment
#line 148 "parser.yy"
                      {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<AssignStatement> > ();
}
#line 1219 "parser.tab.cc"
    break;

  case 9: // statement: PRINT expr
#line 151 "parser.yy"
             {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<PrintStatement>(yystack_[0].value.as < shared_ptr<Expression> > ());

}
#line 1228 "parser.tab.cc"
    break;

  case 10: // statement: if_statement
#line 155 "parser.yy"
               {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<IfStatement> > ();
}
#line 1236 "parser.tab.cc"
    break;

  case 11: // statement: for_counter_loop
#line 158 "parser.yy"
                 {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<ForCounterLoop> > ();
}
#line 1244 "parser.tab.cc"
    break;

  case 12: // statement: BREAK
#line 161 "parser.yy"
       {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: BREAK statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<BreakStatement>();
}
#line 1256 "parser.tab.cc"
    break;

  case 13: // statement: BREAK_ALL
#line 168 "parser.yy"
           {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: BREAK ALL statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<BreakAll>();
}
#line 1268 "parser.tab.cc"
    break;

  case 14: // statement: ADVANCE expr
#line 175 "parser.yy"
              {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: ADVANCE statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Advance>(yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1280 "parser.tab.cc"
    break;

  case 15: // statement: CONTINUE
#line 182 "parser.yy"
          {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: ADVANCE statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Advance>(make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))));
}
#line 1292 "parser.tab.cc"
    break;

  case 16: // statement: REPEAT
#line 189 "parser.yy"
        {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: REPEAT statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Advance>(make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))));
}
#line 1304 "parser.tab.cc"
    break;

  case 17: // statement: RETURN
#line 196 "parser.yy"
        {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Return>(make_shared<LiteralExpression>(make_shared<Data>(make_shared<NullType>())));
}
#line 1312 "parser.tab.cc"
    break;

  case 18: // statement: RETURN expr
#line 199 "parser.yy"
             {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Return>(yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1320 "parser.tab.cc"
    break;

  case 19: // statement: GIVE expr
#line 202 "parser.yy"
           {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Give>(yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1328 "parser.tab.cc"
    break;

  case 20: // statement: function_call
#line 205 "parser.yy"
               {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<FunctionStatement> > ();
}
#line 1336 "parser.tab.cc"
    break;

  case 21: // function_call: expr LEFT_PARENTHESES expr_list RIGHT_PARENTHESES
#line 210 "parser.yy"
                                                                 { 
    yylhs.value.as < shared_ptr<FunctionStatement> > () = make_shared<FunctionStatement>(yystack_[1].value.as < vector<shared_ptr<Expression>> > (), yystack_[3].value.as < shared_ptr<Expression> > ()); 
}
#line 1344 "parser.tab.cc"
    break;

  case 22: // function_call: SELF LEFT_PARENTHESES expr_list RIGHT_PARENTHESES
#line 213 "parser.yy"
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
#line 1361 "parser.tab.cc"
    break;

  case 23: // @1: %empty
#line 228 "parser.yy"
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
#line 1382 "parser.tab.cc"
    break;

  case 24: // assignment: ID ASSIGN @1 expr
#line 244 "parser.yy"
    {
    yylhs.value.as < shared_ptr<AssignStatement> > () = make_shared<AssignStatement>(yystack_[1].value.as < int > (), yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1390 "parser.tab.cc"
    break;

  case 25: // @2: %empty
#line 248 "parser.yy"
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
#line 1408 "parser.tab.cc"
    break;

  case 26: // assignment: CONST ID ASSIGN @2 const_expr
#line 261 "parser.yy"
          {
    *yystack_[1].value.as < DataPtr > () = yystack_[0].value.as < Data > ();
    yylhs.value.as < shared_ptr<AssignStatement> > () = nullptr;
}
#line 1417 "parser.tab.cc"
    break;

  case 27: // if_statement: IF expr COLUMN EOL program elif_branch ENDIF
#line 267 "parser.yy"
                                                           {
    yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[2].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()));
}
#line 1426 "parser.tab.cc"
    break;

  case 28: // if_statement: IF expr COLUMN EOL program elif_branch ELSE COLUMN EOL program ENDIF
#line 271 "parser.yy"
                                                                       {
    yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[9].value.as < shared_ptr<Expression> > (), yystack_[6].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), yystack_[1].value.as < shared_ptr<Program> > ());
}
#line 1435 "parser.tab.cc"
    break;

  case 29: // if_statement: IF expr COLUMN statement elif_branch ENDIF
#line 275 "parser.yy"
                                             {
    yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[4].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[2].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()));
}
#line 1444 "parser.tab.cc"
    break;

  case 30: // if_statement: IF expr COLUMN statement elif_branch ELSE COLUMN EOL program ENDIF
#line 279 "parser.yy"
                                                                     {
    yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[8].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[6].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), yystack_[1].value.as < shared_ptr<Program> > ());
}
#line 1453 "parser.tab.cc"
    break;

  case 31: // if_statement: IF expr COLUMN EOL program elif_branch ELSE COLUMN statement ENDIF
#line 283 "parser.yy"
                                                                     {
    yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[8].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
}
#line 1462 "parser.tab.cc"
    break;

  case 32: // if_statement: IF expr COLUMN statement elif_branch ELSE COLUMN statement ENDIF
#line 287 "parser.yy"
                                                                   {
    yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[7].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[5].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
}
#line 1471 "parser.tab.cc"
    break;

  case 33: // @3: %empty
#line 294 "parser.yy"
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
#line 1490 "parser.tab.cc"
    break;

  case 34: // for_counter_loop: FOR ID ASSIGN expr TO expr BY expr COLUMN EOL @3 program ENDFOR
#line 308 "parser.yy"
               {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), yystack_[9].value.as < shared_ptr<Expression> > (), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1500 "parser.tab.cc"
    break;

  case 35: // @4: %empty
#line 314 "parser.yy"
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
#line 1519 "parser.tab.cc"
    break;

  case 36: // for_counter_loop: FOR ID ASSIGN expr TO expr BY expr COLUMN @4 statement ENDFOR
#line 328 "parser.yy"
                 {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), yystack_[8].value.as < shared_ptr<Expression> > (), yystack_[6].value.as < shared_ptr<Expression> > (), yystack_[4].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1529 "parser.tab.cc"
    break;

  case 37: // @5: %empty
#line 334 "parser.yy"
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
#line 1548 "parser.tab.cc"
    break;

  case 38: // for_counter_loop: FOR ID ASSIGN expr TO expr COLUMN EOL @5 program ENDFOR
#line 348 "parser.yy"
              {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1558 "parser.tab.cc"
    break;

  case 39: // @6: %empty
#line 354 "parser.yy"
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
#line 1577 "parser.tab.cc"
    break;

  case 40: // for_counter_loop: FOR ID ASSIGN expr TO expr COLUMN @6 statement ENDFOR
#line 368 "parser.yy"
                {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), yystack_[6].value.as < shared_ptr<Expression> > (), yystack_[4].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1587 "parser.tab.cc"
    break;

  case 41: // @7: %empty
#line 374 "parser.yy"
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
#line 1606 "parser.tab.cc"
    break;

  case 42: // for_counter_loop: FOR ID TO expr COLUMN EOL @7 program ENDFOR
#line 388 "parser.yy"
              {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[5].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1616 "parser.tab.cc"
    break;

  case 43: // @8: %empty
#line 394 "parser.yy"
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
#line 1635 "parser.tab.cc"
    break;

  case 44: // for_counter_loop: FOR ID TO expr COLUMN @8 statement ENDFOR
#line 408 "parser.yy"
                {
    
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[4].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1646 "parser.tab.cc"
    break;

  case 45: // @9: %empty
#line 415 "parser.yy"
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
#line 1665 "parser.tab.cc"
    break;

  case 46: // for_counter_loop: FOR ID TO expr BY expr COLUMN EOL @9 program ENDFOR
#line 429 "parser.yy"
              {

    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1676 "parser.tab.cc"
    break;

  case 47: // @10: %empty
#line 436 "parser.yy"
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
#line 1695 "parser.tab.cc"
    break;

  case 48: // for_counter_loop: FOR ID TO expr BY expr COLUMN @10 statement ENDFOR
#line 450 "parser.yy"
                 {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[6].value.as < shared_ptr<Expression> > (), yystack_[4].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1705 "parser.tab.cc"
    break;

  case 49: // elif_branch: %empty
#line 457 "parser.yy"
                    {yylhs.value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > () = vector<pair<shared_ptr<Expression>, shared_ptr<Program>>>(); }
#line 1711 "parser.tab.cc"
    break;

  case 50: // elif_branch: ELIF expr COLUMN EOL program elif_branch
#line 458 "parser.yy"
                                           {
    yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[4].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > () = move(yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ());
}
#line 1720 "parser.tab.cc"
    break;

  case 51: // elif_branch: ELIF expr COLUMN statement elif_branch
#line 462 "parser.yy"
                                         {
    yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > () = move(yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ());
}
#line 1729 "parser.tab.cc"
    break;

  case 52: // expr: ID
#line 468 "parser.yy"
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
#line 1754 "parser.tab.cc"
    break;

  case 53: // expr: const_expr
#line 488 "parser.yy"
             { yylhs.value.as < shared_ptr<Expression> > () = make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())); }
#line 1760 "parser.tab.cc"
    break;

  case 54: // expr: expr PLUS expr
#line 489 "parser.yy"
                 {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::ADD);}
#line 1766 "parser.tab.cc"
    break;

  case 55: // expr: expr MINUS expr
#line 490 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::SUB);}
#line 1772 "parser.tab.cc"
    break;

  case 56: // expr: expr TIMES expr
#line 491 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::MULT);}
#line 1778 "parser.tab.cc"
    break;

  case 57: // expr: expr MOD expr
#line 492 "parser.yy"
                {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::MOD);}
#line 1784 "parser.tab.cc"
    break;

  case 58: // expr: expr DIVIDE expr
#line 493 "parser.yy"
                   {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::DIV);}
#line 1790 "parser.tab.cc"
    break;

  case 59: // expr: expr POWER expr
#line 494 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::POW);}
#line 1796 "parser.tab.cc"
    break;

  case 60: // expr: expr EQUAL expr
#line 495 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::EQ);}
#line 1802 "parser.tab.cc"
    break;

  case 61: // expr: expr NOT_EQUAL expr
#line 496 "parser.yy"
                      {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::NEQ);}
#line 1808 "parser.tab.cc"
    break;

  case 62: // expr: expr GREATER_THAN expr
#line 497 "parser.yy"
                         {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::GT);}
#line 1814 "parser.tab.cc"
    break;

  case 63: // expr: expr LESS_THAN expr
#line 498 "parser.yy"
                      {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::LT);}
#line 1820 "parser.tab.cc"
    break;

  case 64: // expr: expr GREATER_THAN_EQ expr
#line 499 "parser.yy"
                            {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::EQ_GT);}
#line 1826 "parser.tab.cc"
    break;

  case 65: // expr: expr LESS_THAN_EQ expr
#line 500 "parser.yy"
                         {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::EQ_LT);}
#line 1832 "parser.tab.cc"
    break;

  case 66: // expr: expr AND expr
#line 501 "parser.yy"
                {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::AND);}
#line 1838 "parser.tab.cc"
    break;

  case 67: // expr: expr OR expr
#line 502 "parser.yy"
               {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::OR);}
#line 1844 "parser.tab.cc"
    break;

  case 68: // expr: expr XOR expr
#line 503 "parser.yy"
                {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::XOR);}
#line 1850 "parser.tab.cc"
    break;

  case 69: // expr: expr NEITHER expr
#line 504 "parser.yy"
                    {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::NEITHER);}
#line 1856 "parser.tab.cc"
    break;

  case 70: // expr: MINUS expr
#line 505 "parser.yy"
             {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression> (yystack_[0].value.as < shared_ptr<Expression> > (), UnaryExpression::INV);}
#line 1862 "parser.tab.cc"
    break;

  case 71: // expr: NOT expr
#line 506 "parser.yy"
           {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression> (yystack_[0].value.as < shared_ptr<Expression> > (), UnaryExpression::NOT);}
#line 1868 "parser.tab.cc"
    break;

  case 72: // expr: if_statement
#line 507 "parser.yy"
               { yylhs.value.as < shared_ptr<Expression> > () = make_shared<StatementExpression> (yystack_[0].value.as < shared_ptr<IfStatement> > ()); }
#line 1874 "parser.tab.cc"
    break;

  case 73: // expr: function_call
#line 508 "parser.yy"
                { yylhs.value.as < shared_ptr<Expression> > () = make_shared<StatementExpression> (yystack_[0].value.as < shared_ptr<FunctionStatement> > ()); }
#line 1880 "parser.tab.cc"
    break;

  case 74: // expr: assignment
#line 509 "parser.yy"
             { yylhs.value.as < shared_ptr<Expression> > () = make_shared<StatementExpression> (yystack_[0].value.as < shared_ptr<AssignStatement> > ()); }
#line 1886 "parser.tab.cc"
    break;

  case 75: // const_expr: DEC
#line 512 "parser.yy"
                { yylhs.value.as < Data > () = make_shared<Number>(yystack_[0].value.as < string > ()); }
#line 1892 "parser.tab.cc"
    break;

  case 76: // const_expr: STR
#line 513 "parser.yy"
      { yylhs.value.as < Data > () = make_shared<String>(move(yystack_[0].value.as < string > ())); }
#line 1898 "parser.tab.cc"
    break;

  case 77: // const_expr: TRUE
#line 514 "parser.yy"
       { yylhs.value.as < Data > () = make_shared<Boolean>(true); }
#line 1904 "parser.tab.cc"
    break;

  case 78: // const_expr: FALSE
#line 515 "parser.yy"
        { yylhs.value.as < Data > () = make_shared<Boolean>(false); }
#line 1910 "parser.tab.cc"
    break;

  case 79: // const_expr: NULL_TOKEN
#line 516 "parser.yy"
             { yylhs.value.as < Data > () = make_shared<NullType>(); }
#line 1916 "parser.tab.cc"
    break;

  case 80: // const_expr: INF
#line 517 "parser.yy"
      { yylhs.value.as < Data > () = make_shared<InfType>(); }
#line 1922 "parser.tab.cc"
    break;

  case 81: // const_expr: ID
#line 518 "parser.yy"
    {
    bool non_declared;
    if(interpreter.is_const(yystack_[0].value.as < string > ()))
    {
        yylhs.value.as < Data > () = *interpreter.get_const_val(yystack_[0].value.as < string > (), non_declared);
    }
    else{
        cout << "Variable " << yystack_[0].value.as < string > () << " is not declared CONST" << ", only CONST values may be assigned to CONST variables." <<endl;
        return 1;
    }
}
#line 1938 "parser.tab.cc"
    break;

  case 82: // const_expr: function
#line 529 "parser.yy"
          { yylhs.value.as < Data > () = yystack_[0].value.as < shared_ptr<Function> > (); }
#line 1944 "parser.tab.cc"
    break;

  case 83: // const_expr: const_expr PLUS const_expr
#line 530 "parser.yy"
                             {yylhs.value.as < Data > () = BinaryExpression(make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::ADD).eval(const_stack);}
#line 1950 "parser.tab.cc"
    break;

  case 84: // const_expr: const_expr MINUS const_expr
#line 531 "parser.yy"
                              {yylhs.value.as < Data > () = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::SUB).eval(const_stack);}
#line 1956 "parser.tab.cc"
    break;

  case 85: // const_expr: const_expr TIMES const_expr
#line 532 "parser.yy"
                              {yylhs.value.as < Data > () = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::MULT).eval(const_stack);}
#line 1962 "parser.tab.cc"
    break;

  case 86: // const_expr: const_expr MOD const_expr
#line 533 "parser.yy"
                            {yylhs.value.as < Data > () = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::MOD).eval(const_stack);}
#line 1968 "parser.tab.cc"
    break;

  case 87: // const_expr: const_expr DIVIDE const_expr
#line 534 "parser.yy"
                               {yylhs.value.as < Data > () = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::DIV).eval(const_stack);}
#line 1974 "parser.tab.cc"
    break;

  case 88: // const_expr: const_expr POWER const_expr
#line 535 "parser.yy"
                              {yylhs.value.as < Data > () = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::POW).eval(const_stack);}
#line 1980 "parser.tab.cc"
    break;

  case 89: // const_expr: const_expr EQUAL const_expr
#line 536 "parser.yy"
                              {yylhs.value.as < Data > () = BinaryExpression(make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::EQ).eval(const_stack);}
#line 1986 "parser.tab.cc"
    break;

  case 90: // const_expr: const_expr NOT_EQUAL const_expr
#line 537 "parser.yy"
                                  {yylhs.value.as < Data > () = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::NEQ).eval(const_stack);}
#line 1992 "parser.tab.cc"
    break;

  case 91: // const_expr: const_expr GREATER_THAN const_expr
#line 538 "parser.yy"
                                     {yylhs.value.as < Data > () = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::GT).eval(const_stack);}
#line 1998 "parser.tab.cc"
    break;

  case 92: // const_expr: const_expr LESS_THAN const_expr
#line 539 "parser.yy"
                                  {yylhs.value.as < Data > () = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::LT).eval(const_stack);}
#line 2004 "parser.tab.cc"
    break;

  case 93: // const_expr: const_expr GREATER_THAN_EQ const_expr
#line 540 "parser.yy"
                                        {yylhs.value.as < Data > () = BinaryExpression(make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::EQ_GT).eval(const_stack);}
#line 2010 "parser.tab.cc"
    break;

  case 94: // const_expr: const_expr LESS_THAN_EQ const_expr
#line 541 "parser.yy"
                                     {yylhs.value.as < Data > () = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::EQ_LT).eval(const_stack);}
#line 2016 "parser.tab.cc"
    break;

  case 95: // const_expr: const_expr AND const_expr
#line 542 "parser.yy"
                            {yylhs.value.as < Data > () = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::AND).eval(const_stack);}
#line 2022 "parser.tab.cc"
    break;

  case 96: // const_expr: const_expr OR const_expr
#line 543 "parser.yy"
                           {yylhs.value.as < Data > () = BinaryExpression(make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::OR).eval(const_stack);}
#line 2028 "parser.tab.cc"
    break;

  case 97: // const_expr: const_expr XOR const_expr
#line 544 "parser.yy"
                            {yylhs.value.as < Data > () = BinaryExpression (make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::XOR).eval(const_stack);}
#line 2034 "parser.tab.cc"
    break;

  case 98: // const_expr: const_expr NEITHER const_expr
#line 545 "parser.yy"
                                {yylhs.value.as < Data > () = BinaryExpression(make_shared<LiteralExpression>(make_shared<Data>(yystack_[2].value.as < Data > ())),make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), BinaryExpression::NEITHER).eval(const_stack);}
#line 2040 "parser.tab.cc"
    break;

  case 99: // const_expr: MINUS const_expr
#line 546 "parser.yy"
                   {yylhs.value.as < Data > () = UnaryExpression (make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), UnaryExpression::INV).eval(const_stack);}
#line 2046 "parser.tab.cc"
    break;

  case 100: // const_expr: NOT const_expr
#line 547 "parser.yy"
                 {yylhs.value.as < Data > () = UnaryExpression (make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < Data > ())), UnaryExpression::NOT).eval(const_stack);}
#line 2052 "parser.tab.cc"
    break;

  case 101: // const_expr: LEFT_PARENTHESES const_expr RIGHT_PARENTHESES
#line 548 "parser.yy"
                                                {yylhs.value.as < Data > () = yystack_[1].value.as < Data > ();}
#line 2058 "parser.tab.cc"
    break;

  case 102: // expr_list: %empty
#line 551 "parser.yy"
                  { yylhs.value.as < vector<shared_ptr<Expression>> > () = vector<shared_ptr<Expression>>(); }
#line 2064 "parser.tab.cc"
    break;

  case 103: // expr_list: expr COMMA expr_list
#line 552 "parser.yy"
                       {
    yystack_[0].value.as < vector<shared_ptr<Expression>> > ().push_back(yystack_[2].value.as < shared_ptr<Expression> > ());
    yylhs.value.as < vector<shared_ptr<Expression>> > () = move(yystack_[0].value.as < vector<shared_ptr<Expression>> > ());
}
#line 2073 "parser.tab.cc"
    break;

  case 104: // expr_list: expr
#line 556 "parser.yy"
       { yylhs.value.as < vector<shared_ptr<Expression>> > () = {yystack_[0].value.as < shared_ptr<Expression> > ()}; }
#line 2079 "parser.tab.cc"
    break;

  case 105: // @11: %empty
#line 561 "parser.yy"
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
#line 2106 "parser.tab.cc"
    break;

  case 106: // function: FUNC LEFT_PARENTHESES id_list RIGHT_PARENTHESES COLUMN EOL @11 program ENDFUNC
#line 583 "parser.yy"
               {
    yystack_[2].value.as < shared_ptr<Function> > ()->attach_program(yystack_[1].value.as < shared_ptr<Program> > ());
    yylhs.value.as < shared_ptr<Function> > () = yystack_[2].value.as < shared_ptr<Function> > ();
    interpreter.pop_scope();
    interpreter.pop_function();
}
#line 2117 "parser.tab.cc"
    break;

  case 107: // @12: %empty
#line 591 "parser.yy"
{
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
#line 2143 "parser.tab.cc"
    break;

  case 108: // function: FUNC LEFT_PARENTHESES id_list RIGHT_PARENTHESES COLUMN @12 statement ENDFUNC
#line 612 "parser.yy"
                 {
    yystack_[2].value.as < shared_ptr<Function> > ()->attach_program(make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1 + yystack_[2].value.as < shared_ptr<Function> > ()->arg_count()));
    yylhs.value.as < shared_ptr<Function> > () = yystack_[2].value.as < shared_ptr<Function> > ();
    interpreter.pop_scope();
    interpreter.pop_function();
}
#line 2154 "parser.tab.cc"
    break;

  case 109: // id_list: %empty
#line 620 "parser.yy"
                { yylhs.value.as < vector<string> > () = vector<string>(); }
#line 2160 "parser.tab.cc"
    break;

  case 110: // id_list: ID COMMA id_list
#line 621 "parser.yy"
                  {
    yystack_[0].value.as < vector<string> > ().push_back(yystack_[2].value.as < string > ());
    yylhs.value.as < vector<string> > () = move(yystack_[0].value.as < vector<string> > ());
}
#line 2169 "parser.tab.cc"
    break;

  case 111: // id_list: ID
#line 625 "parser.yy"
     { yylhs.value.as < vector<string> > () = {yystack_[0].value.as < string > ()}; }
#line 2175 "parser.tab.cc"
    break;


#line 2179 "parser.tab.cc"

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


  const short CS_Parser::yypact_ninf_ = -152;

  const signed char CS_Parser::yytable_ninf_ = -21;

  const short
  CS_Parser::yypact_[] =
  {
    -152,     2,   284,  -152,  -152,  -152,   -27,    12,    12,   -23,
     -18,    12,  -152,  -152,  -152,  -152,    12,  -152,  -152,  -152,
    -152,   928,  -152,   -16,    15,    12,    12,   -13,     1,    12,
       3,   103,   203,   257,  -152,  1224,  1282,  -152,  -152,  -152,
    -152,  -152,   152,    -3,    61,    49,    17,    12,  1224,  1224,
     928,   928,  -152,  1198,  -152,  -152,  1061,  1224,    -8,    -6,
    1224,     5,  -152,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
     928,   928,   928,   928,   928,   928,   928,   928,   928,   928,
     928,   928,   928,   928,   928,   928,  -152,   905,    26,    -3,
      49,  -152,    12,   696,    12,    12,    19,    37,  -152,   152,
     152,     0,     0,    18,     0,    61,    61,    61,    61,    61,
      61,  1267,  1249,  1249,  1249,    38,    -3,    -3,    85,    85,
    -152,    85,    49,    49,    49,    49,    49,    49,   992,  1302,
    1302,  1302,   928,    12,  -152,  1224,  -152,    53,  1161,   967,
      -6,    47,  -152,  1282,  -152,   328,    12,   -30,    12,    12,
      67,  -152,    68,   -19,  1086,    50,  -152,  1014,  1111,  -152,
     856,  -152,   856,    55,  -152,   736,   776,    12,    71,    72,
    -152,    62,  -152,    65,   816,  -152,    53,  -152,    69,  1136,
    -152,   856,  -152,   856,   372,  -152,   420,  -152,  -152,    76,
     328,  -152,   472,  -152,    84,  -152,    90,  -152,    91,  -152,
    -152,   516,  -152,  -152,  -152,  -152,   856,   560,  -152,   608,
    -152,  -152,  -152,    93,  -152,  -152,   656,  -152,  -152
  };

  const signed char
  CS_Parser::yydefact_[] =
  {
       3,     0,     0,     1,    75,    76,     0,     0,     0,     0,
       0,     0,    12,    15,    13,    16,    17,    77,    78,    79,
      80,     0,     6,     0,    52,     0,     0,     0,     0,     0,
       0,    73,    74,    72,    11,     0,    53,    82,     7,    73,
      74,    72,    70,    53,    71,    53,     0,   102,    14,    18,
       0,     0,    81,     0,     2,    23,     0,     9,     0,   109,
      19,     0,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,   104,     0,    99,
     100,   101,     0,     0,     0,     0,   111,     0,     5,    54,
      55,    56,    58,    59,    57,    60,    63,    62,    65,    64,
      61,    66,    67,    68,    69,     0,    83,    84,    85,    87,
      88,    86,    89,    92,    91,    94,    93,    90,    95,    96,
      97,    98,     0,   102,    22,    24,     3,    49,     0,     0,
     109,     0,    21,    26,   103,    49,     0,     0,     0,     0,
      43,   110,   107,     0,     0,     0,    29,     0,     0,    41,
       0,   105,     0,     0,    27,     0,     0,     0,    39,    47,
       3,     0,     3,     0,     0,     3,    49,     3,     0,     0,
      37,     0,    45,     0,     0,    44,     0,   108,     3,     0,
      49,    51,     0,    32,    35,     3,     0,     3,     0,    42,
     106,     0,    31,    50,    30,    33,     0,     0,    40,     0,
      48,    28,     3,     0,    38,    46,     0,    36,    34
  };

  const short
  CS_Parser::yypgoto_[] =
  {
    -152,  -152,    87,   -72,    -2,    11,  -152,  -152,    64,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -151,    13,
      43,   -78,  -152,  -152,  -152,    -7
  };

  const unsigned char
  CS_Parser::yydefgoto_[] =
  {
       0,     1,     2,    30,    39,    40,   102,   142,    41,    34,
     222,   216,   205,   191,   180,   170,   207,   193,   157,    35,
      36,    98,    37,   182,   172,   107
  };

  const short
  CS_Parser::yytable_[] =
  {
      31,   125,     3,   104,   163,    82,    83,    84,    61,    85,
      67,    38,   165,    32,   166,     4,     5,    46,    47,     7,
      42,    44,    54,   173,    48,   174,    55,    58,    96,    49,
       8,   147,     9,    10,   106,   201,    79,    59,    56,    57,
     105,    62,    60,   108,    17,    18,    19,    20,    21,   213,
      43,    45,    24,    25,    79,    80,    81,    82,    83,    84,
      97,    85,    28,   144,    53,   154,    33,    63,    64,    65,
      66,    67,   150,    68,   151,   152,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    97,    99,   100,    84,   156,    79,   181,   162,
     183,    31,   176,   186,   188,   169,   171,   184,   -20,   190,
     192,   195,   199,   203,    32,   145,   197,   148,   149,   206,
     212,   208,   215,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   218,
     220,   -20,   227,   161,   223,   -20,   -20,   -20,     0,     0,
       0,     0,   -20,    31,   -20,     0,    97,     0,     0,     0,
      65,    66,    67,     0,    68,     0,    32,    33,    31,   164,
      31,   167,   168,    31,    31,     0,     0,     0,     0,     0,
       0,    32,    31,    32,     0,   153,    32,    32,    79,    31,
     189,    31,    31,     0,    31,    32,     0,     0,    31,     0,
      31,     0,    32,     0,    32,    32,     0,    32,    -8,    31,
       0,    32,     0,    32,    31,    31,     0,    31,     0,    33,
       0,     0,    32,     0,    31,     0,     0,    32,    32,     0,
      32,     0,     0,   155,    33,     0,    33,    32,     0,    33,
      33,    -8,     0,     0,     0,    -8,    -8,    -8,    33,     0,
       0,     0,    -8,     0,    -8,    33,     0,    33,    33,     0,
      33,     0,   -10,     0,    33,     0,    33,   194,     0,   196,
       0,     0,   200,     0,   202,    33,     0,     0,     0,     0,
      33,    33,     0,    33,     0,   211,     0,     4,     5,     6,
      33,     7,   217,     0,   219,   -10,     0,     0,     0,   -10,
     -10,   -10,     8,     0,     9,    10,   -10,     0,   -10,   226,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,    22,    23,    24,    25,     0,     0,     0,    26,
      27,     4,     5,     6,    28,     7,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     8,     0,     9,    10,
       0,     0,     0,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,    22,     0,    24,    25,
       0,   156,     0,    26,    27,     4,     5,     6,    28,     7,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     9,    10,     0,     0,     0,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
      22,     0,    24,    25,     0,     0,     0,    26,    27,     0,
       0,   209,    28,     4,     5,     6,    29,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       9,    10,     0,     0,     0,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,    22,     0,
      24,    25,     0,     0,     0,    26,    27,     0,     0,     0,
      28,   210,     0,     0,    29,     4,     5,     6,     0,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     9,    10,     0,     0,     0,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
      22,     0,    24,    25,     0,     0,   214,    26,    27,     4,
       5,     6,    28,     7,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    22,     0,    24,    25,     0,     0,
     221,    26,    27,     4,     5,     6,    28,     7,     0,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       9,    10,     0,     0,     0,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,    22,     0,
      24,    25,     0,     0,     0,    26,    27,     0,     0,   224,
      28,     4,     5,     6,    29,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     0,     9,    10,
       0,     0,     0,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,    22,     0,    24,    25,
       0,     0,     0,    26,    27,     0,     0,   225,    28,     4,
       5,     6,    29,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    22,     0,    24,    25,     0,     4,
       5,    26,    27,     7,     0,   228,    28,     0,     0,     0,
      29,     0,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,   146,     0,    24,    25,     0,     4,
       5,    26,    27,     7,     0,     0,    28,     0,     0,     0,
      29,     0,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,   185,     0,    24,    25,     0,     4,
       5,    26,    27,     7,     0,     0,    28,     0,     0,     0,
      29,     0,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,   187,     0,    24,    25,     0,     4,
       5,    26,    27,     7,     0,     0,    28,     0,     0,     0,
      29,     0,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,   198,     0,    24,    25,     0,     4,
       5,    26,    27,     7,     0,     0,    28,     0,     0,     0,
      29,     0,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,    24,    25,     0,     0,
       0,    26,    27,     0,     0,     0,    28,     0,     0,     0,
      29,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,     0,    74,     0,     0,    75,    76,    77,
      78,     4,     5,     0,     0,    50,     0,     0,     0,     0,
       0,    79,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   143,     0,
      17,    18,    19,    20,    21,     0,     0,     0,    52,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    28,    68,
      69,    70,    71,    72,    73,     0,    74,     0,     0,    75,
      76,    77,    78,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    79,    85,    86,    87,    88,    89,    90,
       0,    91,     0,     0,   159,     0,     0,     0,     0,   160,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,     0,    74,     0,     0,    75,    76,    77,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   177,     0,     0,     0,     0,   178,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,     0,
      74,     0,     0,    75,    76,    77,    78,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,    79,    68,    69,
      70,    71,    72,    73,     0,    74,     0,     0,    75,    76,
      77,    78,     0,   103,     0,     0,     0,    63,    64,    65,
      66,    67,    79,    68,    69,    70,    71,    72,    73,     0,
      74,     0,     0,    75,    76,    77,    78,     0,   175,     0,
       0,     0,    63,    64,    65,    66,    67,    79,    68,    69,
      70,    71,    72,    73,     0,    74,     0,     0,    75,    76,
      77,    78,     0,   179,     0,     0,     0,    63,    64,    65,
      66,    67,    79,    68,    69,    70,    71,    72,    73,     0,
      74,     0,     0,    75,    76,    77,    78,     0,   204,     0,
       0,     0,     0,     0,     0,     0,     0,    79,     0,     0,
       0,     0,     0,     0,    80,    81,    82,    83,    84,   158,
      85,    86,    87,    88,    89,    90,     0,    91,     0,     0,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,   101,    68,    69,    70,    71,
      72,    73,     0,    74,     0,     0,    75,    76,    77,    78,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      79,    68,    69,    70,    71,    72,    73,     0,    74,     0,
       0,    75,     0,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,    79,    74,     0,    80,    81,
      82,    83,    84,     0,    85,    86,    87,    88,    89,    90,
       0,    91,     0,    79,    92,    93,    94,    95,    80,    81,
      82,    83,    84,     0,    85,    86,    87,    88,    89,    90,
       0,    91,     0,     0,    92
  };

  const short
  CS_Parser::yycheck_[] =
  {
       2,    79,     0,    11,   155,     8,     9,    10,     5,    12,
      10,    38,    42,     2,    44,     3,     4,    40,    36,     7,
       7,     8,    38,    42,    11,    44,    11,    40,    11,    16,
      18,   103,    20,    21,    40,   186,    36,    36,    25,    26,
      48,    38,    29,    38,    32,    33,    34,    35,    36,   200,
       7,     8,    40,    41,    36,     6,     7,     8,     9,    10,
      47,    12,    50,    37,    21,   143,     2,     6,     7,     8,
       9,    10,    53,    12,    37,    37,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    50,    51,    10,    43,    36,   170,    52,
     172,   103,    52,   175,   176,    38,    38,    52,     5,    38,
      38,    49,   184,    44,   103,   102,    51,   104,   105,   191,
      44,   193,    38,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    49,
      49,    38,    49,   150,   216,    42,    43,    44,    -1,    -1,
      -1,    -1,    49,   155,    51,    -1,   143,    -1,    -1,    -1,
       8,     9,    10,    -1,    12,    -1,   155,   103,   170,   156,
     172,   158,   159,   175,   176,    -1,    -1,    -1,    -1,    -1,
      -1,   170,   184,   172,    -1,   142,   175,   176,    36,   191,
     177,   193,   194,    -1,   196,   184,    -1,    -1,   200,    -1,
     202,    -1,   191,    -1,   193,   194,    -1,   196,     5,   211,
      -1,   200,    -1,   202,   216,   217,    -1,   219,    -1,   155,
      -1,    -1,   211,    -1,   226,    -1,    -1,   216,   217,    -1,
     219,    -1,    -1,   146,   170,    -1,   172,   226,    -1,   175,
     176,    38,    -1,    -1,    -1,    42,    43,    44,   184,    -1,
      -1,    -1,    49,    -1,    51,   191,    -1,   193,   194,    -1,
     196,    -1,     5,    -1,   200,    -1,   202,   180,    -1,   182,
      -1,    -1,   185,    -1,   187,   211,    -1,    -1,    -1,    -1,
     216,   217,    -1,   219,    -1,   198,    -1,     3,     4,     5,
     226,     7,   205,    -1,   207,    38,    -1,    -1,    -1,    42,
      43,    44,    18,    -1,    20,    21,    49,    -1,    51,   222,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    -1,    -1,    -1,    45,
      46,     3,     4,     5,    50,     7,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    -1,    40,    41,
      -1,    43,    -1,    45,    46,     3,     4,     5,    50,     7,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    -1,    40,    41,    -1,    -1,    -1,    45,    46,    -1,
      -1,    49,    50,     3,     4,     5,    54,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    -1,
      40,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      50,    51,    -1,    -1,    54,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    -1,    40,    41,    -1,    -1,    44,    45,    46,     3,
       4,     5,    50,     7,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    -1,    40,    41,    -1,    -1,
      44,    45,    46,     3,     4,     5,    50,     7,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    -1,
      40,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,    49,
      50,     3,     4,     5,    54,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    -1,    40,    41,
      -1,    -1,    -1,    45,    46,    -1,    -1,    49,    50,     3,
       4,     5,    54,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    -1,    40,    41,    -1,     3,
       4,    45,    46,     7,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    -1,    40,    41,    -1,     3,
       4,    45,    46,     7,    -1,    -1,    50,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    -1,    40,    41,    -1,     3,
       4,    45,    46,     7,    -1,    -1,    50,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    -1,    40,    41,    -1,     3,
       4,    45,    46,     7,    -1,    -1,    50,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    -1,    40,    41,    -1,     3,
       4,    45,    46,     7,    -1,    -1,    50,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    41,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      54,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    -1,    19,    -1,    -1,    22,    23,    24,
      25,     3,     4,    -1,    -1,     7,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    50,    12,
      13,    14,    15,    16,    17,    -1,    19,    -1,    -1,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    36,    12,    13,    14,    15,    16,    17,
      -1,    19,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    -1,    19,    -1,    -1,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    52,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    -1,
      19,    -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    36,    12,    13,
      14,    15,    16,    17,    -1,    19,    -1,    -1,    22,    23,
      24,    25,    -1,    52,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    36,    12,    13,    14,    15,    16,    17,    -1,
      19,    -1,    -1,    22,    23,    24,    25,    -1,    52,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    36,    12,    13,
      14,    15,    16,    17,    -1,    19,    -1,    -1,    22,    23,
      24,    25,    -1,    52,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    36,    12,    13,    14,    15,    16,    17,    -1,
      19,    -1,    -1,    22,    23,    24,    25,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,    48,
      12,    13,    14,    15,    16,    17,    -1,    19,    -1,    -1,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    37,    12,    13,    14,    15,
      16,    17,    -1,    19,    -1,    -1,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      36,    12,    13,    14,    15,    16,    17,    -1,    19,    -1,
      -1,    22,    -1,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    36,    19,    -1,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      -1,    19,    -1,    36,    22,    23,    24,    25,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      -1,    19,    -1,    -1,    22
  };

  const signed char
  CS_Parser::yystos_[] =
  {
       0,    56,    57,     0,     3,     4,     5,     7,    18,    20,
      21,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    38,    39,    40,    41,    45,    46,    50,    54,
      58,    59,    60,    63,    64,    74,    75,    77,    38,    59,
      60,    63,    74,    75,    74,    75,    40,    36,    74,    74,
       7,    18,    40,    75,    38,    11,    74,    74,    40,    36,
      74,     5,    38,     6,     7,     8,     9,    10,    12,    13,
      14,    15,    16,    17,    19,    22,    23,    24,    25,    36,
       6,     7,     8,     9,    10,    12,    13,    14,    15,    16,
      17,    19,    22,    23,    24,    25,    11,    74,    76,    75,
      75,    37,    61,    52,    11,    48,    40,    80,    38,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    76,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    62,    53,    37,    74,    38,    58,    74,    74,
      53,    37,    37,    75,    76,    57,    43,    73,    48,    47,
      52,    80,    52,    73,    74,    42,    44,    74,    74,    38,
      70,    38,    79,    42,    44,    52,    52,    47,    52,    52,
      69,    58,    78,    58,    52,    38,    58,    38,    58,    74,
      38,    68,    38,    72,    57,    49,    57,    51,    38,    58,
      57,    73,    57,    44,    52,    67,    58,    71,    58,    49,
      51,    57,    44,    73,    44,    38,    66,    57,    49,    57,
      49,    44,    65,    58,    49,    49,    57,    49,    49
  };

  const signed char
  CS_Parser::yyr1_[] =
  {
       0,    55,    56,    57,    57,    57,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    61,    60,    62,    60,    63,    63,    63,
      63,    63,    63,    65,    64,    66,    64,    67,    64,    68,
      64,    69,    64,    70,    64,    71,    64,    72,    64,    73,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    76,    76,    76,    78,    77,    79,    77,    80,
      80,    80
  };

  const signed char
  CS_Parser::yyr2_[] =
  {
       0,     2,     3,     0,     3,     4,     2,     3,     1,     2,
       1,     1,     1,     1,     2,     1,     1,     1,     2,     2,
       1,     4,     4,     0,     4,     0,     5,     7,    11,     6,
      10,    10,     9,     0,    13,     0,    12,     0,    11,     0,
      10,     0,     9,     0,     8,     0,    11,     0,    10,     0,
       6,     5,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     0,     3,     1,     0,     9,     0,     8,     0,
       3,     1
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
  "RIGHT_PARENTHESES", "EOL", "STOP", "ID", "IF", "ELSE", "ELIF", "ENDIF",
  "PRINT", "FOR", "BY", "TO", "ENDFOR", "FUNC", "ENDFUNC", "COLUMN",
  "COMMA", "GIVE", "$accept", "input", "program", "statement",
  "function_call", "assignment", "@1", "@2", "if_statement",
  "for_counter_loop", "@3", "@4", "@5", "@6", "@7", "@8", "@9", "@10",
  "elif_branch", "expr", "const_expr", "expr_list", "function", "@11",
  "@12", "id_list", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  CS_Parser::yyrline_[] =
  {
       0,   112,   112,   118,   124,   132,   140,   143,   148,   151,
     155,   158,   161,   168,   175,   182,   189,   196,   199,   202,
     205,   210,   213,   228,   227,   248,   247,   267,   271,   275,
     279,   283,   287,   294,   293,   314,   313,   334,   333,   354,
     353,   374,   373,   394,   393,   415,   414,   436,   435,   457,
     458,   462,   468,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   512,   513,   514,   515,   516,
     517,   518,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   551,   552,   556,   561,   559,   591,   589,   620,
     621,   625
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
    };
    // Last valid token kind.
    const int code_max = 309;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 7 "parser.yy"
} // CS
#line 3068 "parser.tab.cc"

#line 627 "parser.yy"


void CS::CS_Parser::error( const location_type &l, const std::string &err_message )
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
        //
    }
    interpreter.pop_scope();
}
