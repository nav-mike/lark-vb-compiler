//
//
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*! \enum VB_Id_type
    Перечисление типов идентификаторов.
 */
enum VB_Id_type
{
	INTEGER_E,
	BOOLEAN_E,
	CHAR_E,
	STRING_E
};

/*! \struct VB_Module_stmt
    Структура дерева для хранения корня дерева.
 */
struct VB_Module_stmt
{
	char* id;                       //!< Идентификатор модуля
	struct VB_Stmt_list* stmt_list; //!< Список операций модуля
	struct VB_Decl_stmt_list* decl_list;
};

struct VB_Decl_stmt_list
{
	struct VB_Decl_stmt* first;
	struct VB_Decl_stmt* last;
};

/*! \enum VB_Type_of_expr
    Перечисление типов операций.
 */
enum VB_Stmt_type
{
	ENDL_E,
	STMT_EXPR_E,
	IF_E,
	DIM_E,
	FOR_E,
	WHILE_E,
	DO_LOOP_E,
	ENUM_D,
	SUB_D,
	FUNC_D,
	TRY_CATCH_E,
	THROW_E,
	PRINT_E,
	PRINTLN_E,
	READ_E,
	READLN_E,
	READKEY_E,
	RETURN_E
};

struct VB_Decl_stmt
{
	enum VB_Stmt_type	      type;	          //!< Тип операции.
	struct VB_Enum_stmt*      enum_stmt;      //!< Указатель на содержащееся в операции перечисление.
	struct VB_Sub_stmt*       sub_stmt;       //!< Указатель на содержащуюся в операции процедуру.
	struct VB_Func_stmt*      func_stmt;      //!< Указатель на содержащуюся в операции функцию.
	struct VB_Decl_stmt*	  next;
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
	void* value;
	struct VB_Stmt*		      next;	          //!< Указатель на следующий элемент последовательности операторов.
};

/*! \struct VB_Expr_list
    Структура, описывающая список выражений.
 */
struct VB_Expr_list
{
	struct VB_Expr* first;  //!< Указатель на первый элемент списка
	struct VB_Expr* last;   //!< Указатель на последний элемент списка
};

/*! \enum VB_Type_of_expr
    Перечисление типов выражения.
 */
enum VB_Expr_type
{
	ID_E,				//!< Идентификатор
	EXPR_FUNC,		//!< Процедура или функция
	CHAR_CONST_E,		//!< Символьная константа
	INT_CONST_E,		//!< Целочисленная константа
	STRING_CONST_E,	//!< Строковая константа
	BOOLEAN_CONST_E,	//!< Булевая константа
	ASSIGN,			//!< Оператор присваивания
	PLUS,			//!< Оператор сложения
	MINUS,			//!< Оператор вычитания
	MUL,			//!< Оператор умножения
	INT_DIV,		//!< Оператор целочисленного деления
	DIV,			//!< Оператор деления
	POWER,			//!< Оператор возведения в степень
	MORE,			//!< Оператор "больше"
	LESS,			//!< Оператор "меньше"
	MORE_OR_EQUAL_E,	//!< Оператор "больше или равно"
	LESS_OR_EQUAL_E,	//!< Оператор "меньше или равно"
	NONEQUAL_E,		//!< Оператор "неравно"
	EQUAL_E,			//!< Оператор "равно"
	UMINUS_E,			//!< Оператор унарного минуса
	UPLUS,			//!< Оператор унарного плюса
	GET_ITEM,		//!< Получение элемента массива
	BRK_EXPR		//!< Выражение со скобками
};

/*! \struct VB_Expr
    Структура дерева для хранения выражения.
 */
struct VB_Expr
{
	enum VB_Expr_type	 type;			//!< Тип выражения.
	char*				 expr_string;	//!< Имя идентификатора, либо строка.
	int					 int_val;		//!< Значение выражения. Используется для bool, int, char.
	struct VB_Expr*		 left_chld;		//!< Указатель на левого сына.
	struct VB_Expr*		 right_chld;		//!< Указатель на правого сына.
	struct VB_Expr_list* list;			//!< Параметры процедуры или функции
	struct VB_Expr*      next;           //!< Указатель на следующего, для Expr_list.

	enum VB_Id_type		id_type;		//!< Тип идентификатора 	????
};

struct VB_Return_stmt
{
	struct VB_Expr*			expr;
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

/*! \struct VB_If_stmt
    Структура дерева для хранения оператора условного перехода.
 */
struct VB_If_stmt
{
	enum   VB_If_stmt_type  type;		//!< Тип условного оператора
	struct VB_Expr*			expr;		//!< Условие
	struct VB_Stmt_list*	stmt_list;	//!< Указатель на список операций при истинном условии.
	struct VB_Stmt_list*	else_list;	//!< Указатель на список операций при ложном условии (только если в 1 строку).
	struct VB_End_if_stmt*	end_stmt;	//!< Указатель на список операций при ложном условии.
	struct VB_Stmt*			next;		//!< Указатель на следующий элемент последовательности операторов.
};

/*! \enum VB_End_if_stmt_type
    Перечисление типов окончания операции условного перехода.
 */
enum VB_End_if_stmt_type
{
	ENDIF_E=0,						//!< Операция завершилась
	ELSE_E=1,						//!< Есть альтернативное действие
	ELSE_IF_THEN_E=2,				//!< Есть альтернативное действие с условием и на конце условия стоит "Then"
	ELSE_IF_ENDL_E=3				//!< Есть альтернативное действие с условием и на конце условия стоит ENDL
};

/*! \struct VB_End_if_stmt
    Структура дерева для хранения второй части оператора условного перехода.
 */
struct VB_End_if_stmt
{
	enum VB_End_if_stmt_type 	type;		//!< Тип условного оператора
	struct VB_Stmt_list*		stmt_list;	//!< Указатель на список операций при истинном условии.
	struct VB_Expr*				expr;		//!< Условие
	struct VB_End_if_stmt*		end_stmt;	//!< Указатель на список операций при ложном условии.
	struct VB_Stmt*				next;		//!< Указатель на следующий элемент последовательности операторов.
};

/*! \struct VB_Dim_stmt
    Структура, описывающая операцию объявления переменных.
 */
struct VB_Dim_stmt
{
	struct VB_As_Expr_list* list;		//!< Указатель на элемент списка объявляемых переменных
	struct VB_Stmt*			next;		//!< Следующий оператор
};


/*! \enum VB_As_Stmt_list
    Перечисление, описывющее тип списка последовательности определения переменных
 */
enum VB_As_Expr_list_type
{
	EXPR,		//!< Определяется идентификатор
	ARRAY,		//!< Определяется массив
	EXPR_LIST,	//!< Определяется список идентификаторов
	ARR_LIST	//!< Определяется список массивов
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
	ID_LIST,	//!< Список идентификаторов
	ONE_ID,		//!< Один идентификаор
	ID_INIT		//!< Инициализированный идентификатор
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

enum VB_Id_type return_type(enum VB_Id_type type)
{
	return type;
}

/*! \struct VB_Id_list
    Список идентификаторов.
 */
struct VB_Id_list
{
	int counter;
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
	struct VB_Expr_list* list;	//!< Данные, которыми заполняется массив
	char*	id;			//!< Идентификатор		???
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

/*! \struct VB_For_stmt
    Структура, описывающая оператор цикла For.
 */
struct VB_For_stmt
{
	enum VB_For_stmt_type type;			//!< Тип операции For
	char*				 id;			//!< Идентификатор
	int 				 from_val;		//!< Начало отсчета
	int 				 to_val;		//!< Конец отчета
	int 				 step_val;		//!< Шаг
	struct VB_Stmt_list* stmt_list;		//!< Тело цикла
	struct VB_Stmt*		 next;			//!< Следующий оператор
	struct VB_Expr*		 new_id;		//!< Если переменная создается для цикла
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

/*! \struct VB_Print_stmt
	Сообщение в стандратный поток вывода.
*/
struct VB_Print_stmt
{
//	char* text; 
	struct VB_Expr*		 expr;	//!< Текст сообщения.
};

/*! \struct VB_Println_stmt
	Сообщение с переводом строки в стандартный поток вывода.
*/
struct VB_Println_stmt
{
	struct VB_Expr*		 expr;	//!< Текст сообщения.
	//char* text; 
};

/*! \struct VB_Read_stmt
	Считывание символа из стандартного потока.
*/
struct VB_Read_stmt
{
	char symbol;
};

/*! \struct VB_Readln_stmt
	Считывание строки из стандартного потока.
*/
struct VB_Readln_stmt
{
	char* text;
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
	struct VB_Stmt_list*       stmt_list;		//!< Отлавливаемый код
	struct VB_Stmt_list*       fin_stmt_list;	//!<
	struct VB_Stmt*		       next;			//!< Следующий оператор
	struct VB_Catch_stmt_list* catch_list;      //!< Блок всех обработчиков исключения.
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

/*!
	\brief Функция слияния списков функций/процедур до Main и после.
	\param prev Список методов до Main.
	\param post Список методов после Main.
	\return Список, содержащий prev и post.
*/
struct VB_Decl_stmt_list* merge_two_decl_stmt_list (struct VB_Decl_stmt_list* prev, struct VB_Decl_stmt_list* post)
{
	struct VB_Decl_stmt* item = post->first;

	//while (item)
	//{
		prev->last->next = item;

	//	item = item->next;
	//}

	return prev;
}

/* Инициализация модуля:
	module_stmt: MODULE ID ENDL stmt_list END_MODULE ENDL ;
*/
/*!
	Функция создания узла дерева: модуля.
  \param id Имя модуля.
  \param list Список выражений модуля.
  \return Новый модуль.
*/
struct VB_Module_stmt* create_VB_Module_stmt (char* id, struct VB_Stmt_list* list, struct VB_Decl_stmt_list* prev_decl, struct VB_Decl_stmt_list* post_decl)
{
	struct VB_Module_stmt* module = NULL;

	printf("CREATING MODULE");

	module = (struct VB_Module_stmt*)malloc(sizeof(struct VB_Module_stmt));
	module->decl_list = NULL;

	if (id == NULL)
	{
		module->id = (char*)malloc(8 * sizeof(char));
		strcpy(module->id, "Unknown\0");
	}
	else
		module->id = id;

	module->stmt_list = list;

	if (prev_decl != NULL && post_decl != NULL)
		module->decl_list = merge_two_decl_stmt_list(prev_decl,post_decl);
	else if (prev_decl != NULL)
		module->decl_list = prev_decl;
	else if (post_decl != NULL)
	{
		module->decl_list = post_decl;
	}

	return module;
}

struct VB_Decl_stmt_list* create_VB_Decl_stmt_list(struct VB_Decl_stmt* decl_stmt)
{
	struct VB_Decl_stmt_list* list = NULL;

	if (decl_stmt == NULL) return list;

	list = (struct VB_Decl_stmt_list*)malloc(sizeof(struct VB_Decl_stmt_list));

	list->first = decl_stmt;
	list->last = decl_stmt;

	return list;
}

struct VB_Decl_stmt_list* edit_VB_Decl_stmt_list(struct VB_Decl_stmt_list* decl_list, struct VB_Decl_stmt* decl_stmt)
{
	if (decl_stmt != NULL)
	{
		if (decl_list != NULL)
		{
			decl_list->last->next = decl_stmt;
			decl_list->last = decl_stmt;
		}
		else
			decl_list = create_VB_Decl_stmt_list(decl_stmt);
	}

	return decl_list;
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
	Функция создания stmt и заполнения его полей.
  \param type Тип stmt.
  \param data Данные для заполнения полей.
  \return stmt.
*/
struct VB_Stmt* fill_stmt(enum VB_Stmt_type type, void* data)
{
	struct VB_Stmt* stmt = NULL;

	if (data != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));

		stmt->value = NULL;

		stmt->value = data;

		stmt->type = type;

		stmt->next = NULL;
	}
	return stmt;
}

struct VB_Decl_stmt* fill_decl_stmt(enum VB_Stmt_type type, void* data)
{
	struct VB_Decl_stmt* stmt = NULL;

	if (data != NULL)
	{
		stmt = (struct VB_Decl_stmt*)malloc(sizeof(struct VB_Decl_stmt));

		stmt->enum_stmt = NULL;
		stmt->func_stmt = NULL;
		stmt->next = NULL;
		stmt->sub_stmt = NULL;

		stmt->type = type;

		switch(type)
		{
		    case(RETURN_E):
                break;
		    case(READKEY_E):
                break;
		    case(READLN_E):
                break;
		    case(PRINT_E):
                break;
            case(PRINTLN_E):
                break;
            case(READ_E):
                break;
		    case(THROW_E):
                break;
		    case(ENDL_E):
                break;
            case(STMT_EXPR_E):
                break;
            case(IF_E):
                break;
            case(DIM_E):
                break;
            case(FOR_E):
                break;
            case(WHILE_E):
                break;
            case(DO_LOOP_E):
                break;
            case(TRY_CATCH_E):
                break;
			case(7):
				stmt->enum_stmt = (struct VB_Enum_stmt*)data;
				break;
			case(8):
				stmt->sub_stmt = (struct VB_Sub_stmt*)data;
				break;
			case(9):
				stmt->func_stmt = (struct VB_Func_stmt*)data;
				break;
		}
	}
	return stmt;
}

/*!
	Функция создания операции из выражения.
  \param expr Выражение.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Expr (struct VB_Expr* expr)
{
	return fill_stmt(1,(void*)expr);
}

/*!
	Функция создания операции из условной операции.
  \param if_stmt Условная операция.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_If (struct VB_If_stmt* if_stmt)
{
	return fill_stmt(2,(void*)if_stmt);
}

/*!
	Функция создания операции из инициализации переменной.
  \param dim_stmt Инициализация перменной.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Dim (struct VB_Dim_stmt* dim_stmt)
{
	return fill_stmt(3,(void*)dim_stmt);
}

/*!
	Функция создания операции из цикла.
  \param for_stmt Цикл.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_For (struct VB_For_stmt* for_stmt)
{
	return fill_stmt(4,(void*)for_stmt);
}

/*!
	Функция создания операции из цикла.
  \param while_stmt Цикл.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_While (struct VB_While_stmt* while_stmt)
{
	return fill_stmt(5,(void*)while_stmt);
}

/*!
	Функция создания операции из цикла.
  \param do_loop_stmt Цикл.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Do_Loop (struct VB_Do_loop_stmt* do_loop_stmt)
{
	return fill_stmt(6,(void*)do_loop_stmt);
}

/*!
	Функция создания операции из перечисления.
  \param enum_stmt Перечисление.
  \return Новая операция.
*/
struct VB_Decl_stmt* create_VB_Decl_Enum (struct VB_Enum_stmt* enum_stmt)
{
	return fill_decl_stmt(7,(void*)enum_stmt);
}

/*!
	Функция создания операции из процедуры.
  \param sub_stmt Процедура.
  \return Новая операция.
*/
struct VB_Decl_stmt* create_VB_Decl_Sub (struct VB_Sub_stmt* sub_stmt)
{
	return fill_decl_stmt(8,(void*)sub_stmt);
}

/*!
	Функция создания операции из функции.
  \param func_stmt Функция.
  \return Новая операция.
*/
struct VB_Decl_stmt* create_VB_Decl_Func (struct VB_Func_stmt* func_stmt)
{
	return fill_decl_stmt(9,(void*)func_stmt);
}

/*!
	Функция создания операции из исключений.
  \param try_catch_stmt Исключение.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Try_Catch (struct VB_Try_catch_stmt* try_catch_stmt)
{
	return fill_stmt(10,(void*)try_catch_stmt);
}

/*!
	Функция создания выброса исключения.
  \param throw_stmt Исключение.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Throw(struct VB_Throw_stmt* throw_stmt)
{
	return fill_stmt(11,(void*)throw_stmt);
}

/*!
	Функция создания операции из печати символа.
  \param print_stmt Печать символа.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Print (struct VB_Print_stmt* print_stmt)
{
	return fill_stmt(12,(void*)print_stmt);
}

/*!
	Функция создания операции из печати строки.
  \param println_stmt Печать строки.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Println (struct VB_Println_stmt* println_stmt)
{
	return fill_stmt(13,(void*)println_stmt);
}

/*!
	Функция создания операции из чтения строки.
  \param readln_stmt Чтение строки.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Readln (struct VB_Readln_stmt* readln_stmt)
{
	return fill_stmt(15,(void*)readln_stmt);
}

/*!
	Функция создания операции из чтения символа.
  \param read_stmt Чтение символа.
  \return Новая операция.
*/
struct VB_Stmt* create_VB_Stmt_Read (struct VB_Read_stmt* read_stmt)
{
	return (struct VB_Stmt*)fill_stmt(14,(void*)read_stmt);
}

struct VB_Return_stmt* create_VB_Stmt_Return(struct VB_Return_stmt* ret)
{
	return (struct VB_Return_stmt*)fill_stmt(RETURN_E,(void*)ret);
}

struct VB_Return_stmt* create_return_stmt(struct VB_Expr* expr)
{
	struct VB_Return_stmt* result = (struct VB_Return_stmt*)malloc(sizeof(struct VB_Return_stmt));

	result->expr = expr;
	result->next = NULL;

	return result;
}

/* Инициализация условного выражения:
	if_stmt: IF expr THEN ENDL stmt_list end_if_stmt
		   | IF expr ENDL stmt_list end_if_stmt
		   | IF expr THEN stmt_list_inline END_IF ENDL
		   | IF expr THEN stmt_list_inline ELSE stmt_list_inline END_IF ENDL
		   ;
*/
/*!
	Функция создает условное выражение по первой строчке грамматики.
  \param expr Условие.
  \param stmt_list Действия при положительном условии.
  \param end_if_stmt Действия при ложном условии.
  \return Новое условное выражение.
*/
struct VB_If_stmt* create_with_Then_expr_stmt_list_end_if_stmt (enum VB_If_stmt_type type, struct VB_Expr* expr,
	struct VB_Stmt_list* stmt_list, struct VB_End_if_stmt* end_if_stmt)
{
	struct VB_If_stmt* if_stmt = NULL;

	if_stmt = (struct VB_If_stmt*)malloc(sizeof(struct VB_If_stmt));

	if_stmt->type = type;
	if_stmt->expr = expr;
	if_stmt->end_stmt = end_if_stmt;
	if_stmt->stmt_list = stmt_list;
	if_stmt->else_list = NULL;

	return if_stmt;
}

struct VB_End_if_stmt* create_end_if_stmt(enum VB_End_if_stmt_type type, struct VB_Expr* expr,
	struct VB_Stmt_list* stmt_list, struct VB_End_if_stmt* end_if_stmt)
{
	struct VB_End_if_stmt* end_if = NULL;

	end_if = (struct VB_End_if_stmt*)malloc(sizeof(struct VB_End_if_stmt));
	end_if->type = type;
	end_if->expr = expr;
	end_if->stmt_list = stmt_list;
	end_if->end_stmt = end_if_stmt;

	return end_if_stmt;
}

/*!
	Функция создает условное выражение по первой строчке грамматики.
  \param expr Условие.
  \param stmt_list Действия при положительном условии.
  \param end_if_stmt Действия при ложном условии.
  \return Новое условное выражение.
*/
struct VB_If_stmt* create_if_inline(enum VB_If_stmt_type type, struct VB_Expr* expr,
									struct VB_Stmt_list* if_list, struct VB_Stmt_list* else_list)
{
	struct VB_If_stmt* if_stmt = NULL;

	if_stmt = (struct VB_If_stmt*)malloc(sizeof(struct VB_If_stmt));

	if_stmt->type = type;
	if_stmt->expr = expr;
	if_stmt->stmt_list = if_list;
	if_stmt->else_list = else_list;

	return if_stmt;
}

/*!
	Функция создания листа выражений.
  \param expr Выражение.
  \return Лист выражений.
*/
struct VB_Expr_list* create_Expr_list (struct VB_Expr* expr)
{
	struct VB_Expr_list* list = NULL;

	if (!expr) return list;

	list = (struct VB_Expr_list*)malloc(sizeof(struct VB_Expr_list));

	list->first = expr;
	list->last = expr;

	return list;
}

/*!
	Функция изменения листа выражений.
  \param expr_list Лист выражений.
  \param expr Добавляемое выражение.
*/
struct VB_Expr_list* add_Expr_to_list (struct VB_Expr_list* expr_list, struct VB_Expr* expr)
{
	expr_list->last->next = expr;
	expr_list->last = expr;

	return expr_list;
}

/*!
	Функция создания массива без его инициализации.
  \param id Имя массива.
  \param int_const Размер массива.
  \param type Тип массива.
  \return Новый узел массива.
*/
struct VB_Array_expr* create_Array (char* id, int int_const, enum VB_Id_type type)
{
	struct VB_Array_expr* arr = NULL;

	arr = (struct VB_Array_expr*)malloc(sizeof(struct VB_Array_expr));

	arr->id_type = type;
	arr->is_init = 0;
	arr->size = int_const;
	arr->id = (char*)malloc(sizeof(char) * strlen(id));
	strcpy(arr->id,id);
	arr->list = NULL;

	return arr;
}

/*!
	Функция создания массива с его инициализацией.
  \param id Имя массива.
  \param type Тип массива.
  \param list Инициализация.
  \return Новый узел массива.
*/
struct VB_Array_expr* create_Array_with_init (char* id, enum VB_Id_type type, struct VB_Expr_list* list)
{
	struct VB_Array_expr* result = NULL;

	result = (struct VB_Array_expr*)malloc(sizeof(struct VB_Array_expr));

	result->id_type = type;
	result->list = list;
	result->is_init = 1;
	result->id = (char*)malloc(sizeof(char) * strlen(id));
	strcpy(result->id, id);

	return result;
}

/*!
	Функция создания узла дерева: выброс исключения.
  \param string Текст исключения.
  \return Узел дерева - выброс исключения.
*/
struct VB_Throw_stmt* create_Throw (char* string)
{
	struct VB_Throw_stmt* th = NULL;

	th = (struct VB_Throw_stmt*)malloc(sizeof(struct VB_Throw_stmt));
	strcpy(th->string, string);

	return th;
}

/*!
	Функция создания Console.Write()
  \param text Текст в функции.
  \return Узел дерева - вывод в стандартный поток.
*/
struct VB_Print_stmt* create_Print (struct VB_Expr* expr)
{
	struct VB_Print_stmt* print = NULL;

	print = (struct VB_Print_stmt*)malloc(sizeof(struct VB_Print_stmt));

	print->expr = expr;

	if (print->expr->expr_string == NULL){
		print->expr->expr_string = (char*)malloc(sizeof(char)*5);
		strcpy(print->expr->expr_string,"expr\0");
	}

	return print;
}

/*!
	Функция создания Console.WriteLine()
  \param text Текст в функции.
  \return Узел дерева - вывод в стандратный поток с переносом строки.
*/
struct VB_Println_stmt* create_Println (struct VB_Expr* expr)
{
	struct VB_Println_stmt* println = NULL;

	println = (struct VB_Println_stmt*)malloc(sizeof(struct VB_Println_stmt));

	println->expr = expr;

	if (println->expr->expr_string == NULL){
		println->expr->expr_string = (char*)malloc(sizeof(char)*6);
		strcpy(println->expr->expr_string,"expr\n\0");
	}
	return println;
}

/*!
	Функция создания Console.Read().
  \return Узел дерева - считывание символа с стандартного потока.
*/
struct VB_Read_stmt* create_Read ()
{
	struct VB_Read_stmt* read = NULL;

	read = (struct VB_Read_stmt*)malloc(sizeof(struct VB_Read_stmt));

	return read;
}

/*!
	Функция создания Console.ReadLine().
  \return Узед дерева - считывание строки с стандартного потока.
*/
struct VB_Readln_stmt* create_Readln ()
{
	struct VB_Readln_stmt* readln = NULL;

	readln = (struct VB_Readln_stmt*)malloc(sizeof(struct VB_Readln_stmt));

	return readln;
}

/*!
	Функция создания блока обработки перехваченного исключения.
  \param id Имя исключения.
  \param stmt_list Блок операторов обработки исключения.
  \return Новый узел дерева - блок обработки исключения.
*/
struct VB_Catch_stmt* create_Catch_stmt (char* id, struct VB_Stmt_list* stmt_list)
{
	struct VB_Catch_stmt* catch_stmt = NULL;

	catch_stmt = (struct VB_Catch_stmt*)malloc(sizeof(struct VB_Catch_stmt));

	strcpy(catch_stmt->id,id);
	catch_stmt->stmt_list = stmt_list;

	return catch_stmt;
}

/*!
	Функция создания листа блоков обработки перехваченных сообщений.
  \param catch_stmt Блок обработки перехваченного исключения.
  \return Новый лист блоков обработки перехваченных сообщений.
*/
struct VB_Catch_stmt_list* create_Catch_stmt_list (struct VB_Catch_stmt* catch_stmt)
{
	struct VB_Catch_stmt_list* list = NULL;

	list = (struct VB_Catch_stmt_list*)malloc(sizeof(struct VB_Catch_stmt_list));
	list->first = catch_stmt;
	list->last = catch_stmt;

	return list;
}

/*!
	Функция добавления нового блока обработки перехваченного исключения.
  \param catch_stmt_list Изменяемый лист блоков обработки перехваченных исключений.
  \param catch_stmt Блок обработки перехваченного исключения.
  \return Новый лист блоков обработки перехваченных сообщений.
*/
struct VB_Catch_stmt_list* add_new_Catch_stmt (struct VB_Catch_stmt_list* catch_stmt_list,
	struct VB_Catch_stmt* catch_stmt)
{
	catch_stmt_list->last->next = catch_stmt;
	catch_stmt_list->last = catch_stmt;

	return catch_stmt_list;
}

/*!
	Функция создания всего блока отлова - обработки исключения.
  \param stmt_list Отлавливаемый код.
  \param catch_stmt_list Обработка исключений.
  \param f_stmt_list Действия после исключения.
  \return Блок отлова - обработки исключений.
*/
struct VB_Try_catch_stmt* create_Try_Catch (struct VB_Stmt_list* stmt_list,
											struct VB_Catch_stmt_list* catch_stmt_list,
											struct VB_Stmt_list* f_stmt_list)
{
	struct VB_Try_catch_stmt* t = NULL;

	t = (struct VB_Try_catch_stmt*)malloc(sizeof(struct VB_Try_catch_stmt));
	t->catch_list = catch_stmt_list;
	t->stmt_list = stmt_list;
	t->fin_stmt_list = f_stmt_list;

	return t;
}

/*!
	Функция создания выражения идентификатора.
  \param name Имя идентификатора.
  \return указатель на объект выражения.
*/
struct VB_Expr* create_id_expr(char* name)
{
	struct VB_Expr* result = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));
	printf("Create ID %s\n", name);

	result->type = 0;
	result->expr_string = name;
	result->left_chld = NULL;
	result->list = NULL;
	result->next = NULL;
	result->right_chld = NULL;

	return result;
}

/*!
	Функция создания выражения вызова функции.
  \param name Имя идентификатора.
  \param params Параметры.
  \return указатель на объект выражения.
*/
struct VB_Expr* create_func_expr(char* name, struct VB_Expr_list* params)
{
	struct VB_Expr* result = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));

	result->type = 9;
	result->expr_string = name;
	result->list = params;
	result->left_chld = NULL;
	result->next = NULL;
	result->right_chld = NULL;

	return result;
}

/*!
	Функция создания выражения со скобками.
*/
struct VB_Expr* create_brackets_actions(char* name, struct VB_Expr_list* params)
{
	struct VB_Expr* result = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));

	result->type = 22;
	result->expr_string = name;
	result->list = params;
	result->left_chld = NULL;
	result->next = NULL;
	result->right_chld = NULL;

	return result;
}

/*!
	Функция создания выражения константы (int, boolean, char).
  \param type Тип идентификатора.
  \param name Имя идентификатора.
  \return указатель на объект выражения.
*/
struct VB_Expr* create_int_boolean_char_const_expr(enum VB_Expr_type type, int value)
{
	struct VB_Expr* result = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));
	printf("Create Expr %d", value);

	result->type = type;
	result->int_val = value;
	result->expr_string = "int";
	result->left_chld = NULL;
	result->list = NULL;
	result->next = NULL;
	result->right_chld = NULL;

	return result;
}

/*!
	Функция создания выражения текстовой константы.
  \param string Строка.
  \return указатель на объект выражения.
*/
struct VB_Expr* create_string_const_expr(char* string)
{
	struct VB_Expr* result = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));

	result->type = STRING_CONST_E;
	result->expr_string = (char*)malloc(sizeof(char)*strlen(string));
	strcpy(result->expr_string,string);
	result->left_chld = NULL;
	result->list = NULL;
	result->next = NULL;
	result->right_chld = NULL;

	return result;
}

/*!
	Функция создания выражения операции.
  \param type Тип операции.
  \param left Левый операнд.
  \param right Правый операнд.
  \return указатель на объект выражения.
*/
struct VB_Expr* create_operator_expr(enum VB_Expr_type type,
									 struct VB_Expr* left,
									 struct VB_Expr* right)
{
	struct VB_Expr* result = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));

	result->expr_string = "???";

	result->type = type;
	result->left_chld = left;
	result->right_chld = right;
	result->list = NULL;
	result->next = NULL;

	return result;
}

/*!
	Функция создания выражения объявления переменных.
  \param list Определяемые переменные.
  \return указатель на объект выражения.
*/
struct VB_Dim_stmt* create_dim_stmt(struct VB_As_Expr_list* list)
{
	struct VB_Dim_stmt* dim_stmt = (struct VB_Dim_stmt*)malloc(sizeof(struct VB_Dim_stmt));

	dim_stmt->list = list;
	dim_stmt->next = NULL;


	return dim_stmt;
}

/*!
	Функция создания списка последовательности определения переменныхх.
  \param expr Создается определение переменной.
  \param arr Создается определение массива.
  \return указатель на объект выражения.
*/
struct VB_As_Expr_list* create_as_expr_list(struct VB_As_expr* expr, struct VB_Array_expr* arr)
{
	struct VB_As_Expr_list* as_list = (struct VB_As_Expr_list*)malloc(sizeof(struct VB_As_Expr_list));

	as_list->as_expr = expr;
	as_list->arr = arr;
	as_list->next = NULL;

	return as_list;
}

/*!
	Функция добавление переменной в список последовательности определения переменныхх.
  \param list Текущий список
  \param expr Доавляемое выражение
  \param arr Добавляемый массив
  \return указатель на объект выражения.
*/
struct VB_As_Expr_list* add_to_as_expr_list(struct VB_As_Expr_list* list, struct VB_As_expr* expr,
											struct VB_Array_expr* arr)
{
	struct VB_As_Expr_list* new_item = (struct VB_As_Expr_list*)malloc(sizeof(struct VB_As_Expr_list));
	
	new_item->as_expr = expr;
	new_item->arr = arr;
	new_item->next = NULL;

	list->next = new_item;

	return list;
}

struct VB_As_expr* create_as_expr(enum VB_As_expr_type type, struct VB_Id_list* list, char* id, enum VB_Id_type id_type, struct VB_Expr* expr)
{
	struct VB_As_expr* as_expr = (struct VB_As_expr*)malloc(sizeof(struct VB_As_expr));
	list->counter = 1;
	as_expr->type = type;
	as_expr->id_type = id_type;

	if (list->counter>1)
	{
		as_expr->list = list;
		as_expr->expr = NULL;
		as_expr->id = NULL;
	}
	else
	{
		as_expr->expr = NULL;
		as_expr->id = expr;
		as_expr->list = list;
		//strcpy(as_expr->id->expr_string,id);
	}

	return as_expr;
}

/*!
	Создание списка идентификаторов.
  \param id Идентификатор
  \return указатель на объект выражения.
*/
struct VB_Id_list* create_id_list(char* id)
{
	struct VB_Id_list* list = (struct VB_Id_list*)malloc(sizeof(struct VB_Id_list));

	list->id = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));

	list->id->list = NULL;
	list->id->next = NULL;
	list->id->expr_string = id;
	list->next = NULL;
	list->id->left_chld = NULL;
	list->id->right_chld = NULL;
	list->counter = 1; /* change init 0 to 1 */
	return list;
}

/*!
	Добавить элемент в список идентификаторов.
  \param id Идентификатор
  \return указатель на объект выражения.
*/
struct VB_Id_list* add_to_id_list(struct VB_Id_list* list,char* id)
{
	struct VB_Id_list* new_list = (struct VB_Id_list*)malloc(sizeof(struct VB_Id_list));
	struct VB_Id_list* last_list = list;
	new_list->id = (struct VB_Expr*)malloc(sizeof(struct VB_Expr*));

	//new_list->id = create_id_expr(id);
	new_list->id->expr_string = (char*)malloc(sizeof(char)*strlen(id));
	strcpy(new_list->id->expr_string,id);
	new_list->next = NULL;
	new_list->id->left_chld = NULL;
	new_list->id->list = NULL;
	new_list->id->next = NULL;
	new_list->id->right_chld = NULL;

	do
	{
		if (last_list->next)
			last_list = last_list->next;
		else
		{
			last_list->next = new_list;
			break;
		}
	}
	while (last_list);

	//list->next = new_list;
	list->counter++;
	return list;
}

/*!
	Создать процедуру (Sub)
  \param id Идентификатор
  \param params Список параметров
  \param body Тело процедуры
  \return указатель на объект процедуры.
*/
struct VB_Sub_stmt * create_sub_stmt(char * id, struct VB_Param_list * params, struct VB_Stmt_list * body)
{
	struct VB_Sub_stmt* result = (struct VB_Sub_stmt*)malloc(sizeof(struct VB_Sub_stmt));

	result->id = id;
	result->next = NULL;
	result->param_list = params;
	result->stmt_list = body;

    return result;
}

/*!
	Создать список параметров процедуры
  \param id Идентификатор
  \return указатель на объект списка параметров.
*/
struct VB_Param_list * create_param_list(struct VB_Param_stmt* first_param)
{
	struct VB_Param_list* result = (struct VB_Param_list*)malloc(sizeof(struct VB_Param_list));

	result->first = first_param;
	result->last = first_param;

    return result;
}

/*!
	Добавить список параметров процедуры
  \param id Идентификатор
  \return указатель на объект списка параметров.
*/
struct VB_Param_list *add_to_param_list(struct VB_Param_list* list, struct VB_Param_stmt* new_param )
{
	list->last->next = new_param;
	list->last = new_param;

    return list;
}

/*!
	Создать объект параметра
  \param id Идентификатор
  \param type Тип параметра
  \return указатель на объект параметра.
*/
struct VB_Param_stmt* create_param_stmt(char* id, enum VB_Id_type type)
{
	struct VB_Param_stmt* result = (struct VB_Param_stmt*)malloc(sizeof(struct VB_Param_stmt));
	result->id = (char*)malloc(sizeof(char)*strlen(id));

	strcpy(result->id,id);
	result->id_type = type;
	result->next = NULL;

    return result;
}

/*!
	Создать выражение For:
	" For i = 0 To 10
		действия
	  Next"

  \param id Итератор
  \param start Начальное значение
  \param end Конечное значение
  \param body Тело цикла
  \return указатель на объект For.
*/
struct VB_For_stmt * create_for_stmt(char* id, int start, int end, struct VB_Stmt_list* body)
{
	struct VB_For_stmt* result = (struct VB_For_stmt*)malloc(sizeof(struct VB_For_stmt));

	result->type = SIMPLE;
	result->id = (char*)malloc(sizeof(char)*strlen(id));
	strcpy(result->id,id);
	result->from_val = start;
	result->to_val = end;
	result->step_val = 1;
	result->stmt_list = body;
	result->next = NULL;
	result->new_id = NULL;

    return result;
}

/*!
	Создать выражение For:
	" For i = 0 To 10 Step 2
		действия
	  Next"

  \param id Итератор
  \param start Начальное значение
  \param end Конечное значение
  \param step Шаг итератора
  \param body Тело цикла
  \return указатель на объект For.
*/
struct VB_For_stmt * create_for_with_step_stmt(char* id, int start, int end, int step, struct VB_Stmt_list* body)
{
	struct VB_For_stmt* result = (struct VB_For_stmt*)malloc(sizeof(struct VB_For_stmt));

	result->type = WITH_STEP;
	result->id = (char*)malloc(sizeof(char)*strlen(id));
	strcpy(result->id,id);
	result->from_val = start;
	result->to_val = end;
	result->step_val = step;
	result->stmt_list = body;
	result->next = NULL;
	result->new_id = NULL;

    return result;
}

/*!
	Создать выражение For:
	" For i As Integer = 0 To 10
		действия
	  Next"

  \param id Итератор
  \param Тип итератора
  \param start Начальное значение
  \param end Конечное значение
  \param body Тело цикла
  \return указатель на объект For.
*/
struct VB_For_stmt * create_for_with_decl_stmt(char* id, enum VB_Id_type type, int start, int end, struct VB_Stmt_list* body)
{
	struct VB_For_stmt* result = (struct VB_For_stmt*)malloc(sizeof(struct VB_For_stmt));

	result->type = WITH_DECL;
	result->new_id = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));
	result->id = (char*)malloc(sizeof(char)*2);
	strcpy(id,"!\0");

	result->new_id->list = NULL;
	result->new_id->expr_string = (char*)malloc(sizeof(char)*strlen(id));
	strcpy(result->new_id->expr_string,id);
	result->new_id->left_chld = NULL;
	result->new_id->right_chld = NULL;
	result->new_id->next = NULL;
	result->new_id->id_type = type;
	result->from_val = start;
	result->to_val = end;
	result->step_val = 1;
	result->stmt_list = body;
	result->next = NULL;

    return result;
}

/*!
	Создать выражение For:
	" For i As Integer = 0 To 10 Step 2
		действия
	  Next"

  \param id Итератор
  \param Тип итератора
  \param start Начальное значение
  \param end Конечное значение
  \param step Шаг итератора
  \param body Тело цикла
  \return указатель на объект For.
*/
struct VB_For_stmt * create_for_with_decl_with_step_stmt(char* id, enum VB_Id_type type, int start, int end, int step, struct VB_Stmt_list* body)
{
	struct VB_For_stmt* result = (struct VB_For_stmt*)malloc(sizeof(struct VB_For_stmt));

	result->type = WITH_DECL_AND_STEP;
	result->new_id = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));


	result->new_id->list =NULL;
	strcpy(result->new_id->expr_string,id);
	result->new_id->type = type;
	result->from_val = start;
	result->to_val = end;
	result->step_val = step;
	result->stmt_list = body;
	result->next = NULL;
	result->new_id->left_chld = NULL;


    return result;
}

/*!
	Создать выражение While:
	" While counter < 20
		counter += 1
	  End While"
  \param expr Условие
  \param body Тело цикла
  \return указатель на объект While.
*/
struct VB_While_stmt * create_while_stmt(struct VB_Expr* expr, struct VB_Stmt_list* body)
{
	struct VB_While_stmt* result = (struct VB_While_stmt*)malloc(sizeof(struct VB_While_stmt));

	result->expr = expr;
	result->stmt_list = body;
	result->next = NULL;

    return result;
}

/*!
	Создать выражение Do..Loop..Until:
	"Do Until number = 10
        number += 1
    Loop"

  \param expr Условие
  \param body Тело цикла
  \return указатель на объект Do..Loop..Until.
*/
struct VB_Do_loop_stmt * create_do_loop_stmt(enum VB_Do_loop_type type, struct VB_Expr* expr, struct VB_Stmt_list* body)
{
	struct VB_Do_loop_stmt* result = (struct VB_Do_loop_stmt*)malloc(sizeof(struct VB_Do_loop_stmt));

	result->type = type;
	result->expr = expr;
	result->stmt_list = body;
	result->next = NULL;

    return result;
}

/*!
	Создать выражение Enum:
	"Enum filePermissions
		create = 1
		read = 2
		write = 4
		delete = 8
	End Enum"

  \param id имя перечисления
  \param list Список элементов
  \return указатель на объект Enum.
*/
struct VB_Enum_stmt * create_enum_stmt(char* id, struct VB_Enum_expr_list* list)
{
	struct VB_Enum_stmt* result = (struct VB_Enum_stmt*)malloc(sizeof(struct VB_Enum_stmt));

	strcpy(result->id,id);
	result->list = list;
	result->next = NULL;

    return result;
}

/*!
	Создать список элементов перечисления
  \param first_expr Первый элемент списка
  \return указатель на объект списка.
*/
struct VB_Enum_expr_list * create_enum_list(struct VB_Enum_expr* first_expr)
{
	struct VB_Enum_expr_list* result = (struct VB_Enum_expr_list*)malloc(sizeof(struct VB_Enum_expr_list));

	result->first = first_expr;
	result->last = first_expr;

    return result;
}

/*!
	Добавить элемент перечисления в список
  \param first_expr Первый элемент списка
  \return указатель на объект списка.
*/
struct VB_Enum_expr_list * add_to_enum_list(struct VB_Enum_expr_list* list, struct VB_Enum_expr* new_expr)
{
	list->last->next = new_expr;
	list->last = new_expr;

    return list;
}

/*!
	Создать элемент перечисления number>0 && number<MAX_INT (в Java) && number_N != number_M
  \param first_expr Первый элемент списка
  \return указатель на элемент Enum.
*/
struct VB_Enum_expr * create_enum_expr(char* id, int number)
{
	struct VB_Enum_expr* result = (struct VB_Enum_expr*)malloc(sizeof(struct VB_Enum_expr));

	strcpy(result->id,id);
	result->next = NULL;

	if (number >= 0)
	{
		result->is_init = 1;
		result->value = number;
	}

    return result;
}

struct VB_Func_stmt * create_func_stmt(char* id, struct VB_Param_list* params, enum VB_Id_type type,
									   struct VB_Stmt_list* body)
{
	struct VB_Func_stmt* result = (struct VB_Func_stmt*)malloc(sizeof(struct VB_Func_stmt));
	result->id = (char*)malloc(sizeof(char)*strlen(id));

	strcpy(result->id,id);
	result->id_type = type;
	result->param_list = params;
	result->stmt_list = body;
	result->next = NULL;
	result->expr = NULL;

    return result;
}
