//
//

#ifndef H_PRT_DECL_LIST
#define H_PRT_DECL_LIST

/*! \struct VB_Decl_stmt_list
    ������ ���������� �������� � ������.
 */
struct VB_Decl_stmt_list
{
	struct VB_Decl_stmt* first;	//!< ������ ������� ������
	struct VB_Decl_stmt* last;	//!< ��������� ������� ������
};

/*!
	�������� ������ ����������.
	\param decl_stmt ����� ������� ������ ����������.
	\return ����� ������ ����������.
*/
struct VB_Decl_stmt_list* create_VB_Decl_stmt_list(struct VB_Decl_stmt* decl_stmt)
{
	struct VB_Decl_stmt_list* list = NULL;

	if (decl_stmt == NULL) return list;

	list = (struct VB_Decl_stmt_list*)malloc(sizeof(struct VB_Decl_stmt_list));

	list->first = decl_stmt;
	list->last = decl_stmt;

	return list;
}

/*!
	���������� �������� � ������ ����������.
	\param decl_list ������� ������ ����������
	\param decl_stmt ����� ������� ������ ����������.
	\return ������� ������ ����������.
*/
struct VB_Decl_stmt_list* edit_VB_Decl_stmt_list(struct VB_Decl_stmt_list* decl_list, struct VB_Decl_stmt* decl_stmt)
{
	if (decl_stmt != NULL)
	{
		if (decl_list != NULL)
		{
			decl_list->last->next = decl_stmt;
			decl_list->last = decl_stmt;
		}
		else
			decl_list = create_VB_Decl_stmt_list(decl_stmt);
	}

	return decl_list;
}

/*!
	\brief ������� ������� ������� �������/�������� �� Main � �����.
	\param prev ������ ������� �� Main.
	\param post ������ ������� ����� Main.
	\return ������, ���������� prev � post.
*/
struct VB_Decl_stmt_list* merge_two_decl_stmt_list (struct VB_Decl_stmt_list* prev, struct VB_Decl_stmt_list* post)
{
	struct VB_Decl_stmt* item = post->first;

	prev->last->next = item;

	return prev;
}

#endif // H_PRT_DECL_LIST