%{
	#include "tree_nodes.h"
	
%}
%start stmt_module			// ѕереопредел€ем им€ стартового нетерминала

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
%token BOOLEAN
%token INTEGER
%token NEW
%token BYREF
%token CALL
%token CASE
%token CHAR
%token CONST
%token SELECT
%token DO_WHILE
%token DO_UNTIL
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
%token STRING
%token MOD

%right '=' ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MUL ASSIGN_DIV ASSIGN_INT_DIV
%left '+' '-' '>' '<' MORE_OR_EQUAL LESS_OR_EQUAL NONEQUAL
%left '*' '/' '\\'
%left '^'
%left UMINUS UPLUS
%nonassoc ')'

%%
	expr_list: expr
			 | expr_list ',' expr
			 ;
			  
	expr:
		| ID
		| INT_CONST
		| CHAR_CONST
		| STRING_CONST
		| BOOL_CONST
		| expr '=' expr
		| expr '+' expr
		| expr '-' expr
		| expt '*' expr
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
		| '(' expr ')'
		| '-' expr %prec UMINUS
		| '+' expr %prec UPLUS
		;
		
	stmt: expr ENDL
		| if_stmt
		| dim_stmt
		;
		
	type_vb: INTEGER
		   | CHAR
		   | STRING
		   | BOOLEAN
		   ;
		   
	sub_stmt_list: stmt_list
				 ;
				 
	parametr: BYREF as_expr
			| BYVAL as_expr
			| PARAM_ARRAY as_expr
			;
				 
	parametrs_list: parametr
				  | parametr_list parametr
				  ;
	
	sub_proc: SUB ID '('')' sub_stmt_list END_SUB
			| SUB ID '('parametrs_list')' sub_stmt_list END_SUB
			;
			
	func_stmt_list: sub_stmt_list RETURN expr
	
	func_proc: FUNCTION '('')' AS type_vb func_stmt_list END_FUNCTION
			 | FUNCTION '('parametrs_list')' func_stmt_list END_FUNCTION
			 ;
		
	stmt_list: stmt
			 | stmt_list stmt
			 ;
			 
	stmt_module: stmt_list
			   ;
		
	elseif_stmt: ELSEIF expr THEN stmt_list
	
	elseif_stmt_list: elseif_stmt
					| elseif_stmt_list elseif_stmt
					;
	
	if_stmt: IF expr THEN stmt_list END_IF
		   | IF expr THEN stmt_list ELSE stmt_list END_IF
		   | IF expr THEN stmt_list elseif_stmt_list END_IF
		   | IF expr THEN stmt_list elseif_stmt_list ELSE stmt_list END_IF
		   ;
		   
	as_expr: expr_list AS type_vb
		   | expr AS type_vb '=' expr
		   ;
		   
	dim_stmt: DIM as_expr
			| DIM as_expr
			;
			
	catch_stmt: CATCH as_expr
			  ;
	
	catch_stmt_list: catch_stmt stmt_list
				   ;
			
	try_stmt: TRY stmt_list catch_stmt_list END_TRY
			;
			
	throw_stmt: THROW NEW SYSTEM '.' EXCEPTION '(' STRING ')'
			  ;
			  
	for_each_stmt: FOR EACH as_expr IN ID stmt_list NEXT
				 ;
				 
	foe_stmt: FOR ID '=' INT_CONST TO ID stmt_list NEXT
			;
			
	while_stmt: WHILE expr stmt_list END_WHILE
			  ;
			  
	do_loop_until_stmt: DO stmt_list LOOP UNTIL expr
					  ;
					  
	enum_expr: ID
			 | ID '=' INT_CONST
			 ;
			 
	enum_expr_list: enum_expr
				  | eunum_expr_list enum_expr
				  ;
				  
	enum_stmt: ENUM ID enum_expr_list END_ENUM
			 ;
			
	console_print: CONSOLE '.' WRITE '(' STRING ')'
				 ;
	console_println: CONSOLE '.' WRITELINE '(' STRING ')'
				   ;
	console_read: CONSOLE '.' READ '('')'
				;
	console_readln: CONSOLE '.' READLINE '('')'
				  ;
	console_read_key: CONSOLE '.' READKEY '('')'
					;
					
	module_stmt: MODULE ID stmt_list END_MODULE
			   ;
	
%%

int main (int argc, char* argv[])
{
	return 0;
}