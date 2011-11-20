%{
	#include "tree_nodes.h"
	#include <stdio.h>
	
	extern int yylex(void);
%}

%start module_stmt

%union
{
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
	struct VB_As_expr*			As;
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

	struct VB_Console_print_stmt*	console_print;
	struct VB_Console_println_stmt*	console_println;
	struct VB_Console_read_stmt*	console_read;
	struct VB_Console_readln_stmt*	console_readln;
	struct VB_Console_readkey_stmt*	console_readkey;
}

%type <Module>		module_stmt
%type <List>		stmt_list
%type <Stmt>		stmt
%type <Expr>		expr
%type <Expr_l>  expr_list
%type <If_stmt>		if_stmt
%type <List>		stmt_list_inline
%type <End_if>		end_if_stmt
%type <Dim>			dim_stmt
%type <As_l>		as_expr_list
%type <As>			as_expr
%type <Id_l>		id_list_stmt
%type <Arr>			array_expr
%type <For>			for_stmt 
%type <While>		while_stmt 
%type <Do_loop> 	do_loop_stmt
%type <Enum>		enum_stmt
%type <Enum_l>  	enum_expr_list 
%type <Enum_e>		enum_expr
%type <Sub>			sub_stmt
%type <Param_l> 	param_list 
%type <Param>		param_stmt
%type <Func>		func_stmt
%type <Try_catch>	try_catch_stmt
%type <Catch_l>		catch_stmt_list
%type <Catch>		catch_stmt
%type <Throw>		throw_stmt

%type <console_print>	console_print_stmt
%type <console_println> console_println_stmt
%type <console_read>	console_read_stmt 
%type <console_readln>	console_readln_stmt
%type <console_readkey> console_readkey_stmt

%token <b_const> BOOLEAN_CONST
%token <i_const> INT_CONST
%token <s_const> STRING_CONST
%token <c_const> CHAR_CONST

%token <Id> 	ID

%token ENDL
%token DIM
%token AS
%token IF
%token THEN
%token ELSE
%token ELSEIF
%token END_IF
%token FUNCTION
%token BYVAL
%token RETURN
%token END_FUNCTION
%token SUB
%token END_SUB
%token TRY
%token CATCH
%token END_TRY
%token THROW
%token NEW
%token BYREF
%token CALL
%token CASE
%token CONST
%token SELECT
%token WHILE
%token UNTIL
%token MODULE
%token DO
%token ENUM
%token END_ENUM
%token END_MODULE
%token END_SELECT
%token END_WHILE
%token LOOP
%token FOR_EACH
%token FOR
%token TO
%token NEXT
%token IN
%token MOD
%token STEP
%token EXCEPTION
%token INTEGER
%token CHAR
%token STRING
%token BOOLEAN
%token CONSOLE
%token WRITE
%token WRITELINE
%token READ
%token READLINE
%token READKEY
%token SYSTEM
%token FINALLY

%right '='
%left '>' '<' MORE_OR_EQUAL LESS_OR_EQUAL NONEQUAL EQUAL
%left '+' '-'
%left '*' '/' '\\'
%left '^'
%left UMINUS
%nonassoc ')'

%%

	module_stmt: MODULE ID ENDL stmt_list END_MODULE ENDL
			   ;
		
	stmt_list: stmt
		 | stmt_list stmt
		 ;
			 	     
	stmt: ENDL
		| expr ENDL
		| if_stmt
		| dim_stmt
		| for_stmt
		| while_stmt
		| do_loop_stmt
		| enum_stmt
		| sub_stmt
		| func_stmt
		| try_catch_stmt
		| throw_stmt
		| console_print_stmt
		| console_println_stmt
		| console_read_stmt
		| console_readln_stmt
		| console_readkey_stmt
		;
					
	expr: ID
		| ID'('expr_list')'
		| INT_CONST
		| CHAR_CONST
		| STRING_CONST
		| BOOLEAN_CONST
		| expr '=' expr
		| expr '+' expr
		| expr '-' expr
		| expr '*' expr
		| expr '/' expr
		| expr '\\' expr
		| expr '^' expr
		| expr '>' expr
		| expr '<' expr
		| expr MORE_OR_EQUAL expr
		| expr LESS_OR_EQUAL expr
		| expr NONEQUAL	expr
		| expr EQUAL	expr
		| expr'('expr')'
		| '-' expr %prec UMINUS
		| '+' expr %prec UPLUS
		;
			
	if_stmt: IF expr THEN ENDL stmt_list end_if_stmt
		   | IF expr ENDL stmt_list end_if_stmt
		   | IF expr THEN stmt_list_inline END_IF ENDL
		   | IF expr THEN stmt_list_inline ELSE stmt_list_inline END_IF ENDL
		   ;
		   
		stmt_list_inline: stmt
						| stmt_list_inline ':' stmt
						;
		   
		end_if_stmt: END_IF ENDL
				   | ELSE ENDL stmt_list END_IF ENDL
				   | ELSEIF expr THEN ENDL stmt_list end_if_stmt
				   | ELSEIF expr ENDL stmt_list end_if_stmt
				   ;			   
		   
	dim_stmt: DIM as_expr_list ENDL
			;
		   
		as_expr_list: as_expr
					| array_expr
					| as_expr_list',' as_expr
					| as_expr_list',' array_expr
					;	   

		as_expr: id_list_stmt AS id_type
			   | ID AS id_type
			   | ID AS id_type '=' expr
			   ;				
	
		id_type: INTEGER
			   | BOOLEAN
			   | CHAR 
			   | STRING
			   ;
	       
		id_list_stmt: ID
					| id_list_stmt',' ID
					;	
		
		array_expr: ID '('INT_CONST')' AS id_type
				  | ID '('')' AS id_type '=' '{'expr_list'}'
				  ;
		
		expr_list: expr
				 | expr_list',' expr
				 ;	
		
	for_stmt: FOR ID '=' INT_CONST TO INT_CONST ENDL stmt_list NEXT ENDL
			| FOR ID '=' INT_CONST TO INT_CONST STEP INT_CONST ENDL stmt_list NEXT ENDL
			| FOR ID AS id_type '=' INT_CONST TO INT_CONST ENDL stmt_list NEXT ENDL
			| FOR ID AS id_type '=' INT_CONST TO INT_CONST STEP INT_CONST ENDL stmt_list NEXT ENDL
			;				

	while_stmt: WHILE expr ENDL stmt_list END_WHILE ENDL
			  ;			  

	do_loop_stmt: DO WHILE expr ENDL stmt_list LOOP ENDL
				| DO UNTIL expr ENDL stmt_list LOOP ENDL
				| DO ENDL stmt_list LOOP WHILE expr ENDL
				| DO ENDL stmt_list LOOP UNTIL expr ENDL
				;			 			 		
	
	enum_stmt: ENUM ID ENDL enum_expr_list END_ENUM ENDL
			 ;			  

		enum_expr_list: enum_expr ENDL
					  | enum_expr_list enum_expr ENDL
					  ;
	
		enum_expr: ID
			 	 | ID '=' INT_CONST
				 ;
	
	sub_stmt: SUB ID '('')' ENDL stmt_list END_SUB ENDL
			| SUB ID '('param_list')' ENDL stmt_list END_SUB ENDL
			;		

		param_list: param_stmt
				  | param_list',' param_stmt
				  ;

		param_stmt: BYREF ID AS id_type
				  | BYVAL ID AS id_type
				  ; 

	func_stmt: FUNCTION ID '('')' AS id_type ENDL stmt_list RETURN expr ENDL END_FUNCTION ENDL
			 | FUNCTION ID '('param_list')' AS id_type ENDL stmt_list RETURN expr ENDL END_FUNCTION ENDL
			 ;
			 
	try_catch_stmt: TRY ENDL stmt_list catch_stmt_list FINALLY ENDL stmt_list ENDL TRY ENDL
				  ;
			 
		catch_stmt_list: catch_stmt
					   | catch_stmt_list catch_stmt
					   ;		
									
		catch_stmt: CATCH ID AS EXCEPTION ENDL stmt_list
				  ;
	
	throw_stmt: THROW NEW SYSTEM '.' EXCEPTION '(' STRING_CONST ')' ENDL
			  ;		

	console_print_stmt: CONSOLE '.' WRITE '(' STRING ')' ENDL
					  ;
				 
	console_println_stmt: CONSOLE '.' WRITELINE '(' STRING ')' ENDL
						;
				   
	console_read_stmt: CONSOLE '.' READ '('')' ENDL
					 ;
				
	console_readln_stmt: CONSOLE '.' READLINE '('')' ENDL
					   ;							   	
%%

int main (int argc, char* argv[])
{
	return 0;
}
