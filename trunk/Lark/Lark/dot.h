#include <stdio.h>
#include "tree_nodes.h"

/*!
    Функция открывает файл для GrphViz и записывает в него верхнюю шапку.
  \return Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
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
    Функция закрывает файл для GrphViz и записывает в него необходимые данные в конец файла.
  \return Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
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
    Функция добавляет в файл GraphViz фрагмент дерева для Expr.
  \param node   - корневой узел дерева.
  \param number - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
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

	fclose(file);

	return 0;
}

struct VB_Expr Create_VB_Expr(enum VB_Type_of_expr type, 
								char* expr_string, int val,
								struct VB_Expr* FirstSon,
								struct VB_Expr* LastSon);

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для stmt_module.
  \param module   - узел дерева.
  \param number   - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_stmt_module (struct VB_Stmt_module* module, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file, "vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file, "\n\t\"node%d\" [", number);
	if (error == -1) return 1;
	error = fprintf(file, "\n\t\tlabel = \"<f0> module | <f1> \"");
	if (error == -1) return 1;
	error = fprintf(file, "\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// Вызов функции для stmt_list

	return 0;
}

/*!
    Функция преобразует тип IF в строку.
  \param type - Тип IF.
  \return Строка - тип IF.
*/
char* VB_If_stmt_type_to_string (enum Vb_If_stmt_type type)
{
	switch (type)
	{
	case(IF_THEN):
		return "IF_THEN";
		break;
	case(IF_ENDL):
		return "IF_ENDL";
		break;
	case(IF_INLINE):
		return"IF_INLINE";
		break;
	case(IF_ELSE_INLINE):
		return "IF_ELSE_INLINE";
		break;
	}

	return "";
}

/*!
	Функция преобразует тип Stmt в строку.
  \param type - Тип Stmt.
  \return Строка - тип Stmt.
*/
char* VB_Stmt_type_to_string (enum VB_Stmt_type type)
{
	switch (type)
	{
	case(0):
		return "ENDL";
		break;
	case(STMT_EXPR):
		return "EXPR";
		break;
	case(IF):
		return "IF";
		break;
	case(DIM):
		return "DIM";
		break;
	case(FOR):
		return "FOR";
		break;
	case(WHILE):
		return "WHILE";
		break;
	case(DO_LOOP):
		return "DO_LOOP";
		break;
	case(ENUM):
		return "ENUM";
		break;
	case(SUB):
		return "SUB";
		break;
	case(FUNC):
		return "FUNC";
		break;
	case(TRY_CATCH):
		return "TRY_CATCH";
		break;
	case(THROW):
		return "THROW";
		break;
	case(PRINT):
		return "PRINT";
		break;
	case(PRINTLN):
		return "PRINTLN";
		break;
	case(READ):
		return "READ";
		break;
	case(READLN):
		return "READLN";
		break;
	case(READKEY):
		return "READKEY";
		break;
	}

	return "";
}

/*!
	Функция преобразует тип конца If в строку.
  \param type - Тип конца If.
  \return Строка - тип конца If.
*/
char* VB_End_if_stmt_type_to_string (enum VB_End_if_stmt_type type)
{
	switch(type)
	{
	case(ENDIF):
		return "ENDIF";
		break;
	case(ELSE):
		return "ELSE";
		break;
	case(ELSE_IF_THEN):
		return "ELSE_IF_THEN";
		break;
	case(ELSE_IF_ENDL):
		return "ELSE_IF_ENDL";
		break;
	}

	return "";
}

/*!
	Функция преобразует тип списка последовательности определения переменных в строку.
  \param type - Тип списка последовательности определения переменных.
  \return Строка - тип списка последовательности определения переменных.
*/
char* VB_As_Expr_list_type_to_string (enum VB_As_Expr_list_type type)
{
	switch(type)
	{
	case(EXPR):
		return "EXPR";
		break;
	case(ARRAY):
		return "ARRAY";
		break;
	case(EXPR_LIST):
		return "EXPR_LIST";
		break;
	case(EXPR_ARR):
		return "EXPR_ARR";
		break;
	}

	return "";
}

/*!
	Функция преобразует тип объявления идентификатора.
  \param type - Тип объявления идентификатора.
  \return Строка - тип объявления идентификатора.
*/
char* VB_As_expr_type_to_string (enum VB_As_expr_type type)
{
	switch(type)
	{
	case(ID_LIST):
		return "ID_LIST";
		break;
	case(ONE_ID):
		return "ONE_ID";
		break;
	case(ID_INIT):
		return "ID_INIT";
		break;
	}

	return "";
}

/*!
	Функция преобразует тип идентификатора.
  \param type - Тип идентификатора.
  \return Строка - тип идентификатора.
*/
char* VB_Id_type_to_string (enum VB_Id_type type)
{
	switch(type)
	{
	case(INTEGER):
		return "INTEGER";
		break;
	case(BOOLEAN):
		return "BOOLEAN";
		break;
	case(CHAR):
		return "CHAR";
		break;
	case(STRING):
		return "STRING";
		break;
	}

	return "";
}

/*!
	Функция преобразует тип цикла Do...Loop.
  \param type - Тип цикла Do...Loop.
  \return Строка - тип цикла Do...Loop.
*/
char* VB_Do_loop_type_to_string(enum VB_Do_loop_type type)
{
	switch(type)
	{
	case(DO_WHILE):
		return "DO_WHILE";
		break;
	case(DO_UNTIL):
		return "DO_UNTIL";
		break;
	case(LOOP_WHILE):
		return "LOOP_WHILE";
		break;
	case(LOOP_UNTIL):
		return "LOOP_UNTIL";
		break;
	}

	return "";
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Throw_stmt.
  \param module   - узел дерева.
  \param number   - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_throw_stmt (struct VB_Throw_stmt* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s\"",
		node->string, "THROW_STMT");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// Запись stmt

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Catch_stmt.
  \param module   - узел дерева.
  \param number   - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_catch_stmt (struct VB_Catch_stmt* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s\"",
		node->id, "CATCH_STMT");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// Запись stmt

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Catch_stmt_list.
  \param module   - узел дерева.
  \param number   - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_catch_stmt_list (struct VB_Catch_stmt_list* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1>  \"",
		"CATCH_STMT_LIST");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// Запись stmt

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Try_catch_stmt.
  \param module   - узел дерева.
  \param number   - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_try_catch_stmt (struct VB_Try_catch_stmt* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1>  \"",
		"TRY_CATCH_STMT");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// Запись stmt и stmt_list

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Func_stmt.
  \param module   - узел дерева.
  \param number   - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_func_stmt (struct VB_Func_stmt* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s \"",
		node->id, VB_Id_type_to_string(node->id_type));
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// Запись паратров и тела

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Param_stmt.
  \param module   - узел дерева.
  \param number   - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_param_stmt (struct VB_Param_stmt* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s \"",
		node->id, VB_Id_type_to_string(node->id_type));
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// Следующий параметр

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Param_list.
  \param module   - узел дерева.
  \param number   - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_param_list (struct VB_Param_list* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s \"",
		"PARAM_LIST", "");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// Ввод параметров.

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Sub_stmt.
  \param module   - узел дерева.
  \param number   - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_sub_stmt (struct VB_Sub_stmt* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt","at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %d \"",
		node->id, node->has_params);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// Вввод параметров и тела процедуры.

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Enum_expr.
  \param module   - узел дерева.
  \param number   - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_enum_expr (struct VB_Enum_expr* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlable = \"<f0> %s | <f1> %d \"",
		node->id, node->value);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// Следующий элемент enum

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Enum_expr_list.
  \param module   - узел дерева.
  \param number   - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_enum_expr_list (struct VB_Enum_expr_list* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %d \"",
		"ENUM_EXPR_LIST", "");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// Запись всех элеметов

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Enum_stmt.
  \param module   - узел дерева.
  \param number   - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_enum_stmt (struct VB_Enum_stmt* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %d \"",
		node->id, "ENUM_STMT");
	if (error == -1) return 1;

	error = fprintf(file, "\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// Запись полей

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Do_loop_stmt.
  \param module   - узел дерева.
  \param number   - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_do_loop_stmt (struct VB_Do_loop_stmt* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt","at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s \"",
		VB_Do_loop_type_to_string(node->type), "DO_LOOP_STMT");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// Условие, тело

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_While_stmt.
  \param module   - узел дерева.
  \param number   - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_while_stmt (struct VB_While_stmt* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s \"",
		"WHILE_STMT", "");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// Условие, тело

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_For_stmt.
  \param module   - узел дерева.
  \param number   - порядковый номер узла.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_for_stmt (struct VB_For_stmt* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %d | <f1> %d | <f2> %d\"",
		node->from_val, node->to_val, node->step_val);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// тело и дентификатор

	fclose(file);
	return 0;
}

int add_node_expr_list (struct VB_Expr_list* node, int number)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	//error = fprintf(

	return 0;
}