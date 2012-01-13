#include <stdio.h>
#include <process.h>


#include"xml.h"

#define WRITE_CHILD(number,Number,data,func,error,file)\
	{\
		int error1;\
		error1 = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0;",number, Number);\
		if (error1 == -1)\
		{ *error = 1; }\
		else {\
		error1 = (*func)(file, data);\
		if (error1) { *error = 1; }\
		 else { *error = 0; } } }

int Number = 0;

struct VB_Module_stmt * root;


char* statement_type_to_string (enum VB_Stmt_type type);
char* id_type_to_string (enum VB_Id_type type);
char* expression_type_to_string (enum VB_Expr_type type);
int add_expression_list (FILE* file, struct VB_Expr_list* list);
int add_expression (FILE* file, struct VB_Expr* expr);
int add_param_list (FILE* file, struct VB_Param_list* list);
int add_statement_list (FILE* file, struct VB_Stmt_list* list);
int add_catch_statement_list (FILE* file, struct VB_Catch_stmt_list* list);
int add_enum_statement (FILE* file, struct VB_Enum_stmt* stmt);
int add_enum_expression_list (FILE* file, struct VB_Enum_expr_list* list);
char* as_expression_list_type_to_string (enum VB_As_Expr_list_type type);
int add_end_if_statement (FILE* file, struct VB_End_if_stmt* stmt);
int add_if_statement (FILE* file, struct VB_If_stmt* stmt);
int add_readln_stmt (FILE* file, struct VB_Readln_stmt* stmt);
int add_println_stmt (FILE* file, struct VB_Println_stmt* stmt);
int add_try_catch_stmt (FILE* file, struct VB_Try_catch_stmt* stmt);
int add_print_stmt (FILE* file, struct VB_Print_stmt* stmt);
int add_throw_stmt (FILE* file, struct VB_Throw_stmt* stmt);
int add_while_statement (FILE* file, struct VB_While_stmt* stmt);
int add_for_statement (FILE* file, struct VB_For_stmt* stmt);
int add_dim_statement (FILE* file, struct VB_Dim_stmt* stmt);
int add_do_loop_statement (FILE* file, struct VB_Do_loop_stmt* stmt);
int add_read_stmt (FILE* file, struct VB_Read_stmt* stmt);
int add_return_statement (FILE* file, struct VB_Return_stmt* stmt);

//int fopen_s (FILE** file, char* filename, char* mode)
//{
//    *file = fopen(filename,mode);
//
//    if (*file == NULL)
//        return 1;
//    else
//        return 0;
//}

/*!
	\brief Функция открытия файла для GraphViz.
	\param file Дескриптор открытого файла.
	\param filename Имя открываемого файла.
	\return 0 если ошибок нет.
*/
int open_gv_file (FILE** file, char* filename)
{
	int result = 0;

	result = fopen_s(file,filename,"wt");

	if (result)
		return 1;

	result = fprintf(*file,
		"digraph G\n{\n\tgraph [ rankdir = \"LR\" ];\n\tnode [ fontsize = \"16\" shape = \"ellipse\"  ];\n\tedge [ ];");
	if (result == -1)
		return 1;

	return 0;
}

/*!
	\brief Функция добавления процедуры в файл.
	\param file Дескриптор файла.
	\param stmt Процедура.
	\return 0 если ошибок нет.
*/
int add_sub_statement (FILE* file, struct VB_Sub_stmt* stmt)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Sub Stmt\
						 | <f1> id: %s \"\n\t\tshape = \"record\"\n\t];",
						 number, stmt->id);
	if (error == -1)
		return 1;

	if (stmt->param_list != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \
							 \"node%d\":f0", number, ++Number);
		if (error == -1)
			return 1;
		error = add_param_list(file,stmt->param_list);
		if (error)
			return 1;
	}
	if (stmt->stmt_list)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \
							 \"node%d\":f0", number, ++Number);
		if (error == -1)
			return 1;
		error = add_statement_list(file,stmt->stmt_list);
		if (error)
			return 1;
	}

	return 0;
}

/*!
	\brief Функция добавления функции в файл.
	\param file Дескриптор файла.
	\param stmt Функция.
	\return 0 если ошибок нет.
*/
int add_func_statement (FILE* file, struct VB_Func_stmt* stmt)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Sub Stmt\
						 | <f1> id: %s | <f2> return type: %s \"\n\t\tshape = \"record\"\n\t];",
						 number, stmt->id, id_type_to_string(stmt->id_type));
	if (error == -1)
		return 1;

	if (stmt->param_list != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \
							 \"node%d\":f0", number, ++Number);
		if (error == -1)
			return 1;
		error = add_param_list(file,stmt->param_list);
		if (error)
			return 1;
	}
	if (stmt->stmt_list)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \
							 \"node%d\":f0", number, ++Number);
		if (error == -1)
			return 1;
		error = add_statement_list(file,stmt->stmt_list);
		if (error)
			return 1;
	}
	if (stmt->expr)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0", number, ++Number);
		if (error == -1)
			return 1;
		error = add_expression(file,stmt->expr);
		if (error)
			return 1;
	}

	return 0;
}

/*!
	\brief Функция добавления обработки исключения в файл.
	\param file Дескриптор файла.
	\param stmt Обработка исключения.
	\return 0 если ошибок нет.
*/
int add_try_catch_stmt (FILE* file, struct VB_Try_catch_stmt* stmt)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Try...Catch", number);

	if (error == -1)
		return 1;

	if (stmt->stmt_list != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0", number, ++Number);
		if (error == -1)
			return 1;
		error = add_statement_list(file,stmt->stmt_list);
		if (error)
			return 1;
	}
	if (stmt->fin_stmt_list != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0", number, ++Number);
		if (error == -1)
			return 1;
		error = add_statement_list(file,stmt->fin_stmt_list);
		if (error)
			return 1;
	}
	if (stmt->catch_list != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0", number, ++Number);
		if (error == -1)
			return 1;
		error = add_catch_statement_list(file,stmt->catch_list);
		if (error)
			return 1;
	}

	return 0;
}

/*!
	\brief Функция добавления обработки исключений.
	\param file Дескриптор файла.
	\param stmt Обработка исключений.
	\return 0 если ошибок нет.
*/
int add_catch_statement (FILE* file, struct VB_Catch_stmt* stmt)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Catch stmt\
						 | <f1> id: %s \"\n\t\tshape = \"record\"\n\t];", number,stmt->id);
	if (error == -1)
		return 1;
	if (stmt->stmt_list != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0", number, ++Number);
		if (error == -1)
			return 1;
		error = add_statement_list(file,stmt->stmt_list);
		if (error)
			return 1;
	}

	return 0;
}

/*!
	\brief Функция добавления в файл инициализации массива.
	\param file Дескриптор файла.
	\param expr Инициализация массива.
	\return 0 если ошибок нет.
*/
int add_array_expression (FILE* file, struct VB_Array_expr* expr)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Array Expr\
						 | <f1> is init: %d | <f2> size: %d | <f3> id: %s | <f4> type: %s\
						 \"\n\t\tshape = \"record\"\n\t];",number,expr->is_init,
						 expr->size,expr->id,id_type_to_string(expr->id_type));
	if (error == -1)
		return 1;

	if (expr->list != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",number,++Number);
		if (error == -1)
			return 1;
		error = add_expression_list(file,expr->list);
		if (error)
			return 1;
	}

	return 0;
}

/*!
	\brief Функция добавления списка id в файл.
	\param file Дескриптор файла.
	\param list Список id.
	\return 0 если ошибок нет.
*/
int add_id_list (FILE* file, struct VB_Id_list* list)
{
	int error, number = Number;
	//struct VB_Expr* item = list->id;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> id list\
						 \"\n\t\tshape = \"record\"\n\t];",number);

	if (error == -1)
		return 1;

	if (list->id != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",number,++Number);
		if (error == -1)
			return 1;
		error = add_expression(file,list->id);
		if (error)
			return 1;
	}

	list = list->next;

	if (list)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",number,++Number);
		if (error == -1)
			return 1;
		error = add_id_list(file,list);
		if (error)
			return 1;

		//list = list->next;
	}

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
						 | <f1> %s \"\n\t\tshape = \"record\"\n\t];", Number, stmt->expr->expr_string);
	if (error == -1)
		return 1;
	Number++;

	return 0;
}

/*!
	\brief Функция добавляет в файл ввод с стандартного потока ввода.
	\param file Дескриптор файла.
	\param stmt Ввод с стандарнтый поток ввода.
	\return 0 если ошибок нет.
*/
int add_read_stmt (FILE* file, struct VB_Read_stmt* stmt)
{
	int error;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Console.Read \
						 \"\n\t\tshape = \"record\"\n\t];", Number);
	if (error == -1)
		return 1;
	Number++;

	return 0;
}

/*!
	\brief Функция добавляет в файл ввод строки с стандартного потока ввода.
	\param file Дескриптор файла.
	\param stmt Ввод строки с стандартного потока ввода.
	\return 0 если ошибок нет.
*/
int add_readln_stmt (FILE* file, struct VB_Readln_stmt* stmt)
{
	int error;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Console.Readln\
						 \"\n\t\tshape = \"record\"\n\t];", Number);
	if (error == -1)
		return 1;
	Number++;

	return 0;
}

/*!
	\brief Функция добавляет в файл элемент перечисления.
	\param file Дескриптор файла.
	\param expr Элемент перечисления.
	\return 0 если нет ошибок.
*/
int add_enum_expression (FILE* file, struct VB_Enum_expr* expr)
{
	int error;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Enum Expr\
						 | <f1> is init: %d | <f2> id: %s | <f3>value: %d\
						 \"\n\t\tshape = \"record\"\n\t];", Number,
						 expr->is_init, expr->id, expr->value);
	if (error == -1)
		return 1;
	Number++;

	return 0;
}

/*!
	\brief Функция добавления параметра функции в файл.
	\param file Дескриптор файла.
	\param stmt Параметр функции.
	\return 0 если ошибок нет.
*/
int add_param_statement (FILE* file, struct VB_Param_stmt* stmt)
{
	int error;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Param Stmt\
						 | <f1> is by ref: %d | <f2> id: %s | <f3>type: %s\
						 \"\n\t\tshape = \"record\"\n\t];", Number++,stmt->is_by_ref,
						 stmt->id,id_type_to_string(stmt->id_type));
	if (error == -1)
		return 1;

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
						 | <f1> %s \"\n\t\tshape = \"record\"\n\t];", Number, stmt->expr->expr_string);
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
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Declaration \
						 \\nstaement| <f1> %s \"\n\t\tshape = \"record\"\n\t];", number,statement_type_to_string(stmt->type));
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
	\brief Функция добавления возврата из функции в файл.
	\param file Дескриптор файла.
	\param stmt Возврат из функции.
	\return 0 если ошибок нет.
*/
int add_return_statement (FILE* file, struct VB_Return_stmt* stmt)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Return\
						 \"\n\t\tshape = \"record\"\n\t];", number);
	if (error == -1)
		return 1;
	if (stmt->expr != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_expression(file,stmt->expr);
		if (error)
			return 1;
	}

	return 0;
}

/*!
	\brief Функция добавления выражения в файл.
	\param file Дескриптор файла.
	\param expr Выражение.
	\return 0 если ошибок не возникло.
*/
int add_expression (FILE* file, struct VB_Expr* expr)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Expression\
						 | <f1> str: %s | <f2> int: %d | <f3> type: %s \
						 | <f4> id type: %s\"\n\t\tshape = \"record\"\n\t];",
						 number,expr->expr_string,expr->int_val,expression_type_to_string(expr->type),
						 id_type_to_string(expr->id_type));
	if (error == -1)
		return 1;

	if (expr->left_chld != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			Number, Number + 1);
		number = Number;
		if (error == -1)
			return 1;
		Number++;
		error = add_expression(file,expr->left_chld);
		if (error)
			return 1;
	}
	if (expr->right_chld != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, Number + 1);
		if (error == -1)
			return 1;
		Number++;
		error = add_expression(file,expr->right_chld);
		if (error)
			return 1;
	}
	if (expr->list)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_expression_list(file,expr->list);
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
	int error, number = Number;
	struct VB_Decl_stmt* item = list->first;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Decl stmt list\"\n\t\tshape = \"record\"\n\t];",
						 number);
	if (error == -1)
		return 1;

	while (item)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_declaration_statement(file, item);
		if (error)
			return 1;

		item = item->next;
	}

	return 0;
}

/*!
	\brief Функция преобразования типа идентификатора в строку.
	\param type Тип идентификатора.
	\return Тип идентификатора в виде строки.
*/
char* id_type_to_string (enum VB_Id_type type)
{
	switch (type)
	{
	case (BOOLEAN_E):
		return "boolean";
	case (CHAR_E):
		return "char";
	case (INTEGER_E):
		return "integer";
	case (STRING_E):
		return "string";
	}

	return "";
}

/*!
	\brief Функция преобразования типа выражения в строку.
	\param type Тип выражения.
	\return Тип выражения в виде строки.
*/
char* expression_type_to_string (enum VB_Expr_type type)
{
	switch(type)
	{
    case (EXPR_FUNC):
        return "EXPR FUNC";
	case (ASSIGN):
		return "ASSIGN";
	case (BOOLEAN_CONST_E):
		return "BOOLEAN CONST";
	case (BRK_EXPR):
		return "()";
	case (CHAR_CONST_E):
		return "CHAR CONST";
	case (DIV):
		return "Div";
	case (EQUAL_E):
		return "EQUAL";
	case (GET_ITEM):
		return "(i)";
	case (ID_E):
		return "id";
	case (INT_CONST_E):
		return "INTEGER CONST";
	case (INT_DIV):
		return ("int div");
	case (LESS):
		return "less";
	case (LESS_OR_EQUAL_E):
		return "nonmore";
	case (MINUS):
		return "-";
	case (MORE):
		return "more";
	case (MORE_OR_EQUAL_E):
		return "nonless";
	case (MUL):
		return "*";
	case (NONEQUAL_E):
		return "nonequal";
	case (PLUS):
		return "+";
	case (POWER):
		return "^";
	case (STRING_CONST_E):
		return "STRING CONST";
	case (UMINUS_E):
		return "uminus";
	case (UPLUS):
		return "uplus";
	case (READ_E):
		return "Console.Read()";
	case (READLN_E):
		return "Console.ReadLine()";
	}

	return "";
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
    case (RETURN_E):
        return "RETURN";
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
	//case(14):
	//	return "READ";
	//	break;
	//case(15):
	//	return "READLN";
	//	break;
	case(READKEY_E):
		return "READKEY";
		break;
	}

	return "";
}

/*!
	\brief Фукнкция преобразрвания типа списка инициализации в строку.
	\param type Тип списка инициализации.
	\return Строка - тип списка инициализации.
*/
char* as_expression_list_type_to_string (enum VB_As_Expr_list_type type)
{
	switch (type)
	{
	case (ARRAY):
		return "Array";
	case (ARR_LIST):
		return "Array List";
	case (EXPR):
		return "Expression";
	case (EXPR_LIST):
		return "Expression List";
	}

	return "";
}

/*!
	\brief Функция преобразования типа инициализации в строку.
	\param type Тип инициализации.
	\return Строка - тип инициализации.
*/
char* as_expression_type_to_string (enum VB_As_expr_type type)
{
	switch (type)
	{
	case (ID_INIT):
		return "ID INIT";
	case (ID_LIST):
		return "ID LIST";
	case (ONE_ID):
		return "ONE ID";
	}

	return "";
}

/*!
	\brief Функция преобразования типа цикла FOR в строку.
	\param type Тип цикла FOR.
	\return Строка - тип цикла FOR.
*/
char* for_statement_type_to_string (enum VB_For_stmt_type type)
{
	switch (type)
	{
	case (SIMPLE):
		return "SIMPLE";
	case (WITH_DECL):
		return "WITH_DECL";
	case (WITH_DECL_AND_STEP):
		return "WITH_DECL_AND_STEP";
	case (WITH_STEP):
		return "WITH_STEP";
	}

	return "";
}

/*!
	\brief Функция преобразования типа цикла Do..Loop в строку.
	\param type Тип цикла.
	\return Строка - тип цикла.
*/
char* do_loop_type_to_string (enum VB_Do_loop_type type)
{
	switch (type)
	{
	case (DO_UNTIL):
		return "Do Until";
	case (DO_WHILE):
		return "Do While";
	case (LOOP_UNTIL):
		return "Loop Until";
	case (LOOP_WHILE):
		return "Loop While";
	}

	return "";
}

/*!
	\brief Функция преобразования типа окончания If в строку.
	\param type Тип окончания If.
	\return Строка - тип окончания If.
*/
char* end_if_statement_type_to_string (enum VB_End_if_stmt_type type)
{
	switch (type)
	{
	case (ELSE_E):
		return "Else";
	case (ELSE_IF_ENDL_E):
		return "ElseIf endl";
	case (ELSE_IF_THEN_E):
		return "ElseIf Then";
	case (ENDIF_E):
		return "End If";
	}

	return "";
}

/*!
	\brief Функция преобразования типа If в строку.
	\param type Тип If.
	\return Строка - тип If.
*/
char* if_statement_type_to_string (enum VB_If_stmt_type type)
{
	switch (type)
	{
	case (IF_ELSE_INLINE):
		return "IF_ELSE_INLINE";
	case (IF_ENDL):
		return "IF_ENDL";
	case (IF_INLINE):
		return "IF_INLINE";
	case (IF_THEN):
		return "IF_THEN";
	}

	return "";
}

int add_statement (FILE* file, struct VB_Stmt* stmt)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Stmt\
                        | type: %s \"\n\t\tshape = \"record\"\n\t];",number,
						 statement_type_to_string(stmt->type));
	if (error == -1)
		return 1;

	if (stmt->value == NULL)
		return 0;

	switch (stmt->type)
	{
    case (READKEY_E):
        break;
    case (RETURN_E):
         error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_return_statement(file,(struct VB_Return_stmt*)stmt->value);
        break;
    case (ENDL_E):
        break;
    case (ENUM_D):
        error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_enum_statement(file,(struct VB_Enum_stmt*)stmt->value);
        break;
    case (SUB_D):
        error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_sub_statement(file,(struct VB_Sub_stmt*)stmt->value);
        break;
    case (FUNC_D):
        error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_func_statement(file,(struct VB_Func_stmt*)stmt->value);
        break;
	case(1):
        error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_expression(file,(struct VB_Expr*)stmt->value);
        break;
	case(2):
        error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_if_statement(file,(struct VB_If_stmt*)stmt->value);
        break;
	case(3):
        error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_dim_statement(file,(struct VB_Dim_stmt*)stmt->value);
        break;
	case(4):
        error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_for_statement(file,(struct VB_For_stmt*)stmt->value);
        break;
	case(5):
        error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_while_statement(file,(struct VB_While_stmt*)stmt->value);
        break;
	case(6):
        error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_do_loop_statement(file,(struct VB_Do_loop_stmt*)stmt->value);
        break;
	case(10):
        error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_try_catch_stmt(file,(struct VB_Try_catch_stmt*)stmt->value);
        break;;
	case(11):
        error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_throw_stmt(file,(struct VB_Throw_stmt*)stmt->value);
        break;
	case(12):
        error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_print_stmt(file,(struct VB_Print_stmt*)stmt->value);
        break;
	case(13):
        error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_println_stmt(file,(struct VB_Println_stmt*)stmt->value);
        break;
	//case(14):
 //       error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
	//		number, ++Number);
	//	if (error == -1)
	//		return 1;
	//	error = add_read_stmt(file,(struct VB_Read_stmt*)stmt->value);
 //       break;
	//case(15):
 //       error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
	//		number, ++Number);
	//	if (error == -1)
	//		return 1;
	//	error = add_readln_stmt(file,(struct VB_Readln_stmt*)stmt->value);
 //       break;
	}

	if (error)
		return 1;

	return 0;
}

/*!
	\brief Функция добавления If в файл.
	\param file Дескриптор файла.
	\param stmt If.
	\return 0 если ошибок нет.
*/
int add_if_statement (FILE* file, struct VB_If_stmt* stmt)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> If Stmt\
						 | type: %s \"\n\t\tshape = \"record\"\n\t];", number,
						 if_statement_type_to_string(stmt->type));
	if (error == -1)
		return 1;

	if (stmt->expr != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_expression(file,stmt->expr);
		if (error)
			return 1;
	}

	if (stmt->stmt_list != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_statement_list(file,stmt->stmt_list);
		if (error)
			return 1;
	}

	if (stmt->else_list)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_statement_list(file,stmt->else_list);
		if (error)
			return 1;
	}

	if (stmt->end_stmt != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_end_if_statement(file,stmt->end_stmt);
		if (error)
			return 1;
	}

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
	int error, number = Number;
	struct VB_Stmt* item = list->first;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Stmt list\"\n\t\tshape = \"record\"\n\t];",
						 number);
	if (error == -1)
		return 1;

	while (item)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_statement(file, item);
		if (error)
			return 1;

		item = item->next;
	}

	return 0;
}

/*!
	\brief Функция для добавления оператора перечисления.
	\param file Дескриптор файла.
	\param stmt Оператор перечисления.
	\return 0 если нет ошибок.
*/
int add_enum_statement (FILE* file, struct VB_Enum_stmt* stmt)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Enum Stmt\
						 | <f1> id: %s \"\n\t\tshape = \"record\"\n\t];", number, stmt->id);
	if (error == -1)
		return 1;

	if (stmt->list != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0", number, ++Number);
		if (error == -1)
			return 1;
		error = add_enum_expression_list(file,stmt->list);
		if (error)
			return 1;
	}

	return 0;
}

/*!
	\brief Функция добавления инициализации в файл.
	\param file Дескриптор файла.
	\param expr Инициализация.
	\return 0 если ошибок нет.
*/
int add_as_expression (FILE* file, struct VB_As_expr* expr)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> As Expr\
						 |<f1> type: %s | <f2> id type: %s\
						 \"\n\t\tshape = \"record\"\n\t];",number,
						 as_expression_type_to_string(expr->type),
						 id_type_to_string(expr->id_type));
	if (error == -1)
		return 1;

	if (expr->expr != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_expression(file,expr->expr);
		if (error)
			return 1;
	}

	if (expr->id != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_expression(file,expr->id);
		if (error)
			return 1;
	}

	if (expr->list != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_id_list(file,expr->list);
		if (error)
			return 1;
	}

	return 0;
}

/*!
	\brief Функция добавления цикла FOR в файл.
	\param file Дескриптор файла.
	\param stmt Цикл FOR.
	\return 0 если ошибок нет.
*/
int add_for_statement (FILE* file, struct VB_For_stmt* stmt)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> For Stmt\
						 |<f1> type: %s |<f2> id: %s |<f3> from: %d\
						 |<f4> to: %d |<f5> step: %d \"\n\t\tshape = \"record\"\n\t];",
						 number,for_statement_type_to_string(stmt->type),stmt->id,
						 stmt->from_val,stmt->to_val,stmt->step_val);
	if (error == -1)
		return 1;
	if (stmt->stmt_list != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_statement_list(file,stmt->stmt_list);
		if (error)
			return 1;
	}

	if (stmt->new_id)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_expression(file,stmt->new_id);
		if (error)
			return 1;
	}

	return 0;
}

/*!
	\brief Функция добавления конца If в файл.
	\param file Дескриптор файла.
	\param stmt Конец If.
	\return 0 если ошибок нет.
*/
int add_end_if_statement (FILE* file, struct VB_End_if_stmt* stmt)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> End If\
						 |<f1> %s \"\t\tshape = \"record\"\n\t];", number,
						 end_if_statement_type_to_string(stmt->type));
	if (error == -1)
		return 1;

	if (stmt->stmt_list == NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_statement_list(file,stmt->stmt_list);
		if (error)
			return 1;
	}

	return 0;
}

/*!
	\brief Функция  добавления цикла Do...Loop в файл.
	\param file Дескриптор файла.
	\param stmt Цикл.
	\return 0 если ошибок нет.
*/
int add_do_loop_statement (FILE* file, struct VB_Do_loop_stmt* stmt)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Do...Loop\
						 |<f1> %s \"\n\t\tshape = \"record\"\n\t];", number,
						 do_loop_type_to_string(stmt->type));
	if (error == -1)
		return 1;

	if (stmt->stmt_list != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_statement_list(file,stmt->stmt_list);
		if (error)
			return 1;
	}

	if (stmt->expr != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_expression(file,stmt->expr);
		if (error)
			return 1;
	}

	return 0;
}

/*!
	\brief Функция добавления цикла While в файл.
	\param file Дескриптор файла.
	\param stmt Цикл While.
	\return 0 если ошибок нет.
*/
int add_while_statement (FILE* file, struct VB_While_stmt* stmt)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> While Stmt\
						 \"\n\t\tshape = \"record\"\n\t];",number);
	if (error == -1)
		return 1;

	if (stmt->stmt_list)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_statement_list(file,stmt->stmt_list);
		if (error)
			return 1;
	}

	if (stmt->expr != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_expression(file,stmt->expr);
		if (error)
			return 1;
	}

	return 0;
}

/*!
	\brief Функция добавления списка инициализации.
	\param file Дескриптор файла.
	\param list Список инициализации.
	\return 0 если ошибок нет.
*/
int add_as_expression_list (FILE* file, struct VB_As_Expr_list* list)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> As Expr List\
						 | <f1> type: %s \"\n\t\tshape = \"record\"\n\t];", number,
						 as_expression_list_type_to_string(list->type));
	if (error == -1)
		return 1;

	if (list->as_expr != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_as_expression(file,list->as_expr);
		if (error)
			return 1;
	}
	if (list->arr != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_array_expression(file,list->arr);
		if (error)
			return 1;
	}

	return 0;
}

/*!
	\brief Функция для добавления оператора объявления в файл.
	\param file Дескриптор файла.
	\param stmt Оператор объявления переменных.
	\return 0 если ошибок нет.
*/
int add_dim_statement (FILE* file, struct VB_Dim_stmt* stmt)
{
	int error, number = Number;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Dim Stmt\
						 \"\n\t\tshape = \"record\"\n\t];", number);
	if (error == -1)
		return 1;

	if (stmt->list != NULL)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",number, ++Number);
		if (error == -1)
			return 1;
		error = add_as_expression_list(file,stmt->list);
		if (error)
			return 1;
	}

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
	int error, number = Number;
	struct VB_Expr* item = list->first;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Expr list\"\n\t\tshape = \"record\"\n\t];",
						 number);
	if (error == -1)
		return 1;

	while (item)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_expression(file,item);
		if (error)
			return 1;

		item = item->next;
	}

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
	int error, number = Number;
	struct VB_Catch_stmt* item = list->first;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Catch stmt list\"\n\t\tshape = \"record\"\n\t];",
						 number);
	if (error == -1)
		return 1;

	while (item)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_catch_statement(file,item);
		if (error)
			return 1;

		item = item->next;
	}

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
	int error, number = Number;
	struct VB_Enum_expr* item = list->first;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Enum expr list\"\n\t\tshape = \"record\"\n\t];",
						 number);
	if (error == -1)
		return 1;

	while (item)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;
		error = add_enum_expression(file,item);
		if (error)
			return 1;

		item = item->next;
	}

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
	int error, number = Number;
	struct VB_Param_stmt* item = list->first;

	error = fprintf(file,"\n\t\"node%d\" [\n\t\tlabel = \"<f0> Param list\"\n\t\tshape = \"record\"\n\t];",
						 number);
	if (error == -1)
		return 1;

	while(item)
	{
		error = fprintf(file,"\n\t\"node%d\":f0 -> \"node%d\":f0",
			number, ++Number);
		if (error == -1)
			return 1;

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

void print_tree(){
	FILE* file = NULL;
	open_gv_file(&file,"test.dot");
	add_module_statement (file, root);
	close_gv_file (file);

	printf("\n\nCreating the image...\n");

	// Сюда надо вписать путь до dot.exe
//	if (_spawnl(_P_WAIT,"D:\\Graphviz2.26.3\\bin\\dot.exe",
//		"dot.exe -Tpng test.dot -o test.png",NULL) == 0)
//		_spawnl(_P_NOWAIT,"C:\\Windows\\system32\\mspaint.exe",
//			"mspaint.exe test.png",NULL);

	printf("Done!\n\n");

	printf("Creating the xml tree...\n");

	VBX_createXML (root);

	printf("Done!\n");
}
