//
//
#ifndef H_DATA_TYPES
#define H_DATA_TYPES

/*! \enum VB_Id_type
    Перечисление типов идентификаторов.
 */
enum VB_Id_type
{
	DATA_INTEGER,
	DATA_BOOLEAN,
	DATA_CHAR,
	DATA_STRING
};

/*! \enum VB_Type_of_expr
    Перечисление типов операций.
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
    Перечисление типов выражения.
 */
enum VB_Expr_type
{
	EXPR_ID,			//!< Идентификатор
	EXPR_CHAR_CONST,	//!< Символьная константа
	EXPR_INT_CONST,		//!< Целочисленная константа
	EXPR_STRING_CONST,	//!< Строковая константа
	EXPR_BOOLEAN_CONST,	//!< Булевая константа
	EXPR_ASSIGN,		//!< Оператор присваивания
	EXPR_PLUS,			//!< Оператор сложения
	EXPR_MINUS,			//!< Оператор вычитания
	EXPR_MUL,			//!< Оператор умножения
	EXPR_DIV,			//!< Оператор деления
	EXPR_POWER,			//!< Оператор возведения в степень
	EXPR_MORE,			//!< Оператор "больше"
	EXPR_LESS,			//!< Оператор "меньше"
	EXPR_MORE_OR_EQUAL,	//!< Оператор "больше или равно"
	EXPR_LESS_OR_EQUAL,	//!< Оператор "меньше или равно"
	EXPR_NONEQUAL,		//!< Оператор "неравно"
	EXPR_EQUAL,			//!< Оператор "равно"
	EXPR_UMINUS,		//!< Оператор унарного минуса
	EXPR_BRK,			//!< Выражение со скобками
	EXPR_READ,			//!< Чтение одного симола из консоли
	EXPR_READLN,		//!< Чтение строки из консоли
	EXPR_PRINT,			//!< Вывод данных на консоль
	EXPR_PRINTLN		//!< Вывод данных на консоль с переносом строки
};

/*! \enum VB_Type_of_expr
    Перечисление типов описаний процедур и функций.
	Сюда же можно добавиь Enum и глобальные переменные
 */
enum VB_Decl_type
{
	DECL_SUB,
	DECL_FUNC
};

/*! \struct VB_For_stmt_type
    Тип цикла For.
 */
enum VB_For_stmt_type
{
	SIMPLE,
	WITH_DECL,
	WITH_STEP,
	WITH_DECL_AND_STEP
};

/*! \struct VB_Do_loop_type
    Тип цикла Do...Loop.
 */
enum VB_Do_loop_type
{
	DO_WHILE,
	DO_UNTIL,
	LOOP_WHILE,
	LOOP_UNTIL
};

/*!
	Преобразовать тип цикла Do...Loop.
	\param type Тип цикла Do .. Loop
	\return Строка с типом
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
	Преобразовать тип For в строку.
	\param type Тип цикла For.
	\return Строка с типом
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
	Получить строку с типом выражения
	\param type Тип выражения
	\return Строка с типом
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
	Получить строку с типом идентификатора.
	\param type Тип идентификатора
	\return Строка с типом
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
	\brief Функция преобразует тип Stmt в строку.
	\param type - Тип Stmt.
	\return Строка - тип Stmt.
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
	Преобразование типа объявления в строку
	\param type Тип объявления
	\return Строка с типом
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
	Преобразовать логическое значение в строку
	\param val Значение
	\return Строка с логическим значением
 */
char * get_boolean_string(int val)
{
	if (val == 0)
		return "false";
	else
		return "true";
}

#endif // H_DATA_TYPES