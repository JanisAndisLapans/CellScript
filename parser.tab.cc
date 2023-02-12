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
#line 38 "parser.yy"


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


#line 67 "parser.tab.cc"


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
#line 160 "parser.tab.cc"

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
      case symbol_kind::S_55_1: // @1
      case symbol_kind::S_56_2: // @2
      case symbol_kind::S_57_3: // @3
      case symbol_kind::S_58_4: // @4
      case symbol_kind::S_59_5: // @5
      case symbol_kind::S_60_6: // @6
      case symbol_kind::S_61_7: // @7
      case symbol_kind::S_62_8: // @8
        value.copy< Interpreter::Variable > (YY_MOVE (that.value));
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
      case symbol_kind::S_55_1: // @1
      case symbol_kind::S_56_2: // @2
      case symbol_kind::S_57_3: // @3
      case symbol_kind::S_58_4: // @4
      case symbol_kind::S_59_5: // @5
      case symbol_kind::S_60_6: // @6
      case symbol_kind::S_61_7: // @7
      case symbol_kind::S_62_8: // @8
        value.move< Interpreter::Variable > (YY_MOVE (s.value));
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
      case symbol_kind::S_55_1: // @1
      case symbol_kind::S_56_2: // @2
      case symbol_kind::S_57_3: // @3
      case symbol_kind::S_58_4: // @4
      case symbol_kind::S_59_5: // @5
      case symbol_kind::S_60_6: // @6
      case symbol_kind::S_61_7: // @7
      case symbol_kind::S_62_8: // @8
        value.YY_MOVE_OR_COPY< Interpreter::Variable > (YY_MOVE (that.value));
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
      case symbol_kind::S_55_1: // @1
      case symbol_kind::S_56_2: // @2
      case symbol_kind::S_57_3: // @3
      case symbol_kind::S_58_4: // @4
      case symbol_kind::S_59_5: // @5
      case symbol_kind::S_60_6: // @6
      case symbol_kind::S_61_7: // @7
      case symbol_kind::S_62_8: // @8
        value.move< Interpreter::Variable > (YY_MOVE (that.value));
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
      case symbol_kind::S_55_1: // @1
      case symbol_kind::S_56_2: // @2
      case symbol_kind::S_57_3: // @3
      case symbol_kind::S_58_4: // @4
      case symbol_kind::S_59_5: // @5
      case symbol_kind::S_60_6: // @6
      case symbol_kind::S_61_7: // @7
      case symbol_kind::S_62_8: // @8
        value.copy< Interpreter::Variable > (that.value);
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
      case symbol_kind::S_55_1: // @1
      case symbol_kind::S_56_2: // @2
      case symbol_kind::S_57_3: // @3
      case symbol_kind::S_58_4: // @4
      case symbol_kind::S_59_5: // @5
      case symbol_kind::S_60_6: // @6
      case symbol_kind::S_61_7: // @7
      case symbol_kind::S_62_8: // @8
        value.move< Interpreter::Variable > (that.value);
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
      case symbol_kind::S_55_1: // @1
      case symbol_kind::S_56_2: // @2
      case symbol_kind::S_57_3: // @3
      case symbol_kind::S_58_4: // @4
      case symbol_kind::S_59_5: // @5
      case symbol_kind::S_60_6: // @6
      case symbol_kind::S_61_7: // @7
      case symbol_kind::S_62_8: // @8
        yylhs.value.emplace< Interpreter::Variable > ();
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
#line 103 "parser.yy"
                        { 
    yystack_[2].value.as < shared_ptr<Program> > ()->run();
    return 0;
    }
#line 967 "parser.tab.cc"
    break;

  case 3: // program: %empty
#line 109 "parser.yy"
                {
    yylhs.value.as < shared_ptr<Program> > () = make_shared<Program>(interpreter.get_scope_number());
}
#line 975 "parser.tab.cc"
    break;

  case 4: // program: program statement EOL
#line 112 "parser.yy"
                       {
    if(yystack_[1].value.as < shared_ptr<Statement> > () != nullptr)
    {
        yystack_[2].value.as < shared_ptr<Program> > ()->attach_statement(yystack_[1].value.as < shared_ptr<Statement> > ());
    }
    yylhs.value.as < shared_ptr<Program> > () = yystack_[2].value.as < shared_ptr<Program> > ();
}
#line 987 "parser.tab.cc"
    break;

  case 5: // statement: %empty
#line 121 "parser.yy"
                  { yylhs.value.as < shared_ptr<Statement> > () = nullptr; }
#line 993 "parser.tab.cc"
    break;

  case 6: // statement: assignment
#line 122 "parser.yy"
             {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<AssignStatement> > ();
}
#line 1001 "parser.tab.cc"
    break;

  case 7: // statement: PRINT expr
#line 125 "parser.yy"
             {
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<PrintStatement>(yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1009 "parser.tab.cc"
    break;

  case 8: // statement: if_statement
#line 128 "parser.yy"
               {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<IfStatement> > ();
}
#line 1017 "parser.tab.cc"
    break;

  case 9: // statement: for_counter_loop
#line 131 "parser.yy"
                 {
    yylhs.value.as < shared_ptr<Statement> > () = yystack_[0].value.as < shared_ptr<ForCounterLoop> > ();
}
#line 1025 "parser.tab.cc"
    break;

  case 10: // statement: BREAK
#line 134 "parser.yy"
       {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: BREAK statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<BreakStatement>();
}
#line 1037 "parser.tab.cc"
    break;

  case 11: // statement: BREAK_ALL
#line 141 "parser.yy"
           {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: BREAK ALL statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<BreakAll>();
}
#line 1049 "parser.tab.cc"
    break;

  case 12: // statement: ADVANCE expr
#line 148 "parser.yy"
              {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: ADVANCE statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Advance>(yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1061 "parser.tab.cc"
    break;

  case 13: // statement: CONTINUE
#line 155 "parser.yy"
          {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: ADVANCE statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Advance>(make_shared<ValueExpression> (make_shared<Data> (make_shared<Number>(1))));
}
#line 1073 "parser.tab.cc"
    break;

  case 14: // statement: REPEAT
#line 162 "parser.yy"
        {
    if(!interpreter.in_loop())
    {
        cout << "ERROR: REPEAT statement outside loop" << endl;
    }
    yylhs.value.as < shared_ptr<Statement> > () = make_shared<Advance>(make_shared<ValueExpression> (make_shared<Data> (make_shared<Number>(0))));
}
#line 1085 "parser.tab.cc"
    break;

  case 15: // assignment: ID ASSIGN expr
#line 171 "parser.yy"
                          {
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[2].value.as < string > (), non_declared);
    if(!non_declared)
    {
        if(var.is_const)
        {
            cout << "ERROR: variable declared CONST in this scope, cannot be altered" <<endl;
            return 1;
        }
    }
    else
    {
        var = interpreter.declare_variable(yystack_[2].value.as < string > (), false);
    }
    yylhs.value.as < shared_ptr<AssignStatement> > () = make_shared<AssignStatement>(var.mem_location, yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1107 "parser.tab.cc"
    break;

  case 16: // assignment: CONST ID ASSIGN expr
#line 188 "parser.yy"
                      {
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[2].value.as < string > (), non_declared);
    if(!non_declared)
    {
        cout << "ERROR: variable was already declared in this scope." << endl;
        return 1;
    }
    else
    {
        var = interpreter.declare_variable(yystack_[2].value.as < string > (), true);
    }
    yylhs.value.as < shared_ptr<AssignStatement> > () = make_shared<AssignStatement>(var.mem_location, yystack_[0].value.as < shared_ptr<Expression> > ());
}
#line 1126 "parser.tab.cc"
    break;

  case 17: // if_statement: IF expr COLUMN EOL program elif_branch ENDIF
#line 204 "parser.yy"
                                                           {
    yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[2].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()));
}
#line 1135 "parser.tab.cc"
    break;

  case 18: // if_statement: IF expr COLUMN EOL program elif_branch ELSE COLUMN EOL program ENDIF
#line 208 "parser.yy"
                                                                       {
    yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[9].value.as < shared_ptr<Expression> > (), yystack_[6].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), yystack_[1].value.as < shared_ptr<Program> > ());
}
#line 1144 "parser.tab.cc"
    break;

  case 19: // if_statement: IF expr COLUMN statement elif_branch ENDIF
#line 212 "parser.yy"
                                             {
    yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[4].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[2].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number())));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[1].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()));
}
#line 1153 "parser.tab.cc"
    break;

  case 20: // if_statement: IF expr COLUMN statement elif_branch ELSE COLUMN EOL program ENDIF
#line 216 "parser.yy"
                                                                     {
    yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[8].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[6].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number())));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[5].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), yystack_[1].value.as < shared_ptr<Program> > ());
}
#line 1162 "parser.tab.cc"
    break;

  case 21: // if_statement: IF expr COLUMN EOL program elif_branch ELSE COLUMN statement ENDIF
#line 220 "parser.yy"
                                                                     {
    yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[8].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number()));
}
#line 1171 "parser.tab.cc"
    break;

  case 22: // if_statement: IF expr COLUMN statement elif_branch ELSE COLUMN statement ENDIF
#line 224 "parser.yy"
                                                                   {
    yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[7].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[5].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number())));
    yylhs.value.as < shared_ptr<IfStatement> > () = make_shared<IfStatement>(move(yystack_[4].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ()), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number()));
}
#line 1180 "parser.tab.cc"
    break;

  case 23: // @1: %empty
#line 231 "parser.yy"
                       {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[8].value.as < string > (), non_declared);
    if(!non_declared)
    {
        yylhs.value.as < Interpreter::Variable > () = var;
    }
    else
    {
        yylhs.value.as < Interpreter::Variable > () = interpreter.declare_variable(yystack_[8].value.as < string > (), false);
    }
}
#line 1199 "parser.tab.cc"
    break;

  case 24: // for_counter_loop: FOR ID ASSIGN expr TO expr BY expr COLUMN EOL @1 program ENDFOR
#line 245 "parser.yy"
               {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < Interpreter::Variable > ().mem_location, yystack_[9].value.as < shared_ptr<Expression> > (), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1209 "parser.tab.cc"
    break;

  case 25: // @2: %empty
#line 251 "parser.yy"
                       {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[7].value.as < string > (), non_declared);
    if(!non_declared)
    {
        yylhs.value.as < Interpreter::Variable > () = var;
    }
    else
    {
        yylhs.value.as < Interpreter::Variable > () = interpreter.declare_variable(yystack_[7].value.as < string > (), false);
    }
}
#line 1228 "parser.tab.cc"
    break;

  case 26: // for_counter_loop: FOR ID ASSIGN expr TO expr BY expr COLUMN @2 statement ENDFOR
#line 265 "parser.yy"
                 {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < Interpreter::Variable > ().mem_location, yystack_[8].value.as < shared_ptr<Expression> > (), yystack_[6].value.as < shared_ptr<Expression> > (), yystack_[4].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number()));
    interpreter.mark_is_in_loop(false);
}
#line 1238 "parser.tab.cc"
    break;

  case 27: // @3: %empty
#line 271 "parser.yy"
                       {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[6].value.as < string > (), non_declared);
    if(!non_declared)
    {
        yylhs.value.as < Interpreter::Variable > () = var;
    }
    else
    {
        yylhs.value.as < Interpreter::Variable > () = interpreter.declare_variable(yystack_[6].value.as < string > (), false);
    }
}
#line 1257 "parser.tab.cc"
    break;

  case 28: // for_counter_loop: FOR ID ASSIGN expr TO expr COLUMN EOL @3 program ENDFOR
#line 285 "parser.yy"
              {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < Interpreter::Variable > ().mem_location, yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), make_shared<ValueExpression> (make_shared<Data> (make_shared<Number>(1))), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1267 "parser.tab.cc"
    break;

  case 29: // @4: %empty
#line 291 "parser.yy"
                       {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[5].value.as < string > (), non_declared);
    if(!non_declared)
    {
        yylhs.value.as < Interpreter::Variable > () = var;
    }
    else
    {
        yylhs.value.as < Interpreter::Variable > () = interpreter.declare_variable(yystack_[5].value.as < string > (), false);
    }
}
#line 1286 "parser.tab.cc"
    break;

  case 30: // for_counter_loop: FOR ID ASSIGN expr TO expr COLUMN @4 statement ENDFOR
#line 305 "parser.yy"
                {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < Interpreter::Variable > ().mem_location, yystack_[6].value.as < shared_ptr<Expression> > (), yystack_[4].value.as < shared_ptr<Expression> > (), make_shared<ValueExpression> (make_shared<Data> (make_shared<Number>(1))), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number()));
    interpreter.mark_is_in_loop(false);
}
#line 1296 "parser.tab.cc"
    break;

  case 31: // @5: %empty
#line 311 "parser.yy"
                       {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[4].value.as < string > (), non_declared);
    if(!non_declared)
    {                
        yylhs.value.as < Interpreter::Variable > () = var;
    }
    else
    {        
        yylhs.value.as < Interpreter::Variable > () = interpreter.declare_variable(yystack_[4].value.as < string > (), false);
    }
}
#line 1315 "parser.tab.cc"
    break;

  case 32: // for_counter_loop: FOR ID TO expr COLUMN EOL @5 program ENDFOR
#line 325 "parser.yy"
              {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < Interpreter::Variable > ().mem_location, make_shared<ValueExpression>(make_shared<Data> (make_shared<Number>(0))), yystack_[5].value.as < shared_ptr<Expression> > (), make_shared<ValueExpression> (make_shared<Data> (make_shared<Number>(1))), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1325 "parser.tab.cc"
    break;

  case 33: // @6: %empty
#line 331 "parser.yy"
                       {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[3].value.as < string > (), non_declared);
    if(!non_declared)
    {
        yylhs.value.as < Interpreter::Variable > () = var;
    }
    else
    {
        yylhs.value.as < Interpreter::Variable > () = interpreter.declare_variable(yystack_[3].value.as < string > (), false);
    }
}
#line 1344 "parser.tab.cc"
    break;

  case 34: // for_counter_loop: FOR ID TO expr COLUMN @6 statement ENDFOR
#line 345 "parser.yy"
                {
    
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < Interpreter::Variable > ().mem_location, make_shared<ValueExpression>(make_shared<Data> (make_shared<Number>(0))), yystack_[4].value.as < shared_ptr<Expression> > (), make_shared<ValueExpression> (make_shared<Data> (make_shared<Number>(1))), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number()));
    interpreter.mark_is_in_loop(false);
}
#line 1355 "parser.tab.cc"
    break;

  case 35: // @7: %empty
#line 352 "parser.yy"
                       {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[6].value.as < string > (), non_declared);
    if(!non_declared)
    {
        yylhs.value.as < Interpreter::Variable > () = var;
    }
    else
    {
        yylhs.value.as < Interpreter::Variable > () = interpreter.declare_variable(yystack_[6].value.as < string > (), false);
    }
}
#line 1374 "parser.tab.cc"
    break;

  case 36: // for_counter_loop: FOR ID TO expr BY expr COLUMN EOL @7 program ENDFOR
#line 366 "parser.yy"
              {

    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < Interpreter::Variable > ().mem_location, make_shared<ValueExpression>(make_shared<Data> (make_shared<Number>(0))), yystack_[7].value.as < shared_ptr<Expression> > (), yystack_[5].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ());
    interpreter.mark_is_in_loop(false);
}
#line 1385 "parser.tab.cc"
    break;

  case 37: // @8: %empty
#line 373 "parser.yy"
                       {
    //Deklarē skaitītāja mainīgo, ja neeksistē
    interpreter.mark_is_in_loop(true);
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[5].value.as < string > (), non_declared);
    if(!non_declared)
    {
        yylhs.value.as < Interpreter::Variable > () = var;
    }
    else
    {
        yylhs.value.as < Interpreter::Variable > () = interpreter.declare_variable(yystack_[5].value.as < string > (), false);
    }
}
#line 1404 "parser.tab.cc"
    break;

  case 38: // for_counter_loop: FOR ID TO expr BY expr COLUMN @8 statement ENDFOR
#line 387 "parser.yy"
                 {
    //Izveido ciklu
    yylhs.value.as < shared_ptr<ForCounterLoop> > () = make_shared<ForCounterLoop>(yystack_[2].value.as < Interpreter::Variable > ().mem_location, make_shared<ValueExpression>(make_shared<Data> (make_shared<Number>(0))), yystack_[6].value.as < shared_ptr<Expression> > (), yystack_[4].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number()));
    interpreter.mark_is_in_loop(false);
}
#line 1414 "parser.tab.cc"
    break;

  case 39: // elif_branch: %empty
#line 394 "parser.yy"
                    {yylhs.value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > () = vector<pair<shared_ptr<Expression>, shared_ptr<Program>>>(); }
#line 1420 "parser.tab.cc"
    break;

  case 40: // elif_branch: ELIF expr COLUMN EOL program elif_branch
#line 395 "parser.yy"
                                           {
    yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[4].value.as < shared_ptr<Expression> > (), yystack_[1].value.as < shared_ptr<Program> > ()));
    yylhs.value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > () = move(yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ());
}
#line 1429 "parser.tab.cc"
    break;

  case 41: // elif_branch: ELIF expr COLUMN statement elif_branch
#line 399 "parser.yy"
                                         {
    yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ().push_back(make_pair(yystack_[3].value.as < shared_ptr<Expression> > (), make_shared<Program>(yystack_[1].value.as < shared_ptr<Statement> > (), interpreter.get_scope_number())));
    yylhs.value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > () = move(yystack_[0].value.as < vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ());
}
#line 1438 "parser.tab.cc"
    break;

  case 42: // expr: DEC
#line 405 "parser.yy"
          { yylhs.value.as < shared_ptr<Expression> > () = make_shared<ValueExpression> (make_shared<Data> (make_shared<Number>(yystack_[0].value.as < string > ()))); }
#line 1444 "parser.tab.cc"
    break;

  case 43: // expr: STR
#line 406 "parser.yy"
      { yylhs.value.as < shared_ptr<Expression> > () = make_shared<ValueExpression> (make_shared<Data> (make_shared<String>(move(yystack_[0].value.as < string > ())))); }
#line 1450 "parser.tab.cc"
    break;

  case 44: // expr: TRUE
#line 407 "parser.yy"
       { yylhs.value.as < shared_ptr<Expression> > () = make_shared<ValueExpression> (make_shared<Data> (make_shared<Boolean>(true))); }
#line 1456 "parser.tab.cc"
    break;

  case 45: // expr: FALSE
#line 408 "parser.yy"
        { yylhs.value.as < shared_ptr<Expression> > () = make_shared<ValueExpression> (make_shared<Data> (make_shared<Boolean>(false))); }
#line 1462 "parser.tab.cc"
    break;

  case 46: // expr: NULL_TOKEN
#line 409 "parser.yy"
             { yylhs.value.as < shared_ptr<Expression> > () = make_shared<ValueExpression> (make_shared<Data> (make_shared<NullType>())); }
#line 1468 "parser.tab.cc"
    break;

  case 47: // expr: INF
#line 410 "parser.yy"
      { yylhs.value.as < shared_ptr<Expression> > () = make_shared<ValueExpression> (make_shared<Data> (make_shared<InfType>())); }
#line 1474 "parser.tab.cc"
    break;

  case 48: // expr: ID
#line 411 "parser.yy"
     {
    bool non_declared;
    auto var = interpreter.get_variable(yystack_[0].value.as < string > (), non_declared);
    if(!non_declared)
    {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<ValueExpression>(var.mem_location, string(yystack_[0].value.as < string > ()));
    }
    else
    {
        cout << "ERROR: variable not declared in this scope." <<endl;
        return 1;
    }
}
#line 1492 "parser.tab.cc"
    break;

  case 49: // expr: expr PLUS expr
#line 424 "parser.yy"
                 {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::ADD);}
#line 1498 "parser.tab.cc"
    break;

  case 50: // expr: expr MINUS expr
#line 425 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::SUB);}
#line 1504 "parser.tab.cc"
    break;

  case 51: // expr: expr TIMES expr
#line 426 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::MULT);}
#line 1510 "parser.tab.cc"
    break;

  case 52: // expr: expr MOD expr
#line 427 "parser.yy"
                {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::MOD);}
#line 1516 "parser.tab.cc"
    break;

  case 53: // expr: expr DIVIDE expr
#line 428 "parser.yy"
                   {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::DIV);}
#line 1522 "parser.tab.cc"
    break;

  case 54: // expr: expr POWER expr
#line 429 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::POW);}
#line 1528 "parser.tab.cc"
    break;

  case 55: // expr: expr EQUAL expr
#line 430 "parser.yy"
                  {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::EQ);}
#line 1534 "parser.tab.cc"
    break;

  case 56: // expr: expr NOT_EQUAL expr
#line 431 "parser.yy"
                      {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::NEQ);}
#line 1540 "parser.tab.cc"
    break;

  case 57: // expr: expr GREATER_THAN expr
#line 432 "parser.yy"
                         {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::GT);}
#line 1546 "parser.tab.cc"
    break;

  case 58: // expr: expr LESS_THAN expr
#line 433 "parser.yy"
                      {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::LT);}
#line 1552 "parser.tab.cc"
    break;

  case 59: // expr: expr GREATER_THAN_EQ expr
#line 434 "parser.yy"
                            {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::EQ_GT);}
#line 1558 "parser.tab.cc"
    break;

  case 60: // expr: expr LESS_THAN_EQ expr
#line 435 "parser.yy"
                         {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::EQ_LT);}
#line 1564 "parser.tab.cc"
    break;

  case 61: // expr: expr AND expr
#line 436 "parser.yy"
                {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::AND);}
#line 1570 "parser.tab.cc"
    break;

  case 62: // expr: expr OR expr
#line 437 "parser.yy"
               {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::OR);}
#line 1576 "parser.tab.cc"
    break;

  case 63: // expr: expr XOR expr
#line 438 "parser.yy"
                {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::XOR);}
#line 1582 "parser.tab.cc"
    break;

  case 64: // expr: expr NEITHER expr
#line 439 "parser.yy"
                    {yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression> (yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Expression> > (), BinaryExpression::NEITHER);}
#line 1588 "parser.tab.cc"
    break;

  case 65: // expr: MINUS expr
#line 440 "parser.yy"
             {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression> (yystack_[0].value.as < shared_ptr<Expression> > (), UnaryExpression::INV);}
#line 1594 "parser.tab.cc"
    break;

  case 66: // expr: NOT expr
#line 441 "parser.yy"
           {yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression> (yystack_[0].value.as < shared_ptr<Expression> > (), UnaryExpression::NOT);}
#line 1600 "parser.tab.cc"
    break;

  case 67: // expr: LEFT_PARENTHESES expr RIGHT_PARENTHESES
#line 442 "parser.yy"
                                          {yylhs.value.as < shared_ptr<Expression> > () = yystack_[1].value.as < shared_ptr<Expression> > ();}
#line 1606 "parser.tab.cc"
    break;


#line 1610 "parser.tab.cc"

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
        std::string msg = YY_("syntax error");
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

#if YYDEBUG || 0
  const char *
  CS_Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char CS_Parser::yypact_ninf_ = -57;

  const signed char CS_Parser::yytable_ninf_ = -6;

  const short
  CS_Parser::yypact_[] =
  {
     -57,     2,   396,   -57,   -25,    63,   -57,   -57,   -57,   -57,
      -9,    13,    63,    63,    17,    -7,   -57,   -57,   -57,    35,
     -57,   -57,    63,    63,   -57,   -57,   -57,   -57,    63,   -57,
     575,   -57,    63,   158,   575,     8,   -57,    63,     6,    -2,
     271,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,   575,   416,    63,
      63,   575,   -57,     6,     6,    46,    46,   -57,    46,    -2,
      -2,    -2,    -2,    -2,    -2,   594,   140,   140,   140,   -57,
      18,   252,    96,   376,    63,   -20,    63,    63,    22,   -17,
     177,    12,   -57,   115,   205,   -57,   536,    14,   -57,   436,
     456,    63,    25,    27,   -57,    24,   476,   -57,    18,   -57,
      30,   224,   -57,   536,   -57,   536,   276,   -57,   -57,    32,
     376,   -57,   496,   -57,    33,   -57,    31,   -57,    36,   -57,
     516,   -57,   -57,   -57,   -57,   536,   301,   -57,   326,   -57,
     -57,   -57,    37,   -57,   -57,   351,   -57,   -57
  };

  const signed char
  CS_Parser::yydefact_[] =
  {
       3,     0,     5,     1,     0,     0,    10,    13,    11,    14,
       0,     0,     0,     0,     0,     0,     6,     8,     9,     0,
      42,    43,     0,     0,    44,    45,    46,    47,     0,    48,
      12,     2,     0,     0,     7,     0,     4,     0,    65,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     5,     0,
       0,    16,    67,    49,    50,    51,    53,    54,    52,    55,
      58,    57,    60,    59,    56,    61,    62,    63,    64,     3,
      39,     0,     0,    39,     0,     0,     0,     0,    33,     0,
       0,     0,    19,     0,     0,    31,     5,     0,    17,     5,
       5,     0,    29,    37,     3,     0,     5,     3,    39,     3,
       0,     0,    27,     5,    35,     5,     5,    34,     3,     0,
      39,    41,     5,    22,    25,     3,     0,     3,     0,    32,
       5,    21,    40,    20,    23,     5,     5,    30,     5,    38,
      18,     3,     0,    28,    36,     5,    26,    24
  };

  const signed char
  CS_Parser::yypgoto_[] =
  {
     -57,   -57,   -28,   -50,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -56,   -12
  };

  const unsigned char
  CS_Parser::yydefgoto_[] =
  {
       0,     1,     2,    15,    16,    17,    18,   141,   135,   125,
     113,   104,    96,   127,   115,    85,    30
  };

  const short
  CS_Parser::yytable_[] =
  {
      33,    34,     3,    41,    42,    43,    44,    45,    80,    46,
      38,    39,    19,    43,    44,    45,    40,    46,    59,    91,
      57,    92,    97,    32,    98,    61,    31,    89,    36,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    37,   105,    81,    82,   108,
     110,    83,   121,    60,    35,    45,   119,    95,    84,   100,
     112,   106,   114,   126,   132,   128,    20,    21,   134,    22,
     117,   123,    90,   131,    93,    94,   116,   137,     0,   120,
      23,   122,   139,   146,     0,   142,     0,     0,     0,   111,
     130,     0,    24,    25,    26,    27,    28,   136,     0,   138,
      29,    41,    42,    43,    44,    45,     0,    46,    47,    48,
      49,    50,    51,   145,    52,     0,    53,    54,    55,    56,
      41,    42,    43,    44,    45,     0,    46,    47,    48,    49,
      50,    51,     0,    52,     0,    53,    54,    55,    56,     0,
      87,     0,     0,    88,     0,    41,    42,    43,    44,    45,
       0,    46,    47,    48,    49,    50,    51,     0,    52,   101,
      53,     0,   102,    41,    42,    43,    44,    45,     0,    46,
      47,    48,    49,    50,    51,     0,    52,     0,    53,    54,
      55,    56,    41,    42,    43,    44,    45,     0,    46,    47,
      48,    49,    50,    51,     0,    52,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    58,     0,     0,     0,     0,
      41,    42,    43,    44,    45,     0,    46,    47,    48,    49,
      50,    51,     0,    52,    99,    53,    54,    55,    56,    41,
      42,    43,    44,    45,     0,    46,    47,    48,    49,    50,
      51,     0,    52,     0,    53,    54,    55,    56,     0,     0,
       0,     0,   103,     0,     0,     0,     0,    41,    42,    43,
      44,    45,     0,    46,    47,    48,    49,    50,    51,     0,
      52,   124,    53,    54,    55,    56,    41,    42,    43,    44,
      45,     0,    46,    47,    48,    49,    50,    51,     0,    52,
       0,    53,    54,    55,    56,     4,     0,    86,     0,     0,
       5,     6,     7,     8,     9,    62,     0,     0,     0,     0,
       0,     0,     0,    11,    12,     0,     0,     0,    13,    14,
       4,     0,   129,     0,     0,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
       0,     0,     0,    13,    14,     4,     0,   143,     0,     0,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,     0,     0,     0,    13,    14,
       4,     0,   144,     0,     0,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
       0,     0,     0,    13,    14,     4,     0,   147,     0,     0,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,    -5,     0,    11,    12,     4,    84,     0,    13,    14,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,     4,     0,     0,    13,    14,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,    79,     0,    11,    12,     4,     0,     0,    13,    14,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,   107,     0,    11,    12,     4,     0,     0,    13,    14,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,   109,     0,    11,    12,     4,     0,     0,    13,    14,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,   118,     0,    11,    12,     4,     0,     0,    13,    14,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,     4,     0,   133,    13,    14,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,     4,     0,   140,    13,    14,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,     0,     0,     0,    13,    14,
      41,    42,    43,    44,    45,     0,    46,    47,    48,    49,
      50,    51,     0,    52,     0,    53,    54,    55,    56,    41,
      42,    43,    44,    45,     0,    46,    47,    48,    49,    50,
      51,     0,    52
  };

  const short
  CS_Parser::yycheck_[] =
  {
      12,    13,     0,     5,     6,     7,     8,     9,    58,    11,
      22,    23,    37,     7,     8,     9,    28,    11,    10,    39,
      32,    41,    39,    10,    41,    37,    35,    83,    35,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    10,    96,    59,    60,    99,
     100,    79,   108,    45,    37,     9,   106,    35,    40,    47,
      35,    47,    35,   113,   120,   115,     3,     4,    35,     6,
      46,    41,    84,    41,    86,    87,   104,    46,    -1,   107,
      17,   109,    46,    46,    -1,   135,    -1,    -1,    -1,   101,
     118,    -1,    29,    30,    31,    32,    33,   125,    -1,   127,
      37,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    16,   141,    18,    -1,    20,    21,    22,    23,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,    16,    -1,    18,    -1,    20,    21,    22,    23,    -1,
      44,    -1,    -1,    47,    -1,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    16,    -1,    18,    44,
      20,    -1,    47,     5,     6,     7,     8,     9,    -1,    11,
      12,    13,    14,    15,    16,    -1,    18,    -1,    20,    21,
      22,    23,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,    16,    -1,    18,    47,    20,    21,    22,    23,     5,
       6,     7,     8,     9,    -1,    11,    12,    13,    14,    15,
      16,    -1,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    15,    16,    -1,
      18,    47,    20,    21,    22,    23,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    16,    -1,    18,
      -1,    20,    21,    22,    23,    19,    -1,    45,    -1,    -1,
      24,    25,    26,    27,    28,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    42,    43,
      19,    -1,    46,    -1,    -1,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    -1,    -1,    42,    43,    19,    -1,    46,    -1,    -1,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    42,    43,
      19,    -1,    46,    -1,    -1,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    -1,    -1,    42,    43,    19,    -1,    46,    -1,    -1,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    37,    38,    19,    40,    -1,    42,    43,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    19,    -1,    -1,    42,    43,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    37,    38,    19,    -1,    -1,    42,    43,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    37,    38,    19,    -1,    -1,    42,    43,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    37,    38,    19,    -1,    -1,    42,    43,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    37,    38,    19,    -1,    -1,    42,    43,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    19,    -1,    41,    42,    43,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    19,    -1,    41,    42,    43,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    42,    43,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,    16,    -1,    18,    -1,    20,    21,    22,    23,     5,
       6,     7,     8,     9,    -1,    11,    12,    13,    14,    15,
      16,    -1,    18
  };

  const signed char
  CS_Parser::yystos_[] =
  {
       0,    49,    50,     0,    19,    24,    25,    26,    27,    28,
      36,    37,    38,    42,    43,    51,    52,    53,    54,    37,
       3,     4,     6,    17,    29,    30,    31,    32,    33,    37,
      64,    35,    10,    64,    64,    37,    35,    10,    64,    64,
      64,     5,     6,     7,     8,     9,    11,    12,    13,    14,
      15,    16,    18,    20,    21,    22,    23,    64,    47,    10,
      45,    64,    34,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    35,
      51,    64,    64,    50,    40,    63,    45,    44,    47,    63,
      64,    39,    41,    64,    64,    35,    60,    39,    41,    47,
      47,    44,    47,    47,    59,    51,    47,    35,    51,    35,
      51,    64,    35,    58,    35,    62,    50,    46,    35,    51,
      50,    63,    50,    41,    47,    57,    51,    61,    51,    46,
      50,    41,    63,    41,    35,    56,    50,    46,    50,    46,
      41,    55,    51,    46,    46,    50,    46,    46
  };

  const signed char
  CS_Parser::yyr1_[] =
  {
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    55,    54,    56,    54,    57,    54,    58,
      54,    59,    54,    60,    54,    61,    54,    62,    54,    63,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64
  };

  const signed char
  CS_Parser::yyr2_[] =
  {
       0,     2,     3,     0,     3,     0,     1,     2,     1,     1,
       1,     1,     2,     1,     1,     3,     4,     7,    11,     6,
      10,    10,     9,     0,    13,     0,    12,     0,    11,     0,
      10,     0,     9,     0,     8,     0,    11,     0,    10,     0,
       6,     5,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const CS_Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "DEC", "STR", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "POWER", "ASSIGN", "MOD", "EQUAL",
  "LESS_THAN", "GREATER_THAN", "LESS_THAN_EQ", "GREATER_THAN_EQ", "NOT",
  "NOT_EQUAL", "CONST", "AND", "OR", "XOR", "NEITHER", "ADVANCE", "BREAK",
  "CONTINUE", "BREAK_ALL", "REPEAT", "TRUE", "FALSE", "NULL_TOKEN", "INF",
  "LEFT_PARENTHESES", "RIGHT_PARENTHESES", "EOL", "STOP", "ID", "IF",
  "ELSE", "ELIF", "ENDIF", "PRINT", "FOR", "BY", "TO", "ENDFOR", "COLUMN",
  "$accept", "input", "program", "statement", "assignment", "if_statement",
  "for_counter_loop", "@1", "@2", "@3", "@4", "@5", "@6", "@7", "@8",
  "elif_branch", "expr", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  CS_Parser::yyrline_[] =
  {
       0,   103,   103,   109,   112,   121,   122,   125,   128,   131,
     134,   141,   148,   155,   162,   171,   188,   204,   208,   212,
     216,   220,   224,   231,   230,   251,   250,   271,   270,   291,
     290,   311,   310,   331,   330,   352,   351,   373,   372,   394,
     395,   399,   405,   406,   407,   408,   409,   410,   411,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442
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
      45,    46,    47
    };
    // Last valid token kind.
    const int code_max = 302;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 7 "parser.yy"
} // CS
#line 2154 "parser.tab.cc"

#line 444 "parser.yy"


void 
CS::CS_Parser::error( const location_type &l, const std::string &err_message )
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
        /* curr_program->run(); */
    }
    interpreter.pop_scope();
}
