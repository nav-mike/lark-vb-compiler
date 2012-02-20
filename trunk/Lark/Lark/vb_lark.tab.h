/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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

/* Line 2068 of yacc.c  */
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



/* Line 2068 of yacc.c  */
#line 165 "vb_lark.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;

