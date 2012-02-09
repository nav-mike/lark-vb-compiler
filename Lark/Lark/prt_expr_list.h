//
//

#ifndef H_PRT_EXPR_LIST
#define H_PRT_EXPR_LIST


/*! \struct VB_Expr_list
    ���������, ����������� ������ ���������.
 */
struct VB_Expr_list
{
	struct VB_Expr* first;  //!< ��������� �� ������ ������� ������
	struct VB_Expr* last;   //!< ��������� �� ��������� ������� ������
};


/*!
	������� �������� ����� ���������.
  \param expr ���������.
  \return ���� ���������.
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
	������� ��������� ����� ���������.
  \param expr_list ���� ���������.
  \param expr ����������� ���������.
*/
struct VB_Expr_list* add_Expr_to_list (struct VB_Expr_list* expr_list, struct VB_Expr* expr)
{
	expr_list->last->next = expr;
	expr_list->last = expr;

	return expr_list;
}


#endif // H_PRT_EXPR_LIST