//
//

#ifndef H_PRT_DO_LOOP
#define H_PRT_DO_LOOP

/*! \struct VB_Do_loop_stmt
    ���������, ����������� �������� ����� Do...Loop.
 */
struct VB_Do_loop_stmt
{
	enum VB_Do_loop_type type;		//!< ���
	struct VB_Stmt_list* stmt_list;	//!< ���� �����
	struct VB_Expr*		 expr;		//!< �������
	struct VB_Stmt*		 next;		//!< ��������� ��������
	       int           line_number; //!< Line of this staement.
};

/*!
	������� ��������� Do..Loop..Until:
	"Do Until number = 10
        number += 1
    Loop"

  \param expr �������
  \param body ���� �����
  \return ��������� �� ������ Do..Loop..Until.
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