//
//
#ifndef H_PRT_EXPR
#define H_PRT_EXPR

char* expression_type_to_string (enum VB_Expr_type type);

/*! \struct VB_Expr
    ��������� ������ ��� �������� ���������.
 */
struct VB_Expr
{
	enum VB_Expr_type	 type;			//!< ��� ���������.
	char*				 expr_string;	//!< ��� ��������������, ���� ������.
	int					 int_val;		//!< �������� ���������. ������������ ��� bool, int, char.
	struct VB_Expr*		 left_chld;		//!< ��������� �� ������ ����.
	struct VB_Expr*		 right_chld;		//!< ��������� �� ������� ����.
	struct VB_Expr_list* list;			//!< ��������� ��������� ��� �������
	struct VB_Expr*      next;           //!< ��������� �� ����������, ��� Expr_list.

	enum VB_Id_type		id_type;		//!< ��� �������������� 	????

	// ���� ��� ���������	
	char* string_val;			//!< �������� ��������� ���������� 
	int   line_number; //!< Line of this expression.
};

/*!
	������� �������� Console.Write()
  \param text ����� � �������.
  \return ���� ������ - ����� � ����������� �����.
*/
struct VB_Expr* create_Print (struct VB_Expr* expr)
{
	struct VB_Expr* print = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));
	print->expr_string = (char*)malloc(sizeof(char)*6);
	print->expr_string = "PRINT";

	print->id_type = DATA_INTEGER;
	print->int_val = 0;
	print->left_chld = expr;
	print->list = NULL;
	print->next = NULL;
	print->right_chld = NULL;
	print->type = EXPR_PRINT;
	print->line_number = get_location();

	return print;
}

/*!
	������� �������� Console.WriteLine()
  \param text ����� � �������.
  \return ���� ������ - ����� � ����������� ����� � ��������� ������.
*/
struct VB_Expr* create_Println (struct VB_Expr* expr)
{
	struct VB_Expr* println = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));
	println->expr_string = (char*)malloc(sizeof(char)*10);
	println->expr_string = "PRINTLINE";

	println->id_type = DATA_INTEGER;
	println->int_val = 0;
	println->left_chld = expr;
	println->list = NULL;
	println->next = NULL;
	println->right_chld = NULL;
	println->type = EXPR_PRINTLN;
	println->line_number = get_location();

	return println;
}

/*!
	������� �������� Console.Read().
  \return ���� ������ - ���������� ������� � ������������ ������.
*/
struct VB_Expr* create_Read ()
{
	struct VB_Expr* read = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));
	read->expr_string = (char*)malloc(sizeof(char)*5);
	read->expr_string = "READ";

	read->id_type = DATA_INTEGER;
	read->int_val = 0;
	read->left_chld = NULL;
	read->list = NULL;
	read->next = NULL;
	read->right_chld = NULL;
	read->type = EXPR_READ;

	//struct VB_Read_stmt* read = NULL;

	//read = (struct VB_Read_stmt*)malloc(sizeof(struct VB_Read_stmt));
	read->line_number = get_location();

	return read;
}

/*!
	������� �������� Console.ReadLine().
  \return ���� ������ - ���������� ������ � ������������ ������.
*/
struct VB_Expr* create_Readln ()
{
	struct VB_Expr* readln = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));
	readln->expr_string = (char*)malloc(sizeof(char)*9);
	readln->expr_string = "READLINE";

	readln->id_type = DATA_INTEGER;
	readln->int_val = 0;
	readln->left_chld = NULL;
	readln->list = NULL;
	readln->next = NULL;
	readln->right_chld = NULL;
	readln->type = EXPR_READLN;
	
	//struct VB_Readln_stmt* readln = NULL;

	//readln = (struct VB_Readln_stmt*)malloc(sizeof(struct VB_Readln_stmt));

	readln->line_number = get_location();

	return readln;
}

/*!
	������� �������� ��������� ��������������.
  \param name ��� ��������������.
  \return ��������� �� ������ ���������.
*/
struct VB_Expr* create_id_expr(char* name)
{
	struct VB_Expr* result = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));
	printf("Create ID %s\n", name);

	result->type = EXPR_ID;
	result->expr_string = name;
	result->left_chld = NULL;
	result->list = NULL;
	result->next = NULL;
	result->right_chld = NULL;
	result->id_type = DATA_INTEGER;
	result->int_val = 0;
	result->string_val = "";
	result->line_number = get_location();

	return result;
}

/*!
	������� �������� ��������� �� ��������.
*/
struct VB_Expr* create_brackets_actions(char* name, struct VB_Expr_list* params)
{
	struct VB_Expr* result = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));

	result->type = EXPR_BRK;
	result->expr_string = name;
	result->list = params;
	result->left_chld = NULL;
	result->next = NULL;
	result->right_chld = NULL;
	result->int_val = 0;
	result->id_type = DATA_INTEGER;
	result->line_number = get_location();

	return result;
}

/*!
	������� �������� ��������� ��������� (int, boolean, char).
  \param type ��� ��������������.
  \param name ��� ��������������.
  \return ��������� �� ������ ���������.
*/
struct VB_Expr* create_int_boolean_char_const_expr(enum VB_Expr_type type, int value)
{
	struct VB_Expr* result = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));
	printf("Create Expr %d", value);

	result->id_type = DATA_INTEGER;

	if (type == EXPR_BOOLEAN_CONST) {
		if (value == 1)			
			result->expr_string = "true";
		else
			result->expr_string = "false";

		result->id_type = DATA_BOOLEAN;
	}
	//else if (type == EXPR_CHAR_CONST){
	//	result->expr_string = (char*)malloc(sizeof(char)*2);
	//	result->expr_string[0] = (char)value;

	//	result->id_type = DATA_CHAR;
	//}
	else
		result->expr_string = "";


	result->type = type;
	result->int_val = value;
	
	result->left_chld = NULL;
	result->list = NULL;
	result->next = NULL;
	result->right_chld = NULL;
	result->line_number = get_location();

	return result;
}

/*!
	������� �������� ��������� ��������� ���������.
  \param string ������.
  \return ��������� �� ������ ���������.
*/
struct VB_Expr* create_string_const_expr(char* string)
{
	struct VB_Expr* result = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));

	result->type = EXPR_STRING_CONST;
	result->expr_string = (char*)malloc(sizeof(char)*strlen(string));
	strcpy(result->expr_string,string);
	result->left_chld = NULL;
	result->list = NULL;
	result->next = NULL;
	result->right_chld = NULL;
	result->id_type = DATA_STRING;
	result->int_val = 0;
	result->line_number = get_location();

	return result;
}

/*!
 * ������� ���������� ������������
 */
void solve_assign(struct VB_Expr* result, struct VB_Expr* left, struct VB_Expr* right){
	
	printf("\n = \n");

	// �������� ����, ���� ���-�� �� ����� ���������� ���� � ���� �� �����, �� ������
	//if ((left->id_type == DATA_STRING || right->id_type == DATA_STRING) && left->id_type != right->id_type)
	//	yyerror("\nIncorrect types!");

	// ���� ������ ����� - ������������� ���������� ����
	if (left->id_type == DATA_STRING){

		if (right->type == EXPR_STRING_CONST){
			strcpy(left->string_val, right->expr_string);
			strcpy(result->expr_string, right->expr_string);
		}
		else if (right->type == EXPR_ID || right->type == EXPR_BRK){
			strcpy(left->string_val, right->string_val);
			strcpy(result->expr_string, right->string_val);
		}
	}
	else if (left->id_type == DATA_BOOLEAN && right->int_val != 0)
		left->int_val = 1;
	
	else {
		left->int_val = right->int_val;
		result->int_val = right->int_val;
	}
	
	result->id_type = left->id_type;
}

/*!
 * ������� ����������� ����, ���� ����� ���������� ��������� ���������� � ������ �� �����
 */
char * get_string_pointer(struct VB_Expr* expr){
	char * buf;

	if (expr->type == EXPR_ID)
		buf = expr->string_val;
	else
		buf = expr->expr_string;

	return buf;
}

/*!
 * ������� ������������� ��������
 */
void solve_plus(struct VB_Expr* result, struct VB_Expr* left, struct VB_Expr* right){
	
	char * buf1, *buf2;

	printf("\n + \n");

	// �������� ����, ���� ���-�� �� ����� ���������� ���� � ���� �� �����, �� ������
	if ((left->id_type == DATA_STRING || right->id_type == DATA_STRING) && left->id_type != right->id_type)
		yyerror("\nIncorrect types!");

	// ���� ��� ���������, �� ���������� ������
	if (left->id_type == DATA_STRING){
		buf1 = get_string_pointer(left);

		buf2 = get_string_pointer(right);
		
		result->expr_string = (char*)malloc(sizeof(char) * (strlen(buf1) + strlen(buf2)) + 1);
		strcpy(result->expr_string,buf1);
		strcat(result->expr_string,buf2);
	}

	// ����� ���������� �����
	else if (left->id_type == DATA_BOOLEAN)
		left->int_val = left->int_val || right->int_val;
	else
		result->int_val = left->int_val + right->int_val;

	result->id_type = left->id_type;
}

/*!
 * ������� ������������� ���������
 */
void solve_minus(struct VB_Expr* result, struct VB_Expr* left, struct VB_Expr* right){
	
	printf("\n - \n");

	// ������ �������� ������ � �� ����������� ���� �������� ������
	if (left->id_type == DATA_STRING || right->id_type == DATA_STRING || left->id_type == DATA_BOOLEAN)
		yyerror("\nIncorrect types!");

	else{
		result->int_val = left->int_val - right->int_val;

		result->id_type = left->id_type;
	}
}


/*!
 * ������� ������������� ���������
 */
void solve_mul(struct VB_Expr* result, struct VB_Expr* left, struct VB_Expr* right){
	
	printf("\n * \n");

	// ������ �������� ������ � �� ����������� ���� �������� ������
	if (left->id_type == DATA_STRING || right->id_type == DATA_STRING)
		yyerror("\nIncorrect types!");

	// ����� ���������� �����
	else if (left->id_type == DATA_BOOLEAN)
		left->int_val = left->int_val && right->int_val;

	else{
		result->int_val = left->int_val * right->int_val;
	}
		
	result->id_type = left->id_type;
}

/*!
 * ������� ������������� �������
 */
void solve_div(struct VB_Expr* result, struct VB_Expr* left, struct VB_Expr* right){
	
	printf("\n / \n");

	// ������ ������ ������ � ���������� ���
	if (left->id_type == DATA_STRING || right->id_type == DATA_STRING || left->id_type == DATA_BOOLEAN)
		yyerror("\nIncorrect types!");

	// ���� ������� �� 0
	if (right->int_val == 0)
		yyerror("\nDivision by zero!");

	result->int_val = left->int_val / right->int_val;

	result->id_type = left->id_type;
}

/*!
 * ������� ������������� ���������� � �������
 */
void solve_pow(struct VB_Expr* result, struct VB_Expr* left, struct VB_Expr* right){
	
	printf("\n ^ \n");

	// ������ ��������� � ������� ������
	if (left->id_type == DATA_STRING || right->id_type == DATA_STRING)
		yyerror("\nIncorrect types!");

	result->int_val = (int)pow((float)left->int_val,right->int_val);

	result->id_type = left->id_type;
}

/*!
 * ������� ������������� �������� "������"
 */
void solve_more(struct VB_Expr* result, struct VB_Expr* left, struct VB_Expr* right){
	
	char* buf1, *buf2;

	printf("\n > \n");

	// �������� ����, ���� ���-�� �� ����� ���������� ���� � ���� �� �����, �� ������
	if ((left->id_type == DATA_STRING || right->id_type == DATA_STRING) && left->id_type != right->id_type)
		yyerror("\nIncorrect types!");

	// ������ ������ ��������� � �������
	if (left->id_type == DATA_STRING){
		buf1 = get_string_pointer(left);

		buf2 = get_string_pointer(right);

		result->int_val = strlen(buf1) > strlen(buf2);
	}
	else
		result->int_val = left->int_val > right->int_val;
	
	result->id_type = DATA_BOOLEAN;
	result->expr_string = get_boolean_string(result->int_val);
}

/*!
 * ������� ������������� �������� "������"
 */
void solve_less(struct VB_Expr* result, struct VB_Expr* left, struct VB_Expr* right){
	
	char* buf1, *buf2;

	printf("\n < \n");

	// �������� ����, ���� ���-�� �� ����� ���������� ���� � ���� �� �����, �� ������
	if ((left->id_type == DATA_STRING || right->id_type == DATA_STRING) && left->id_type != right->id_type)
		yyerror("\nIncorrect types!");

	// ������ ������ ��������� � �������
	if (left->id_type == DATA_STRING){
		buf1 = get_string_pointer(left);

		buf2 = get_string_pointer(right);

		result->int_val = strlen(buf1) < strlen(buf2);
	}
	else	
		result->int_val = left->int_val < right->int_val;

	result->id_type = DATA_BOOLEAN;
	result->expr_string = get_boolean_string(result->int_val);
}

/*!
 * ������� ������������� �������� "������ ��� �����""
 */
void solve_more_or_equal(struct VB_Expr* result, struct VB_Expr* left, struct VB_Expr* right){
	char* buf1, *buf2;

	printf("\n >= \n");

	// �������� ����, ���� ���-�� �� ����� ���������� ���� � ���� �� �����, �� ������
	if ((left->id_type == DATA_STRING || right->id_type == DATA_STRING) && left->id_type != right->id_type)
		yyerror("\nIncorrect types!");

	// ������ ������ ��������� � �������
	if (left->id_type == DATA_STRING){
		buf1 = get_string_pointer(left);

		buf2 = get_string_pointer(right);

		result->int_val = strlen(buf1) >= strlen(buf2);
	}
	else
		result->int_val = left->int_val >= right->int_val;

	result->id_type = DATA_BOOLEAN;
	result->expr_string = get_boolean_string(result->int_val);
}

/*!
 * ������� ������������� �������� "������ ��� �����"
 */
void solve_less_or_equal(struct VB_Expr* result, struct VB_Expr* left, struct VB_Expr* right){
	char* buf1, *buf2;

	printf("\n >= \n");

	// �������� ����, ���� ���-�� �� ����� ���������� ���� � ���� �� �����, �� ������
	if ((left->id_type == DATA_STRING || right->id_type == DATA_STRING) && left->id_type != right->id_type)
		yyerror("\nIncorrect types!");

	// ������ ������ ��������� � �������
	if (left->id_type == DATA_STRING){
		buf1 = get_string_pointer(left);

		buf2 = get_string_pointer(right);

		result->int_val = strlen(buf1) >= strlen(buf2);
	}
	else	
		result->int_val = left->int_val >= right->int_val;

	result->id_type = DATA_BOOLEAN;
	result->expr_string = get_boolean_string(result->int_val);
}

/*!
 * ������� ������������� �������� "�������"
 */
void solve_nonqeual(struct VB_Expr* result, struct VB_Expr* left, struct VB_Expr* right){
	char* buf1, *buf2;

	printf("\n <> \n");

	// �������� ����, ���� ���-�� �� ����� ���������� ���� � ���� �� �����, �� ������
	if ((left->id_type == DATA_STRING || right->id_type == DATA_STRING) && left->id_type != right->id_type)
		yyerror("\nIncorrect types!");

	// ������ ������ ��������� � �������
	if (left->id_type == DATA_STRING){
		buf1 = get_string_pointer(left);

		buf2 = get_string_pointer(right);

		result->int_val = strlen(buf1) != strlen(buf2);
	}
	else
		result->int_val = left->int_val != right->int_val;

	result->id_type = DATA_BOOLEAN;
	result->expr_string = get_boolean_string(result->int_val);
}

/*!
 * ������� ������������� �������� "������� �����"
 */
void solve_uminus(struct VB_Expr* result, struct VB_Expr* left){
	char* buf1, *buf2;

	printf("\n U- \n");

	// ������ ������ �������� ����
	if (left->id_type == DATA_STRING)
		yyerror("\nIncorrect type!");
	
	left->int_val = -left->int_val;
	result->int_val = -left->int_val;
	result->id_type = left->id_type;
}

/*!
	������� �������� ��������� ��������.
  \param type ��� ��������.
  \param left ����� �������.
  \param right ������ �������.
  \return ��������� �� ������ ���������.
*/
struct VB_Expr* create_operator_expr(enum VB_Expr_type type,
									 struct VB_Expr* left,
									 struct VB_Expr* right)
{
	struct VB_Expr* result = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));

	result->expr_string = expression_type_to_string(type);

	result->type = type;
	result->left_chld = left;
	result->right_chld = right;
	result->list = NULL;
	result->next = NULL;
	result->id_type = DATA_INTEGER;
	result->int_val = 0;

	if (type == EXPR_ASSIGN)
		solve_assign(result,left,right);

	else if (type == EXPR_PLUS)
		solve_plus(result,left,right);

	else if (type == EXPR_MINUS)
		solve_minus(result,left,right);

	else if (type == EXPR_MUL)
		solve_mul(result,left,right);

	else if (type == EXPR_DIV)
		solve_div(result,left,right);

	else if (type == EXPR_POWER)
		solve_pow(result,left,right);

	else if (type == EXPR_MORE)
		solve_more(result,left,right);

	else if (type == EXPR_LESS)
		solve_less(result,left,right);

	else if (type == EXPR_MORE_OR_EQUAL)
		solve_more_or_equal(result,left,right);

	else if (type == EXPR_LESS_OR_EQUAL)
		solve_less_or_equal(result,left,right);

	else if (type == EXPR_NONEQUAL)
		solve_nonqeual(result,left,right);

	else if (type == EXPR_UMINUS)
		solve_uminus(result,left);

	result->line_number = get_location();


	return result;
}

/*!
 * ������� ������ Expr, ���� ��� ���
 */
struct VB_Expr * create_expr_with_id(char* id) 
{
	struct VB_Expr * result = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));

	// �������� ���
	result->expr_string = (char*)malloc(sizeof(char)*strlen(id));
	strcpy(result->expr_string,id);

	// ���� �� ���������
	result->type = EXPR_ID;
	result->int_val = 0;
	result->left_chld = NULL;
	result->list = NULL;
	result->next = NULL;
	result->right_chld = NULL;
	result->id_type = DATA_INTEGER;
	result->string_val = "";
	result->line_number = get_location();

	return result;
}

#endif // H_PRT_EXPR