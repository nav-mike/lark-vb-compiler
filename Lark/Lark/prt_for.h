//
//

#ifndef H_PRT_FOR
#define H_PRT_FOR

/*! \struct VB_For_stmt
    Структура, описывающая оператор цикла For.
 */
struct VB_For_stmt
{
	enum VB_For_stmt_type type;			//!< Тип операции For
	char*				 id;			//!< Идентификатор
	int 				 from_val;		//!< Начало отсчета
	int 				 to_val;		//!< Конец отчета
	int 				 step_val;		//!< Шаг
	struct VB_Stmt_list* stmt_list;		//!< Тело цикла
	struct VB_Stmt*		 next;			//!< Следующий оператор

	char*			new_id;				//!< Если переменная создается для цикла
	enum VB_Id_type new_id_type;
	     int        line_number;        //!< Line of this number.
};
/*!

	Создать выражение For:
	" For i = 0 To 10
		действия
	  Next"

for_stmt: FOR ID '=' expr TO expr ENDL stmt_list NEXT ENDL            				{$$ = create_for_stmt($2,$4,$6,$8);}
		;


  \param id Итератор
  \param start Начальное значение
  \param end Конечное значение
  \param body Тело цикла
  \return указатель на объект For.
*/
struct VB_For_stmt * create_for_stmt(char* id, struct VB_Expr* start_expr, struct VB_Expr* end_expr, struct VB_Stmt_list* body)
{
	struct VB_For_stmt* result = (struct VB_For_stmt*)malloc(sizeof(struct VB_For_stmt));

	result->type = SIMPLE;
	result->id = (char*)malloc(sizeof(char)*strlen(id));
	strcpy(result->id,id);
	result->from_val = 	start_expr->int_val;
	result->to_val = end_expr->int_val;
	result->step_val = 1;
	result->stmt_list = body;
	result->next = NULL;
	result->new_id = NULL;
	result->line_number = get_location();

    return result;
}

/*!
	Создать выражение For:
	" For i = 0 To 10 Step 2
		действия
	  Next"

| FOR ID '=' expr TO expr STEP expr ENDL stmt_list NEXT ENDL 				{$$ = create_for_with_step_stmt($2,$4,$6,$8,$10);}


  \param id Итератор
  \param start Начальное значение
  \param end Конечное значение
  \param step Шаг итератора
  \param body Тело цикла
  \return указатель на объект For.
*/
struct VB_For_stmt * create_for_with_step_stmt(char* id, struct VB_Expr* start_expr, 
												struct VB_Expr* end_expr, struct VB_Expr* step_expr,
												struct VB_Stmt_list* body)
{
	struct VB_For_stmt* result = (struct VB_For_stmt*)malloc(sizeof(struct VB_For_stmt));

	result->type = WITH_STEP;
	result->id = (char*)malloc(sizeof(char)*strlen(id));
	strcpy(result->id,id);
	result->from_val = start_expr->int_val;
	result->to_val = end_expr->int_val;
	if (step_expr->type != EXPR_UMINUS)
		result->step_val = step_expr->int_val;
	else
		result->step_val = step_expr->left_chld->int_val;
	result->stmt_list = body;
	result->next = NULL;
	result->new_id = NULL;
	result->line_number = get_location();

    return result;
}

/*!
	Создать выражение For:
	" For i As Integer = 0 To 10
		действия
	  Next"

| FOR ID AS param_type '=' expr TO expr ENDL stmt_list NEXT ENDL 			{$$ = create_for_with_decl_stmt($2,DATA_INTEGER,$6,$8,$10);}


  \param id Итератор
  \param Тип итератора
  \param start Начальное значение
  \param end Конечное значение
  \param body Тело цикла
  \return указатель на объект For.
*/
struct VB_For_stmt * create_for_with_decl_stmt(char* id, enum VB_Id_type type, struct VB_Expr* start_expr,
												struct VB_Expr* end_expr, struct VB_Stmt_list* body)
{
	struct VB_For_stmt* result = (struct VB_For_stmt*)malloc(sizeof(struct VB_For_stmt));

	result->type = WITH_DECL;
	result->new_id = (char*)malloc(sizeof(char)*strlen(id));
	strcpy(result->new_id,id);
	result->new_id_type = type;

	result->from_val = start_expr->int_val;
	result->to_val = end_expr->int_val;
	result->step_val = 1;
	result->stmt_list = body;
	result->next = NULL;

	result->id = result->new_id;
	result->line_number = get_location();

    return result;
}

/*!
	Создать выражение For:
	" For i As Integer = 0 To 10 Step 2
		действия
	  Next"

| FOR ID AS param_type '=' expr TO expr STEP expr ENDL stmt_list NEXT ENDL 	{$$ = create_for_with_decl_with_step_stmt($2,DATA_INTEGER,$6,$8,$10,$12);}
  
  \param id Итератор
  \param Тип итератора
  \param start Начальное значение
  \param end Конечное значение
  \param step Шаг итератора
  \param body Тело цикла
  \return указатель на объект For.
*/
struct VB_For_stmt * create_for_with_decl_with_step_stmt(char* id, enum VB_Id_type type,
														 struct VB_Expr* start_expr, struct VB_Expr* end_expr,
													     struct VB_Expr* step_expr, struct VB_Stmt_list* body)
{
	struct VB_For_stmt* result = (struct VB_For_stmt*)malloc(sizeof(struct VB_For_stmt));

	result->type = WITH_DECL_AND_STEP;

	result->new_id = (char*)malloc(sizeof(char)*strlen(id));
	result->new_id_type = type;


	strcpy(result->new_id,id);
	
	result->from_val = start_expr->int_val;
	result->to_val = end_expr->int_val;
	result->step_val = step_expr->int_val;
	result->stmt_list = body;
	result->next = NULL;
	
	result->id = result->new_id;
	result->line_number = get_location();


    return result;
}

#endif // H_PRT_FOR