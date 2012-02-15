//
//

#ifndef H_PRT_IF
#define H_PRT_IF

/*! \enum VB_If_stmt_type
    ������������ ����� ��������� ��������.
 */
enum VB_If_stmt_type
{
	IF_THEN,
	IF_THEN_ELSE
};

/*! \struct VB_If_stmt
    ��������� ������ ��� �������� ��������� ��������� ��������.
 */
struct VB_If_stmt
{
	enum   VB_If_stmt_type  type;		//!< ��� ��������� ���������
	struct VB_Expr*			expr;		//!< �������
	struct VB_Stmt_list*	stmt_list;	//!< ��������� �� ������ �������� ��� �������� �������.
	struct VB_Stmt_list*	else_list;	//!< ��������� �� ������ �������� ��� ������ ������� (������ ���� � 1 ������).
	struct VB_Stmt*			next;		//!< ��������� �� ��������� ������� ������������������ ����������.
	       int              line_number; //!< Line of this statement.
};

/* ������������� ��������� ���������:
	if_stmt: IF expr THEN ENDL stmt_list end_if_stmt
		   | IF expr ENDL stmt_list end_if_stmt
		   | IF expr THEN stmt_list_inline END_IF ENDL
		   | IF expr THEN stmt_list_inline ELSE stmt_list_inline END_IF ENDL
		   ;
*/
/*!
	������� ������� �������� ��������� �� ������ ������� ����������.
  \param expr �������.
  \param stmt_list �������� ��� ������������� �������.
  \param end_if_stmt �������� ��� ������ �������.
  \return ����� �������� ���������.
*/
//struct VB_If_stmt* create_with_Then_expr_stmt_list_end_if_stmt (enum VB_If_stmt_type type, struct VB_Expr* expr,
//	struct VB_Stmt_list* stmt_list, struct VB_End_if_stmt* end_if_stmt)
//{
//	struct VB_If_stmt* if_stmt = NULL;
//
//	if_stmt = (struct VB_If_stmt*)malloc(sizeof(struct VB_If_stmt));
//
//	if_stmt->type = type;
//	if_stmt->expr = expr;
//	if_stmt->end_stmt = end_if_stmt;
//	if_stmt->stmt_list = stmt_list;
//	if_stmt->else_list = NULL;
//	if_stmt->next = NULL;
//
//	return if_stmt;
//}

//struct VB_End_if_stmt* create_end_if_stmt(enum VB_End_if_stmt_type type, struct VB_Expr* expr,
//	struct VB_Stmt_list* stmt_list, struct VB_End_if_stmt* end_if_stmt)
//{
//	struct VB_End_if_stmt* end_if = NULL;
//
//	end_if = (struct VB_End_if_stmt*)malloc(sizeof(struct VB_End_if_stmt));
//	end_if->type = type;
//	end_if->expr = expr;
//	end_if->stmt_list = stmt_list;
//	end_if->end_stmt = end_if_stmt;
//	end_if->next = NULL;
//
//	return end_if_stmt;
//}

/*!
	������� ������� �������� ��������� �� ������ ������� ����������.
  \param expr �������.
  \param stmt_list �������� ��� ������������� �������.
  \param end_if_stmt �������� ��� ������ �������.
  \return ����� �������� ���������.
*/
//struct VB_If_stmt* create_if_inline(enum VB_If_stmt_type type, struct VB_Expr* expr,
//									struct VB_Stmt_list* if_list, struct VB_Stmt_list* else_list)
//{
//	struct VB_If_stmt* if_stmt = NULL;
//
//	if_stmt = (struct VB_If_stmt*)malloc(sizeof(struct VB_If_stmt));
//
//	if_stmt->type = type;
//	if_stmt->expr = expr;
//	if_stmt->stmt_list = if_list;
//	if_stmt->else_list = else_list;
//	if_stmt->end_stmt = NULL;
//	if_stmt->next = NULL;
//
//	return if_stmt;
//}


struct VB_If_stmt* create_if_stmt(int hasElse,struct VB_Expr* expr,struct VB_Stmt_list* if_list, struct VB_Stmt_list* else_list) {
	struct VB_If_stmt* if_stmt = NULL;

	if (expr->type == EXPR_ASSIGN){
		expr->type = EXPR_EQUAL;
		expr->expr_string = "EXPR_EQUAL";
	}


	if_stmt = (struct VB_If_stmt*)malloc(sizeof(struct VB_If_stmt));

	if_stmt->type = hasElse;
	if_stmt->expr = expr;
	if_stmt->stmt_list = if_list;
	if_stmt->else_list = else_list;
	if_stmt->next = NULL;
	if_stmt->line_number = get_location();

	return if_stmt;
}

#endif // H_PRT_IF