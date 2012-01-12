#include "stdafx.h"
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
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "vb_lark.y"

	#include <stdio.h>
	#include <malloc.h>
	#include "dot.h"

	extern int yylex(void);
	//extern int yyparse(void);

	struct VB_Module_stmt* root;

	void yyerror (char const* s);

	extern FILE* yyin;


/* Line 189 of yacc.c  */
#line 89 "vb_lark.tab.c"

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
     STRING_T = 305,
     BOOLEAN = 306,
     CONSOLE = 307,
     WRITE = 308,
     WRITELINE = 309,
     READ = 310,
     READLINE = 311,
     SYSTEM = 312,
     FINALLY = 313,
     TRUE = 314,
     FALSE = 315,
     SUB_MAIN = 316,
     EQUAL = 317,
     NONEQUAL = 318,
     LESS_OR_EQUAL = 319,
     MORE_OR_EQUAL = 320,
     UMINUS = 321
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 20 "vb_lark.y"

	int		b_const;
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
	struct VB_As_Expr_list*		As_l;
    struct VB_As_expr*			As_expr_str;
	struct VB_Id_list*			Id_l;
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
	struct VB_Return_stmt*		Ret;

	struct VB_Decl_stmt_list*	Decl_l;
	struct VB_Decl_stmt*		Decl;

	enum VB_Id_type				Id_type;

	struct VB_Print_stmt*			console_print;
	struct VB_Println_stmt*			console_println;
	struct VB_Read_stmt*			console_read;
	struct VB_Readln_stmt*			console_readln;



/* Line 214 of yacc.c  */
#line 240 "vb_lark.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 265 "vb_lark.tab.c"

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
#define YYLAST   449

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  317

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      77,    76,    71,    69,    79,    70,    80,    72,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    78,     2,
      64,    62,    63,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    73,     2,    74,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    65,    66,    67,
      68,    75
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    15,    28,    29,    31,    33,    36,    39,
      41,    43,    45,    47,    49,    51,    53,    55,    57,    59,
      61,    63,    64,    66,    68,    71,    73,    75,    77,    79,
      84,    86,    88,    90,    92,    96,   100,   104,   108,   112,
     116,   120,   124,   128,   132,   136,   140,   144,   148,   151,
     158,   164,   171,   180,   182,   186,   189,   195,   202,   208,
     212,   214,   216,   220,   224,   228,   234,   236,   240,   247,
     249,   253,   264,   277,   290,   305,   318,   333,   340,   348,
     356,   364,   372,   379,   382,   386,   388,   392,   401,   411,
     413,   417,   422,   424,   426,   428,   430,   434,   445,   457,
     468,   470,   473,   480,   490,   498,   506,   513
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      82,     0,    -1,    32,     7,     8,    86,    61,     8,    83,
      21,     8,    86,    36,    -1,    32,     7,     8,    86,    61,
       8,    83,    21,     8,    86,    36,     8,    -1,    -1,    84,
      -1,    85,    -1,    84,    85,    -1,    89,     8,    -1,    90,
      -1,    93,    -1,    99,    -1,   100,    -1,   101,    -1,   111,
      -1,   114,    -1,   115,    -1,   116,    -1,   117,    -1,   118,
      -1,   109,    -1,    -1,    87,    -1,    88,    -1,    87,    88,
      -1,   102,    -1,   105,    -1,   110,    -1,     7,    -1,     7,
      77,    98,    76,    -1,     4,    -1,     6,    -1,     5,    -1,
       3,    -1,    89,    62,    89,    -1,    89,    69,    89,    -1,
      89,    70,    89,    -1,    89,    71,    89,    -1,    89,    72,
      89,    -1,    89,    73,    89,    -1,    89,    74,    89,    -1,
      89,    63,    89,    -1,    89,    64,    89,    -1,    89,    68,
      89,    -1,    89,    67,    89,    -1,    89,    66,    89,    -1,
      89,    65,    89,    -1,    77,    89,    76,    -1,    70,    89,
      -1,    11,    89,    12,     8,    83,    92,    -1,    11,    89,
       8,    83,    92,    -1,    11,    89,    12,    91,    15,     8,
      -1,    11,    89,    12,    91,    13,    91,    15,     8,    -1,
      85,    -1,    91,    78,    85,    -1,    15,     8,    -1,    13,
       8,    83,    15,     8,    -1,    14,    89,    12,     8,    83,
      92,    -1,    14,    89,     8,    83,    92,    -1,     9,    94,
       8,    -1,    95,    -1,    97,    -1,    94,    79,    95,    -1,
      94,    79,    97,    -1,    96,    10,   108,    -1,    96,    10,
     108,    62,    89,    -1,     7,    -1,    96,    79,     7,    -1,
       7,    77,     4,    76,    10,   108,    -1,    89,    -1,    98,
      79,    89,    -1,    41,     7,    62,     4,    42,     4,     8,
      83,    43,     8,    -1,    41,     7,    62,     4,    42,     4,
      46,     4,     8,    83,    43,     8,    -1,    41,     7,    10,
      48,    62,     4,    42,     4,     8,    83,    43,     8,    -1,
      41,     7,    10,    48,    62,     4,    42,     4,    46,     4,
       8,    83,    43,     8,    -1,    41,     7,    10,    49,    62,
       6,    42,     6,     8,    83,    43,     8,    -1,    41,     7,
      10,    49,    62,     6,    42,     6,    46,     6,     8,    83,
      43,     8,    -1,    30,    89,     8,    83,    38,     8,    -1,
      33,    30,    89,     8,    83,    39,     8,    -1,    33,    31,
      89,     8,    83,    39,     8,    -1,    33,     8,    83,    39,
      30,    89,     8,    -1,    33,     8,    83,    39,    31,    89,
       8,    -1,    34,     7,     8,   103,    35,     8,    -1,   104,
       8,    -1,   103,   104,     8,    -1,     7,    -1,     7,    62,
       4,    -1,    20,     7,    77,    76,     8,    83,    21,     8,
      -1,    20,     7,    77,   106,    76,     8,    83,    21,     8,
      -1,   107,    -1,   106,    79,   107,    -1,    17,     7,    10,
     108,    -1,    48,    -1,    51,    -1,    49,    -1,    50,    -1,
      18,    89,     8,    -1,    16,     7,    77,    76,    10,   108,
       8,    83,    19,     8,    -1,    16,     7,    77,   106,    76,
      10,   108,     8,    83,    19,     8,    -1,    22,     8,    83,
     112,    58,     8,    83,     8,    24,     8,    -1,   113,    -1,
     112,   113,    -1,    23,     7,    10,    47,     8,    83,    -1,
      25,    26,    57,    80,    47,    77,     5,    76,     8,    -1,
      52,    80,    53,    77,     5,    76,     8,    -1,    52,    80,
      54,    77,     5,    76,     8,    -1,    52,    80,    55,    77,
      76,     8,    -1,    52,    80,    56,    77,    76,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   182,   182,   183,   186,   187,   190,   191,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   209,   210,   213,   214,   217,   218,   219,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   245,
     246,   247,   248,   251,   252,   255,   256,   257,   258,   261,
     264,   265,   266,   267,   270,   271,   274,   275,   278,   281,
     282,   285,   286,   287,   288,   289,   290,   293,   296,   297,
     298,   299,   302,   305,   306,   309,   310,   313,   314,   317,
     318,   321,   324,   325,   326,   327,   330,   332,   333,   336,
     339,   340,   343,   346,   349,   352,   355,   358
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
  "INTEGER", "CHAR", "STRING_T", "BOOLEAN", "CONSOLE", "WRITE",
  "WRITELINE", "READ", "READLINE", "SYSTEM", "FINALLY", "TRUE", "FALSE",
  "SUB_MAIN", "'='", "'>'", "'<'", "EQUAL", "NONEQUAL", "LESS_OR_EQUAL",
  "MORE_OR_EQUAL", "'+'", "'-'", "'*'", "'/'", "'\\\\'", "'^'", "UMINUS",
  "')'", "'('", "':'", "','", "'.'", "$accept", "module_stmt", "stmt_list",
  "stmt_listE", "stmt", "decl_stmt_list", "decl_stmt_listE", "decl_stmt",
  "expr", "if_stmt", "stmt_list_inline", "end_if_stmt", "dim_stmt",
  "as_expr_list", "as_expr", "id_list_stmt", "array_expr", "expr_list",
  "for_stmt", "while_stmt", "do_loop_stmt", "enum_stmt", "enum_expr_list",
  "enum_expr", "sub_stmt", "param_list", "param_stmt", "param_type",
  "return_stmt", "func_stmt", "try_catch_stmt", "catch_stmt_list",
  "catch_stmt", "throw_stmt", "console_print_stmt", "console_println_stmt",
  "console_read_stmt", "console_readln_stmt", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    61,    62,    60,   317,   318,   319,   320,    43,
      45,    42,    47,    92,    94,   321,    41,    40,    58,    44,
      46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    86,    87,    87,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    90,
      90,    90,    90,    91,    91,    92,    92,    92,    92,    93,
      94,    94,    94,    94,    95,    95,    96,    96,    97,    98,
      98,    99,    99,    99,    99,    99,    99,   100,   101,   101,
     101,   101,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   108,   108,   108,   108,   109,   110,   110,   111,
     112,   112,   113,   114,   115,   116,   117,   118
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    11,    12,     0,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     2,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     6,
       5,     6,     8,     1,     3,     2,     5,     6,     5,     3,
       1,     1,     3,     3,     3,     5,     1,     3,     6,     1,
       3,    10,    12,    12,    14,    12,    14,     6,     7,     7,
       7,     7,     6,     2,     3,     1,     3,     8,     9,     1,
       3,     4,     1,     1,     1,     1,     3,    10,    11,    10,
       1,     2,     6,     9,     7,     7,     6,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    21,     0,     0,     0,     0,
      22,    23,    25,    26,    27,     0,     0,     0,     0,    24,
       0,     0,     0,     4,     0,     0,     0,    89,     0,     0,
      85,     0,     0,    33,    30,    32,    31,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     0,     9,    10,    11,    12,    13,    20,    14,
      15,    16,    17,    18,    19,     0,     0,     0,     0,     4,
       0,     0,     0,     0,    83,     0,    66,     0,    60,     0,
      61,     0,     0,     4,     0,     0,     4,     0,     0,     0,
       0,    48,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    94,    95,    93,     0,     0,    90,     0,     4,    86,
      82,    84,    69,     0,     0,    59,     0,     0,     0,     4,
       0,    96,     0,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    21,    34,    41,    42,    46,
      45,    44,    43,    35,    36,    37,    38,    39,    40,    91,
       4,     0,     0,     0,    29,     0,     0,    62,    63,    64,
      67,     0,     4,    53,     0,     0,     0,   100,     0,     0,
       0,     4,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,    87,     0,    70,     0,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,    88,     0,    65,     4,     0,
      55,    49,     0,    51,    54,     0,     4,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,   107,
       3,    97,     0,    68,     0,     4,     0,     0,     0,     0,
       0,    80,    81,    78,    79,     0,     0,     4,     0,   104,
     105,    98,     0,     0,     4,    52,     4,     0,     0,     0,
       0,     0,     0,    56,    58,     0,   102,     0,   103,     4,
       0,     4,     0,     0,     4,    57,    99,     0,     0,     0,
       0,    71,     0,     0,     4,     0,     4,     0,    73,     0,
      75,     0,    72,     0,     0,    74,    76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    49,    50,    51,     9,    10,    11,    52,    53,
     174,   201,    54,    77,    78,    79,    80,   123,    55,    56,
      57,    12,    31,    32,    13,    26,    27,   114,    58,    14,
      59,   176,   177,    60,    61,    62,    63,    64
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -185
static const yytype_int16 yypact[] =
{
     -11,    45,    67,    78,  -185,    19,    64,    81,    87,    36,
      19,  -185,  -185,  -185,  -185,    21,    25,    88,    92,  -185,
      -8,    -7,   103,   206,   104,   108,   -22,  -185,   112,   -21,
      59,    24,   114,  -185,  -185,  -185,  -185,    47,   125,    22,
      22,   130,   113,    22,     3,   135,    65,    22,    22,   127,
     206,  -185,   198,  -185,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,   133,    66,   136,   132,   206,
     142,   147,   145,   146,  -185,    22,    79,    14,  -185,    -9,
    -185,   222,   249,   206,   100,   265,   206,    22,    22,    -6,
     -13,  -185,   369,   153,  -185,  -185,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22,    22,    22,    22,    66,
    -185,  -185,  -185,  -185,   154,    66,  -185,   143,   206,  -185,
    -185,  -185,   303,    11,   161,  -185,   125,    66,   159,   206,
     122,  -185,   148,    89,   206,   129,   289,   316,    13,   166,
      95,    99,   101,   102,  -185,    19,   303,    35,    35,    35,
      35,    35,    35,    63,    63,   106,   106,   106,  -185,  -185,
     206,   169,   173,   162,  -185,    22,   109,  -185,  -185,   120,
    -185,    23,   206,  -185,    17,   177,   -10,  -185,   144,   151,
      16,   206,   206,   128,   131,   152,   190,   191,   121,   124,
     165,   183,   206,  -185,   195,   303,   194,    22,   200,    22,
     208,  -185,    23,   206,   210,   206,   204,   211,  -185,   149,
     213,    22,    22,   184,   188,   225,   226,   229,   164,   167,
     230,   233,   234,   237,   227,  -185,    66,   303,   206,   236,
    -185,  -185,   -12,  -185,  -185,   202,   206,   245,  -185,   332,
     356,   243,   244,   212,   214,    -2,   247,   251,  -185,  -185,
    -185,  -185,   266,  -185,   238,   206,   267,   269,   270,   271,
     205,  -185,  -185,  -185,  -185,   276,   319,   206,   278,  -185,
    -185,  -185,   318,    23,   206,  -185,   206,   317,   334,    -1,
       4,   300,   336,  -185,  -185,    23,  -185,   337,  -185,   206,
     342,   206,   341,   340,   206,  -185,  -185,   306,   383,   307,
     384,  -185,   350,   399,   206,   400,   206,   401,  -185,   367,
    -185,   368,  -185,   404,   405,  -185,  -185
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -185,  -185,   -69,  -185,   -45,   272,  -185,   406,   -24,  -185,
     241,  -184,  -185,  -185,   288,  -185,   320,  -185,  -185,  -185,
    -185,  -185,  -185,   416,  -185,   394,   380,  -107,  -185,  -185,
    -185,  -185,   273,  -185,  -185,  -185,  -185,  -185
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     117,   127,   159,   257,   138,    94,   267,   289,   161,    24,
      24,    86,   291,   175,   132,    81,    82,   135,   231,    85,
     169,     1,   125,    91,    92,    33,    34,    35,    36,    37,
     203,    30,   204,    87,    88,     6,   198,   199,   200,     7,
     140,   141,   142,   143,   268,   290,   211,   212,   207,   163,
     292,   122,     3,     8,    67,    70,   139,    68,    68,    72,
     171,   183,   184,   136,   137,   179,   205,     4,    25,    28,
     128,    15,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   173,     5,   164,    16,   284,
     165,   191,    47,   126,    17,   205,    22,    18,    20,    48,
      23,   295,    21,   202,   103,   104,   105,   106,   107,   108,
      30,    65,   213,   214,   110,   111,   112,   113,    66,   253,
      69,    71,    74,   224,    75,    33,    34,    35,    36,    37,
     172,    38,    76,    39,   105,   106,   107,   108,    83,    84,
      40,   195,    89,   109,    41,    90,   115,    42,    93,    24,
     118,   119,    43,   120,   121,    44,   124,   133,   173,   254,
     234,   145,   160,    45,   162,   166,   170,   259,   180,   178,
     185,   175,   186,   227,    46,   229,   187,   192,   188,   189,
     108,   193,   197,   194,   206,   196,   273,   239,   240,   210,
     215,   209,    47,   216,   217,   218,   219,   220,   281,    48,
     221,   222,   223,   225,   226,   285,    95,   286,   228,    33,
      34,    35,    36,    37,   235,    38,   230,    39,   233,   236,
     297,   238,   299,   241,    40,   302,   237,   242,    41,   243,
     129,    42,   244,   245,   130,   309,    43,   311,   248,    44,
     246,   249,   250,   247,   255,   251,   252,    45,   256,   258,
     260,   263,   264,   272,   265,   269,   266,   131,    46,   270,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   134,   271,   274,    47,   275,   276,   277,
     279,   278,   282,    48,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   181,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   182,   280,   283,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     261,   287,   288,   293,   294,   296,   298,   300,   301,   303,
     305,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   262,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   304,   306,   307,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   308,   310,   312,
     313,   314,   315,   316,   167,    29,    19,   190,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   232,   144,   168,    73,   116,   208
};

static const yytype_uint16 yycheck[] =
{
      69,    10,   109,    15,    10,    50,     8,     8,   115,    17,
      17,     8,     8,    23,    83,    39,    40,    86,   202,    43,
     127,    32,     8,    47,    48,     3,     4,     5,     6,     7,
      13,     7,    15,    30,    31,    16,    13,    14,    15,    20,
      53,    54,    55,    56,    46,    46,    30,    31,    58,   118,
      46,    75,     7,    34,    76,    76,    62,    79,    79,    35,
     129,    48,    49,    87,    88,   134,    78,     0,    76,    76,
      79,     7,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   130,     8,    76,     7,   273,
      79,   160,    70,    79,     7,    78,     8,    61,    77,    77,
       8,   285,    77,   172,    69,    70,    71,    72,    73,    74,
       7,     7,   181,   182,    48,    49,    50,    51,    10,   226,
       8,    62,     8,   192,    77,     3,     4,     5,     6,     7,
       8,     9,     7,    11,    71,    72,    73,    74,     8,    26,
      18,   165,     7,    10,    22,    80,    10,    25,    21,    17,
       8,     4,    30,     8,     8,    33,    77,    57,   203,   228,
     205,     8,     8,    41,    21,     4,     7,   236,    39,    80,
       4,    23,    77,   197,    52,   199,    77,     8,    77,    77,
      74,     8,    62,    21,     7,    76,   255,   211,   212,    38,
      62,    47,    70,    62,    42,     5,     5,    76,   267,    77,
      76,    36,    19,     8,    10,   274,     8,   276,     8,     3,
       4,     5,     6,     7,    10,     9,     8,    11,     8,     8,
     289,     8,   291,    39,    18,   294,    77,    39,    22,     4,
       8,    25,     6,     4,    12,   304,    30,   306,     8,    33,
      76,     8,     8,    76,     8,     8,    19,    41,    12,    47,
       5,     8,     8,    15,    42,     8,    42,     8,    52,     8,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     8,     8,     8,    70,     8,     8,     8,
       4,    76,     4,    77,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     8,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     8,     6,     8,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       8,    24,     8,    43,     8,     8,     4,     6,     8,    43,
      43,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     8,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     8,     8,    43,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     8,     8,     8,
      43,    43,     8,     8,   126,    21,    10,   145,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,   203,    76,   126,    31,    68,   176
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    82,     7,     0,     8,    16,    20,    34,    86,
      87,    88,   102,   105,   110,     7,     7,     7,    61,    88,
      77,    77,     8,     8,    17,    76,   106,   107,    76,   106,
       7,   103,   104,     3,     4,     5,     6,     7,     9,    11,
      18,    22,    25,    30,    33,    41,    52,    70,    77,    83,
      84,    85,    89,    90,    93,    99,   100,   101,   109,   111,
     114,   115,   116,   117,   118,     7,    10,    76,    79,     8,
      76,    62,    35,   104,     8,    77,     7,    94,    95,    96,
      97,    89,    89,     8,    26,    89,     8,    30,    31,     7,
      80,    89,    89,    21,    85,     8,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    10,
      48,    49,    50,    51,   108,    10,   107,    83,     8,     4,
       8,     8,    89,    98,    77,     8,    79,    10,    79,     8,
      12,     8,    83,    57,     8,    83,    89,    89,    10,    62,
      53,    54,    55,    56,    76,     8,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,   108,
       8,   108,    21,    83,    76,    79,     4,    95,    97,   108,
       7,    83,     8,    85,    91,    23,   112,   113,    80,    83,
      39,     8,     8,    48,    49,     4,    77,    77,    77,    77,
      86,    83,     8,     8,    21,    89,    76,    62,    13,    14,
      15,    92,    83,    13,    15,    78,     7,    58,   113,    47,
      38,    30,    31,    83,    83,    62,    62,    42,     5,     5,
      76,    76,    36,    19,    83,     8,    10,    89,     8,    89,
       8,    92,    91,     8,    85,    10,     8,    77,     8,    89,
      89,    39,    39,     4,     6,     4,    76,    76,     8,     8,
       8,     8,    19,   108,    83,     8,    12,    15,    47,    83,
       5,     8,     8,     8,     8,    42,    42,     8,    46,     8,
       8,     8,    15,    83,     8,     8,     8,     8,    76,     4,
       6,    83,     4,     8,    92,    83,    83,    24,     8,     8,
      46,     8,    46,    43,     8,    92,     8,    83,     4,    83,
       6,     8,    83,    43,     8,    43,     8,    43,     8,    83,
       8,    83,     8,    43,    43,     8,     8
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

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
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
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
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 182 "vb_lark.y"
    {(yyval.Module) = root = create_VB_Module_stmt((yyvsp[(2) - (11)].Id),(yyvsp[(7) - (11)].List),(yyvsp[(4) - (11)].Decl_l),(yyvsp[(10) - (11)].Decl_l));;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 183 "vb_lark.y"
    {(yyval.Module) = root = create_VB_Module_stmt((yyvsp[(2) - (12)].Id),(yyvsp[(7) - (12)].List),(yyvsp[(4) - (12)].Decl_l),(yyvsp[(10) - (12)].Decl_l));;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 186 "vb_lark.y"
    {(yyval.List) = create_VB_Stmt_list(0);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 190 "vb_lark.y"
    {(yyval.List) = create_VB_Stmt_list((yyvsp[(1) - (1)].Stmt));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 191 "vb_lark.y"
    {(yyval.List) = edit_VB_Stmt_list((yyvsp[(1) - (2)].List),(yyvsp[(2) - (2)].Stmt));;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 194 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Expr((yyvsp[(1) - (2)].Expr));;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 195 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_If((yyvsp[(1) - (1)].If_stmt));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 196 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Dim((yyvsp[(1) - (1)].Dim));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 197 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_For((yyvsp[(1) - (1)].For));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 198 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_While((yyvsp[(1) - (1)].While));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 199 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Do_Loop((yyvsp[(1) - (1)].Do_loop));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 200 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Try_Catch((yyvsp[(1) - (1)].Try_catch));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 201 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Throw((yyvsp[(1) - (1)].Throw));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 202 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Print((yyvsp[(1) - (1)].console_print));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 203 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Println((yyvsp[(1) - (1)].console_println));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 204 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Read((yyvsp[(1) - (1)].console_read));;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 205 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Readln((yyvsp[(1) - (1)].console_readln));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 206 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Return((yyvsp[(1) - (1)].Ret));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 209 "vb_lark.y"
    {(yyval.Decl_l) = create_VB_Decl_stmt_list(0);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 213 "vb_lark.y"
    {(yyval.Decl_l) = create_VB_Decl_stmt_list((yyvsp[(1) - (1)].Decl));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 214 "vb_lark.y"
    {(yyval.Decl_l) = edit_VB_Decl_stmt_list((yyvsp[(1) - (2)].Decl_l),(yyvsp[(2) - (2)].Decl));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 217 "vb_lark.y"
    {(yyval.Decl) = create_VB_Decl_Enum((yyvsp[(1) - (1)].Enum));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 218 "vb_lark.y"
    {(yyval.Decl) = create_VB_Decl_Sub((yyvsp[(1) - (1)].Sub));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 219 "vb_lark.y"
    {(yyval.Decl) = create_VB_Decl_Func((yyvsp[(1) - (1)].Func));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 222 "vb_lark.y"
    {(yyval.Expr) = create_id_expr((yyvsp[(1) - (1)].Id));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 223 "vb_lark.y"
    {(yyval.Expr) = create_brackets_actions((yyvsp[(1) - (4)].Id),(yyvsp[(3) - (4)].Expr_l));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 224 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(3,(yyvsp[(1) - (1)].i_const));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 225 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(2,(yyvsp[(1) - (1)].c_const));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 226 "vb_lark.y"
    {(yyval.Expr) = create_string_const_expr((yyvsp[(1) - (1)].s_const));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 227 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(5,(yyvsp[(1) - (1)].b_const));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 228 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(6,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 229 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(7,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 230 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(8,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 231 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(9,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 232 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(11,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 233 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(10,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 234 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(12,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 235 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(13,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 236 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(14,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 237 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(15,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 238 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(16,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 239 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(17,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 240 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(18,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 241 "vb_lark.y"
    {(yyval.Expr) = (yyvsp[(2) - (3)].Expr);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 242 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(19,(yyvsp[(2) - (2)].Expr),0);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 245 "vb_lark.y"
    {(yyval.If_stmt) = create_with_Then_expr_stmt_list_end_if_stmt(0,(yyvsp[(2) - (6)].Expr),(yyvsp[(5) - (6)].List),(yyvsp[(6) - (6)].End_if));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 246 "vb_lark.y"
    {(yyval.If_stmt) = create_with_Then_expr_stmt_list_end_if_stmt(1,(yyvsp[(2) - (5)].Expr),(yyvsp[(4) - (5)].List),(yyvsp[(5) - (5)].End_if));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 247 "vb_lark.y"
    {(yyval.If_stmt) = create_if_inline(2,(yyvsp[(2) - (6)].Expr),(yyvsp[(4) - (6)].List),0);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 248 "vb_lark.y"
    {(yyval.If_stmt) = create_if_inline(3,(yyvsp[(2) - (8)].Expr),(yyvsp[(4) - (8)].List),(yyvsp[(6) - (8)].List));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 251 "vb_lark.y"
    {(yyval.List) = create_VB_Stmt_list((yyvsp[(1) - (1)].Stmt));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 252 "vb_lark.y"
    {(yyval.List) = edit_VB_Stmt_list((yyvsp[(1) - (3)].List),(yyvsp[(3) - (3)].Stmt));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 255 "vb_lark.y"
    {(yyval.End_if) = create_end_if_stmt(0,NULL,NULL,NULL);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 256 "vb_lark.y"
    {(yyval.End_if) = create_end_if_stmt(1,NULL,(yyvsp[(3) - (5)].List),NULL);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 257 "vb_lark.y"
    {(yyval.End_if) = create_end_if_stmt(2,(yyvsp[(2) - (6)].Expr),(yyvsp[(5) - (6)].List),(yyvsp[(6) - (6)].End_if));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 258 "vb_lark.y"
    {(yyval.End_if) = create_end_if_stmt(3,(yyvsp[(2) - (5)].Expr),(yyvsp[(4) - (5)].List),(yyvsp[(5) - (5)].End_if));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 261 "vb_lark.y"
    {(yyval.Dim) = create_dim_stmt((yyvsp[(2) - (3)].As_l));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 264 "vb_lark.y"
    {(yyval.As_l) = create_as_expr_list((yyvsp[(1) - (1)].As_expr_str),NULL);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 265 "vb_lark.y"
    {(yyval.As_l) = create_as_expr_list(NULL,(yyvsp[(1) - (1)].Arr));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 266 "vb_lark.y"
    {(yyval.As_l) = add_to_as_expr_list((yyvsp[(1) - (3)].As_l),(yyvsp[(3) - (3)].As_expr_str),NULL);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 267 "vb_lark.y"
    {(yyval.As_l) = add_to_as_expr_list((yyvsp[(1) - (3)].As_l),NULL,(yyvsp[(3) - (3)].Arr));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 270 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr(0,(yyvsp[(1) - (3)].Id_l),NULL,(yyvsp[(3) - (3)].Id_type),NULL);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 271 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr(0,(yyvsp[(1) - (5)].Id_l),NULL,(yyvsp[(3) - (5)].Id_type),(yyvsp[(5) - (5)].Expr));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 274 "vb_lark.y"
    {(yyval.Id_l) = create_id_list((yyvsp[(1) - (1)].Id));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 275 "vb_lark.y"
    {(yyval.Id_l) = add_to_id_list((yyvsp[(1) - (3)].Id_l),(yyvsp[(3) - (3)].Id));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 278 "vb_lark.y"
    {(yyval.Arr) = create_Array((yyvsp[(1) - (6)].Id),(yyvsp[(3) - (6)].i_const),(yyvsp[(6) - (6)].Id_type));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 281 "vb_lark.y"
    {(yyval.Expr_l) = create_Expr_list((yyvsp[(1) - (1)].Expr));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 282 "vb_lark.y"
    {(yyval.Expr_l) = add_Expr_to_list((yyvsp[(1) - (3)].Expr_l),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 285 "vb_lark.y"
    {(yyval.For) = create_for_stmt((yyvsp[(2) - (10)].Id),(yyvsp[(4) - (10)].i_const),(yyvsp[(6) - (10)].i_const),(yyvsp[(8) - (10)].List));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 286 "vb_lark.y"
    {(yyval.For) = create_for_with_step_stmt((yyvsp[(2) - (12)].Id),(yyvsp[(4) - (12)].i_const),(yyvsp[(6) - (12)].i_const),(yyvsp[(8) - (12)].i_const),(yyvsp[(10) - (12)].List));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 287 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_stmt((yyvsp[(2) - (12)].Id),INTEGER_E,(yyvsp[(6) - (12)].i_const),(yyvsp[(8) - (12)].i_const),(yyvsp[(10) - (12)].List));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 288 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_with_step_stmt((yyvsp[(2) - (14)].Id),INTEGER_E,(yyvsp[(6) - (14)].i_const),(yyvsp[(8) - (14)].i_const),(yyvsp[(10) - (14)].i_const),(yyvsp[(12) - (14)].List));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 289 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_stmt((yyvsp[(2) - (12)].Id),CHAR_E,(yyvsp[(6) - (12)].c_const),(yyvsp[(8) - (12)].c_const),(yyvsp[(10) - (12)].List));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 290 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_with_step_stmt((yyvsp[(2) - (14)].Id),CHAR_E,(yyvsp[(6) - (14)].c_const),(yyvsp[(8) - (14)].c_const),(yyvsp[(10) - (14)].c_const),(yyvsp[(12) - (14)].List));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 293 "vb_lark.y"
    {(yyval.While) = create_while_stmt((yyvsp[(2) - (6)].Expr),(yyvsp[(4) - (6)].List));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 296 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(0,(yyvsp[(3) - (7)].Expr),(yyvsp[(5) - (7)].List));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 297 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(1,(yyvsp[(3) - (7)].Expr),(yyvsp[(5) - (7)].List));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 298 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(2,(yyvsp[(6) - (7)].Expr),(yyvsp[(3) - (7)].List));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 299 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(3,(yyvsp[(6) - (7)].Expr),(yyvsp[(3) - (7)].List));;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 302 "vb_lark.y"
    {(yyval.Enum) = create_enum_stmt((yyvsp[(2) - (6)].Id),(yyvsp[(4) - (6)].Enum_l));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 305 "vb_lark.y"
    {(yyval.Enum_l) = create_enum_list((yyvsp[(1) - (2)].Enum_e));;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 306 "vb_lark.y"
    {(yyval.Enum_l) = add_to_enum_list((yyvsp[(1) - (3)].Enum_l),(yyvsp[(2) - (3)].Enum_e));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 309 "vb_lark.y"
    {(yyval.Enum_e) = create_enum_expr((yyvsp[(1) - (1)].Id),-1);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 310 "vb_lark.y"
    {(yyval.Enum_e) = create_enum_expr((yyvsp[(1) - (3)].Id),(yyvsp[(3) - (3)].i_const));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 313 "vb_lark.y"
    {(yyval.Sub) = create_sub_stmt((yyvsp[(2) - (8)].Id),NULL,(yyvsp[(6) - (8)].List));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 314 "vb_lark.y"
    {(yyval.Sub) = create_sub_stmt((yyvsp[(2) - (9)].Id),(yyvsp[(4) - (9)].Param_l),(yyvsp[(7) - (9)].List));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 317 "vb_lark.y"
    {(yyval.Param_l) = create_param_list((yyvsp[(1) - (1)].Param));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 318 "vb_lark.y"
    {(yyval.Param_l) = add_to_param_list((yyvsp[(1) - (3)].Param_l),(yyvsp[(3) - (3)].Param));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 321 "vb_lark.y"
    {(yyval.Param) = create_param_stmt((yyvsp[(2) - (4)].Id),(yyvsp[(4) - (4)].Id_type));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 324 "vb_lark.y"
    {(yyval.Id_type) = INTEGER_E;;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 325 "vb_lark.y"
    {(yyval.Id_type) = BOOLEAN_E;;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 326 "vb_lark.y"
    {(yyval.Id_type) = CHAR_E;;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 327 "vb_lark.y"
    {(yyval.Id_type) = STRING_E;;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 330 "vb_lark.y"
    {(yyval.Ret) = create_return_stmt((yyvsp[(2) - (3)].Expr));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 332 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (10)].Id),NULL,(yyvsp[(6) - (10)].Id_type),(yyvsp[(8) - (10)].List));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 333 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (11)].Id),(yyvsp[(4) - (11)].Param_l),(yyvsp[(7) - (11)].Id_type),(yyvsp[(9) - (11)].List));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 336 "vb_lark.y"
    {(yyval.Try_catch) = create_Try_Catch((yyvsp[(3) - (10)].List),(yyvsp[(4) - (10)].Catch_l),(yyvsp[(7) - (10)].List));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 339 "vb_lark.y"
    {(yyval.Catch_l) = create_Catch_stmt_list((yyvsp[(1) - (1)].Catch));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 340 "vb_lark.y"
    {(yyval.Catch_l) = add_new_Catch_stmt((yyvsp[(1) - (2)].Catch_l),(yyvsp[(2) - (2)].Catch));;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 343 "vb_lark.y"
    {(yyval.Catch) = create_Catch_stmt((yyvsp[(2) - (6)].Id),(yyvsp[(6) - (6)].List));;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 346 "vb_lark.y"
    {(yyval.Throw) = create_Throw((yyvsp[(7) - (9)].s_const));;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 349 "vb_lark.y"
    {(yyval.console_print) = create_Print((yyvsp[(5) - (7)].s_const));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 352 "vb_lark.y"
    {(yyval.console_println) = create_Println((yyvsp[(5) - (7)].s_const));;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 355 "vb_lark.y"
    {(yyval.console_read) = create_Read();;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 358 "vb_lark.y"
    {(yyval.console_readln) = create_Readln();;}
    break;



/* Line 1455 of yacc.c  */
#line 2518 "vb_lark.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
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
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 360 "vb_lark.y"


void yyerror (char const* s)
{
	printf("%s\n",s);
	printf("ERROR on line: %d and column: %d", yylloc.first_line,yylloc.last_column);
	getchar();
	exit(0);
}

int main (int argc, char* argv[])
{
	FILE* file;

	file = fopen("result.txt", "wt");
	yyin = fopen(argv[1], "r");

	//yylex();	// ÇÀÌÅÍÅÍÅÍÎ

	yyparse();

	print_tree();		// Âûâîä äåðåâà

	fclose(file);
	getchar();
	return 0;
}

