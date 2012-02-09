//
//

#ifndef H_PRT_WHILE
#define H_PRT_WHILE

/*! \struct VB_While_stmt
    Структура, описывающая оператор цикла While.
 */
struct VB_While_stmt
{
	struct VB_Stmt_list* stmt_list;	//!< Тело цикла
	struct VB_Expr*		 expr;		//!< Условие
	struct VB_Stmt*		 next;		//!< Следующий оператор
};

/*!
	Создать выражение While:
	" While counter < 20
		counter += 1
	  End While"
  \param expr Условие
  \param body Тело цикла
  \return указатель на объект While.
*/
struct VB_While_stmt * create_while_stmt(struct VB_Expr* expr, struct VB_Stmt_list* body)
{
	struct VB_While_stmt* result = (struct VB_While_stmt*)malloc(sizeof(struct VB_While_stmt));

	result->expr = expr;
	result->stmt_list = body;
	result->next = NULL;

    return result;
}


#endif // H_PRT_WHILE