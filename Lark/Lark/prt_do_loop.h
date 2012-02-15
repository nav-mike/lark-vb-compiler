//
//

#ifndef H_PRT_DO_LOOP
#define H_PRT_DO_LOOP

/*! \struct VB_Do_loop_stmt
    Структура, описывающая оператор цикла Do...Loop.
 */
struct VB_Do_loop_stmt
{
	enum VB_Do_loop_type type;		//!< Тип
	struct VB_Stmt_list* stmt_list;	//!< Тело цикла
	struct VB_Expr*		 expr;		//!< Условие
	struct VB_Stmt*		 next;		//!< Следующий оператор
	       int           line_number; //!< Line of this staement.
};

/*!
	Создать выражение Do..Loop..Until:
	"Do Until number = 10
        number += 1
    Loop"

  \param expr Условие
  \param body Тело цикла
  \return указатель на объект Do..Loop..Until.
*/
struct VB_Do_loop_stmt * create_do_loop_stmt(enum VB_Do_loop_type type, struct VB_Expr* expr, struct VB_Stmt_list* body)
{
	struct VB_Do_loop_stmt* result = (struct VB_Do_loop_stmt*)malloc(sizeof(struct VB_Do_loop_stmt));

	result->type = type;
	result->expr = expr;
	result->stmt_list = body;
	result->next = NULL;
	result->line_number = get_location();

    return result;
}

#endif // H_PRT_DO_LOOP