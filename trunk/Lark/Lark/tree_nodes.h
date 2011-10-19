//
//

/*! \enum VB_Type_of_expr
    Перечисление типов выражения. 
 */
enum VB_Expr_type
{
	ID,							//!< Идентификатор

	CHAR_CONST,					//!< Символьная константа
	INT_CONST,					//!< Целочисленная константа
	STRING_CONST,				//!< Строковая константа
	BOOLEAN_CONST,				//!< Булевая константа

	ASSIGN_OPERATOR,			//!< Оператор присваивания
	PLUS_OPERATOR,				//!< Оператор сложения
	MINUS_OPERATOR,				//!< Оператор вычитания
	MUL_OPERATOR,				//!< Оператор умножения
	INT_DIV_OPERATOR,			//!< Оператор целочисленного деления
	DIV_OPERATOR,				//!< Оператор деления
	POWER_OPERATOR,				//!< Оператор возведения в степень

	MORE_OPERATOR,				//!< Оператор "больше"
	LESS_OPERATOR,				//!< Оператор "меньше"
	MORE_OR_EQUAL_OPERATOR,		//!< Оператор "больше или равно"
	LESS_OR_EQUAL_OPERATOR,		//!< Оператор "меньше или равно"
	ASSIGN_NONEQUAL_OPERATOR,	//!< Оператор "неравно"

	ASSIGN_PLUS_OPERATOR,		//!< Оператор сложения и присваивания
	ASSIGN_MINUS_OPERATOR,		//!< Оператор вычитания и присваивания
	ASSIGN_MUL_OPERATOR,		//!< Оператор умножения и присваивания
	ASSIGN_DIV_OPERATOR,		//!< Оператор деления и присваивания
	ASSIGN_INT_DIV_OPERATOR,	//!< Оператор целочисленного деления и присваивания

	UMINUS_OPERATOR				//!< Оператор унарного минуса
};


/*! \enum VB_Type_of_expr
    Перечисление типов операций. 
 */
enum VB_Stmt_type
{
	EXPR,						//!< Выражение
	IF_STMT						//!< Операция условного перехода
};


/*! \struct VB_Expr
    Структура дерева для хранения выражения.
 */
struct VB_Expr
{
	enum VB_Expr_type type;			//!< Тип выражения.
	char* expr_string;				//!< Имя идентификатора, либо строка.
	int int_val;					//!< Значение выражения. Используется для bool, int, char.
	struct VB_Expr* left_chld;		//!< Указатель на левого сына.
	struct VB_Expr* right_chld;		//!< Указатель на правого сына.
};


/*! \struct VB_Stmt_list
    Структура, описывающая список операций.
 */
struct VB_Stmt_list
{
	struct VB_Stmt* first;			//!< Указатель на первый элемент списка
	struct VB_Stmt* last;			//!< Указатель на последний элемент списка
};


/*! \struct VB_Stmt
    Структура, описывающая операцию.
 */
struct VB_Stmt
{
	enum VB_Stmt_type type;			//!< Тип операции.
	struct VB_Expr* expr;			//!< Указатель на содержащееся в операции выражение.
	struct VB_Stmt_list* stmt_list;	//!< Указатель на список операций включающихся в данную операцию.
	struct VB_Stmt* next;			//!< Указатель на следующий элемент последовательности операторов.
};