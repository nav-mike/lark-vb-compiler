//
//

#ifndef H_PRT_STMT_LIST
#define H_PRT_STMT_LIST

/*! \struct VB_Stmt_list
    Структура, описывающая список операций.
 */
struct VB_Stmt_list
{
	struct VB_Stmt* first;		//!< Указатель на первый элемент списка
	struct VB_Stmt* last;		//!< Указатель на последний элемент списка
	       int      line_number; //!< Line of this statement.
};



/*!
	Функция создания узла дерева: списка операций.
  \param stmt Операция.
  \return Новый список операций.
*/
struct VB_Stmt_list* create_VB_Stmt_list (struct VB_Stmt* stmt)
{
	struct VB_Stmt_list* list = NULL;

	if (stmt == NULL) return list;

	list = (struct VB_Stmt_list*)malloc(sizeof(struct VB_Stmt_list));

	list->first = stmt;
	list->last = stmt;
	list->line_number = get_location();

	return list;
}

/*!
	Функция изменения узла дерева: добавление к списку выражений операций.
  \param list Список операций.
  \param stmt Операция.
  \return Новый список операций.
*/
struct VB_Stmt_list* edit_VB_Stmt_list (struct VB_Stmt_list* list, struct VB_Stmt* stmt)
{
	if (stmt != NULL)
	{
		if (list != NULL)
		{
			list->last->next = stmt;
			list->last = stmt;
		}
		else list = create_VB_Stmt_list(stmt);
	}

	return list;
}

#endif // H_PRT_STMT_LIST