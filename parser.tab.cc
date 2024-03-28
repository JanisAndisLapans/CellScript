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
#line 41 "parser.yy"


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

#line 93 "parser.tab.cc"


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
#line 186 "parser.tab.cc"

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
      case symbol_kind::S_78_3: // @3
        value.copy< DataPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_76_1: // @1
      case symbol_kind::S_77_2: // @2
      case symbol_kind::S_84_6: // @6
      case symbol_kind::S_85_7: // @7
      case symbol_kind::S_86_8: // @8
      case symbol_kind::S_87_9: // @9
      case symbol_kind::S_88_10: // @10
      case symbol_kind::S_89_11: // @11
      case symbol_kind::S_90_12: // @12
      case symbol_kind::S_91_13: // @13
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
      case symbol_kind::S_97_14: // @14
      case symbol_kind::S_98_15: // @15
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

      case symbol_kind::S_while_loop: // while_loop
        value.copy< shared_ptr<WhileLoop> > (YY_MOVE (that.value));
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

      case symbol_kind::S_81_4: // $@4
      case symbol_kind::S_82_5: // $@5
        value.copy< void* > (YY_MOVE (that.value));
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
      case symbol_kind::S_78_3: // @3
        value.move< DataPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_76_1: // @1
      case symbol_kind::S_77_2: // @2
      case symbol_kind::S_84_6: // @6
      case symbol_kind::S_85_7: // @7
      case symbol_kind::S_86_8: // @8
      case symbol_kind::S_87_9: // @9
      case symbol_kind::S_88_10: // @10
      case symbol_kind::S_89_11: // @11
      case symbol_kind::S_90_12: // @12
      case symbol_kind::S_91_13: // @13
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
      case symbol_kind::S_97_14: // @14
      case symbol_kind::S_98_15: // @15
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

      case symbol_kind::S_while_loop: // while_loop
        value.move< shared_ptr<WhileLoop> > (YY_MOVE (s.value));
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

      case symbol_kind::S_81_4: // $@4
      case symbol_kind::S_82_5: // $@5
        value.move< void* > (YY_MOVE (s.value));
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
      case symbol_kind::S_78_3: // @3
        value.YY_MOVE_OR_COPY< DataPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_76_1: // @1
      case symbol_kind::S_77_2: // @2
      case symbol_kind::S_84_6: // @6
      case symbol_kind::S_85_7: // @7
      case symbol_kind::S_86_8: // @8
      case symbol_kind::S_87_9: // @9
      case symbol_kind::S_88_10: // @10
      case symbol_kind::S_89_11: // @11
      case symbol_kind::S_90_12: // @12
      case symbol_kind::S_91_13: // @13
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
      case symbol_kind::S_97_14: // @14
      case symbol_kind::S_98_15: // @15
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

      case symbol_kind::S_while_loop: // while_loop
        value.YY_MOVE_OR_COPY< shared_ptr<WhileLoop> > (YY_MOVE (that.value));
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

      case symbol_kind::S_81_4: // $@4
      case symbol_kind::S_82_5: // $@5
        value.YY_MOVE_OR_COPY< void* > (YY_MOVE (that.value));
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
      case symbol_kind::S_78_3: // @3
        value.move< DataPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_76_1: // @1
      case symbol_kind::S_77_2: // @2
      case symbol_kind::S_84_6: // @6
      case symbol_kind::S_85_7: // @7
      case symbol_kind::S_86_8: // @8
      case symbol_kind::S_87_9: // @9
      case symbol_kind::S_88_10: // @10
      case symbol_kind::S_89_11: // @11
      case symbol_kind::S_90_12: // @12
      case symbol_kind::S_91_13: // @13
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
      case symbol_kind::S_97_14: // @14
      case symbol_kind::S_98_15: // @15
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

      case symbol_kind::S_while_loop: // while_loop
        value.move< shared_ptr<WhileLoop> > (YY_MOVE (that.value));
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

      case symbol_kind::S_81_4: // $@4
      case symbol_kind::S_82_5: // $@5
        value.move< void* > (YY_MOVE (that.value));
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
      case symbol_kind::S_78_3: // @3
        value.copy< DataPtr > (that.value);
        break;

      case symbol_kind::S_76_1: // @1
      case symbol_kind::S_77_2: // @2
      case symbol_kind::S_84_6: // @6
      case symbol_kind::S_85_7: // @7
      case symbol_kind::S_86_8: // @8
      case symbol_kind::S_87_9: // @9
      case symbol_kind::S_88_10: // @10
      case symbol_kind::S_89_11: // @11
      case symbol_kind::S_90_12: // @12
      case symbol_kind::S_91_13: // @13
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
      case symbol_kind::S_97_14: // @14
      case symbol_kind::S_98_15: // @15
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

      case symbol_kind::S_while_loop: // while_loop
        value.copy< shared_ptr<WhileLoop> > (that.value);
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

      case symbol_kind::S_81_4: // $@4
      case symbol_kind::S_82_5: // $@5
        value.copy< void* > (that.value);
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
      case symbol_kind::S_78_3: // @3
        value.move< DataPtr > (that.value);
        break;

      case symbol_kind::S_76_1: // @1
      case symbol_kind::S_77_2: // @2
      case symbol_kind::S_84_6: // @6
      case symbol_kind::S_85_7: // @7
      case symbol_kind::S_86_8: // @8
      case symbol_kind::S_87_9: // @9
      case symbol_kind::S_88_10: // @10
      case symbol_kind::S_89_11: // @11
      case symbol_kind::S_90_12: // @12
      case symbol_kind::S_91_13: // @13
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
      case symbol_kind::S_97_14: // @14
      case symbol_kind::S_98_15: // @15
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

      case symbol_kind::S_while_loop: // while_loop
        value.move< shared_ptr<WhileLoop> > (that.value);
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

      case symbol_kind::S_81_4: // $@4
      case symbol_kind::S_82_5: // $@5
        value.move< void* > (that.value);
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
      case symbol_kind::S_78_3: // @3
        yylhs.value.emplace< DataPtr > ();
        break;

      case symbol_kind::S_76_1: // @1
      case symbol_kind::S_77_2: // @2
      case symbol_kind::S_84_6: // @6
      case symbol_kind::S_85_7: // @7
      case symbol_kind::S_86_8: // @8
      case symbol_kind::S_87_9: // @9
      case symbol_kind::S_88_10: // @10
      case symbol_kind::S_89_11: // @11
      case symbol_kind::S_90_12: // @12
      case symbol_kind::S_91_13: // @13
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
      case symbol_kind::S_97_14: // @14
      case symbol_kind::S_98_15: // @15
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

      case symbol_kind::S_while_loop: // while_loop
        yylhs.value.emplace< shared_ptr<WhileLoop> > ();
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

      case symbol_kind::S_81_4: // $@4
      case symbol_kind::S_82_5: // $@5
        yylhs.value.emplace< void* > ();
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
#line 140 "parser.yy"
                           { 
    yystack_[1].value.as < shared_ptr<Program> > ()->run();
    return 0;
    }
#line 1231 "parser.tab.cc"
    break;

  case 3: // program: %empty
#line 146 "parser.yy"
                {
    if(interpreter.is_sep_scope())
        yylhs.value.as < shared_ptr<Program> > () = make_shared<Program>(interpreter.get_scope_number(),interpreter.get_top_scope_size());
    else
        yylhs.value.as < shared_ptr<Program> > () = make_shared<Program>(interpreter.get_scope_number());  
}
#line 1242 "parser.tab.cc"
    break;

  case 4: // program: program statement EOL
#line 152 "parser.yy"
                       {
    if(yystack_[1].value.as < shared_ptr<Statement> > () != nullptr)
    {
        yystack_[2].value.as < shared_ptr<Program> > ()->attach_statement(yystack_[1].value.as < shared_ptr<Statement> > ());
    }
    yylhs.value.as < shared_ptr<Program> > () = yystack_[2].value.as < shared_ptr<Program> > ();
    yystack_[2].value.as < shared_ptr<Program> > ()->set_callstack_size(interpreter.get_top_scope_size());
}
#line 1255 "parser.tab.cc"
    break;

  case 5: // program: program statement ONE_LINE_COMMENT EOL
#line 160 "parser.yy"
                                        {
    if(yystack_[2].value.as < shared_ptr<Statement> > () != nullptr)
    {
        yystack_[3].value.as < shared_ptr<Program> > ()->attach_statement(yystack_[2].value.as < shared_ptr<Statement> > ());
    }
    yylhs.value.as < shared_ptr<Program> > () = yystack_[3].value.as < shared_ptr<Program> > ();
    yystack_[3].value.as < shared_ptr<Program> > ()->set_callstack_size(interpreter.get_top_scope_size());
}
#line 1268 "parser.tab.cc"
    break;

  case 6: // program: program EOL
#line 168 "parser.yy"
             {
    yylhs.value.as < shared_ptr<Program> > () = yystack_[1].value.as < shared_ptr<Program> > ();
}
#line 1276 "parser.tab.cc"
    break;

  case 7: // program: program ONE_LINE_COMMENT EOL
#line 171 "parser.yy"
                              {
    yylhs.value.as < shared_ptr<Program> > () = yystack_[2].value.as < shared_ptr<Program> > ();
}
#line 1284 "parser.tab.cc"
    break;

  case 8: // statement: assignment
#line 176 "parser.yy"
                      {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<AssignStatement> > ();
}
#line 1292 "parser.tab.cc"
    break;

  case 9: // statement: expr LEFT_BRACKET expr RIGHT_BRACKET ASSIGN expr
#line 179 "parser.yy"
                                                   {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<IndexAssignStatement>(yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[3].value.as < shared_ptr<Expression> > (), yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1300 "parser.tab.cc"
    break;

  case 10: // statement: PRINT expr_val
#line 182 "parser.yy"
                 {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<PrintStatement>(yystack_[0].value.as < shared_ptr<Expression> > ());

}
#line 1309 "parser.tab.cc"
    break;

  case 11: // statement: READ id_list
#line 186 "parser.yy"
               {
    vector<int> arg_inds;
    for(const auto& id_name : yystack_[0].value.as < vector<string> > ())
    {
        arg_inds.push_back(get_variable(id_name));
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<ReadStatement>(arg_inds);
}
#line 1322 "parser.tab.cc"
    break;

  case 12: // statement: if_statement
#line 194 "parser.yy"
               {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<IfStatement> > ();
}
#line 1330 "parser.tab.cc"
    break;

  case 13: // statement: for_counter_loop
#line 197 "parser.yy"
                 {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<ForCounterLoop> > ();
}
#line 1338 "parser.tab.cc"
    break;

  case 14: // statement: while_loop
#line 200 "parser.yy"
             {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<WhileLoop> > ();
}
#line 1346 "parser.tab.cc"
    break;

  case 15: // statement: BREAK
#line 203 "parser.yy"
       {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: BREAK statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<BreakStatement>();
}
#line 1358 "parser.tab.cc"
    break;

  case 16: // statement: BREAK_ALL
#line 210 "parser.yy"
           {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: BREAK ALL statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<BreakAll>();
}
#line 1370 "parser.tab.cc"
    break;

  case 17: // statement: ADVANCE expr
#line 217 "parser.yy"
              {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: ADVANCE statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Advance>(yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1382 "parser.tab.cc"
    break;

  case 18: // statement: CONTINUE
#line 224 "parser.yy"
          {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: ADVANCE statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Advance>(make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))));
}
#line 1394 "parser.tab.cc"
    break;

  case 19: // statement: REPEAT
#line 231 "parser.yy"
        {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: REPEAT statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Advance>(make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))));
}
#line 1406 "parser.tab.cc"
    break;

  case 20: // statement: RETURN
#line 238 "parser.yy"
        {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Return>(make_shared<LiteralExpression>(make_shared<Data>(make_shared<NullType>())));
}
#line 1414 "parser.tab.cc"
    break;

  case 21: // statement: RETURN expr
#line 241 "parser.yy"
             {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Return>(yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1422 "parser.tab.cc"
    break;

  case 22: // statement: GIVE expr
#line 244 "parser.yy"
           {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Give>(yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1430 "parser.tab.cc"
    break;

  case 23: // statement: function_call
#line 247 "parser.yy"
               {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<FunctionStatement> > ();
}
#line 1438 "parser.tab.cc"
    break;

  case 24: // function_call: expr_val LEFT_PARENTHESES expr_list RIGHT_PARENTHESES
#line 252 "parser.yy"
                                                                     { 
    yylhs.value.as < shared_ptr<FunctionStatement> > () = make_shared<FunctionStatement>(yystack_[1].value.as < vector<shared_ptr<Expression>> > (), yystack_[3].value.as < shared_ptr<Expression> > ()); 
}
#line 1446 "parser.tab.cc"
    break;

  case 25: // function_call: SELF LEFT_PARENTHESES expr_list RIGHT_PARENTHESES
#line 255 "parser.yy"
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
#line 1463 "parser.tab.cc"
    break;

  case 26: // @1: %empty
#line 270 "parser.yy"
     {
    yylhs.value.as < int > () = get_variable(yystack_[1].value.as < string > ());
    if(yylhs.value.as < int > () == -1) { // Error
        return 1;
    }
}
#line 1474 "parser.tab.cc"
    break;

  case 27: // assignment: ID ASSIGN @1 expr_val
#line 276 "parser.yy"
        {
    yylhs.value.as < shared_ptr<AssignStatement> > () = make_shared<AssignStatement>(yystack_[1].value.as < int > (), yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1482 "parser.tab.cc"
    break;

  case 28: // @2: %empty
#line 280 "parser.yy"
     {
    yylhs.value.as < int > () = get_variable(yystack_[1].value.as < string > (), false);
    if(yylhs.value.as < int > () == -1) { // Error
        return 1;
    }
}
#line 1493 "parser.tab.cc"
    break;

  case 29: // assignment: ID PLUS_ASSIGN @2 expr_val
#line 286 "parser.yy"
        {
    yylhs.value.as < shared_ptr<AssignStatement> > () = make_shared<AssignStatement>(yystack_[1].value.as < int > (), yystack_[0].value.as < shared_ptr<Expression> > (), make_shared<PlusAssignmentOperation>());
}
#line 1501 "parser.tab.cc"
    break;

  case 30: // @3: %empty
#line 290 "parser.yy"
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
#line 1519 "parser.tab.cc"
    break;

  case 31: // assignment: CONST ID ASSIGN @3 expr_val
#line 303 "parser.yy"
        {
    if(!yystack_[0].value.as < shared_ptr<Expression> > ()->is_const())
    {
        cout << "ERROR: CONST assignment requires a CONST expression." <<endl;
        return 1;
    }

    *yystack_[1].value.as < DataPtr > () = yystack_[0].value.as < shared_ptr<Expression> > ()->eval(const_stack);
    yylhs.value.as < shared_ptr<AssignStatement> > () = nullptr;
}
#line 1534 "parser.tab.cc"
    break;

  case 32: // if_statement: IF expr_val COLUMN EOL program elif_branch ENDIF
#line 315 "parser.yy"
                                                               {
    yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[2].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()));
}
#line 1543 "parser.tab.cc"
    break;

  case 33: // if_statement: IF expr_val COLUMN EOL program elif_branch ELSE COLUMN EOL program ENDIF
#line 319 "parser.yy"
                                                                           {
    yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[9].value.as < shared_ptr<Expression> > (), yystack_[6].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), yystack_[1].value.as < shared_ptr<Program> > ());
}
#line 1552 "parser.tab.cc"
    break;

  case 34: // if_statement: IF expr_val COLUMN statement elif_branch ENDIF
#line 323 "parser.yy"
                                                 {
    yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[4].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[2].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()));
}
#line 1561 "parser.tab.cc"
    break;

  case 35: // if_statement: IF expr_val COLUMN statement elif_branch ELSE COLUMN EOL program ENDIF
#line 327 "parser.yy"
                                                                         {
    yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[8].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[6].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), yystack_[1].value.as < shared_ptr<Program> > ());
}
#line 1570 "parser.tab.cc"
    break;

  case 36: // if_statement: IF expr_val COLUMN EOL program elif_branch ELSE COLUMN statement ENDIF
#line 331 "parser.yy"
                                                                         {
    yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[8].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
}
#line 1579 "parser.tab.cc"
    break;

  case 37: // if_statement: IF expr_val COLUMN statement elif_branch ELSE COLUMN statement ENDIF
#line 335 "parser.yy"
                                                                       {
    yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[7].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[5].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
}
#line 1588 "parser.tab.cc"
    break;

  case 38: // if_statement: IF expr_val COLUMN statement ELSE COLUMN statement
#line 339 "parser.yy"
                                                    {
    vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> ifs = {make_pair(yystack_[5].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[3].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1))};
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(ifs), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
}
#line 1597 "parser.tab.cc"
    break;

  case 39: // if_statement: IF expr_val COLUMN statement
#line 343 "parser.yy"
                              {
    vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> ifs = {make_pair(yystack_[2].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1))};
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(ifs));
}
#line 1606 "parser.tab.cc"
    break;

  case 40: // $@4: %empty
#line 350 "parser.yy"
        {
    interpreter.mark_is_in_loop(true);
}
#line 1614 "parser.tab.cc"
    break;

  case 41: // while_loop: WHILE expr_val COLUMN EOL $@4 program ENDWHILE
#line 353 "parser.yy"
                 {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<WhileLoop> > () = make_shared<WhileLoop>(yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1624 "parser.tab.cc"
    break;

  case 42: // $@5: %empty
#line 359 "parser.yy"
        {
    interpreter.mark_is_in_loop(true);
}
#line 1632 "parser.tab.cc"
    break;

  case 43: // while_loop: WHILE expr_val COLUMN $@5 statement
#line 362 "parser.yy"
          {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<WhileLoop> > () = make_shared<WhileLoop>(yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1642 "parser.tab.cc"
    break;

  case 44: // @6: %empty
#line 369 "parser.yy"
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
#line 1661 "parser.tab.cc"
    break;

  case 45: // for_counter_loop: FOR ID ASSIGN expr_val TO expr_val BY expr_val COLUMN EOL @6 program ENDFOR
#line 383 "parser.yy"
               {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), yystack_[9].value.as < shared_ptr<Expression> > (), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1671 "parser.tab.cc"
    break;

  case 46: // @7: %empty
#line 389 "parser.yy"
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
#line 1690 "parser.tab.cc"
    break;

  case 47: // for_counter_loop: FOR ID ASSIGN expr_val TO expr_val BY expr_val COLUMN @7 statement
#line 403 "parser.yy"
          {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[1].value.as < int > (), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1700 "parser.tab.cc"
    break;

  case 48: // @8: %empty
#line 409 "parser.yy"
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
#line 1719 "parser.tab.cc"
    break;

  case 49: // for_counter_loop: FOR ID ASSIGN expr_val TO expr_val COLUMN EOL @8 program ENDFOR
#line 423 "parser.yy"
              {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1729 "parser.tab.cc"
    break;

  case 50: // @9: %empty
#line 429 "parser.yy"
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
#line 1748 "parser.tab.cc"
    break;

  case 51: // for_counter_loop: FOR ID ASSIGN expr_val TO expr_val COLUMN @9 statement
#line 443 "parser.yy"
         {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[1].value.as < int > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1758 "parser.tab.cc"
    break;

  case 52: // @10: %empty
#line 449 "parser.yy"
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
#line 1777 "parser.tab.cc"
    break;

  case 53: // for_counter_loop: FOR ID TO expr_val COLUMN EOL @10 program ENDFOR
#line 463 "parser.yy"
              {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[5].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1787 "parser.tab.cc"
    break;

  case 54: // @11: %empty
#line 469 "parser.yy"
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
#line 1806 "parser.tab.cc"
    break;

  case 55: // for_counter_loop: FOR ID TO expr_val COLUMN @11 statement
#line 483 "parser.yy"
         {
    
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[1].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1817 "parser.tab.cc"
    break;

  case 56: // @12: %empty
#line 490 "parser.yy"
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
#line 1836 "parser.tab.cc"
    break;

  case 57: // for_counter_loop: FOR ID TO expr_val BY expr_val COLUMN EOL @12 program ENDFOR
#line 504 "parser.yy"
              {

    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1847 "parser.tab.cc"
    break;

  case 58: // @13: %empty
#line 511 "parser.yy"
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
#line 1866 "parser.tab.cc"
    break;

  case 59: // for_counter_loop: FOR ID TO expr_val BY expr_val COLUMN @13 statement
#line 525 "parser.yy"
          {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[1].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1876 "parser.tab.cc"
    break;

  case 60: // elif_branch: %empty
#line 532 "parser.yy"
                    {yylhs.value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > () = vector<pair<shared_ptr<Expression>, shared_ptr<Program>>>(); }
#line 1882 "parser.tab.cc"
    break;

  case 61: // elif_branch: ELIF expr_val COLUMN EOL program elif_branch
#line 533 "parser.yy"
                                               {
    yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[4].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > () = move(yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ());
}
#line 1891 "parser.tab.cc"
    break;

  case 62: // elif_branch: ELIF expr_val COLUMN statement elif_branch
#line 537 "parser.yy"
                                             {
    yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > () = move(yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ());
}
#line 1900 "parser.tab.cc"
    break;

  case 63: // expr: DEC
#line 543 "parser.yy"
          { yylhs.value.as < shared_ptr<Expression> > () = make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(yystack_[0].value.as < string > ()))); }
#line 1906 "parser.tab.cc"
    break;

  case 64: // expr: STR
#line 544 "parser.yy"
      { yylhs.value.as < shared_ptr<Expression> > () = make_shared<LiteralExpression>( make_shared<Data>(make_shared<String>(move(yystack_[0].value.as < string > ())))); }
#line 1912 "parser.tab.cc"
    break;

  case 65: // expr: TRUE
#line 545 "parser.yy"
       { yylhs.value.as < shared_ptr<Expression> > () =  make_shared<LiteralExpression>(make_shared<Data>(make_shared<Boolean>(true))); }
#line 1918 "parser.tab.cc"
    break;

  case 66: // expr: FALSE
#line 546 "parser.yy"
        { yylhs.value.as < shared_ptr<Expression> > () = make_shared<LiteralExpression>( make_shared<Data>(make_shared<Boolean>(false))); }
#line 1924 "parser.tab.cc"
    break;

  case 67: // expr: NULL_TOKEN
#line 547 "parser.yy"
             { yylhs.value.as < shared_ptr<Expression> > () =  make_shared<LiteralExpression>(make_shared<Data>(make_shared<NullType>())); }
#line 1930 "parser.tab.cc"
    break;

  case 68: // expr: INF
#line 548 "parser.yy"
      { yylhs.value.as < shared_ptr<Expression> > () =  make_shared<LiteralExpression>(make_shared<Data>(make_shared<InfType>())); }
#line 1936 "parser.tab.cc"
    break;

  case 69: // expr: ID
#line 549 "parser.yy"
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
#line 1961 "parser.tab.cc"
    break;

  case 70: // expr: function
#line 569 "parser.yy"
           { yylhs.value.as < shared_ptr<Expression> > () =  make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < shared_ptr<Function> > ())); }
#line 1967 "parser.tab.cc"
    break;

  case 71: // expr: expr PLUS expr
#line 570 "parser.yy"
                 {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::ADD);}
#line 1973 "parser.tab.cc"
    break;

  case 72: // expr: expr MINUS expr
#line 571 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::SUB);}
#line 1979 "parser.tab.cc"
    break;

  case 73: // expr: expr TIMES expr
#line 572 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::MULT);}
#line 1985 "parser.tab.cc"
    break;

  case 74: // expr: expr MOD expr
#line 573 "parser.yy"
                {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::MOD);}
#line 1991 "parser.tab.cc"
    break;

  case 75: // expr: expr DIVIDE expr
#line 574 "parser.yy"
                   {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::DIV);}
#line 1997 "parser.tab.cc"
    break;

  case 76: // expr: expr POWER expr
#line 575 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::POW);}
#line 2003 "parser.tab.cc"
    break;

  case 77: // expr: expr EQUAL expr
#line 576 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::EQ);}
#line 2009 "parser.tab.cc"
    break;

  case 78: // expr: expr NOT_EQUAL expr
#line 577 "parser.yy"
                      {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::NEQ);}
#line 2015 "parser.tab.cc"
    break;

  case 79: // expr: expr GREATER_THAN expr
#line 578 "parser.yy"
                         {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::GT);}
#line 2021 "parser.tab.cc"
    break;

  case 80: // expr: expr LESS_THAN expr
#line 579 "parser.yy"
                      {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::LT);}
#line 2027 "parser.tab.cc"
    break;

  case 81: // expr: expr GREATER_THAN_EQ expr
#line 580 "parser.yy"
                            {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::EQ_GT);}
#line 2033 "parser.tab.cc"
    break;

  case 82: // expr: expr LESS_THAN_EQ expr
#line 581 "parser.yy"
                         {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::EQ_LT);}
#line 2039 "parser.tab.cc"
    break;

  case 83: // expr: expr AND expr
#line 582 "parser.yy"
                {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::AND);}
#line 2045 "parser.tab.cc"
    break;

  case 84: // expr: expr OR expr
#line 583 "parser.yy"
               {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::OR);}
#line 2051 "parser.tab.cc"
    break;

  case 85: // expr: expr XOR expr
#line 584 "parser.yy"
                {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::XOR);}
#line 2057 "parser.tab.cc"
    break;

  case 86: // expr: expr NEITHER expr
#line 585 "parser.yy"
                    {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::NEITHER);}
#line 2063 "parser.tab.cc"
    break;

  case 87: // expr: expr AS NumType
#line 586 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression>(yystack_[2].value.as < shared_ptr<Expression> > (), UnaryExpression::TO_NUM);}
#line 2069 "parser.tab.cc"
    break;

  case 88: // expr: expr AS BoolType
#line 587 "parser.yy"
                   {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression>(yystack_[2].value.as < shared_ptr<Expression> > (), UnaryExpression::TO_BOOL);}
#line 2075 "parser.tab.cc"
    break;

  case 89: // expr: expr AS StrType
#line 588 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression>(yystack_[2].value.as < shared_ptr<Expression> > (), UnaryExpression::TO_STR);}
#line 2081 "parser.tab.cc"
    break;

  case 90: // expr: MINUS expr
#line 589 "parser.yy"
             {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression> (yystack_[0].value.as < shared_ptr<Expression> > (), UnaryExpression::INV);}
#line 2087 "parser.tab.cc"
    break;

  case 91: // expr: NOT expr
#line 590 "parser.yy"
           {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression> (yystack_[0].value.as < shared_ptr<Expression> > (), UnaryExpression::NOT);}
#line 2093 "parser.tab.cc"
    break;

  case 92: // expr: if_statement
#line 591 "parser.yy"
               { yylhs.value.as < shared_ptr<Expression> > () = make_shared<StatementExpression> (yystack_[0].value.as < shared_ptr<IfStatement> > ()); }
#line 2099 "parser.tab.cc"
    break;

  case 93: // expr: function_call
#line 592 "parser.yy"
                { yylhs.value.as < shared_ptr<Expression> > () = make_shared<StatementExpression> (yystack_[0].value.as < shared_ptr<FunctionStatement> > ()); }
#line 2105 "parser.tab.cc"
    break;

  case 94: // expr: assignment
#line 593 "parser.yy"
             { yylhs.value.as < shared_ptr<Expression> > () = make_shared<StatementExpression> (yystack_[0].value.as < shared_ptr<AssignStatement> > ());}
#line 2111 "parser.tab.cc"
    break;

  case 95: // expr: LEFT_PARENTHESES expr RIGHT_PARENTHESES
#line 594 "parser.yy"
                                          {yylhs.value.as < shared_ptr<Expression> > () = yystack_[1].value.as < shared_ptr<Expression> > ();}
#line 2117 "parser.tab.cc"
    break;

  case 96: // expr: LEFT_BRACKET expr_list RIGHT_BRACKET
#line 595 "parser.yy"
                                       { yylhs.value.as < shared_ptr<Expression> > () = make_shared<InititializerListExpression>(yystack_[1].value.as < vector<shared_ptr<Expression>> > ()); }
#line 2123 "parser.tab.cc"
    break;

  case 97: // expr: expr LEFT_BRACKET expr RIGHT_BRACKET
#line 596 "parser.yy"
                                       { yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yystack_[3].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Expression> > (), BinaryExpression::INDEX); }
#line 2129 "parser.tab.cc"
    break;

  case 98: // expr: LEN LEFT_PARENTHESES expr RIGHT_PARENTHESES
#line 597 "parser.yy"
                                              { yylhs.value.as < shared_ptr<Expression> > () = make_shared<LengthExpression>(yystack_[1].value.as < shared_ptr<Expression> > ()); }
#line 2135 "parser.tab.cc"
    break;

  case 99: // expr_val: expr
#line 600 "parser.yy"
               {
    yylhs.value.as < shared_ptr<Expression> > () = yystack_[0].value.as < shared_ptr<Expression> > ()->reduce_const();
}
#line 2143 "parser.tab.cc"
    break;

  case 100: // expr_list: %empty
#line 605 "parser.yy"
                  { yylhs.value.as < vector<shared_ptr<Expression>> > () = vector<shared_ptr<Expression>>(); }
#line 2149 "parser.tab.cc"
    break;

  case 101: // expr_list: expr_val COMMA expr_list
#line 606 "parser.yy"
                           {
    yystack_[0].value.as < vector<shared_ptr<Expression>> > ().push_back(yystack_[2].value.as < shared_ptr<Expression> > ());
    yylhs.value.as < vector<shared_ptr<Expression>> > () = move(yystack_[0].value.as < vector<shared_ptr<Expression>> > ());
}
#line 2158 "parser.tab.cc"
    break;

  case 102: // expr_list: expr_val
#line 610 "parser.yy"
           { yylhs.value.as < vector<shared_ptr<Expression>> > () = {yystack_[0].value.as < shared_ptr<Expression> > ()}; }
#line 2164 "parser.tab.cc"
    break;

  case 103: // @14: %empty
#line 615 "parser.yy"
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
#line 2191 "parser.tab.cc"
    break;

  case 104: // function: FUNC LEFT_PARENTHESES id_list RIGHT_PARENTHESES COLUMN EOL @14 program ENDFUNC
#line 637 "parser.yy"
               {
    yystack_[2].value.as < shared_ptr<Function> > ()->attach_program(yystack_[1].value.as < shared_ptr<Program> > ());
    yylhs.value.as < shared_ptr<Function> > () = yystack_[2].value.as < shared_ptr<Function> > ();
    interpreter.pop_scope();
    interpreter.pop_function();
}
#line 2202 "parser.tab.cc"
    break;

  case 105: // @15: %empty
#line 645 "parser.yy"
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
#line 2229 "parser.tab.cc"
    break;

  case 106: // function: FUNC LEFT_PARENTHESES id_list RIGHT_PARENTHESES COLUMN @15 statement
#line 667 "parser.yy"
         {
    yystack_[1].value.as < shared_ptr<Function> > ()->attach_program(make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1 + yystack_[1].value.as < shared_ptr<Function> > ()->arg_count()));
    yylhs.value.as < shared_ptr<Function> > () = yystack_[1].value.as < shared_ptr<Function> > ();
    interpreter.pop_scope();
    interpreter.pop_function();
}
#line 2240 "parser.tab.cc"
    break;

  case 107: // id_list: %empty
#line 675 "parser.yy"
                { yylhs.value.as < vector<string> > () = vector<string>(); }
#line 2246 "parser.tab.cc"
    break;

  case 108: // id_list: ID COMMA id_list
#line 676 "parser.yy"
                  {
    yystack_[0].value.as < vector<string> > ().push_back(yystack_[2].value.as < string > ());
    yylhs.value.as < vector<string> > () = move(yystack_[0].value.as < vector<string> > ());
}
#line 2255 "parser.tab.cc"
    break;

  case 109: // id_list: ID
#line 680 "parser.yy"
     { yylhs.value.as < vector<string> > () = {yystack_[0].value.as < string > ()}; }
#line 2261 "parser.tab.cc"
    break;


#line 2265 "parser.tab.cc"

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


  const short CS_Parser::yypact_ninf_ = -145;

  const signed char CS_Parser::yytable_ninf_ = -1;

  const short
  CS_Parser::yypact_[] =
  {
    -145,    13,   314,  -145,  -145,  -145,   -41,  1089,  1089,    -6,
     -19,  1089,  -145,  -145,  -145,  -145,  1089,  -145,  -145,  -145,
    -145,  1089,  -145,  -145,    12,  1089,  1089,     5,     6,  1089,
      27,  1089,    30,  1089,    26,  -145,  -145,  -145,  -145,  -145,
    1271,    70,  -145,  -145,  -145,  -145,  -145,    98,    -3,   107,
    1089,  1296,  1296,  1220,  -145,  -145,  1296,   -33,    70,     9,
      27,   -23,    58,  -145,  1296,  1089,   -26,    59,    84,  -145,
    1089,  1089,  1089,  1089,  1089,  1089,  1089,  1089,  1089,  1089,
    1089,  1089,  1089,  1089,  1089,  1089,    52,  1089,  1089,  1089,
    -145,    89,  -145,  1089,  1089,   844,  1089,  1089,    90,    91,
      27,  1245,  1089,  -145,  -145,    98,    98,     2,     2,    65,
       2,    -3,    -3,    -3,    -3,    -3,    -3,  1322,    36,    36,
      36,  -145,  -145,  -145,  1131,    95,  1156,  1089,  -145,    70,
      70,  -145,   -31,   -15,   -11,    79,  -145,  1040,  -145,  -145,
    -145,   129,  -145,  -145,    70,   371,    81,  1089,    75,  1089,
    1089,    99,   103,  -145,  -145,  1089,    76,  1040,    53,    87,
    -145,    60,    54,  -145,  1040,  -145,  1040,   420,  1296,    88,
    -145,  -145,   893,   942,  1089,   106,   113,  -145,  -145,  -145,
    -145,  -145,   991,  -145,   109,  -145,   102,    61,  -145,  1040,
    -145,  1040,   469,   526,  -145,   118,   371,  -145,   583,  -145,
     126,  -145,  -145,  -145,  -145,  -145,  -145,   632,  -145,  -145,
    -145,  -145,  1040,   681,   738,  -145,  -145,  -145,  -145,  -145,
     795,  -145
  };

  const signed char
  CS_Parser::yydefact_[] =
  {
       3,     0,     0,     1,    63,    64,     0,     0,     0,     0,
       0,     0,    15,    18,    16,    19,    20,    65,    66,    67,
      68,     0,     6,     2,    69,     0,     0,     0,     0,     0,
     107,     0,     0,   100,     0,    23,     8,    12,    14,    13,
      99,     0,    70,     7,    93,    94,    92,    90,    91,     0,
     100,    17,    21,    99,    26,    28,    99,     0,    10,     0,
     107,     0,   109,    11,    22,     0,   102,     0,     0,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,     0,
      30,     0,    95,     0,     0,     0,     0,     0,     0,    42,
     107,    99,   100,    96,     5,    71,    72,    73,    75,    76,
      74,    77,    80,    79,    82,    81,    78,    83,    84,    85,
      86,    87,    88,    89,    99,     0,    99,     0,    25,    27,
      29,     3,    39,     0,     0,     0,    40,     0,   108,    98,
     101,    97,    24,    97,    31,    60,     0,     0,     0,     0,
       0,    54,   105,     3,    43,     0,     0,     0,     0,     0,
      34,     0,     0,    52,     0,   103,     0,     0,     9,     0,
      32,    38,     0,     0,     0,    50,    58,     3,    55,     3,
     106,    41,     0,     3,    60,     3,     0,     0,    48,     0,
      56,     0,     0,     0,     3,     0,    60,    62,     0,    37,
      46,     3,    51,     3,    59,    53,   104,     0,    36,    61,
      35,    44,     0,     0,     0,    33,     3,    47,    49,    57,
       0,    45
  };

  const short
  CS_Parser::yypgoto_[] =
  {
    -145,  -145,   108,   -28,    -2,    31,  -145,  -145,  -145,    64,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -144,     3,   239,     1,  -145,  -145,  -145,   -39
  };

  const unsigned char
  CS_Parser::yydefgoto_[] =
  {
       0,     1,     2,    34,    44,    45,    93,    94,   127,    46,
      38,   153,   137,    39,   216,   212,   201,   189,   177,   164,
     203,   191,   148,    40,    41,    67,    42,   179,   166,    63
  };

  const unsigned char
  CS_Parser::yytable_[] =
  {
      35,   156,    43,    70,    71,    72,    73,    74,    88,    75,
      47,    48,    74,     3,    51,    88,   146,   147,    88,    52,
      96,    98,    50,    54,    53,    55,    88,    95,    56,    56,
      88,    68,    56,    36,    64,   102,    56,    99,   149,    49,
     197,   150,    70,    71,    72,    73,    74,    60,    75,   151,
      59,    91,   209,    56,    76,    77,    78,    79,    80,    86,
      81,   138,    97,    82,    86,    89,    37,   132,   101,    69,
      89,    65,    62,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   125,
     124,    56,   126,    35,    88,    88,    56,    56,    86,    56,
      56,    88,    88,   140,    89,    56,    72,    73,    74,   154,
      75,    88,   174,   172,   176,   121,   122,   123,    90,   100,
     175,   200,   159,   169,   160,   170,    36,   104,   103,   171,
      56,   128,   135,    89,   136,    35,   178,   142,   180,   152,
     155,   157,   163,    35,   184,   186,   165,   173,   182,   188,
      56,   199,    56,    56,   195,    35,   190,   147,   168,    37,
      86,   202,    35,   204,    35,    35,    89,   208,    36,   211,
      35,    35,     0,     0,     0,     0,    36,    56,     0,     0,
      35,     0,     0,     0,   217,     0,     0,    35,    36,    35,
      35,    35,     0,     0,    35,    36,    35,    36,    36,     0,
       0,    37,     0,    36,    36,    35,     0,     0,     0,    37,
      35,    35,    35,    36,     0,     0,     0,     0,    35,     0,
      36,    37,    36,    36,    36,     0,     0,    36,    37,    36,
      37,    37,     0,     0,     0,     0,    37,    37,    36,   145,
       0,     0,     0,    36,    36,    36,    37,     0,     0,     0,
       0,    36,     0,    37,     0,    37,    37,    37,     0,     0,
      37,   167,    37,     0,    57,    58,     0,     0,    61,     0,
       0,    37,    66,     0,     0,     0,    37,    37,    37,     0,
       0,     0,     0,     0,    37,   192,     0,   193,     0,    66,
       0,   196,     0,   198,     0,     0,     0,     0,     0,     0,
       0,     0,   207,     0,     0,     0,     0,     0,     0,   213,
       0,   214,     0,     0,     0,     0,     0,     4,     5,     6,
       0,     7,     0,     0,   220,     0,     0,    66,     0,     0,
       0,     0,   129,   130,     0,   133,   134,     8,     0,     9,
      10,    66,     0,     0,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,    22,    23,    24,
      25,     0,     0,     0,    26,    27,   144,     0,     0,    28,
       0,    29,     0,    30,     4,     5,     6,     0,     7,     0,
      31,    32,    33,     0,     0,     0,   158,     0,   161,   162,
       0,     0,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   187,    22,     0,    24,    25,     0,   147,
       0,    26,    27,     4,     5,     6,    28,     7,    29,     0,
      30,     0,     0,     0,     0,     0,     0,    31,    32,    33,
       0,     0,     0,     8,     0,     9,    10,     0,     0,     0,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,    22,     0,    24,    25,     0,     0,     0,
      26,    27,     4,     5,     6,    28,     7,    29,   181,    30,
       0,     0,     0,     0,     0,     0,    31,    32,    33,     0,
       0,     0,     8,     0,     9,    10,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,    22,     0,    24,    25,     0,     0,     0,    26,
      27,     0,     0,   205,    28,     0,    29,     0,    30,     4,
       5,     6,     0,     7,     0,    31,    32,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,     9,    10,     0,     0,     0,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    22,
       0,    24,    25,     0,     0,     0,    26,    27,     0,     0,
       0,    28,   206,    29,     0,    30,     4,     5,     6,     0,
       7,     0,    31,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     0,     9,    10,
       0,     0,     0,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,    22,     0,    24,    25,
       0,     0,   210,    26,    27,     4,     5,     6,    28,     7,
      29,     0,    30,     0,     0,     0,     0,     0,     0,    31,
      32,    33,     0,     0,     0,     8,     0,     9,    10,     0,
       0,     0,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,    22,     0,    24,    25,     0,
       0,   215,    26,    27,     4,     5,     6,    28,     7,    29,
       0,    30,     0,     0,     0,     0,     0,     0,    31,    32,
      33,     0,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    22,     0,    24,    25,     0,     0,
       0,    26,    27,     0,     0,   218,    28,     0,    29,     0,
      30,     4,     5,     6,     0,     7,     0,    31,    32,    33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     0,     9,    10,     0,     0,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,    22,     0,    24,    25,     0,     0,     0,    26,    27,
       0,     0,   219,    28,     0,    29,     0,    30,     4,     5,
       6,     0,     7,     0,    31,    32,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       9,    10,     0,     0,     0,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,    22,     0,
      24,    25,     0,     0,     0,    26,    27,     4,     5,   221,
      28,     7,    29,     0,    30,     0,     0,     0,     0,     0,
       0,    31,    32,    33,     0,     0,     0,     8,     0,     9,
      10,     0,     0,     0,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,   131,     0,    24,
      25,     0,     0,     0,    26,    27,     4,     5,     0,    28,
       7,    29,     0,    30,     0,     0,     0,     0,     0,     0,
      31,    32,    33,     0,     0,     0,     8,     0,     9,    10,
       0,     0,     0,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,   183,     0,    24,    25,
       0,     0,     0,    26,    27,     4,     5,     0,    28,     7,
      29,     0,    30,     0,     0,     0,     0,     0,     0,    31,
      32,    33,     0,     0,     0,     8,     0,     9,    10,     0,
       0,     0,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,   185,     0,    24,    25,     0,
       0,     0,    26,    27,     4,     5,     0,    28,     7,    29,
       0,    30,     0,     0,     0,     0,     0,     0,    31,    32,
      33,     0,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,   194,     0,    24,    25,     0,     0,
       0,    26,    27,     4,     5,     0,    28,     7,    29,     0,
      30,     0,     0,     0,     0,     0,     0,    31,    32,    33,
       0,     0,     0,     8,     0,     9,    10,     0,     0,     0,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     0,    24,    25,     0,     0,     0,
      26,    27,     4,     5,     0,    28,     7,    29,     0,    30,
       0,     0,     0,     0,     0,     0,    31,    32,    33,     0,
       0,     0,     8,     0,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    18,    19,    20,
      21,     0,     0,     0,    24,    25,     0,    70,    71,    72,
      73,    74,     0,    75,    28,     0,     0,     0,     0,    76,
      77,    78,    79,    80,     0,    81,    32,    33,    82,    83,
      84,    85,    70,    71,    72,    73,    74,     0,    75,     0,
       0,     0,     0,     0,    76,    77,    78,    79,    80,     0,
      81,     0,     0,    82,    83,    84,    85,     0,     0,     0,
       0,     0,     0,    86,     0,     0,     0,     0,     0,    89,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,     0,
       0,     0,     0,     0,    89,   143,    70,    71,    72,    73,
      74,     0,    75,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,     0,    81,     0,     0,    82,    83,    84,
      85,    70,    71,    72,    73,    74,     0,    75,     0,     0,
       0,     0,    92,    76,    77,    78,    79,    80,     0,    81,
       0,     0,    82,    83,    84,    85,     0,    70,    71,    72,
      73,    74,    86,    75,     0,     0,     0,   139,    89,    76,
      77,    78,    79,    80,     0,    81,     0,     0,    82,    83,
      84,    85,    70,    71,    72,    73,    74,    86,    75,     0,
       0,     0,     0,    89,    76,    77,    78,    79,    80,     0,
      81,     0,     0,    82,    83,    84,    85,     0,    70,    71,
      72,    73,    74,    86,    75,     0,     0,     0,     0,    87,
      76,    77,    78,    79,    80,     0,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,     0,     0,     0,     0,     0,
      89
  };

  const short
  CS_Parser::yycheck_[] =
  {
       2,   145,    43,     6,     7,     8,     9,    10,    41,    12,
       7,     8,    10,     0,    11,    41,    47,    48,    41,    16,
      11,    60,    41,    11,    21,    13,    41,    60,    25,    26,
      41,     5,    29,     2,    31,    61,    33,    60,    53,    45,
     184,    52,     6,     7,     8,     9,    10,    41,    12,    60,
      45,    50,   196,    50,    18,    19,    20,    21,    22,    62,
      24,   100,    53,    27,    62,    68,     2,    95,    65,    43,
      68,    41,    45,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    88,
      87,    88,    89,    95,    41,    41,    93,    94,    62,    96,
      97,    41,    41,   102,    68,   102,     8,     9,    10,   137,
      12,    41,    52,    60,    60,    63,    64,    65,    11,    61,
      60,    60,    47,    47,    49,    49,    95,    43,    69,   157,
     127,    42,    42,    68,    43,   137,   164,    42,   166,    60,
      11,    60,    43,   145,   172,   173,    43,    60,    60,    43,
     147,    49,   149,   150,   182,   157,    43,    48,   155,    95,
      62,   189,   164,   191,   166,   167,    68,    49,   137,    43,
     172,   173,    -1,    -1,    -1,    -1,   145,   174,    -1,    -1,
     182,    -1,    -1,    -1,   212,    -1,    -1,   189,   157,   191,
     192,   193,    -1,    -1,   196,   164,   198,   166,   167,    -1,
      -1,   137,    -1,   172,   173,   207,    -1,    -1,    -1,   145,
     212,   213,   214,   182,    -1,    -1,    -1,    -1,   220,    -1,
     189,   157,   191,   192,   193,    -1,    -1,   196,   164,   198,
     166,   167,    -1,    -1,    -1,    -1,   172,   173,   207,   131,
      -1,    -1,    -1,   212,   213,   214,   182,    -1,    -1,    -1,
      -1,   220,    -1,   189,    -1,   191,   192,   193,    -1,    -1,
     196,   153,   198,    -1,    25,    26,    -1,    -1,    29,    -1,
      -1,   207,    33,    -1,    -1,    -1,   212,   213,   214,    -1,
      -1,    -1,    -1,    -1,   220,   177,    -1,   179,    -1,    50,
      -1,   183,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,   201,
      -1,   203,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,   216,    -1,    -1,    88,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    97,    23,    -1,    25,
      26,   102,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    -1,    -1,    -1,    50,    51,   127,    -1,    -1,    55,
      -1,    57,    -1,    59,     3,     4,     5,    -1,     7,    -1,
      66,    67,    68,    -1,    -1,    -1,   147,    -1,   149,   150,
      -1,    -1,    -1,    -1,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   174,    43,    -1,    45,    46,    -1,    48,
      -1,    50,    51,     3,     4,     5,    55,     7,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      -1,    -1,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,
      50,    51,     3,     4,     5,    55,     7,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,
      -1,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    55,    -1,    57,    -1,    59,     3,
       4,     5,    -1,     7,    -1,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    25,    26,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,
      -1,    55,    56,    57,    -1,    59,     3,     4,     5,    -1,
       7,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    -1,    45,    46,
      -1,    -1,    49,    50,    51,     3,     4,     5,    55,     7,
      57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    -1,    -1,    23,    -1,    25,    26,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    -1,    45,    46,    -1,
      -1,    49,    50,    51,     3,     4,     5,    55,     7,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    -1,    -1,    -1,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    55,    -1,    57,    -1,
      59,     3,     4,     5,    -1,     7,    -1,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    43,    -1,    45,    46,    -1,    -1,    -1,    50,    51,
      -1,    -1,    54,    55,    -1,    57,    -1,    59,     3,     4,
       5,    -1,     7,    -1,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    -1,
      45,    46,    -1,    -1,    -1,    50,    51,     3,     4,    54,
      55,     7,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    23,    -1,    25,
      26,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    -1,    45,
      46,    -1,    -1,    -1,    50,    51,     3,     4,    -1,    55,
       7,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    -1,    -1,    -1,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    -1,    45,    46,
      -1,    -1,    -1,    50,    51,     3,     4,    -1,    55,     7,
      57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    -1,    -1,    23,    -1,    25,    26,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    -1,    45,    46,    -1,
      -1,    -1,    50,    51,     3,     4,    -1,    55,     7,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    -1,    -1,    -1,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,     3,     4,    -1,    55,     7,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      -1,    -1,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      50,    51,     3,     4,    -1,    55,     7,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,
      -1,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    45,    46,    -1,     6,     7,     8,
       9,    10,    -1,    12,    55,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    24,    67,    68,    27,    28,
      29,    30,     6,     7,     8,     9,    10,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      24,    -1,    -1,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,     6,     7,     8,     9,
      10,    -1,    12,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    27,    28,    29,
      30,     6,     7,     8,     9,    10,    -1,    12,    -1,    -1,
      -1,    -1,    42,    18,    19,    20,    21,    22,    -1,    24,
      -1,    -1,    27,    28,    29,    30,    -1,     6,     7,     8,
       9,    10,    62,    12,    -1,    -1,    -1,    42,    68,    18,
      19,    20,    21,    22,    -1,    24,    -1,    -1,    27,    28,
      29,    30,     6,     7,     8,     9,    10,    62,    12,    -1,
      -1,    -1,    -1,    68,    18,    19,    20,    21,    22,    -1,
      24,    -1,    -1,    27,    28,    29,    30,    -1,     6,     7,
       8,     9,    10,    62,    12,    -1,    -1,    -1,    -1,    68,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      68
  };

  const signed char
  CS_Parser::yystos_[] =
  {
       0,    71,    72,     0,     3,     4,     5,     7,    23,    25,
      26,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    43,    44,    45,    46,    50,    51,    55,    57,
      59,    66,    67,    68,    73,    74,    75,    79,    80,    83,
      93,    94,    96,    43,    74,    75,    79,    93,    93,    45,
      41,    93,    93,    93,    11,    13,    93,    94,    94,    45,
      41,    94,    45,    99,    93,    41,    94,    95,     5,    43,
       6,     7,     8,     9,    10,    12,    18,    19,    20,    21,
      22,    24,    27,    28,    29,    30,    62,    68,    41,    68,
      11,    95,    42,    76,    77,    60,    11,    53,    99,    60,
      61,    93,    61,    69,    43,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    63,    64,    65,    93,    95,    93,    78,    42,    94,
      94,    43,    73,    94,    94,    42,    43,    82,    99,    42,
      95,    69,    42,    69,    94,    72,    47,    48,    92,    53,
      52,    60,    60,    81,    73,    11,    92,    60,    94,    47,
      49,    94,    94,    43,    89,    43,    98,    72,    93,    47,
      49,    73,    60,    60,    52,    60,    60,    88,    73,    97,
      73,    58,    60,    43,    73,    43,    73,    94,    43,    87,
      43,    91,    72,    72,    43,    73,    72,    92,    72,    49,
      60,    86,    73,    90,    73,    54,    56,    72,    49,    92,
      49,    43,    85,    72,    72,    49,    84,    73,    54,    54,
      72,    54
  };

  const signed char
  CS_Parser::yyr1_[] =
  {
       0,    70,    71,    72,    72,    72,    72,    72,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    76,    75,    77,    75,
      78,    75,    79,    79,    79,    79,    79,    79,    79,    79,
      81,    80,    82,    80,    84,    83,    85,    83,    86,    83,
      87,    83,    88,    83,    89,    83,    90,    83,    91,    83,
      92,    92,    92,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    94,
      95,    95,    95,    97,    96,    98,    96,    99,    99,    99
  };

  const signed char
  CS_Parser::yyr2_[] =
  {
       0,     2,     2,     0,     3,     4,     2,     3,     1,     6,
       2,     2,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     2,     1,     4,     4,     0,     4,     0,     4,
       0,     5,     7,    11,     6,    10,    10,     9,     7,     4,
       0,     7,     0,     5,     0,    13,     0,    11,     0,    11,
       0,     9,     0,     9,     0,     7,     0,    11,     0,     9,
       0,     6,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     1,     3,     3,     4,     4,     1,
       0,     3,     1,     0,     9,     0,     7,     0,     3,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const CS_Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "DEC", "STR",
  "ONE_LINE_COMMENT", "PLUS", "MINUS", "TIMES", "DIVIDE", "POWER",
  "ASSIGN", "MOD", "PLUS_ASSIGN", "MINUS_ASSIGN", "TIMES_ASSIGN",
  "DIVIDE_ASSIGN", "MOD_ASSIGN", "EQUAL", "LESS_THAN", "GREATER_THAN",
  "LESS_THAN_EQ", "GREATER_THAN_EQ", "NOT", "NOT_EQUAL", "CONST", "SELF",
  "AND", "OR", "XOR", "NEITHER", "ADVANCE", "BREAK", "CONTINUE",
  "BREAK_ALL", "REPEAT", "RETURN", "TRUE", "FALSE", "NULL_TOKEN", "INF",
  "LEFT_PARENTHESES", "RIGHT_PARENTHESES", "EOL", "END_OF_FILE", "ID",
  "IF", "ELSE", "ELIF", "ENDIF", "PRINT", "FOR", "BY", "TO", "ENDFOR",
  "FUNC", "ENDFUNC", "WHILE", "ENDWHILE", "READ", "COLUMN", "COMMA", "AS",
  "NumType", "BoolType", "StrType", "GIVE", "LEN", "LEFT_BRACKET",
  "RIGHT_BRACKET", "$accept", "input", "program", "statement",
  "function_call", "assignment", "@1", "@2", "@3", "if_statement",
  "while_loop", "$@4", "$@5", "for_counter_loop", "@6", "@7", "@8", "@9",
  "@10", "@11", "@12", "@13", "elif_branch", "expr", "expr_val",
  "expr_list", "function", "@14", "@15", "id_list", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  CS_Parser::yyrline_[] =
  {
       0,   140,   140,   146,   152,   160,   168,   171,   176,   179,
     182,   186,   194,   197,   200,   203,   210,   217,   224,   231,
     238,   241,   244,   247,   252,   255,   270,   269,   280,   279,
     290,   289,   315,   319,   323,   327,   331,   335,   339,   343,
     350,   349,   359,   358,   369,   368,   389,   388,   409,   408,
     429,   428,   449,   448,   469,   468,   490,   489,   511,   510,
     532,   533,   537,   543,   544,   545,   546,   547,   548,   549,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   600,
     605,   606,   610,   615,   613,   645,   643,   675,   676,   680
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
    };
    // Last valid token kind.
    const int code_max = 324;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 7 "parser.yy"
} // CS
#line 3170 "parser.tab.cc"

#line 682 "parser.yy"


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
