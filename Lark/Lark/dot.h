#include <stdio.h>

/* ������������ ����� ���������. */
enum VB_Type_of_expr
{
	_ID_vb,
	_CHAR_CONST_vb,
	_INT_CONST_vb,
	_STRING_CONST_vb,
	_BOOLEAN_CONST_vb,
	_ASSIGN_OPERATOR_vb,
	_PLUS_OPERATOR_vb,
	_MINUS_OPERATOR_vb,
	_MUL_OPERATOR_vb,
	_INT_DIV_OPERATOR_vb,
	_DIV_OPERATOR_vb,
	_POWER_OPERATOR_vb,
	_MORE_OPERATOR_vb,
	_LESS_OPERATOR_vb,
	_MORE_OR_LESS_OPERATOR_vb,
	_LESS_OR_EQUAL_OPERATOR_vb,
	_ASSIGN_PLUS_OPERATOR_vb,
	_ASSIGN_MINUS_OPERATOR_vb,
	_ASSIGN_MUL_OPERATOR_vb,
	_ASSIGN_DIV_OPERATOR_vb,
	_ASSIGN_INT_DIV_OPERATOR_vb,
	_ASSIGN_NONEQUAL_OPERATOR_vb,
	_ASSIGN_UMINUS_OPERATOR_vb
};

/* ��������� ������ ��� �������� "Expression". */
struct VB_Expr
{
	enum VB_Type_of_expr type;  // ����������� ���� ���������.
	char* expr_string;            // ��� ��������������, ������.
	int int_val;                // �������� ���������. ������������ ��� bool, int, char.
	struct VB_Expr* FirstSon;   // ��������� �� ������ ����.
	struct VB_Expr* LastSon;    // ��������� �� ������� ����.
};

/*!
    ������� ��������� ���� ��� GrphViz � ���������� � ���� ������� �����.
  \return ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
*/
int open_dot_file ()
{
	FILE* file = NULL;
	int error = fopen_s(&file, "vb_lark.txt", "wt");
	if (error) return 1;

	error = fprintf(file,"digraph G\n{\n\tgraph [ rankdir = \"LR\" ];\n\tnode [ fontsize = \"16\" shape = \"ellipse\"  ];\n\tedge [ ];");
	if (error == -1) return 1;

	fclose(file);

	return 0;
}

/*!
    ������� ��������� ���� ��� GrphViz � ���������� � ���� ����������� ������ � ����� �����.
  \return ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
*/
int close_dot_file ()
{
	FILE* file = NULL;
	int error = fopen_s(&file, "vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file, "\n};");
	if (error == -1) return 1;

	fclose(file);

	return 0;
}

/*!
    ������� ��������� � ���� GraphViz �������� ������ ��� Expr.
  \param node   - �������� ���� ������.
  \param number - ���������� ����� ����.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
*/
int add_node_expr (struct VB_Expr* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file, "vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file, "\n\t\"node%d\" [", number);
	if (error == -1) return 1;
	error = fprintf(file, "\n\t\tlabel = \"<f0> %s | <f1> %d\"",
		                          node->expr_string, node->int_val);
	if (error == -1) return 1;
	error = fprintf(file, "\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->FirstSon != NULL)
	{
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;", number, number+1);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_expr(node->FirstSon, number+1);
		if (error == -1) return 1;
	}

	if (node->LastSon != NULL)
	{
		error = fopen_s(&file, "vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;", number, number+2);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_expr(node->LastSon, number+2);
		if (error == -1) return 1;
		error = fopen_s(&file, "vb_lark.txt", "at");
		if (error) return 1;
	}

	fclose(file);

	return 0;
}

struct VB_Expr Create_VB_Expr(	enum VB_Type_of_expr type, 
								char* expr_string, int val,
								struct VB_Expr* FirstSon,
								struct VB_Expr* LastSon);

