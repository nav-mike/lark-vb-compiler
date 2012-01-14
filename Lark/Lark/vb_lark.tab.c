#include "stdafx.h"
/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

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
#line 88 "vb_lark.tab.c"

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
     BYREF = 273,
     RETURN = 274,
     END_FUNCTION = 275,
     SUB = 276,
     END_SUB = 277,
     TRY = 278,
     CATCH = 279,
     END_TRY = 280,
     THROW = 281,
     NEW = 282,
     CASE = 283,
     CONST = 284,
     SELECT = 285,
     WHILE = 286,
     UNTIL = 287,
     MODULE = 288,
     DO = 289,
     ENUM = 290,
     END_ENUM = 291,
     END_MODULE = 292,
     END_SELECT = 293,
     END_WHILE = 294,
     LOOP = 295,
     FOR_EACH = 296,
     FOR = 297,
     TO = 298,
     NEXT = 299,
     IN = 300,
     MOD = 301,
     STEP = 302,
     EXCEPTION = 303,
     INTEGER = 304,
     CHAR = 305,
     STRING_T = 306,
     BOOLEAN = 307,
     CONSOLE = 308,
     WRITE = 309,
     WRITELINE = 310,
     READ = 311,
     READLINE = 312,
     SYSTEM = 313,
     FINALLY = 314,
     TRUE = 315,
     FALSE = 316,
     SUB_MAIN = 317,
     EQUAL = 318,
     NONEQUAL = 319,
     LESS_OR_EQUAL = 320,
     MORE_OR_EQUAL = 321,
     UMINUS = 322
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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#define YYLAST   528

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNRULES -- Number of states.  */
#define YYNSTATES  300

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      78,    77,    72,    70,    80,    71,    79,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      65,    63,    64,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    74,     2,    75,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    66,    67,
      68,    69,    76
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    15,    28,    29,    31,    33,    36,    39,
      41,    43,    45,    47,    49,    51,    53,    55,    57,    59,
      60,    62,    64,    67,    69,    71,    73,    75,    80,    86,
      92,    94,    96,    98,   100,   104,   108,   112,   116,   120,
     124,   128,   132,   136,   140,   144,   148,   152,   156,   159,
     167,   178,   182,   184,   186,   190,   194,   198,   204,   206,
     210,   217,   218,   220,   222,   226,   237,   250,   263,   278,
     285,   293,   301,   309,   317,   324,   327,   331,   333,   337,
     346,   356,   358,   362,   367,   374,   376,   378,   380,   382,
     386,   397,   409,   422,   436,   447,   449,   452,   459,   469,
     477,   484,   492
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      82,     0,    -1,    33,     7,     8,    86,    62,     8,    83,
      22,     8,    86,    37,    -1,    33,     7,     8,    86,    62,
       8,    83,    22,     8,    86,    37,     8,    -1,    -1,    84,
      -1,    85,    -1,    84,    85,    -1,    89,     8,    -1,    90,
      -1,    91,    -1,    98,    -1,    99,    -1,   100,    -1,   110,
      -1,   113,    -1,   114,    -1,   115,    -1,   108,    -1,    -1,
      87,    -1,    88,    -1,    87,    88,    -1,   101,    -1,   104,
      -1,   109,    -1,     7,    -1,     7,    78,    96,    77,    -1,
      53,    79,    56,    78,    77,    -1,    53,    79,    57,    78,
      77,    -1,     4,    -1,     6,    -1,     5,    -1,     3,    -1,
      89,    63,    89,    -1,    89,    70,    89,    -1,    89,    71,
      89,    -1,    89,    72,    89,    -1,    89,    73,    89,    -1,
      89,    74,    89,    -1,    89,    75,    89,    -1,    89,    64,
      89,    -1,    89,    65,    89,    -1,    89,    69,    89,    -1,
      89,    68,    89,    -1,    89,    67,    89,    -1,    89,    66,
      89,    -1,    78,    89,    77,    -1,    71,    89,    -1,    11,
      89,    12,     8,    83,    15,     8,    -1,    11,    89,    12,
       8,    83,    13,     8,    83,    15,     8,    -1,     9,    92,
       8,    -1,    93,    -1,    95,    -1,    92,    80,    93,    -1,
      92,    80,    95,    -1,    94,    10,   107,    -1,    94,    10,
     107,    63,    89,    -1,     7,    -1,    94,    80,     7,    -1,
       7,    78,     4,    77,    10,   107,    -1,    -1,    97,    -1,
      89,    -1,    97,    80,    89,    -1,    42,     7,    63,    89,
      43,    89,     8,    83,    44,     8,    -1,    42,     7,    63,
      89,    43,    89,    47,    89,     8,    83,    44,     8,    -1,
      42,     7,    10,   107,    63,    89,    43,    89,     8,    83,
      44,     8,    -1,    42,     7,    10,   107,    63,    89,    43,
      89,    47,    89,     8,    83,    44,     8,    -1,    31,    89,
       8,    83,    39,     8,    -1,    34,    31,    89,     8,    83,
      40,     8,    -1,    34,    32,    89,     8,    83,    40,     8,
      -1,    34,     8,    83,    40,    31,    89,     8,    -1,    34,
       8,    83,    40,    32,    89,     8,    -1,    35,     7,     8,
     102,    36,     8,    -1,   103,     8,    -1,   102,   103,     8,
      -1,     7,    -1,     7,    63,     4,    -1,    21,     7,    78,
      77,     8,    83,    22,     8,    -1,    21,     7,    78,   105,
      77,     8,    83,    22,     8,    -1,   106,    -1,   105,    80,
     106,    -1,    17,     7,    10,   107,    -1,    18,     7,    78,
      77,    10,   107,    -1,    49,    -1,    52,    -1,    50,    -1,
      51,    -1,    19,    89,     8,    -1,    16,     7,    78,    77,
      10,   107,     8,    83,    20,     8,    -1,    16,     7,    78,
     105,    77,    10,   107,     8,    83,    20,     8,    -1,    16,
       7,    78,    77,    10,   107,    78,    77,     8,    83,    20,
       8,    -1,    16,     7,    78,   105,    77,    10,   107,    78,
      77,     8,    83,    20,     8,    -1,    23,     8,    83,   111,
      59,     8,    83,     8,    25,     8,    -1,   112,    -1,   111,
     112,    -1,    24,     7,    10,    48,     8,    83,    -1,    26,
      27,    58,    79,    48,    78,     5,    77,     8,    -1,    53,
      79,    54,    78,    89,    77,     8,    -1,    53,    79,    54,
      78,    77,     8,    -1,    53,    79,    55,    78,    89,    77,
       8,    -1,    53,    79,    55,    78,    77,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   184,   184,   185,   188,   189,   192,   193,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   209,
     210,   213,   214,   217,   218,   219,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   247,
     248,   251,   254,   255,   256,   257,   260,   261,   264,   265,
     268,   271,   272,   275,   276,   279,   280,   281,   282,   285,
     288,   289,   290,   291,   294,   297,   298,   301,   302,   305,
     306,   309,   310,   313,   314,   317,   318,   319,   320,   323,
     325,   326,   327,   328,   331,   334,   335,   338,   341,   344,
     345,   348,   349
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOLEAN_CONST", "INT_CONST",
  "STRING_CONST", "CHAR_CONST", "ID", "ENDL", "DIM", "AS", "IF", "THEN",
  "ELSE", "ELSEIF", "END_IF", "FUNCTION", "BYVAL", "BYREF", "RETURN",
  "END_FUNCTION", "SUB", "END_SUB", "TRY", "CATCH", "END_TRY", "THROW",
  "NEW", "CASE", "CONST", "SELECT", "WHILE", "UNTIL", "MODULE", "DO",
  "ENUM", "END_ENUM", "END_MODULE", "END_SELECT", "END_WHILE", "LOOP",
  "FOR_EACH", "FOR", "TO", "NEXT", "IN", "MOD", "STEP", "EXCEPTION",
  "INTEGER", "CHAR", "STRING_T", "BOOLEAN", "CONSOLE", "WRITE",
  "WRITELINE", "READ", "READLINE", "SYSTEM", "FINALLY", "TRUE", "FALSE",
  "SUB_MAIN", "'='", "'>'", "'<'", "EQUAL", "NONEQUAL", "LESS_OR_EQUAL",
  "MORE_OR_EQUAL", "'+'", "'-'", "'*'", "'/'", "'\\\\'", "'^'", "UMINUS",
  "')'", "'('", "'.'", "','", "$accept", "module_stmt", "stmt_list",
  "stmt_listE", "stmt", "decl_stmt_list", "decl_stmt_listE", "decl_stmt",
  "expr", "if_stmt", "dim_stmt", "as_expr_list", "as_expr", "id_list_stmt",
  "array_expr", "expr_list_empty", "expr_list", "for_stmt", "while_stmt",
  "do_loop_stmt", "enum_stmt", "enum_expr_list", "enum_expr", "sub_stmt",
  "param_list", "param_stmt", "param_type", "return_stmt", "func_stmt",
  "try_catch_stmt", "catch_stmt_list", "catch_stmt", "throw_stmt",
  "console_print_stmt", "console_println_stmt", 0
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
     315,   316,   317,    61,    62,    60,   318,   319,   320,   321,
      43,    45,    42,    47,    92,    94,   322,    41,    40,    46,
      44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    86,
      86,    87,    87,    88,    88,    88,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    90,
      90,    91,    92,    92,    92,    92,    93,    93,    94,    94,
      95,    96,    96,    97,    97,    98,    98,    98,    98,    99,
     100,   100,   100,   100,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   107,   107,   108,
     109,   109,   109,   109,   110,   111,   111,   112,   113,   114,
     114,   115,   115
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    11,    12,     0,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     2,     1,     1,     1,     1,     4,     5,     5,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     7,
      10,     3,     1,     1,     3,     3,     3,     5,     1,     3,
       6,     0,     1,     1,     3,    10,    12,    12,    14,     6,
       7,     7,     7,     7,     6,     2,     3,     1,     3,     8,
       9,     1,     3,     4,     6,     1,     1,     1,     1,     3,
      10,    11,    12,    13,    10,     1,     2,     6,     9,     7,
       6,     7,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    19,     0,     0,     0,     0,
      20,    21,    23,    24,    25,     0,     0,     0,     0,    22,
       0,     0,     0,     4,     0,     0,     0,     0,    81,     0,
       0,    77,     0,     0,    33,    30,    32,    31,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     0,     9,    10,    11,    12,    13,    18,
      14,    15,    16,    17,     0,     0,     0,     0,     0,     4,
       0,     0,     0,     0,    75,    61,    58,     0,    52,     0,
      53,     0,     0,     0,     4,     0,     0,     4,     0,     0,
       0,     0,    48,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    87,    88,    86,     0,     0,    82,     0,
       4,    78,    74,    76,    63,     0,    62,     0,    51,     0,
       0,     0,     0,     0,    89,     0,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,    19,    34,
      41,    42,    46,    45,    44,    43,    35,    36,    37,    38,
      39,    40,    83,     0,     4,     0,     0,     0,     0,    27,
       0,     0,    54,    55,    56,    59,     4,     0,     0,    95,
       0,     0,     0,     4,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     0,    79,     0,    64,
       0,     0,     0,     0,     0,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    29,
       2,    84,     0,     4,     0,     0,    80,     0,    57,     0,
       0,     0,     4,     0,    69,     0,     0,     0,     0,     0,
       0,   100,     0,   102,     0,     3,    90,     0,     0,     4,
      60,     4,    49,     0,     0,     0,    72,    73,    70,    71,
       0,     4,     0,    99,   101,     0,    91,     0,     0,     4,
       0,     0,     0,     0,     0,    92,     0,     0,    97,     0,
      98,     4,     0,     0,     4,    93,    50,    94,     0,     0,
      65,     0,     0,     4,     0,    67,     0,    66,     0,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    50,    51,    52,     9,    10,    11,    53,    54,
      55,    77,    78,    79,    80,   125,   126,    56,    57,    58,
      12,    32,    33,    13,    27,    28,   116,    59,    14,    60,
     178,   179,    61,    62,    63
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -108
static const yytype_int16 yypact[] =
{
     -27,    36,    50,     7,  -108,    91,    49,    64,    65,    18,
      91,  -108,  -108,  -108,  -108,    16,    27,    88,   100,  -108,
      -4,    24,    86,    72,   106,   108,   109,   -33,  -108,   110,
      10,    79,     9,   119,  -108,  -108,  -108,  -108,    51,   137,
      21,    21,   138,   118,    21,    23,   142,    76,    21,    21,
     140,    72,  -108,   193,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,   153,    89,   102,   154,    15,    72,
     158,   167,   162,   168,  -108,    21,    97,     4,  -108,     8,
    -108,    98,   378,   207,    72,   120,   220,    72,    21,    21,
      19,    67,  -108,   355,   171,  -108,  -108,    21,    21,    21,
      21,    21,    21,    21,    21,    21,    21,    21,    21,    21,
     102,   103,  -108,  -108,  -108,  -108,    11,   102,  -108,   161,
      72,  -108,  -108,  -108,   452,   112,   105,   182,  -108,   137,
     102,   183,   -35,   179,  -108,   169,   113,    72,   151,   261,
     288,   102,    21,   117,   122,   125,   126,  -108,    91,   452,
      66,    66,    66,    66,    66,    66,    85,    85,   121,   121,
     121,  -108,  -108,   187,    72,   130,    22,   190,   186,  -108,
      21,   132,  -108,  -108,   147,  -108,    72,   204,   -13,  -108,
     164,   177,    20,    72,    72,   155,   391,    33,   128,   144,
     146,   188,   102,   199,   216,    72,   221,  -108,   289,   452,
     290,    21,    -8,   291,   294,  -108,   225,   296,    21,    21,
     259,   265,    21,    21,   298,   405,   299,   437,  -108,  -108,
     300,  -108,   302,    72,   292,   303,  -108,   102,   452,   305,
     306,   267,    72,   311,  -108,   301,   314,   309,   310,   424,
     166,  -108,   312,  -108,   313,  -108,  -108,   318,   315,    72,
    -108,    72,  -108,   331,   332,   242,  -108,  -108,  -108,  -108,
      21,    72,    21,  -108,  -108,   333,  -108,   322,   328,    72,
     319,   337,   180,   304,   329,  -108,   338,   339,  -108,   341,
    -108,    72,    21,   383,    72,  -108,  -108,  -108,   387,   342,
    -108,   389,   427,    72,   428,  -108,   393,  -108,   430,  -108
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,   -67,  -108,   388,   335,  -108,   471,   -40,  -108,
    -108,  -108,   356,  -108,   357,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,   408,  -108,   463,   445,  -107,  -108,  -108,  -108,
    -108,   350,  -108,  -108,  -108
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      82,    83,   119,   162,    86,   229,     1,   230,    92,    93,
     166,   177,   128,    24,    25,     5,    31,   135,   130,   164,
     138,   145,   146,   174,    34,    35,    36,    37,    38,   141,
     195,    87,    24,    25,   185,   124,    34,    35,    36,    37,
      38,    24,    25,     3,    67,    72,   204,    68,   139,   140,
       4,   208,   209,   168,    88,    89,    15,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     181,    16,    17,    26,    81,    34,    35,    36,    37,    38,
      18,    39,   142,    40,   129,   221,    81,    70,   131,   165,
      68,    41,    48,    31,    20,    42,    22,   193,    43,    49,
     196,    29,   186,    44,    48,    21,    45,     6,    23,   202,
     214,    49,     7,    64,    46,    65,   210,   211,    69,    66,
     250,   143,   144,   145,   146,    47,     8,    74,   224,    75,
     199,    34,    35,    36,    37,    38,   104,   105,   106,   107,
     108,   109,    71,    48,    76,    85,    84,   215,   217,    90,
      49,   112,   113,   114,   115,    91,   247,   106,   107,   108,
     109,   228,    94,   110,   117,   254,   120,   111,   235,   236,
     122,   121,   239,   240,   261,   127,   123,   132,   136,   148,
     163,    81,   267,   167,   268,   170,   171,   176,   281,   169,
     175,   182,   180,   177,   273,   187,   109,   192,   197,    48,
     188,    96,   278,   189,   190,   216,    49,   194,   198,   200,
     201,   203,   206,   262,   288,   134,   207,   291,   212,   222,
     272,   218,   274,   219,   223,   220,   296,   282,   137,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   289,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   183,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   184,   226,   225,   237,
     227,   231,   232,   233,   234,   238,   241,   243,   245,   256,
     246,   249,   248,   251,   252,   253,   255,   258,   259,   271,
     263,   264,   257,   266,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   284,   265,   269,
     270,   275,   276,   277,   279,   280,   285,   286,   283,   287,
     293,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     133,   290,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   292,   147,   294,   213,   295,   297,   298,   299,    95,
      73,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   260,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,    19,   242,   191,    30,   172,   173,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   118,   244,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   205
};

static const yytype_uint16 yycheck[] =
{
      40,    41,    69,   110,    44,    13,    33,    15,    48,    49,
     117,    24,     8,    17,    18,     8,     7,    84,    10,     8,
      87,    56,    57,   130,     3,     4,     5,     6,     7,    10,
       8,     8,    17,    18,   141,    75,     3,     4,     5,     6,
       7,    17,    18,     7,    77,    36,    59,    80,    88,    89,
       0,    31,    32,   120,    31,    32,     7,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     137,     7,     7,    77,    53,     3,     4,     5,     6,     7,
      62,     9,    63,    11,    80,   192,    53,    77,    80,    78,
      80,    19,    71,     7,    78,    23,     8,   164,    26,    78,
      78,    77,   142,    31,    71,    78,    34,    16,     8,   176,
      77,    78,    21,     7,    42,     7,   183,   184,     8,    10,
     227,    54,    55,    56,    57,    53,    35,     8,   195,    78,
     170,     3,     4,     5,     6,     7,    70,    71,    72,    73,
      74,    75,    63,    71,     7,    27,     8,   187,   188,     7,
      78,    49,    50,    51,    52,    79,   223,    72,    73,    74,
      75,   201,    22,    10,    10,   232,     8,    78,   208,   209,
       8,     4,   212,   213,     8,    78,     8,    79,    58,     8,
      77,    53,   249,    22,   251,    80,     4,     8,     8,    77,
       7,    40,    79,    24,   261,    78,    75,    10,     8,    71,
      78,     8,   269,    78,    78,    77,    78,    77,    22,    77,
      63,     7,    48,    47,   281,     8,    39,   284,    63,    20,
     260,    77,   262,    77,     8,    37,   293,    47,     8,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,   282,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     8,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     8,     8,    77,    40,
      10,    10,     8,    78,     8,    40,     8,     8,     8,     8,
       8,     8,    20,     8,     8,    48,     5,     8,     8,    77,
       8,     8,     8,     8,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     8,    20,     8,
       8,     8,    20,    15,    25,     8,     8,     8,    44,     8,
       8,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      12,     8,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    44,    77,    44,    43,     8,     8,    44,     8,    51,
      32,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    43,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    10,    77,   148,    21,   129,   129,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    68,    77,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,   178
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    82,     7,     0,     8,    16,    21,    35,    86,
      87,    88,   101,   104,   109,     7,     7,     7,    62,    88,
      78,    78,     8,     8,    17,    18,    77,   105,   106,    77,
     105,     7,   102,   103,     3,     4,     5,     6,     7,     9,
      11,    19,    23,    26,    31,    34,    42,    53,    71,    78,
      83,    84,    85,    89,    90,    91,    98,    99,   100,   108,
     110,   113,   114,   115,     7,     7,    10,    77,    80,     8,
      77,    63,    36,   103,     8,    78,     7,    92,    93,    94,
      95,    53,    89,    89,     8,    27,    89,     8,    31,    32,
       7,    79,    89,    89,    22,    85,     8,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      10,    78,    49,    50,    51,    52,   107,    10,   106,    83,
       8,     4,     8,     8,    89,    96,    97,    78,     8,    80,
      10,    80,    79,    12,     8,    83,    58,     8,    83,    89,
      89,    10,    63,    54,    55,    56,    57,    77,     8,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,   107,    77,     8,    78,   107,    22,    83,    77,
      80,     4,    93,    95,   107,     7,     8,    24,   111,   112,
      79,    83,    40,     8,     8,   107,    89,    78,    78,    78,
      78,    86,    10,    83,    77,     8,    78,     8,    22,    89,
      77,    63,    83,     7,    59,   112,    48,    39,    31,    32,
      83,    83,    63,    43,    77,    89,    77,    89,    77,    77,
      37,   107,    20,     8,    83,    77,     8,    10,    89,    13,
      15,    10,     8,    78,     8,    89,    89,    40,    40,    89,
      89,     8,    77,     8,    77,     8,     8,    83,    20,     8,
     107,     8,     8,    48,    83,     5,     8,     8,     8,     8,
      43,     8,    47,     8,     8,    20,     8,    83,    83,     8,
       8,    77,    89,    83,    89,     8,    20,    15,    83,    25,
       8,     8,    47,    44,     8,     8,     8,     8,    83,    89,
       8,    83,    44,     8,    44,     8,    83,     8,    44,     8
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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

/* Line 1464 of yacc.c  */
#line 184 "vb_lark.y"
    {(yyval.Module) = root = create_VB_Module_stmt((yyvsp[(2) - (11)].Id),(yyvsp[(7) - (11)].List),(yyvsp[(4) - (11)].Decl_l),(yyvsp[(10) - (11)].Decl_l));;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 185 "vb_lark.y"
    {(yyval.Module) = root = create_VB_Module_stmt((yyvsp[(2) - (12)].Id),(yyvsp[(7) - (12)].List),(yyvsp[(4) - (12)].Decl_l),(yyvsp[(10) - (12)].Decl_l));;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 188 "vb_lark.y"
    {(yyval.List) = create_VB_Stmt_list(0);;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 192 "vb_lark.y"
    {(yyval.List) = create_VB_Stmt_list((yyvsp[(1) - (1)].Stmt));;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 193 "vb_lark.y"
    {(yyval.List) = edit_VB_Stmt_list((yyvsp[(1) - (2)].List),(yyvsp[(2) - (2)].Stmt));;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 196 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Expr((yyvsp[(1) - (2)].Expr));;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 197 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_If((yyvsp[(1) - (1)].If_stmt));;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 198 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Dim((yyvsp[(1) - (1)].Dim));;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 199 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_For((yyvsp[(1) - (1)].For));;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 200 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_While((yyvsp[(1) - (1)].While));;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 201 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Do_Loop((yyvsp[(1) - (1)].Do_loop));;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 202 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Try_Catch((yyvsp[(1) - (1)].Try_catch));;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 203 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Throw((yyvsp[(1) - (1)].Throw));;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 204 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Print((yyvsp[(1) - (1)].console_print));;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 205 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Println((yyvsp[(1) - (1)].console_println));;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 206 "vb_lark.y"
    {(yyval.Stmt) = create_VB_Stmt_Return((yyvsp[(1) - (1)].Ret));;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 209 "vb_lark.y"
    {(yyval.Decl_l) = create_VB_Decl_stmt_list(0);;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 213 "vb_lark.y"
    {(yyval.Decl_l) = create_VB_Decl_stmt_list((yyvsp[(1) - (1)].Decl));;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 214 "vb_lark.y"
    {(yyval.Decl_l) = edit_VB_Decl_stmt_list((yyvsp[(1) - (2)].Decl_l),(yyvsp[(2) - (2)].Decl));;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 217 "vb_lark.y"
    {(yyval.Decl) = create_VB_Decl_Enum((yyvsp[(1) - (1)].Enum));;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 218 "vb_lark.y"
    {(yyval.Decl) = create_VB_Decl_Sub((yyvsp[(1) - (1)].Sub));;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 219 "vb_lark.y"
    {(yyval.Decl) = create_VB_Decl_Func((yyvsp[(1) - (1)].Func));;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 222 "vb_lark.y"
    {(yyval.Expr) = create_id_expr((yyvsp[(1) - (1)].Id));;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 223 "vb_lark.y"
    {(yyval.Expr) = create_brackets_actions((yyvsp[(1) - (4)].Id),(yyvsp[(3) - (4)].Expr_l));;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 224 "vb_lark.y"
    {(yyval.Expr) = create_Read();;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 225 "vb_lark.y"
    {(yyval.Expr) = create_Readln();;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 226 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(3,(yyvsp[(1) - (1)].i_const));;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 227 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(2,(yyvsp[(1) - (1)].c_const));;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 228 "vb_lark.y"
    {(yyval.Expr) = create_string_const_expr((yyvsp[(1) - (1)].s_const));;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 229 "vb_lark.y"
    {(yyval.Expr) = create_int_boolean_char_const_expr(5,(yyvsp[(1) - (1)].b_const));;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 230 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(6,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 231 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(7,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 232 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(8,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 233 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(9,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 234 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(11,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 235 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(10,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 236 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(12,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 237 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(13,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 238 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(14,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 239 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(15,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 240 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(16,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 241 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(17,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 242 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(18,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 243 "vb_lark.y"
    {(yyval.Expr) = (yyvsp[(2) - (3)].Expr);;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 244 "vb_lark.y"
    {(yyval.Expr) = create_operator_expr(19,(yyvsp[(2) - (2)].Expr),0);;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 247 "vb_lark.y"
    {(yyval.If_stmt) = create_if_stmt(0,(yyvsp[(2) - (7)].Expr),(yyvsp[(5) - (7)].List),NULL);;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 248 "vb_lark.y"
    {(yyval.If_stmt) = create_if_stmt(1,(yyvsp[(2) - (10)].Expr),(yyvsp[(5) - (10)].List),(yyvsp[(8) - (10)].List));;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 251 "vb_lark.y"
    {(yyval.Dim) = create_dim_stmt((yyvsp[(2) - (3)].As_l));;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 254 "vb_lark.y"
    {(yyval.As_l) = create_as_expr_list((yyvsp[(1) - (1)].As_expr_str),NULL);;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 255 "vb_lark.y"
    {(yyval.As_l) = create_as_expr_list(NULL,(yyvsp[(1) - (1)].Arr));;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 256 "vb_lark.y"
    {(yyval.As_l) = add_to_as_expr_list((yyvsp[(1) - (3)].As_l),(yyvsp[(3) - (3)].As_expr_str),NULL);;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 257 "vb_lark.y"
    {(yyval.As_l) = add_to_as_expr_list((yyvsp[(1) - (3)].As_l),NULL,(yyvsp[(3) - (3)].Arr));;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 260 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr(0,(yyvsp[(1) - (3)].Id_l),NULL,(yyvsp[(3) - (3)].Id_type),NULL);;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 261 "vb_lark.y"
    {(yyval.As_expr_str) = create_as_expr(0,(yyvsp[(1) - (5)].Id_l),NULL,(yyvsp[(3) - (5)].Id_type),(yyvsp[(5) - (5)].Expr));;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 264 "vb_lark.y"
    {(yyval.Id_l) = create_id_list((yyvsp[(1) - (1)].Id));;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 265 "vb_lark.y"
    {(yyval.Id_l) = add_to_id_list((yyvsp[(1) - (3)].Id_l),(yyvsp[(3) - (3)].Id));;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 268 "vb_lark.y"
    {(yyval.Arr) = create_Array((yyvsp[(1) - (6)].Id),(yyvsp[(3) - (6)].i_const),(yyvsp[(6) - (6)].Id_type));;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 271 "vb_lark.y"
    {(yyval.Expr_l) = create_Expr_list(NULL);;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 275 "vb_lark.y"
    {(yyval.Expr_l) = create_Expr_list((yyvsp[(1) - (1)].Expr));;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 276 "vb_lark.y"
    {(yyval.Expr_l) = add_Expr_to_list((yyvsp[(1) - (3)].Expr_l),(yyvsp[(3) - (3)].Expr));;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 279 "vb_lark.y"
    {(yyval.For) = create_for_stmt((yyvsp[(2) - (10)].Id),(yyvsp[(4) - (10)].Expr),(yyvsp[(6) - (10)].Expr),(yyvsp[(8) - (10)].List));;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 280 "vb_lark.y"
    {(yyval.For) = create_for_with_step_stmt((yyvsp[(2) - (12)].Id),(yyvsp[(4) - (12)].Expr),(yyvsp[(6) - (12)].Expr),(yyvsp[(8) - (12)].Expr),(yyvsp[(10) - (12)].List));;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 281 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_stmt((yyvsp[(2) - (12)].Id),INTEGER_E,(yyvsp[(6) - (12)].Expr),(yyvsp[(8) - (12)].Expr),(yyvsp[(10) - (12)].List));;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 282 "vb_lark.y"
    {(yyval.For) = create_for_with_decl_with_step_stmt((yyvsp[(2) - (14)].Id),INTEGER_E,(yyvsp[(6) - (14)].Expr),(yyvsp[(8) - (14)].Expr),(yyvsp[(10) - (14)].Expr),(yyvsp[(12) - (14)].List));;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 285 "vb_lark.y"
    {(yyval.While) = create_while_stmt((yyvsp[(2) - (6)].Expr),(yyvsp[(4) - (6)].List));;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 288 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(0,(yyvsp[(3) - (7)].Expr),(yyvsp[(5) - (7)].List));;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 289 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(1,(yyvsp[(3) - (7)].Expr),(yyvsp[(5) - (7)].List));;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 290 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(2,(yyvsp[(6) - (7)].Expr),(yyvsp[(3) - (7)].List));;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 291 "vb_lark.y"
    {(yyval.Do_loop) = create_do_loop_stmt(3,(yyvsp[(6) - (7)].Expr),(yyvsp[(3) - (7)].List));;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 294 "vb_lark.y"
    {(yyval.Enum) = create_enum_stmt((yyvsp[(2) - (6)].Id),(yyvsp[(4) - (6)].Enum_l));;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 297 "vb_lark.y"
    {(yyval.Enum_l) = create_enum_list((yyvsp[(1) - (2)].Enum_e));;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 298 "vb_lark.y"
    {(yyval.Enum_l) = add_to_enum_list((yyvsp[(1) - (3)].Enum_l),(yyvsp[(2) - (3)].Enum_e));;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 301 "vb_lark.y"
    {(yyval.Enum_e) = create_enum_expr((yyvsp[(1) - (1)].Id),-1);;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 302 "vb_lark.y"
    {(yyval.Enum_e) = create_enum_expr((yyvsp[(1) - (3)].Id),(yyvsp[(3) - (3)].i_const));;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 305 "vb_lark.y"
    {(yyval.Sub) = create_sub_stmt((yyvsp[(2) - (8)].Id),NULL,(yyvsp[(6) - (8)].List));;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 306 "vb_lark.y"
    {(yyval.Sub) = create_sub_stmt((yyvsp[(2) - (9)].Id),(yyvsp[(4) - (9)].Param_l),(yyvsp[(7) - (9)].List));;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 309 "vb_lark.y"
    {(yyval.Param_l) = create_param_list((yyvsp[(1) - (1)].Param));;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 310 "vb_lark.y"
    {(yyval.Param_l) = add_to_param_list((yyvsp[(1) - (3)].Param_l),(yyvsp[(3) - (3)].Param));;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 313 "vb_lark.y"
    {(yyval.Param) = create_param_stmt(0,(yyvsp[(2) - (4)].Id),(yyvsp[(4) - (4)].Id_type));;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 314 "vb_lark.y"
    {(yyval.Param) = create_param_stmt(1,(yyvsp[(2) - (6)].Id),(yyvsp[(6) - (6)].Id_type));;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 317 "vb_lark.y"
    {(yyval.Id_type) = INTEGER_E;;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 318 "vb_lark.y"
    {(yyval.Id_type) = BOOLEAN_E;;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 319 "vb_lark.y"
    {(yyval.Id_type) = CHAR_E;;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 320 "vb_lark.y"
    {(yyval.Id_type) = STRING_E;;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 323 "vb_lark.y"
    {(yyval.Ret) = create_return_stmt((yyvsp[(2) - (3)].Expr));;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 325 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (10)].Id),NULL,(yyvsp[(6) - (10)].Id_type),(yyvsp[(8) - (10)].List));;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 326 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (11)].Id),(yyvsp[(4) - (11)].Param_l),(yyvsp[(7) - (11)].Id_type),(yyvsp[(9) - (11)].List));;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 327 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (12)].Id),NULL,(yyvsp[(6) - (12)].Id_type),(yyvsp[(10) - (12)].List));;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 328 "vb_lark.y"
    {(yyval.Func) = create_func_stmt((yyvsp[(2) - (13)].Id),(yyvsp[(4) - (13)].Param_l),(yyvsp[(7) - (13)].Id_type),(yyvsp[(11) - (13)].List));;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 331 "vb_lark.y"
    {(yyval.Try_catch) = create_Try_Catch((yyvsp[(3) - (10)].List),(yyvsp[(4) - (10)].Catch_l),(yyvsp[(7) - (10)].List));;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 334 "vb_lark.y"
    {(yyval.Catch_l) = create_Catch_stmt_list((yyvsp[(1) - (1)].Catch));;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 335 "vb_lark.y"
    {(yyval.Catch_l) = add_new_Catch_stmt((yyvsp[(1) - (2)].Catch_l),(yyvsp[(2) - (2)].Catch));;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 338 "vb_lark.y"
    {(yyval.Catch) = create_Catch_stmt((yyvsp[(2) - (6)].Id),(yyvsp[(6) - (6)].List));;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 341 "vb_lark.y"
    {(yyval.Throw) = create_Throw((yyvsp[(7) - (9)].s_const));;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 344 "vb_lark.y"
    {(yyval.console_print) = create_Print((yyvsp[(5) - (7)].Expr));;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 345 "vb_lark.y"
    {(yyval.console_print) = create_Print(NULL);;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 348 "vb_lark.y"
    {(yyval.console_println) = create_Println((yyvsp[(5) - (7)].Expr));;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 349 "vb_lark.y"
    {(yyval.console_println) = create_Println(NULL);;}
    break;



/* Line 1464 of yacc.c  */
#line 2492 "vb_lark.tab.c"
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



/* Line 1684 of yacc.c  */
#line 351 "vb_lark.y"


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
