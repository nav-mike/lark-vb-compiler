%{
	#include "tree_nodes.h"
	#include <stdio.h>
	
	extern int yylex(void);
	
	struct VB_Module_stmt* root;
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
	
	enum VB_Id_type				Id_type;

	struct VB_Console_print_stmt*	console_print;
	struct VB_Console_println_stmt*	console_println;
	struct VB_Console_read_stmt*	console_read;
	struct VB_Console_readln_stmt*	console_readln;
}

%type <Module>		module_stmt
%type <List>		stmt_list
%type <Stmt>		stmt
%type <Expr>		expr
%type <Expr_l>		expr_list
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

%type <Id_type>		id_type

%type <console_print>	console_print_stmt
%type <console_println> console_println_stmt
%type <console_read>	console_read_stmt 
%type <console_readln>	console_readln_stmt

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

	module_stmt: MODULE ID ENDL stmt_list END_MODULE ENDL {root = $$;$$ = create_VB_Module_stmt($2,$4);}
			   ;
		
	stmt_list: stmt			{$$ = create_VB_Stmt_list($1);}
		 | stmt_list stmt	{$$ = edit_VB_Stmt_list($1,$2);}
		 ;
			 	     
	stmt: ENDL
		| expr ENDL				{$$ = create_VB_Stmt_Expr($1);}
		| if_stmt				{$$ = create_VB_Stmt_If($1);}
		| dim_stmt				{$$ = create_VB_Stmt_Dim($1);}
		| for_stmt				{$$ = create_VB_Stmt_For($1);}
		| while_stmt			{$$ = create_VB_Stmt_While($1);}
		| do_loop_stmt			{$$ = create_VB_Stmt_Do_Loop($1);}
		| enum_stmt				{$$ = create_VB_Stmt_Enum($1);}
		| sub_stmt				{$$ = create_VB_Stmt_Sub($1);}
		| func_stmt				{$$ = create_VB_Stmt_Func($1);}
		| try_catch_stmt		{$$ = create_VB_Stmt_Try_Catch($1);}
		| throw_stmt			{$$ = create_VB_Stmt_Throw($1);}
		| console_print_stmt	{$$ = create_VB_Stmt_Print($1);}
		| console_println_stmt	{$$ = create_VB_Stmt_Println($1);}
		| console_read_stmt		{$$ = create_VB_Stmt_Read($1);}
		| console_readln_stmt	{$$ = create_VB_Stmt_Readln($1);}
		;
					
	expr: ID						{$$ = create_id_expr($1);}
		| ID'('expr_list')'			{$$ = create_func_expr($1,$3);}
		| INT_CONST					{$$ = create_int_boolean_char_const_expr(INT_CONST,$1);}
		| CHAR_CONST				{$$ = create_int_boolean_char_const_expr(CHAR_CONST,$1);}
		| STRING_CONST				{$$ = create_string_const_expr($1);}
		| BOOLEAN_CONST				{$$ = create_int_boolean_char_const_expr(BOOLEAN_CONST,$1);}
		| expr '=' expr				{$$ = create_operator_expr(ASSIGN,$1,$3);}
		| expr '+' expr				{$$ = create_operator_expr(PLUS,$1,$3);}
		| expr '-' expr				{$$ = create_operator_expr(MINUS,$1,$3);}
		| expr '*' expr				{$$ = create_operator_expr(MUL,$1,$3);}
		| expr '/' expr				{$$ = create_operator_expr(DIV,$1,$3);}
		| expr '\\' expr			{$$ = create_operator_expr(INT_DIV,$1,$3);}
		| expr '^' expr				{$$ = create_operator_expr(POWER,$1,$3);}
		| expr '>' expr				{$$ = create_operator_expr(MORE,$1,$3);}
		| expr '<' expr				{$$ = create_operator_expr(LESS,$1,$3);}
		| expr MORE_OR_EQUAL expr	{$$ = create_operator_expr(MORE_OR_EQUAL,$1,$3);}
		| expr LESS_OR_EQUAL expr	{$$ = create_operator_expr(LESS_OR_EQUAL,$1,$3);}
		| expr NONEQUAL	expr		{$$ = create_operator_expr(NONEQUAL,$1,$3);}
		| expr EQUAL	expr		{$$ = create_operator_expr(EQUAL,$1,$3);}
		| expr'('expr')'			{$$ = create_operator_expr(GET_ITEM,$1,$3);}
		| '('expr')'				{$$ = $2;}
		| '-' expr %prec UMINUS		{$$ = create_operator_expr(UMINUS,$2,0);}
		| '+' expr %prec UPLUS		{$$ = create_operator_expr(UPLUS,$2,0);}
		;
			
	if_stmt: IF expr THEN ENDL stmt_list end_if_stmt	{$$ = create_with_Then_expr_stmt_list_end_if_stmt(IF_THEN,$2,$5,$6);}
		   | IF expr ENDL stmt_list end_if_stmt			{$$ = create_with_Then_expr_stmt_list_end_if_stmt(IF_ENDL,$2,$4,$5);}
		   | IF expr THEN stmt_list_inline END_IF ENDL	{$$ = create_if_inline(IF_INLINE,$2,$4,0);}
		   | IF expr THEN stmt_list_inline ELSE stmt_list_inline END_IF ENDL	{$$ = create_if_inline(IF_ELSE_INLINE,$2,$4,$6);}
		   ;
		   
		stmt_list_inline: stmt						{$$ = create_VB_Stmt_list($1);}
						| stmt_list_inline ':' stmt	{$$ = edit_VB_Stmt_list($1,$3);}
						;
		   
		end_if_stmt: END_IF ENDL								 {$$ = create_end_if_stmt(ENDIF,NULL,NULL,NULL);}
				   | ELSE ENDL stmt_list END_IF ENDL			 {$$ = create_end_if_stmt(ELSE,NULL,$3,NULL);}
				   | ELSEIF expr THEN ENDL stmt_list end_if_stmt {$$ = create_end_if_stmt(ELSE_IF_THEN,$2,$5,$6);}
				   | ELSEIF expr ENDL stmt_list end_if_stmt		 {$$ = create_end_if_stmt(ELSE_IF_ENDL,$2,$4,$5);}
				   ;			   		

	dim_stmt: DIM as_expr_list ENDL			{$$ = create_dim_stmt($2);}
			;
		   
		as_expr_list: as_expr					 {$$ = create_as_expr_list($1,NULL);}
					| array_expr				 {$$ = create_as_expr_list(NULL,$1);}
					| as_expr_list',' as_expr	 {$$ = add_to_as_expr_list($1,$3,NULL);}
					| as_expr_list',' array_expr {$$ = add_to_as_expr_list($1,NULL,$3);}
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
		
		array_expr: ID '('INT_CONST')' AS id_type				{$$ = create_Array($1,$3,$6);}
				  | ID '('')' AS id_type '=' '{'expr_list'}'	{$$ = create_Array_with_init($1,$5,$8);}
				  ;

		expr_list: expr					{$$ = create_Expr_list($1);}
				 | expr_list',' expr	{$$ = add_Expr_to_list($1,$3);}
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
			 
	try_catch_stmt: TRY ENDL stmt_list catch_stmt_list FINALLY ENDL stmt_list ENDL TRY ENDL {$$ = create_Try_Catch($3,$4,$7);}
				  ;
			 
		catch_stmt_list: catch_stmt						{$$ = create_Catch_stmt_list($1);}
					   | catch_stmt_list catch_stmt		{$$ = add_new_Catch_stmt($1,$2);}
					   ;		
									
		catch_stmt: CATCH ID AS EXCEPTION ENDL stmt_list	{$$ = create_Catch_stmt($2,$6);}
				  ;
	
	throw_stmt: THROW NEW SYSTEM '.' EXCEPTION '(' STRING_CONST ')' ENDL  {$$ = create_Throw($7);}
			  ;		

	console_print_stmt: CONSOLE '.' WRITE '(' STRING_CONST ')' ENDL		  {$$ = create_Print($5);}
					  ;
				 
	console_println_stmt: CONSOLE '.' WRITELINE '(' STRING_CONST ')' ENDL {$$ = create_Println$5);}
						;
				   
	console_read_stmt: CONSOLE '.' READ '('')' ENDL						  {$$ = create_Read();}
					 ;
				
	console_readln_stmt: CONSOLE '.' READLINE '('')' ENDL				  {$$ = create_Readln();}
					   ;							   	
%%

int main (int argc, char* argv[])
{
	return 0;
}
