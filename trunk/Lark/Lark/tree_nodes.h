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


/*! \enum VB_If_stmt_type
    ������������ ����� ��������� ��������. 
 */
enum VB_If_stmt_type
{
	IF_THEN,
	IF_ENDL,
	IF_INLINE,
	IF_ELSE_INLINE
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
	enum VB_Stmt_type	type;	//!< ��� ��������.
	struct VB_Expr*		expr;	//!< ��������� �� ������������ � �������� ���������.
	struct VB_Stmt*		next;	//!< ��������� �� ��������� ������� ������������������ ����������.
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
	struct VB_Expr_list* list;			//!< �������� �� ������ ���������
};


/*! \struct VB_Expr_list
    ���������, ����������� ������ ���������.
 */
struct VB_Expr_list
{
	struct VB_Expr* first;  //!< ��������� �� ������ ������� ������
	struct VB_Expr* last;   //!< ��������� �� ��������� ������� ������
};


/*! \struct VB_If_stmt
    ��������� ������ ��� �������� ��������� ��������� ��������.
 */
struct VB_If_stmt
{
	enum   VB_If_stmt_type  type;		//!< ��� ��������� ���������
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
	struct VB_As_Expr_list* first;		//!< ��������� �� ������ ������� ������ ����������� ����������
	struct VB_As_Expr_list* last;		//!< ��������� �� ��������� ������� ������ ����������� ����������
};


/*! \enum VB_As_Stmt_list
    ������������, ���������� ��� ������ ������������������ ����������� ����������
 */
enum VB_As_Expr_list_type
{
	EXPR,		// ������������ �������������
	ARRAY,		// ������������ ������
	EXPR_LIST,	// ������������ ������ ���������������
	EXPR_ARR	// ������������ ������ ��������
};


/*! \struct VB_As_Stmt_list
    ���������, ����������� ������� ������ ����������, ����������� ����� �����
 */
struct VB_As_Expr_list
{
	enum   VB_As_Expr_list_type type;		//!< ���
	struct VB_As_expr*			as_expr;	//!< �������������
	struct VB_As_Expr_list*		next;		//!< ������ ��������������� ��� ��������
	struct VB_Array_expr*		arr;		//!< ������
};


enum VB_As_expr_type
{
	ID_LIST,	// ������ ���������������
	ONE_ID,		// ���� ������������
	ID_INIT		// ������������������ �������������
};


/*! \struct VB_As_stmt
    ��������� ������ ��� �������� ����������� ���������� ������ ����.
 */
struct VB_As_expr
{ 
	enum	VB_As_expr_type	type;		// ��� 
	struct	VB_Id_list*		list;		// ������ ���������������
	enum	VB_Id_type		id_type;	// ��� ������������� �������������� ��� ������
	struct	VB_Expr*		expr;		// ���������������� ��������
};

/*! \struct VB_Id_list
    ������ ���������������.
 */
struct VB_Id_list
{
	char* id;
	struct VB_Id_list* next;
};
