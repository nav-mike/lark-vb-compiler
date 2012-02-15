//
//

#ifndef H_PRT_MODULE
#define H_PRT_MODULE

/*! \struct VB_Module_stmt
    ��������� ������ ��� �������� ����� ������.
 */
struct VB_Module_stmt
{
	char* id;								//!< ������������� ������
	struct VB_Stmt_list*		stmt_list;	//!< ������ �������� ������
	struct VB_Decl_stmt_list*	decl_list;  //!< ������ ���������� �������� � ������
	       int                  line_number; //!< Line of this statement.
};

/*!
	������� �������� ���� ������: ������.
  \param id ��� ������.
  \param list ������ ��������� ������.
  \return ����� ������.
*/
struct VB_Module_stmt* create_VB_Module_stmt(char* id, struct VB_Stmt_list* list,
													   struct VB_Decl_stmt_list* prev_decl,
													   struct VB_Decl_stmt_list* post_decl)
{
	struct VB_Module_stmt* module = NULL;

	module = (struct VB_Module_stmt*)malloc(sizeof(struct VB_Module_stmt));

	module->decl_list = NULL;

	if (id == NULL)
	{
		module->id = (char*)malloc(8 * sizeof(char));
		strcpy(module->id, "Unknown\0");
	}
	else
		module->id = id;

	module->stmt_list = list;

	if (prev_decl != NULL && post_decl != NULL)
		module->decl_list = merge_two_decl_stmt_list(prev_decl,post_decl);

	else if (prev_decl != NULL)
		module->decl_list = prev_decl;

	else if (post_decl != NULL)
		module->decl_list = post_decl;

	module->line_number = get_location();
	
	return module;
}

#endif // H_PRT_MODULE