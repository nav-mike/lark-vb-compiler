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
	IF_STMT,					//!< Операция условного перехода
	DIM_STMT					//!< Операция определения переменной
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
	enum VB_Stmt_type		type;			//!< Тип операции.
	struct VB_Expr*			expr;			//!< Указатель на содержащееся в операции выражение.
	struct VB_Stmt_list*	stmt_list;		//!< Указатель на список операций включающихся в данную операцию.
	struct VB_Stmt*			next;			//!< Указатель на следующий элемент последовательности операторов.
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
};


/*! \struct VB_If_stmt
    Структура дерева для хранения оператора условного перехода.
 */
struct VB_If_stmt
{
	bool					hasThen;	//!< Есть ли "Then" или после условия идет конец строки
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
	struct VB_As_Stmt_list* first;		//!< Указатель на первый элемент списка объявляемых переменных
	struct VB_As_Stmt_list* last;		//!< Указатель на последний элемент списка объявляемых переменных
};


/*! \struct VB_As_Stmt_list
    Структура, описывающая связный список переменных, объявляемых одним типом
 */
struct VB_As_Stmt_list
{
	struct VB_As_stmt*		as_stmt;	//!< Список переменных, определяемых одним типом
	struct VB_As_Stmt_list* next;		//!< Указатель на следующий список переменных определяемых одним типом
};


/*! \struct VB_As_stmt
    Структура дерева для хранения определения переменных одного типа.
 */
struct VB_As_stmt
{ 
	bool					isInit;		//!< Инициализируется ли переменная
	struct VB_Id_list*		idents;		//!< Указатель на идентификаторов
	struct VB_Expr*			expr;		//!< Выражение, которым переменная инициализируетяс
};


/*! \struct VB_Id_list
    Структура дерева для хранения списка идентификаторов.
 */
struct VB_Id_list
{
	struct VB_Id*		current_id;		//!< Текущий идентификатор
	struct VB_Id_list*	next;			//!< Следующий идентификатор
};


/*! \struct VB_Id
    Структура дерева для хранения идентификатора.
 */
struct VB_Id
{
	enum VB_Id_type	type;			//!< Тип, определяемой переменной
	char*			name;			//!< Имя идентификатора.
	char*			str_val;		//!< Строковое значение переменной
	int				int_val;		//!< Значение выражения. Используется для bool, int, char.
};

