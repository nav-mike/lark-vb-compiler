//
//

#ifndef H_PRT_WHILE
#define H_PRT_WHILE

/*! \struct VB_While_stmt
    ���������, ����������� �������� ����� While.
 */
struct VB_While_stmt
{
	struct VB_Stmt_list* stmt_list;	//!< ���� �����
	struct VB_Expr*		 expr;		//!< �������
	struct VB_Stmt*		 next;		//!< ��������� ��������
	       int           line_number; //!< Line of this statement.
};

/*!
	������� ��������� While:
	" While counter < 20
		counter += 1
	  End While"
  \param expr �������
  \param body ���� �����
  \return ��������� �� ������ While.
*/
struct VB_While_stmt * create_while_stmt(struct VB_Expr* expr, struct VB_Stmt_list* body)
{
	struct VB_While_stmt* result = (struct VB_While_stmt*)malloc(sizeof(struct VB_While_stmt));

	result->expr = expr;
	result->stmt_list = body;
	result->next = NULL;
	result->line_number = get_location();

    return result;
}


#endif // H_PRT_WHILE