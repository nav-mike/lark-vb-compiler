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
	//struct VB_Array_expr*		Arr;
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
#define YYLAST   551

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNRULES -- Number of states.  */
#define YYNSTATES  312

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
       0,     0,     3,    15,    28,    29,    31,    33,    36,    39,
      41,    43,    45,    47,    49,    51,    53,    55,    56,    58,
      60,    63,    65,    67,    69,    71,    73,    75,    80,    86,
      92,    99,   105,   112,   118,   120,   122,   124,   128,   132,
     136,   140,   144,   148,   152,   156,   160,   164,   168,   172,
     176,   180,   183,   191,   202,   206,   208,   212,   216,   223,
     229,   239,   245,   254,   256,   261,   265,   272,   273,   275,
     277,   281,   292,   305,   318,   333,   340,   348,   356,   364,
     372,   379,   382,   386,   388,   392,   401,   411,   413,   417,
     422,   429,   431,   433,   435,   437,   441,   452,   464,   477,
     491,   502,   504,   507,   514
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      83,     0,    -1,    34,     8,     9,    87,    61,     9,    84,
      23,     9,    87,    38,    -1,    34,     8,     9,    87,    61,
       9,    84,    23,     9,    87,    38,     9,    -1,    -1,    85,
      -1,    86,    -1,    85,    86,    -1,    90,     9,    -1,    91,
      -1,    92,    -1,    98,    -1,    99,    -1,   100,    -1,   110,
      -1,   113,    -1,   108,    -1,    -1,    88,    -1,    89,    -1,
      88,    89,    -1,   101,    -1,   104,    -1,   109,    -1,     3,
      -1,     4,    -1,     8,    -1,     8,    77,    96,    76,    -1,
      54,    78,    57,    77,    76,    -1,    54,    78,    58,    77,
      76,    -1,    54,    78,    55,    77,    90,    76,    -1,    54,
      78,    55,    77,    76,    -1,    54,    78,    56,    77,    90,
      76,    -1,    54,    78,    56,    77,    76,    -1,     5,    -1,
       7,    -1,     6,    -1,    90,    62,    90,    -1,    90,    69,
      90,    -1,    90,    70,    90,    -1,    90,    71,    90,    -1,
      90,    72,    90,    -1,    90,    73,    90,    -1,    90,    74,
      90,    -1,    90,    63,    90,    -1,    90,    64,    90,    -1,
      90,    68,    90,    -1,    90,    67,    90,    -1,    90,    66,
      90,    -1,    90,    65,    90,    -1,    77,    90,    76,    -1,
      70,    90,    -1,    12,    90,    13,     9,    84,    16,     9,
      -1,    12,    90,    13,     9,    84,    14,     9,    84,    16,
       9,    -1,    10,    93,     9,    -1,    94,    -1,    93,    79,
      94,    -1,     8,    11,   107,    -1,     8,    77,     5,    76,
      11,   107,    -1,     8,    11,   107,    62,    90,    -1,     8,
      77,    76,    11,   107,    62,    80,    97,    81,    -1,     8,
      79,    95,    11,   107,    -1,     8,    77,     5,    76,    79,
      95,    11,   107,    -1,     8,    -1,     8,    77,     5,    76,
      -1,    95,    79,     8,    -1,    95,    79,     8,    77,     5,
      76,    -1,    -1,    97,    -1,    90,    -1,    97,    79,    90,
      -1,    43,     8,    62,    90,    44,    90,     9,    84,    45,
       9,    -1,    43,     8,    62,    90,    44,    90,    48,    90,
       9,    84,    45,     9,    -1,    43,     8,    11,   107,    62,
      90,    44,    90,     9,    84,    45,     9,    -1,    43,     8,
      11,   107,    62,    90,    44,    90,    48,    90,     9,    84,
      45,     9,    -1,    32,    90,     9,    84,    40,     9,    -1,
      35,    32,    90,     9,    84,    41,     9,    -1,    35,    33,
      90,     9,    84,    41,     9,    -1,    35,     9,    84,    41,
      32,    90,     9,    -1,    35,     9,    84,    41,    33,    90,
       9,    -1,    36,     8,     9,   102,    37,     9,    -1,   103,
       9,    -1,   102,   103,     9,    -1,     8,    -1,     8,    62,
       5,    -1,    22,     8,    77,    76,     9,    84,    23,     9,
      -1,    22,     8,    77,   105,    76,     9,    84,    23,     9,
      -1,   106,    -1,   105,    79,   106,    -1,    18,     8,    11,
     107,    -1,    19,     8,    77,    76,    11,   107,    -1,    50,
      -1,    53,    -1,    51,    -1,    52,    -1,    20,    90,     9,
      -1,    17,     8,    77,    76,    11,   107,     9,    84,    21,
       9,    -1,    17,     8,    77,   105,    76,    11,   107,     9,
      84,    21,     9,    -1,    17,     8,    77,    76,    11,   107,
      77,    76,     9,    84,    21,     9,    -1,    17,     8,    77,
     105,    76,    11,   107,    77,    76,     9,    84,    21,     9,
      -1,    24,     9,    84,   111,    60,     9,    84,     9,    26,
       9,    -1,   112,    -1,   111,   112,    -1,    25,     8,    11,
      49,     9,    84,    -1,    27,    28,    59,    78,    49,    77,
       6,    76,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   183,   183,   184,   187,   188,   191,   192,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   206,   207,   210,
     211,   214,   215,   216,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   249,   250,   253,   256,   257,   260,   261,   262,
     263,   264,   265,   268,   269,   270,   271,   274,   275,   278,
     279,   282,   283,   284,   285,   288,   291,   292,   293,   294,
     297,   300,   301,   304,   305,   308,   309,   312,   313,   316,
     317,   320,   321,   322,   323,   326,   328,   329,   330,   331,
     334,   337,   338,   341,   344
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
  "'.'", "','", "'{'", "'}'", "$accept", "module_stmt", "stmt_list",
  "stmt_listE", "stmt", "decl_stmt_list", "decl_stmt_listE", "decl_stmt",
  "expr", "if_stmt", "dim_stmt", "as_expr_list", "as_expr", "id_list_stmt",
  "expr_list_empty", "expr_list", "for_stmt", "while_stmt", "do_loop_stmt",
  "enum_stmt", "enum_expr_list", "enum_expr", "sub_stmt", "param_list",
  "param_stmt", "param_type", "return_stmt", "func_stmt", "try_catch_stmt",
  "catch_stmt_list", "catch_stmt", "throw_stmt", 0
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
       0,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    87,    87,    88,
      88,    89,    89,    89,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    92,    93,    93,    94,    94,    94,
      94,    94,    94,    95,    95,    95,    95,    96,    96,    97,
      97,    98,    98,    98,    98,    99,   100,   100,   100,   100,
     101,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   107,   107,   107,   108,   109,   109,   109,   109,
     110,   111,   111,   112,   113
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    11,    12,     0,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     4,     5,     5,
       6,     5,     6,     5,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     7,    10,     3,     1,     3,     3,     6,     5,
       9,     5,     8,     1,     4,     3,     6,     0,     1,     1,
       3,    10,    12,    12,    14,     6,     7,     7,     7,     7,
       6,     2,     3,     1,     3,     8,     9,     1,     3,     4,
       6,     1,     1,     1,     1,     3,    10,    11,    12,    13,
      10,     1,     2,     6,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    17,     0,     0,     0,     0,
      18,    19,    21,    22,    23,     0,     0,     0,     0,    20,
       0,     0,     0,     4,     0,     0,     0,     0,    87,     0,
       0,    83,     0,     0,    24,    25,    34,    36,    35,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     0,     9,    10,    11,    12,    13,
      16,    14,    15,     0,     0,     0,     0,     0,     4,     0,
       0,     0,     0,    81,    67,     0,     0,    55,     0,     0,
       4,     0,     0,     4,     0,     0,     0,     0,    51,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    93,
      94,    92,     0,     0,    88,     0,     4,    84,    80,    82,
      69,     0,    68,     0,     0,     0,    54,     0,     0,    95,
       0,     0,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,    17,    37,    44,    45,    49,    48,    47,
      46,    38,    39,    40,    41,    42,    43,    89,     0,     4,
       0,     0,     0,     0,    27,     0,    57,     0,     0,    63,
       0,    56,     4,     0,     0,   101,     0,     0,     0,     4,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     0,    85,     0,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,    33,     0,    28,    29,
       2,    90,     0,     4,     0,     0,    86,    59,     0,     0,
       0,     0,    61,    65,     0,     0,     0,     4,     0,    75,
       0,     0,     0,     0,     0,     0,    30,    32,     3,    96,
       0,     0,     4,    58,     0,     0,    64,     0,     4,    52,
       0,     0,     0,    78,    79,    76,    77,     0,     4,     0,
       0,    97,     0,     0,     0,     0,     0,     4,     0,     0,
       0,     0,     0,    98,     0,    62,     0,    66,     0,   103,
       0,   104,     4,     0,     0,     4,    99,    60,    53,   100,
       0,     0,    71,     0,     0,     4,     0,    73,     0,    72,
       0,    74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    51,    52,    53,     9,    10,    11,    54,    55,
      56,    76,    77,   170,   121,   122,    57,    58,    59,    12,
      32,    33,    13,    27,    28,   112,    60,    14,    61,   174,
     175,    62
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int16 yypact[] =
{
     -13,    18,    30,    36,  -101,    10,    33,    41,    58,    44,
      10,  -101,  -101,  -101,  -101,    25,    34,   123,   135,  -101,
      32,    49,   121,    77,   148,   150,   155,   -51,  -101,   160,
      51,   108,    -6,   166,  -101,  -101,  -101,  -101,  -101,   101,
     172,    69,    69,   173,   156,    69,    15,   175,   107,    69,
      69,   163,    77,  -101,   212,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,   178,   113,    85,   181,   103,    77,   198,
     204,   201,   202,  -101,    69,    -8,    20,  -101,   419,   225,
      77,   154,   239,    77,    69,    69,     3,    93,  -101,   445,
     205,  -101,  -101,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    85,   139,  -101,  -101,
    -101,  -101,    26,    85,  -101,   193,    77,  -101,  -101,  -101,
     384,   141,   140,    85,     2,   210,  -101,   172,   211,  -101,
     200,   145,    77,   183,   291,   305,    85,    69,   152,   153,
     158,   159,  -101,    10,   384,   -54,   -54,   -54,   -54,   -54,
     -54,    88,    88,   164,   164,   164,  -101,  -101,   216,    77,
     161,    29,   223,   217,  -101,    69,   177,   165,   231,   167,
       0,  -101,    77,   235,   -20,  -101,   196,   213,   120,    77,
      77,   188,   371,    87,   111,   179,   180,   219,    85,   230,
     245,    77,   182,  -101,   251,   384,    69,    28,    85,   310,
      85,   308,    -4,   306,   309,  -101,   242,   311,    69,    69,
     280,   281,    69,    69,  -101,   460,  -101,   475,  -101,  -101,
     314,  -101,   315,    77,   304,   317,  -101,   384,    85,   210,
     266,   253,  -101,   254,   321,   323,   284,    77,   328,  -101,
     318,   331,   326,   327,   432,   131,  -101,  -101,  -101,  -101,
     316,   329,    77,  -101,    31,   259,  -101,   336,    77,  -101,
     333,   334,   268,  -101,  -101,  -101,  -101,    69,    77,    69,
     337,  -101,   324,    85,    69,   271,   332,    77,   325,   340,
     199,   307,   357,  -101,   341,  -101,    95,  -101,   398,  -101,
     399,  -101,    77,    69,   400,    77,  -101,  -101,  -101,  -101,
     365,   397,  -101,   366,   403,    77,   404,  -101,   369,  -101,
     407,  -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,   -46,  -101,   420,   274,  -101,   408,   -41,  -101,
    -101,  -101,   346,   246,  -101,   203,  -101,  -101,  -101,  -101,
    -101,   442,  -101,   457,   412,  -100,  -101,  -101,  -101,  -101,
     361,  -101
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      78,    79,    31,   123,    82,   173,   157,   167,    88,    89,
     234,   200,   235,   161,   136,   100,   101,   102,   103,   104,
     105,     1,   115,   166,    83,    66,     3,     6,    67,   126,
       4,    71,     7,   120,   130,   159,   181,   133,   191,   228,
     204,    15,   273,   134,   135,     5,     8,    84,    85,    16,
      24,    25,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   137,    17,    24,    25,   124,
     163,   125,    34,    35,    36,    37,    38,    39,   168,   201,
      34,    35,    36,    37,    38,    39,   177,    40,   221,    41,
      34,    35,    36,    37,    38,    39,   182,    42,   230,   127,
     232,    43,    20,   160,    44,    18,   192,   229,    26,    45,
     201,    21,    46,   189,    34,    35,    36,    37,    38,    39,
      47,    24,    25,    48,   195,    29,   202,    69,   253,    31,
      67,    48,    22,   210,   211,   108,   109,   110,   111,    49,
     268,    48,   215,   217,    23,   224,    50,    49,   138,   139,
     140,   141,   208,   209,    50,   227,    63,    49,    64,   102,
     103,   104,   105,   214,    50,    48,    65,   240,   241,    68,
      70,   244,   245,   285,   165,    73,   297,   250,    74,   269,
      75,    49,    80,    86,    81,    87,    90,   216,    50,   106,
     107,   261,   113,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   272,   116,   292,   117,
     118,   119,   276,   131,   143,   158,   162,   164,   169,   165,
     172,    92,   281,   176,   178,   173,   280,   188,   282,   183,
     184,   289,   193,   120,   129,   185,   186,   190,   105,   196,
     194,   197,   198,   203,   199,   206,   300,   293,   132,   303,
     212,   222,   301,   207,   223,   218,   219,   220,   225,   308,
     226,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     179,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   180,   231,   233,   236,   237,   238,
     239,   242,   243,   248,   249,   251,   252,   263,   255,   256,
     258,   257,   259,   260,   262,   265,   266,   270,   271,   274,
     264,   275,   277,   278,   279,   284,   283,   287,   288,   291,
     296,   290,   294,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   295,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   305,   298,   299,   302,
     304,   306,   307,   309,   310,   213,   311,   187,    19,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   128,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    91,   171,    72,   254,   267,   286,    30,   114,
       0,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   142,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   205,   246,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   247
};

static const yytype_int16 yycheck[] =
{
      41,    42,     8,    11,    45,    25,   106,     5,    49,    50,
      14,    11,    16,   113,    11,    69,    70,    71,    72,    73,
      74,    34,    68,   123,     9,    76,     8,    17,    79,     9,
       0,    37,    22,    74,    80,     9,   136,    83,     9,    11,
      60,     8,    11,    84,    85,     9,    36,    32,    33,     8,
      18,    19,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,    62,     8,    18,    19,    77,
     116,    79,     3,     4,     5,     6,     7,     8,    76,    79,
       3,     4,     5,     6,     7,     8,   132,    10,   188,    12,
       3,     4,     5,     6,     7,     8,   137,    20,   198,    79,
     200,    24,    77,    77,    27,    61,    77,    79,    76,    32,
      79,    77,    35,   159,     3,     4,     5,     6,     7,     8,
      43,    18,    19,    54,   165,    76,   172,    76,   228,     8,
      79,    54,     9,   179,   180,    50,    51,    52,    53,    70,
       9,    54,   183,   184,     9,   191,    77,    70,    55,    56,
      57,    58,    32,    33,    77,   196,     8,    70,     8,    71,
      72,    73,    74,    76,    77,    54,    11,   208,   209,     9,
      62,   212,   213,   273,    79,     9,    81,   223,    77,    48,
       8,    70,     9,     8,    28,    78,    23,    76,    77,    11,
      77,   237,    11,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   252,     9,     9,     5,
       9,     9,   258,    59,     9,    76,    23,    76,     8,    79,
       9,     9,   268,    78,    41,    25,   267,    11,   269,    77,
      77,   277,     9,   274,     9,    77,    77,    76,    74,    62,
      23,    76,    11,     8,    77,    49,   292,    48,     9,   295,
      62,    21,   293,    40,     9,    76,    76,    38,    76,   305,
       9,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       9,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     9,     5,     8,    11,     9,    77,
       9,    41,    41,     9,     9,    21,     9,     9,    62,    76,
       9,    77,     9,    49,     6,     9,     9,    21,     9,    80,
       9,     5,     9,     9,    76,    21,     9,    76,    16,     9,
       9,    26,    45,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     9,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     9,     9,     9,     9,
      45,    45,     9,     9,    45,    44,     9,   143,    10,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    13,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    52,   127,    32,   229,    44,   274,    21,    67,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,   174,    76,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    83,     8,     0,     9,    17,    22,    36,    87,
      88,    89,   101,   104,   109,     8,     8,     8,    61,    89,
      77,    77,     9,     9,    18,    19,    76,   105,   106,    76,
     105,     8,   102,   103,     3,     4,     5,     6,     7,     8,
      10,    12,    20,    24,    27,    32,    35,    43,    54,    70,
      77,    84,    85,    86,    90,    91,    92,    98,    99,   100,
     108,   110,   113,     8,     8,    11,    76,    79,     9,    76,
      62,    37,   103,     9,    77,     8,    93,    94,    90,    90,
       9,    28,    90,     9,    32,    33,     8,    78,    90,    90,
      23,    86,     9,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    11,    77,    50,    51,
      52,    53,   107,    11,   106,    84,     9,     5,     9,     9,
      90,    96,    97,    11,    77,    79,     9,    79,    13,     9,
      84,    59,     9,    84,    90,    90,    11,    62,    55,    56,
      57,    58,    76,     9,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,   107,    76,     9,
      77,   107,    23,    84,    76,    79,   107,     5,    76,     8,
      95,    94,     9,    25,   111,   112,    78,    84,    41,     9,
       9,   107,    90,    77,    77,    77,    77,    87,    11,    84,
      76,     9,    77,     9,    23,    90,    62,    76,    11,    77,
      11,    79,    84,     8,    60,   112,    49,    40,    32,    33,
      84,    84,    62,    44,    76,    90,    76,    90,    76,    76,
      38,   107,    21,     9,    84,    76,     9,    90,    11,    79,
     107,     5,   107,     8,    14,    16,    11,     9,    77,     9,
      90,    90,    41,    41,    90,    90,    76,    76,     9,     9,
      84,    21,     9,   107,    95,    62,    76,    77,     9,     9,
      49,    84,     6,     9,     9,     9,     9,    44,     9,    48,
      21,     9,    84,    11,    80,     5,    84,     9,     9,    76,
      90,    84,    90,     9,    21,   107,    97,    76,    16,    84,
      26,     9,     9,    48,    45,     9,     9,    81,     9,     9,
      84,    90,     9,    84,    45,     9,    45,     9,    84,     9,
      45,     9
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
#line 183 "vb_lark.y"
    {(yyval.Module) = root = create_VB_Module_stmt((yyvsp[(2) - (11)].Id),(yyvsp[(7) - (11)].List),(yyvsp[(4) - (11)].Decl_l),(yyvsp[(10) - (11)].Decl_l));;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 184 "vb_lark.y"
    {(yyval.Module) = root = create_VB_Module_stmt((yyvsp[(2) - (12)].Id),(yyvsp[(7) - (12)].List),(yyvsp[(4) - (12)].Decl_l),(yyvsp[(10) - (12)].Decl_l));;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 187 "vb_lark.y"
    {(yyval.List) = create_VB_Stmt_list(0);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 191 "vb_lark.y"
    {(yyval.List) = create_VB_Stmt_list((yyvsp[(1) - (1)].Stmt));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 192 "vb_lark.y"
    {(yyval.List) = edit_VB_Stmt_list((yyvsp[(1) - (2)].List),(yyvsp[(2) - (2)].Stmt));;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 195 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Expr((yyvsp[(1) - (2)].Expr));;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 196 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_If((yyvsp[(1) - (1)].If_stmt));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 197 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Dim((yyvsp[(1) - (1)].Dim));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 198 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_For((yyvsp[(1) - (1)].For));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 199 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_While((yyvsp[(1) - (1)].While));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 200 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Do_Loop((yyvsp[(1) - (1)].Do_loop));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 201 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Try_Catch((yyvsp[(1) - (1)].Try_catch));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 202 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Throw((yyvsp[(1) - (1)].Throw));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 203 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Return((yyvsp[(1) - (1)].Ret));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 206 "vb_lark.y"
    {(yyval.Decl_l) = create_VB_Decl_stmt_list(0);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 210 "vb_lark.y"
    {(yyval.Decl_l) = create_VB_Decl_stmt_list((yyvsp[(1) - (1)].Decl));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 211 "vb_lark.y"
    {(yyval.Decl_l) = edit_VB_Decl_stmt_list((yyvsp[(1) - (2)].Decl_l),(yyvsp[(2) - (2)].Decl));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 214 "vb_lark.y"
    {(yyval.Decl) = create_VB_Decl_Enum((yyvsp[(1) - (1)].Enum));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 215 "vb_lark.y"
    {(yyval.Decl) = create_VB_Decl_Sub((yyvsp[(1) - (1)].Sub));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 216 "vb_lark.y"
    {(yyval.Decl) = create_VB_Decl_Func((yyvsp[(1) - (1)].Func));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 219 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(5,1);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 220 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(5,0);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 221 "vb_lark.y"
    {(yyval.Expr) = create_id_expr((yyvsp[(1) - (1)].Id));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 222 "vb_lark.y"
    {(yyval.Expr) = create_brackets_actions((yyvsp[(1) - (4)].Id),(yyvsp[(3) - (4)].Expr_l));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 223 "vb_lark.y"
    {(yyval.Expr) = create_Read();;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 224 "vb_lark.y"
    {(yyval.Expr) = create_Readln();;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 225 "vb_lark.y"
    {(yyval.Expr) = create_Print((yyvsp[(5) - (6)].Expr));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 226 "vb_lark.y"
    {(yyval.Expr) = create_Print(NULL);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 227 "vb_lark.y"
    {(yyval.Expr) = create_Println((yyvsp[(5) - (6)].Expr));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 228 "vb_lark.y"
    {(yyval.Expr) = create_Println(NULL);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 229 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(3,(yyvsp[(1) - (1)].i_const));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 230 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(2,(yyvsp[(1) - (1)].c_const));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 231 "vb_lark.y"
    {(yyval.Expr) = create_string_const_expr((yyvsp[(1) - (1)].s_const));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 232 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(6,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 233 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(7,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 234 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(8,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 235 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(9,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 236 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(11,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 237 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(10,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 238 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(12,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 239 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(13,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 240 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(14,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 241 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(15,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 242 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(16,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 243 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(17,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 244 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(18,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 245 "vb_lark.y"
    {(yyval.Expr) = (yyvsp[(2) - (3)].Expr);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 246 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(19,(yyvsp[(2) - (2)].Expr),0);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 249 "vb_lark.y"
    {(yyval.If_stmt) = create_if_stmt(0,(yyvsp[(2) - (7)].Expr),(yyvsp[(5) - (7)].List),NULL);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 250 "vb_lark.y"
    {(yyval.If_stmt) = create_if_stmt(1,(yyvsp[(2) - (10)].Expr),(yyvsp[(5) - (10)].List),(yyvsp[(8) - (10)].List));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 253 "vb_lark.y"
    {(yyval.Dim) = create_dim_stmt((yyvsp[(2) - (3)].As_l));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 256 "vb_lark.y"
    {(yyval.As_l) = create_as_expr_list((yyvsp[(1) - (1)].As_expr_str));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 257 "vb_lark.y"
    {(yyval.As_l) = add_to_as_expr_list((yyvsp[(1) - (3)].As_l),(yyvsp[(3) - (3)].As_expr_str));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 260 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr_init((yyvsp[(1) - (3)].Id),(yyvsp[(3) - (3)].Id_type),NULL);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 261 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_array((yyvsp[(1) - (6)].Id),(yyvsp[(3) - (6)].i_const),(yyvsp[(6) - (6)].Id_type));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 262 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr_init((yyvsp[(1) - (5)].Id),(yyvsp[(3) - (5)].Id_type),(yyvsp[(5) - (5)].Expr));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 263 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_array_init((yyvsp[(1) - (9)].Id),(yyvsp[(5) - (9)].Id_type),(yyvsp[(8) - (9)].Expr_l));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 264 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr_id((yyvsp[(1) - (5)].Id),(yyvsp[(3) - (5)].Id_l),(yyvsp[(5) - (5)].Id_type));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 265 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr_arr((yyvsp[(1) - (8)].Id),(yyvsp[(3) - (8)].i_const),(yyvsp[(6) - (8)].Id_l),(yyvsp[(8) - (8)].Id_type));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 268 "vb_lark.y"
    {(yyval.Id_l) = create_id_list((yyvsp[(1) - (1)].Id),0,0);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 269 "vb_lark.y"
    {(yyval.Id_l) = create_id_list((yyvsp[(1) - (4)].Id),1,(yyvsp[(3) - (4)].i_const));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 270 "vb_lark.y"
    {(yyval.Id_l) = add_to_id_list((yyvsp[(1) - (3)].Id_l),(yyvsp[(3) - (3)].Id),0,0);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 271 "vb_lark.y"
    {(yyval.Id_l) = add_to_id_list((yyvsp[(1) - (6)].Id_l),(yyvsp[(3) - (6)].Id),1,(yyvsp[(5) - (6)].i_const));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 274 "vb_lark.y"
    {(yyval.Expr_l) = create_Expr_list(NULL);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 278 "vb_lark.y"
    {(yyval.Expr_l) = create_Expr_list((yyvsp[(1) - (1)].Expr));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 279 "vb_lark.y"
    {(yyval.Expr_l) = add_Expr_to_list((yyvsp[(1) - (3)].Expr_l),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 282 "vb_lark.y"
    {(yyval.For) = create_for_stmt((yyvsp[(2) - (10)].Id),(yyvsp[(4) - (10)].Expr),(yyvsp[(6) - (10)].Expr),(yyvsp[(8) - (10)].List));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 283 "vb_lark.y"
    {(yyval.For) = create_for_with_step_stmt((yyvsp[(2) - (12)].Id),(yyvsp[(4) - (12)].Expr),(yyvsp[(6) - (12)].Expr),(yyvsp[(8) - (12)].Expr),(yyvsp[(10) - (12)].List));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 284 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_stmt((yyvsp[(2) - (12)].Id),INTEGER_E,(yyvsp[(6) - (12)].Expr),(yyvsp[(8) - (12)].Expr),(yyvsp[(10) - (12)].List));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 285 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_with_step_stmt((yyvsp[(2) - (14)].Id),INTEGER_E,(yyvsp[(6) - (14)].Expr),(yyvsp[(8) - (14)].Expr),(yyvsp[(10) - (14)].Expr),(yyvsp[(12) - (14)].List));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 288 "vb_lark.y"
    {(yyval.While) = create_while_stmt((yyvsp[(2) - (6)].Expr),(yyvsp[(4) - (6)].List));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 291 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(0,(yyvsp[(3) - (7)].Expr),(yyvsp[(5) - (7)].List));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 292 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(1,(yyvsp[(3) - (7)].Expr),(yyvsp[(5) - (7)].List));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 293 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(2,(yyvsp[(6) - (7)].Expr),(yyvsp[(3) - (7)].List));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 294 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(3,(yyvsp[(6) - (7)].Expr),(yyvsp[(3) - (7)].List));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 297 "vb_lark.y"
    {(yyval.Enum) = create_enum_stmt((yyvsp[(2) - (6)].Id),(yyvsp[(4) - (6)].Enum_l));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 300 "vb_lark.y"
    {(yyval.Enum_l) = create_enum_list((yyvsp[(1) - (2)].Enum_e));;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 301 "vb_lark.y"
    {(yyval.Enum_l) = add_to_enum_list((yyvsp[(1) - (3)].Enum_l),(yyvsp[(2) - (3)].Enum_e));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 304 "vb_lark.y"
    {(yyval.Enum_e) = create_enum_expr((yyvsp[(1) - (1)].Id),-1);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 305 "vb_lark.y"
    {(yyval.Enum_e) = create_enum_expr((yyvsp[(1) - (3)].Id),(yyvsp[(3) - (3)].i_const));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 308 "vb_lark.y"
    {(yyval.Sub) = create_sub_stmt((yyvsp[(2) - (8)].Id),NULL,(yyvsp[(6) - (8)].List));;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 309 "vb_lark.y"
    {(yyval.Sub) = create_sub_stmt((yyvsp[(2) - (9)].Id),(yyvsp[(4) - (9)].Param_l),(yyvsp[(7) - (9)].List));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 312 "vb_lark.y"
    {(yyval.Param_l) = create_param_list((yyvsp[(1) - (1)].Param));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 313 "vb_lark.y"
    {(yyval.Param_l) = add_to_param_list((yyvsp[(1) - (3)].Param_l),(yyvsp[(3) - (3)].Param));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 316 "vb_lark.y"
    {(yyval.Param) = create_param_stmt(0,(yyvsp[(2) - (4)].Id),(yyvsp[(4) - (4)].Id_type));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 317 "vb_lark.y"
    {(yyval.Param) = create_param_stmt(1,(yyvsp[(2) - (6)].Id),(yyvsp[(6) - (6)].Id_type));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 320 "vb_lark.y"
    {(yyval.Id_type) = INTEGER_E;;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 321 "vb_lark.y"
    {(yyval.Id_type) = BOOLEAN_E;;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 322 "vb_lark.y"
    {(yyval.Id_type) = CHAR_E;;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 323 "vb_lark.y"
    {(yyval.Id_type) = STRING_E;;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 326 "vb_lark.y"
    {(yyval.Ret) = create_return_stmt((yyvsp[(2) - (3)].Expr));;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 328 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (10)].Id),NULL,(yyvsp[(6) - (10)].Id_type),(yyvsp[(8) - (10)].List));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 329 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (11)].Id),(yyvsp[(4) - (11)].Param_l),(yyvsp[(7) - (11)].Id_type),(yyvsp[(9) - (11)].List));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 330 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (12)].Id),NULL,(yyvsp[(6) - (12)].Id_type),(yyvsp[(10) - (12)].List));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 331 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (13)].Id),(yyvsp[(4) - (13)].Param_l),(yyvsp[(7) - (13)].Id_type),(yyvsp[(11) - (13)].List));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 334 "vb_lark.y"
    {(yyval.Try_catch) = create_Try_Catch((yyvsp[(3) - (10)].List),(yyvsp[(4) - (10)].Catch_l),(yyvsp[(7) - (10)].List));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 337 "vb_lark.y"
    {(yyval.Catch_l) = create_Catch_stmt_list((yyvsp[(1) - (1)].Catch));;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 338 "vb_lark.y"
    {(yyval.Catch_l) = add_new_Catch_stmt((yyvsp[(1) - (2)].Catch_l),(yyvsp[(2) - (2)].Catch));;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 341 "vb_lark.y"
    {(yyval.Catch) = create_Catch_stmt((yyvsp[(2) - (6)].Id),(yyvsp[(6) - (6)].List));;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 344 "vb_lark.y"
    {(yyval.Throw) = create_Throw((yyvsp[(7) - (9)].s_const));;}
    break;



/* Line 1455 of yacc.c  */
#line 2511 "vb_lark.tab.c"
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
#line 346 "vb_lark.y"


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
