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

	UMINUS_OPERATOR				//!< Оператор унарного минуса
};


/*! \enum VB_Type_of_expr
    Перечисление типов операций. 
 */
enum VB_Stmt_type
{
	EXPR,						//!< Выражение
	IF_STMT,					//!< Операция условного перехода
	DIM_STMT					//!< Операция определения переменной
};


/*! \enum VB_If_stmt_type
    Перечисление типов условного перехода. 
 */
enum VB_If_stmt_type
{
	IF_THEN,
	IF_ENDL,
	IF_INLINE,
	IF_ELSE_INLINE
};


/*! \enum VB_End_if_stmt_type
    Перечисление типов окончания операции условного перехода. 
 */
enum VB_End_if_stmt_type
{
	ENDIF,						//!< Операция завершилась
	ELSE,						//!< Есть альтернативное действие
	ELSE_IF_THEN,				//!< Есть альтернативное действие с условием и на конце условия стоит "Then"
	ELSE_IF_ENDL				//!< Есть альтернативное действие с условием и на конце условия стоит ENDL
};


/*! \enum VB_Id_type
    Перечисление типов идентификаторов. 
 */
enum VB_Id_type
{
	INTEGER,
	BOOLEAN,
	CHAR,
	STRING
};


/*! \struct VB_Stmt_module
    Структура дерева для хранения корня дерева.
 */
struct VB_Stmt_module
{
	struct VB_Stmt_list* stmt_list; //!< Список операций
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
	enum VB_Stmt_type	type;	//!< Тип операции.
	struct VB_Expr*		expr;	//!< Указатель на содержащееся в операции выражение.
	struct VB_Stmt*		next;	//!< Указатель на следующий элемент последовательности операторов.
};


/*! \struct VB_Expr
    Структура дерева для хранения выражения.
 */
struct VB_Expr
{
	enum VB_Expr_type	type;			//!< Тип выражения.
	char*				expr_string;	//!< Имя идентификатора, либо строка.
	int					int_val;		//!< Значение выражения. Используется для bool, int, char.
	struct VB_Expr*		left_chld;		//!< Указатель на левого сына.
	struct VB_Expr*		right_chld;		//!< Указатель на правого сына.
	struct VB_Expr_list* list;			//!< Указаель на список выражений
};


/*! \struct VB_Expr_list
    Структура, описывающая список выражений.
 */
struct VB_Expr_list
{
	struct VB_Expr* first;  //!< Указатель на первый элемент списка
	struct VB_Expr* last;   //!< Указатель на последний элемент списка
};


/*! \struct VB_If_stmt
    Структура дерева для хранения оператора условного перехода.
 */
struct VB_If_stmt
{
	enum   VB_If_stmt_type  type;		//!< Тип условного оператора
	struct VB_Expr*			expr;		//!< Условие
	struct VB_Stmt_list*	stmt_list;	//!< Указатель на список операций при истинном условии.
	struct VB_End_if_stmt*	end_stmt;	//!< Указатель на список операций при ложном условии условии.
	struct VB_Stmt*			next;		//!< Указатель на следующий элемент последовательности операторов.
};


/*! \struct VB_End_if_stmt
    Структура дерева для хранения действий при ложном условии
	оператора условного перехода.
 */
struct VB_End_if_stmt
{
	enum VB_End_if_stmt_type	type;		//!< Тип окончания условия
	struct VB_Expr*				expr;		//!< Дополнительное условие, если есть
	struct VB_Stmt_list*		stmt_list;	//!< Указатель на список операций при истинном дополнительном условии.
	struct VB_End_if_stmt*		end_stmt;	//!< Указатель на список операций при ложном дополнительном условии условии.
};


/*! \struct VB_Dim_stmt
    Структура, описывающая операцию объявления переменных.
 */
struct VB_Dim_stmt
{
	struct VB_As_Expr_list* first;		//!< Указатель на первый элемент списка объявляемых переменных
	struct VB_As_Expr_list* last;		//!< Указатель на последний элемент списка объявляемых переменных
};


/*! \enum VB_As_Stmt_list
    Перечисление, описывющее тип списка последовательности определения переменных
 */
enum VB_As_Expr_list_type
{
	EXPR,		// Определяется идентификатор
	ARRAY,		// Определяется массив
	EXPR_LIST,	// Определяется список идентификаторов
	EXPR_ARR	// Определяется список массивов
};


/*! \struct VB_As_Stmt_list
    Структура, описывающая связный список переменных, объявляемых одним типом
 */
struct VB_As_Expr_list
{
	enum   VB_As_Expr_list_type type;		//!< Тип
	struct VB_As_expr*			as_expr;	//!< Идентификатор
	struct VB_As_Expr_list*		next;		//!< Список идентификаторов или массивов
	struct VB_Array_expr*		arr;		//!< Массив
};


enum VB_As_expr_type
{
	ID_LIST,	// Список идентификаторов
	ONE_ID,		// Один идентификаор
	ID_INIT		// Инициализированный идентификатор
};


/*! \struct VB_As_stmt
    Структура дерева для хранения определения переменных одного типа.
 */
struct VB_As_expr
{ 
	enum	VB_As_expr_type	type;		// Тип 
	struct	VB_Id_list*		list;		// Список идентификаторов
	enum	VB_Id_type		id_type;	// Тип определяемого идентификатора или масива
	struct	VB_Expr*		expr;		// Инициализируемое значение
};

/*! \struct VB_Id_list
    Список идентификаторов.
 */
struct VB_Id_list
{
	char* id;
	struct VB_Id_list* next;
};
