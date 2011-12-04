
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "vb_lark.y"
	
	#include "tree_nodes.h"
	#include <stdio.h>
	#include "dot.h"
	#include "stdafx.h"
	
	extern int yylex(void);
	
	struct VB_Module_stmt* root;


/* Line 189 of yacc.c  */
#line 84 "vb_lark.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOLEAN_CONST = 258,
     INT_CONST = 259,
     STRING_CONST = 260,
     CHAR_CONST = 261,
     ID = 262,
     ENDL = 263,
     DIM = 264,
     AS = 265,
     IF = 266,
     THEN = 267,
     ELSE = 268,
     ELSEIF = 269,
     END_IF = 270,
     FUNCTION = 271,
     BYVAL = 272,
     RETURN = 273,
     END_FUNCTION = 274,
     SUB = 275,
     END_SUB = 276,
     TRY = 277,
     CATCH = 278,
     END_TRY = 279,
     THROW = 280,
     NEW = 281,
     CASE = 282,
     CONST = 283,
     SELECT = 284,
     WHILE = 285,
     UNTIL = 286,
     MODULE = 287,
     DO = 288,
     ENUM = 289,
     END_ENUM = 290,
     END_MODULE = 291,
     END_SELECT = 292,
     END_WHILE = 293,
     LOOP = 294,
     FOR_EACH = 295,
     FOR = 296,
     TO = 297,
     NEXT = 298,
     IN = 299,
     MOD = 300,
     STEP = 301,
     EXCEPTION = 302,
     INTEGER = 303,
     CHAR = 304,
     STRING = 305,
     BOOLEAN = 306,
     CONSOLE = 307,
     WRITE = 308,
     WRITELINE = 309,
     READ = 310,
     READLINE = 311,
     SYSTEM = 312,
     FINALLY = 313,
     EQUAL = 314,
     NONEQUAL = 315,
     LESS_OR_EQUAL = 316,
     MORE_OR_EQUAL = 317,
     UMINUS = 318
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 14 "vb_lark.y"

	bool	b_const;
	int		i_const;
	char	c_const;
	char*	s_const;
	
	char* 	Id;
	
	struct VB_Module_stmt*		Module;
	struct VB_Stmt_list*		List;
	struct VB_Stmt*				Stmt;
	struct VB_Expr*				Expr;
	struct VB_Expr_list*		Expr_l;
	struct VB_If_stmt*			If_stmt;
	struct VB_End_if_stmt*		End_if;
	struct VB_Dim_stmt*			Dim;
	struct VB_As_expr_list*		As_l;
    struct VB_As_expr*			As_expr_str;
	struct VB_Id_list_stmt*		Id_l;
	struct VB_Array_expr*		Arr;
	struct VB_For_stmt*			For;
	struct VB_While_stmt*		While;
	struct VB_Do_loop_stmt*		Do_loop;
	struct VB_Enum_stmt*		Enum;
	struct VB_Enum_expr_list*	Enum_l;
	struct VB_Enum_expr*		Enum_e;
	struct VB_Sub_stmt*			Sub;
	struct VB_Param_list*		Param_l;
	struct VB_Param_stmt*		Param;
	struct VB_Func_stmt*		Func;
	struct VB_Try_catch_stmt*	Try_catch;
	struct VB_Catch_stmt_list*	Catch_l;
	struct VB_Catch_stmt*		Catch;
	struct VB_Throw_stmt*		Throw;
	
	enum VB_Id_type				Id_type;

	struct VB_Console_print_stmt*	console_print;
	struct VB_Console_println_stmt*	console_println;
	struct VB_Console_read_stmt*	console_read;
	struct VB_Console_readln_stmt*	console_readln;



/* Line 214 of yacc.c  */
#line 228 "vb_lark.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 240 "vb_lark.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1909

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNRULES -- Number of states.  */
#define YYNSTATES  383

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      74,    73,    68,    66,    76,    67,    77,    69,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    75,     2,
      61,    59,    60,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    70,     2,    71,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    62,    63,    64,    65,    72
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    12,    15,    18,    20,    22,    24,
      26,    28,    30,    32,    34,    36,    38,    40,    42,    44,
      46,    48,    53,    55,    57,    59,    61,    65,    69,    73,
      77,    81,    85,    89,    93,    97,   101,   105,   109,   113,
     117,   120,   127,   133,   140,   149,   151,   155,   158,   164,
     171,   177,   181,   183,   185,   189,   193,   197,   201,   205,
     209,   215,   221,   227,   233,   235,   239,   246,   253,   260,
     267,   269,   273,   284,   297,   310,   323,   336,   351,   366,
     381,   388,   396,   404,   412,   420,   427,   430,   434,   436,
     440,   449,   459,   461,   465,   470,   475,   480,   485,   499,
     513,   527,   541,   556,   571,   586,   601,   612,   614,   617,
     624,   634,   642,   650,   657
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      79,     0,    -1,    32,     7,     8,    80,    36,     8,    -1,
      81,    -1,    80,    81,    -1,    82,     8,    -1,    83,    -1,
      86,    -1,    92,    -1,    93,    -1,    94,    -1,    95,    -1,
      98,    -1,   101,    -1,   102,    -1,   105,    -1,   106,    -1,
     107,    -1,   108,    -1,   109,    -1,     7,    -1,     7,    74,
      91,    73,    -1,     4,    -1,     6,    -1,     5,    -1,     3,
      -1,    82,    59,    82,    -1,    82,    66,    82,    -1,    82,
      67,    82,    -1,    82,    68,    82,    -1,    82,    69,    82,
      -1,    82,    70,    82,    -1,    82,    71,    82,    -1,    82,
      60,    82,    -1,    82,    61,    82,    -1,    82,    65,    82,
      -1,    82,    64,    82,    -1,    82,    63,    82,    -1,    82,
      62,    82,    -1,    74,    82,    73,    -1,    67,    82,    -1,
      11,    82,    12,     8,    80,    85,    -1,    11,    82,     8,
      80,    85,    -1,    11,    82,    12,    84,    15,     8,    -1,
      11,    82,    12,    84,    13,    84,    15,     8,    -1,    81,
      -1,    84,    75,    81,    -1,    15,     8,    -1,    13,     8,
      80,    15,     8,    -1,    14,    82,    12,     8,    80,    85,
      -1,    14,    82,     8,    80,    85,    -1,     9,    87,     8,
      -1,    88,    -1,    90,    -1,    87,    76,    88,    -1,    87,
      76,    90,    -1,    89,    10,    48,    -1,    89,    10,    51,
      -1,    89,    10,    49,    -1,    89,    10,    50,    -1,    89,
      10,    48,    59,    82,    -1,    89,    10,    51,    59,    82,
      -1,    89,    10,    49,    59,    82,    -1,    89,    10,    50,
      59,    82,    -1,     7,    -1,    89,    76,     7,    -1,     7,
      74,     4,    73,    10,    48,    -1,     7,    74,     4,    73,
      10,    51,    -1,     7,    74,     4,    73,    10,    49,    -1,
       7,    74,     4,    73,    10,    50,    -1,    82,    -1,    91,
      76,    82,    -1,    41,     7,    59,     4,    42,     4,     8,
      80,    43,     8,    -1,    41,     7,    59,     4,    42,     4,
      46,     4,     8,    80,    43,     8,    -1,    41,     7,    10,
      48,    59,     4,    42,     4,     8,    80,    43,     8,    -1,
      41,     7,    10,    51,    59,     4,    42,     4,     8,    80,
      43,     8,    -1,    41,     7,    10,    49,    59,     4,    42,
       4,     8,    80,    43,     8,    -1,    41,     7,    10,    48,
      59,     4,    42,     4,    46,     4,     8,    80,    43,     8,
      -1,    41,     7,    10,    51,    59,     4,    42,     4,    46,
       4,     8,    80,    43,     8,    -1,    41,     7,    10,    49,
      59,     4,    42,     4,    46,     4,     8,    80,    43,     8,
      -1,    30,    82,     8,    80,    38,     8,    -1,    33,    30,
      82,     8,    80,    39,     8,    -1,    33,    31,    82,     8,
      80,    39,     8,    -1,    33,     8,    80,    39,    30,    82,
       8,    -1,    33,     8,    80,    39,    31,    82,     8,    -1,
      34,     7,     8,    96,    35,     8,    -1,    97,     8,    -1,
      96,    97,     8,    -1,     7,    -1,     7,    59,     4,    -1,
      20,     7,    74,    73,     8,    80,    21,     8,    -1,    20,
       7,    74,    99,    73,     8,    80,    21,     8,    -1,   100,
      -1,    99,    76,   100,    -1,    17,     7,    10,    48,    -1,
      17,     7,    10,    51,    -1,    17,     7,    10,    49,    -1,
      17,     7,    10,    50,    -1,    16,     7,    74,    73,    10,
      48,     8,    80,    18,    82,     8,    19,     8,    -1,    16,
       7,    74,    73,    10,    51,     8,    80,    18,    82,     8,
      19,     8,    -1,    16,     7,    74,    73,    10,    49,     8,
      80,    18,    82,     8,    19,     8,    -1,    16,     7,    74,
      73,    10,    50,     8,    80,    18,    82,     8,    19,     8,
      -1,    16,     7,    74,    99,    73,    10,    48,     8,    80,
      18,    82,     8,    19,     8,    -1,    16,     7,    74,    99,
      73,    10,    51,     8,    80,    18,    82,     8,    19,     8,
      -1,    16,     7,    74,    99,    73,    10,    49,     8,    80,
      18,    82,     8,    19,     8,    -1,    16,     7,    74,    99,
      73,    10,    50,     8,    80,    18,    82,     8,    19,     8,
      -1,    22,     8,    80,   103,    58,     8,    80,     8,    24,
       8,    -1,   104,    -1,   103,   104,    -1,    23,     7,    10,
      47,     8,    80,    -1,    25,    26,    57,    77,    47,    74,
       5,    73,     8,    -1,    52,    77,    53,    74,     5,    73,
       8,    -1,    52,    77,    54,    74,     5,    73,     8,    -1,
      52,    77,    55,    74,    73,     8,    -1,    52,    77,    56,
      74,    73,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   159,   159,   162,   163,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   206,   207,   208,   209,   212,   213,   216,   217,   218,
     219,   222,   225,   226,   227,   228,   231,   232,   233,   234,
     235,   236,   237,   238,   241,   242,   245,   246,   247,   248,
     251,   252,   255,   256,   257,   258,   259,   260,   261,   262,
     265,   268,   269,   270,   271,   274,   277,   278,   281,   282,
     285,   286,   289,   290,   293,   294,   295,   296,   299,   300,
     301,   302,   303,   304,   305,   306,   309,   312,   313,   316,
     319,   322,   325,   328,   331
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOLEAN_CONST", "INT_CONST",
  "STRING_CONST", "CHAR_CONST", "ID", "ENDL", "DIM", "AS", "IF", "THEN",
  "ELSE", "ELSEIF", "END_IF", "FUNCTION", "BYVAL", "RETURN",
  "END_FUNCTION", "SUB", "END_SUB", "TRY", "CATCH", "END_TRY", "THROW",
  "NEW", "CASE", "CONST", "SELECT", "WHILE", "UNTIL", "MODULE", "DO",
  "ENUM", "END_ENUM", "END_MODULE", "END_SELECT", "END_WHILE", "LOOP",
  "FOR_EACH", "FOR", "TO", "NEXT", "IN", "MOD", "STEP", "EXCEPTION",
  "INTEGER", "CHAR", "STRING", "BOOLEAN", "CONSOLE", "WRITE", "WRITELINE",
  "READ", "READLINE", "SYSTEM", "FINALLY", "'='", "'>'", "'<'", "EQUAL",
  "NONEQUAL", "LESS_OR_EQUAL", "MORE_OR_EQUAL", "'+'", "'-'", "'*'", "'/'",
  "'\\\\'", "'^'", "UMINUS", "')'", "'('", "':'", "','", "'.'", "$accept",
  "module_stmt", "stmt_list", "stmt", "expr", "if_stmt",
  "stmt_list_inline", "end_if_stmt", "dim_stmt", "as_expr_list", "as_expr",
  "id_list_stmt", "array_expr", "expr_list", "for_stmt", "while_stmt",
  "do_loop_stmt", "enum_stmt", "enum_expr_list", "enum_expr", "sub_stmt",
  "param_list", "param_stmt", "func_stmt", "try_catch_stmt",
  "catch_stmt_list", "catch_stmt", "throw_stmt", "console_print_stmt",
  "console_println_stmt", "console_read_stmt", "console_readln_stmt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,    61,
      62,    60,   314,   315,   316,   317,    43,    45,    42,    47,
      92,    94,   318,    41,    40,    58,    44,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    83,    83,    83,    83,    84,    84,    85,    85,    85,
      85,    86,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    90,    90,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    94,    94,    94,    94,    95,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   100,   100,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   103,   103,   104,
     105,   106,   107,   108,   109
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     6,     5,     6,     8,     1,     3,     2,     5,     6,
       5,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       5,     5,     5,     5,     1,     3,     6,     6,     6,     6,
       1,     3,    10,    12,    12,    12,    12,    14,    14,    14,
       6,     7,     7,     7,     7,     6,     2,     3,     1,     3,
       8,     9,     1,     3,     4,     4,     4,     4,    13,    13,
      13,    13,    14,    14,    14,    14,    10,     1,     2,     6,
       9,     7,     7,     6,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    25,    22,    24,    23,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    64,     0,    52,     0,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     4,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,     2,    26,    33,    34,    38,    37,    36,    35,
      27,    28,    29,    30,    31,    32,    21,     0,     0,    54,
      55,    56,    58,    59,    57,    65,     0,     0,    45,     0,
       0,     0,     0,    92,     0,     0,     0,     0,   107,     0,
       0,     0,     0,     0,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,     0,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    62,    63,
      61,     0,     0,    47,    41,     0,    43,    46,     0,     0,
       0,     0,     0,     0,    93,     0,     0,     0,     0,     0,
      80,     0,     0,     0,     0,    89,    85,    87,     0,     0,
       0,     0,     0,     0,   113,   114,    66,    68,    69,    67,
       0,     0,     0,     0,    94,    96,    97,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    81,    82,     0,     0,     0,     0,     0,
     111,   112,     0,     0,     0,    44,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,   109,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,   106,     0,     0,     0,
       0,     0,     0,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,     0,
      76,     0,    75,     0,    73,    98,   100,   101,    99,     0,
       0,     0,     0,     0,     0,     0,   102,   104,   105,   103,
      77,    79,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    24,    25,    26,    27,   129,   164,    28,    43,
      44,    45,    46,    78,    29,    30,    31,    32,   145,   146,
      33,   132,   133,    34,    35,   137,   138,    36,    37,    38,
      39,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -165
static const yytype_int16 yypact[] =
{
      13,    51,    53,    55,  -165,  1497,  -165,  -165,  -165,  -165,
      27,    59,    43,    67,    72,   107,   105,    43,    21,   126,
     127,    66,    43,    43,   345,  -165,   161,  -165,  -165,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,
    -165,    43,    76,    -5,  -165,    -8,  -165,   141,    77,    86,
    1497,    95,  1529,  1497,    43,    43,   153,    10,    58,  -165,
    1788,   154,  -165,  -165,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,  1803,   -19,   159,
    -165,    59,    70,   157,  1497,   395,   -13,     5,   434,    88,
    1497,   473,  1542,  1555,   160,   -17,   162,    94,    96,    98,
     100,  -165,  -165,  1803,    37,    37,    37,    37,    37,    37,
      54,    54,   108,   108,   108,  -165,  -165,    43,   109,  -165,
    -165,   112,   122,   124,   125,  -165,     3,  1497,  -165,     0,
     178,   176,    22,  -165,   179,    24,   183,    -2,  -165,   145,
     512,    -4,  1497,  1497,   134,     4,   186,   136,   137,   138,
     171,   209,   210,   144,   163,  1803,   208,    43,    43,    43,
      43,   226,    43,   229,  -165,     3,  1497,   230,  1497,   231,
      78,   232,   222,  1497,   235,   234,   237,  -165,   166,   238,
      43,    43,   551,   590,   244,   242,   243,  -165,   252,   253,
     254,   255,   187,   188,   257,   258,    89,  1803,  1803,  1803,
    1803,  1497,  1516,  -165,  -165,   -10,  -165,  -165,    97,   259,
     261,   262,   263,   106,  -165,   629,  1497,   216,  1497,   268,
    -165,  1619,  1632,   266,   267,  -165,  -165,  -165,   239,   241,
     246,    16,   276,   277,  -165,  -165,  -165,  -165,  -165,  -165,
     668,  1497,   278,   281,  -165,  -165,  -165,  -165,  1497,  1497,
    1497,  1497,   282,   283,   284,   285,   290,   707,   291,   746,
     203,  -165,  -165,  -165,  -165,   296,   297,   298,  1497,   300,
    -165,  -165,   301,     3,  1497,  -165,   785,   824,   863,   902,
    1497,  1497,  1497,  1497,  -165,   303,  1497,   288,   305,    30,
      34,    35,   941,   311,  -165,  -165,     3,    43,    43,    43,
      43,   991,  1030,  1069,  1108,  -165,  1497,   313,  -165,  1497,
     302,  1497,   304,  1497,   318,   315,  1497,  -165,  1645,  1658,
    1722,  1735,    43,    43,    43,    43,  -165,  1147,   316,  1197,
     317,  1247,   322,  -165,  1297,   312,   314,   319,   325,  1748,
    1761,  1825,  1838,   326,  1497,   328,  1497,   337,  1497,   338,
     339,   350,   352,   355,   334,   347,   349,   353,  -165,  1347,
    -165,  1397,  -165,  1447,  -165,  -165,  -165,  -165,  -165,   356,
     361,   363,   365,   366,   368,   369,  -165,  -165,  -165,  -165,
    -165,  -165,  -165
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -165,  -165,    46,   -24,    18,  -165,   214,  -164,  -165,  -165,
     306,  -165,   307,  -165,  -165,  -165,  -165,  -165,  -165,   240,
    -165,   295,   211,  -165,  -165,  -165,   247,  -165,  -165,  -165,
    -165,  -165
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      62,   204,    82,    80,   130,   243,     6,     7,     8,     9,
      10,   144,    11,   166,    12,   167,   161,   162,   163,    13,
      95,   136,   130,    14,   268,    15,   180,   181,    16,    53,
      47,   147,   148,    17,   149,    52,    18,    19,   309,   185,
      59,    60,   311,   313,    20,     1,     6,     7,     8,     9,
      10,    54,    55,     4,   116,    21,   176,   117,     3,    77,
     131,   128,   269,     5,    62,   168,    42,    62,    83,    96,
      22,    81,    92,    93,    48,   168,   310,    23,   134,    49,
     312,   314,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   171,    88,   174,   172,    91,
     172,    41,    62,    71,    72,    73,    74,    75,    76,   295,
      22,    97,    98,    99,   100,    50,    62,    23,   121,   122,
     123,   124,    73,    74,    75,    76,   209,   210,   211,   212,
     126,    51,   317,    56,    57,   155,   140,   236,   237,   238,
     239,    62,   128,    58,   207,   244,   245,   246,   247,    84,
      79,    86,    89,    85,   252,   253,   254,   255,    62,    62,
      87,    94,   102,   118,   125,   139,   150,   144,   151,    63,
     152,   157,   153,   165,   154,   197,   198,   199,   200,    76,
     202,   158,   156,   159,   160,   169,   170,   173,   182,   183,
     175,    62,   178,   184,   187,   188,   189,   190,   221,   222,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,   191,   192,   193,    62,   194,   196,   215,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    62,   201,    62,   195,   203,   206,   130,
     219,   208,   213,   216,   217,   218,   220,   240,   225,    62,
     226,   227,    62,    62,    62,    62,   228,   229,   230,   231,
     232,   233,   257,   258,   259,   234,   235,   248,    62,   249,
     250,   251,    62,   260,   263,   264,   288,    62,    62,    62,
      62,   265,    62,   266,   270,   271,   274,   273,   267,   275,
     280,   281,   282,   283,   276,   277,   278,   279,   284,   286,
     289,   290,   291,    62,   293,    62,   328,    62,   330,   294,
      62,   305,   307,   308,   292,   318,   319,   320,   321,   316,
     296,   326,   332,   333,   344,   346,   301,   302,   303,   304,
     348,   350,   306,   351,   358,    62,   360,    62,   352,    62,
     339,   340,   341,   342,   353,   362,   364,   365,     6,     7,
       8,     9,    10,   369,    11,   327,    12,   329,   366,   331,
     367,    13,   334,   368,   376,    14,   370,    15,   371,   377,
      16,   378,   372,   379,   380,    17,   381,   382,    18,    19,
     205,    61,   135,   214,   177,   186,    20,   119,   120,     0,
     359,     0,   361,     0,   363,     0,     0,    21,     6,     7,
       8,     9,    10,   127,    11,     0,    12,     0,     0,     0,
       0,    13,    22,     0,     0,    14,     0,    15,     0,    23,
      16,     0,     0,     0,     0,    17,     0,     0,    18,    19,
       0,     0,     0,     0,     0,     0,    20,     6,     7,     8,
       9,    10,     0,    11,     0,    12,     0,    21,     0,     0,
      13,     0,     0,     0,    14,     0,    15,   136,     0,    16,
       0,     0,    22,     0,    17,     0,     0,    18,    19,    23,
       0,     0,     0,     0,     0,    20,     6,     7,     8,     9,
      10,     0,    11,     0,    12,     0,    21,     0,     0,    13,
       0,     0,     0,    14,     0,    15,     0,     0,    16,     0,
       0,    22,     0,    17,     0,     0,    18,    19,    23,     0,
       0,     0,   141,     0,    20,     6,     7,     8,     9,    10,
       0,    11,     0,    12,     0,    21,     0,     0,    13,     0,
       0,     0,    14,     0,    15,     0,     0,    16,     0,     0,
      22,     0,    17,     0,     0,    18,    19,    23,     0,     0,
     179,     0,     0,    20,     6,     7,     8,     9,    10,     0,
      11,     0,    12,     0,    21,     0,     0,    13,     0,     0,
       0,    14,     0,    15,     0,     0,    16,     0,     0,    22,
       0,    17,     0,     0,    18,    19,    23,     0,     0,     0,
     223,     0,    20,     6,     7,     8,     9,    10,     0,    11,
       0,    12,     0,    21,     0,     0,    13,     0,     0,     0,
      14,     0,    15,     0,     0,    16,     0,     0,    22,     0,
      17,     0,     0,    18,    19,    23,     0,     0,     0,   224,
       0,    20,     6,     7,     8,     9,    10,     0,    11,     0,
      12,     0,    21,     0,     0,    13,     0,     0,     0,    14,
     256,    15,     0,     0,    16,     0,     0,    22,     0,    17,
       0,     0,    18,    19,    23,     0,     0,     0,     0,     0,
      20,     6,     7,     8,     9,    10,     0,    11,     0,    12,
       0,    21,     0,   272,    13,     0,     0,     0,    14,     0,
      15,     0,     0,    16,     0,     0,    22,     0,    17,     0,
       0,    18,    19,    23,     0,     0,     0,     0,     0,    20,
       6,     7,     8,     9,    10,     0,    11,     0,    12,     0,
      21,     0,     0,    13,     0,     0,     0,    14,   285,    15,
       0,     0,    16,     0,     0,    22,     0,    17,     0,     0,
      18,    19,    23,     0,     0,     0,     0,     0,    20,     6,
       7,     8,     9,    10,   287,    11,     0,    12,     0,    21,
       0,     0,    13,     0,     0,     0,    14,     0,    15,     0,
       0,    16,     0,     0,    22,     0,    17,     0,     0,    18,
      19,    23,     0,     0,     0,     0,     0,    20,     6,     7,
       8,     9,    10,     0,    11,     0,    12,     0,    21,     0,
       0,    13,     0,   297,     0,    14,     0,    15,     0,     0,
      16,     0,     0,    22,     0,    17,     0,     0,    18,    19,
      23,     0,     0,     0,     0,     0,    20,     6,     7,     8,
       9,    10,     0,    11,     0,    12,     0,    21,     0,     0,
      13,     0,   298,     0,    14,     0,    15,     0,     0,    16,
       0,     0,    22,     0,    17,     0,     0,    18,    19,    23,
       0,     0,     0,     0,     0,    20,     6,     7,     8,     9,
      10,     0,    11,     0,    12,     0,    21,     0,     0,    13,
       0,   299,     0,    14,     0,    15,     0,     0,    16,     0,
       0,    22,     0,    17,     0,     0,    18,    19,    23,     0,
       0,     0,     0,     0,    20,     6,     7,     8,     9,    10,
       0,    11,     0,    12,     0,    21,     0,     0,    13,     0,
     300,     0,    14,     0,    15,     0,     0,    16,     0,     0,
      22,     0,    17,     0,     0,    18,    19,    23,     0,     0,
       0,     0,     0,    20,     6,     7,     8,     9,    10,     0,
      11,     0,    12,     0,    21,     0,     0,    13,     0,     0,
       0,    14,     0,    15,     0,     0,    16,     0,     0,    22,
       0,    17,     0,     0,    18,    19,    23,     0,     0,     0,
       0,     0,    20,     0,   315,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     6,     7,     8,     9,    10,     0,
      11,     0,    12,     0,     0,     0,     0,    13,    22,   322,
       0,    14,     0,    15,     0,    23,    16,     0,     0,     0,
       0,    17,     0,     0,    18,    19,     0,     0,     0,     0,
       0,     0,    20,     6,     7,     8,     9,    10,     0,    11,
       0,    12,     0,    21,     0,     0,    13,     0,   323,     0,
      14,     0,    15,     0,     0,    16,     0,     0,    22,     0,
      17,     0,     0,    18,    19,    23,     0,     0,     0,     0,
       0,    20,     6,     7,     8,     9,    10,     0,    11,     0,
      12,     0,    21,     0,     0,    13,     0,   324,     0,    14,
       0,    15,     0,     0,    16,     0,     0,    22,     0,    17,
       0,     0,    18,    19,    23,     0,     0,     0,     0,     0,
      20,     6,     7,     8,     9,    10,     0,    11,     0,    12,
       0,    21,     0,     0,    13,     0,   325,     0,    14,     0,
      15,     0,     0,    16,     0,     0,    22,     0,    17,     0,
       0,    18,    19,    23,     0,     0,     0,     0,     0,    20,
       6,     7,     8,     9,    10,     0,    11,     0,    12,     0,
      21,     0,     0,    13,     0,     0,     0,    14,     0,    15,
       0,     0,    16,     0,     0,    22,     0,    17,     0,     0,
      18,    19,    23,     0,     0,     0,     0,     0,    20,     0,
     343,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       6,     7,     8,     9,    10,     0,    11,     0,    12,     0,
       0,     0,     0,    13,    22,     0,     0,    14,     0,    15,
       0,    23,    16,     0,     0,     0,     0,    17,     0,     0,
      18,    19,     0,     0,     0,     0,     0,     0,    20,     0,
     345,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       6,     7,     8,     9,    10,     0,    11,     0,    12,     0,
       0,     0,     0,    13,    22,     0,     0,    14,     0,    15,
       0,    23,    16,     0,     0,     0,     0,    17,     0,     0,
      18,    19,     0,     0,     0,     0,     0,     0,    20,     0,
     347,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       6,     7,     8,     9,    10,     0,    11,     0,    12,     0,
       0,     0,     0,    13,    22,     0,     0,    14,     0,    15,
       0,    23,    16,     0,     0,     0,     0,    17,     0,     0,
      18,    19,     0,     0,     0,     0,     0,     0,    20,     0,
     349,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       6,     7,     8,     9,    10,     0,    11,     0,    12,     0,
       0,     0,     0,    13,    22,     0,     0,    14,     0,    15,
       0,    23,    16,     0,     0,     0,     0,    17,     0,     0,
      18,    19,     0,     0,     0,     0,     0,     0,    20,     0,
     373,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       6,     7,     8,     9,    10,     0,    11,     0,    12,     0,
       0,     0,     0,    13,    22,     0,     0,    14,     0,    15,
       0,    23,    16,     0,     0,     0,     0,    17,     0,     0,
      18,    19,     0,     0,     0,     0,     0,     0,    20,     0,
     374,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       6,     7,     8,     9,    10,     0,    11,     0,    12,     0,
       0,     0,     0,    13,    22,     0,     0,    14,     0,    15,
       0,    23,    16,     0,     0,     0,     0,    17,     0,     0,
      18,    19,     0,     0,     0,     0,     0,     0,    20,     0,
     375,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       6,     7,     8,     9,    10,     0,    11,     0,    12,     0,
       0,     0,     0,    13,    22,     0,     0,    14,     0,    15,
       0,    23,    16,     0,   241,     0,     0,    17,   242,     0,
      18,    19,     0,     0,     0,     0,     0,    90,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
     142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,    22,     0,     0,     0,     0,     0,
       0,    23,     0,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,   261,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   335,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   336,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
     337,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   338,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   354,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   355,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,   356,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   357,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
       0,   101,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76
};

static const yytype_int16 yycheck[] =
{
      24,   165,    10,     8,    17,    15,     3,     4,     5,     6,
       7,     7,     9,    13,    11,    15,    13,    14,    15,    16,
      10,    23,    17,    20,     8,    22,    30,    31,    25,     8,
      12,    48,    49,    30,    51,    17,    33,    34,     8,    35,
      22,    23,     8,     8,    41,    32,     3,     4,     5,     6,
       7,    30,    31,     0,    73,    52,    58,    76,     7,    41,
      73,    85,    46,     8,    88,    75,     7,    91,    76,    59,
      67,    76,    54,    55,     7,    75,    46,    74,    73,     7,
      46,    46,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    73,    50,    73,    76,    53,
      76,    74,   126,    66,    67,    68,    69,    70,    71,   273,
      67,    53,    54,    55,    56,     8,   140,    74,    48,    49,
      50,    51,    68,    69,    70,    71,    48,    49,    50,    51,
      84,    26,   296,     7,     7,   117,    90,    48,    49,    50,
      51,   165,   166,    77,   168,    48,    49,    50,    51,     8,
      74,    74,    57,    12,    48,    49,    50,    51,   182,   183,
      74,     8,     8,     4,     7,    77,     4,     7,    74,     8,
      74,    59,    74,   127,    74,   157,   158,   159,   160,    71,
     162,    59,    73,    59,    59,     7,    10,     8,   142,   143,
       7,   215,    47,    59,     8,    59,    59,    59,   180,   181,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    42,     5,     5,   240,    73,    10,   173,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,   257,     8,   259,    73,     8,     8,    17,
      74,    10,    10,     8,    10,     8,     8,   201,     4,   273,
       8,     8,   276,   277,   278,   279,     4,     4,     4,     4,
      73,    73,   216,    47,   218,     8,     8,     8,   292,     8,
       8,     8,   296,     5,     8,     8,    73,   301,   302,   303,
     304,    42,   306,    42,     8,     8,     8,   241,    42,     8,
       8,     8,     8,     8,   248,   249,   250,   251,     8,     8,
       4,     4,     4,   327,     4,   329,     4,   331,     4,     8,
     334,     8,    24,     8,   268,   297,   298,   299,   300,     8,
     274,     8,     4,     8,     8,     8,   280,   281,   282,   283,
       8,    19,   286,    19,     8,   359,     8,   361,    19,   363,
     322,   323,   324,   325,    19,     8,     8,     8,     3,     4,
       5,     6,     7,    19,     9,   309,    11,   311,     8,   313,
       8,    16,   316,     8,     8,    20,    19,    22,    19,     8,
      25,     8,    19,     8,     8,    30,     8,     8,    33,    34,
     166,    36,    87,   172,   137,   145,    41,    81,    81,    -1,
     344,    -1,   346,    -1,   348,    -1,    -1,    52,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,
      -1,    16,    67,    -1,    -1,    20,    -1,    22,    -1,    74,
      25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    41,     3,     4,     5,
       6,     7,    -1,     9,    -1,    11,    -1,    52,    -1,    -1,
      16,    -1,    -1,    -1,    20,    -1,    22,    23,    -1,    25,
      -1,    -1,    67,    -1,    30,    -1,    -1,    33,    34,    74,
      -1,    -1,    -1,    -1,    -1,    41,     3,     4,     5,     6,
       7,    -1,     9,    -1,    11,    -1,    52,    -1,    -1,    16,
      -1,    -1,    -1,    20,    -1,    22,    -1,    -1,    25,    -1,
      -1,    67,    -1,    30,    -1,    -1,    33,    34,    74,    -1,
      -1,    -1,    39,    -1,    41,     3,     4,     5,     6,     7,
      -1,     9,    -1,    11,    -1,    52,    -1,    -1,    16,    -1,
      -1,    -1,    20,    -1,    22,    -1,    -1,    25,    -1,    -1,
      67,    -1,    30,    -1,    -1,    33,    34,    74,    -1,    -1,
      38,    -1,    -1,    41,     3,     4,     5,     6,     7,    -1,
       9,    -1,    11,    -1,    52,    -1,    -1,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    -1,    25,    -1,    -1,    67,
      -1,    30,    -1,    -1,    33,    34,    74,    -1,    -1,    -1,
      39,    -1,    41,     3,     4,     5,     6,     7,    -1,     9,
      -1,    11,    -1,    52,    -1,    -1,    16,    -1,    -1,    -1,
      20,    -1,    22,    -1,    -1,    25,    -1,    -1,    67,    -1,
      30,    -1,    -1,    33,    34,    74,    -1,    -1,    -1,    39,
      -1,    41,     3,     4,     5,     6,     7,    -1,     9,    -1,
      11,    -1,    52,    -1,    -1,    16,    -1,    -1,    -1,    20,
      21,    22,    -1,    -1,    25,    -1,    -1,    67,    -1,    30,
      -1,    -1,    33,    34,    74,    -1,    -1,    -1,    -1,    -1,
      41,     3,     4,     5,     6,     7,    -1,     9,    -1,    11,
      -1,    52,    -1,    15,    16,    -1,    -1,    -1,    20,    -1,
      22,    -1,    -1,    25,    -1,    -1,    67,    -1,    30,    -1,
      -1,    33,    34,    74,    -1,    -1,    -1,    -1,    -1,    41,
       3,     4,     5,     6,     7,    -1,     9,    -1,    11,    -1,
      52,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      -1,    -1,    25,    -1,    -1,    67,    -1,    30,    -1,    -1,
      33,    34,    74,    -1,    -1,    -1,    -1,    -1,    41,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    52,
      -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    22,    -1,
      -1,    25,    -1,    -1,    67,    -1,    30,    -1,    -1,    33,
      34,    74,    -1,    -1,    -1,    -1,    -1,    41,     3,     4,
       5,     6,     7,    -1,     9,    -1,    11,    -1,    52,    -1,
      -1,    16,    -1,    18,    -1,    20,    -1,    22,    -1,    -1,
      25,    -1,    -1,    67,    -1,    30,    -1,    -1,    33,    34,
      74,    -1,    -1,    -1,    -1,    -1,    41,     3,     4,     5,
       6,     7,    -1,     9,    -1,    11,    -1,    52,    -1,    -1,
      16,    -1,    18,    -1,    20,    -1,    22,    -1,    -1,    25,
      -1,    -1,    67,    -1,    30,    -1,    -1,    33,    34,    74,
      -1,    -1,    -1,    -1,    -1,    41,     3,     4,     5,     6,
       7,    -1,     9,    -1,    11,    -1,    52,    -1,    -1,    16,
      -1,    18,    -1,    20,    -1,    22,    -1,    -1,    25,    -1,
      -1,    67,    -1,    30,    -1,    -1,    33,    34,    74,    -1,
      -1,    -1,    -1,    -1,    41,     3,     4,     5,     6,     7,
      -1,     9,    -1,    11,    -1,    52,    -1,    -1,    16,    -1,
      18,    -1,    20,    -1,    22,    -1,    -1,    25,    -1,    -1,
      67,    -1,    30,    -1,    -1,    33,    34,    74,    -1,    -1,
      -1,    -1,    -1,    41,     3,     4,     5,     6,     7,    -1,
       9,    -1,    11,    -1,    52,    -1,    -1,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    -1,    25,    -1,    -1,    67,
      -1,    30,    -1,    -1,    33,    34,    74,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,     3,     4,     5,     6,     7,    -1,
       9,    -1,    11,    -1,    -1,    -1,    -1,    16,    67,    18,
      -1,    20,    -1,    22,    -1,    74,    25,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    41,     3,     4,     5,     6,     7,    -1,     9,
      -1,    11,    -1,    52,    -1,    -1,    16,    -1,    18,    -1,
      20,    -1,    22,    -1,    -1,    25,    -1,    -1,    67,    -1,
      30,    -1,    -1,    33,    34,    74,    -1,    -1,    -1,    -1,
      -1,    41,     3,     4,     5,     6,     7,    -1,     9,    -1,
      11,    -1,    52,    -1,    -1,    16,    -1,    18,    -1,    20,
      -1,    22,    -1,    -1,    25,    -1,    -1,    67,    -1,    30,
      -1,    -1,    33,    34,    74,    -1,    -1,    -1,    -1,    -1,
      41,     3,     4,     5,     6,     7,    -1,     9,    -1,    11,
      -1,    52,    -1,    -1,    16,    -1,    18,    -1,    20,    -1,
      22,    -1,    -1,    25,    -1,    -1,    67,    -1,    30,    -1,
      -1,    33,    34,    74,    -1,    -1,    -1,    -1,    -1,    41,
       3,     4,     5,     6,     7,    -1,     9,    -1,    11,    -1,
      52,    -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    22,
      -1,    -1,    25,    -1,    -1,    67,    -1,    30,    -1,    -1,
      33,    34,    74,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
       3,     4,     5,     6,     7,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    16,    67,    -1,    -1,    20,    -1,    22,
      -1,    74,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
       3,     4,     5,     6,     7,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    16,    67,    -1,    -1,    20,    -1,    22,
      -1,    74,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
       3,     4,     5,     6,     7,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    16,    67,    -1,    -1,    20,    -1,    22,
      -1,    74,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
       3,     4,     5,     6,     7,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    16,    67,    -1,    -1,    20,    -1,    22,
      -1,    74,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
       3,     4,     5,     6,     7,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    16,    67,    -1,    -1,    20,    -1,    22,
      -1,    74,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
       3,     4,     5,     6,     7,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    16,    67,    -1,    -1,    20,    -1,    22,
      -1,    74,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
       3,     4,     5,     6,     7,    -1,     9,    -1,    11,    -1,
      -1,    -1,    -1,    16,    67,    -1,    -1,    20,    -1,    22,
      -1,    74,    25,    -1,     8,    -1,    -1,    30,    12,    -1,
      33,    34,    -1,    -1,    -1,    -1,    -1,     8,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      -1,    73,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    79,     7,     0,     8,     3,     4,     5,     6,
       7,     9,    11,    16,    20,    22,    25,    30,    33,    34,
      41,    52,    67,    74,    80,    81,    82,    83,    86,    92,
      93,    94,    95,    98,   101,   102,   105,   106,   107,   108,
     109,    74,     7,    87,    88,    89,    90,    82,     7,     7,
       8,    26,    82,     8,    30,    31,     7,     7,    77,    82,
      82,    36,    81,     8,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    82,    91,    74,
       8,    76,    10,    76,     8,    12,    74,    74,    80,    57,
       8,    80,    82,    82,     8,    10,    59,    53,    54,    55,
      56,    73,     8,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    73,    76,     4,    88,
      90,    48,    49,    50,    51,     7,    80,     8,    81,    84,
      17,    73,    99,   100,    73,    99,    23,   103,   104,    77,
      80,    39,     8,     8,     7,    96,    97,    48,    49,    51,
       4,    74,    74,    74,    74,    82,    73,    59,    59,    59,
      59,    13,    14,    15,    85,    80,    13,    15,    75,     7,
      10,    73,    76,     8,    73,     7,    58,   104,    47,    38,
      30,    31,    80,    80,    59,    35,    97,     8,    59,    59,
      59,    42,     5,     5,    73,    73,    10,    82,    82,    82,
      82,     8,    82,     8,    85,    84,     8,    81,    10,    48,
      49,    50,    51,    10,   100,    80,     8,    10,     8,    74,
       8,    82,    82,    39,    39,     4,     8,     8,     4,     4,
       4,     4,    73,    73,     8,     8,    48,    49,    50,    51,
      80,     8,    12,    15,    48,    49,    50,    51,     8,     8,
       8,     8,    48,    49,    50,    51,    21,    80,    47,    80,
       5,     8,     8,     8,     8,    42,    42,    42,     8,    46,
       8,     8,    15,    80,     8,     8,    80,    80,    80,    80,
       8,     8,     8,     8,     8,    21,     8,     8,    73,     4,
       4,     4,    80,     4,     8,    85,    80,    18,    18,    18,
      18,    80,    80,    80,    80,     8,    80,    24,     8,     8,
      46,     8,    46,     8,    46,    43,     8,    85,    82,    82,
      82,    82,    18,    18,    18,    18,     8,    80,     4,    80,
       4,    80,     4,     8,    80,     8,     8,     8,     8,    82,
      82,    82,    82,    43,     8,    43,     8,    43,     8,    43,
      19,    19,    19,    19,     8,     8,     8,     8,     8,    80,
       8,    80,     8,    80,     8,     8,     8,     8,     8,    19,
      19,    19,    19,    43,    43,    43,     8,     8,     8,     8,
       8,     8,     8
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 159 "vb_lark.y"
    {root = (yyval.Module);(yyval.Module) = create_VB_Module_stmt((yyvsp[(2) - (6)].Id),(yyvsp[(4) - (6)].List));;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 162 "vb_lark.y"
    {(yyval.List) = create_VB_Stmt_list((yyvsp[(1) - (1)].Stmt));;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 163 "vb_lark.y"
    {(yyval.List) = edit_VB_Stmt_list((yyvsp[(1) - (2)].List),(yyvsp[(2) - (2)].Stmt));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 166 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Expr((yyvsp[(1) - (2)].Expr));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 167 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_If((yyvsp[(1) - (1)].If_stmt));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 168 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Dim((yyvsp[(1) - (1)].Dim));;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 169 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_For((yyvsp[(1) - (1)].For));;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 170 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_While((yyvsp[(1) - (1)].While));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 171 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Do_Loop((yyvsp[(1) - (1)].Do_loop));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 172 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Enum((yyvsp[(1) - (1)].Enum));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 173 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Sub((yyvsp[(1) - (1)].Sub));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 174 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Func((yyvsp[(1) - (1)].Func));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 175 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Try_Catch((yyvsp[(1) - (1)].Try_catch));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 176 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Throw((yyvsp[(1) - (1)].Throw));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 177 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Print((yyvsp[(1) - (1)].console_print));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 178 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Println((yyvsp[(1) - (1)].console_println));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 179 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Read((yyvsp[(1) - (1)].console_read));;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 180 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Readln((yyvsp[(1) - (1)].console_readln));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 183 "vb_lark.y"
    {(yyval.Expr) = create_id_expr((yyvsp[(1) - (1)].Id));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 184 "vb_lark.y"
    {(yyval.Expr) = create_brackets_actions((yyvsp[(1) - (4)].Id),(yyvsp[(3) - (4)].Expr_l));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 185 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(INT_CONST,(yyvsp[(1) - (1)].i_const));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 186 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(CHAR_CONST,(yyvsp[(1) - (1)].c_const));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 187 "vb_lark.y"
    {(yyval.Expr) = create_string_const_expr((yyvsp[(1) - (1)].s_const));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 188 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(BOOLEAN_CONST,(yyvsp[(1) - (1)].b_const));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 189 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(ASSIGN,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 190 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(PLUS,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 191 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(MINUS,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 192 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(MUL,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 193 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(DIV,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 194 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(INT_DIV,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 195 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(POWER,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 196 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(MORE,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 197 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(LESS,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 198 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(MORE_OR_EQUAL,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 199 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(LESS_OR_EQUAL,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 200 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(NONEQUAL,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 201 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(EQUAL,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 202 "vb_lark.y"
    {(yyval.Expr) = (yyvsp[(2) - (3)].Expr);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 203 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(UMINUS,(yyvsp[(2) - (2)].Expr),0);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 206 "vb_lark.y"
    {(yyval.If_stmt) = create_with_Then_expr_stmt_list_end_if_stmt(IF_THEN,(yyvsp[(2) - (6)].Expr),(yyvsp[(5) - (6)].List),(yyvsp[(6) - (6)].End_if));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 207 "vb_lark.y"
    {(yyval.If_stmt) = create_with_Then_expr_stmt_list_end_if_stmt(IF_ENDL,(yyvsp[(2) - (5)].Expr),(yyvsp[(4) - (5)].List),(yyvsp[(5) - (5)].End_if));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 208 "vb_lark.y"
    {(yyval.If_stmt) = create_if_inline(IF_INLINE,(yyvsp[(2) - (6)].Expr),(yyvsp[(4) - (6)].List),0);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 209 "vb_lark.y"
    {(yyval.If_stmt) = create_if_inline(IF_ELSE_INLINE,(yyvsp[(2) - (8)].Expr),(yyvsp[(4) - (8)].List),(yyvsp[(6) - (8)].List));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 212 "vb_lark.y"
    {(yyval.List) = create_VB_Stmt_list((yyvsp[(1) - (1)].Stmt));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 213 "vb_lark.y"
    {(yyval.List) = edit_VB_Stmt_list((yyvsp[(1) - (3)].List),(yyvsp[(3) - (3)].Stmt));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 216 "vb_lark.y"
    {(yyval.End_if) = create_end_if_stmt(ENDIF,NULL,NULL,NULL);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 217 "vb_lark.y"
    {(yyval.End_if) = create_end_if_stmt(ELSE,NULL,(yyvsp[(3) - (5)].List),NULL);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 218 "vb_lark.y"
    {(yyval.End_if) = create_end_if_stmt(ELSE_IF_THEN,(yyvsp[(2) - (6)].Expr),(yyvsp[(5) - (6)].List),(yyvsp[(6) - (6)].End_if));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 219 "vb_lark.y"
    {(yyval.End_if) = create_end_if_stmt(ELSE_IF_ENDL,(yyvsp[(2) - (5)].Expr),(yyvsp[(4) - (5)].List),(yyvsp[(5) - (5)].End_if));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 222 "vb_lark.y"
    {(yyval.Dim) = create_dim_stmt((yyvsp[(2) - (3)].As_l));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 225 "vb_lark.y"
    {(yyval.As_l) = create_as_expr_list((yyvsp[(1) - (1)].As_expr_str),NULL);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 226 "vb_lark.y"
    {(yyval.As_l) = create_as_expr_list(NULL,(yyvsp[(1) - (1)].Arr));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 227 "vb_lark.y"
    {(yyval.As_l) = add_to_as_expr_list((yyvsp[(1) - (3)].As_l),(yyvsp[(3) - (3)].As_expr_str),NULL);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 228 "vb_lark.y"
    {(yyval.As_l) = add_to_as_expr_list((yyvsp[(1) - (3)].As_l),NULL,(yyvsp[(3) - (3)].Arr));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 231 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr(ID_LIST,(yyvsp[(1) - (3)].Id_l),NULL,INTEGER,NULL);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 232 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr(ID_LIST,(yyvsp[(1) - (3)].Id_l),NULL,BOOLEAN,NULL);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 233 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr(ID_LIST,(yyvsp[(1) - (3)].Id_l),NULL,CHAR,NULL);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 234 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr(ID_LIST,(yyvsp[(1) - (3)].Id_l),NULL,STRING,NULL);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 235 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr(ID_INIT,NULL,(yyvsp[(1) - (5)].Id_l),INTEGER,(yyvsp[(5) - (5)].Expr));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 236 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr(ID_INIT,NULL,(yyvsp[(1) - (5)].Id_l),BOOLEAN,(yyvsp[(5) - (5)].Expr));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 237 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr(ID_INIT,NULL,(yyvsp[(1) - (5)].Id_l),CHAR,(yyvsp[(5) - (5)].Expr));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 238 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr(ID_INIT,NULL,(yyvsp[(1) - (5)].Id_l),STRING,(yyvsp[(5) - (5)].Expr));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 241 "vb_lark.y"
    {(yyval.Id_l) = create_id_list((yyvsp[(1) - (1)].Id));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 242 "vb_lark.y"
    {(yyval.Id_l) = add_to_id_list((yyvsp[(1) - (3)].Id_l),(yyvsp[(3) - (3)].Id));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 245 "vb_lark.y"
    {(yyval.Arr) = create_Array((yyvsp[(1) - (6)].Id),(yyvsp[(3) - (6)].i_const),INTEGER);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 246 "vb_lark.y"
    {(yyval.Arr) = create_Array((yyvsp[(1) - (6)].Id),(yyvsp[(3) - (6)].i_const),BOOLEAN);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 247 "vb_lark.y"
    {(yyval.Arr) = create_Array((yyvsp[(1) - (6)].Id),(yyvsp[(3) - (6)].i_const),CHAR);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 248 "vb_lark.y"
    {(yyval.Arr) = create_Array((yyvsp[(1) - (6)].Id),(yyvsp[(3) - (6)].i_const),STRING);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 251 "vb_lark.y"
    {(yyval.Expr_l) = create_Expr_list((yyvsp[(1) - (1)].Expr));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 252 "vb_lark.y"
    {(yyval.Expr_l) = add_Expr_to_list((yyvsp[(1) - (3)].Expr_l),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 255 "vb_lark.y"
    {(yyval.For) = create_for_stmt((yyvsp[(2) - (10)].Id),(yyvsp[(4) - (10)].i_const),(yyvsp[(6) - (10)].i_const),(yyvsp[(8) - (10)].List));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 256 "vb_lark.y"
    {(yyval.For) = create_for_with_step_stmt((yyvsp[(2) - (12)].Id),(yyvsp[(4) - (12)].i_const),(yyvsp[(6) - (12)].i_const),(yyvsp[(8) - (12)].i_const),(yyvsp[(10) - (12)].List));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 257 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_stmt((yyvsp[(2) - (12)].Id),INTEGER,(yyvsp[(6) - (12)].i_const),(yyvsp[(8) - (12)].i_const),(yyvsp[(10) - (12)].List));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 258 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_stmt((yyvsp[(2) - (12)].Id),BOOLEAN,(yyvsp[(6) - (12)].i_const),(yyvsp[(8) - (12)].i_const),(yyvsp[(10) - (12)].List));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 259 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_stmt((yyvsp[(2) - (12)].Id),CHAR,(yyvsp[(6) - (12)].i_const),(yyvsp[(8) - (12)].i_const),(yyvsp[(10) - (12)].List));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 260 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_with_step_stmt((yyvsp[(2) - (14)].Id),STRING,(yyvsp[(6) - (14)].i_const),(yyvsp[(8) - (14)].i_const),(yyvsp[(10) - (14)].i_const),(yyvsp[(12) - (14)].List));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 261 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_with_step_stmt((yyvsp[(2) - (14)].Id),STRING,(yyvsp[(6) - (14)].i_const),(yyvsp[(8) - (14)].i_const),(yyvsp[(10) - (14)].i_const),(yyvsp[(12) - (14)].List));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 262 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_with_step_stmt((yyvsp[(2) - (14)].Id),STRING,(yyvsp[(6) - (14)].i_const),(yyvsp[(8) - (14)].i_const),(yyvsp[(10) - (14)].i_const),(yyvsp[(12) - (14)].List));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 265 "vb_lark.y"
    {(yyval.While) = create_while_stmt((yyvsp[(2) - (6)].Expr),(yyvsp[(4) - (6)].List));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 268 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(DO_WHILE,(yyvsp[(3) - (7)].Expr),(yyvsp[(5) - (7)].List));;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 269 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(DO_UNTIL,(yyvsp[(3) - (7)].Expr),(yyvsp[(5) - (7)].List));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 270 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(LOOP_WHILE,(yyvsp[(6) - (7)].Expr),(yyvsp[(3) - (7)].List));;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 271 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(LOOP_UNTIL,(yyvsp[(6) - (7)].Expr),(yyvsp[(3) - (7)].List));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 274 "vb_lark.y"
    {(yyval.Enum) = create_enum_stmt((yyvsp[(2) - (6)].Id),(yyvsp[(4) - (6)].Enum_l));;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 277 "vb_lark.y"
    {(yyval.Enum_l) = create_enum_list((yyvsp[(1) - (2)].Enum_e));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 278 "vb_lark.y"
    {(yyval.Enum_l) = add_to_enum_list((yyvsp[(1) - (3)].Enum_l),(yyvsp[(2) - (3)].Enum_e));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 281 "vb_lark.y"
    {(yyval.Enum_e) = create_enum_expr((yyvsp[(1) - (1)].Id),-1);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 282 "vb_lark.y"
    {(yyval.Enum_e) = create_enum_expr((yyvsp[(1) - (3)].Id),(yyvsp[(3) - (3)].i_const));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 285 "vb_lark.y"
    {(yyval.Sub) = create_sub_stmt((yyvsp[(2) - (8)].Id),NULL,(yyvsp[(6) - (8)].List));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 286 "vb_lark.y"
    {(yyval.Sub) = create_sub_stmt((yyvsp[(2) - (9)].Id),(yyvsp[(4) - (9)].Param_l),(yyvsp[(7) - (9)].List));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 289 "vb_lark.y"
    {(yyval.Param_l) = create_param_list((yyvsp[(1) - (1)].Param)):;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 290 "vb_lark.y"
    {(yyval.Param_l) = add_to_param_list((yyvsp[(1) - (3)].Param_l),(yyvsp[(3) - (3)].Param)):;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 293 "vb_lark.y"
    {(yyval.Param) = create_param_stmt((yyvsp[(2) - (4)].Id),INTEGER):;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 294 "vb_lark.y"
    {(yyval.Param) = create_param_stmt((yyvsp[(2) - (4)].Id),BOOLEAN):;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 295 "vb_lark.y"
    {(yyval.Param) = create_param_stmt((yyvsp[(2) - (4)].Id),CHAR):;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 296 "vb_lark.y"
    {(yyval.Param) = create_param_stmt((yyvsp[(2) - (4)].Id),STRING):;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 299 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (13)].Id),NULL,INTEGER,(yyvsp[(8) - (13)].List),(yyvsp[(10) - (13)].Expr));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 300 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (13)].Id),NULL,BOOLEAN,(yyvsp[(8) - (13)].List),(yyvsp[(10) - (13)].Expr));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 301 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (13)].Id),NULL,CHAR,(yyvsp[(8) - (13)].List),(yyvsp[(10) - (13)].Expr));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 302 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (13)].Id),NULL,STRING,(yyvsp[(8) - (13)].List),(yyvsp[(10) - (13)].Expr));;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 303 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (14)].Id),(yyvsp[(4) - (14)].Param_l),INTEGER,(yyvsp[(9) - (14)].List),(yyvsp[(11) - (14)].Expr));;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 304 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (14)].Id),(yyvsp[(4) - (14)].Param_l),BOOLEAN,(yyvsp[(9) - (14)].List),(yyvsp[(11) - (14)].Expr));;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 305 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (14)].Id),(yyvsp[(4) - (14)].Param_l),CHAR,(yyvsp[(9) - (14)].List),(yyvsp[(11) - (14)].Expr));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 306 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (14)].Id),(yyvsp[(4) - (14)].Param_l),STRING,(yyvsp[(9) - (14)].List),(yyvsp[(11) - (14)].Expr));;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 309 "vb_lark.y"
    {(yyval.Try_catch) = create_Try_Catch((yyvsp[(3) - (10)].List),(yyvsp[(4) - (10)].Catch_l),(yyvsp[(7) - (10)].List));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 312 "vb_lark.y"
    {(yyval.Catch_l) = create_Catch_stmt_list((yyvsp[(1) - (1)].Catch));;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 313 "vb_lark.y"
    {(yyval.Catch_l) = add_new_Catch_stmt((yyvsp[(1) - (2)].Catch_l),(yyvsp[(2) - (2)].Catch));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 316 "vb_lark.y"
    {(yyval.Catch) = create_Catch_stmt((yyvsp[(2) - (6)].Id),(yyvsp[(6) - (6)].List));;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 319 "vb_lark.y"
    {(yyval.Throw) = create_Throw((yyvsp[(7) - (9)].s_const));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 322 "vb_lark.y"
    {(yyval.console_print) = create_Print((yyvsp[(5) - (7)].s_const));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 325 "vb_lark.y"
    {(yyval.console_println) = create_Println(yyvsp[(5) - (7)].s_const));;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 328 "vb_lark.y"
    {(yyval.console_read) = create_Read();;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 331 "vb_lark.y"
    {(yyval.console_readln) = create_Readln();;}
    break;



/* Line 1455 of yacc.c  */
#line 2847 "vb_lark.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 333 "vb_lark.y"


int main (int argc, char* argv[])
{
	file = fopen("result.txt", "wt");
	yyin = fopen(argv[1], "r");
	
	//yylex();	// ÇÀÌÅÍÅÍÅÍÎ
	
	yyparse();
	
	print_tree();		// Âûâîä äåðåâà
	
	fclose(file);
	getchar();
	return 0;
}

