//
//

#ifndef H_PRT_RETURN
#define H_PRT_RETURN


struct VB_Return_stmt
{
	struct VB_Expr*			expr;
	struct VB_Stmt*			next;		//!< ”казатель на следующий элемент последовательности операторов.
	       int              line_number; //!< Line of this statement.
};

struct VB_Return_stmt* create_return_stmt(struct VB_Expr* expr)
{
	struct VB_Return_stmt* result = (struct VB_Return_stmt*)malloc(sizeof(struct VB_Return_stmt));

	result->expr = expr;
	result->next = NULL;
	result->line_number = get_location();

	return result;
}


#endif // H_PRT_RETURN