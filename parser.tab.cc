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
      case symbol_kind::S_77_3: // @3
        value.copy< DataPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_75_1: // @1
      case symbol_kind::S_76_2: // @2
      case symbol_kind::S_83_6: // @6
      case symbol_kind::S_84_7: // @7
      case symbol_kind::S_85_8: // @8
      case symbol_kind::S_86_9: // @9
      case symbol_kind::S_87_10: // @10
      case symbol_kind::S_88_11: // @11
      case symbol_kind::S_89_12: // @12
      case symbol_kind::S_90_13: // @13
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
      case symbol_kind::S_96_14: // @14
      case symbol_kind::S_97_15: // @15
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

      case symbol_kind::S_80_4: // $@4
      case symbol_kind::S_81_5: // $@5
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
      case symbol_kind::S_77_3: // @3
        value.move< DataPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_75_1: // @1
      case symbol_kind::S_76_2: // @2
      case symbol_kind::S_83_6: // @6
      case symbol_kind::S_84_7: // @7
      case symbol_kind::S_85_8: // @8
      case symbol_kind::S_86_9: // @9
      case symbol_kind::S_87_10: // @10
      case symbol_kind::S_88_11: // @11
      case symbol_kind::S_89_12: // @12
      case symbol_kind::S_90_13: // @13
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
      case symbol_kind::S_96_14: // @14
      case symbol_kind::S_97_15: // @15
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

      case symbol_kind::S_80_4: // $@4
      case symbol_kind::S_81_5: // $@5
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
      case symbol_kind::S_77_3: // @3
        value.YY_MOVE_OR_COPY< DataPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_75_1: // @1
      case symbol_kind::S_76_2: // @2
      case symbol_kind::S_83_6: // @6
      case symbol_kind::S_84_7: // @7
      case symbol_kind::S_85_8: // @8
      case symbol_kind::S_86_9: // @9
      case symbol_kind::S_87_10: // @10
      case symbol_kind::S_88_11: // @11
      case symbol_kind::S_89_12: // @12
      case symbol_kind::S_90_13: // @13
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
      case symbol_kind::S_96_14: // @14
      case symbol_kind::S_97_15: // @15
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

      case symbol_kind::S_80_4: // $@4
      case symbol_kind::S_81_5: // $@5
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
      case symbol_kind::S_77_3: // @3
        value.move< DataPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_75_1: // @1
      case symbol_kind::S_76_2: // @2
      case symbol_kind::S_83_6: // @6
      case symbol_kind::S_84_7: // @7
      case symbol_kind::S_85_8: // @8
      case symbol_kind::S_86_9: // @9
      case symbol_kind::S_87_10: // @10
      case symbol_kind::S_88_11: // @11
      case symbol_kind::S_89_12: // @12
      case symbol_kind::S_90_13: // @13
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
      case symbol_kind::S_96_14: // @14
      case symbol_kind::S_97_15: // @15
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

      case symbol_kind::S_80_4: // $@4
      case symbol_kind::S_81_5: // $@5
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
      case symbol_kind::S_77_3: // @3
        value.copy< DataPtr > (that.value);
        break;

      case symbol_kind::S_75_1: // @1
      case symbol_kind::S_76_2: // @2
      case symbol_kind::S_83_6: // @6
      case symbol_kind::S_84_7: // @7
      case symbol_kind::S_85_8: // @8
      case symbol_kind::S_86_9: // @9
      case symbol_kind::S_87_10: // @10
      case symbol_kind::S_88_11: // @11
      case symbol_kind::S_89_12: // @12
      case symbol_kind::S_90_13: // @13
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
      case symbol_kind::S_96_14: // @14
      case symbol_kind::S_97_15: // @15
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

      case symbol_kind::S_80_4: // $@4
      case symbol_kind::S_81_5: // $@5
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
      case symbol_kind::S_77_3: // @3
        value.move< DataPtr > (that.value);
        break;

      case symbol_kind::S_75_1: // @1
      case symbol_kind::S_76_2: // @2
      case symbol_kind::S_83_6: // @6
      case symbol_kind::S_84_7: // @7
      case symbol_kind::S_85_8: // @8
      case symbol_kind::S_86_9: // @9
      case symbol_kind::S_87_10: // @10
      case symbol_kind::S_88_11: // @11
      case symbol_kind::S_89_12: // @12
      case symbol_kind::S_90_13: // @13
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
      case symbol_kind::S_96_14: // @14
      case symbol_kind::S_97_15: // @15
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

      case symbol_kind::S_80_4: // $@4
      case symbol_kind::S_81_5: // $@5
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
      case symbol_kind::S_77_3: // @3
        yylhs.value.emplace< DataPtr > ();
        break;

      case symbol_kind::S_75_1: // @1
      case symbol_kind::S_76_2: // @2
      case symbol_kind::S_83_6: // @6
      case symbol_kind::S_84_7: // @7
      case symbol_kind::S_85_8: // @8
      case symbol_kind::S_86_9: // @9
      case symbol_kind::S_87_10: // @10
      case symbol_kind::S_88_11: // @11
      case symbol_kind::S_89_12: // @12
      case symbol_kind::S_90_13: // @13
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
      case symbol_kind::S_96_14: // @14
      case symbol_kind::S_97_15: // @15
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

      case symbol_kind::S_80_4: // $@4
      case symbol_kind::S_81_5: // $@5
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

  case 11: // statement: if_statement
#line 186 "parser.yy"
               {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<IfStatement> > ();
}
#line 1317 "parser.tab.cc"
    break;

  case 12: // statement: for_counter_loop
#line 189 "parser.yy"
                 {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<ForCounterLoop> > ();
}
#line 1325 "parser.tab.cc"
    break;

  case 13: // statement: while_loop
#line 192 "parser.yy"
             {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<WhileLoop> > ();
}
#line 1333 "parser.tab.cc"
    break;

  case 14: // statement: BREAK
#line 195 "parser.yy"
       {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: BREAK statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<BreakStatement>();
}
#line 1345 "parser.tab.cc"
    break;

  case 15: // statement: BREAK_ALL
#line 202 "parser.yy"
           {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: BREAK ALL statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<BreakAll>();
}
#line 1357 "parser.tab.cc"
    break;

  case 16: // statement: ADVANCE expr
#line 209 "parser.yy"
              {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: ADVANCE statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Advance>(yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1369 "parser.tab.cc"
    break;

  case 17: // statement: CONTINUE
#line 216 "parser.yy"
          {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: ADVANCE statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Advance>(make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))));
}
#line 1381 "parser.tab.cc"
    break;

  case 18: // statement: REPEAT
#line 223 "parser.yy"
        {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: REPEAT statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Advance>(make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))));
}
#line 1393 "parser.tab.cc"
    break;

  case 19: // statement: RETURN
#line 230 "parser.yy"
        {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Return>(make_shared<LiteralExpression>(make_shared<Data>(make_shared<NullType>())));
}
#line 1401 "parser.tab.cc"
    break;

  case 20: // statement: RETURN expr
#line 233 "parser.yy"
             {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Return>(yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1409 "parser.tab.cc"
    break;

  case 21: // statement: GIVE expr
#line 236 "parser.yy"
           {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Give>(yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1417 "parser.tab.cc"
    break;

  case 22: // statement: function_call
#line 239 "parser.yy"
               {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<FunctionStatement> > ();
}
#line 1425 "parser.tab.cc"
    break;

  case 23: // function_call: expr_val LEFT_PARENTHESES expr_list RIGHT_PARENTHESES
#line 244 "parser.yy"
                                                                     { 
    yylhs.value.as < shared_ptr<FunctionStatement> > () = make_shared<FunctionStatement>(yystack_[1].value.as < vector<shared_ptr<Expression>> > (), yystack_[3].value.as < shared_ptr<Expression> > ()); 
}
#line 1433 "parser.tab.cc"
    break;

  case 24: // function_call: SELF LEFT_PARENTHESES expr_list RIGHT_PARENTHESES
#line 247 "parser.yy"
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
#line 1450 "parser.tab.cc"
    break;

  case 25: // @1: %empty
#line 262 "parser.yy"
     {
    yylhs.value.as < int > () = get_variable(yystack_[1].value.as < string > ());
    if(yylhs.value.as < int > () == -1) { // Error
        return 1;
    }
}
#line 1461 "parser.tab.cc"
    break;

  case 26: // assignment: ID ASSIGN @1 expr_val
#line 268 "parser.yy"
        {
    yylhs.value.as < shared_ptr<AssignStatement> > () = make_shared<AssignStatement>(yystack_[1].value.as < int > (), yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1469 "parser.tab.cc"
    break;

  case 27: // @2: %empty
#line 272 "parser.yy"
     {
    yylhs.value.as < int > () = get_variable(yystack_[1].value.as < string > (), false);
    if(yylhs.value.as < int > () == -1) { // Error
        return 1;
    }
}
#line 1480 "parser.tab.cc"
    break;

  case 28: // assignment: ID PLUS_ASSIGN @2 expr_val
#line 278 "parser.yy"
        {
    yylhs.value.as < shared_ptr<AssignStatement> > () = make_shared<AssignStatement>(yystack_[1].value.as < int > (), yystack_[0].value.as < shared_ptr<Expression> > (), make_shared<PlusAssignmentOperation>());
}
#line 1488 "parser.tab.cc"
    break;

  case 29: // @3: %empty
#line 282 "parser.yy"
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
#line 1506 "parser.tab.cc"
    break;

  case 30: // assignment: CONST ID ASSIGN @3 expr_val
#line 295 "parser.yy"
        {
    if(!yystack_[0].value.as < shared_ptr<Expression> > ()->is_const())
    {
        cout << "ERROR: CONST assignment requires a CONST expression." <<endl;
        return 1;
    }

    *yystack_[1].value.as < DataPtr > () = yystack_[0].value.as < shared_ptr<Expression> > ()->eval(const_stack);
    yylhs.value.as < shared_ptr<AssignStatement> > () = nullptr;
}
#line 1521 "parser.tab.cc"
    break;

  case 31: // if_statement: IF expr_val COLUMN EOL program elif_branch ENDIF
#line 307 "parser.yy"
                                                               {
    yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[2].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()));
}
#line 1530 "parser.tab.cc"
    break;

  case 32: // if_statement: IF expr_val COLUMN EOL program elif_branch ELSE COLUMN EOL program ENDIF
#line 311 "parser.yy"
                                                                           {
    yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[9].value.as < shared_ptr<Expression> > (), yystack_[6].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), yystack_[1].value.as < shared_ptr<Program> > ());
}
#line 1539 "parser.tab.cc"
    break;

  case 33: // if_statement: IF expr_val COLUMN statement elif_branch ENDIF
#line 315 "parser.yy"
                                                 {
    yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[4].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[2].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()));
}
#line 1548 "parser.tab.cc"
    break;

  case 34: // if_statement: IF expr_val COLUMN statement elif_branch ELSE COLUMN EOL program ENDIF
#line 319 "parser.yy"
                                                                         {
    yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[8].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[6].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), yystack_[1].value.as < shared_ptr<Program> > ());
}
#line 1557 "parser.tab.cc"
    break;

  case 35: // if_statement: IF expr_val COLUMN EOL program elif_branch ELSE COLUMN statement ENDIF
#line 323 "parser.yy"
                                                                         {
    yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[8].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
}
#line 1566 "parser.tab.cc"
    break;

  case 36: // if_statement: IF expr_val COLUMN statement elif_branch ELSE COLUMN statement ENDIF
#line 327 "parser.yy"
                                                                       {
    yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[7].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[5].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
}
#line 1575 "parser.tab.cc"
    break;

  case 37: // if_statement: IF expr_val COLUMN statement ELSE COLUMN statement
#line 331 "parser.yy"
                                                    {
    vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> ifs = {make_pair(yystack_[5].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[3].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1))};
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(ifs), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
}
#line 1584 "parser.tab.cc"
    break;

  case 38: // if_statement: IF expr_val COLUMN statement
#line 335 "parser.yy"
                              {
    vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> ifs = {make_pair(yystack_[2].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1))};
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(ifs));
}
#line 1593 "parser.tab.cc"
    break;

  case 39: // $@4: %empty
#line 342 "parser.yy"
        {
    interpreter.mark_is_in_loop(true);
}
#line 1601 "parser.tab.cc"
    break;

  case 40: // while_loop: WHILE expr_val COLUMN EOL $@4 program ENDWHILE
#line 345 "parser.yy"
                 {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<WhileLoop> > () = make_shared<WhileLoop>(yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1611 "parser.tab.cc"
    break;

  case 41: // $@5: %empty
#line 351 "parser.yy"
        {
    interpreter.mark_is_in_loop(true);
}
#line 1619 "parser.tab.cc"
    break;

  case 42: // while_loop: WHILE expr_val COLUMN $@5 statement
#line 354 "parser.yy"
          {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<WhileLoop> > () = make_shared<WhileLoop>(yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1629 "parser.tab.cc"
    break;

  case 43: // @6: %empty
#line 361 "parser.yy"
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
#line 1648 "parser.tab.cc"
    break;

  case 44: // for_counter_loop: FOR ID ASSIGN expr_val TO expr_val BY expr_val COLUMN EOL @6 program ENDFOR
#line 375 "parser.yy"
               {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), yystack_[9].value.as < shared_ptr<Expression> > (), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1658 "parser.tab.cc"
    break;

  case 45: // @7: %empty
#line 381 "parser.yy"
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
#line 1677 "parser.tab.cc"
    break;

  case 46: // for_counter_loop: FOR ID ASSIGN expr_val TO expr_val BY expr_val COLUMN @7 statement
#line 395 "parser.yy"
          {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[1].value.as < int > (), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1687 "parser.tab.cc"
    break;

  case 47: // @8: %empty
#line 401 "parser.yy"
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
#line 1706 "parser.tab.cc"
    break;

  case 48: // for_counter_loop: FOR ID ASSIGN expr_val TO expr_val COLUMN EOL @8 program ENDFOR
#line 415 "parser.yy"
              {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1716 "parser.tab.cc"
    break;

  case 49: // @9: %empty
#line 421 "parser.yy"
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
#line 1735 "parser.tab.cc"
    break;

  case 50: // for_counter_loop: FOR ID ASSIGN expr_val TO expr_val COLUMN @9 statement
#line 435 "parser.yy"
         {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[1].value.as < int > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1745 "parser.tab.cc"
    break;

  case 51: // @10: %empty
#line 441 "parser.yy"
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
#line 1764 "parser.tab.cc"
    break;

  case 52: // for_counter_loop: FOR ID TO expr_val COLUMN EOL @10 program ENDFOR
#line 455 "parser.yy"
              {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[5].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1774 "parser.tab.cc"
    break;

  case 53: // @11: %empty
#line 461 "parser.yy"
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
#line 1793 "parser.tab.cc"
    break;

  case 54: // for_counter_loop: FOR ID TO expr_val COLUMN @11 statement
#line 475 "parser.yy"
         {
    
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[1].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(1))), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1804 "parser.tab.cc"
    break;

  case 55: // @12: %empty
#line 482 "parser.yy"
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
#line 1823 "parser.tab.cc"
    break;

  case 56: // for_counter_loop: FOR ID TO expr_val BY expr_val COLUMN EOL @12 program ENDFOR
#line 496 "parser.yy"
              {

    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1834 "parser.tab.cc"
    break;

  case 57: // @13: %empty
#line 503 "parser.yy"
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
#line 1853 "parser.tab.cc"
    break;

  case 58: // for_counter_loop: FOR ID TO expr_val BY expr_val COLUMN @13 statement
#line 517 "parser.yy"
          {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[1].value.as < int > (), make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(0))), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1));
    interpreter.mark_is_in_loop(false);
}
#line 1863 "parser.tab.cc"
    break;

  case 59: // elif_branch: %empty
#line 524 "parser.yy"
                    {yylhs.value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > () = vector<pair<shared_ptr<Expression>, shared_ptr<Program>>>(); }
#line 1869 "parser.tab.cc"
    break;

  case 60: // elif_branch: ELIF expr_val COLUMN EOL program elif_branch
#line 525 "parser.yy"
                                               {
    yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[4].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > () = move(yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ());
}
#line 1878 "parser.tab.cc"
    break;

  case 61: // elif_branch: ELIF expr_val COLUMN statement elif_branch
#line 529 "parser.yy"
                                             {
    yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1)));
    yylhs.value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > () = move(yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ());
}
#line 1887 "parser.tab.cc"
    break;

  case 62: // expr: DEC
#line 535 "parser.yy"
          { yylhs.value.as < shared_ptr<Expression> > () = make_shared<LiteralExpression>(make_shared<Data>(make_shared<Number>(yystack_[0].value.as < string > ()))); }
#line 1893 "parser.tab.cc"
    break;

  case 63: // expr: STR
#line 536 "parser.yy"
      { yylhs.value.as < shared_ptr<Expression> > () = make_shared<LiteralExpression>( make_shared<Data>(make_shared<String>(move(yystack_[0].value.as < string > ())))); }
#line 1899 "parser.tab.cc"
    break;

  case 64: // expr: TRUE
#line 537 "parser.yy"
       { yylhs.value.as < shared_ptr<Expression> > () =  make_shared<LiteralExpression>(make_shared<Data>(make_shared<Boolean>(true))); }
#line 1905 "parser.tab.cc"
    break;

  case 65: // expr: FALSE
#line 538 "parser.yy"
        { yylhs.value.as < shared_ptr<Expression> > () = make_shared<LiteralExpression>( make_shared<Data>(make_shared<Boolean>(false))); }
#line 1911 "parser.tab.cc"
    break;

  case 66: // expr: NULL_TOKEN
#line 539 "parser.yy"
             { yylhs.value.as < shared_ptr<Expression> > () =  make_shared<LiteralExpression>(make_shared<Data>(make_shared<NullType>())); }
#line 1917 "parser.tab.cc"
    break;

  case 67: // expr: INF
#line 540 "parser.yy"
      { yylhs.value.as < shared_ptr<Expression> > () =  make_shared<LiteralExpression>(make_shared<Data>(make_shared<InfType>())); }
#line 1923 "parser.tab.cc"
    break;

  case 68: // expr: ID
#line 541 "parser.yy"
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
#line 1948 "parser.tab.cc"
    break;

  case 69: // expr: function
#line 561 "parser.yy"
           { yylhs.value.as < shared_ptr<Expression> > () =  make_shared<LiteralExpression>(make_shared<Data>(yystack_[0].value.as < shared_ptr<Function> > ())); }
#line 1954 "parser.tab.cc"
    break;

  case 70: // expr: expr PLUS expr
#line 562 "parser.yy"
                 {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::ADD);}
#line 1960 "parser.tab.cc"
    break;

  case 71: // expr: expr MINUS expr
#line 563 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::SUB);}
#line 1966 "parser.tab.cc"
    break;

  case 72: // expr: expr TIMES expr
#line 564 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::MULT);}
#line 1972 "parser.tab.cc"
    break;

  case 73: // expr: expr MOD expr
#line 565 "parser.yy"
                {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::MOD);}
#line 1978 "parser.tab.cc"
    break;

  case 74: // expr: expr DIVIDE expr
#line 566 "parser.yy"
                   {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::DIV);}
#line 1984 "parser.tab.cc"
    break;

  case 75: // expr: expr POWER expr
#line 567 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::POW);}
#line 1990 "parser.tab.cc"
    break;

  case 76: // expr: expr EQUAL expr
#line 568 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::EQ);}
#line 1996 "parser.tab.cc"
    break;

  case 77: // expr: expr NOT_EQUAL expr
#line 569 "parser.yy"
                      {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::NEQ);}
#line 2002 "parser.tab.cc"
    break;

  case 78: // expr: expr GREATER_THAN expr
#line 570 "parser.yy"
                         {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::GT);}
#line 2008 "parser.tab.cc"
    break;

  case 79: // expr: expr LESS_THAN expr
#line 571 "parser.yy"
                      {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::LT);}
#line 2014 "parser.tab.cc"
    break;

  case 80: // expr: expr GREATER_THAN_EQ expr
#line 572 "parser.yy"
                            {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::EQ_GT);}
#line 2020 "parser.tab.cc"
    break;

  case 81: // expr: expr LESS_THAN_EQ expr
#line 573 "parser.yy"
                         {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::EQ_LT);}
#line 2026 "parser.tab.cc"
    break;

  case 82: // expr: expr AND expr
#line 574 "parser.yy"
                {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::AND);}
#line 2032 "parser.tab.cc"
    break;

  case 83: // expr: expr OR expr
#line 575 "parser.yy"
               {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::OR);}
#line 2038 "parser.tab.cc"
    break;

  case 84: // expr: expr XOR expr
#line 576 "parser.yy"
                {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::XOR);}
#line 2044 "parser.tab.cc"
    break;

  case 85: // expr: expr NEITHER expr
#line 577 "parser.yy"
                    {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::NEITHER);}
#line 2050 "parser.tab.cc"
    break;

  case 86: // expr: expr AS NumType
#line 578 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression>(yystack_[2].value.as < shared_ptr<Expression> > (), UnaryExpression::TO_NUM);}
#line 2056 "parser.tab.cc"
    break;

  case 87: // expr: expr AS BoolType
#line 579 "parser.yy"
                   {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression>(yystack_[2].value.as < shared_ptr<Expression> > (), UnaryExpression::TO_BOOL);}
#line 2062 "parser.tab.cc"
    break;

  case 88: // expr: expr AS StrType
#line 580 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression>(yystack_[2].value.as < shared_ptr<Expression> > (), UnaryExpression::TO_STR);}
#line 2068 "parser.tab.cc"
    break;

  case 89: // expr: MINUS expr
#line 581 "parser.yy"
             {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression> (yystack_[0].value.as < shared_ptr<Expression> > (), UnaryExpression::INV);}
#line 2074 "parser.tab.cc"
    break;

  case 90: // expr: NOT expr
#line 582 "parser.yy"
           {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression> (yystack_[0].value.as < shared_ptr<Expression> > (), UnaryExpression::NOT);}
#line 2080 "parser.tab.cc"
    break;

  case 91: // expr: if_statement
#line 583 "parser.yy"
               { yylhs.value.as < shared_ptr<Expression> > () = make_shared<StatementExpression> (yystack_[0].value.as < shared_ptr<IfStatement> > ()); }
#line 2086 "parser.tab.cc"
    break;

  case 92: // expr: function_call
#line 584 "parser.yy"
                { yylhs.value.as < shared_ptr<Expression> > () = make_shared<StatementExpression> (yystack_[0].value.as < shared_ptr<FunctionStatement> > ()); }
#line 2092 "parser.tab.cc"
    break;

  case 93: // expr: assignment
#line 585 "parser.yy"
             { yylhs.value.as < shared_ptr<Expression> > () = make_shared<StatementExpression> (yystack_[0].value.as < shared_ptr<AssignStatement> > ());}
#line 2098 "parser.tab.cc"
    break;

  case 94: // expr: LEFT_PARENTHESES expr RIGHT_PARENTHESES
#line 586 "parser.yy"
                                          {yylhs.value.as < shared_ptr<Expression> > () = yystack_[1].value.as < shared_ptr<Expression> > ();}
#line 2104 "parser.tab.cc"
    break;

  case 95: // expr: LEFT_BRACKET expr_list RIGHT_BRACKET
#line 587 "parser.yy"
                                       { yylhs.value.as < shared_ptr<Expression> > () = make_shared<InititializerListExpression>(yystack_[1].value.as < vector<shared_ptr<Expression>> > ()); }
#line 2110 "parser.tab.cc"
    break;

  case 96: // expr: expr LEFT_BRACKET expr RIGHT_BRACKET
#line 588 "parser.yy"
                                       { yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yystack_[3].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Expression> > (), BinaryExpression::INDEX); }
#line 2116 "parser.tab.cc"
    break;

  case 97: // expr: LEN LEFT_PARENTHESES expr RIGHT_PARENTHESES
#line 589 "parser.yy"
                                              { yylhs.value.as < shared_ptr<Expression> > () = make_shared<LengthExpression>(yystack_[1].value.as < shared_ptr<Expression> > ()); }
#line 2122 "parser.tab.cc"
    break;

  case 98: // expr_val: expr
#line 592 "parser.yy"
               {
    yylhs.value.as < shared_ptr<Expression> > () = yystack_[0].value.as < shared_ptr<Expression> > ()->reduce_const();
}
#line 2130 "parser.tab.cc"
    break;

  case 99: // expr_list: %empty
#line 597 "parser.yy"
                  { yylhs.value.as < vector<shared_ptr<Expression>> > () = vector<shared_ptr<Expression>>(); }
#line 2136 "parser.tab.cc"
    break;

  case 100: // expr_list: expr_val COMMA expr_list
#line 598 "parser.yy"
                           {
    yystack_[0].value.as < vector<shared_ptr<Expression>> > ().push_back(yystack_[2].value.as < shared_ptr<Expression> > ());
    yylhs.value.as < vector<shared_ptr<Expression>> > () = move(yystack_[0].value.as < vector<shared_ptr<Expression>> > ());
}
#line 2145 "parser.tab.cc"
    break;

  case 101: // expr_list: expr_val
#line 602 "parser.yy"
           { yylhs.value.as < vector<shared_ptr<Expression>> > () = {yystack_[0].value.as < shared_ptr<Expression> > ()}; }
#line 2151 "parser.tab.cc"
    break;

  case 102: // @14: %empty
#line 607 "parser.yy"
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
#line 2178 "parser.tab.cc"
    break;

  case 103: // function: FUNC LEFT_PARENTHESES id_list RIGHT_PARENTHESES COLUMN EOL @14 program ENDFUNC
#line 629 "parser.yy"
               {
    yystack_[2].value.as < shared_ptr<Function> > ()->attach_program(yystack_[1].value.as < shared_ptr<Program> > ());
    yylhs.value.as < shared_ptr<Function> > () = yystack_[2].value.as < shared_ptr<Function> > ();
    interpreter.pop_scope();
    interpreter.pop_function();
}
#line 2189 "parser.tab.cc"
    break;

  case 104: // @15: %empty
#line 637 "parser.yy"
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
#line 2216 "parser.tab.cc"
    break;

  case 105: // function: FUNC LEFT_PARENTHESES id_list RIGHT_PARENTHESES COLUMN @15 statement
#line 659 "parser.yy"
         {
    yystack_[1].value.as < shared_ptr<Function> > ()->attach_program(make_shared<Program>(yystack_[0].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number(), 1 + yystack_[1].value.as < shared_ptr<Function> > ()->arg_count()));
    yylhs.value.as < shared_ptr<Function> > () = yystack_[1].value.as < shared_ptr<Function> > ();
    interpreter.pop_scope();
    interpreter.pop_function();
}
#line 2227 "parser.tab.cc"
    break;

  case 106: // id_list: %empty
#line 667 "parser.yy"
                { yylhs.value.as < vector<string> > () = vector<string>(); }
#line 2233 "parser.tab.cc"
    break;

  case 107: // id_list: ID COMMA id_list
#line 668 "parser.yy"
                  {
    yystack_[0].value.as < vector<string> > ().push_back(yystack_[2].value.as < string > ());
    yylhs.value.as < vector<string> > () = move(yystack_[0].value.as < vector<string> > ());
}
#line 2242 "parser.tab.cc"
    break;

  case 108: // id_list: ID
#line 672 "parser.yy"
     { yylhs.value.as < vector<string> > () = {yystack_[0].value.as < string > ()}; }
#line 2248 "parser.tab.cc"
    break;


#line 2252 "parser.tab.cc"

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


  const short CS_Parser::yypact_ninf_ = -130;

  const signed char CS_Parser::yytable_ninf_ = -1;

  const short
  CS_Parser::yypact_[] =
  {
    -130,    11,   349,  -130,  -130,  -130,   -19,    91,    91,     3,
     -15,    91,  -130,  -130,  -130,  -130,    91,  -130,  -130,  -130,
    -130,    91,  -130,  -130,     6,    91,    91,    23,    44,    91,
      91,    48,    91,    -1,  -130,  -130,  -130,  -130,  -130,  1249,
      50,  -130,  -130,  -130,  -130,  -130,   100,   330,    40,    91,
    1274,  1274,  1179,  -130,  -130,  1274,   -21,    50,     5,    31,
     -18,  1274,    91,   -38,    28,    64,  -130,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    62,    91,    91,    91,  -130,    57,  -130,
      91,    91,   859,    91,    91,    51,    71,    75,  1205,    91,
    -130,  -130,   100,   100,    -4,    -4,    52,    -4,   330,   330,
     330,   330,   330,   330,    25,  1299,  1299,  1299,  -130,  -130,
    -130,  1091,    73,  1116,    91,  -130,    50,    50,  -130,    -8,
     -26,   -31,    31,    76,  -130,  1039,  -130,  -130,   110,  -130,
    -130,    50,   398,    79,    91,    35,    91,    91,    96,  -130,
      98,  -130,  -130,    91,    56,  1039,    14,    83,  -130,   -23,
      18,  -130,  1039,  -130,  1039,   447,  1274,    84,  -130,  -130,
     904,   949,    91,   101,   104,  -130,  -130,  -130,  -130,  -130,
     994,  -130,    86,  -130,   102,    42,  -130,  1039,  -130,  1039,
     496,   551,  -130,   105,   398,  -130,   606,  -130,   106,  -130,
    -130,  -130,  -130,  -130,  -130,   655,  -130,  -130,  -130,  -130,
    1039,   704,   759,  -130,  -130,  -130,  -130,  -130,   814,  -130
  };

  const signed char
  CS_Parser::yydefact_[] =
  {
       3,     0,     0,     1,    62,    63,     0,     0,     0,     0,
       0,     0,    14,    17,    15,    18,    19,    64,    65,    66,
      67,     0,     6,     2,    68,     0,     0,     0,     0,     0,
       0,     0,    99,     0,    22,     8,    11,    13,    12,    98,
       0,    69,     7,    92,    93,    91,    89,    90,     0,    99,
      16,    20,    98,    25,    27,    98,     0,    10,     0,   106,
       0,    21,     0,   101,     0,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,     0,    29,     0,    94,
       0,     0,     0,     0,     0,   108,     0,    41,    98,    99,
      95,     5,    70,    71,    72,    74,    75,    73,    76,    79,
      78,    81,    80,    77,    82,    83,    84,    85,    86,    87,
      88,    98,     0,    98,     0,    24,    26,    28,     3,    38,
       0,     0,   106,     0,    39,     0,    97,   100,    96,    23,
      96,    30,    59,     0,     0,     0,     0,     0,    53,   107,
     104,     3,    42,     0,     0,     0,     0,     0,    33,     0,
       0,    51,     0,   102,     0,     0,     9,     0,    31,    37,
       0,     0,     0,    49,    57,     3,    54,     3,   105,    40,
       0,     3,    59,     3,     0,     0,    47,     0,    55,     0,
       0,     0,     3,     0,    59,    61,     0,    36,    45,     3,
      50,     3,    58,    52,   103,     0,    35,    60,    34,    43,
       0,     0,     0,    32,     3,    46,    48,    56,     0,    44
  };

  const short
  CS_Parser::yypgoto_[] =
  {
    -130,  -130,  -121,   -83,    -2,    10,  -130,  -130,  -130,    72,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -129,   224,   -24,   -35,  -130,  -130,  -130,    24
  };

  const unsigned char
  CS_Parser::yydefgoto_[] =
  {
       0,     1,     2,    33,    43,    44,    90,    91,   124,    45,
      37,   151,   135,    38,   214,   210,   199,   187,   175,   162,
     201,   189,   145,    39,    40,    64,    41,   177,   164,    96
  };

  const unsigned char
  CS_Parser::yytable_[] =
  {
      34,    56,    57,    85,    65,    60,    71,   142,    63,   129,
      85,     3,    35,   154,    88,    85,    93,    53,    85,    54,
      85,   147,    99,    85,    42,    63,    49,   146,   148,   172,
     165,    67,    68,    69,    70,    71,   173,    72,    92,   143,
     144,    97,    66,    73,    74,    75,    76,    77,    48,    78,
     122,    87,   152,   195,   190,    85,   191,    83,    94,    85,
     194,    63,   196,    86,   137,   207,   126,   127,    58,   130,
     131,   205,   169,   170,    36,    63,    95,   174,   211,   176,
     212,   178,   157,    85,   158,    59,    83,   182,   184,    62,
      34,    85,    86,   218,     4,     5,   100,   193,     7,   125,
     141,   198,    35,   167,   200,   168,   202,   101,    69,    70,
      71,   132,    72,   133,     8,   139,     9,    10,   134,    86,
     156,   153,   159,   160,   118,   119,   120,   215,    17,    18,
      19,    20,    21,    34,   144,   150,    24,    25,   155,   161,
      34,   163,   171,   180,   186,    35,    28,   188,   185,   209,
       0,   197,    35,    34,   206,     0,   149,    31,    32,     0,
      34,    83,    34,    34,    36,    35,     0,    86,    34,    34,
       0,     0,    35,     0,    35,    35,     0,     0,    34,     0,
      35,    35,     0,     0,     0,    34,     0,    34,    34,    34,
      35,     0,    34,     0,    34,     0,     0,    35,     0,    35,
      35,    35,     0,    34,    35,     0,    35,    36,    34,    34,
      34,     0,     0,     0,    36,    35,    34,     0,     0,     0,
      35,    35,    35,     0,     0,     0,     0,    36,    35,     0,
       0,    46,    47,     0,    36,    50,    36,    36,     0,     0,
      51,     0,    36,    36,     0,    52,     0,     0,     0,    55,
      55,     0,    36,    55,    61,     0,    55,     0,     0,    36,
       0,    36,    36,    36,     0,     0,    36,     0,    36,     0,
       0,     0,     0,    55,     0,     0,     0,    36,     0,     0,
       0,     0,    36,    36,    36,     0,    98,     0,     0,     0,
      36,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,   121,    55,
     123,     0,     0,     0,    55,    55,     0,    55,    55,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,    70,
      71,     0,    72,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     4,     5,     6,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      55,    55,     8,     0,     9,    10,     0,   166,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    83,    22,    23,    24,    25,    55,    86,     0,    26,
      27,     4,     5,     6,    28,     7,    29,     0,     0,     0,
       0,     0,     0,     0,    30,    31,    32,     0,     0,     0,
       0,     8,     0,     9,    10,     0,     0,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,    22,     0,    24,    25,     0,   144,     0,    26,    27,
       4,     5,     6,    28,     7,    29,     0,     0,     0,     0,
       0,     0,     0,    30,    31,    32,     0,     0,     0,     0,
       8,     0,     9,    10,     0,     0,     0,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
      22,     0,    24,    25,     0,     0,     0,    26,    27,     4,
       5,     6,    28,     7,    29,   179,     0,     0,     0,     0,
       0,     0,    30,    31,    32,     0,     0,     0,     0,     8,
       0,     9,    10,     0,     0,     0,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    22,
       0,    24,    25,     0,     0,     0,    26,    27,     0,     0,
     203,    28,     0,    29,     4,     5,     6,     0,     7,     0,
       0,    30,    31,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     9,    10,     0,     0,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    22,     0,    24,    25,     0,     0,
       0,    26,    27,     0,     0,     0,    28,   204,    29,     4,
       5,     6,     0,     7,     0,     0,    30,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,     9,    10,     0,     0,     0,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    22,
       0,    24,    25,     0,     0,   208,    26,    27,     4,     5,
       6,    28,     7,    29,     0,     0,     0,     0,     0,     0,
       0,    30,    31,    32,     0,     0,     0,     0,     8,     0,
       9,    10,     0,     0,     0,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,    22,     0,
      24,    25,     0,     0,   213,    26,    27,     4,     5,     6,
      28,     7,    29,     0,     0,     0,     0,     0,     0,     0,
      30,    31,    32,     0,     0,     0,     0,     8,     0,     9,
      10,     0,     0,     0,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,    22,     0,    24,
      25,     0,     0,     0,    26,    27,     0,     0,   216,    28,
       0,    29,     4,     5,     6,     0,     7,     0,     0,    30,
      31,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     0,     9,    10,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,    22,     0,    24,    25,     0,     0,     0,    26,
      27,     0,     0,   217,    28,     0,    29,     4,     5,     6,
       0,     7,     0,     0,    30,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     0,     9,
      10,     0,     0,     0,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,    22,     0,    24,
      25,     0,     4,     5,    26,    27,     7,     0,   219,    28,
       0,    29,     0,     0,     0,     0,     0,     0,     0,    30,
      31,    32,     8,     0,     9,    10,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,   128,     0,    24,    25,     0,     4,     5,    26,
      27,     7,     0,     0,    28,     0,    29,     0,     0,     0,
       0,     0,     0,     0,    30,    31,    32,     8,     0,     9,
      10,     0,     0,     0,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,   181,     0,    24,
      25,     0,     4,     5,    26,    27,     7,     0,     0,    28,
       0,    29,     0,     0,     0,     0,     0,     0,     0,    30,
      31,    32,     8,     0,     9,    10,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,   183,     0,    24,    25,     0,     4,     5,    26,
      27,     7,     0,     0,    28,     0,    29,     0,     0,     0,
       0,     0,     0,     0,    30,    31,    32,     8,     0,     9,
      10,     0,     0,     0,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,   192,     0,    24,
      25,     0,     4,     5,    26,    27,     7,     0,     0,    28,
       0,    29,     0,     0,     0,     0,     0,     0,     0,    30,
      31,    32,     8,     0,     9,    10,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     0,     0,    24,    25,     0,     0,     0,    26,
      27,     0,     0,     0,    28,     0,    29,    67,    68,    69,
      70,    71,     0,    72,    30,    31,    32,     0,     0,    73,
      74,    75,    76,    77,     0,    78,     0,     0,    79,    80,
      81,    82,    67,    68,    69,    70,    71,     0,    72,     0,
       0,     0,     0,     0,    73,    74,    75,    76,    77,     0,
      78,     0,     0,    79,    80,    81,    82,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,    86,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     0,    86,   140,    67,    68,    69,    70,    71,
       0,    72,     0,     0,     0,     0,     0,    73,    74,    75,
      76,    77,     0,    78,     0,     0,    79,    80,    81,    82,
       0,    67,    68,    69,    70,    71,     0,    72,     0,     0,
       0,    89,     0,    73,    74,    75,    76,    77,     0,    78,
       0,     0,    79,    80,    81,    82,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,    86,   136,     0,     0,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
       0,    72,     0,     0,     0,     0,    83,    73,    74,    75,
      76,    77,    86,    78,     0,     0,    79,    80,    81,    82,
      67,    68,    69,    70,    71,     0,    72,     0,     0,     0,
       0,     0,    73,    74,    75,    76,    77,     0,    78,     0,
       0,    79,    80,    81,    82,    67,    68,    69,    70,    71,
      83,    72,     0,     0,     0,     0,    84,    73,    74,    75,
      76,    77,     0,    78,     0,     0,    79,     0,     0,     0,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,    86
  };

  const short
  CS_Parser::yycheck_[] =
  {
       2,    25,    26,    41,     5,    29,    10,   128,    32,    92,
      41,     0,     2,   142,    49,    41,    11,    11,    41,    13,
      41,    52,    60,    41,    43,    49,    41,    53,    59,    52,
     151,     6,     7,     8,     9,    10,    59,    12,    59,    47,
      48,    59,    43,    18,    19,    20,    21,    22,    45,    24,
      85,    11,   135,   182,   175,    41,   177,    61,    53,    41,
     181,    85,   183,    67,    99,   194,    90,    91,    45,    93,
      94,   192,   155,    59,     2,    99,    45,    59,   199,   162,
     201,   164,    47,    41,    49,    41,    61,   170,   171,    41,
      92,    41,    67,   214,     3,     4,    68,   180,     7,    42,
     124,    59,    92,    47,   187,    49,   189,    43,     8,     9,
      10,    60,    12,    42,    23,    42,    25,    26,    43,    67,
     144,    11,   146,   147,    62,    63,    64,   210,    37,    38,
      39,    40,    41,   135,    48,    59,    45,    46,    59,    43,
     142,    43,    59,    59,    43,   135,    55,    43,   172,    43,
      -1,    49,   142,   155,    49,    -1,   132,    66,    67,    -1,
     162,    61,   164,   165,    92,   155,    -1,    67,   170,   171,
      -1,    -1,   162,    -1,   164,   165,    -1,    -1,   180,    -1,
     170,   171,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     180,    -1,   194,    -1,   196,    -1,    -1,   187,    -1,   189,
     190,   191,    -1,   205,   194,    -1,   196,   135,   210,   211,
     212,    -1,    -1,    -1,   142,   205,   218,    -1,    -1,    -1,
     210,   211,   212,    -1,    -1,    -1,    -1,   155,   218,    -1,
      -1,     7,     8,    -1,   162,    11,   164,   165,    -1,    -1,
      16,    -1,   170,   171,    -1,    21,    -1,    -1,    -1,    25,
      26,    -1,   180,    29,    30,    -1,    32,    -1,    -1,   187,
      -1,   189,   190,   191,    -1,    -1,   194,    -1,   196,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,   210,   211,   212,    -1,    62,    -1,    -1,    -1,
     218,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    -1,    84,    85,
      86,    -1,    -1,    -1,    90,    91,    -1,    93,    94,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    -1,    12,    -1,    -1,    -1,    -1,    -1,   124,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
     146,   147,    23,    -1,    25,    26,    -1,   153,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    61,    43,    44,    45,    46,   172,    67,    -1,    50,
      51,     3,     4,     5,    55,     7,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,    -1,
      -1,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    43,    -1,    45,    46,    -1,    48,    -1,    50,    51,
       3,     4,     5,    55,     7,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    -1,    -1,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    -1,    45,    46,    -1,    -1,    -1,    50,    51,     3,
       4,     5,    55,     7,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    -1,    -1,    23,
      -1,    25,    26,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,
      54,    55,    -1,    57,     3,     4,     5,    -1,     7,    -1,
      -1,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    -1,    55,    56,    57,     3,
       4,     5,    -1,     7,    -1,    -1,    65,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    25,    26,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      -1,    45,    46,    -1,    -1,    49,    50,    51,     3,     4,
       5,    55,     7,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    -1,    -1,    -1,    -1,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    -1,
      45,    46,    -1,    -1,    49,    50,    51,     3,     4,     5,
      55,     7,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    -1,    -1,    23,    -1,    25,
      26,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    -1,    45,
      46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    55,
      -1,    57,     3,     4,     5,    -1,     7,    -1,    -1,    65,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    55,    -1,    57,     3,     4,     5,
      -1,     7,    -1,    -1,    65,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,
      26,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    -1,    45,
      46,    -1,     3,     4,    50,    51,     7,    -1,    54,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    -1,    45,    46,    -1,     3,     4,    50,
      51,     7,    -1,    -1,    55,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    23,    -1,    25,
      26,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    -1,    45,
      46,    -1,     3,     4,    50,    51,     7,    -1,    -1,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    -1,    45,    46,    -1,     3,     4,    50,
      51,     7,    -1,    -1,    55,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    23,    -1,    25,
      26,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    -1,    45,
      46,    -1,     3,     4,    50,    51,     7,    -1,    -1,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    55,    -1,    57,     6,     7,     8,
       9,    10,    -1,    12,    65,    66,    67,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    24,    -1,    -1,    27,    28,
      29,    30,     6,     7,     8,     9,    10,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      24,    -1,    -1,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,     6,     7,     8,     9,    10,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    24,    -1,    -1,    27,    28,    29,    30,
      -1,     6,     7,     8,     9,    10,    -1,    12,    -1,    -1,
      -1,    42,    -1,    18,    19,    20,    21,    22,    -1,    24,
      -1,    -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      -1,    12,    -1,    -1,    -1,    -1,    61,    18,    19,    20,
      21,    22,    67,    24,    -1,    -1,    27,    28,    29,    30,
       6,     7,     8,     9,    10,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    24,    -1,
      -1,    27,    28,    29,    30,     6,     7,     8,     9,    10,
      61,    12,    -1,    -1,    -1,    -1,    67,    18,    19,    20,
      21,    22,    -1,    24,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67
  };

  const signed char
  CS_Parser::yystos_[] =
  {
       0,    70,    71,     0,     3,     4,     5,     7,    23,    25,
      26,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    43,    44,    45,    46,    50,    51,    55,    57,
      65,    66,    67,    72,    73,    74,    78,    79,    82,    92,
      93,    95,    43,    73,    74,    78,    92,    92,    45,    41,
      92,    92,    92,    11,    13,    92,    93,    93,    45,    41,
      93,    92,    41,    93,    94,     5,    43,     6,     7,     8,
       9,    10,    12,    18,    19,    20,    21,    22,    24,    27,
      28,    29,    30,    61,    67,    41,    67,    11,    94,    42,
      75,    76,    59,    11,    53,    45,    98,    59,    92,    60,
      68,    43,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    62,    63,
      64,    92,    94,    92,    77,    42,    93,    93,    43,    72,
      93,    93,    60,    42,    43,    81,    42,    94,    68,    42,
      68,    93,    71,    47,    48,    91,    53,    52,    59,    98,
      59,    80,    72,    11,    91,    59,    93,    47,    49,    93,
      93,    43,    88,    43,    97,    71,    92,    47,    49,    72,
      59,    59,    52,    59,    59,    87,    72,    96,    72,    58,
      59,    43,    72,    43,    72,    93,    43,    86,    43,    90,
      71,    71,    43,    72,    71,    91,    71,    49,    59,    85,
      72,    89,    72,    54,    56,    71,    49,    91,    49,    43,
      84,    71,    71,    49,    83,    72,    54,    54,    71,    54
  };

  const signed char
  CS_Parser::yyr1_[] =
  {
       0,    69,    70,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    75,    74,    76,    74,    77,
      74,    78,    78,    78,    78,    78,    78,    78,    78,    80,
      79,    81,    79,    83,    82,    84,    82,    85,    82,    86,
      82,    87,    82,    88,    82,    89,    82,    90,    82,    91,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    93,    94,
      94,    94,    96,    95,    97,    95,    98,    98,    98
  };

  const signed char
  CS_Parser::yyr2_[] =
  {
       0,     2,     2,     0,     3,     4,     2,     3,     1,     6,
       2,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       2,     2,     1,     4,     4,     0,     4,     0,     4,     0,
       5,     7,    11,     6,    10,    10,     9,     7,     4,     0,
       7,     0,     5,     0,    13,     0,    11,     0,    11,     0,
       9,     0,     9,     0,     7,     0,    11,     0,     9,     0,
       6,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     1,     1,     3,     3,     4,     4,     1,     0,
       3,     1,     0,     9,     0,     7,     0,     3,     1
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
  "FUNC", "ENDFUNC", "WHILE", "ENDWHILE", "COLUMN", "COMMA", "AS",
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
     182,   186,   189,   192,   195,   202,   209,   216,   223,   230,
     233,   236,   239,   244,   247,   262,   261,   272,   271,   282,
     281,   307,   311,   315,   319,   323,   327,   331,   335,   342,
     341,   351,   350,   361,   360,   381,   380,   401,   400,   421,
     420,   441,   440,   461,   460,   482,   481,   503,   502,   524,
     525,   529,   535,   536,   537,   538,   539,   540,   541,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   592,   597,
     598,   602,   607,   605,   637,   635,   667,   668,   672
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
      65,    66,    67,    68
    };
    // Last valid token kind.
    const int code_max = 323;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 7 "parser.yy"
} // CS
#line 3148 "parser.tab.cc"

#line 674 "parser.yy"


void CS::CS_Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cout << "ERROR: No file provided" << endl;
        return 0;
    } 

    std::ifstream ifs(argv[1], std::ifstream::in);
    auto lexer = make_unique<CS::CS_Scanner>(&ifs);
    auto parser = make_unique<CS::CS_Parser>(*lexer);
    interpreter.make_new_scope(); //Globālais
    if(parser->parse() == 0) //Nav kļūdu
    {
        //
    }
    interpreter.pop_scope();
}
