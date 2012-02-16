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

	int get_location ();
	
	extern FILE* yyin;


/* Line 189 of yacc.c  */
#line 91 "vb_lark.tab.c"

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
     TRUE = 258,
     FALSE = 259,
     INT_CONST = 260,
     STRING_CONST = 261,
     CHAR_CONST = 262,
     ID = 263,
     ENDL = 264,
     DIM = 265,
     AS = 266,
     IF = 267,
     THEN = 268,
     ELSE = 269,
     ELSEIF = 270,
     END_IF = 271,
     FUNCTION = 272,
     BYVAL = 273,
     BYREF = 274,
     RETURN = 275,
     END_FUNCTION = 276,
     SUB = 277,
     END_SUB = 278,
     TRY = 279,
     CATCH = 280,
     END_TRY = 281,
     THROW = 282,
     NEW = 283,
     CASE = 284,
     CONST = 285,
     SELECT = 286,
     WHILE = 287,
     UNTIL = 288,
     MODULE = 289,
     DO = 290,
     ENUM = 291,
     END_ENUM = 292,
     END_MODULE = 293,
     END_SELECT = 294,
     END_WHILE = 295,
     LOOP = 296,
     FOR_EACH = 297,
     FOR = 298,
     TO = 299,
     NEXT = 300,
     IN = 301,
     MOD = 302,
     STEP = 303,
     EXCEPTION = 304,
     INTEGER = 305,
     CHAR = 306,
     STRING_T = 307,
     BOOLEAN = 308,
     CONSOLE = 309,
     WRITE = 310,
     WRITELINE = 311,
     READ = 312,
     READLINE = 313,
     SYSTEM = 314,
     FINALLY = 315,
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
#line 22 "vb_lark.y"

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
//	struct VB_End_if_stmt*		End_if;
	struct VB_Dim_stmt*			Dim;
	struct VB_As_Expr_list*		As_l;
    struct VB_As_expr*			As_expr_str;
	struct VB_Id_list*			Id_l;
	//struct VB_Array_expr*		Arr;
	struct VB_For_stmt*			For;
	struct VB_While_stmt*		While;
	struct VB_Do_loop_stmt*		Do_loop;
//	struct VB_Enum_stmt*		Enum;
//	struct VB_Enum_expr_list*	Enum_l;
//	struct VB_Enum_expr*		Enum_e;
	struct VB_Sub_stmt*			Sub;
	struct VB_Param_list*		Param_l;
	struct VB_Param_stmt*		Param;
	struct VB_Func_stmt*		Func;
//	struct VB_Try_catch_stmt*	Try_catch;
//	struct VB_Catch_stmt_list*	Catch_l;
//	struct VB_Catch_stmt*		Catch;
//	struct VB_Throw_stmt*		Throw;
	struct VB_Return_stmt*		Ret;

	struct VB_Decl_stmt_list*	Decl_l;
	struct VB_Decl_stmt*		Decl;

	enum VB_Id_type				Id_type;

//	struct VB_Print_stmt*			console_print;
//	struct VB_Println_stmt*			console_println;
//	struct VB_Read_stmt*			console_read;
//	struct VB_Readln_stmt*			console_readln;



/* Line 214 of yacc.c  */
#line 242 "vb_lark.tab.c"
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
#line 267 "vb_lark.tab.c"

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   503

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNRULES -- Number of states.  */
#define YYNSTATES  271

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
      77,    76,    71,    69,    79,    70,    78,    72,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      64,    62,    63,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    73,     2,    74,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    80,     2,    81,     2,     2,     2,     2,
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
       0,     0,     3,     4,     6,     8,    11,    25,    26,    28,
      30,    33,    36,    38,    40,    42,    44,    46,    48,    49,
      51,    53,    56,    58,    60,    62,    64,    66,    71,    77,
      83,    90,    96,   103,   109,   111,   113,   115,   119,   123,
     127,   131,   135,   139,   143,   147,   151,   155,   159,   163,
     167,   170,   178,   189,   193,   195,   199,   203,   210,   216,
     226,   232,   241,   243,   248,   252,   259,   260,   262,   264,
     268,   279,   292,   305,   320,   327,   335,   343,   351,   359,
     368,   378,   380,   384,   389,   396,   398,   400,   402,   404,
     408,   419,   431,   444
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      85,     0,    -1,    -1,    84,    -1,     9,    -1,    84,     9,
      -1,    83,    34,     8,    84,    89,    61,    84,    86,    23,
      84,    89,    38,    83,    -1,    -1,    87,    -1,    88,    -1,
      87,    88,    -1,    92,    84,    -1,    93,    -1,    94,    -1,
     100,    -1,   101,    -1,   102,    -1,   107,    -1,    -1,    90,
      -1,    91,    -1,    90,    91,    -1,   103,    -1,   108,    -1,
       3,    -1,     4,    -1,     8,    -1,     8,    77,    98,    76,
      -1,    54,    78,    57,    77,    76,    -1,    54,    78,    58,
      77,    76,    -1,    54,    78,    55,    77,    92,    76,    -1,
      54,    78,    55,    77,    76,    -1,    54,    78,    56,    77,
      92,    76,    -1,    54,    78,    56,    77,    76,    -1,     5,
      -1,     7,    -1,     6,    -1,    92,    62,    92,    -1,    92,
      69,    92,    -1,    92,    70,    92,    -1,    92,    71,    92,
      -1,    92,    72,    92,    -1,    92,    74,    92,    -1,    92,
      63,    92,    -1,    92,    64,    92,    -1,    92,    68,    92,
      -1,    92,    67,    92,    -1,    92,    66,    92,    -1,    92,
      65,    92,    -1,    77,    92,    76,    -1,    70,    92,    -1,
      12,    92,    13,    84,    86,    16,    84,    -1,    12,    92,
      13,    84,    86,    14,    84,    86,    16,    84,    -1,    10,
      95,    84,    -1,    96,    -1,    95,    79,    96,    -1,     8,
      11,   106,    -1,     8,    77,     5,    76,    11,   106,    -1,
       8,    11,   106,    62,    92,    -1,     8,    77,    76,    11,
     106,    62,    80,    99,    81,    -1,     8,    79,    97,    11,
     106,    -1,     8,    77,     5,    76,    79,    97,    11,   106,
      -1,     8,    -1,     8,    77,     5,    76,    -1,    97,    79,
       8,    -1,    97,    79,     8,    77,     5,    76,    -1,    -1,
      99,    -1,    92,    -1,    99,    79,    92,    -1,    43,     8,
      62,    92,    44,    92,    84,    86,    45,    84,    -1,    43,
       8,    62,    92,    44,    92,    48,    92,    84,    86,    45,
      84,    -1,    43,     8,    11,   106,    62,    92,    44,    92,
      84,    86,    45,    84,    -1,    43,     8,    11,   106,    62,
      92,    44,    92,    48,    92,    84,    86,    45,    84,    -1,
      32,    92,    84,    86,    40,    84,    -1,    35,    32,    92,
      84,    86,    41,    84,    -1,    35,    33,    92,    84,    86,
      41,    84,    -1,    35,    84,    86,    41,    32,    92,    84,
      -1,    35,    84,    86,    41,    33,    92,    84,    -1,    22,
       8,    77,    76,    84,    86,    23,    84,    -1,    22,     8,
      77,   104,    76,    84,    86,    23,    84,    -1,   105,    -1,
     104,    79,   105,    -1,    18,     8,    11,   106,    -1,    19,
       8,    77,    76,    11,   106,    -1,    50,    -1,    53,    -1,
      51,    -1,    52,    -1,    20,    92,    84,    -1,    17,     8,
      77,    76,    11,   106,    84,    86,    21,    84,    -1,    17,
       8,    77,   104,    76,    11,   106,    84,    86,    21,    84,
      -1,    17,     8,    77,    76,    11,   106,    77,    76,    84,
      86,    21,    84,    -1,    17,     8,    77,   104,    76,    11,
     106,    77,    76,    84,    86,    21,    84,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   186,   189,   190,   193,   196,   197,   200,
     201,   204,   205,   206,   207,   208,   209,   210,   213,   214,
     217,   218,   221,   222,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   254,   255,   258,   261,   262,   265,   266,   267,   268,
     269,   270,   273,   274,   275,   276,   279,   280,   283,   284,
     287,   288,   289,   290,   293,   296,   297,   298,   299,   302,
     303,   306,   307,   310,   311,   314,   315,   316,   317,   320,
     322,   323,   324,   325
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TRUE", "FALSE", "INT_CONST",
  "STRING_CONST", "CHAR_CONST", "ID", "ENDL", "DIM", "AS", "IF", "THEN",
  "ELSE", "ELSEIF", "END_IF", "FUNCTION", "BYVAL", "BYREF", "RETURN",
  "END_FUNCTION", "SUB", "END_SUB", "TRY", "CATCH", "END_TRY", "THROW",
  "NEW", "CASE", "CONST", "SELECT", "WHILE", "UNTIL", "MODULE", "DO",
  "ENUM", "END_ENUM", "END_MODULE", "END_SELECT", "END_WHILE", "LOOP",
  "FOR_EACH", "FOR", "TO", "NEXT", "IN", "MOD", "STEP", "EXCEPTION",
  "INTEGER", "CHAR", "STRING_T", "BOOLEAN", "CONSOLE", "WRITE",
  "WRITELINE", "READ", "READLINE", "SYSTEM", "FINALLY", "SUB_MAIN", "'='",
  "'>'", "'<'", "EQUAL", "NONEQUAL", "LESS_OR_EQUAL", "MORE_OR_EQUAL",
  "'+'", "'-'", "'*'", "'/'", "'\\\\'", "'^'", "UMINUS", "')'", "'('",
  "'.'", "','", "'{'", "'}'", "$accept", "ENDL_s", "ENDL_sE",
  "module_stmt", "stmt_list", "stmt_listE", "stmt", "decl_stmt_list",
  "decl_stmt_listE", "decl_stmt", "expr", "if_stmt", "dim_stmt",
  "as_expr_list", "as_expr", "id_list_stmt", "expr_list_empty",
  "expr_list", "for_stmt", "while_stmt", "do_loop_stmt", "sub_stmt",
  "param_list", "param_stmt", "param_type", "return_stmt", "func_stmt", 0
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
      45,    42,    47,    92,    94,   321,    41,    40,    46,    44,
     123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    83,    84,    84,    85,    86,    86,    87,
      87,    88,    88,    88,    88,    88,    88,    88,    89,    89,
      90,    90,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    93,    93,    94,    95,    95,    96,    96,    96,    96,
      96,    96,    97,    97,    97,    97,    98,    98,    99,    99,
     100,   100,   100,   100,   101,   102,   102,   102,   102,   103,
     103,   104,   104,   105,   105,   106,   106,   106,   106,   107,
     108,   108,   108,   108
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,    13,     0,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     4,     5,     5,
       6,     5,     6,     5,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     7,    10,     3,     1,     3,     3,     6,     5,     9,
       5,     8,     1,     4,     3,     6,     0,     1,     1,     3,
      10,    12,    12,    14,     6,     7,     7,     7,     7,     8,
       9,     1,     3,     4,     6,     1,     1,     1,     1,     3,
      10,    11,    12,    13
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     4,     0,     3,     0,     0,     5,     1,     0,    18,
       0,     0,     0,    19,    20,    22,    23,     0,     0,     0,
      21,     0,     0,     7,     0,     0,     0,     0,    81,     0,
       0,    24,    25,    34,    36,    35,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     9,     0,
      12,    13,    14,    15,    16,    17,     0,     0,     0,     0,
       0,     7,     0,    66,     0,     0,    54,     0,     0,     0,
       0,     0,     7,     0,     0,    50,     0,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,    85,    87,    88,    86,     0,     0,
      82,     0,     7,    68,     0,    67,     0,     0,     0,     0,
      53,     0,    89,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,    18,    37,    43,    44,    48,    47,
      46,    45,    38,    39,    40,    41,    42,    83,     0,     0,
       7,     0,     0,     0,    27,     0,    56,     0,     0,    62,
       0,    55,     7,     0,     7,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,    79,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,     0,    33,     0,
      28,    29,     2,    84,     7,     0,     0,     0,    80,    58,
       0,     0,     0,     0,    60,    64,     0,     0,    74,     0,
       0,     0,     0,     0,     0,    30,    32,     6,     0,    90,
       7,     0,    57,     0,     0,    63,     0,     7,    51,    75,
      76,    77,    78,     0,     0,     7,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,    92,     0,    61,     0,
      65,     0,     0,     7,     7,     0,    93,    59,    52,     0,
       0,     0,    70,     7,     0,     0,     0,    72,    71,     0,
      73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    46,    47,    48,    12,    13,    14,
      49,    50,    51,    65,    66,   150,   104,   105,    52,    53,
      54,    15,    27,    28,    98,    55,    16
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -91
static const yytype_int16 yypact[] =
{
      17,   -91,     6,    21,    92,    86,   -91,   -91,    17,    82,
     103,   104,    56,    -7,   -91,   -91,   -91,    23,    49,    17,
     -91,    13,    52,   263,   124,   130,   128,   -17,   -91,    17,
      26,   -91,   -91,   -91,   -91,   -91,    64,   132,    31,    31,
      31,    -4,   134,    65,    31,    31,   121,   115,   -91,   329,
     -91,   -91,   -91,   -91,   -91,   -91,   135,    68,   -28,   141,
     -12,   263,    17,    31,     1,    -6,   -91,   342,   329,   329,
      31,    31,   263,   -10,    40,   -91,   384,    17,   -91,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    21,   -28,    72,   -91,   -91,   -91,   -91,     4,   -28,
     -91,   131,   263,   429,    77,    76,   -28,    -1,   148,   132,
      21,    17,    21,   263,   329,   329,   118,   -28,    31,    83,
      84,    87,    90,   -91,    82,   429,   -21,   -21,   -21,   -21,
     -21,   -21,   -16,   -16,    94,    94,   -91,   -91,   159,    96,
     263,     5,    17,   150,   -91,    31,   112,   102,   169,   106,
      -3,   -91,   263,   144,   263,   263,   -15,   127,   358,    39,
      60,   110,   114,   153,   -28,    17,   172,   119,   263,    21,
      17,   429,    31,     8,   -28,   189,   -28,   188,    63,    17,
     156,   168,    31,    31,    31,    31,   -91,   399,   -91,   414,
     -91,   -91,    17,   -91,   263,    17,    17,   190,    21,   429,
     -28,   148,   152,   136,   -91,   133,    17,    17,    21,    17,
      17,   329,   329,   371,   279,   -91,   -91,   -91,   194,    21,
     263,    17,   -91,     9,   149,   -91,   225,   263,    21,    21,
      21,    21,    21,    31,    31,   263,    17,   211,    21,   -28,
      31,   157,   218,   316,   329,   192,    21,    17,   -91,    50,
     -91,    17,    31,   263,   263,    17,    21,   -91,    21,   329,
     195,   196,    21,   263,    17,    17,   197,    21,    21,    17,
      21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,    53,    -8,   -91,    11,   -91,   201,   120,   -91,   236,
     137,   -91,   -91,   -91,   143,    57,   -91,    10,   -91,   -91,
     -91,   -91,   231,   199,   -90,   -91,   -91
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
       9,   117,   137,     1,   147,     1,    24,    25,   176,   141,
      10,    23,   106,     1,     1,    11,   146,   182,   183,   200,
     239,    61,    94,    95,    96,    97,     1,   157,    70,    71,
       6,    24,    25,    72,    31,    32,    33,    34,    35,    36,
       5,    91,    31,    32,    33,    34,    35,    36,    86,    87,
      88,    89,   118,    90,   102,    88,    89,   110,    90,    59,
     112,   113,    60,    31,    32,    33,    34,    35,    36,   124,
      24,    25,   101,   109,   193,   148,   177,   206,   107,   207,
     108,   139,   167,   116,   202,    43,   204,   201,   177,    26,
     140,     6,     7,    43,     8,   119,   120,   121,   122,    10,
      21,    44,    62,   152,    11,    60,   154,   155,    45,    44,
     222,    17,    18,   143,    43,   186,    45,    19,    31,    32,
      33,    34,    35,    36,   153,    37,    22,    38,    29,   145,
      44,   257,    56,   168,   169,    39,   188,    45,    57,    58,
      64,    63,    73,    74,    77,    93,    92,    40,   138,   248,
      41,   166,    99,   144,   142,   145,   149,   194,    42,   156,
     159,   160,   198,   178,   161,   180,   181,   162,    90,    43,
     164,   208,   165,   170,   172,    67,    68,    69,   173,   197,
     174,    75,    76,   175,   179,    44,   190,   219,   220,   184,
     191,   192,    45,   195,   203,   196,   205,   209,   227,   228,
     103,   229,   230,   231,   232,   218,   235,   114,   115,   210,
     226,   221,   225,   238,   224,   236,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   246,   240,
     241,   237,   247,   250,   251,   253,   254,   255,   242,   256,
     264,   265,   269,   258,   163,   217,   245,   262,    78,    20,
     249,   263,   151,    30,     0,   158,   267,   268,   223,   100,
       0,   270,     0,     0,   260,   261,    31,    32,    33,    34,
      35,    36,     6,    37,   266,    38,     0,     0,     0,     0,
       0,     0,   171,    39,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,    40,   187,   189,    41,     0,
       0,     0,     0,     0,     0,     0,    42,     0,     0,   199,
       0,     0,     0,     0,     0,     0,     0,    43,     0,   211,
     212,   213,   214,     0,     0,     1,     0,   234,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     1,     0,
      45,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,    90,     0,   111,     0,     0,     0,     0,
       0,     0,     0,     0,   252,     0,     0,     0,     0,     0,
     243,   244,     0,     0,     0,     0,     0,   103,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   259,
      90,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,   185,    90,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   233,    90,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,    90,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,    90,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,    90,     0,
     123,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,    90,     0,   215,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,    90,     0,
     216,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,    90
};

static const yytype_int16 yycheck[] =
{
       8,    11,    92,     9,     5,     9,    18,    19,    11,    99,
      17,    19,    11,     9,     9,    22,   106,    32,    33,    11,
      11,    29,    50,    51,    52,    53,     9,   117,    32,    33,
       9,    18,    19,    41,     3,     4,     5,     6,     7,     8,
      34,    49,     3,     4,     5,     6,     7,     8,    69,    70,
      71,    72,    62,    74,    62,    71,    72,    65,    74,    76,
      68,    69,    79,     3,     4,     5,     6,     7,     8,    77,
      18,    19,    61,    79,   164,    76,    79,    14,    77,    16,
      79,    77,    77,    72,   174,    54,   176,    79,    79,    76,
      98,     9,     0,    54,     8,    55,    56,    57,    58,    17,
      77,    70,    76,   111,    22,    79,   114,   115,    77,    70,
     200,     8,     8,   102,    54,    76,    77,    61,     3,     4,
       5,     6,     7,     8,   113,    10,    77,    12,    76,    79,
      70,    81,     8,   141,   142,    20,    76,    77,     8,    11,
       8,    77,     8,    78,    23,    77,    11,    32,    76,   239,
      35,   140,    11,    76,    23,    79,     8,   165,    43,    41,
      77,    77,   170,   152,    77,   154,   155,    77,    74,    54,
      11,   179,    76,    23,    62,    38,    39,    40,    76,   168,
      11,    44,    45,    77,    40,    70,    76,   195,   196,    62,
      76,    38,    77,    21,     5,    76,     8,    41,   206,   207,
      63,   209,   210,   211,   212,   194,   214,    70,    71,    41,
      77,    21,    76,   221,    62,    21,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   236,    80,
       5,   220,    21,    76,    16,   243,   244,    45,   227,   247,
      45,    45,    45,   251,   124,   192,   235,   255,    47,    13,
     240,   259,   109,    22,    -1,   118,   264,   265,   201,    60,
      -1,   269,    -1,    -1,   253,   254,     3,     4,     5,     6,
       7,     8,     9,    10,   263,    12,    -1,    -1,    -1,    -1,
      -1,    -1,   145,    20,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    32,   159,   160,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,   182,
     183,   184,   185,    -1,    -1,     9,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,     9,    -1,
      77,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    -1,    74,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
     233,   234,    -1,    -1,    -1,    -1,    -1,   240,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,   252,
      74,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    44,    74,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    44,    74,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    -1,    74,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    -1,    74,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    -1,    74,    -1,
      76,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    -1,    74,    -1,    76,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    -1,    74,    -1,
      76,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    -1,    74
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    83,    84,    85,    34,     9,     0,     8,    84,
      17,    22,    89,    90,    91,   103,   108,     8,     8,    61,
      91,    77,    77,    84,    18,    19,    76,   104,   105,    76,
     104,     3,     4,     5,     6,     7,     8,    10,    12,    20,
      32,    35,    43,    54,    70,    77,    86,    87,    88,    92,
      93,    94,   100,   101,   102,   107,     8,     8,    11,    76,
      79,    84,    76,    77,     8,    95,    96,    92,    92,    92,
      32,    33,    84,     8,    78,    92,    92,    23,    88,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      74,    84,    11,    77,    50,    51,    52,    53,   106,    11,
     105,    86,    84,    92,    98,    99,    11,    77,    79,    79,
      84,    13,    84,    84,    92,    92,    86,    11,    62,    55,
      56,    57,    58,    76,    84,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,   106,    76,    77,
      84,   106,    23,    86,    76,    79,   106,     5,    76,     8,
      97,    96,    84,    86,    84,    84,    41,   106,    92,    77,
      77,    77,    77,    89,    11,    76,    86,    77,    84,    84,
      23,    92,    62,    76,    11,    77,    11,    79,    86,    40,
      86,    86,    32,    33,    62,    44,    76,    92,    76,    92,
      76,    76,    38,   106,    84,    21,    76,    86,    84,    92,
      11,    79,   106,     5,   106,     8,    14,    16,    84,    41,
      41,    92,    92,    92,    92,    76,    76,    83,    86,    84,
      84,    21,   106,    97,    62,    76,    77,    84,    84,    84,
      84,    84,    84,    44,    48,    84,    21,    86,    84,    11,
      80,     5,    86,    92,    92,    86,    84,    21,   106,    99,
      76,    16,    48,    84,    84,    45,    84,    81,    84,    92,
      86,    86,    84,    84,    45,    45,    86,    84,    84,    45,
      84
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
        case 6:

/* Line 1455 of yacc.c  */
#line 193 "vb_lark.y"
    {(yyval.Module) = root = create_VB_Module_stmt((yyvsp[(3) - (13)].Id),(yyvsp[(8) - (13)].List),(yyvsp[(5) - (13)].Decl_l),(yyvsp[(11) - (13)].Decl_l));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 196 "vb_lark.y"
    {(yyval.List) = create_VB_Stmt_list(0);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 200 "vb_lark.y"
    {(yyval.List) = create_VB_Stmt_list((yyvsp[(1) - (1)].Stmt));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 201 "vb_lark.y"
    {(yyval.List) = edit_VB_Stmt_list((yyvsp[(1) - (2)].List),(yyvsp[(2) - (2)].Stmt));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 204 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Expr((yyvsp[(1) - (2)].Expr));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 205 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_If((yyvsp[(1) - (1)].If_stmt));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 206 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Dim((yyvsp[(1) - (1)].Dim));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 207 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_For((yyvsp[(1) - (1)].For));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 208 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_While((yyvsp[(1) - (1)].While));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 209 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Do_Loop((yyvsp[(1) - (1)].Do_loop));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 210 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Return((yyvsp[(1) - (1)].Ret));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 213 "vb_lark.y"
    {(yyval.Decl_l) = create_VB_Decl_stmt_list(0);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 217 "vb_lark.y"
    {(yyval.Decl_l) = create_VB_Decl_stmt_list((yyvsp[(1) - (1)].Decl));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 218 "vb_lark.y"
    {(yyval.Decl_l) = edit_VB_Decl_stmt_list((yyvsp[(1) - (2)].Decl_l),(yyvsp[(2) - (2)].Decl));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 221 "vb_lark.y"
    {(yyval.Decl) = create_VB_Decl_Sub((yyvsp[(1) - (1)].Sub));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 222 "vb_lark.y"
    {(yyval.Decl) = create_VB_Decl_Func((yyvsp[(1) - (1)].Func));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 225 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(EXPR_BOOLEAN_CONST,1);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 226 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(EXPR_BOOLEAN_CONST,0);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 227 "vb_lark.y"
    {(yyval.Expr) = create_id_expr((yyvsp[(1) - (1)].Id));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 228 "vb_lark.y"
    {(yyval.Expr) = create_brackets_actions((yyvsp[(1) - (4)].Id),(yyvsp[(3) - (4)].Expr_l));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 229 "vb_lark.y"
    {(yyval.Expr) = create_Read();;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 230 "vb_lark.y"
    {(yyval.Expr) = create_Readln();;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 231 "vb_lark.y"
    {(yyval.Expr) = create_Print((yyvsp[(5) - (6)].Expr));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 232 "vb_lark.y"
    {(yyval.Expr) = create_Print(NULL);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 233 "vb_lark.y"
    {(yyval.Expr) = create_Println((yyvsp[(5) - (6)].Expr));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 234 "vb_lark.y"
    {(yyval.Expr) = create_Println(NULL);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 235 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(EXPR_INT_CONST,(yyvsp[(1) - (1)].i_const));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 236 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(EXPR_CHAR_CONST,(yyvsp[(1) - (1)].c_const));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 237 "vb_lark.y"
    {(yyval.Expr) = create_string_const_expr((yyvsp[(1) - (1)].s_const));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 238 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(EXPR_ASSIGN,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 239 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(EXPR_PLUS,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 240 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(EXPR_MINUS,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 241 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(EXPR_MUL,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 242 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(EXPR_DIV,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 243 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(EXPR_POWER,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 244 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(EXPR_MORE,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 245 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(EXPR_LESS,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 246 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(EXPR_MORE_OR_EQUAL,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 247 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(EXPR_LESS_OR_EQUAL,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 248 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(EXPR_NONEQUAL,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 249 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(EXPR_EQUAL,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 250 "vb_lark.y"
    {(yyval.Expr) = (yyvsp[(2) - (3)].Expr);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 251 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(EXPR_UMINUS,(yyvsp[(2) - (2)].Expr),0);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 254 "vb_lark.y"
    {(yyval.If_stmt) = create_if_stmt(0,(yyvsp[(2) - (7)].Expr),(yyvsp[(5) - (7)].List),NULL);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 255 "vb_lark.y"
    {(yyval.If_stmt) = create_if_stmt(1,(yyvsp[(2) - (10)].Expr),(yyvsp[(5) - (10)].List),(yyvsp[(8) - (10)].List));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 258 "vb_lark.y"
    {(yyval.Dim) = create_dim_stmt((yyvsp[(2) - (3)].As_l));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 261 "vb_lark.y"
    {(yyval.As_l) = create_as_expr_list((yyvsp[(1) - (1)].As_expr_str));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 262 "vb_lark.y"
    {(yyval.As_l) = add_to_as_expr_list((yyvsp[(1) - (3)].As_l),(yyvsp[(3) - (3)].As_expr_str));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 265 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr_init((yyvsp[(1) - (3)].Id),(yyvsp[(3) - (3)].Id_type),NULL);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 266 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_array((yyvsp[(1) - (6)].Id),(yyvsp[(3) - (6)].i_const),(yyvsp[(6) - (6)].Id_type));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 267 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr_init((yyvsp[(1) - (5)].Id),(yyvsp[(3) - (5)].Id_type),(yyvsp[(5) - (5)].Expr));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 268 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_array_init((yyvsp[(1) - (9)].Id),(yyvsp[(5) - (9)].Id_type),(yyvsp[(8) - (9)].Expr_l));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 269 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr_id((yyvsp[(1) - (5)].Id),(yyvsp[(3) - (5)].Id_l),(yyvsp[(5) - (5)].Id_type));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 270 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr_arr((yyvsp[(1) - (8)].Id),(yyvsp[(3) - (8)].i_const),(yyvsp[(6) - (8)].Id_l),(yyvsp[(8) - (8)].Id_type));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 273 "vb_lark.y"
    {(yyval.Id_l) = create_id_list((yyvsp[(1) - (1)].Id),0,0);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 274 "vb_lark.y"
    {(yyval.Id_l) = create_id_list((yyvsp[(1) - (4)].Id),1,(yyvsp[(3) - (4)].i_const));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 275 "vb_lark.y"
    {(yyval.Id_l) = add_to_id_list((yyvsp[(1) - (3)].Id_l),(yyvsp[(3) - (3)].Id),0,0);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 276 "vb_lark.y"
    {(yyval.Id_l) = add_to_id_list((yyvsp[(1) - (6)].Id_l),(yyvsp[(3) - (6)].Id),1,(yyvsp[(5) - (6)].i_const));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 279 "vb_lark.y"
    {(yyval.Expr_l) = create_Expr_list(NULL);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 283 "vb_lark.y"
    {(yyval.Expr_l) = create_Expr_list((yyvsp[(1) - (1)].Expr));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 284 "vb_lark.y"
    {(yyval.Expr_l) = add_Expr_to_list((yyvsp[(1) - (3)].Expr_l),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 287 "vb_lark.y"
    {(yyval.For) = create_for_stmt((yyvsp[(2) - (10)].Id),(yyvsp[(4) - (10)].Expr),(yyvsp[(6) - (10)].Expr),(yyvsp[(8) - (10)].List));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 288 "vb_lark.y"
    {(yyval.For) = create_for_with_step_stmt((yyvsp[(2) - (12)].Id),(yyvsp[(4) - (12)].Expr),(yyvsp[(6) - (12)].Expr),(yyvsp[(8) - (12)].Expr),(yyvsp[(10) - (12)].List));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 289 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_stmt((yyvsp[(2) - (12)].Id),DATA_INTEGER,(yyvsp[(6) - (12)].Expr),(yyvsp[(8) - (12)].Expr),(yyvsp[(10) - (12)].List));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 290 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_with_step_stmt((yyvsp[(2) - (14)].Id),DATA_INTEGER,(yyvsp[(6) - (14)].Expr),(yyvsp[(8) - (14)].Expr),(yyvsp[(10) - (14)].Expr),(yyvsp[(12) - (14)].List));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 293 "vb_lark.y"
    {(yyval.While) = create_while_stmt((yyvsp[(2) - (6)].Expr),(yyvsp[(4) - (6)].List));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 296 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(0,(yyvsp[(3) - (7)].Expr),(yyvsp[(5) - (7)].List));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 297 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(1,(yyvsp[(3) - (7)].Expr),(yyvsp[(5) - (7)].List));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 298 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(2,(yyvsp[(6) - (7)].Expr),(yyvsp[(3) - (7)].List));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 299 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(3,(yyvsp[(6) - (7)].Expr),(yyvsp[(3) - (7)].List));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 302 "vb_lark.y"
    {(yyval.Sub) = create_sub_stmt((yyvsp[(2) - (8)].Id),NULL,(yyvsp[(6) - (8)].List));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 303 "vb_lark.y"
    {(yyval.Sub) = create_sub_stmt((yyvsp[(2) - (9)].Id),(yyvsp[(4) - (9)].Param_l),(yyvsp[(7) - (9)].List));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 306 "vb_lark.y"
    {(yyval.Param_l) = create_param_list((yyvsp[(1) - (1)].Param));;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 307 "vb_lark.y"
    {(yyval.Param_l) = add_to_param_list((yyvsp[(1) - (3)].Param_l),(yyvsp[(3) - (3)].Param));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 310 "vb_lark.y"
    {(yyval.Param) = create_param_stmt(0,(yyvsp[(2) - (4)].Id),(yyvsp[(4) - (4)].Id_type));;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 311 "vb_lark.y"
    {(yyval.Param) = create_param_stmt(1,(yyvsp[(2) - (6)].Id),(yyvsp[(6) - (6)].Id_type));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 314 "vb_lark.y"
    {(yyval.Id_type) = DATA_INTEGER;;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 315 "vb_lark.y"
    {(yyval.Id_type) = DATA_BOOLEAN;;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 316 "vb_lark.y"
    {(yyval.Id_type) = DATA_CHAR;;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 317 "vb_lark.y"
    {(yyval.Id_type) = DATA_STRING;;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 320 "vb_lark.y"
    {(yyval.Ret) = create_return_stmt((yyvsp[(2) - (3)].Expr));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 322 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (10)].Id),NULL,(yyvsp[(6) - (10)].Id_type),(yyvsp[(8) - (10)].List));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 323 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (11)].Id),(yyvsp[(4) - (11)].Param_l),(yyvsp[(7) - (11)].Id_type),(yyvsp[(9) - (11)].List));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 324 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (12)].Id),NULL,(yyvsp[(6) - (12)].Id_type),(yyvsp[(10) - (12)].List));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 325 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (13)].Id),(yyvsp[(4) - (13)].Param_l),(yyvsp[(7) - (13)].Id_type),(yyvsp[(11) - (13)].List));;}
    break;



/* Line 1455 of yacc.c  */
#line 2372 "vb_lark.tab.c"
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
#line 328 "vb_lark.y"


void yyerror (char const* s)
{
	printf("%s\n",s);
	printf("ERROR on line: %d and column: %d", yylloc.first_line,yylloc.last_column);
	getchar();
	exit(0);
}

int get_location()
{
	return yylloc.first_line;
}

int main (int argc, char* argv[])
{
	FILE* file;

	file = fopen("result.txt", "wt");
	yyin = fopen(argv[1], "r");

	yyparse();

	print_tree();		// Вывод дерева

	fclose(file);
	getch();
	return 0;
}



/*	
if_stmt: IF expr THEN ENDL stmt_list end_if_stmt							
		   | IF expr ENDL stmt_list end_if_stmt									{$$ = create_with_Then_expr_stmt_list_end_if_stmt(1,$2,$4,$5);}
		   | IF expr THEN stmt_list_inline END_IF ENDL							{$$ = create_if_inline(2,$2,$4,0);}
		   | IF expr THEN stmt_list_inline ELSE stmt_list_inline END_IF ENDL	{$$ = create_if_inline(3,$2,$4,$6);}
		   ;

		stmt_list_inline: stmt									 {$$ = create_VB_Stmt_list($1);}
						| stmt_list_inline ':' stmt				 {$$ = edit_VB_Stmt_list($1,$3);}
						;

		end_if_stmt: END_IF ENDL								 {$$ = create_end_if_stmt(0,NULL,NULL,NULL);}
				   | ELSE ENDL stmt_list END_IF ENDL			 {$$ = create_end_if_stmt(1,NULL,$3,NULL);}
				   | ELSEIF expr THEN ENDL stmt_list end_if_stmt {$$ = create_end_if_stmt(2,$2,$5,$6);}
				   | ELSEIF expr ENDL stmt_list end_if_stmt		 {$$ = create_end_if_stmt(3,$2,$4,$5);}
				   ;
*/
