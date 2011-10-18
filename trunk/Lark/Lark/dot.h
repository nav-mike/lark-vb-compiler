#include <stdio.h>

/* ��������� ������ ��� �������� "Expression". */
struct VB_Expr
{
	char* expr_name;            // ��� ��������������, ������.
	int int_val;                // �������� ���������. ������������ ��� bool, int, char.
	struct VB_Expr* FirstSon;   // ��������� �� ������ ����.
	struct VB_Expr* lastSon;    // ��������� �� ������� ����.
};

int open_dot_file ()
{
	FILE* file = NULL;
	int error = fopen_s(&file, "vb_lark.txt", "wt");
	if (error) return 1;

	error = fprintf(file,"digraph G\n{\n\tgraph [ rankdir = \"LR\" ];\n\tnode [ fontsize = \"16\" shape = \"ellipse\"  ];\n\tedge [ ];");
	if (error == -1) return 1;

	return 0;
}