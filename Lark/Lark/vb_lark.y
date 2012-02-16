%{
	#include <stdio.h>
	#include <malloc.h>
	#include "dot.h"

	extern int yylex(void);
	//extern int yyparse(void);

	struct VB_Module_stmt* root;

	void yyerror (char const* s);

	int get_location ();
	
	extern FILE* yyin;
%}


%start module_stmt

%union
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
}



%type <Module>		module_stmt
%type <List>		stmt_list
%type <List>		stmt_listE
%type <Stmt>		stmt
%type <Expr>		expr
%type <Expr_l>		expr_list
%type <Expr_l>		expr_list_empty
%type <If_stmt>		if_stmt
//%type <List>		stmt_list_inline
//%type <End_if>	end_if_stmt
%type <Dim>			dim_stmt
%type <As_l>		as_expr_list
%type <As_expr_str>	as_expr
%type <Id_l>		id_list_stmt
//%type <Arr>			array_expr
%type <For>			for_stmt
%type <While>		while_stmt
%type <Do_loop> 	do_loop_stmt
//%type <Enum>		enum_stmt
//%type <Enum_l>  	enum_expr_list
//%type <Enum_e>		enum_expr
%type <Sub>			sub_stmt
%type <Param_l> 	param_list
%type <Param>		param_stmt
%type <Func>		func_stmt
//%type <Try_catch>	try_catch_stmt
//%type <Catch_l>		catch_stmt_list
//%type <Catch>		catch_stmt
//%type <Throw>		throw_stmt

%type <Decl_l>		decl_stmt_listE
%type <Decl_l>		decl_stmt_list
%type <Decl>		decl_stmt

%type <Id_type> param_type
%type <Ret> return_stmt

/*%type <console_print>	console_print_stmt		*/
/*%type <console_println> console_println_stmt	*/
/* %type <console_read>	console_read_stmt		*/
/* %type <console_readln>	console_readln_stmt	*/

%token <b_const> TRUE
%token <b_const> FALSE
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
%token BYREF
%token RETURN
%token END_FUNCTION
%token SUB
%token END_SUB
%token TRY
%token CATCH
%token END_TRY
%token THROW
%token NEW
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
%token STRING_T
%token BOOLEAN
%token CONSOLE
%token WRITE
%token WRITELINE
%token READ
%token READLINE
%token SYSTEM
%token FINALLY
%token SUB_MAIN

%right '='
%left '>' '<' MORE_OR_EQUAL LESS_OR_EQUAL NONEQUAL EQUAL
%left '+' '-'
%left '*' '/' '\\'
%left '^'
%left UMINUS
%nonassoc ')'
%locations
%%

	ENDL_s:
		  | ENDL_sE
		  ;
			 
	ENDL_sE: ENDL
		   | ENDL_sE ENDL
		   ;

	module_stmt: ENDL_s MODULE ID ENDL_sE decl_stmt_list SUB_MAIN ENDL_sE stmt_list END_SUB ENDL_sE decl_stmt_list END_MODULE ENDL_s {$$ = root = create_VB_Module_stmt($3,$8,$5,$11);}
			   ;

	stmt_list:						{$$ = create_VB_Stmt_list(0);}
			 | stmt_listE
		     ;

	stmt_listE: stmt				{$$ = create_VB_Stmt_list($1);}
			  | stmt_listE stmt		{$$ = edit_VB_Stmt_list($1,$2);}
		      ;

        stmt: expr ENDL_sE			{$$ = create_VB_Stmt_Expr($1);}
		    | if_stmt				{$$ = create_VB_Stmt_If($1);}
		    | dim_stmt				{$$ = create_VB_Stmt_Dim($1);}
		    | for_stmt				{$$ = create_VB_Stmt_For($1);}
		    | while_stmt			{$$ = create_VB_Stmt_While($1);}
		    | do_loop_stmt			{$$ = create_VB_Stmt_Do_Loop($1);}
		    | return_stmt			{$$ = create_VB_Stmt_Return($1);}
		    ;

	decl_stmt_list:								{$$ = create_VB_Decl_stmt_list(0);}
				  | decl_stmt_listE
				  ;

	decl_stmt_listE: decl_stmt					{$$ = create_VB_Decl_stmt_list($1);}
				   | decl_stmt_listE decl_stmt	{$$ = edit_VB_Decl_stmt_list($1,$2);}
				   ;

			decl_stmt: sub_stmt					{$$ = create_VB_Decl_Sub($1);}
					 | func_stmt				{$$ = create_VB_Decl_Func($1);}
					 ;
						
	expr: TRUE										{$$ = create_int_boolean_char_const_expr(EXPR_BOOLEAN_CONST,1);}
		| FALSE										{$$ = create_int_boolean_char_const_expr(EXPR_BOOLEAN_CONST,0);}
		| ID										{$$ = create_id_expr($1);}
		| ID'('expr_list_empty')'					{$$ = create_brackets_actions($1,$3);}
		| CONSOLE '.' READ '('')'					{$$ = create_Read();}
		| CONSOLE '.' READLINE '('')'				{$$ = create_Readln();}
		| CONSOLE '.' WRITE '(' expr ')'    		{$$ = create_Print($5);}
		| CONSOLE '.' WRITE '('')' 		  			{$$ = create_Print(NULL);}
		| CONSOLE '.' WRITELINE '(' expr ')'  		{$$ = create_Println($5);}
		| CONSOLE '.' WRITELINE '('')'  			{$$ = create_Println(NULL);}
		| INT_CONST									{$$ = create_int_boolean_char_const_expr(EXPR_INT_CONST,$1);}
		| CHAR_CONST								{$$ = create_int_boolean_char_const_expr(EXPR_CHAR_CONST,$1);}
		| STRING_CONST								{$$ = create_string_const_expr($1);}
        | expr '=' expr								{$$ = create_operator_expr(EXPR_ASSIGN,$1,$3);}
		| expr '+' expr								{$$ = create_operator_expr(EXPR_PLUS,$1,$3);}
		| expr '-' expr								{$$ = create_operator_expr(EXPR_MINUS,$1,$3);}
		| expr '*' expr								{$$ = create_operator_expr(EXPR_MUL,$1,$3);}
		| expr '/' expr								{$$ = create_operator_expr(EXPR_DIV,$1,$3);}
		| expr '^' expr								{$$ = create_operator_expr(EXPR_POWER,$1,$3);}
		| expr '>' expr								{$$ = create_operator_expr(EXPR_MORE,$1,$3);}
		| expr '<' expr								{$$ = create_operator_expr(EXPR_LESS,$1,$3);}
		| expr MORE_OR_EQUAL expr					{$$ = create_operator_expr(EXPR_MORE_OR_EQUAL,$1,$3);}
		| expr LESS_OR_EQUAL expr					{$$ = create_operator_expr(EXPR_LESS_OR_EQUAL,$1,$3);}
		| expr NONEQUAL	expr						{$$ = create_operator_expr(EXPR_NONEQUAL,$1,$3);}
		| expr EQUAL	expr						{$$ = create_operator_expr(EXPR_EQUAL,$1,$3);}
		| '('expr')'								{$$ = $2;}
		| '-' expr %prec UMINUS						{$$ = create_operator_expr(EXPR_UMINUS,$2,0);}
		;

	if_stmt: IF expr THEN ENDL_sE stmt_list END_IF ENDL_sE							{$$ = create_if_stmt(0,$2,$5,NULL);}
		   | IF expr THEN ENDL_sE stmt_list ELSE ENDL_sE stmt_list END_IF ENDL_sE	{$$ = create_if_stmt(1,$2,$5,$8);}
		   ;

	dim_stmt: DIM as_expr_list ENDL_sE				 			{$$ = create_dim_stmt($2);}
			;

		as_expr_list: as_expr					 			{$$ = create_as_expr_list($1);}
					| as_expr_list',' as_expr	 			{$$ = add_to_as_expr_list($1,$3);}
					;

			as_expr: ID AS param_type										{$$ = create_as_expr_init($1,$3,NULL);}
				   | ID '('INT_CONST')' AS param_type						{$$ = create_as_array($1,$3,$6);}
				   | ID AS param_type '=' expr								{$$ = create_as_expr_init($1,$3,$5);}
				   | ID '('')' AS param_type '=' '{'expr_list'}'			{$$ = create_as_array_init($1,$5,$8);}
				   | ID',' id_list_stmt AS param_type						{$$ = create_as_expr_id($1,$3,$5);}	
				   | ID '(' INT_CONST ')' ',' id_list_stmt AS param_type	{$$ = create_as_expr_arr($1,$3,$6,$8);}
				   ;

				id_list_stmt: ID											{$$ = create_id_list($1,0,0);}	
							| ID '(' INT_CONST ')'							{$$ = create_id_list($1,1,$3);}	
							| id_list_stmt',' ID							{$$ = add_to_id_list($1,$3,0,0);}
							| id_list_stmt',' ID '(' INT_CONST ')'			{$$ = add_to_id_list($1,$3,1,$5);}
							;

		expr_list_empty: /*empty*/						{$$ = create_Expr_list(NULL);}
					   | expr_list
					   ;

		expr_list: expr									{$$ = create_Expr_list($1);}
				 | expr_list',' expr					{$$ = add_Expr_to_list($1,$3);}
				 ;

        for_stmt: FOR ID '=' expr TO expr ENDL_sE stmt_list NEXT ENDL_sE            				{$$ = create_for_stmt($2,$4,$6,$8);}
                | FOR ID '=' expr TO expr STEP expr ENDL_sE stmt_list NEXT ENDL_sE 				{$$ = create_for_with_step_stmt($2,$4,$6,$8,$10);}
                | FOR ID AS param_type '=' expr TO expr ENDL_sE stmt_list NEXT ENDL_sE 			{$$ = create_for_with_decl_stmt($2,DATA_INTEGER,$6,$8,$10);}
                | FOR ID AS param_type '=' expr TO expr STEP expr ENDL_sE stmt_list NEXT ENDL_sE 	{$$ = create_for_with_decl_with_step_stmt($2,DATA_INTEGER,$6,$8,$10,$12);}
				;

        while_stmt: WHILE expr ENDL_sE stmt_list END_WHILE ENDL_sE 	 {$$ = create_while_stmt($2,$4);}
				  ;

        do_loop_stmt: DO WHILE expr ENDL_sE stmt_list LOOP ENDL_sE     {$$ = create_do_loop_stmt(0,$3,$5);}
                    | DO UNTIL expr ENDL_sE stmt_list LOOP ENDL_sE     {$$ = create_do_loop_stmt(1,$3,$5);}
                    | DO ENDL_sE stmt_list LOOP WHILE expr ENDL_sE     {$$ = create_do_loop_stmt(2,$6,$3);}
                    | DO ENDL_sE stmt_list LOOP UNTIL expr ENDL_sE     {$$ = create_do_loop_stmt(3,$6,$3);}
                    ;

        sub_stmt: SUB ID '('')' ENDL_sE stmt_list END_SUB ENDL_sE             {$$ = create_sub_stmt($2,NULL,$6);}
                | SUB ID '('param_list')' ENDL_sE stmt_list END_SUB ENDL_sE   {$$ = create_sub_stmt($2,$4,$7);}
				;

                param_list: param_stmt                  {$$ = create_param_list($1);}
                          | param_list',' param_stmt    {$$ = add_to_param_list($1,$3);}
						  ;

                param_stmt: BYVAL ID AS param_type         {$$ = create_param_stmt(0,$2,$4);}
						  | BYREF ID'('')' AS param_type       {$$ = create_param_stmt(1,$2,$6);}
						  ;

				param_type: INTEGER        {$$ = DATA_INTEGER;}
                          | BOOLEAN        {$$ = DATA_BOOLEAN;}
                          | CHAR           {$$ = DATA_CHAR;}
                          | STRING_T       {$$ = DATA_STRING;}
                          ;

	return_stmt: RETURN expr ENDL_sE   {$$ = create_return_stmt($2);}

        func_stmt: FUNCTION ID '('')' AS param_type ENDL_sE stmt_list END_FUNCTION ENDL_sE          {$$ = create_func_stmt($2,NULL,$6,$8);}
				 | FUNCTION ID '('param_list')' AS param_type ENDL_sE stmt_list END_FUNCTION ENDL_sE  {$$ = create_func_stmt($2,$4,$7,$9);}
				 | FUNCTION ID '('')' AS param_type'('')' ENDL_sE stmt_list END_FUNCTION ENDL_sE          {$$ = create_func_stmt($2,NULL,$6,$10);}
				 | FUNCTION ID '('param_list')' AS param_type'('')' ENDL_sE stmt_list END_FUNCTION ENDL_sE  {$$ = create_func_stmt($2,$4,$7,$11);}
				 ;

%%

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