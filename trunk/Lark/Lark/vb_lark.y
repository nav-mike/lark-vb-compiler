%{
	#include "tree_nodes.h"
	#include <stdio.h>
	
	extern int yylex(void);
%}

%start stmt_module

%union
{
	bool	b_const;
	int		i_const;
	char	c_const;
	char*	s_const;
	
	struct VB_Stmt_module*	module_str;
	struct VB_Stmt_list*	list_str;
	struct VB_Stmt*			stmt_str;
	struct VB_Expr*			expr_str;
	struct VB_If_stmt*		if_str;
	struct VB_End_if_stmt*	end_if_str;
	struct VB_Dim_stmt*		dim_str;
	struct VB_As_Stmt_list*	as_list_str;
	struct VB_As_stmt*		as_str;
	
}









%token <expr_str>	ID

%token <b_const> BOOLEAN_CONST
%token <i_const> INT_CONST
%token <s_const> STRING_CONST
%token <c_const> CHAR_CONST


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
%token EQUAL


%right '=' ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MUL ASSIGN_DIV ASSIGN_INT_DIV
%left '>' '<' MORE_OR_EQUAL LESS_OR_EQUAL NONEQUAL
%left '+' '-'
%left '*' '/' '\\'
%left '^'
%left UMINUS
%nonassoc ')'

%%

	stmt_module: stmt_list
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
		| catch_stmt
		| try_stmt
		| throw_stmt
		| console_print_stmt
		| console_println_stmt
		| console_read_stmt
		| console_readln_stmt
		| console_readkey_stmt
		| module_stmt
		;
					  
	expr: ID
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
		| expr MORE_OR_EQUAL 	expr
		| expr LESS_OR_EQUAL 	expr
		| expr ASSIGN_PLUS 		expr
		| expr ASSIGN_MINUS 	expr
		| expr ASSIGN_MUL 		expr
		| expr ASSIGN_DIV 		expr
		| expr ASSIGN_INT_DIV 	expr
		| expr NONEQUAL			expr
		| expr EQUAL			expr
		| '(' expr ')'
		| '-' expr %prec UMINUS
		| '+' expr %prec UPLUS
		;
				
	if_stmt: IF expr THEN ENDL stmt_list end_if_stmt
		   | IF expr ENDL stmt_list end_if_stmt
		   | IF expr THEN stmt_list_inline END_IF
		   | IF expr THEN stmt_list_inline ELSE stmt_list_inline END_IF
		   ;
		   
	stmt_list_inline: stmt
					| stmt_list_inline ':' stmt
					;
					
	end_if_stmt: END_IF
			   | ELSE stmt_list END_IF
		       | ELSEIF expr THEN stmt_list end_if_stmt
		       | ELSEIF expr ENDL stmt_list end_if_stmt
		       ;		
		       
	dim_stmt: DIM as_stmt_list
			;
			
	as_stmt_list: as_stmt
				| as_stmt_list',' as_stmt
				;			
		
	as_stmt: id_list as_stmt_type
		   | ID as_stmt_type
		   | ID as_stmt_type '=' expr
		   ;	
			  
	as_stmt_type: AS INTEGER
			    | AS BOOLEAN
			    | AS CHAR 
			    | AS STRING
			    ;

	id_list: ID
		   | id_list',' ID
		   ;		
		
	for_stmt: FOR ID '=' INT_CONST TO INT_CONST stmt_list NEXT
			| FOR ID '=' INT_CONST TO INT_CONST stmt_list STEP INT_CONST NEXT
			| FOR ID as_stmt_type '=' INT_CONST TO INT_CONST stmt_list NEXT
			| FOR ID as_stmt_type '=' INT_CONST TO INT_CONST stmt_list STEP INT_CONST NEXT
			;	
			
	while_stmt: WHILE expr stmt_list END_WHILE
			  ;	

	do_loop_stmt: DO WHILE expr stmt_list LOOP
				| DO UNTIL expr stmt_list LOOP
				| DO stmt_list LOOP WHILE expr
				| DO stmt_list LOOP UNTIL expr
				;

	enum_stmt: ENUM ID enum_member_list END_ENUM
			 ;

	enum_member_list: enum_expr
					| enum_member_list enum_expr
					;

	enum_expr: ID
			 | ID '=' INT_CONST
			 ;
			 
	sub_stmt: SUB ID '('')' stmt_list END_SUB
			| SUB ID '('param_list')' stmt_list END_SUB
			;
			
	param_list: param
		      | param_list',' param
			  ;

	param: BYREF ID as_stmt_type
	     | BYVAL ID as_stmt_type
		 ; 

	func_stmt: FUNCTION ID '('')' as_stmt_type func_stmt_list END_FUNCTION
			 | FUNCTION ID '('param_list')' as_stmt_type func_stmt_list END_FUNCTION
			 ;					 
				
	func_stmt_list: stmt_list RETURN expr
				  ;   

	catch_stmt: CATCH ID AS EXCEPTION ENDL stmt_list
			  ;
	
	catch_stmt_list: catch_stmt
				   | catch_stmt_list catch_stmt
				   ;
			
	try_stmt: TRY stmt_list catch_stmt_list END_TRY
			;
			
	throw_stmt: THROW NEW SYSTEM '.' EXCEPTION '(' STRING ')'
			  ;			  

	console_print_stmt: CONSOLE '.' WRITE '(' STRING ')'
					  ;
				 
	console_println_stmt: CONSOLE '.' WRITELINE '(' STRING ')'
						;
				   
	console_read_stmt: CONSOLE '.' READ '('')'
					 ;
				
	console_readln_stmt: CONSOLE '.' READLINE '('')'
					   ;
				  
	console_readkey_stmt: CONSOLE '.' READKEY '('')'
						;
					
	module_stmt: MODULE ID stmt_list END_MODULE
			   ;
	
%%

int main (int argc, char* argv[])
{
	return 0;
}