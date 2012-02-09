//
//
#ifndef H_DATA_TYPES
#define H_DATA_TYPES

/*! \enum VB_Id_type
    ������������ ����� ���������������.
 */
enum VB_Id_type
{
	DATA_INTEGER,
	DATA_BOOLEAN,
	DATA_CHAR,
	DATA_STRING
};

/*! \enum VB_Type_of_expr
    ������������ ����� ��������.
 */
enum VB_Stmt_type
{
	STMT_ENDL,
	STMT_EXPR,
	STMT_IF,
	STMT_DIM,
	STMT_FOR,
	STMT_WHILE,
	STMT_DO_LOOP,
	STMT_RETURN
};

/*! \enum VB_Type_of_expr
    ������������ ����� ���������.
 */
enum VB_Expr_type
{
	EXPR_ID,			//!< �������������
	EXPR_CHAR_CONST,	//!< ���������� ���������
	EXPR_INT_CONST,		//!< ������������� ���������
	EXPR_STRING_CONST,	//!< ��������� ���������
	EXPR_BOOLEAN_CONST,	//!< ������� ���������
	EXPR_ASSIGN,		//!< �������� ������������
	EXPR_PLUS,			//!< �������� ��������
	EXPR_MINUS,			//!< �������� ���������
	EXPR_MUL,			//!< �������� ���������
	EXPR_DIV,			//!< �������� �������
	EXPR_POWER,			//!< �������� ���������� � �������
	EXPR_MORE,			//!< �������� "������"
	EXPR_LESS,			//!< �������� "������"
	EXPR_MORE_OR_EQUAL,	//!< �������� "������ ��� �����"
	EXPR_LESS_OR_EQUAL,	//!< �������� "������ ��� �����"
	EXPR_NONEQUAL,		//!< �������� "�������"
	EXPR_EQUAL,			//!< �������� "�����"
	EXPR_UMINUS,		//!< �������� �������� ������
	EXPR_BRK,			//!< ��������� �� ��������
	EXPR_READ,			//!< ������ ������ ������ �� �������
	EXPR_READLN,		//!< ������ ������ �� �������
	EXPR_PRINT,			//!< ����� ������ �� �������
	EXPR_PRINTLN		//!< ����� ������ �� ������� � ��������� ������
};

/*! \enum VB_Type_of_expr
    ������������ ����� �������� �������� � �������.
	���� �� ����� ������� Enum � ���������� ����������
 */
enum VB_Decl_type
{
	DECL_SUB,
	DECL_FUNC
};

/*! \struct VB_For_stmt_type
    ��� ����� For.
 */
enum VB_For_stmt_type
{
	SIMPLE,
	WITH_DECL,
	WITH_STEP,
	WITH_DECL_AND_STEP
};

/*! \struct VB_Do_loop_type
    ��� ����� Do...Loop.
 */
enum VB_Do_loop_type
{
	DO_WHILE,
	DO_UNTIL,
	LOOP_WHILE,
	LOOP_UNTIL
};

/*!
	������������� ��� ����� Do...Loop.
	\param type ��� ����� Do .. Loop
	\return ������ � �����
 */
char * VBX_do_loop_type_to_string(enum VB_Do_loop_type type)
{
	switch(type)
	{
	case (DO_WHILE):
		return "DO_WHILE";

	case (DO_UNTIL):
		return "DO_UNTIL";

	case (LOOP_WHILE):
		return "LOOP_WHILE";

	case (LOOP_UNTIL):
		return "LOOP_UNTIL";
	}

	return "";
}

/*!
	������������� ��� For � ������.
	\param type ��� ����� For.
	\return ������ � �����
 */
char * VBX_for_type_to_string(enum VB_For_stmt_type type)
{
	switch(type)
	{
	case (SIMPLE):
		return "SIMPLE";

	case (WITH_DECL):
		return "WITH_DECL";

	case (WITH_STEP):
		return "WITH_STEP";

	case (WITH_DECL_AND_STEP):
		return "WITH_DECL_AND_STEP";
	}
	
	return "";
}

/*!
	�������� ������ � ����� ���������
	\param type ��� ���������
	\return ������ � �����
 */
char* VBX_expression_type_to_string (enum VB_Expr_type type)
{
	switch(type)
	{
	case (EXPR_ASSIGN):
		return "EXPR_ASSIGN";
	case (EXPR_BOOLEAN_CONST):
		return "EXPR_BOOLEAN_CONST";
	case (EXPR_BRK):
		return "EXPR_BRK";
	case (EXPR_CHAR_CONST):
		return "EXPR_CHAR_CONST";
	case (EXPR_DIV):
		return "EXPR_DIV";
	case (EXPR_EQUAL):
		return "EXPR_EQUAL";
	case (EXPR_ID):
		return "EXPR_ID";
	case (EXPR_INT_CONST):
		return "EXPR_INT_CONST";
	case (EXPR_LESS):
		return "EXPR_LESS";
	case (EXPR_LESS_OR_EQUAL):
		return "EXPR_LESS_OR_EQUAL";
	case (EXPR_MINUS):
		return "EXPR_MINUS";
	case (EXPR_MORE):
		return "EXPR_MORE";
	case (EXPR_MORE_OR_EQUAL):
		return "EXPR_MORE_OR_EQUAL";
	case (EXPR_MUL):
		return "EXPR_MUL";
	case (EXPR_NONEQUAL):
		return "EXPR_NONEQUAL";
	case (EXPR_PLUS):
		return "EXPR_PLUS";
	case (EXPR_POWER):
		return "^";
	case (EXPR_STRING_CONST):
		return "EXPR_STRING_CONST";
	case (EXPR_UMINUS):
		return "EXPR_UMINUS";
	case (EXPR_READ):
		return "EXPR_READ";
	case (EXPR_READLN):
		return "EXPR_READLN";
	case (EXPR_PRINT):
		return "EXPR_PRINT";
	case (EXPR_PRINTLN):
		return "EXPR_PRINTLN";
	}

	return "";
}

/*!
	�������� ������ � ����� ��������������.
	\param type ��� ��������������
	\return ������ � �����
 */
char* VBX_id_type_to_string (enum VB_Id_type type)
{
	switch (type)
	{
	case (DATA_BOOLEAN):
		return "DATA_BOOLEAN";
	case (DATA_CHAR):
		return "DATA_CHAR";
	case (DATA_INTEGER):
		return "DATA_INTEGER";
	case (DATA_STRING):
		return "DATA_STRING";
	}

	return "";
}

/*!
	\brief ������� ����������� ��� Stmt � ������.
	\param type - ��� Stmt.
	\return ������ - ��� Stmt.
*/
char* statement_type_to_string (enum VB_Stmt_type type)
{
	switch (type)
	{
	case (STMT_ENDL):
		return "STMT_ENDL";
	case (STMT_EXPR):
		return "STMT_EXPR";
	case (STMT_IF):
		return "STMT_IF";
	case (STMT_DIM):
		return "STMT_DIM";
	case (STMT_FOR):
		return "STMT_FOR";
	case (STMT_WHILE):
		return "STMT_WHILE";
	case (STMT_DO_LOOP):
		return "STMT_DO_LOOP";
	case (STMT_RETURN):
		return "STMT_RETURN";
	}

	return "";
}

/*!
	�������������� ���� ���������� � ������
	\param type ��� ����������
	\return ������ � �����
 */
char * VBX_decl_type_to_string(enum VB_Decl_type type)
{
	switch(type)
	{
	case DECL_SUB:
		return "DECL_SUB";

	case DECL_FUNC:
		return "DECL_FUNC";
	}

	return "";
}

/*!
	������������� ���������� �������� � ������
	\param val ��������
	\return ������ � ���������� ���������
 */
char * get_boolean_string(int val)
{
	if (val == 0)
		return "false";
	else
		return "true";
}

#endif // H_DATA_TYPES