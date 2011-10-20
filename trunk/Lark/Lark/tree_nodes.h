//
//

/*! \enum VB_Type_of_expr
    ������������ ����� ���������. 
 */
enum VB_Expr_type
{
	ID,							//!< �������������

	CHAR_CONST,					//!< ���������� ���������
	INT_CONST,					//!< ������������� ���������
	STRING_CONST,				//!< ��������� ���������
	BOOLEAN_CONST,				//!< ������� ���������

	ASSIGN_OPERATOR,			//!< �������� ������������
	PLUS_OPERATOR,				//!< �������� ��������
	MINUS_OPERATOR,				//!< �������� ���������
	MUL_OPERATOR,				//!< �������� ���������
	INT_DIV_OPERATOR,			//!< �������� �������������� �������
	DIV_OPERATOR,				//!< �������� �������
	POWER_OPERATOR,				//!< �������� ���������� � �������

	MORE_OPERATOR,				//!< �������� "������"
	LESS_OPERATOR,				//!< �������� "������"
	MORE_OR_EQUAL_OPERATOR,		//!< �������� "������ ��� �����"
	LESS_OR_EQUAL_OPERATOR,		//!< �������� "������ ��� �����"
	ASSIGN_NONEQUAL_OPERATOR,	//!< �������� "�������"

	ASSIGN_PLUS_OPERATOR,		//!< �������� �������� � ������������
	ASSIGN_MINUS_OPERATOR,		//!< �������� ��������� � ������������
	ASSIGN_MUL_OPERATOR,		//!< �������� ��������� � ������������
	ASSIGN_DIV_OPERATOR,		//!< �������� ������� � ������������
	ASSIGN_INT_DIV_OPERATOR,	//!< �������� �������������� ������� � ������������

	UMINUS_OPERATOR				//!< �������� �������� ������
};


/*! \enum VB_Type_of_expr
    ������������ ����� ��������. 
 */
enum VB_Stmt_type
{
	EXPR,						//!< ���������
	IF_STMT,					//!< �������� ��������� ��������
	DIM_STMT					//!< �������� ����������� ����������
};


/*! \enum VB_End_if_stmt_type
    ������������ ����� ��������� �������� ��������� ��������. 
 */
enum VB_End_if_stmt_type
{
	ENDIF,						//!< �������� �����������
	ELSE,						//!< ���� �������������� ��������
	ELSE_IF_THEN,				//!< ���� �������������� �������� � �������� � �� ����� ������� ����� "Then"
	ELSE_IF_ENDL				//!< ���� �������������� �������� � �������� � �� ����� ������� ����� ENDL
};


/*! \enum VB_Id_type
    ������������ ����� ���������������. 
 */
enum VB_Id_type
{
	INTEGER,
	BOOLEAN,
	CHAR,
	STRING
};


/*! \struct VB_Stmt_module
    ��������� ������ ��� �������� ����� ������.
 */
struct VB_Stmt_module
{
	struct VB_Stmt_list* stmt_list; //!< ������ ��������
};


/*! \struct VB_Stmt_list
    ���������, ����������� ������ ��������.
 */
struct VB_Stmt_list
{
	struct VB_Stmt* first;			//!< ��������� �� ������ ������� ������
	struct VB_Stmt* last;			//!< ��������� �� ��������� ������� ������
};


/*! \struct VB_Stmt
    ���������, ����������� ��������.
 */
struct VB_Stmt
{
	enum VB_Stmt_type		type;			//!< ��� ��������.
	struct VB_Expr*			expr;			//!< ��������� �� ������������ � �������� ���������.
	struct VB_Stmt_list*	stmt_list;		//!< ��������� �� ������ �������� ������������ � ������ ��������.
	struct VB_Stmt*			next;			//!< ��������� �� ��������� ������� ������������������ ����������.
};


/*! \struct VB_Expr
    ��������� ������ ��� �������� ���������.
 */
struct VB_Expr
{
	enum VB_Expr_type	type;			//!< ��� ���������.
	char*				expr_string;	//!< ��� ��������������, ���� ������.
	int					int_val;		//!< �������� ���������. ������������ ��� bool, int, char.
	struct VB_Expr*		left_chld;		//!< ��������� �� ������ ����.
	struct VB_Expr*		right_chld;		//!< ��������� �� ������� ����.
};


/*! \struct VB_If_stmt
    ��������� ������ ��� �������� ��������� ��������� ��������.
 */
struct VB_If_stmt
{
	bool					hasThen;	//!< ���� �� "Then" ��� ����� ������� ���� ����� ������
	struct VB_Expr*			expr;		//!< �������
	struct VB_Stmt_list*	stmt_list;	//!< ��������� �� ������ �������� ��� �������� �������.
	struct VB_End_if_stmt*	end_stmt;	//!< ��������� �� ������ �������� ��� ������ ������� �������.
	struct VB_Stmt*			next;		//!< ��������� �� ��������� ������� ������������������ ����������.

};

/*! \struct VB_End_if_stmt
    ��������� ������ ��� �������� �������� ��� ������ �������
	��������� ��������� ��������.
 */
struct VB_End_if_stmt
{
	enum VB_End_if_stmt_type	type;		//!< ��� ��������� �������
	struct VB_Expr*				expr;		//!< �������������� �������, ���� ����
	struct VB_Stmt_list*		stmt_list;	//!< ��������� �� ������ �������� ��� �������� �������������� �������.
	struct VB_End_if_stmt*		end_stmt;	//!< ��������� �� ������ �������� ��� ������ �������������� ������� �������.
};


/*! \struct VB_Dim_stmt
    ���������, ����������� �������� ���������� ����������.
 */
struct VB_Dim_stmt
{
	struct VB_As_Stmt_list* first;		//!< ��������� �� ������ ������� ������ ����������� ����������
	struct VB_As_Stmt_list* last;		//!< ��������� �� ��������� ������� ������ ����������� ����������
};


/*! \struct VB_As_Stmt_list
    ���������, ����������� ������� ������ ����������, ����������� ����� �����
 */
struct VB_As_Stmt_list
{
	struct VB_As_stmt*		as_stmt;	//!< ������ ����������, ������������ ����� �����
	struct VB_As_Stmt_list* next;		//!< ��������� �� ��������� ������ ���������� ������������ ����� �����
};


/*! \struct VB_As_stmt
    ��������� ������ ��� �������� ����������� ���������� ������ ����.
 */
struct VB_As_stmt
{ 
	bool					isInit;		//!< ���������������� �� ����������
	struct VB_Id_list*		idents;		//!< ��������� �� ���������������
	struct VB_Expr*			expr;		//!< ���������, ������� ���������� ����������������
};


/*! \struct VB_Id_list
    ��������� ������ ��� �������� ������ ���������������.
 */
struct VB_Id_list
{
	struct VB_Id*		current_id;		//!< ������� �������������
	struct VB_Id_list*	next;			//!< ��������� �������������
};


/*! \struct VB_Id
    ��������� ������ ��� �������� ��������������.
 */
struct VB_Id
{
	enum VB_Id_type	type;			//!< ���, ������������ ����������
	char*			name;			//!< ��� ��������������.
	char*			str_val;		//!< ��������� �������� ����������
	int				int_val;		//!< �������� ���������. ������������ ��� bool, int, char.
};

