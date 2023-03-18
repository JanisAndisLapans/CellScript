// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file parser.tab.hh
 ** Define the CS::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 13 "parser.yy"

    #include <string>
    #include <string>
    #include <vector>
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

#line 74 "parser.tab.hh"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 7 "parser.yy"
namespace CS {
#line 215 "parser.tab.hh"




  /// A Bison parser.
  class CS_Parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // @2
      char dummy1[sizeof (DataPtr)];

      // @1
      // @3
      // @4
      // @5
      // @6
      // @7
      // @8
      // @9
      // @10
      char dummy2[sizeof (int)];

      // assignment
      char dummy3[sizeof (shared_ptr<AssignStatement>)];

      // expr
      // expr_val
      char dummy4[sizeof (shared_ptr<Expression>)];

      // for_counter_loop
      char dummy5[sizeof (shared_ptr<ForCounterLoop>)];

      // function
      // @11
      // @12
      char dummy6[sizeof (shared_ptr<Function>)];

      // function_call
      char dummy7[sizeof (shared_ptr<FunctionStatement>)];

      // if_statement
      char dummy8[sizeof (shared_ptr<IfStatement>)];

      // program
      char dummy9[sizeof (shared_ptr<Program>)];

      // statement
      char dummy10[sizeof (shared_ptr<Statement>)];

      // DEC
      // STR
      // ID
      char dummy11[sizeof (string)];

      // elif_branch
      char dummy12[sizeof (vector<pair<shared_ptr<Expression>, shared_ptr<Program>>>)];

      // expr_list
      char dummy13[sizeof (vector<shared_ptr<Expression>>)];

      // id_list
      char dummy14[sizeof (vector<string>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    DEC = 258,                     // DEC
    STR = 259,                     // STR
    ONE_LINE_COMMENT = 260,        // ONE_LINE_COMMENT
    PLUS = 261,                    // PLUS
    MINUS = 262,                   // MINUS
    TIMES = 263,                   // TIMES
    DIVIDE = 264,                  // DIVIDE
    POWER = 265,                   // POWER
    ASSIGN = 266,                  // ASSIGN
    MOD = 267,                     // MOD
    EQUAL = 268,                   // EQUAL
    LESS_THAN = 269,               // LESS_THAN
    GREATER_THAN = 270,            // GREATER_THAN
    LESS_THAN_EQ = 271,            // LESS_THAN_EQ
    GREATER_THAN_EQ = 272,         // GREATER_THAN_EQ
    NOT = 273,                     // NOT
    NOT_EQUAL = 274,               // NOT_EQUAL
    CONST = 275,                   // CONST
    SELF = 276,                    // SELF
    AND = 277,                     // AND
    OR = 278,                      // OR
    XOR = 279,                     // XOR
    NEITHER = 280,                 // NEITHER
    ADVANCE = 281,                 // ADVANCE
    BREAK = 282,                   // BREAK
    CONTINUE = 283,                // CONTINUE
    BREAK_ALL = 284,               // BREAK_ALL
    REPEAT = 285,                  // REPEAT
    RETURN = 286,                  // RETURN
    TRUE = 287,                    // TRUE
    FALSE = 288,                   // FALSE
    NULL_TOKEN = 289,              // NULL_TOKEN
    INF = 290,                     // INF
    LEFT_PARENTHESES = 291,        // LEFT_PARENTHESES
    RIGHT_PARENTHESES = 292,       // RIGHT_PARENTHESES
    EOL = 293,                     // EOL
    STOP = 294,                    // STOP
    ID = 295,                      // ID
    IF = 296,                      // IF
    ELSE = 297,                    // ELSE
    ELIF = 298,                    // ELIF
    ENDIF = 299,                   // ENDIF
    PRINT = 300,                   // PRINT
    FOR = 301,                     // FOR
    BY = 302,                      // BY
    TO = 303,                      // TO
    ENDFOR = 304,                  // ENDFOR
    FUNC = 305,                    // FUNC
    ENDFUNC = 306,                 // ENDFUNC
    COLUMN = 307,                  // COLUMN
    COMMA = 308,                   // COMMA
    AS = 309,                      // AS
    NumType = 310,                 // NumType
    BoolType = 311,                // BoolType
    StrType = 312,                 // StrType
    GIVE = 313                     // GIVE
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 59, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_DEC = 3,                               // DEC
        S_STR = 4,                               // STR
        S_ONE_LINE_COMMENT = 5,                  // ONE_LINE_COMMENT
        S_PLUS = 6,                              // PLUS
        S_MINUS = 7,                             // MINUS
        S_TIMES = 8,                             // TIMES
        S_DIVIDE = 9,                            // DIVIDE
        S_POWER = 10,                            // POWER
        S_ASSIGN = 11,                           // ASSIGN
        S_MOD = 12,                              // MOD
        S_EQUAL = 13,                            // EQUAL
        S_LESS_THAN = 14,                        // LESS_THAN
        S_GREATER_THAN = 15,                     // GREATER_THAN
        S_LESS_THAN_EQ = 16,                     // LESS_THAN_EQ
        S_GREATER_THAN_EQ = 17,                  // GREATER_THAN_EQ
        S_NOT = 18,                              // NOT
        S_NOT_EQUAL = 19,                        // NOT_EQUAL
        S_CONST = 20,                            // CONST
        S_SELF = 21,                             // SELF
        S_AND = 22,                              // AND
        S_OR = 23,                               // OR
        S_XOR = 24,                              // XOR
        S_NEITHER = 25,                          // NEITHER
        S_ADVANCE = 26,                          // ADVANCE
        S_BREAK = 27,                            // BREAK
        S_CONTINUE = 28,                         // CONTINUE
        S_BREAK_ALL = 29,                        // BREAK_ALL
        S_REPEAT = 30,                           // REPEAT
        S_RETURN = 31,                           // RETURN
        S_TRUE = 32,                             // TRUE
        S_FALSE = 33,                            // FALSE
        S_NULL_TOKEN = 34,                       // NULL_TOKEN
        S_INF = 35,                              // INF
        S_LEFT_PARENTHESES = 36,                 // LEFT_PARENTHESES
        S_RIGHT_PARENTHESES = 37,                // RIGHT_PARENTHESES
        S_EOL = 38,                              // EOL
        S_STOP = 39,                             // STOP
        S_ID = 40,                               // ID
        S_IF = 41,                               // IF
        S_ELSE = 42,                             // ELSE
        S_ELIF = 43,                             // ELIF
        S_ENDIF = 44,                            // ENDIF
        S_PRINT = 45,                            // PRINT
        S_FOR = 46,                              // FOR
        S_BY = 47,                               // BY
        S_TO = 48,                               // TO
        S_ENDFOR = 49,                           // ENDFOR
        S_FUNC = 50,                             // FUNC
        S_ENDFUNC = 51,                          // ENDFUNC
        S_COLUMN = 52,                           // COLUMN
        S_COMMA = 53,                            // COMMA
        S_AS = 54,                               // AS
        S_NumType = 55,                          // NumType
        S_BoolType = 56,                         // BoolType
        S_StrType = 57,                          // StrType
        S_GIVE = 58,                             // GIVE
        S_YYACCEPT = 59,                         // $accept
        S_input = 60,                            // input
        S_program = 61,                          // program
        S_statement = 62,                        // statement
        S_function_call = 63,                    // function_call
        S_assignment = 64,                       // assignment
        S_65_1 = 65,                             // @1
        S_66_2 = 66,                             // @2
        S_if_statement = 67,                     // if_statement
        S_for_counter_loop = 68,                 // for_counter_loop
        S_69_3 = 69,                             // @3
        S_70_4 = 70,                             // @4
        S_71_5 = 71,                             // @5
        S_72_6 = 72,                             // @6
        S_73_7 = 73,                             // @7
        S_74_8 = 74,                             // @8
        S_75_9 = 75,                             // @9
        S_76_10 = 76,                            // @10
        S_elif_branch = 77,                      // elif_branch
        S_expr = 78,                             // expr
        S_expr_val = 79,                         // expr_val
        S_expr_list = 80,                        // expr_list
        S_function = 81,                         // function
        S_82_11 = 82,                            // @11
        S_83_12 = 83,                            // @12
        S_id_list = 84                           // id_list
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_66_2: // @2
        value.move< DataPtr > (std::move (that.value));
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
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_assignment: // assignment
        value.move< shared_ptr<AssignStatement> > (std::move (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_val: // expr_val
        value.move< shared_ptr<Expression> > (std::move (that.value));
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        value.move< shared_ptr<ForCounterLoop> > (std::move (that.value));
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_82_11: // @11
      case symbol_kind::S_83_12: // @12
        value.move< shared_ptr<Function> > (std::move (that.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.move< shared_ptr<FunctionStatement> > (std::move (that.value));
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.move< shared_ptr<IfStatement> > (std::move (that.value));
        break;

      case symbol_kind::S_program: // program
        value.move< shared_ptr<Program> > (std::move (that.value));
        break;

      case symbol_kind::S_statement: // statement
        value.move< shared_ptr<Statement> > (std::move (that.value));
        break;

      case symbol_kind::S_DEC: // DEC
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_ID: // ID
        value.move< string > (std::move (that.value));
        break;

      case symbol_kind::S_elif_branch: // elif_branch
        value.move< vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > (std::move (that.value));
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.move< vector<shared_ptr<Expression>> > (std::move (that.value));
        break;

      case symbol_kind::S_id_list: // id_list
        value.move< vector<string> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DataPtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DataPtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<AssignStatement>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<AssignStatement>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Expression>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Expression>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<ForCounterLoop>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<ForCounterLoop>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Function>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Function>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<FunctionStatement>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<FunctionStatement>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<IfStatement>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<IfStatement>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Program>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Program>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Statement>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Statement>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, vector<pair<shared_ptr<Expression>, shared_ptr<Program>>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const vector<pair<shared_ptr<Expression>, shared_ptr<Program>>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, vector<shared_ptr<Expression>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const vector<shared_ptr<Expression>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, vector<string>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const vector<string>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_66_2: // @2
        value.template destroy< DataPtr > ();
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
        value.template destroy< int > ();
        break;

      case symbol_kind::S_assignment: // assignment
        value.template destroy< shared_ptr<AssignStatement> > ();
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_expr_val: // expr_val
        value.template destroy< shared_ptr<Expression> > ();
        break;

      case symbol_kind::S_for_counter_loop: // for_counter_loop
        value.template destroy< shared_ptr<ForCounterLoop> > ();
        break;

      case symbol_kind::S_function: // function
      case symbol_kind::S_82_11: // @11
      case symbol_kind::S_83_12: // @12
        value.template destroy< shared_ptr<Function> > ();
        break;

      case symbol_kind::S_function_call: // function_call
        value.template destroy< shared_ptr<FunctionStatement> > ();
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.template destroy< shared_ptr<IfStatement> > ();
        break;

      case symbol_kind::S_program: // program
        value.template destroy< shared_ptr<Program> > ();
        break;

      case symbol_kind::S_statement: // statement
        value.template destroy< shared_ptr<Statement> > ();
        break;

      case symbol_kind::S_DEC: // DEC
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_ID: // ID
        value.template destroy< string > ();
        break;

      case symbol_kind::S_elif_branch: // elif_branch
        value.template destroy< vector<pair<shared_ptr<Expression>, shared_ptr<Program>>> > ();
        break;

      case symbol_kind::S_expr_list: // expr_list
        value.template destroy< vector<shared_ptr<Expression>> > ();
        break;

      case symbol_kind::S_id_list: // id_list
        value.template destroy< vector<string> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return CS_Parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::YYEOF
                   || (token::YYerror <= tok && tok <= token::YYUNDEF)
                   || (token::ONE_LINE_COMMENT <= tok && tok <= token::STOP)
                   || (token::IF <= tok && tok <= token::GIVE));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::DEC <= tok && tok <= token::STR)
                   || tok == token::ID);
#endif
      }
    };

    /// Build a parser object.
    CS_Parser (CS::CS_Scanner  &scanner_yyarg);
    virtual ~CS_Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    CS_Parser (const CS_Parser&) = delete;
    /// Non copyable.
    CS_Parser& operator= (const CS_Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEC (string v, location_type l)
      {
        return symbol_type (token::DEC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DEC (const string& v, const location_type& l)
      {
        return symbol_type (token::DEC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STR (string v, location_type l)
      {
        return symbol_type (token::STR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STR (const string& v, const location_type& l)
      {
        return symbol_type (token::STR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ONE_LINE_COMMENT (location_type l)
      {
        return symbol_type (token::ONE_LINE_COMMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_ONE_LINE_COMMENT (const location_type& l)
      {
        return symbol_type (token::ONE_LINE_COMMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIMES (location_type l)
      {
        return symbol_type (token::TIMES, std::move (l));
      }
#else
      static
      symbol_type
      make_TIMES (const location_type& l)
      {
        return symbol_type (token::TIMES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIVIDE (location_type l)
      {
        return symbol_type (token::DIVIDE, std::move (l));
      }
#else
      static
      symbol_type
      make_DIVIDE (const location_type& l)
      {
        return symbol_type (token::DIVIDE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POWER (location_type l)
      {
        return symbol_type (token::POWER, std::move (l));
      }
#else
      static
      symbol_type
      make_POWER (const location_type& l)
      {
        return symbol_type (token::POWER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (location_type l)
      {
        return symbol_type (token::ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const location_type& l)
      {
        return symbol_type (token::ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD (location_type l)
      {
        return symbol_type (token::MOD, std::move (l));
      }
#else
      static
      symbol_type
      make_MOD (const location_type& l)
      {
        return symbol_type (token::MOD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (location_type l)
      {
        return symbol_type (token::EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL (const location_type& l)
      {
        return symbol_type (token::EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS_THAN (location_type l)
      {
        return symbol_type (token::LESS_THAN, std::move (l));
      }
#else
      static
      symbol_type
      make_LESS_THAN (const location_type& l)
      {
        return symbol_type (token::LESS_THAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER_THAN (location_type l)
      {
        return symbol_type (token::GREATER_THAN, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER_THAN (const location_type& l)
      {
        return symbol_type (token::GREATER_THAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS_THAN_EQ (location_type l)
      {
        return symbol_type (token::LESS_THAN_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_LESS_THAN_EQ (const location_type& l)
      {
        return symbol_type (token::LESS_THAN_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER_THAN_EQ (location_type l)
      {
        return symbol_type (token::GREATER_THAN_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER_THAN_EQ (const location_type& l)
      {
        return symbol_type (token::GREATER_THAN_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (location_type l)
      {
        return symbol_type (token::NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const location_type& l)
      {
        return symbol_type (token::NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT_EQUAL (location_type l)
      {
        return symbol_type (token::NOT_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_NOT_EQUAL (const location_type& l)
      {
        return symbol_type (token::NOT_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONST (location_type l)
      {
        return symbol_type (token::CONST, std::move (l));
      }
#else
      static
      symbol_type
      make_CONST (const location_type& l)
      {
        return symbol_type (token::CONST, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SELF (location_type l)
      {
        return symbol_type (token::SELF, std::move (l));
      }
#else
      static
      symbol_type
      make_SELF (const location_type& l)
      {
        return symbol_type (token::SELF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (location_type l)
      {
        return symbol_type (token::OR, std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const location_type& l)
      {
        return symbol_type (token::OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XOR (location_type l)
      {
        return symbol_type (token::XOR, std::move (l));
      }
#else
      static
      symbol_type
      make_XOR (const location_type& l)
      {
        return symbol_type (token::XOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEITHER (location_type l)
      {
        return symbol_type (token::NEITHER, std::move (l));
      }
#else
      static
      symbol_type
      make_NEITHER (const location_type& l)
      {
        return symbol_type (token::NEITHER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADVANCE (location_type l)
      {
        return symbol_type (token::ADVANCE, std::move (l));
      }
#else
      static
      symbol_type
      make_ADVANCE (const location_type& l)
      {
        return symbol_type (token::ADVANCE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (location_type l)
      {
        return symbol_type (token::BREAK, std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const location_type& l)
      {
        return symbol_type (token::BREAK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTINUE (location_type l)
      {
        return symbol_type (token::CONTINUE, std::move (l));
      }
#else
      static
      symbol_type
      make_CONTINUE (const location_type& l)
      {
        return symbol_type (token::CONTINUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK_ALL (location_type l)
      {
        return symbol_type (token::BREAK_ALL, std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK_ALL (const location_type& l)
      {
        return symbol_type (token::BREAK_ALL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REPEAT (location_type l)
      {
        return symbol_type (token::REPEAT, std::move (l));
      }
#else
      static
      symbol_type
      make_REPEAT (const location_type& l)
      {
        return symbol_type (token::REPEAT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (location_type l)
      {
        return symbol_type (token::RETURN, std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const location_type& l)
      {
        return symbol_type (token::RETURN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUE (location_type l)
      {
        return symbol_type (token::TRUE, std::move (l));
      }
#else
      static
      symbol_type
      make_TRUE (const location_type& l)
      {
        return symbol_type (token::TRUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSE (location_type l)
      {
        return symbol_type (token::FALSE, std::move (l));
      }
#else
      static
      symbol_type
      make_FALSE (const location_type& l)
      {
        return symbol_type (token::FALSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NULL_TOKEN (location_type l)
      {
        return symbol_type (token::NULL_TOKEN, std::move (l));
      }
#else
      static
      symbol_type
      make_NULL_TOKEN (const location_type& l)
      {
        return symbol_type (token::NULL_TOKEN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INF (location_type l)
      {
        return symbol_type (token::INF, std::move (l));
      }
#else
      static
      symbol_type
      make_INF (const location_type& l)
      {
        return symbol_type (token::INF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_PARENTHESES (location_type l)
      {
        return symbol_type (token::LEFT_PARENTHESES, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_PARENTHESES (const location_type& l)
      {
        return symbol_type (token::LEFT_PARENTHESES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_PARENTHESES (location_type l)
      {
        return symbol_type (token::RIGHT_PARENTHESES, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_PARENTHESES (const location_type& l)
      {
        return symbol_type (token::RIGHT_PARENTHESES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EOL (location_type l)
      {
        return symbol_type (token::EOL, std::move (l));
      }
#else
      static
      symbol_type
      make_EOL (const location_type& l)
      {
        return symbol_type (token::EOL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STOP (location_type l)
      {
        return symbol_type (token::STOP, std::move (l));
      }
#else
      static
      symbol_type
      make_STOP (const location_type& l)
      {
        return symbol_type (token::STOP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (string v, location_type l)
      {
        return symbol_type (token::ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID (const string& v, const location_type& l)
      {
        return symbol_type (token::ID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELIF (location_type l)
      {
        return symbol_type (token::ELIF, std::move (l));
      }
#else
      static
      symbol_type
      make_ELIF (const location_type& l)
      {
        return symbol_type (token::ELIF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENDIF (location_type l)
      {
        return symbol_type (token::ENDIF, std::move (l));
      }
#else
      static
      symbol_type
      make_ENDIF (const location_type& l)
      {
        return symbol_type (token::ENDIF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINT (location_type l)
      {
        return symbol_type (token::PRINT, std::move (l));
      }
#else
      static
      symbol_type
      make_PRINT (const location_type& l)
      {
        return symbol_type (token::PRINT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (location_type l)
      {
        return symbol_type (token::FOR, std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const location_type& l)
      {
        return symbol_type (token::FOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BY (location_type l)
      {
        return symbol_type (token::BY, std::move (l));
      }
#else
      static
      symbol_type
      make_BY (const location_type& l)
      {
        return symbol_type (token::BY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TO (location_type l)
      {
        return symbol_type (token::TO, std::move (l));
      }
#else
      static
      symbol_type
      make_TO (const location_type& l)
      {
        return symbol_type (token::TO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENDFOR (location_type l)
      {
        return symbol_type (token::ENDFOR, std::move (l));
      }
#else
      static
      symbol_type
      make_ENDFOR (const location_type& l)
      {
        return symbol_type (token::ENDFOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNC (location_type l)
      {
        return symbol_type (token::FUNC, std::move (l));
      }
#else
      static
      symbol_type
      make_FUNC (const location_type& l)
      {
        return symbol_type (token::FUNC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENDFUNC (location_type l)
      {
        return symbol_type (token::ENDFUNC, std::move (l));
      }
#else
      static
      symbol_type
      make_ENDFUNC (const location_type& l)
      {
        return symbol_type (token::ENDFUNC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLUMN (location_type l)
      {
        return symbol_type (token::COLUMN, std::move (l));
      }
#else
      static
      symbol_type
      make_COLUMN (const location_type& l)
      {
        return symbol_type (token::COLUMN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AS (location_type l)
      {
        return symbol_type (token::AS, std::move (l));
      }
#else
      static
      symbol_type
      make_AS (const location_type& l)
      {
        return symbol_type (token::AS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NumType (location_type l)
      {
        return symbol_type (token::NumType, std::move (l));
      }
#else
      static
      symbol_type
      make_NumType (const location_type& l)
      {
        return symbol_type (token::NumType, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BoolType (location_type l)
      {
        return symbol_type (token::BoolType, std::move (l));
      }
#else
      static
      symbol_type
      make_BoolType (const location_type& l)
      {
        return symbol_type (token::BoolType, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_StrType (location_type l)
      {
        return symbol_type (token::StrType, std::move (l));
      }
#else
      static
      symbol_type
      make_StrType (const location_type& l)
      {
        return symbol_type (token::StrType, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GIVE (location_type l)
      {
        return symbol_type (token::GIVE, std::move (l));
      }
#else
      static
      symbol_type
      make_GIVE (const location_type& l)
      {
        return symbol_type (token::GIVE, l);
      }
#endif


    class context
    {
    public:
      context (const CS_Parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const CS_Parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    CS_Parser (const CS_Parser&);
    /// Non copyable.
    CS_Parser& operator= (const CS_Parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 994,     ///< Last index in yytable_.
      yynnts_ = 26,  ///< Number of nonterminal symbols.
      yyfinal_ = 3 ///< Termination state number.
    };


    // User arguments.
    CS::CS_Scanner  &scanner;

  };


#line 7 "parser.yy"
} // CS
#line 2509 "parser.tab.hh"




#endif // !YY_YY_PARSER_TAB_HH_INCLUDED
