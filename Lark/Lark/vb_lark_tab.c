#include "stdafx.h"
/*  A Bison parser, made from vb_lark.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	BOOLEAN_CONST	258
#define	INT_CONST	259
#define	STRING_CONST	260
#define	CHAR_CONST	261
#define	ID	262
#define	ENDL	263
#define	DIM	264
#define	AS	265
#define	IF	266
#define	THEN	267
#define	ELSE	268
#define	ELSEIF	269
#define	END_IF	270
#define	FUNCTION	271
#define	BYVAL	272
#define	RETURN	273
#define	END_FUNCTION	274
#define	SUB	275
#define	END_SUB	276
#define	TRY	277
#define	CATCH	278
#define	END_TRY	279
#define	THROW	280
#define	NEW	281
#define	CASE	282
#define	CONST	283
#define	SELECT	284
#define	WHILE	285
#define	UNTIL	286
#define	MODULE	287
#define	DO	288
#define	ENUM	289
#define	END_ENUM	290
#define	END_MODULE	291
#define	END_SELECT	292
#define	END_WHILE	293
#define	LOOP	294
#define	FOR_EACH	295
#define	FOR	296
#define	TO	297
#define	NEXT	298
#define	IN	299
#define	MOD	300
#define	STEP	301
#define	EXCEPTION	302
#define	INTEGER	303
#define	CHAR	304
#define	STRING_T	305
#define	BOOLEAN	306
#define	CONSOLE	307
#define	WRITE	308
#define	WRITELINE	309
#define	READ	310
#define	READLINE	311
#define	SYSTEM	312
#define	FINALLY	313
#define	TRUE	314
#define	FALSE	315
#define	SUB_MAIN	316
#define	MORE_OR_EQUAL	317
#define	LESS_OR_EQUAL	318
#define	NONEQUAL	319
#define	EQUAL	320
#define	UMINUS	321

#line 1 "vb_lark.y"

	#include <stdio.h>
	#include <malloc.h>
	#include "dot.h"
	
	extern int yylex(void);
	//extern int yyparse(void);
	
	struct VB_Module_stmt* root;
	
	void yyerror (char const* s);
	
	extern FILE* yyin;

#line 18 "vb_lark.y"
typedef union
{
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
	
	struct VB_Decl_stmt_list*	Decl_l;
	struct VB_Decl_stmt*		Decl;
	
	enum VB_Id_type				Id_type;

	struct VB_Print_stmt*			console_print;
	struct VB_Println_stmt*			console_println;
	struct VB_Read_stmt*			console_read;
	struct VB_Readln_stmt*			console_readln;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		392
#define	YYFLAG		-32768
#define	YYNTBASE	81

#define YYTRANSLATE(x) ((unsigned)(x) <= 321 ? yytranslate[x] : 116)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    77,
    76,    71,    69,    79,    70,    80,    72,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    78,     2,    64,
    62,    63,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,    73,     2,    74,     2,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    65,    66,    67,    68,
    75
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,    12,    13,    15,    17,    20,    23,    25,    27,    29,
    31,    33,    35,    37,    39,    41,    43,    45,    46,    48,
    50,    53,    55,    57,    59,    61,    66,    68,    70,    72,
    74,    78,    82,    86,    90,    94,    98,   102,   106,   110,
   114,   118,   122,   126,   130,   133,   140,   146,   153,   162,
   164,   168,   171,   177,   184,   190,   194,   196,   198,   202,
   206,   210,   214,   218,   222,   228,   234,   240,   246,   248,
   252,   259,   266,   273,   280,   282,   286,   297,   310,   323,
   336,   349,   364,   379,   394,   401,   409,   417,   425,   433,
   440,   443,   447,   449,   453,   462,   472,   474,   478,   483,
   488,   493,   498,   512,   526,   540,   554,   569,   584,   599,
   614,   625,   627,   630,   637,   647,   655,   663,   670
};

static const short yyrhs[] = {    32,
     7,     8,    85,    61,     8,    82,    21,     8,    85,    36,
     0,     0,    83,     0,    84,     0,    83,    84,     0,    88,
     8,     0,    89,     0,    92,     0,    98,     0,    99,     0,
   100,     0,   108,     0,   111,     0,   112,     0,   113,     0,
   114,     0,   115,     0,     0,    86,     0,    87,     0,    86,
    87,     0,   101,     0,   104,     0,   107,     0,     7,     0,
     7,    77,    97,    76,     0,     4,     0,     6,     0,     5,
     0,     3,     0,    88,    62,    88,     0,    88,    69,    88,
     0,    88,    70,    88,     0,    88,    71,    88,     0,    88,
    72,    88,     0,    88,    73,    88,     0,    88,    74,    88,
     0,    88,    63,    88,     0,    88,    64,    88,     0,    88,
    65,    88,     0,    88,    66,    88,     0,    88,    67,    88,
     0,    88,    68,    88,     0,    77,    88,    76,     0,    70,
    88,     0,    11,    88,    12,     8,    82,    91,     0,    11,
    88,     8,    82,    91,     0,    11,    88,    12,    90,    15,
     8,     0,    11,    88,    12,    90,    13,    90,    15,     8,
     0,    84,     0,    90,    78,    84,     0,    15,     8,     0,
    13,     8,    82,    15,     8,     0,    14,    88,    12,     8,
    82,    91,     0,    14,    88,     8,    82,    91,     0,     9,
    93,     8,     0,    94,     0,    96,     0,    93,    79,    94,
     0,    93,    79,    96,     0,    95,    10,    48,     0,    95,
    10,    51,     0,    95,    10,    49,     0,    95,    10,    50,
     0,    95,    10,    48,    62,    88,     0,    95,    10,    51,
    62,    88,     0,    95,    10,    49,    62,    88,     0,    95,
    10,    50,    62,    88,     0,     7,     0,    95,    79,     7,
     0,     7,    77,     4,    76,    10,    48,     0,     7,    77,
     4,    76,    10,    51,     0,     7,    77,     4,    76,    10,
    49,     0,     7,    77,     4,    76,    10,    50,     0,    88,
     0,    97,    79,    88,     0,    41,     7,    62,     4,    42,
     4,     8,    82,    43,     8,     0,    41,     7,    62,     4,
    42,     4,    46,     4,     8,    82,    43,     8,     0,    41,
     7,    10,    48,    62,     4,    42,     4,     8,    82,    43,
     8,     0,    41,     7,    10,    51,    62,     4,    42,     4,
     8,    82,    43,     8,     0,    41,     7,    10,    49,    62,
     4,    42,     4,     8,    82,    43,     8,     0,    41,     7,
    10,    48,    62,     4,    42,     4,    46,     4,     8,    82,
    43,     8,     0,    41,     7,    10,    51,    62,     4,    42,
     4,    46,     4,     8,    82,    43,     8,     0,    41,     7,
    10,    49,    62,     4,    42,     4,    46,     4,     8,    82,
    43,     8,     0,    30,    88,     8,    82,    38,     8,     0,
    33,    30,    88,     8,    82,    39,     8,     0,    33,    31,
    88,     8,    82,    39,     8,     0,    33,     8,    82,    39,
    30,    88,     8,     0,    33,     8,    82,    39,    31,    88,
     8,     0,    34,     7,     8,   102,    35,     8,     0,   103,
     8,     0,   102,   103,     8,     0,     7,     0,     7,    62,
     4,     0,    20,     7,    77,    76,     8,    82,    21,     8,
     0,    20,     7,    77,   105,    76,     8,    82,    21,     8,
     0,   106,     0,   105,    79,   106,     0,    17,     7,    10,
    48,     0,    17,     7,    10,    51,     0,    17,     7,    10,
    49,     0,    17,     7,    10,    50,     0,    16,     7,    77,
    76,    10,    48,     8,    82,    18,    88,     8,    19,     8,
     0,    16,     7,    77,    76,    10,    51,     8,    82,    18,
    88,     8,    19,     8,     0,    16,     7,    77,    76,    10,
    49,     8,    82,    18,    88,     8,    19,     8,     0,    16,
     7,    77,    76,    10,    50,     8,    82,    18,    88,     8,
    19,     8,     0,    16,     7,    77,   105,    76,    10,    48,
     8,    82,    18,    88,     8,    19,     8,     0,    16,     7,
    77,   105,    76,    10,    51,     8,    82,    18,    88,     8,
    19,     8,     0,    16,     7,    77,   105,    76,    10,    49,
     8,    82,    18,    88,     8,    19,     8,     0,    16,     7,
    77,   105,    76,    10,    50,     8,    82,    18,    88,     8,
    19,     8,     0,    22,     8,    82,   109,    58,     8,    82,
     8,    24,     8,     0,   110,     0,   109,   110,     0,    23,
     7,    10,    47,     8,    82,     0,    25,    26,    57,    80,
    47,    77,     5,    76,     8,     0,    52,    80,    53,    77,
     5,    76,     8,     0,    52,    80,    54,    77,     5,    76,
     8,     0,    52,    80,    55,    77,    76,     8,     0,    52,
    80,    56,    77,    76,     8,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   175,   178,   179,   182,   183,   186,   187,   188,   189,   190,
   191,   192,   193,   194,   195,   196,   197,   200,   201,   204,
   205,   208,   209,   210,   213,   214,   215,   216,   217,   218,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   236,   237,   238,   239,   242,
   243,   246,   247,   248,   249,   252,   255,   256,   257,   258,
   261,   262,   263,   264,   265,   266,   267,   268,   271,   272,
   275,   276,   277,   278,   281,   282,   285,   286,   287,   288,
   289,   290,   291,   292,   295,   298,   299,   300,   301,   304,
   307,   308,   311,   312,   315,   316,   319,   320,   323,   324,
   325,   326,   329,   330,   331,   332,   333,   334,   335,   336,
   339,   342,   343,   346,   349,   352,   355,   358,   361
};

static const char * const yytname[] = {   "$","error","$undefined.","BOOLEAN_CONST",
"INT_CONST","STRING_CONST","CHAR_CONST","ID","ENDL","DIM","AS","IF","THEN","ELSE",
"ELSEIF","END_IF","FUNCTION","BYVAL","RETURN","END_FUNCTION","SUB","END_SUB",
"TRY","CATCH","END_TRY","THROW","NEW","CASE","CONST","SELECT","WHILE","UNTIL",
"MODULE","DO","ENUM","END_ENUM","END_MODULE","END_SELECT","END_WHILE","LOOP",
"FOR_EACH","FOR","TO","NEXT","IN","MOD","STEP","EXCEPTION","INTEGER","CHAR",
"STRING_T","BOOLEAN","CONSOLE","WRITE","WRITELINE","READ","READLINE","SYSTEM",
"FINALLY","TRUE","FALSE","SUB_MAIN","'='","'>'","'<'","MORE_OR_EQUAL","LESS_OR_EQUAL",
"NONEQUAL","EQUAL","'+'","'-'","'*'","'/'","'\\\\'","'^'","UMINUS","')'","'('",
"':'","','","'.'","module_stmt","stmt_list","stmt_listE","stmt","decl_stmt_list",
"decl_stmt_listE","decl_stmt","expr","if_stmt","stmt_list_inline","end_if_stmt",
"dim_stmt","as_expr_list","as_expr","id_list_stmt","array_expr","expr_list",
"for_stmt","while_stmt","do_loop_stmt","enum_stmt","enum_expr_list","enum_expr",
"sub_stmt","param_list","param_stmt","func_stmt","try_catch_stmt","catch_stmt_list",
"catch_stmt","throw_stmt","console_print_stmt","console_println_stmt","console_read_stmt",
"console_readln_stmt",""
};
#endif

static const short yyr1[] = {     0,
    81,    82,    82,    83,    83,    84,    84,    84,    84,    84,
    84,    84,    84,    84,    84,    84,    84,    85,    85,    86,
    86,    87,    87,    87,    88,    88,    88,    88,    88,    88,
    88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
    88,    88,    88,    88,    88,    89,    89,    89,    89,    90,
    90,    91,    91,    91,    91,    92,    93,    93,    93,    93,
    94,    94,    94,    94,    94,    94,    94,    94,    95,    95,
    96,    96,    96,    96,    97,    97,    98,    98,    98,    98,
    98,    98,    98,    98,    99,   100,   100,   100,   100,   101,
   102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
   106,   106,   107,   107,   107,   107,   107,   107,   107,   107,
   108,   109,   109,   110,   111,   112,   113,   114,   115
};

static const short yyr2[] = {     0,
    11,     0,     1,     1,     2,     2,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
     2,     1,     1,     1,     1,     4,     1,     1,     1,     1,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     2,     6,     5,     6,     8,     1,
     3,     2,     5,     6,     5,     3,     1,     1,     3,     3,
     3,     3,     3,     3,     5,     5,     5,     5,     1,     3,
     6,     6,     6,     6,     1,     3,    10,    12,    12,    12,
    12,    14,    14,    14,     6,     7,     7,     7,     7,     6,
     2,     3,     1,     3,     8,     9,     1,     3,     4,     4,
     4,     4,    13,    13,    13,    13,    14,    14,    14,    14,
    10,     1,     2,     6,     9,     7,     7,     6,     6
};

static const short yydefact[] = {     0,
     0,     0,    18,     0,     0,     0,     0,    19,    20,    22,
    23,    24,     0,     0,     0,     0,    21,     0,     0,     0,
     2,     0,     0,     0,    97,     0,     0,    93,     0,     0,
    30,    27,    29,    28,    25,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     3,     4,     0,     7,
     8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
     0,     0,     0,     0,     2,     0,     0,     0,     0,    91,
     0,    69,     0,    57,     0,    58,     0,     2,     0,     0,
     2,     0,     0,     0,     0,    45,     0,     0,     5,     6,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
     0,     2,    94,    90,    92,    75,     0,     0,    56,     0,
     0,     0,     2,     0,     0,     0,     2,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    44,    18,    31,    38,
    39,    40,    41,    42,    43,    32,    33,    34,    35,    36,
    37,    99,   101,   102,   100,     2,     2,     2,     2,     0,
     0,     0,     0,     0,     0,    26,     0,     0,    59,    60,
    61,    63,    64,    62,    70,     0,     2,    50,     0,     0,
     0,   112,     0,     0,     0,     2,     2,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     2,     2,     2,     2,    95,     0,    76,     0,     0,     0,
     0,     0,     0,     0,     0,    47,     0,     0,     0,     0,
     0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
     0,     0,     0,     0,     0,     0,    96,     0,    65,    67,
    68,    66,     2,     0,    52,    46,     0,    48,    51,     0,
     2,     0,    85,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   118,   119,     0,     0,     0,     0,     0,
     0,     0,     0,    71,    73,    74,    72,     0,     2,     0,
     0,     0,     0,     0,    88,    89,    86,    87,     0,     0,
     0,     2,     0,   116,   117,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     2,    49,     2,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    53,    55,     0,   114,     0,   115,     2,
     0,     2,     0,     2,     0,     0,     2,   103,   105,   106,
   104,     0,     0,     0,     0,    54,   111,     0,     0,     0,
     0,     0,     0,    77,     0,   107,   109,   110,   108,     0,
     2,     0,     2,     0,     2,     0,    79,     0,    81,     0,
    80,     0,    78,     0,     0,     0,    82,    84,    83,     0,
     0,     0
};

static const short yydefgoto[] = {   390,
    46,    47,    48,     7,     8,     9,    49,    50,   179,   216,
    51,    73,    74,    75,    76,   117,    52,    53,    54,    10,
    29,    30,    11,    24,    25,    12,    55,   181,   182,    56,
    57,    58,    59,    60
};

static const short yypact[] = {     8,
    15,    38,    19,    16,    44,    47,    -5,    19,-32768,-32768,
-32768,-32768,   -12,    23,    58,    93,-32768,    -7,    -6,   103,
   206,   104,    99,   -52,-32768,   109,   -38,    56,     2,   111,
-32768,-32768,-32768,-32768,    57,   137,    25,   139,   119,    25,
    12,   148,    76,    25,    25,   141,   206,-32768,   270,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   153,    39,   154,   155,   206,   162,   167,   165,   166,-32768,
    25,    98,     7,-32768,    -8,-32768,   222,   206,   120,   289,
   206,    25,    25,    -3,    60,-32768,   530,   170,-32768,-32768,
    25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
    25,    25,    25,    75,   172,   174,   175,   176,    92,-32768,
   164,   206,-32768,-32768,-32768,   545,   -31,   182,-32768,   137,
   102,   180,   206,   124,   177,   117,   206,   150,   303,   337,
   -15,   194,   122,   125,   126,   127,-32768,    19,   545,    34,
    34,    34,    34,    34,    34,    87,    87,   131,   131,   131,
-32768,-32768,-32768,-32768,-32768,   206,   206,   206,   206,   198,
   208,   210,   211,   217,   193,-32768,    25,   151,-32768,-32768,
   171,   173,   178,   179,-32768,    83,   206,-32768,   -10,   219,
    -9,-32768,   185,   191,    30,   206,   206,   181,   183,   184,
   196,   237,   239,   190,   192,   212,   231,   232,   234,   236,
   206,   206,   206,   206,-32768,   247,   545,   246,    25,    25,
    25,    25,   249,    25,   251,-32768,    83,   206,   252,   206,
   260,   259,-32768,   195,   263,    25,    25,   235,   241,   269,
   277,   294,   295,   224,   225,   296,   297,-32768,    25,    25,
    25,    25,   284,   285,   291,   298,-32768,   118,   545,   545,
   545,   545,   206,   257,-32768,-32768,   -11,-32768,-32768,   265,
   206,   302,-32768,   356,   370,   305,   306,   273,   275,   276,
    -2,   338,   339,-32768,-32768,   383,   404,   423,   450,    25,
    25,    25,    25,-32768,-32768,-32768,-32768,   333,   206,   341,
   342,   371,   372,   307,-32768,-32768,-32768,-32768,   377,   378,
   380,   206,   381,-32768,-32768,   367,   368,   369,   373,   471,
   490,   503,   517,   382,    83,   206,-32768,   206,   365,   385,
     4,     9,    11,   351,   387,   388,   389,   390,   405,   395,
   396,   397,   398,-32768,-32768,    83,-32768,   451,-32768,   206,
   456,   206,   457,   206,   458,   455,   206,-32768,-32768,-32768,
-32768,   472,   473,   474,   475,-32768,-32768,   421,   476,   422,
   491,   459,   492,-32768,   460,-32768,-32768,-32768,-32768,   493,
   206,   496,   206,   497,   206,   498,-32768,   464,-32768,   465,
-32768,   466,-32768,   502,   518,   519,-32768,-32768,-32768,   528,
   529,-32768
};

static const short yypgoto[] = {-32768,
   -65,-32768,   -39,   392,-32768,   523,   -19,-32768,   314,  -216,
-32768,-32768,   426,-32768,   427,-32768,-32768,-32768,-32768,-32768,
-32768,   520,-32768,   531,   484,-32768,-32768,-32768,   424,-32768,
-32768,-32768,-32768,-32768
};


#define	YYLAST		619


static const short yytable[] = {   111,
   256,   121,   218,   291,   219,   302,   131,    89,    28,    22,
    22,   340,   125,   180,   119,   128,   342,    77,   344,    81,
    80,     2,    13,    63,    86,    87,    64,    31,    32,    33,
    34,    35,   188,   189,     4,   190,    68,    66,     5,     1,
    64,    82,    83,   303,   166,     3,   165,   167,   222,   341,
    14,   116,     6,    15,   343,    16,   345,   176,   132,   226,
   227,   184,   129,   130,    18,    20,   220,   220,    23,    26,
   122,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   178,   120,   105,   106,   107,   108,
   197,   198,   199,   200,    44,   213,   214,   215,   335,    19,
    21,    45,    98,    99,   100,   101,   102,   103,    62,    28,
    61,   217,   133,   134,   135,   136,    65,    67,    70,   356,
   228,   229,   152,   153,   154,   155,    31,    32,    33,    34,
    35,   177,    36,    71,    37,   243,   244,   245,   246,   160,
   161,   162,   163,    72,    79,    38,    78,   207,    39,   171,
   172,   173,   174,    40,    84,    85,    41,   100,   101,   102,
   103,    88,   104,   109,    42,   284,   285,   286,   287,   112,
   113,    22,   114,   115,   118,    43,   126,   138,   178,   156,
   259,   157,   158,   159,   164,   168,   175,   288,   185,   249,
   250,   251,   252,    44,   254,   293,   183,   191,   192,   180,
    45,   193,   194,   195,   103,   201,   264,   265,    31,    32,
    33,    34,    35,   206,    36,   202,    37,   203,   204,   276,
   277,   278,   279,   315,   205,   221,   208,    38,   225,   123,
    39,   224,   209,   124,   210,    40,   324,   233,    41,   211,
   212,   234,   230,   235,   231,   232,    42,   238,   239,   240,
   336,   241,   337,   242,   247,   248,   253,    43,   255,   258,
   310,   311,   312,   313,   289,   236,   261,   237,   290,   260,
   263,   262,   268,   266,   358,    44,   360,    90,   362,   267,
   269,   365,    45,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   127,   270,   271,   272,
   273,   280,   281,   274,   275,   378,   294,   380,   282,   382,
   186,   292,   297,   298,   299,   283,   300,   301,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   187,   304,   305,   314,   316,   317,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   295,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   296,   318,   319,
   321,   322,   320,   323,   325,   326,   327,   328,   338,   334,
   306,   329,   339,   346,   347,   348,   349,   350,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   307,   351,   352,   353,   354,   355,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   308,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   309,   357,   359,
   361,   363,   364,   370,   372,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   330,   366,
   367,   368,   369,   371,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   331,   373,   375,
   377,   374,   376,   379,   381,   383,   384,   385,   386,   387,
   332,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   333,   388,   389,   391,   392,   196,
    17,   257,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   169,   170,   110,    69,    27,
     0,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,     0,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   223,   137,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103
};

static const short yycheck[] = {    65,
   217,    10,    13,    15,    15,     8,    10,    47,     7,    17,
    17,     8,    78,    23,     8,    81,     8,    37,     8,     8,
    40,     7,     7,    76,    44,    45,    79,     3,     4,     5,
     6,     7,    48,    49,    16,    51,    35,    76,    20,    32,
    79,    30,    31,    46,    76,     8,   112,    79,    58,    46,
     7,    71,    34,     7,    46,    61,    46,   123,    62,    30,
    31,   127,    82,    83,    77,     8,    78,    78,    76,    76,
    79,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   124,    79,    48,    49,    50,    51,
   156,   157,   158,   159,    70,    13,    14,    15,   315,    77,
     8,    77,    69,    70,    71,    72,    73,    74,    10,     7,
     7,   177,    53,    54,    55,    56,     8,    62,     8,   336,
   186,   187,    48,    49,    50,    51,     3,     4,     5,     6,
     7,     8,     9,    77,    11,   201,   202,   203,   204,    48,
    49,    50,    51,     7,    26,    22,     8,   167,    25,    48,
    49,    50,    51,    30,     7,    80,    33,    71,    72,    73,
    74,    21,    10,    10,    41,    48,    49,    50,    51,     8,
     4,    17,     8,     8,    77,    52,    57,     8,   218,     8,
   220,     8,     8,     8,    21,     4,     7,   253,    39,   209,
   210,   211,   212,    70,   214,   261,    80,     4,    77,    23,
    77,    77,    77,    77,    74,     8,   226,   227,     3,     4,
     5,     6,     7,    21,     9,     8,    11,     8,     8,   239,
   240,   241,   242,   289,     8,     7,    76,    22,    38,     8,
    25,    47,    62,    12,    62,    30,   302,    42,    33,    62,
    62,     5,    62,     5,    62,    62,    41,    36,    18,    18,
   316,    18,   318,    18,     8,    10,     8,    52,     8,     8,
   280,   281,   282,   283,     8,    76,     8,    76,    12,    10,
     8,    77,     4,    39,   340,    70,   342,     8,   344,    39,
     4,   347,    77,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,     8,     4,     4,    76,
    76,    18,    18,     8,     8,   371,     5,   373,    18,   375,
     8,    47,     8,     8,    42,    18,    42,    42,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,     8,     8,     8,    15,     8,     8,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,     8,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,     8,     8,     8,
     4,     4,    76,     4,     4,    19,    19,    19,    24,     8,
     8,    19,     8,    43,     8,     8,     8,     8,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,     8,     8,    19,    19,    19,    19,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
     8,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,     8,     8,     4,
     4,     4,     8,    43,    43,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,     8,     8,
     8,     8,     8,     8,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,     8,     8,     8,
     8,    43,    43,     8,     8,     8,    43,    43,    43,     8,
     8,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,     8,     8,     8,     0,     0,   138,
     8,   218,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,   120,   120,    64,    29,    19,
    -1,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    -1,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,   181,    76,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 175 "vb_lark.y"
{yyval.Module = root = create_VB_Module_stmt(yyvsp[-9].Id,yyvsp[-4].List,yyvsp[-7].Decl_l,yyvsp[-1].Decl_l);;
    break;}
case 2:
#line 178 "vb_lark.y"
{yyval.List = create_VB_Stmt_list(0);;
    break;}
case 4:
#line 182 "vb_lark.y"
{yyval.List = create_VB_Stmt_list(yyvsp[0].Stmt);;
    break;}
case 5:
#line 183 "vb_lark.y"
{yyval.List = edit_VB_Stmt_list(yyvsp[-1].List,yyvsp[0].Stmt);;
    break;}
case 6:
#line 186 "vb_lark.y"
{yyval.Stmt = create_VB_Stmt_Expr(yyvsp[-1].Expr);;
    break;}
case 7:
#line 187 "vb_lark.y"
{yyval.Stmt = create_VB_Stmt_If(yyvsp[0].If_stmt);;
    break;}
case 8:
#line 188 "vb_lark.y"
{yyval.Stmt = create_VB_Stmt_Dim(yyvsp[0].Dim);;
    break;}
case 9:
#line 189 "vb_lark.y"
{yyval.Stmt = create_VB_Stmt_For(yyvsp[0].For);;
    break;}
case 10:
#line 190 "vb_lark.y"
{yyval.Stmt = create_VB_Stmt_While(yyvsp[0].While);;
    break;}
case 11:
#line 191 "vb_lark.y"
{yyval.Stmt = create_VB_Stmt_Do_Loop(yyvsp[0].Do_loop);;
    break;}
case 12:
#line 192 "vb_lark.y"
{yyval.Stmt = create_VB_Stmt_Try_Catch(yyvsp[0].Try_catch);;
    break;}
case 13:
#line 193 "vb_lark.y"
{yyval.Stmt = create_VB_Stmt_Throw(yyvsp[0].Throw);;
    break;}
case 14:
#line 194 "vb_lark.y"
{yyval.Stmt = create_VB_Stmt_Print(yyvsp[0].console_print);;
    break;}
case 15:
#line 195 "vb_lark.y"
{yyval.Stmt = create_VB_Stmt_Println(yyvsp[0].console_println);;
    break;}
case 16:
#line 196 "vb_lark.y"
{yyval.Stmt = create_VB_Stmt_Read(yyvsp[0].console_read);;
    break;}
case 17:
#line 197 "vb_lark.y"
{yyval.Stmt = create_VB_Stmt_Readln(yyvsp[0].console_readln);;
    break;}
case 18:
#line 200 "vb_lark.y"
{yyval.Decl_l = create_VB_Decl_stmt_list(0);;
    break;}
case 20:
#line 204 "vb_lark.y"
{yyval.Decl_l = create_VB_Decl_stmt_list(yyvsp[0].Decl);;
    break;}
case 21:
#line 205 "vb_lark.y"
{yyval.Decl_l = edit_VB_Decl_stmt_list(yyvsp[-1].Decl_l,yyvsp[0].Decl);;
    break;}
case 22:
#line 208 "vb_lark.y"
{yyval.Decl = create_VB_Decl_Enum(yyvsp[0].Enum);;
    break;}
case 23:
#line 209 "vb_lark.y"
{yyval.Decl = create_VB_Decl_Sub(yyvsp[0].Sub);;
    break;}
case 24:
#line 210 "vb_lark.y"
{yyval.Decl = create_VB_Decl_Func(yyvsp[0].Func);;
    break;}
case 25:
#line 213 "vb_lark.y"
{yyval.Expr = create_id_expr(yyvsp[0].Id);;
    break;}
case 26:
#line 214 "vb_lark.y"
{yyval.Expr = create_brackets_actions(yyvsp[-3].Id,yyvsp[-1].Expr_l);;
    break;}
case 27:
#line 215 "vb_lark.y"
{yyval.Expr = create_int_boolean_char_const_expr(3,yyvsp[0].i_const);;
    break;}
case 28:
#line 216 "vb_lark.y"
{yyval.Expr = create_int_boolean_char_const_expr(2,yyvsp[0].c_const);;
    break;}
case 29:
#line 217 "vb_lark.y"
{yyval.Expr = create_string_const_expr(yyvsp[0].s_const);;
    break;}
case 30:
#line 218 "vb_lark.y"
{yyval.Expr = create_int_boolean_char_const_expr(5,yyvsp[0].b_const);;
    break;}
case 31:
#line 219 "vb_lark.y"
{yyval.Expr = create_operator_expr(6,yyvsp[-2].Expr,yyvsp[0].Expr);;
    break;}
case 32:
#line 220 "vb_lark.y"
{yyval.Expr = create_operator_expr(7,yyvsp[-2].Expr,yyvsp[0].Expr);;
    break;}
case 33:
#line 221 "vb_lark.y"
{yyval.Expr = create_operator_expr(8,yyvsp[-2].Expr,yyvsp[0].Expr);;
    break;}
case 34:
#line 222 "vb_lark.y"
{yyval.Expr = create_operator_expr(9,yyvsp[-2].Expr,yyvsp[0].Expr);;
    break;}
case 35:
#line 223 "vb_lark.y"
{yyval.Expr = create_operator_expr(11,yyvsp[-2].Expr,yyvsp[0].Expr);;
    break;}
case 36:
#line 224 "vb_lark.y"
{yyval.Expr = create_operator_expr(10,yyvsp[-2].Expr,yyvsp[0].Expr);;
    break;}
case 37:
#line 225 "vb_lark.y"
{yyval.Expr = create_operator_expr(12,yyvsp[-2].Expr,yyvsp[0].Expr);;
    break;}
case 38:
#line 226 "vb_lark.y"
{yyval.Expr = create_operator_expr(13,yyvsp[-2].Expr,yyvsp[0].Expr);;
    break;}
case 39:
#line 227 "vb_lark.y"
{yyval.Expr = create_operator_expr(14,yyvsp[-2].Expr,yyvsp[0].Expr);;
    break;}
case 40:
#line 228 "vb_lark.y"
{yyval.Expr = create_operator_expr(15,yyvsp[-2].Expr,yyvsp[0].Expr);;
    break;}
case 41:
#line 229 "vb_lark.y"
{yyval.Expr = create_operator_expr(16,yyvsp[-2].Expr,yyvsp[0].Expr);;
    break;}
case 42:
#line 230 "vb_lark.y"
{yyval.Expr = create_operator_expr(17,yyvsp[-2].Expr,yyvsp[0].Expr);;
    break;}
case 43:
#line 231 "vb_lark.y"
{yyval.Expr = create_operator_expr(18,yyvsp[-2].Expr,yyvsp[0].Expr);;
    break;}
case 44:
#line 232 "vb_lark.y"
{yyval.Expr = yyvsp[-1].Expr;;
    break;}
case 45:
#line 233 "vb_lark.y"
{yyval.Expr = create_operator_expr(19,yyvsp[0].Expr,0);;
    break;}
case 46:
#line 236 "vb_lark.y"
{yyval.If_stmt = create_with_Then_expr_stmt_list_end_if_stmt(0,yyvsp[-4].Expr,yyvsp[-1].List,yyvsp[0].End_if);;
    break;}
case 47:
#line 237 "vb_lark.y"
{yyval.If_stmt = create_with_Then_expr_stmt_list_end_if_stmt(1,yyvsp[-3].Expr,yyvsp[-1].List,yyvsp[0].End_if);;
    break;}
case 48:
#line 238 "vb_lark.y"
{yyval.If_stmt = create_if_inline(2,yyvsp[-4].Expr,yyvsp[-2].List,0);;
    break;}
case 49:
#line 239 "vb_lark.y"
{yyval.If_stmt = create_if_inline(3,yyvsp[-6].Expr,yyvsp[-4].List,yyvsp[-2].List);;
    break;}
case 50:
#line 242 "vb_lark.y"
{yyval.List = create_VB_Stmt_list(yyvsp[0].Stmt);;
    break;}
case 51:
#line 243 "vb_lark.y"
{yyval.List = edit_VB_Stmt_list(yyvsp[-2].List,yyvsp[0].Stmt);;
    break;}
case 52:
#line 246 "vb_lark.y"
{yyval.End_if = create_end_if_stmt(0,NULL,NULL,NULL);;
    break;}
case 53:
#line 247 "vb_lark.y"
{yyval.End_if = create_end_if_stmt(1,NULL,yyvsp[-2].List,NULL);;
    break;}
case 54:
#line 248 "vb_lark.y"
{yyval.End_if = create_end_if_stmt(2,yyvsp[-4].Expr,yyvsp[-1].List,yyvsp[0].End_if);;
    break;}
case 55:
#line 249 "vb_lark.y"
{yyval.End_if = create_end_if_stmt(3,yyvsp[-3].Expr,yyvsp[-1].List,yyvsp[0].End_if);;
    break;}
case 56:
#line 252 "vb_lark.y"
{yyval.Dim = create_dim_stmt(yyvsp[-1].As_l);;
    break;}
case 57:
#line 255 "vb_lark.y"
{yyval.As_l = create_as_expr_list(yyvsp[0].As_expr_str,NULL);;
    break;}
case 58:
#line 256 "vb_lark.y"
{yyval.As_l = create_as_expr_list(NULL,yyvsp[0].Arr);;
    break;}
case 59:
#line 257 "vb_lark.y"
{yyval.As_l = add_to_as_expr_list(yyvsp[-2].As_l,yyvsp[0].As_expr_str,NULL);;
    break;}
case 60:
#line 258 "vb_lark.y"
{yyval.As_l = add_to_as_expr_list(yyvsp[-2].As_l,NULL,yyvsp[0].Arr);;
    break;}
case 61:
#line 261 "vb_lark.y"
{yyval.As_expr_str = create_as_expr(0,yyvsp[-2].Id_l,NULL,0,NULL);;
    break;}
case 62:
#line 262 "vb_lark.y"
{yyval.As_expr_str = create_as_expr(0,yyvsp[-2].Id_l,NULL,1,NULL);;
    break;}
case 63:
#line 263 "vb_lark.y"
{yyval.As_expr_str = create_as_expr(0,yyvsp[-2].Id_l,NULL,2,NULL);;
    break;}
case 64:
#line 264 "vb_lark.y"
{yyval.As_expr_str = create_as_expr(0,yyvsp[-2].Id_l,NULL,3,NULL);;
    break;}
case 65:
#line 265 "vb_lark.y"
{yyval.As_expr_str = create_as_expr(0,yyvsp[-4].Id_l,NULL,0,yyvsp[0].Expr);;
    break;}
case 66:
#line 266 "vb_lark.y"
{yyval.As_expr_str = create_as_expr(0,yyvsp[-4].Id_l,NULL,1,yyvsp[0].Expr);;
    break;}
case 67:
#line 267 "vb_lark.y"
{yyval.As_expr_str = create_as_expr(0,yyvsp[-4].Id_l,NULL,2,yyvsp[0].Expr);;
    break;}
case 68:
#line 268 "vb_lark.y"
{yyval.As_expr_str = create_as_expr(0,yyvsp[-4].Id_l,NULL,3,yyvsp[0].Expr);;
    break;}
case 69:
#line 271 "vb_lark.y"
{yyval.Id_l = create_id_list(yyvsp[0].Id);;
    break;}
case 70:
#line 272 "vb_lark.y"
{yyval.Id_l = add_to_id_list(yyvsp[-2].Id_l,yyvsp[0].Id);;
    break;}
case 71:
#line 275 "vb_lark.y"
{yyval.Arr = create_Array(yyvsp[-5].Id,yyvsp[-3].i_const,0);;
    break;}
case 72:
#line 276 "vb_lark.y"
{yyval.Arr = create_Array(yyvsp[-5].Id,yyvsp[-3].i_const,1);;
    break;}
case 73:
#line 277 "vb_lark.y"
{yyval.Arr = create_Array(yyvsp[-5].Id,yyvsp[-3].i_const,2);;
    break;}
case 74:
#line 278 "vb_lark.y"
{yyval.Arr = create_Array(yyvsp[-5].Id,yyvsp[-3].i_const,3);;
    break;}
case 75:
#line 281 "vb_lark.y"
{yyval.Expr_l = create_Expr_list(yyvsp[0].Expr);;
    break;}
case 76:
#line 282 "vb_lark.y"
{yyval.Expr_l = add_Expr_to_list(yyvsp[-2].Expr_l,yyvsp[0].Expr);;
    break;}
case 77:
#line 285 "vb_lark.y"
{yyval.For = create_for_stmt(yyvsp[-8].Id,yyvsp[-6].i_const,yyvsp[-4].i_const,yyvsp[-2].List);;
    break;}
case 78:
#line 286 "vb_lark.y"
{yyval.For = create_for_with_step_stmt(yyvsp[-10].Id,yyvsp[-8].i_const,yyvsp[-6].i_const,yyvsp[-4].i_const,yyvsp[-2].List);;
    break;}
case 79:
#line 287 "vb_lark.y"
{yyval.For = create_for_with_decl_stmt(yyvsp[-10].Id,0,yyvsp[-6].i_const,yyvsp[-4].i_const,yyvsp[-2].List);;
    break;}
case 80:
#line 288 "vb_lark.y"
{yyval.For = create_for_with_decl_stmt(yyvsp[-10].Id,1,yyvsp[-6].i_const,yyvsp[-4].i_const,yyvsp[-2].List);;
    break;}
case 81:
#line 289 "vb_lark.y"
{yyval.For = create_for_with_decl_stmt(yyvsp[-10].Id,2,yyvsp[-6].i_const,yyvsp[-4].i_const,yyvsp[-2].List);;
    break;}
case 82:
#line 290 "vb_lark.y"
{yyval.For = create_for_with_decl_with_step_stmt(yyvsp[-12].Id,0,yyvsp[-8].i_const,yyvsp[-6].i_const,yyvsp[-4].i_const,yyvsp[-2].List);;
    break;}
case 83:
#line 291 "vb_lark.y"
{yyval.For = create_for_with_decl_with_step_stmt(yyvsp[-12].Id,1,yyvsp[-8].i_const,yyvsp[-6].i_const,yyvsp[-4].i_const,yyvsp[-2].List);;
    break;}
case 84:
#line 292 "vb_lark.y"
{yyval.For = create_for_with_decl_with_step_stmt(yyvsp[-12].Id,2,yyvsp[-8].i_const,yyvsp[-6].i_const,yyvsp[-4].i_const,yyvsp[-2].List);;
    break;}
case 85:
#line 295 "vb_lark.y"
{yyval.While = create_while_stmt(yyvsp[-4].Expr,yyvsp[-2].List);;
    break;}
case 86:
#line 298 "vb_lark.y"
{yyval.Do_loop = create_do_loop_stmt(0,yyvsp[-4].Expr,yyvsp[-2].List);;
    break;}
case 87:
#line 299 "vb_lark.y"
{yyval.Do_loop = create_do_loop_stmt(1,yyvsp[-4].Expr,yyvsp[-2].List);;
    break;}
case 88:
#line 300 "vb_lark.y"
{yyval.Do_loop = create_do_loop_stmt(2,yyvsp[-1].Expr,yyvsp[-4].List);;
    break;}
case 89:
#line 301 "vb_lark.y"
{yyval.Do_loop = create_do_loop_stmt(3,yyvsp[-1].Expr,yyvsp[-4].List);;
    break;}
case 90:
#line 304 "vb_lark.y"
{yyval.Enum = create_enum_stmt(yyvsp[-4].Id,yyvsp[-2].Enum_l);;
    break;}
case 91:
#line 307 "vb_lark.y"
{yyval.Enum_l = create_enum_list(yyvsp[-1].Enum_e);;
    break;}
case 92:
#line 308 "vb_lark.y"
{yyval.Enum_l = add_to_enum_list(yyvsp[-2].Enum_l,yyvsp[-1].Enum_e);;
    break;}
case 93:
#line 311 "vb_lark.y"
{yyval.Enum_e = create_enum_expr(yyvsp[0].Id,-1);;
    break;}
case 94:
#line 312 "vb_lark.y"
{yyval.Enum_e = create_enum_expr(yyvsp[-2].Id,yyvsp[0].i_const);;
    break;}
case 95:
#line 315 "vb_lark.y"
{yyval.Sub = create_sub_stmt(yyvsp[-6].Id,NULL,yyvsp[-2].List);;
    break;}
case 96:
#line 316 "vb_lark.y"
{yyval.Sub = create_sub_stmt(yyvsp[-7].Id,yyvsp[-5].Param_l,yyvsp[-2].List);;
    break;}
case 97:
#line 319 "vb_lark.y"
{yyval.Param_l = create_param_list(yyvsp[0].Param);;
    break;}
case 98:
#line 320 "vb_lark.y"
{yyval.Param_l = add_to_param_list(yyvsp[-2].Param_l,yyvsp[0].Param);;
    break;}
case 99:
#line 323 "vb_lark.y"
{yyval.Param = create_param_stmt(yyvsp[-2].Id,0);;
    break;}
case 100:
#line 324 "vb_lark.y"
{yyval.Param = create_param_stmt(yyvsp[-2].Id,1);;
    break;}
case 101:
#line 325 "vb_lark.y"
{yyval.Param = create_param_stmt(yyvsp[-2].Id,2);;
    break;}
case 102:
#line 326 "vb_lark.y"
{yyval.Param = create_param_stmt(yyvsp[-2].Id,3);;
    break;}
case 103:
#line 329 "vb_lark.y"
{yyval.Func = create_func_stmt(yyvsp[-11].Id,NULL,0,yyvsp[-5].List,yyvsp[-3].Expr);;
    break;}
case 104:
#line 330 "vb_lark.y"
{yyval.Func = create_func_stmt(yyvsp[-11].Id,NULL,1,yyvsp[-5].List,yyvsp[-3].Expr);;
    break;}
case 105:
#line 331 "vb_lark.y"
{yyval.Func = create_func_stmt(yyvsp[-11].Id,NULL,2,yyvsp[-5].List,yyvsp[-3].Expr);;
    break;}
case 106:
#line 332 "vb_lark.y"
{yyval.Func = create_func_stmt(yyvsp[-11].Id,NULL,3,yyvsp[-5].List,yyvsp[-3].Expr);;
    break;}
case 107:
#line 333 "vb_lark.y"
{yyval.Func = create_func_stmt(yyvsp[-12].Id,yyvsp[-10].Param_l,0,yyvsp[-5].List,yyvsp[-3].Expr);;
    break;}
case 108:
#line 334 "vb_lark.y"
{yyval.Func = create_func_stmt(yyvsp[-12].Id,yyvsp[-10].Param_l,1,yyvsp[-5].List,yyvsp[-3].Expr);;
    break;}
case 109:
#line 335 "vb_lark.y"
{yyval.Func = create_func_stmt(yyvsp[-12].Id,yyvsp[-10].Param_l,2,yyvsp[-5].List,yyvsp[-3].Expr);;
    break;}
case 110:
#line 336 "vb_lark.y"
{yyval.Func = create_func_stmt(yyvsp[-12].Id,yyvsp[-10].Param_l,3,yyvsp[-5].List,yyvsp[-3].Expr);;
    break;}
case 111:
#line 339 "vb_lark.y"
{yyval.Try_catch = create_Try_Catch(yyvsp[-7].List,yyvsp[-6].Catch_l,yyvsp[-3].List);;
    break;}
case 112:
#line 342 "vb_lark.y"
{yyval.Catch_l = create_Catch_stmt_list(yyvsp[0].Catch);;
    break;}
case 113:
#line 343 "vb_lark.y"
{yyval.Catch_l = add_new_Catch_stmt(yyvsp[-1].Catch_l,yyvsp[0].Catch);;
    break;}
case 114:
#line 346 "vb_lark.y"
{yyval.Catch = create_Catch_stmt(yyvsp[-4].Id,yyvsp[0].List);;
    break;}
case 115:
#line 349 "vb_lark.y"
{yyval.Throw = create_Throw(yyvsp[-2].s_const);;
    break;}
case 116:
#line 352 "vb_lark.y"
{yyval.console_print = create_Print(yyvsp[-2].s_const);;
    break;}
case 117:
#line 355 "vb_lark.y"
{yyval.console_println = create_Println(yyvsp[-2].s_const);;
    break;}
case 118:
#line 358 "vb_lark.y"
{yyval.console_read = create_Read();;
    break;}
case 119:
#line 361 "vb_lark.y"
{yyval.console_readln = create_Readln();;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 363 "vb_lark.y"


void yyerror (char const* s)
{
	printf("%s\n",s);
	getchar();
	exit(0);
}

int main (int argc, char* argv[])
{
	FILE* file;
	
	file = fopen("result.txt", "wt");
	yyin = fopen(argv[1], "r");
	
	//yylex();	// ����������
	
	yyparse();
	
	print_tree();		// ����� ������

	fclose(file);
	getchar();
	return 0;
}
