#include <stdio.h>
#include "tree_nodes.h"

extern struct VB_Module_stmt* root;

int add_node_stmt_list (struct VB_Stmt_list* node);
int add_node_param_list (struct VB_Param_list* node);
int add_node_if_stmt (struct VB_If_stmt* node);
int add_node_stmt (struct VB_Stmt* node);
int add_node_dim_stmt (struct VB_Dim_stmt* node);
int add_node_array_expr (struct VB_Array_expr* node);
int add_node_end_if_stmt (struct VB_End_if_stmt* node);
int add_node_as_expr (struct VB_As_expr* node);
int add_node_id_list (struct VB_Id_list* node);
int add_node_print_stmt (struct VB_Print_stmt* node);
int add_node_println_stmt (struct VB_Println_stmt* node);
int add_node_as_Expr_list (struct VB_As_Expr_list* node);
int add_node_readln_stmt (struct VB_Readln_stmt* node);
int add_node_read_stmt (struct VB_Read_stmt* node);


int print_tree()
{
	open_dot_file();
	add_node_stmt_module(root);
	close_dot_file();
	return 0;
}


/*!
	������� ����������� ��� ��������� � ������.
  \param type - ��� ���������.
  \return ������ - ��� ���������.
*/
char* VB_Expr_type_to_string (enum VB_Expr_type type)
{
	switch (type)
	{
	case(0):
		return "ID";
		break;
	case(1):
		return "EXPR_FUNC";
		break;
	case(2):
		return "CHAR_CONST";
		break;
	case(3):
		return "INT_CONST";
		break;
	case(4):
		return "STRING_CONST";
		break;
	case(5):
		return "BOOLEAN_CONST";
		break;
	case(6):
		return "ASSIGN";
		break;
	case(7):
		return "PLUS";
		break;
	case(8):
		return "MINUS";
		break;
	case(9):
		return "MUL";
		break;
	case(10):
		return "INT_DIV";
		break;
	case(11):
		return "DIV";
		break;
	case(12):
		return "POWER";
		break;
	case(13):
		return "MORE";
		break;
	case(14):
		return "LESS";
		break;
	case(15):
		return "MORE_OR_EQUAL";
		break;
	case(16):
		return "LESS_OR_EQUAL";
		break;
	case(17):
		return "NONEQUAL";
		break;
	case(18):
		return "EQUAL";
		break;
	case(19):
		return "UMINUS";
		break;
	case(20):
		return "UPLUS";
		break;
	case(21):
		return "GET_ITEM";
		break;
	}

	return "";
}

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
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� stmt_module.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ����������� ��� IF � ������.
  \param type - ��� IF.
  \return ������ - ��� IF.
*/
char* VB_If_stmt_type_to_string (enum VB_If_stmt_type type)
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
	������� ����������� ��� Stmt � ������.
  \param type - ��� Stmt.
  \return ������ - ��� Stmt.
*/
char* VB_Stmt_type_to_string (enum VB_Stmt_type type)
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

/*!
	������� ����������� ��� ����� If � ������.
  \param type - ��� ����� If.
  \return ������ - ��� ����� If.
*/
char* VB_End_if_stmt_type_to_string (enum VB_End_if_stmt_type type)
{
	switch(type)
	{
	case(0):
		return "ENDIF";
		break;
	case(1):
		return "ELSE";
		break;
	case(2):
		return "ELSE_IF_THEN";
		break;
	case(3):
		return "ELSE_IF_ENDL";
		break;
	}

	return "";
}

/*!
	������� ����������� ��� ������ ������������������ ����������� ���������� � ������.
  \param type - ��� ������ ������������������ ����������� ����������.
  \return ������ - ��� ������ ������������������ ����������� ����������.
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
	case(ARR_LIST):
		return "EXPR_ARR";
		break;
	}

	return "";
}

/*!
	������� ����������� ��� ���������� ��������������.
  \param type - ��� ���������� ��������������.
  \return ������ - ��� ���������� ��������������.
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
	������� ����������� ��� ��������������.
  \param type - ��� ��������������.
  \return ������ - ��� ��������������.
*/
char* VB_Id_type_to_string (enum VB_Id_type type)
{
	switch(type)
	{
	case(0):
		return "INTEGER";
		break;
	case(1):
		return "BOOLEAN";
		break;
	case(2):
		return "CHAR";
		break;
	case(3):
		return "STRING";
		break;
	}

	return "";
}

/*!
	������� ����������� ��� ����� Do...Loop.
  \param type - ��� ����� Do...Loop.
  \return ������ - ��� ����� Do...Loop.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Throw_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Catch_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Catch_stmt_list.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Try_catch_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Func_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Param_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Param_list.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Sub_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
		node->id, node->param_list != NULL ? 1 : 0 );
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Enum_expr.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Enum_expr_list.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
*/
int add_node_enum_expr_list (struct VB_Enum_expr_list* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s \"",
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Enum_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
*/
int add_node_enum_stmt (struct VB_Enum_stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s \"",
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Do_loop_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_While_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_For_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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

	//if (node->id != NULL) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//{
	//	Number++;
	//	error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
	//	number, Number);
	//	if (error == -1) return 1;

	//	fclose(file);
	//	error = add_node_expr(node->id);
	//	if (error) return 1;
	//}

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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Expr_list.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Stmt_list.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
	case(1):
		error = add_node_expr(node->expr);
		break;
	case(2):
		error = add_node_if_stmt(node->if_stmt);
		break;
	case(3):
		error = add_node_dim_stmt(node->dim_stmt);
		break;
	case(4):
		error = add_node_for_stmt(node->for_stmt);
		break;
	case(5):
		error = add_node_while_stmt(node->while_stmt);
		break;
	case(6):
		error = add_node_do_loop_stmt(node->do_loop_stmt);
		break;
	//case(7):
	//	error = add_node_enum_stmt(node->enum_stmt);
	//	break;
	//case(8):
	//	error = add_node_sub_stmt(node->sub_stmt);
	//	break;
	//case(9):
	//	error = add_node_func_stmt(node->func_stmt);
	//	break;
	case(10):
		error = add_node_try_catch_stmt(node->try_catch_stmt);
		break;
	case(11):
		error = add_node_throw_stmt(node->throw_stmt);
		break;
	case(12):
		error = add_node_print_stmt(node->print_stmt);
		break;
	case(13):
		error = add_node_println_stmt(node->println_stmt);
		break;
	case(14):
		error = add_node_read_stmt(node->read_stmt);
		break;
	case(15):
		error = add_node_readln_stmt(node->readln_stmt);
		break;
	}
	if (error) return 1;

	fclose(file);
	return 0;
}

/*!
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_If_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_End_if_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Dim_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_As_Expr_list.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_As_expr.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
*/
int add_node_as_expr (struct VB_As_expr* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s | <f2> %s\"",
		VB_As_expr_type_to_string(node->type), VB_Id_type_to_string(node->id_type), "AS_EXPR");
	if (error == -1) return 1;

	error = fprintf(file, "\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	if (node->list != NULL)
	{
		Number++;
		if (error == -1) return 1;
		fclose(file);
		error = add_node_id_list(node->list);
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

	if (node->id != NULL)
	{
		Number++;
		error = fopen_s(&file,"vb_lark.txt", "at");
		if (error) return 1;
		error = fprintf(file, "\n\t\"node%d\":f0 -> \"node%d\":f0;",
			number, Number);
		if (error == -1) return 1;
		fclose(file);
		error = add_node_expr(node->id);
		if (error) return 1;
	}

	fclose(file);
	return 0;
}

/*!
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Id_list.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
*/
int add_node_id_list (struct VB_Id_list* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s\"",
		"ID_LIST", "");
	if (error == -1) return 1;

	error = fprintf(file, "\n\t\tshape = \"record\"\n\t];");
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

	fclose(file);
	return 0;
}

/*!
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Array_expr.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
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

/*!
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Print_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
*/
int add_node_print_stmt (struct VB_Print_stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;
	Number++;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;
	Number++;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s\"",
		node->text, "PRINT");
	if (error == -1) return 1;

	error = fprintf(file, "\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	fclose(file);
	return 0;
}

/*!
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Println_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
*/
int add_node_println_stmt (struct VB_Println_stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;
	Number++;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;
	Number++;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s\"",
		node->text, "PRINTLN");
	if (error == -1) return 1;

	error = fprintf(file, "\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	fclose(file);
	return 0;
}

/*!
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Read_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
*/
int add_node_read_stmt (struct VB_Read_stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;
	Number++;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;
	Number++;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s\"",
		"", "READ");
	if (error == -1) return 1;

	error = fprintf(file, "\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	fclose(file);
	return 0;
}

/*!
    ������� ��������� � ���� GraphViz �������� ������ ��� VB_Readln_stmt.
  \param module   - ���� ������.
  \return         ���� ��������� ������ ������ � ������, �� ������������ 1, ����� 0.
*/
int add_node_readln_stmt (struct VB_Readln_stmt* node)
{
	FILE* file = NULL;
	int number = Number;
	int error = fopen_s(&file,"vb_lark.txt", "at");
	if (error) return 1;
	Number++;

	error = fprintf(file,"\n\t\"node%d\" [", number);
	if (error == -1) return 1;
	Number++;

	error = fprintf(file,"\n\t\tlabel = \"<f0> %s | <f1> %s\"",
		"", "READLN");
	if (error == -1) return 1;

	error = fprintf(file, "\n\t\tshape = \"record\"\n\t];");
	if (error == -1) return 1;

	fclose(file);
	return 0;
}