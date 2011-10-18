#include <stdio.h>

/* Структура дерева для хранения "Expression". */
struct VB_Expr
{
	char* expr_name;            // Имя идентификатора, строка.
	int int_val;                // Значение выражения. Используется для bool, int, char.
	struct VB_Expr* FirstSon;   // Указатель на левого сына.
	struct VB_Expr* lastSon;    // Указатель на правого сына.
};