//
//

#ifndef H_PRT_EXPR_LIST
#define H_PRT_EXPR_LIST


/*! \struct VB_Expr_list
    Структура, описывающая список выражений.
 */
struct VB_Expr_list
{
	struct VB_Expr* first;  //!< Указатель на первый элемент списка
	struct VB_Expr* last;   //!< Указатель на последний элемент списка
};


/*!
	Функция создания листа выражений.
  \param expr Выражение.
  \return Лист выражений.
*/
struct VB_Expr_list* create_Expr_list (struct VB_Expr* expr)
{
	struct VB_Expr_list* list = NULL;

	if (!expr) return list;

	list = (struct VB_Expr_list*)malloc(sizeof(struct VB_Expr_list));

	list->first = expr;
	list->last = expr;

	return list;
}

/*!
	Функция изменения листа выражений.
  \param expr_list Лист выражений.
  \param expr Добавляемое выражение.
*/
struct VB_Expr_list* add_Expr_to_list (struct VB_Expr_list* expr_list, struct VB_Expr* expr)
{
	expr_list->last->next = expr;
	expr_list->last = expr;

	return expr_list;
}


#endif // H_PRT_EXPR_LIST