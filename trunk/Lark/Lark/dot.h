#include <stdio.h>

/* ��������� ������ ��� �������� "Expression". */
struct VB_Expr
{
	char* expr_name;            // ��� ��������������, ������.
	int int_val;                // �������� ���������. ������������ ��� bool, int, char.
	struct VB_Expr* FirstSon;   // ��������� �� ������ ����.
	struct VB_Expr* lastSon;    // ��������� �� ������� ����.
};