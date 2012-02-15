//
//

#ifndef H_PRT_STMT_LIST
#define H_PRT_STMT_LIST

/*! \struct VB_Stmt_list
    ���������, ����������� ������ ��������.
 */
struct VB_Stmt_list
{
	struct VB_Stmt* first;		//!< ��������� �� ������ ������� ������
	struct VB_Stmt* last;		//!< ��������� �� ��������� ������� ������
	       int      line_number; //!< Line of this statement.
};



/*!
	������� �������� ���� ������: ������ ��������.
  \param stmt ��������.
  \return ����� ������ ��������.
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
	������� ��������� ���� ������: ���������� � ������ ��������� ��������.
  \param list ������ ��������.
  \param stmt ��������.
  \return ����� ������ ��������.
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