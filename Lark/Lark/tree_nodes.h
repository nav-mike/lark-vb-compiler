//
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*! \struct VB_Module_stmt
    Структура дерева для хранения корня дерева.
 */
struct VB_Module_stmt
{
	char* id;                       //!< Идентификатор модуля
	struct VB_Stmt_list* stmt_list; //!< Список операций модуля
};

/*! \struct VB_Stmt_list
    Структура, описывающая список операций.
 */
struct VB_Stmt_list
{
	struct VB_Stmt* first;		//!< Указатель на первый элемент списка
	struct VB_Stmt* last;		//!< Указатель на последний элемент списка
};

/*! \struct VB_Stmt
    Структура, описывающая операцию.
 */
struct VB_Stmt
{
	enum VB_Stmt_type	      type;	          //!< Тип операции.
	struct VB_Expr*		      expr;	          //!< Указатель на содержащееся в операции выражение.
	struct VB_If_stmt*        if_stmt;        //!< Указатель на содержащееся в операции условие.
	struct VB_Dim_stmt*       dim_stmt;       //!< Указатель на содержащуюся в операции инициализацию.
	struct VB_For_stmt*       for_stmt;       //!< Указатель на содержащийся в операции цикл.
	struct VB_While_stmt*     while_stmt;     //!< Указатель на содержащийся в операции цикл.
	struct VB_Do_Loop_stmt*   do_loop_stmt;   //!< Указатель на содержащийся в операции цикл.
	struct VB_Enum_stmt*      enum_stmt;      //!< Указатель на содержащееся в операции перечисление.
	struct VB_Sub_stmt*       sub_stmt;       //!< Указатель на содержащуюся в операции процедуру.
	struct VB_Func_stmt*      func_stmt;      //!< Указатель на содержащуюся в операции функцию.
	struct VB_Try_Catch_stmt* try_catch_stmt; //!< Указатель на содержащееся в операции отлов и обработка исключений.
	struct VB_Throw_stmt*     throw_stmt;     //!< Указатель на содержащийся в операции выброс исключения.
	struct VB_Print_stmt*     print_stmt;     //!< Указатель на содержащуюся в операции печать символа.
	struct VB_Println_stmt*   println_stmt;   //!< Указатель на содержащуюся в операции печать строки.
	struct VB_Read_stmt*      read_stmt;      //!< Указатель на содержащееся в операции считывание символа.
	struct VB_Readln_stmt*    readln_stmt;    //!< Указатель на содержащееся в операции считывание строки.
	struct VB_Readkey_stmt*   readkey_stmt;   //!< Указатель на содержащееся в операции считывание нажатой клавиши.
	struct VB_Stmt*		      next;	          //!< Указатель на следующий элемент последовательности операторов.
};

/*! \enum VB_Type_of_expr
    Перечисление типов операций. 
 */
enum VB_Stmt_type
{
	ENDL,
	STMT_EXPR,
	IF,
	DIM,
	FOR,
	WHILE,
	DO_LOOP,
	ENUM,
	SUB,
	FUNC,
	TRY_CATCH,
	THROW,
	PRINT,
	PRINTLN,
	READ,
	READLN,
	READKEY
};

/*! \struct VB_Expr_list
    Структура, описывающая список выражений.
 */
struct VB_Expr_list
{
	struct VB_Expr* first;  //!< Указатель на первый элемент списка
	struct VB_Expr* last;   //!< Указатель на последний элемент списка
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
	struct VB_Expr_list list;			//!< Параметры процедуры или функции
	
	enum VB_Id_type		id_type;		//!< Тип идентификатора 	????
};

/*! \enum VB_Type_of_expr
    Перечисление типов выражения. 
 */
enum VB_Expr_type
{
	ID,				//!< Идентификатор
	EXPR_FUNC,			//!< Процедура или функция
	CHAR_CONST,		//!< Символьная константа
	INT_CONST,		//!< Целочисленная константа
	STRING_CONST,	//!< Строковая константа
	BOOLEAN_CONST,	//!< Булевая константа
	ASSIGN,			//!< Оператор присваивания
	PLUS,			//!< Оператор сложения
	MINUS,			//!< Оператор вычитания
	MUL,			//!< Оператор умножения
	INT_DIV,		//!< Оператор целочисленного деления
	DIV,			//!< Оператор деления
	POWER,			//!< Оператор возведения в степень
	MORE,			//!< Оператор "больше"
	LESS,			//!< Оператор "меньше"
	MORE_OR_EQUAL,	//!< Оператор "больше или равно"
	LESS_OR_EQUAL,	//!< Оператор "меньше или равно"
	NONEQUAL,		//!< Оператор "неравно"
	EQUAL,			//!< Оператор "равно"
	UMINUS,			//!< Оператор унарного минуса
	UPLUS,			//!< Оператор унарного плюса
	GET_ITEM		//!< Получение элемента массива
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

/*! \struct VB_End_if_stmt
    Структура дерева для хранения второй части оператора условного перехода.
 */
struct VB_End_if_stmt
{
	enum VB_End_if_stmt_type 	type;		//!< Тип условного оператора
	struct VB_Stmt_list*		stmt_list;	//!< Указатель на список операций при истинном условии.
	struct VB_Expr*				expr;		//!< Условие
	struct VB_End_if_stmt*		end_stmt;	//!< Указатель на список операций при ложном условии условии.
	struct VB_Stmt*				next;		//!< Указатель на следующий элемент последовательности операторов.
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

/*! \struct VB_Dim_stmt
    Структура, описывающая операцию объявления переменных.
 */
struct VB_Dim_stmt
{
	struct VB_As_Expr_list* list;		//!< Указатель на элемент списка объявляемых переменных
	struct VB_Stmt*			next;		//!< Следующий оператор
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

/*! \enum VB_As_Stmt_list
    Перечисление, описывющее тип списка последовательности определения переменных
 */
enum VB_As_Expr_list_type
{
	EXPR,		//!< Определяется идентификатор
	ARRAY,		//!< Определяется массив
	EXPR_LIST,	//!< Определяется список идентификаторов
	EXPR_ARR	//!< Определяется список массивов
};

/*! \struct VB_As_stmt
    Структура дерева для хранения определения переменных одного типа.
 */
struct VB_As_expr
{ 
	enum	VB_As_expr_type	type;		//!< Тип 
	struct	VB_Id_list*		list;		//!< Список идентификаторов
	enum	VB_Id_type		id_type;	//!< Тип определяемого идентификатора
	struct	VB_Expr*		expr;		//!< Инициализируемое значение
	struct 	VB_Expr*		id;			//!< Идентификатор
};

enum VB_As_expr_type
{
	ID_LIST,	//!< Список идентификаторов
	ONE_ID,		//!< Один идентификаор
	ID_INIT		//!< Инициализированный идентификатор
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

/*! \struct VB_Id_list
    Список идентификаторов.
 */
struct VB_Id_list
{
	struct VB_Expr* id;					//!< Имя текущего идентификатора
	struct VB_Id_list* next;	//!Б Указатель на следубщий идентификатор
};

/*! \struct VB_Array_expr
    Структура, хранящая данные для определения массива.
 */
struct VB_Array_expr
{
	int is_init;				//!< Инициализируется ли массив.
	int size;					//!< Размер массива
	enum VB_Id_type	id_type;	//!< Тип определяемого идентификатора или масива
	struct VB_Expr_list list;	//!< Данные, которыми заполняется массив
	struct VB_Expr*	id;			//!< Идентификатор		???	
};

/*! \struct VB_For_stmt
    Структура, описывающая оператор цикла For.
 */
struct VB_For_stmt
{
	struct VB_Expr*		 id;			//!< Идентификатор
	int 				 from_val;		//!< Начало отсчета		
	int 				 to_val;		//!< Конец отчета
	int 				 step_val;		//!< Шаг
	struct VB_Stmt_list* stmt_list;		//!< Тело цикла
	struct VB_Stmt*		 next;			//!< Следующий оператор
};

/*! \struct VB_While_stmt
    Структура, описывающая оператор цикла While.
 */
struct VB_While_stmt
{
	struct VB_Stmt_list* stmt_list;	//!< Тело цикла
	struct VB_Expr*		 expr;		//!< Условие
	struct VB_Stmt*		 next;		//!< Следующий оператор
};

/*! \struct VB_Do_loop_stmt
    Структура, описывающая оператор цикла Do...Loop.
 */
struct VB_Do_loop_stmt
{
	enum VB_Do_loop_type type;		//!< Тип
	struct VB_Stmt_list* stmt_list;	//!< Тело цикла
	struct VB_Expr*		 expr;		//!< Условие
	struct VB_Stmt*		 next;		//!< Следующий оператор
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

/*! \struct VB_Enum_stmt
    Структура, описывающая перечисление Enum
 */
struct VB_Enum_stmt
{
	char*		 			  id;		//!< Имя поля
	struct VB_Enum_expr_list* list;		//!< Список полей
	struct VB_Stmt*			  next;		//!< Следующий оператор
};

/*! \struct VB_Enum_expr_list
    Связный список элементов Enum
 */
struct VB_Enum_expr_list
{
	struct VB_Enum_expr*	first;	//!< Указатель на первый элемент списка
	struct VB_Enum_expr*	last;	//!< Указатель на последний элемент списка
};

/*! \struct VB_Enum_expr
    Элемент перечисления Enum
 */
struct VB_Enum_expr
{
	int 				 is_init;	//!< Инициализируется ли				
	char*				 id;		//!< Имя
	int					 value;		//!< Значение
	struct VB_Enum_expr* next;		//!< Следующий элемент
};

/*! \struct VB_Sub_stmt
    Процедура
 */
struct VB_Sub_stmt
{
	int 					has_params;	//!< Есть ли параметры
	char*		 			id;			//!< Имя поля
	struct VB_Param_list*	param_list;	//!< Список параметров
	struct VB_Stmt_list* 	stmt_list;	//!< Тело процедуры
	struct VB_Stmt*			next;		//!< Следующий оператор
};

/*! \struct VB_Param_list
    Список параметров процедуры
 */
struct VB_Param_list
{
	struct VB_Param_stmt* first;	//!< Указатель на первый элемент списка
	struct VB_Param_stmt* last;		//!< Указатель на последний элемент списка
};

/*! \struct VB_Param_stmt
    Параметр процедуры
 */
struct VB_Param_stmt
{
	int  is_by_ref;			//!< Передача по ссылке
	char* id;					//!< Имя парметра
	enum VB_Id_type	id_type;	//!< Тип параметра
	struct VB_Param_stmt* next;	//!< Следующий 
};

/*! \struct VB_Func_stmt
    Функция
 */
struct VB_Func_stmt
{
	char* id;						//!< Имя функции
	enum VB_Id_type	id_type;		//!< Тип возвращаемого значения
	struct VB_Stmt_list* stmt_list;	//!< Тело процедуры
	struct VB_Expr*	expr;			//!< Возвращаемое значение
	struct VB_Param_list*	param_list;	//!< Список параметров
	struct VB_Stmt*			next;		//!< Следующий оператор
};

/*! \struct VB_Try_catch_stmt
    Try...cath
 */
struct VB_Try_catch_stmt
{
	struct VB_Stmt_list* stmt_list;		//!< Отлавливаемый код
	struct VB_Stmt_list* fin_stmt_list;	//!< 
	struct VB_Stmt*		 next;			//!< Следующий оператор
};

/*! \struct VB_Catch_stmt_list
    
 */
struct VB_Catch_stmt_list
{
	struct VB_Catch_stmt* first;
	struct VB_Catch_stmt* last;
};

/*! \struct VB_Catch_stmt
    
 */
struct VB_Catch_stmt
{
	char* id;
	struct VB_Stmt_list* stmt_list;	
	struct VB_Catch_stmt* next;
};

/*! \struct VB_Throw_stmt
   Выбрасываемое исключение
 */
struct VB_Throw_stmt
{
	char* 			string;		//!< Строка
	struct VB_Stmt*	next;		//!< Следующий оператор
};

/** Функции инициализации структур. */

/* Инициализация модуля:
	module_stmt: MODULE ID ENDL stmt_list END_MODULE ENDL ;
*/
/*!
	Функция создания узла дерева: модуля.
  \param id Имя модуля.
  \param list Список выражений модуля.
  \return Новый модуль.
*/
struct VB_Module_stmt* create_VB_Module_stmt (char* id, struct VB_Stmt_list* list)
{
	struct VB_Module_stmt* module = NULL;

	if (list == NULL) return module;

	module = (struct VB_Module_stmt*)malloc(sizeof(struct VB_Module_stmt));

	if (id == NULL) strcpy(module->id, "Unknown");
	else strcpy(module->id, id);

	module->stmt_list = list;

	return module;
}

/* Инициализация списка операций:
	stmt_list: stmt
		 | stmt_list stmt ;
*/
/*!
	Функция создания узла дерева: списка операций.
  \param stmt Операция.
  \return Новый список операций.
*/
struct VB_Stmt_list* create_VB_Stmt_list (struct VB_Stmt* stmt)
{
	struct VB_Stmt_list* list = NULL;

	if (stmt == NULL) return list;

	list = (struct VB_Stmt_list*)malloc(sizeof(struct VB_Stmt_list));

	list->first = stmt;
	list->last = stmt;

	return list;
}

/*!
	Функция изменения узла дерева: добавление к списку выражений операций.
  \param list Список операций.
  \param stmt Операция.
  \return Новый список операций.
*/
struct VB_Stmt_list* edit_VB_Stmt_list (struct VB_Stmt_list* list, struct VB_Stmt* stmt)
{
	if (stmt != NULL)
	{
		if (list != NULL)
		{
			list->last->next = stmt;
			list->last = stmt;
		}
		else list = create_VB_Stmt_list(stmt);
	}

	return list;
}

/* Инициализация выражения:
	stmt: ENDL
		| expr ENDL
		| if_stmt
		| dim_stmt
		| for_stmt
		| while_stmt
		| do_loop_stmt
		| enum_stmt
		| sub_stmt
		| func_stmt
		| try_catch_stmt
		| throw_stmt
		| console_print_stmt
		| console_println_stmt
		| console_read_stmt
		| console_readln_stmt
		| console_readkey_stmt
		;
*/
/*!
	Функция создания операции из выражения.
  \param expr Выражение.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Expr (struct VB_Expr* expr)
{
	struct VB_Stmt* stmt = NULL;

	if (expr != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));
		stmt->expr = expr;
		stmt->dim_stmt = NULL;
		stmt->do_loop_stmt = NULL;
		stmt->enum_stmt = NULL;
		stmt->for_stmt = NULL;
		stmt->func_stmt = NULL;
		stmt->if_stmt = NULL;
		stmt->next = NULL;
		stmt->print_stmt = NULL;
		stmt->println_stmt = NULL;
		stmt->read_stmt = NULL;
		stmt->readkey_stmt = NULL;
		stmt->readln_stmt = NULL;
		stmt->sub_stmt = NULL;
		stmt->throw_stmt = NULL;
		stmt->try_catch_stmt = NULL;
		stmt->type = STMT_EXPR;
		stmt->while_stmt = NULL;
	}

	return stmt;
}

/*!
	Функция создания операции из условной операции.
  \param if_stmt Условная операция.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_If (struct VB_If_stmt* if_stmt)
{
	struct VB_Stmt* stmt = NULL;

	if (if_stmt != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));
		stmt->expr = NULL;
		stmt->dim_stmt = NULL;
		stmt->do_loop_stmt = NULL;
		stmt->enum_stmt = NULL;
		stmt->for_stmt = NULL;
		stmt->func_stmt = NULL;
		stmt->if_stmt = if_stmt;
		stmt->next = NULL;
		stmt->print_stmt = NULL;
		stmt->println_stmt = NULL;
		stmt->read_stmt = NULL;
		stmt->readkey_stmt = NULL;
		stmt->readln_stmt = NULL;
		stmt->sub_stmt = NULL;
		stmt->throw_stmt = NULL;
		stmt->try_catch_stmt = NULL;
		stmt->type = IF;
		stmt->while_stmt = NULL;
	}

	return stmt;
}

/*!
	Функция создания операции из инициализации переменной.
  \param dim_stmt Инициализация перменной.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Dim (struct VB_Dim_stmt* dim_stmt)
{
	struct VB_Stmt* stmt = NULL;

	if (dim_stmt != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));
		stmt->expr = NULL;
		stmt->dim_stmt = dim_stmt;
		stmt->do_loop_stmt = NULL;
		stmt->enum_stmt = NULL;
		stmt->for_stmt = NULL;
		stmt->func_stmt = NULL;
		stmt->if_stmt = NULL;
		stmt->next = NULL;
		stmt->print_stmt = NULL;
		stmt->println_stmt = NULL;
		stmt->read_stmt = NULL;
		stmt->readkey_stmt = NULL;
		stmt->readln_stmt = NULL;
		stmt->sub_stmt = NULL;
		stmt->throw_stmt = NULL;
		stmt->try_catch_stmt = NULL;
		stmt->type = DIM;
		stmt->while_stmt = NULL;
	}

	return stmt;
}

/*!
	Функция создания операции из цикла.
  \param for_stmt Цикл.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_For (struct VB_For_stmt* for_stmt)
{
	struct VB_Stmt* stmt = NULL;

	if (for_stmt != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));
		stmt->expr = NULL;
		stmt->dim_stmt = NULL;
		stmt->do_loop_stmt = NULL;
		stmt->enum_stmt = NULL;
		stmt->for_stmt = for_stmt;
		stmt->func_stmt = NULL;
		stmt->if_stmt = NULL;
		stmt->next = NULL;
		stmt->print_stmt = NULL;
		stmt->println_stmt = NULL;
		stmt->read_stmt = NULL;
		stmt->readkey_stmt = NULL;
		stmt->readln_stmt = NULL;
		stmt->sub_stmt = NULL;
		stmt->throw_stmt = NULL;
		stmt->try_catch_stmt = NULL;
		stmt->type = FOR;
		stmt->while_stmt = NULL;
	}

	return stmt;
}

/*!
	Функция создания операции из цикла.
  \param while_stmt Цикл.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_While (struct VB_While_stmt* while_stmt)
{
	struct VB_Stmt* stmt = NULL;

	if (while_stmt != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));
		stmt->expr = NULL;
		stmt->dim_stmt = NULL;
		stmt->do_loop_stmt = NULL;
		stmt->enum_stmt = NULL;
		stmt->for_stmt = NULL;
		stmt->func_stmt = NULL;
		stmt->if_stmt = NULL;
		stmt->next = NULL;
		stmt->print_stmt = NULL;
		stmt->println_stmt = NULL;
		stmt->read_stmt = NULL;
		stmt->readkey_stmt = NULL;
		stmt->readln_stmt = NULL;
		stmt->sub_stmt = NULL;
		stmt->throw_stmt = NULL;
		stmt->try_catch_stmt = NULL;
		stmt->type = WHILE;
		stmt->while_stmt = while_stmt;
	}

	return stmt;
}

/*!
	Функция создания операции из цикла.
  \param do_loop_stmt Цикл.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Do_Loop (struct VB_Do_Loop_stmt* do_loop_stmt)
{
	struct VB_Stmt* stmt = NULL;

	if (do_loop_stmt != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));
		stmt->expr = NULL;
		stmt->dim_stmt = NULL;
		stmt->do_loop_stmt = do_loop_stmt;
		stmt->enum_stmt = NULL;
		stmt->for_stmt = NULL;
		stmt->func_stmt = NULL;
		stmt->if_stmt = NULL;
		stmt->next = NULL;
		stmt->print_stmt = NULL;
		stmt->println_stmt = NULL;
		stmt->read_stmt = NULL;
		stmt->readkey_stmt = NULL;
		stmt->readln_stmt = NULL;
		stmt->sub_stmt = NULL;
		stmt->throw_stmt = NULL;
		stmt->try_catch_stmt = NULL;
		stmt->type = DO_LOOP;
		stmt->while_stmt = NULL;
	}

	return stmt;
}

/*!
	Функция создания операции из перечисления.
  \param enum_stmt Перечисление.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Enum (struct VB_Enum_stmt* enum_stmt)
{
	struct VB_Stmt* stmt = NULL;

	if (enum_stmt != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));
		stmt->expr = NULL;
		stmt->dim_stmt = NULL;
		stmt->do_loop_stmt = NULL;
		stmt->enum_stmt = enum_stmt;
		stmt->for_stmt = NULL;
		stmt->func_stmt = NULL;
		stmt->if_stmt = NULL;
		stmt->next = NULL;
		stmt->print_stmt = NULL;
		stmt->println_stmt = NULL;
		stmt->read_stmt = NULL;
		stmt->readkey_stmt = NULL;
		stmt->readln_stmt = NULL;
		stmt->sub_stmt = NULL;
		stmt->throw_stmt = NULL;
		stmt->try_catch_stmt = NULL;
		stmt->type = ENUM;
		stmt->while_stmt = NULL;
	}

	return stmt;
}

/*!
	Функция создания операции из процедуры.
  \param sub_stmt Процедура.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Sub (struct VB_Sub_stmt* sub_stmt)
{
	struct VB_Stmt* stmt = NULL;

	if (sub_stmt != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));
		stmt->expr = NULL;
		stmt->dim_stmt = NULL;
		stmt->do_loop_stmt = NULL;
		stmt->enum_stmt = NULL;
		stmt->for_stmt = NULL;
		stmt->func_stmt = NULL;
		stmt->if_stmt = NULL;
		stmt->next = NULL;
		stmt->print_stmt = NULL;
		stmt->println_stmt = NULL;
		stmt->read_stmt = NULL;
		stmt->readkey_stmt = NULL;
		stmt->readln_stmt = NULL;
		stmt->sub_stmt = sub_stmt;
		stmt->throw_stmt = NULL;
		stmt->try_catch_stmt = NULL;
		stmt->type = SUB;
		stmt->while_stmt = NULL;
	}

	return stmt;
}

/*!
	Функция создания операции из функции.
  \param func_stmt Функция.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Func (struct VB_Func_stmt* func_stmt)
{
	struct VB_Stmt* stmt = NULL;

	if (func_stmt != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));
		stmt->expr = NULL;
		stmt->dim_stmt = NULL;
		stmt->do_loop_stmt = NULL;
		stmt->enum_stmt = NULL;
		stmt->for_stmt = NULL;
		stmt->func_stmt = func_stmt;
		stmt->if_stmt = NULL;
		stmt->next = NULL;
		stmt->print_stmt = NULL;
		stmt->println_stmt = NULL;
		stmt->read_stmt = NULL;
		stmt->readkey_stmt = NULL;
		stmt->readln_stmt = NULL;
		stmt->sub_stmt = NULL;
		stmt->throw_stmt = NULL;
		stmt->try_catch_stmt = NULL;
		stmt->type = FUNC;
		stmt->while_stmt = NULL;
	}

	return stmt;
}

/*!
	Функция создания операции из исключений.
  \param try_catch_stmt Исключение.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Try_Cathc (struct VB_Try_Catch_stmt* try_catch_stmt)
{
	struct VB_Stmt* stmt = NULL;

	if (try_catch_stmt != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));
		stmt->expr = NULL;
		stmt->dim_stmt = NULL;
		stmt->do_loop_stmt = NULL;
		stmt->enum_stmt = NULL;
		stmt->for_stmt = NULL;
		stmt->func_stmt =  NULL;
		stmt->if_stmt = NULL;
		stmt->next = NULL;
		stmt->print_stmt = NULL;
		stmt->println_stmt = NULL;
		stmt->read_stmt = NULL;
		stmt->readkey_stmt = NULL;
		stmt->readln_stmt = NULL;
		stmt->sub_stmt = NULL;
		stmt->throw_stmt = NULL;
		stmt->try_catch_stmt = try_catch_stmt;
		stmt->type = THROW;
		stmt->while_stmt = NULL;
	}

	return stmt;
}

/*!
	Функция создания операции из печати символа.
  \param print_stmt Печать символа.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Print (struct VB_Print_stmt* print_stmt)
{
	struct VB_Stmt* stmt = NULL;

	if (print_stmt != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));
		stmt->expr = NULL;
		stmt->dim_stmt = NULL;
		stmt->do_loop_stmt = NULL;
		stmt->enum_stmt = NULL;
		stmt->for_stmt = NULL;
		stmt->func_stmt =  NULL;
		stmt->if_stmt = NULL;
		stmt->next = NULL;
		stmt->print_stmt = print_stmt;
		stmt->println_stmt = NULL;
		stmt->read_stmt = NULL;
		stmt->readkey_stmt = NULL;
		stmt->readln_stmt = NULL;
		stmt->sub_stmt = NULL;
		stmt->throw_stmt = NULL;
		stmt->try_catch_stmt = NULL;
		stmt->type = PRINT;
		stmt->while_stmt = NULL;
	}

	return stmt;
}

/*!
	Функция создания операции из печати строки.
  \param println_stmt Печать строки.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Println (struct VB_Println_stmt* println_stmt)
{
	struct VB_Stmt* stmt = NULL;

	if (println_stmt != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));
		stmt->expr = NULL;
		stmt->dim_stmt = NULL;
		stmt->do_loop_stmt = NULL;
		stmt->enum_stmt = NULL;
		stmt->for_stmt = NULL;
		stmt->func_stmt =  NULL;
		stmt->if_stmt = NULL;
		stmt->next = NULL;
		stmt->print_stmt = NULL;
		stmt->println_stmt = println_stmt;
		stmt->read_stmt = NULL;
		stmt->readkey_stmt = NULL;
		stmt->readln_stmt = NULL;
		stmt->sub_stmt = NULL;
		stmt->throw_stmt = NULL;
		stmt->try_catch_stmt = NULL;
		stmt->type = PRINTLN;
		stmt->while_stmt = NULL;
	}

	return stmt;
}

/*!
	Функция создания операции из чтения строки.
  \param readln_stmt Печать строки.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Readln (struct VB_Readln_stmt* readln_stmt)
{
	struct VB_Stmt* stmt = NULL;

	if (readln_stmt != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));
		stmt->expr = NULL;
		stmt->dim_stmt = NULL;
		stmt->do_loop_stmt = NULL;
		stmt->enum_stmt = NULL;
		stmt->for_stmt = NULL;
		stmt->func_stmt =  NULL;
		stmt->if_stmt = NULL;
		stmt->next = NULL;
		stmt->print_stmt = NULL;
		stmt->println_stmt = NULL;
		stmt->read_stmt = NULL;
		stmt->readkey_stmt = NULL;
		stmt->readln_stmt = readln_stmt;
		stmt->sub_stmt = NULL;
		stmt->throw_stmt = NULL;
		stmt->try_catch_stmt = NULL;
		stmt->type = PRINTLN;
		stmt->while_stmt = NULL;
	}

	return stmt;
}