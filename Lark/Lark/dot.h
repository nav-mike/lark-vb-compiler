#include <stdio.h>
#include "tree_nodes.h"

/*!
	Функция преобразует тип выражения в строку.
  \param type - Тип выражения.
  \return Строка - тип выражения.
*/
char* VB_Expr_type_to_string (enum VB_Expr_type type)
{
	switch (type)
	{
	case(ID):
		return "ID";
		break;
	case(EXPR_FUNC):
		return "EXPR_FUNC";
		break;
	case(CHAR_CONST):
		return "CHAR_CONST";
		break;
	case(INT_CONST):
		return "INT_CONST";
		break;
	case(STRING_CONST):
		return "STRING_CONST";
		break;
	case(BOOLEAN_CONST):
		return "BOOLEAN_CONST";
		break;
	case(ASSIGN):
		return "ASSIGN";
		break;
	case(PLUS):
		return "PLUS";
		break;
	case(MINUS):
		return "MINUS";
		break;
	case(MUL):
		return "MUL";
		break;
	case(INT_DIV):
		return "INT_DIV";
		break;
	case(DIV):
		return "DIV";
		break;
	case(POWER):
		return "POWER";
		break;
	case(MORE):
		return "MORE";
		break;
	case(LESS):
		return "LESS";
		break;
	case(MORE_OR_EQUAL):
		return "MORE_OR_EQUAL";
		break;
	case(LESS_OR_EQUAL):
		return "LESS_OR_EQUAL";
		break;
	case(NONEQUAL):
		return "NONEQUAL";
		break;
	case(EQUAL):
		return "EQUAL";
		break;
	case(UMINUS):
		return "UMINUS";
		break;
	case(UPLUS):
		return "UPLUS";
		break;
	case(GET_ITEM):
		return "GET_ITEM";
		break;
	}

	return "";
}

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
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_expr (struct VB_Expr* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file, "vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file, "\n\t\"node%d\" [", number);
	if (error == -1) return 1;
	error = fprintf(file, "\n\t\tlabel = \"<f0> %s | <f1> %d | <f2> %s\"",
		node->expr_string, node->int_val, VB_Expr_type_to_string(node->type));
	if (error == -1) return 1;
	error = fprintf(file, "\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->left_chld != NULL)
	{
		Number++;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_expr(node->left_chld);
		if (error) return 1;
	}

	if (node->right_chld != NULL)
	{
		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_expr(node->right_chld);
		if (error) return 1;
	}

	fclose(file);

	return 0;
}


/*!
    Функция добавляет в файл GraphViz фрагмент дерева для stmt_module.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_stmt_module (struct VB_Module_stmt* module)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file, "vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file, "\n\t\"node%d\" [", number);
	if (error == -1) return 1;
	error = fprintf(file, "\n\t\tlabel = \"<f0> module | <f1> \"");
	if (error == -1) return 1;
	error = fprintf(file, "\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (module->stmt_list != NULL)
	{
		Number++;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_stmt_list(module->stmt_list);
		if (error) return 1;
	}

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
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_throw_stmt (struct VB_Throw_stmt* node)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", Number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s\"",
		node->string, "THROW_STMT");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Catch_stmt.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_catch_stmt (struct VB_Catch_stmt* node)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", Number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s\"",
		node->id, "CATCH_STMT");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Catch_stmt_list.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_catch_stmt_list (struct VB_Catch_stmt_list* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1>  \"",
		"CATCH_STMT_LIST");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->first != NULL)
	{
		struct VB_Catch_stmt* stmt = node->first;
		fclose(file);

		while (stmt != node->last)
		{
			Number++;
			error = fopen_s(&file,"vb_lark.txt", "at");
			if (error) return 1;
			error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
			if (error == -1) return 1;

			fclose(file);
			error = add_node_catch_stmt(stmt);
			if (error) return 1;
			stmt = stmt->next;
		}

		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_catch_stmt(stmt);
		if (error) return 1;
	}

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Try_catch_stmt.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_try_catch_stmt (struct VB_Try_catch_stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1>  \"",
		"TRY_CATCH_STMT");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->catch_list != NULL)
	{
		Number++;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_catch_stmt_list(node->catch_list);
		if (error) return 1;
	}

	if (node->fin_stmt_list != NULL)
	{
		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_stmt_list(node->fin_stmt_list);
		if (error) return 1;
	}

	if (node->stmt_list != NULL)
	{
		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_stmt_list(node->stmt_list);
		if (error) return 1;
	}

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Func_stmt.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_func_stmt (struct VB_Func_stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s \"",
		node->id, VB_Id_type_to_string(node->id_type));
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->stmt_list != NULL)
	{
		Number++;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
		number, Number);
		if (error == -1) return 1;

		fclose(file);
		error = add_node_stmt_list(node->stmt_list);
		if (error) return 1;
	}

	if (node->expr != NULL)
	{
		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
		number, Number);
		if (error == -1) return 1;

		fclose(file);
		error = add_node_expr(node->expr);
		if (error) return 1;
	}

	if (node->param_list != NULL)
	{
		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
		number, Number);
		if (error == -1) return 1;

		fclose(file);
		error = add_node_param_list(node->param_list);
		if (error) return 1;
	}

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Param_stmt.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_param_stmt (struct VB_Param_stmt* node)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", Number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s \"",
		node->id, VB_Id_type_to_string(node->id_type));
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Param_list.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_param_list (struct VB_Param_list* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s \"",
		"PARAM_LIST", "");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->first != NULL)
	{
		struct VB_Param_stmt* stmt = node->first;
		fclose(file);

		while (stmt != node->last)
		{
			Number++;
			error = fopen_s(&file,"vb_lark.txt", "at");
			if (error) return 1;
			error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
			if (error == -1) return 1;

			fclose(file);
			error = add_node_param_stmt(stmt);
			if (error) return 1;
			stmt = stmt->next;
		}

		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_param_stmt(stmt);
		if (error) return 1;
	}

	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Sub_stmt.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_sub_stmt (struct VB_Sub_stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt","at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %d \"",
		node->id, node->has_params);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->stmt_list != NULL)
	{
		Number++;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_stmt_list(node->stmt_list);
		if (error) return 1;
	}

	if (node->param_list != NULL)
	{
		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_param_list(node->param_list);
		if (error) return 1;
	}

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Enum_expr.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_enum_expr (struct VB_Enum_expr* node)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", Number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlable = \"<f0> %s | <f1> %d \"",
		node->id, node->value);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Enum_expr_list.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_enum_expr_list (struct VB_Enum_expr_list* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %d \"",
		"ENUM_EXPR_LIST", "");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->first != NULL)
	{
		struct VB_Enum_expr* stmt = node->first;
		fclose(file);

		while (stmt != node->last)
		{
			Number++;
			error = fopen_s(&file,"vb_lark.txt", "at");
			if (error) return 1;
			error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
			if (error == -1) return 1;

			fclose(file);
			error = add_node_enum_expr(stmt);
			if (error) return 1;
			stmt = stmt->next;
		}

		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_enum_expr(stmt);
		if (error) return 1;
	}

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Enum_stmt.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_enum_stmt (struct VB_Enum_stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %d \"",
		node->id, "ENUM_STMT");
	if (error == -1) return 1;

	error = fprintf(file, "\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->list != NULL)
	{
		Number++;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
		number, Number);
		if (error == -1) return 1;

		fclose(file);
		error = add_node_enum_expr_list(node->list);
		if (error) return 1;
	}

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Do_loop_stmt.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_do_loop_stmt (struct VB_Do_loop_stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt","at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s \"",
		VB_Do_loop_type_to_string(node->type), "DO_LOOP_STMT");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->expr != NULL)
	{
		Number++;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
		number, Number);
		if (error == -1) return 1;

		fclose(file);
		error = add_node_expr(node->expr);
		if (error) return 1;
	}

	if (node->stmt_list != NULL)
	{
		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
		number, Number);
		if (error == -1) return 1;

		fclose(file);
		error = add_node_stmt_list(node->stmt_list);
		if (error) return 1;
	}

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_While_stmt.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_while_stmt (struct VB_While_stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s \"",
		"WHILE_STMT", "");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->expr != NULL)
	{
		Number++;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
		number, Number);
		if (error == -1) return 1;

		fclose(file);
		error = add_node_expr(node->expr);
		if (error) return 1;
	}

	if (node->stmt_list != NULL)
	{
		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
		number, Number);
		if (error == -1) return 1;

		fclose(file);
		error = add_node_stmt_list(node->stmt_list);
		if (error) return 1;
	}

	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_For_stmt.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_for_stmt (struct VB_For_stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %d | <f1> %d | <f2> %d\"",
		node->from_val, node->to_val, node->step_val);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->id != NULL)
	{
		Number++;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
		number, Number);
		if (error == -1) return 1;

		fclose(file);
		error = add_node_expr(node->id);
		if (error) return 1;
	}

	if (node->stmt_list != NULL)
	{
		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
		number, Number);
		if (error == -1) return 1;

		fclose(file);
		error = add_node_stmt_list(node->stmt_list);
		if (error) return 1;
	}

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Expr_list.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_expr_list (struct VB_Expr_list* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s\"",
		"EXPR_LIST", "");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->first != NULL)
	{
		struct VB_Expr* stmt = node->first;
		fclose(file);

		while (stmt != node->last)
		{
			Number++;
			error = fopen_s(&file,"vb_lark.txt", "at");
			if (error) return 1;
			error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
			if (error == -1) return 1;

			fclose(file);
			error = add_node_expr(stmt);
			if (error) return 1;
			stmt = stmt->next;
		}

		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_expr(stmt);
		if (error) return 1;
	}

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Stmt_list.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_stmt_list (struct VB_Stmt_list* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt","at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s\"",
		"STMT_LIST", "");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->first != NULL)
	{
		struct VB_Stmt* stmt = node->first;
		fclose(file);

		while (stmt != node->last)
		{
			Number++;
			error = fopen_s(&file,"vb_lark.txt", "at");
			if (error) return 1;
			error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
			if (error == -1) return 1;

			fclose(file);
			error = add_node_stmt(stmt);
			if (error) return 1;
			stmt = stmt->next;
		}

		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_stmt(stmt);
		if (error) return 1;
	}

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Stmt.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_stmt (struct VB_Stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s\"",
		VB_Stmt_type_to_string(node->type), "STMT");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	Number++;
	error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
		number, Number);
	if (error == -1) return 1;
	fclose(file);
	switch (node->type)
	{
	case(STMT_EXPR):
		error = add_node_expr(node->expr);
		break;
	case(IF):
		error = add_node_if_stmt(node->if_stmt);
		break;
	case(DIM):
		error = add_node_dim_stmt(node->dim_stmt);
		break;
	case(FOR):
		error = add_node_for_stmt(node->for_stmt);
		break;
	case(WHILE):
		error = add_node_while_stmt(node->while_stmt);
		break;
	case(DO_LOOP):
		error = add_node_do_loop_stmt(node->do_loop_stmt);
		break;
	case(ENUM):
		error = add_node_enum_stmt(node->enum_stmt);
		break;
	case(SUB):
		error = add_node_sub_stmt(node->sub_stmt);
		break;
	case(FUNC):
		error = add_node_func_stmt(node->func_stmt);
		break;
	case(TRY_CATCH):
		error = add_node_try_catch_stmt(node->try_catch_stmt);
		break;
	case(THROW):
		error = add_node_throw_stmt(node->throw_stmt);
		break;
	case(PRINT):
		//error = add_node_print_stmt(node->print_stmt);
		break;
	case(PRINTLN):
		//error = add_node_println_stmt(node->println_stmt);
		break;
	case(READ):
		//error = add_node_read_stmt(node->read_stmt);
		break;
	case(READLN):
		//error = add_node_readln_stmt(node->readln_stmt);
		break;
	}
	if (error) return 1;

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_If_stmt.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_if_stmt (struct VB_If_stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s \"",
		VB_If_stmt_type_to_string(node->type), "IF_STMT");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->expr != NULL)
	{
		Number++;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_expr(node->expr);
		if (error) return 1;
	}

	if (node->stmt_list != NULL)
	{
		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_stmt_list(node->stmt_list);
		if (error) return 1;
	}

	if (node->end_stmt != NULL)
	{
		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_end_if_stmt(node->end_stmt);
		if (error) return 1;
	}

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_End_if_stmt.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_end_if_stmt (struct VB_End_if_stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s \"",
		VB_End_if_stmt_type_to_string(node->type), "END_IF_STMT");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->stmt_list != NULL)
	{
		Number++;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_stmt_list(node->stmt_list);
		if (error) return 1;
	}

	if (node->end_stmt != NULL)
	{
		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_end_if_stmt(node->end_stmt);
		if (error) return 1;
	}

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Dim_stmt.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_dim_stmt (struct VB_Dim_stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file, "vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s \"",
		"DIM_STMT", "");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->list != NULL)
	{
		Number++;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_as_Expr_list(node->list);
		if (error) return 1;
	}

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_As_Expr_list.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_as_Expr_list (struct VB_As_Expr_list* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file, "vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s\"",
		VB_As_Expr_list_type_to_string(node->type), "AS_EXPR_LIST");
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->as_expr != NULL)
	{
		Number++;
		if (error == -1) return 1;
		fclose(file);
		error = add_node_as_expr(node->as_expr);
		if (error) return 1;
	}

	if (node->arr != NULL)
	{
		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_array_expr(node->arr);
		if (error) return 1;
	}

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_As_expr.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_as_expr (struct VB_As_expr* node)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", Number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s | <f2> %s\"",
		VB_As_expr_type_to_string(node->type), VB_Id_type_to_string(node->id_type), "AS_EXPR");
	if (error == -1) return 1;

	error = fprintf(file, "\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// внутренние указатели

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Id_list.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_id_list (struct VB_Id_list* node)
{
	FILE* file = NULL;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", Number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s\"",
		"ID_LIST", "");
	if (error == -1) return 1;

	error = fprintf(file, "\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	// внутренние указатели

	fclose(file);
	return 0;
}

/*!
    Функция добавляет в файл GraphViz фрагмент дерева для VB_Array_expr.
  \param module   - узел дерева.
  \return         Если произошла ошибка работы с файлом, то возвращается 1, иначе 0.
*/
int add_node_array_expr (struct VB_Array_expr* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;
	Number++;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;
	Number++;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %d | <f1> %s\"",
		node->size, VB_Id_type_to_string(node->id_type));
	if (error == -1) return 1;

	error = fprintf(file, "\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->id != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_expr(node->id);
		if (error == -1) return 1;
	}

	if (node->list != NULL)
	{
		error = fopen_s(&file,"vb_lark.txt","at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_expr_list(node->list);
		if (error == -1) return 1;
		error = fopen_s(&file, "vb_lark.txt", "at");
		if (error) return 1;
	}

	fclose(file);
	return 0;
}