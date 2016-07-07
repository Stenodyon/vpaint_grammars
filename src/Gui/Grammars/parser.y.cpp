/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 32 "../../src/Gui/Grammars/parser.y" /* yacc.c:316  */

    /* Goes into the .cpp I think */
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>

#include <QString>

#include "Grammars/grammar.h"
#include "Grammars/production.h"
#include "Grammars/medusatype.h"

typedef std::shared_ptr<grammar::MedusaType> type_ptr;
typedef std::pair<std::string, std::list<unsigned int>*> str_type;
typedef grammar::Production::result_structure restruct;
typedef std::list<restruct*> prod_type;
typedef std::shared_ptr<grammar::Production> prod_ptr;
typedef std::shared_ptr<restruct> restruct_ptr;
typedef std::pair<std::string, grammar::AttributeExpr*> attribute_t;
typedef std::list<attribute_t*> attrlist;

void parse_grammar(QString string, grammar::Grammar * grammar);
void add_production(str_type * initial, int newnodes,
                    std::list<prod_type*> * prod_list,
                    grammar::Grammar * grammar);

grammar::Grammar * _grammar;
std::map<std::string,type_ptr> _type_dict;

class initialization_error : public std::invalid_argument
{
   public:
      initialization_error(const char * s)
          : std::invalid_argument(s)
      {}
};

#line 103 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:316  */



/* Copy the first part of user declarations.  */
#line 1 "../../src/Gui/Grammars/parser.y" /* yacc.c:339  */

typedef struct yy_buffer_state * YY_BUFFER_STATE;

extern "C" int yylex();
extern "C" int yyparse();
extern YY_BUFFER_STATE yy_scan_string(const char * str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
extern unsigned int line_number;
extern char * yytext;
void yyerror(const char * s);

#line 120 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.y.h".  */
#ifndef YY_YY_SRC_GUI_GRAMMARS_PARSER_Y_H_INCLUDED
# define YY_YY_SRC_GUI_GRAMMARS_PARSER_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 14 "../../src/Gui/Grammars/parser.y" /* yacc.c:355  */

    /* Goes into the .h I think */
#include <list>
#include <memory>
#include <string>

#include "Eigen/Eigen"

#include "production.h"
#include "attributeexpr.h"

typedef grammar::Production::result_structure restruct;
typedef std::pair<std::string, std::list<unsigned int>*> str_type;
typedef std::list<restruct*> prod_type;
typedef std::pair<std::string, grammar::AttributeExpr*> attribute_t;
typedef std::list<attribute_t*> attrlist;

#line 168 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TERMINAL = 258,
    NONTERMINAL = 259,
    AXIOM = 260,
    COLOR = 261,
    ARROW = 262,
    SEMICOLON = 263,
    LPAR = 264,
    RPAR = 265,
    COMMA = 266,
    VERT = 267,
    LBRA = 268,
    RBRA = 269,
    PLUS = 270,
    TIMES = 271,
    EQUAL = 272,
    PARENTX = 273,
    PARENTY = 274,
    PARENTROTATION = 275,
    NUMBER = 276,
    STRING = 277,
    ATTRIBUTENAME = 278
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 73 "../../src/Gui/Grammars/parser.y" /* yacc.c:355  */

    int ival;
    double fval;
    std::string * sval;
    std::list<unsigned int> * ilistval;
    str_type * strval;
    std::list<restruct*> * strlistval;
    std::list<prod_type*> * prodlistval;
    Eigen::Vector2d * vecval;
    std::list<Eigen::Vector2d*> * veclistval;
    grammar::AttributeExpr * exprval;
    attribute_t * attrval;
    attrlist * attrlistval;
    restruct * restructval;

#line 220 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_GUI_GRAMMARS_PARSER_Y_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 235 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   89

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  40
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  87

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   118,   118,   121,   122,   125,   126,   127,   128,   131,
     147,   158,   180,   188,   192,   199,   203,   210,   237,   265,
     269,   276,   279,   284,   288,   295,   300,   304,   311,   315,
     322,   323,   328,   331,   336,   339,   344,   347,   350,   353,
     356
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TERMINAL", "NONTERMINAL", "AXIOM",
  "COLOR", "ARROW", "SEMICOLON", "LPAR", "RPAR", "COMMA", "VERT", "LBRA",
  "RBRA", "PLUS", "TIMES", "EQUAL", "PARENTX", "PARENTY", "PARENTROTATION",
  "NUMBER", "STRING", "ATTRIBUTENAME", "$accept", "grammar", "statements",
  "statement", "termdef", "nontermdef", "axiomdef", "proddef",
  "productions", "production", "attributedstructure", "structure", "INTS",
  "VECTOR", "VECTORS", "attributes", "attribute", "expression", "term",
  "factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278
};
# endif

#define YYPACT_NINF -51

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -3,   -15,     8,     9,    23,    18,    -3,   -51,   -51,   -51,
     -51,   -51,    13,    24,    26,    28,    -4,   -51,   -51,    30,
      19,    20,   -51,   -51,   -51,    14,    16,    29,    32,   -51,
      22,    35,    37,    34,    36,    38,    40,   -51,    -1,   -51,
      16,    16,    41,   -51,    39,   -51,    42,    17,    43,    44,
     -51,   -51,    31,   -51,    12,    27,    -6,   -51,    -2,   -51,
      -2,    46,    41,    50,   -51,    -6,   -51,   -51,   -51,   -51,
      45,    47,   -51,    51,   -51,    33,   -51,   -51,     1,    -6,
      -6,   -51,    52,   -51,    47,   -51,   -51
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     0,     1,     3,     0,
       0,     0,    11,    22,    24,     0,     0,     0,     0,    21,
       0,     0,     0,    14,    16,     0,     0,    23,     0,    12,
       0,     0,     0,    10,     0,    20,     0,     0,     0,    29,
      13,    15,     0,    27,     0,     0,     0,    19,     0,    18,
       0,     0,     0,     0,    30,     0,    37,    38,    39,    36,
      31,    33,    35,     0,    28,     0,    26,     9,     0,     0,
       0,    17,     0,    40,    32,    34,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,    58,   -51,   -51,   -51,   -51,    25,    48,
     -51,   -51,    49,     4,   -51,   -50,   -51,     2,   -11,   -10
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    10,    11,    32,    33,
      34,    12,    25,    53,    54,    48,    49,    70,    71,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       1,     2,     3,    65,    44,    44,    23,    13,    73,    45,
      74,    83,    66,    67,    68,    69,    79,    24,    17,     4,
      24,    46,    46,    62,    29,    30,    63,    57,    30,    58,
      14,    15,    16,    20,    19,    21,    22,    26,    31,    35,
      27,    28,    36,    37,    38,    39,    40,    41,    43,    64,
      52,    42,    61,    59,    82,    60,    55,    75,    77,    56,
      79,    81,    86,    80,    18,    50,    76,    78,    84,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,    51
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     9,     6,     6,    10,    22,    58,    10,
      60,    10,    18,    19,    20,    21,    15,    21,     0,    22,
      21,    23,    23,    11,    10,    11,    14,    10,    11,    12,
      22,    22,     9,     9,    21,     9,     8,     7,    22,    10,
      21,    21,    10,    21,     9,     8,    12,    11,     8,    22,
       9,    13,    21,    10,    21,    11,    17,    11,     8,    17,
      15,    10,    10,    16,     6,    40,    62,    65,    79,    -1,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    22,    25,    26,    27,    28,    29,
      30,    31,    35,    22,    22,    22,     9,     0,    27,    21,
       9,     9,     8,    10,    21,    36,     7,    21,    21,    10,
      11,    22,    32,    33,    34,    10,    10,    21,     9,     8,
      12,    11,    13,     8,     6,    10,    23,    36,    39,    40,
      32,    33,     9,    37,    38,    17,    17,    10,    12,    10,
      11,    21,    11,    14,    22,     9,    18,    19,    20,    21,
      41,    42,    43,    39,    39,    11,    37,     8,    41,    15,
      16,    10,    21,    10,    42,    43,    10
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    24,    25,    26,    26,    27,    27,    27,    27,    28,
      29,    30,    31,    32,    32,    33,    33,    34,    34,    34,
      34,    35,    35,    36,    36,    37,    38,    38,    39,    39,
      40,    40,    41,    41,    42,    42,    43,    43,    43,    43,
      43
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     9,
       6,     3,     5,     3,     1,     3,     1,     6,     4,     4,
       3,     4,     3,     3,     1,     5,     3,     1,     3,     1,
       3,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 9:
#line 131 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        /*std::cout << "New terminal: \"" << *$2 << "\" of arity "*/
                  /*<< $4 << std::endl;*/
        unsigned int arity = std::stoi(*(yyvsp[-5].sval));
        type_ptr type = std::make_shared<grammar::MedusaType>(*(yyvsp[-7].sval));
        for( Eigen::Vector2d * point : *(yyvsp[-2].veclistval) )
        {
            type->points.push_back(*point);
        }
        delete (yyvsp[-2].veclistval);
        _type_dict[*(yyvsp[-7].sval)] = type;
        delete (yyvsp[-7].sval);
        _grammar->addMedusaType(type);
    }
#line 1377 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 147 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        /*std::cout << "New non-terminal: \"" << *$2 << "\" of arity "*/
                  /*<< $4 << std::endl;*/
        unsigned int arity = std::stoi(*(yyvsp[-2].sval));
        type_ptr type = std::make_shared<grammar::MedusaType>(*(yyvsp[-4].sval));
        _type_dict[*(yyvsp[-4].sval)] = type;
        delete (yyvsp[-4].sval);
        _grammar->addMedusaType(type);
    }
#line 1391 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 158 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        if( _grammar->getAxiom() )
        {
            delete (yyvsp[-1].sval);
            throw std::invalid_argument("Axiom defined twice");
        }
        try
        {
            type_ptr type = _type_dict.at(*(yyvsp[-1].sval));
            _grammar->setAxiom(type);
        }
        catch(const std::out_of_range & exception)
        {
            std::ostringstream sstream;
            sstream << "Undefined element \"" << *(yyvsp[-1].sval) << "\"";
            delete (yyvsp[-1].sval);
            throw initialization_error(sstream.str().c_str());
        }
        delete (yyvsp[-1].sval);
    }
#line 1416 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 180 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        unsigned int newNodes = std::stoi(*(yyvsp[-3].sval));
        add_production((yyvsp[-4].strval), newNodes, (yyvsp[-1].prodlistval), _grammar);
        delete (yyvsp[-4].strval);
        delete (yyvsp[-1].prodlistval);
    }
#line 1427 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 188 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyvsp[0].prodlistval)->push_back((yyvsp[-2].strlistval));
        (yyval.prodlistval) = (yyvsp[0].prodlistval);
    }
#line 1436 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 192 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        std::list<prod_type*> * lst = new std::list<prod_type*>();
        lst->push_back((yyvsp[0].strlistval));
        (yyval.prodlistval) = lst;
    }
#line 1446 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 199 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyvsp[0].strlistval)->push_back((yyvsp[-2].restructval));
        (yyval.strlistval) = (yyvsp[0].strlistval);
    }
#line 1455 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 203 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        std::list<restruct*> * lst = new std::list<restruct*>();
        lst->push_back((yyvsp[0].restructval));
        (yyval.strlistval) = lst;
    }
#line 1465 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 210 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        type_ptr type = _type_dict[*(yyvsp[-5].sval)];
        restruct * rs = new restruct(type, (yyvsp[-3].ilistval));
        for(auto attribute : *(yyvsp[-1].attrlistval))
        {
            std::string name = attribute->first;
            if(name == "x")
            {
                rs->x_expr = attribute->second;
                continue;
            }
            else if(name == "y")
            {
                rs->y_expr = attribute->second;
                continue;
            }
            else if(name == "rotation")
            {
                rs->rotation = attribute->second;
                continue;
            }
            std::ostringstream stream;
            stream << "Unknown attribute \"" << name << "\"";
            throw std::invalid_argument(stream.str());
        }
        (yyval.restructval) = rs;
    }
#line 1497 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 237 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        std::vector<unsigned int> empty;
        type_ptr type = _type_dict[*(yyvsp[-3].sval)];
        restruct * rs = new restruct(type, &empty);
        for(auto attribute : *(yyvsp[-1].attrlistval))
        {
            std::string name = attribute->first;
            if(name == "x")
            {
                rs->x_expr = attribute->second;
                continue;
            }
            else if(name == "y")
            {
                rs->y_expr = attribute->second;
                continue;
            }
            else if(name == "rotation")
            {
                rs->rotation = attribute->second;
                continue;
            }
            std::ostringstream stream;
            stream << "Unknown attribute \"" << name << "\"";
            throw std::invalid_argument(stream.str());
        }
        (yyval.restructval) = rs;
    }
#line 1530 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 265 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        type_ptr type = _type_dict[*(yyvsp[-3].sval)];
        (yyval.restructval) = new restruct(type, (yyvsp[-1].ilistval));
    }
#line 1539 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 269 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        std::vector<unsigned int> empty;
        type_ptr type = _type_dict[*(yyvsp[-2].sval)];
        (yyval.restructval) = new restruct(type, &empty);
    }
#line 1549 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 276 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyval.strval) = new str_type(*(yyvsp[-3].sval), (yyvsp[-1].ilistval));
    }
#line 1557 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 279 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyval.strval) = new str_type(*(yyvsp[-2].sval), new std::list<unsigned int>());
    }
#line 1565 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 284 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyvsp[-2].ilistval)->push_back(std::stoi(*(yyvsp[0].sval)));
        (yyval.ilistval) = (yyvsp[-2].ilistval);
    }
#line 1574 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 288 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        std::list<unsigned int> * lst = new std::list<unsigned int>();
        lst->push_back(std::stoi(*(yyvsp[0].sval)));
        (yyval.ilistval) = lst;
    }
#line 1584 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 295 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyval.vecval) = new Eigen::Vector2d(std::stoi(*(yyvsp[-3].sval)),std::stoi(*(yyvsp[-1].sval)));
    }
#line 1592 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 300 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyvsp[-2].veclistval)->push_back((yyvsp[0].vecval));
        (yyval.veclistval) = (yyvsp[-2].veclistval);
    }
#line 1601 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 304 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        std::list<Eigen::Vector2d *> * lst = new std::list<Eigen::Vector2d *>();
        lst->push_back((yyvsp[0].vecval));
        (yyval.veclistval) = lst;
    }
#line 1611 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 311 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyvsp[0].attrlistval)->push_back((yyvsp[-2].attrval));
        (yyval.attrlistval) = (yyvsp[0].attrlistval);
    }
#line 1620 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 315 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        attrlist * lst = new attrlist();
        lst->push_back((yyvsp[0].attrval));
        (yyval.attrlistval) = lst;
    }
#line 1630 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 323 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyval.attrval) = new attribute_t(*(yyvsp[-2].sval), (yyvsp[0].exprval));
    }
#line 1638 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 328 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyval.exprval) = new grammar::AddAttributeExpr((yyvsp[-2].exprval),(yyvsp[0].exprval));
    }
#line 1646 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 331 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyval.exprval) = (yyvsp[0].exprval);
    }
#line 1654 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 336 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyval.exprval) = new grammar::MultAttributeExpr((yyvsp[-2].exprval),(yyvsp[0].exprval));
    }
#line 1662 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 339 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyval.exprval) = (yyvsp[0].exprval);
    }
#line 1670 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 344 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyval.exprval) = new grammar::ConstantAttributeExpr(std::stod(*(yyvsp[0].sval)));
    }
#line 1678 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 347 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyval.exprval) = new grammar::InheritedXAttributeExpr();
    }
#line 1686 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 350 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyval.exprval) = new grammar::InheritedYAttributeExpr();
    }
#line 1694 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 353 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyval.exprval) = new grammar::InheritedRotationAttributeExpr();
    }
#line 1702 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 356 "../../src/Gui/Grammars/parser.y" /* yacc.c:1646  */
    {
        (yyval.exprval) = (yyvsp[-1].exprval);
    }
#line 1710 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
    break;


#line 1714 "../../src/Gui/Grammars/parser.y.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 361 "../../src/Gui/Grammars/parser.y" /* yacc.c:1906  */


void parse_grammar(QString string, grammar::Grammar * grammar)
{
    _grammar = grammar;
    YY_BUFFER_STATE buffstate = yy_scan_string(string.toStdString().c_str());
    yyparse();
    yy_delete_buffer(buffstate);
    if( !_grammar->getAxiom() )
        throw initialization_error("No axiom specified");
}

void add_production(str_type *initial, int newnodes,
                    std::list<prod_type *> *prod_list,
                    grammar::Grammar * grammar)
{
    type_ptr head = _type_dict[initial->first];
    unsigned int nodeCount = initial->second->size() + newnodes;
    std::vector<int> _map(nodeCount, -1);
    auto iterator = initial->second->begin();
    for(unsigned int index = 0; index < initial->second->size(); index++)
    {
        _map[*iterator] = index;
        iterator++;
    }
    for(prod_type * prod : *prod_list)
    {
        prod_ptr newprod =
                std::make_shared<grammar::Production>(head, newnodes);
        unsigned int map_index = initial->second->size();
        std::vector<int> map(_map);
        for(restruct * structure : *prod)
        {
            for(unsigned int index = 0;
                index < structure->size();
                index++)
            {
                unsigned int value = (*structure)[index];
                if( !(value < nodeCount) )
                {
                    std::ostringstream stream;
                    stream << value << " out of range";
                    throw std::invalid_argument(stream.str());
                }
                if( map[value] == -1 )
                    map[value] = map_index++;
                (*structure)[index] = map[value];
            }
            restruct_ptr body = std::shared_ptr<restruct>(structure);
            newprod->addBodyStructure(body);
        }
        grammar->addProduction(newprod);
    }
}

void yyerror(const char * s)
{
    std::ostringstream sstream;
    sstream << line_number << ": " << s << " on token \"" << yytext << "\""
            << std::endl;
    throw std::invalid_argument(sstream.str());
}
