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




/* Copy the first part of user declarations.  */
#line 1 "turtle.y" /* yacc.c:339  */

	/* File/Module name: (turtle.y)
   * Author: <Yunen He>, u<5251400> and <Geyang Huang> , u<5421856>
	 * Date: <23 Oct 2015>
	 * Description:
	 */
	
	#include <stdio.h>
	#include "symtab.h"
	#include "codegen.h"
	
	void yyerror(const char *s);
	  
	/* TABLE FOR UNRESOLVED FUNCTION CALLS
	 * It is legal to call a function before defining it. 
	 * Keeping unresolved functions, we can backpatch their addresses.
	 */
	
	typedef struct {
		// function name
		char *ident;
		// the number of parameters
		char num_param;
		// a location where the function is defined
	  unsigned short jump_to;
		int line;
	} unresolved_func_call;
	
	int unresolved_func_call_index = 0;
  unresolved_func_call unresolved_func_call_table[1000];
	
	/* prototypes */
	// generate PDPlot-2 code to call a function
	// return 1 on successfully emitting code or keeping an unresovled function call
	// return 0 on mismatch between the number of parameters in the definition of a function and the number of arguments in a call
	int call_func(char *ident, int num_args);	
	
	/* the scope of global variables is NULL */
	sym_func *scope = NULL;
	

#line 108 "turtle.tab.c" /* yacc.c:339  */

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
   by #include "turtle.tab.h".  */
#ifndef YY_YY_TURTLE_TAB_H_INCLUDED
# define YY_YY_TURTLE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 45 "turtle.y" /* yacc.c:355  */

    #include "symtab.h"
    typedef unsigned short address;

#line 143 "turtle.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENT = 258,
    NUM = 259,
    TURTLE = 260,
    UP = 261,
    DOWN = 262,
    MOVETO = 263,
    VAR = 264,
    ASSIGN = 265,
    READ = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    RETURN = 270,
    FUNC = 271,
    LE = 272,
    EQ = 273,
    IFX = 274,
    UMINUS = 275
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 50 "turtle.y" /* yacc.c:355  */

	char *ident;
	int ival;
	sym_func *func;
	address address;

#line 183 "turtle.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_TURTLE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 212 "turtle.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   104

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

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
      24,    25,    22,    20,    26,    21,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,    93,   121,   127,   128,   131,   145,   146,
     153,   154,   157,   157,   168,   186,   193,   196,   201,   205,
     206,   209,   210,   213,   214,   215,   216,   230,   244,   248,
     254,   259,   273,   273,   278,   281,   290,   301,   303,   306,
     321,   337,   336,   343,   346,   349,   352,   355,   358,   359,
     362,   363
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "NUM", "TURTLE", "UP", "DOWN",
  "MOVETO", "VAR", "ASSIGN", "READ", "IF", "ELSE", "WHILE", "RETURN",
  "FUNC", "LE", "EQ", "IFX", "'+'", "'-'", "'*'", "UMINUS", "'('", "')'",
  "','", "'{'", "'}'", "$accept", "program", "$@1", "global_variables",
  "var_declarations", "decl", "initialization", "funcs", "func", "$@2",
  "func_ident", "parameters", "parameter_list", "block", "stmts", "stmt",
  "$@3", "comp", "elsepart", "whilepart", "expr", "$@4", "actuals",
  "actual_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      43,    45,    42,   275,    40,    41,    44,   123,   125
};
# endif

#define YYPACT_NINF -65

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-65)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,     1,    15,     8,   -65,    13,     6,   -65,     8,    25,
      20,   -65,     6,    19,   -65,    27,   -65,   -65,    -2,   -65,
      36,    21,   -65,    27,    27,    65,    -1,   -65,    23,    22,
     -65,   -65,    45,    27,    27,    27,    42,   -65,   -65,    51,
      58,    64,   -65,    27,   -65,   -65,    41,    26,    66,    80,
     -65,   -65,    27,   -65,    67,    67,   -65,    27,    68,    27,
      88,    27,    65,   -65,   -65,    27,    23,     8,    34,    69,
      65,    27,    37,    70,    71,    56,    72,   -65,    -2,    27,
     -65,   -65,    73,    27,   -65,    26,    27,    27,    26,   -65,
      34,   -65,    59,    86,    65,    65,   -65,   -65,   -65,   -65,
      26,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     6,     1,     0,    11,     4,     6,     9,
       0,     2,    11,     0,     5,     0,     7,    14,     0,    10,
      16,    40,    39,     0,     0,     8,     0,     3,    18,     0,
      41,    43,     0,     0,     0,     0,    32,    23,    24,     0,
       0,     0,    38,     0,    20,    34,     0,    22,     0,     0,
      15,    12,    49,    47,    44,    45,    46,     0,     0,     0,
       0,     0,    31,    19,    21,     0,    18,     6,    51,     0,
      27,    49,     0,     0,     0,     0,     0,    17,     0,     0,
      48,    42,     0,     0,    26,     0,     0,     0,     0,    13,
      51,    33,     0,    28,    36,    35,    30,    50,    25,    37,
       0,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -65,   -65,    -5,   -65,   -65,    81,   -65,   -65,
     -65,   -65,    35,   -17,    53,   -64,   -65,    38,   -65,   -65,
     -15,   -65,    31,    14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    18,     6,     7,     8,    16,    11,    12,    67,
      13,    29,    50,    45,    46,    47,    58,    74,   100,    48,
      68,    52,    69,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,    27,    36,    14,     3,    37,    38,    39,    31,    32,
      40,    41,     1,    42,    43,     4,     9,     5,    54,    55,
      56,    93,    10,    17,    96,    26,    26,    44,    62,    36,
      21,    22,    37,    38,    39,    15,   101,    40,    41,    28,
      42,    43,    70,    20,    72,    30,    75,    51,    23,    49,
      75,    24,    57,    26,    33,    34,    35,    33,    34,    35,
      79,    89,    78,    83,    90,    33,    34,    35,    92,    63,
      53,    94,    95,    86,    87,    59,    33,    34,    35,    33,
      34,    35,    60,    66,    98,    33,    34,    35,    61,    35,
      65,    73,    71,    19,    81,    84,    85,    88,    91,    99,
      64,    77,    82,    76,    97
};

static const yytype_uint8 yycheck[] =
{
      15,    18,     3,     8,     3,     6,     7,     8,    23,    24,
      11,    12,     5,    14,    15,     0,     3,     9,    33,    34,
      35,    85,    16,     3,    88,    27,    27,    28,    43,     3,
       3,     4,     6,     7,     8,    10,   100,    11,    12,     3,
      14,    15,    57,    24,    59,    24,    61,    25,    21,    26,
      65,    24,    10,    27,    20,    21,    22,    20,    21,    22,
      26,    78,    67,    26,    79,    20,    21,    22,    83,    28,
      25,    86,    87,    17,    18,    24,    20,    21,    22,    20,
      21,    22,    24,     3,    25,    20,    21,    22,    24,    22,
      24,     3,    24,    12,    25,    25,    25,    25,    25,    13,
      47,    66,    71,    65,    90
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    30,     3,     0,     9,    32,    33,    34,     3,
      16,    36,    37,    39,    33,    10,    35,     3,    31,    36,
      24,     3,     4,    21,    24,    49,    27,    42,     3,    40,
      24,    49,    49,    20,    21,    22,     3,     6,     7,     8,
      11,    12,    14,    15,    28,    42,    43,    44,    48,    26,
      41,    25,    50,    25,    49,    49,    49,    10,    45,    24,
      24,    24,    49,    28,    43,    24,     3,    38,    49,    51,
      49,    24,    49,     3,    46,    49,    46,    41,    33,    26,
      52,    25,    51,    26,    25,    25,    17,    18,    25,    42,
      49,    25,    49,    44,    49,    49,    44,    52,    25,    13,
      47,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    31,    30,    32,    33,    33,    34,    35,    35,
      36,    36,    38,    37,    39,    40,    40,    41,    41,    42,
      42,    43,    43,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    45,    44,    44,    46,    46,    47,    48,    49,
      49,    50,    49,    49,    49,    49,    49,    49,    51,    51,
      52,    52
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     1,     2,     0,     3,     2,     0,
       2,     0,     0,     7,     2,     2,     0,     3,     0,     3,
       2,     2,     1,     1,     1,     6,     4,     3,     5,     7,
       5,     2,     0,     5,     1,     3,     3,     1,     1,     1,
       1,     0,     5,     2,     3,     3,     3,     3,     2,     0,
       3,     0
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 93 "turtle.y" /* yacc.c:1661  */
    {
		// After parsing function declarations, turtle compiler knows their location. 
		// Therefore, the compiler could jump over function declarations from global variables.
		backpatch((yyvsp[-1].address), get_address());
	}
#line 1455 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 98 "turtle.y" /* yacc.c:1661  */
    {
    emit(OPR_HALT);
		 
		int i;
    for(i = 0; i < unresolved_func_call_index; i++) {
			unresolved_func_call call = unresolved_func_call_table[i];
			sym_func *f = get_func(call.ident);			
			if(f == NULL) {
			  printf("undefined function : %s, line %d \n", call.ident, call.line);
				YYERROR;
			} else if((*f).num_param != call.num_param) {
	      printf("%d parameter(s) defined in the function %s, %d argument(s) in this call, line %d \n", call.num_param, call.ident, call.num_param, call.line);
        YYERROR;
			}
			else {
				backpatch(call.jump_to, (*f).address);
			}
    }
		
	}
#line 1480 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 121 "turtle.y" /* yacc.c:1661  */
    {
		// jump to block (compound statements)
		(yyval.address) = emit_two(OPR_JUMP, 0);
	}
#line 1489 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 131 "turtle.y" /* yacc.c:1661  */
    {
		// create a new variable within the scope
		signed char address = get_var_address(scope);
		sym_var *var = add_var((yyvsp[-1].ident), scope, address);
		
		if (var == NULL) {
			char error_msg[100];
		  sprintf(error_msg, "The variable %s is declared twice in the same scope.", (yyvsp[-1].ident));
		  yyerror(error_msg);
      YYERROR;
		}
	}
#line 1506 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 146 "turtle.y" /* yacc.c:1661  */
    {
									 // push a value onto the top of the stack
									 emit_two(OPR_LOADI, 0);
								 }
#line 1515 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 157 "turtle.y" /* yacc.c:1661  */
    {
		// keep the number of parameters for the symbol table
		(*(yyvsp[-3].func)).num_param = (yyvsp[-1].ival);
	}
#line 1524 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 161 "turtle.y" /* yacc.c:1661  */
    {
		// reset the scope once parsing the current function is complete.
		scope = NULL;
		emit(OPR_RTS);
	}
#line 1534 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 168 "turtle.y" /* yacc.c:1661  */
    {
		// add a new function
		sym_func *f = add_func((yyvsp[0].ident), get_address());
		
		if (!f) {
			char error_msg[100];
		  sprintf(error_msg, "The function %s is declared twice in the same scope.", (yyvsp[0].ident));
		  yyerror(error_msg);
      YYERROR;
		}
		
		// update the scope
		scope = f;
		// flow up to keep the number of parameters
		(yyval.func) = f;
	}
#line 1555 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 186 "turtle.y" /* yacc.c:1661  */
    {
		// The formal parameters are also referenced relative to the FP.
		// Notice that the first parameter is (–n–1) away from FP and the last is at -2(FP).
		signed char address = -2 - (yyvsp[0].ival);
		add_var((yyvsp[-1].ident), scope, address);
		(yyval.ival) = (yyvsp[0].ival) + 1;
	}
#line 1567 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 193 "turtle.y" /* yacc.c:1661  */
    { (yyval.ival) = 0; }
#line 1573 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 196 "turtle.y" /* yacc.c:1661  */
    {
		signed char address = -2 - (yyvsp[0].ival);
		add_var((yyvsp[-1].ident), scope, address);
		(yyval.ival) = (yyvsp[0].ival) + 1;
	}
#line 1583 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 201 "turtle.y" /* yacc.c:1661  */
    { (yyval.ival) = 0; }
#line 1589 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 213 "turtle.y" /* yacc.c:1661  */
    { emit(OPR_UP); }
#line 1595 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 214 "turtle.y" /* yacc.c:1661  */
    { emit(OPR_DOWN); }
#line 1601 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 215 "turtle.y" /* yacc.c:1661  */
    { emit(OPR_MOVE); }
#line 1607 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 216 "turtle.y" /* yacc.c:1661  */
    {
				 
				 sym_var *var = get_var((yyvsp[-1].ident), scope);
				 
		 		if (var == NULL) {
					char error_msg[100];
				  sprintf(error_msg, "undeclared variable : %s", (yyvsp[-1].ident));
				  yyerror(error_msg);
					YYERROR;
		 		}
				
				 emit_offset(OPR_READ, (*var).scope != NULL ? 1 : 0, (*var).address);
				 
			 }
#line 1626 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 230 "turtle.y" /* yacc.c:1661  */
    {
				 sym_var *var = get_var((yyvsp[-2].ident), scope);
				 
				 if (var == NULL) {
 					char error_msg[100];
				  sprintf(error_msg, "undeclared variable : %s", (yyvsp[-2].ident));
 				  yyerror(error_msg);
 					YYERROR;
				 }
				 else {
					 emit_offset(OPR_STORE, (*var).scope != NULL ? 1 : 0, (*var).address);				 
				 }
				 
			 }
#line 1645 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 244 "turtle.y" /* yacc.c:1661  */
    {
				 // hop over the stmt
				 backpatch((yyvsp[-2].address), get_address());
			 }
#line 1654 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 248 "turtle.y" /* yacc.c:1661  */
    {
				 // hop over the second stmt
				 backpatch((yyvsp[-1].address), get_address());
				 // jump to the first stmt
				 backpatch((yyvsp[-4].address), (yyvsp[-1].address)+2);
			 }
#line 1665 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 254 "turtle.y" /* yacc.c:1661  */
    {
				 // build a loop and keep watching the condition
				 emit_two(OPR_JUMP, (yyvsp[-4].address));
				 backpatch((yyvsp[-2].address), get_address());
			 }
#line 1675 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 259 "turtle.y" /* yacc.c:1661  */
    {
				 // Error
				 if (scope == NULL) {
					 char error_msg[100];
				   sprintf(error_msg, "A return statement is in the main program.");
				   yyerror(error_msg);
           YYERROR;
				 }
				 else {
					 // Notice that the first parameter is (–n–1) away from FP and the last is at -2(FP).
					 emit_offset(OPR_STORE, 1, -2 - (*scope).num_param);
					 emit(OPR_RTS);
				 }
			 }
#line 1694 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 273 "turtle.y" /* yacc.c:1661  */
    {
				 emit_two(OPR_LOADI, 0);
			 }
#line 1702 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 275 "turtle.y" /* yacc.c:1661  */
    {				 
         if(call_func((yyvsp[-4].ident), (yyvsp[-1].ival)) == 0) { YYERROR; } 
			 }
#line 1710 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 281 "turtle.y" /* yacc.c:1661  */
    {
		emit(OPR_SUB);
		emit(OPR_TEST);
		emit_two(OPR_POP, 1);
		// hop over the escape Jump
		emit_two(OPR_JEQ, get_address() + 4);
		// jump over <code for body>
		(yyval.address) = emit_two(OPR_JUMP, 0);
	}
#line 1724 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 290 "turtle.y" /* yacc.c:1661  */
    {
				emit(OPR_SUB);
				emit(OPR_TEST);
				emit_two(OPR_POP, 1);
				// hop over the escape Jump
				emit_two(OPR_JLT, get_address() + 4);
				// jump over <code for body>
				(yyval.address) = emit_two(OPR_JUMP, 0);
			}
#line 1738 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 301 "turtle.y" /* yacc.c:1661  */
    { (yyval.address) = emit_two(OPR_JUMP, 0); }
#line 1744 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 303 "turtle.y" /* yacc.c:1661  */
    { (yyval.address) = get_address(); }
#line 1750 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 306 "turtle.y" /* yacc.c:1661  */
    {

		unsigned short val = (yyvsp[0].ival);
		
		if (val >= 0 && val <= 32767) {
			emit_two(OPR_LOADI, val);
		}
		else {
      char error_msg[100];
      sprintf(error_msg, "out of range error: %d", val);
      yyerror(error_msg);
      YYERROR;
		}
		
	}
#line 1770 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 321 "turtle.y" /* yacc.c:1661  */
    {
				 
				 sym_var *var = get_var((yyvsp[0].ident), scope);
				 
				 if (var == NULL) {
  					char error_msg[100];
					  sprintf(error_msg, "undeclared variable : %s", (yyvsp[0].ident));
  				  yyerror(error_msg);
  					YYERROR;
				 }
				 else {
					 emit_offset(OPR_LOAD, (*var).scope != NULL ? 1 : 0, (*var).address);
				 }
				 
			 }
#line 1790 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 337 "turtle.y" /* yacc.c:1661  */
    {					 					 
					 emit_two(OPR_LOADI, 0);
	       }
#line 1798 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 340 "turtle.y" /* yacc.c:1661  */
    {
	          if(call_func((yyvsp[-4].ident), (yyvsp[-1].ival)) == 0) { YYERROR; } 
	        }
#line 1806 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 343 "turtle.y" /* yacc.c:1661  */
    {
				 emit(OPR_NEG);
			 }
#line 1814 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 346 "turtle.y" /* yacc.c:1661  */
    {
				 emit(OPR_ADD);
			 }
#line 1822 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 349 "turtle.y" /* yacc.c:1661  */
    {
				 emit(OPR_SUB);
			 }
#line 1830 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 352 "turtle.y" /* yacc.c:1661  */
    {
				 emit(OPR_MUL);
			 }
#line 1838 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 358 "turtle.y" /* yacc.c:1661  */
    {(yyval.ival) = (yyvsp[0].ival) + 1;}
#line 1844 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 359 "turtle.y" /* yacc.c:1661  */
    {(yyval.ival) = 0;}
#line 1850 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 362 "turtle.y" /* yacc.c:1661  */
    {(yyval.ival) = (yyvsp[0].ival) + 1;}
#line 1856 "turtle.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 363 "turtle.y" /* yacc.c:1661  */
    {(yyval.ival) = 0;}
#line 1862 "turtle.tab.c" /* yacc.c:1661  */
    break;


#line 1866 "turtle.tab.c" /* yacc.c:1661  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 365 "turtle.y" /* yacc.c:1906  */


void yyerror(const char *s) {
	printf("%s line: %d \n", s, yylloc.first_line);
}

int call_func(char *name, int num_args) {
	
	sym_func *f = get_func(name);
	
	if (f) {
		if ((*f).num_param == num_args) {
			emit_two(OPR_JSR, (*f).address);
			emit_two(OPR_POP, (*f).num_param);
			return 1;
		}
		else {
			char error_msg[100];
      sprintf(error_msg, "%d parameter(s) defined in the function %s, %d argument(s) in this call", (*f).num_param, name, num_args);
		  yyerror(error_msg);
		}
	}
	else {
		// keep an unresovled function call
		
    unresolved_func_call func_call;
		
    func_call.num_param = num_args;
    func_call.ident = name;
    func_call.line = yylloc.first_line;
    func_call.jump_to = emit_two(OPR_JSR, 0);
    emit_two(OPR_POP, num_args);

    unresolved_func_call_table[unresolved_func_call_index] = func_call;
    unresolved_func_call_index = unresolved_func_call_index + 1;
		
		return 1;
	}
	return 0;
}