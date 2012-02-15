//
//

#ifndef H_PRT_STMT
#define H_PRT_STMT

/*! \struct VB_Stmt
    ���������, ����������� ��������.
 */
struct VB_Stmt
{
	enum VB_Stmt_type type;		//!< ��� ��������.
	void*			  value;	//!< ��������
	struct VB_Stmt*   next;	    //!< ��������� �� ��������� ������� ������������������ ����������.
	       int        line_number; //!< Line of this statement.
};

/*!
	������� �������� stmt � ���������� ��� �����.
  \param type ��� stmt.
  \param data ������ ��� ���������� �����.
  \return stmt.
*/
struct VB_Stmt* fill_stmt(enum VB_Stmt_type type, void* data)
{
	struct VB_Stmt* stmt = NULL;

	if (data != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));

		stmt->value = NULL;

		stmt->value = data;

		stmt->type = type;

		stmt->next = NULL;
	}
	
	stmt->line_number = get_location();

	return stmt;
}

/*!
	������� �������� �������� �� ���������.
  \param expr ���������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Expr (struct VB_Expr* expr)
{
	return fill_stmt(STMT_EXPR,(void*)expr);
}

/*!
	������� �������� �������� �� �������� ��������.
  \param if_stmt �������� ��������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_If (struct VB_If_stmt* if_stmt)
{
	return fill_stmt(STMT_IF,(void*)if_stmt);
}

/*!
	������� �������� �������� �� ������������� ����������.
  \param dim_stmt ������������� ���������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Dim (struct VB_Dim_stmt* dim_stmt)
{
	return fill_stmt(STMT_DIM,(void*)dim_stmt);
}

/*!
	������� �������� �������� �� �����.
  \param for_stmt ����.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_For (struct VB_For_stmt* for_stmt)
{
	return fill_stmt(STMT_FOR,(void*)for_stmt);
}

/*!
	������� �������� �������� �� �����.
  \param while_stmt ����.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_While (struct VB_While_stmt* while_stmt)
{
	return fill_stmt(STMT_WHILE,(void*)while_stmt);
}

/*!
	������� �������� �������� �� �����.
  \param do_loop_stmt ����.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Do_Loop (struct VB_Do_loop_stmt* do_loop_stmt)
{
	return fill_stmt(STMT_DO_LOOP,(void*)do_loop_stmt);
}

/*!
	������� �������� �������� �� ������ ������.
  \param readln_stmt ������ ������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Readln (struct VB_Readln_stmt* readln_stmt)
{
	return fill_stmt(15,(void*)readln_stmt);
}

/*!
	������� �������� �������� �� ������ �������.
  \param read_stmt ������ �������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Read (struct VB_Read_stmt* read_stmt)
{
	return fill_stmt(14,(void*)read_stmt);
}

struct VB_Stmt* create_VB_Stmt_Return(struct VB_Return_stmt* ret)
{
	return fill_stmt(STMT_RETURN,(void*)ret);
}

/*!
	������� �������� �������� �� ���������.
  \param sub_stmt ���������.
  \return ����� ��������.
*/
struct VB_Decl_stmt* create_VB_Decl_Sub (struct VB_Sub_stmt* sub_stmt)
{
	return fill_decl_stmt(0,(void*)sub_stmt);
}

/*!
	������� �������� �������� �� �������.
  \param func_stmt �������.
  \return ����� ��������.
*/
struct VB_Decl_stmt* create_VB_Decl_Func (struct VB_Func_stmt* func_stmt)
{
	return fill_decl_stmt(1,(void*)func_stmt);
}

#endif // H_PRT_STMT