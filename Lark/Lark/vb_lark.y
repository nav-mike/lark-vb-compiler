%{
	#include "tree_nodes.h"
	
%}
%start stmt_module

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
%left '*' '/' '\'
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
		| expr '\' expr
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
		   
	dim_stmt: DIM expr_list AS INTEGER
			| DIM expr_list AS BOOLEAN
			| DIM expr_list AS CHAR
			| DIM expr_list AS STRING
			| DIM expr AS INTEGER '=' expr
			| DIM expr AS BOOLEAN '=' expr
			| DIM expr AS CHAR '=' expr
			| DIM expr AS STRING '=' expr
			;
			
	
%%

int main (int argc, char* argv[])
{
	return 0;
}