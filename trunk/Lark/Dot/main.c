#include <stdio.h>

#include"tree_nodes.h"

long int Number = 0;

char* statement_type_to_string (enum VB_Stmt_type type);

/*!
	\brief Функция открытия файла для GraphViz.
	\param file Дескриптор открытого файла.
	\param filename Имя открываемого файла.
	\return 0 если ошибок нет.
*/
int open_gv_file (FILE* file, char* filename)
{
	int result = 0;

	result = fopen_s(&file,filename,"wt");

	if (result)
		return 1;

	result = fprintf(file,
		"digraph G\n{\n\tgraph [ rankdir = \"LR\" ];\n\tnode [ fontsize = \"16\" shape = \"ellipse\"  ];\n\tedge [ ];");
	if (result == -1)
		return 1;

	return 0;
}

int add_enum_statement (FILE* file, struct VB_Enum_stmt* stmt)
{
	return 0;
}

int add_sub_statement (FILE* file, struct VB_Sub_stmt* stmt)
{
	return 0;
}

int add_func_statement (FILE* file, struct VB_Func_stmt* stmt)
{
	return 0;
}

/*!
	\brief Функция добавления выброса исключения в файл.
	\param file Дескриптор файла.
	\param stmt Выброс исключения.
	\return 0 если ошибок нет.
*/
int add_throw_stmt (FILE* file, struct VB_Throw_stmt* stmt)
{
	int error;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Throw \
						 | <f1> %s \"\n\t\tshape = \"record\"\n\t];", Number, stmt->string);
	if (error == -1)
		return 1;
	Number++;

	return 0;
}

/*!
	\brief Функция добавляет в файл вывод в стандартный поток вывода.
	\param file Дескриптор файла.
	\param stmt Вывод в стандартный поток вывода.
	\return 0, если ошибок нет.
*/
int add_print_stmt (FILE* file, struct VB_Print_stmt* stmt)
{
	int error;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Console.Print \
						 | <f1> %s \"\n\t\tshape = \"record\"\n\t];", Number, stmt->text);
	if (error == -1)
		return 1;
	Number++;

	return 0;
}

/*!
	\brief Функция добавления в файл вывода в стандартный поток с переносом строки.
	\param file Дескриптор файла.
	\param stmt Вывод в стандартный поток с переносом строки.
	\return 0 если ошибок нет.
*/
int add_println_stmt (FILE* file, struct VB_Println_stmt* stmt)
{
	int error;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Console.Println \
						 | <f1> %s \"\n\t\tshape = \"record\"\n\t];", Number, stmt->text);
	if (error == -1)
		return 1;
	Number++;

	return 0;
}

/*!
	\brief Функция добавления оператора объявления.
	\param file Дескриптор файла.
	\param stmt Оператор.
	\reuturn 0 если ошибок нет.
*/
int add_declaration_statement (FILE* file, struct VB_Decl_stmt* stmt)
{
	int error, number;
	
	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Declaration \
						 \\nstaement| <f1> %s \"\n\t\tshape = \"record\"\n\t];", Number,statement_type_to_string(stmt->type));
	if (error == -1)
		return 1;

	if (stmt->enum_stmt != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0;",
			Number, Number + 1);
		if (error == -1)
			return 1;
		number = Number;
		Number++;
		error = add_enum_statement (file, stmt->enum_stmt);
		if (error)
			return 1;
	}

	if (stmt->sub_stmt != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number + 1);
		if (error == -1)
			return 1;
		Number++;
		error = add_sub_statement (file, stmt->sub_stmt);
		if (error)
			return 1;
	}
	
	if (stmt->func_stmt != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number + 1);
		if (error == -1)
			return 1;
		Number++;
		error = add_func_statement (file, stmt->func_stmt);
		if (error)
			return 1;
	}

	return 0;
}

/*!
	\brief Функция добавления листа объявления в файл.
	\param file Дескриптор файла.
	\list Лист объявления.
	\return 0 если ошибок нет.
*/
int add_declaration_list (FILE* file, struct VB_Decl_stmt_list* list)
{
	int error;
	struct VB_Decl_stmt* item = list->first;

	while (item)
	{
		error = add_declaration_statement(file, item);
		if (error)
			return 1;

		item = item->next;
	}

	return 0;
}

/*!
	\brief Функция преобразует тип Stmt в строку.
	\param type - Тип Stmt.
	\return Строка - тип Stmt.
*/
char* statement_type_to_string (enum VB_Stmt_type type)
{
	switch (type)
	{
	case(0):
		return "ENDL";
		break;
	case(1):
		return "EXPR";
		break;
	case(2):
		return "IF";
		break;
	case(3):
		return "DIM";
		break;
	case(4):
		return "FOR";
		break;
	case(5):
		return "WHILE";
		break;
	case(6):
		return "DO_LOOP";
		break;
	case(7):
		return "ENUM";
		break;
	case(8):
		return "SUB";
		break;
	case(9):
		return "FUNC";
		break;
	case(10):
		return "TRY_CATCH";
		break;
	case(11):
		return "THROW";
		break;
	case(12):
		return "PRINT";
		break;
	case(13):
		return "PRINTLN";
		break;
	case(14):
		return "READ";
		break;
	case(15):
		return "READLN";
		break;
	case(16):
		return "READKEY";
		break;
	}

	return "";
}

int add_statement_statement(FILE* file, struct VB_Stmt* stmt)
{
	return 0;
}

/*!
	\brief Функция добавления списка операторов в файл.
	\param file Дескриптор файла.
	\param list Список операторов.
	\return 0 если ошибок нет.
*/
int add_statement_list (FILE* file, struct VB_Stmt_list* list)
{
	int error;
	struct VB_Stmt* item = list->first;

	while (item)
	{
		error = add_statement_statement(file, item);
		if (error)
			return 1;

		item = item->next;
	}

	return 0;
}

int add_expression (FILE* file, struct VB_Expr* expr)
{
	return 0;
}

/*!
	\brief Функция добавления списка выражений в файл.
	\param file Дескриптор файла.
	\param list Список выражений.
	\return 0 если ошибок нет.
*/
int add_expression_list (FILE* file, struct VB_Expr_list* list)
{
	int error;
	struct VB_Expr* item = list->first;

	while (item)
	{
		error = add_expression(file,item);
		if (error)
			return 1;

		item = item->next;
	}

	return 0;
}

int add_catch_statement (FILE* file, struct VB_Catch_stmt* stmt)
{
	return 0;
}

/*!
	\brief Функция добавления списка обработки исключений.
	\param file Дескриптор файла.
	\param list Список обработки исключений.
	\return 0 если ошибок нет.
*/
int add_catch_statement_list (FILE* file, struct VB_Catch_stmt_list* list)
{
	int error;
	struct VB_Catch_stmt* item = list->first;

	while (item)
	{
		error = add_catch_statement(file,item);
		if (error)
			return 1;

		item = item->next;
	}

	return 0;
}

int add_enum_expression (FILE* file, struct VB_Enum_expr* expr)
{
	return 0;
}

/*!
	\brief Функция добавления в файл списка перечисления.
	\param file Дескриптор файла.
	\param list Список перечисления.
	\return 0 если ошибок нет.
*/
int add_enum_expression_list (FILE* file, struct VB_Enum_expr_list* list)
{
	int error;
	struct VB_Enum_expr* item = list->first;

	while (item)
	{
		error = add_enum_expression(file,item);
		if (error)
			return 1;

		item = item->next;
	}

	return 0;
}

int add_param_statement (FILE* file, struct VB_Param_stmt* stmt)
{
	return 0;
}

/*!
	\brief Функция добавления списка параметров в файл.
	\param file Дескриптор файла.
	\param list Список параметров.
	\return 0 если ошибок нет.
*/
int add_param_list (FILE* file, struct VB_Param_list* list)
{
	int error;
	struct VB_Param_stmt* item = list->first;

	while(item)
	{
		error = add_param_statement(file,item);
		if (error)
			return 1;

		item = item->next;
	}

	return 0;
}

/*!
	\brief Функция добавления модуля в файл.
	\param file Дескриптор файла.
	\param module Добавляемый модуль.
	\return 0 если ошибок нет.
*/
int add_module_statement (FILE* file, struct VB_Module_stmt* module)
{
	int number = 0;
	int error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Module | <f1> %s \"\n\t\tshape = \"record\"\n\t];",
		Number, module->id);
	if (error == -1)
		return 1;

	if (module->decl_list != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0;",
			Number, Number + 1);
		if (error == -1)
			return 1;
		number = Number;
		Number++;
		error = add_declaration_list(file, module->decl_list);
		if (error)
			return 1;
	}

	if (module->stmt_list != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number + 1);
		if (error == -1)
			return 1;
		Number++;
		error = add_statement_list(file, module->stmt_list);
		if (error)
			return 1;
	}

	return 0;
}

/*!
	\brief Функция закрытия файла для GraphViz.
	\param file Дескриптор закрываемого файла.
	\return 0 если ошибок нет.
*/
int close_gv_file (FILE* file)
{
	int error = fprintf(file, "\n};");
	if (error == -1)
		return 1;
	
	fclose(file);

	return 0;
}

int main (int argc, char* argv[])
{
	return 0;
}