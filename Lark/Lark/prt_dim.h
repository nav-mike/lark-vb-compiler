//
//

#ifndef H_PRT_DIM
#define H_PRT_DIM

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
	struct  VB_Expr_list*	expr_list;
	//struct 	VB_Expr*		id;			//!< Идентификатор
};

/*! \struct VB_Id_list
    Список идентификаторов.
 */
struct VB_Id_list
{
	int counter;
	struct VB_Expr* id;					//!< Имя текущего идентификатора
	struct VB_Array_expr * arr;		//!< Массив
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
	result->size = 0;

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
struct VB_As_Expr_list* create_as_expr_list(struct VB_As_expr* expr)
{
	struct VB_As_Expr_list* as_list = (struct VB_As_Expr_list*)malloc(sizeof(struct VB_As_Expr_list));

	as_list->as_expr = expr;
	as_list->next = NULL;
	as_list->type = EXPR;

	return as_list;
}

/*!
	Функция добавление переменной в список последовательности определения переменныхх.
  \param list Текущий список
  \param expr Доавляемое выражение
  \param arr Добавляемый массив
  \return указатель на объект выражения.
*/
struct VB_As_Expr_list* add_to_as_expr_list(struct VB_As_Expr_list* list, struct VB_As_expr* expr)
{
	struct VB_As_Expr_list* new_item = (struct VB_As_Expr_list*)malloc(sizeof(struct VB_As_Expr_list));
	struct VB_As_Expr_list* lastList = list;

	new_item->as_expr = expr;
	new_item->next = NULL;
	new_item->type = EXPR_LIST;

	list->type = EXPR_LIST;

	while (lastList->next != NULL){
		lastList = lastList->next;
	}

	lastList->next = new_item;


	return list;
}

/*!
	Создание списка идентификаторов.
  \param id Идентификатор
  \return указатель на объект выражения.
*/
struct VB_Id_list* create_id_list(char* id, int isArray, int size)
{
	struct VB_Id_list* list = (struct VB_Id_list*)malloc(sizeof(struct VB_Id_list));

	if (isArray == NULL) {

		// Создаем одну переменную
		list->id = create_expr_with_id(id);
		
		list->arr = NULL;
	}
	else {
		// Создаем одну переменную
		list->arr = (struct VB_Array_expr*)malloc(sizeof(struct VB_Array_expr));

		// Копируем имя
		list->arr->id = (char*)malloc(sizeof(char)*strlen(id));
		strcpy(list->arr->id,id);

		list->arr->id_type = DATA_INTEGER;
		list->arr->is_init = 0;
		list->arr->size = size;
		list->arr->list = NULL;

		list->id = NULL;
	}

	list->next = NULL;
	list->counter = 1; /* change init 0 to 1 */	
	
	return list;
}

struct VB_As_Expr* create_as_expr_id(char* id,struct VB_Id_list* list,enum VB_Id_type id_type){

	struct VB_As_expr* as_expr = (struct VB_As_expr*)malloc(sizeof(struct VB_As_expr));
	
	as_expr->expr = NULL;
	as_expr->expr_list = NULL;

	as_expr->list = create_id_list(id,0,0);

	as_expr->list->id->id_type = id_type;

	as_expr->id_type = id_type;
	
	as_expr->type = ID_LIST;

	as_expr->list->next = list;

	return as_expr;
}



struct VB_As_Expr* create_as_expr_arr(char* id, int size, struct VB_Id_list* list,enum VB_Id_type id_type){

	struct VB_As_expr* as_expr = (struct VB_As_expr*)malloc(sizeof(struct VB_As_expr));
	
	as_expr->expr = NULL;
	as_expr->expr_list = NULL;

	as_expr->list = create_id_list(id,1,size);

	as_expr->list->arr->id_type = id_type;

	as_expr->id_type = id_type;
	
	as_expr->type = ID_LIST;

	as_expr->list->next = list;

	return as_expr;
}






struct VB_As_expr* create_as_expr_init(char* id, enum VB_Id_type id_type, struct VB_Expr* expr)
{
	struct VB_As_expr* as_expr = (struct VB_As_expr*)malloc(sizeof(struct VB_As_expr));
	
	as_expr->expr = expr;
	as_expr->expr_list = NULL;
	as_expr->list = create_id_list(id,0,0);
	//as_expr->id = create_expr_with_id(id);
	as_expr->list->id->id_type = id_type;

	as_expr->id_type = id_type;
	
	if (expr != NULL)
		as_expr->type = ID_INIT;
	else
		as_expr->type = ONE_ID;

	return as_expr;
}

struct VB_As_expr* create_as_array(char* id, int size, enum VB_Id_type id_type)
{
	struct VB_As_expr* as_expr = (struct VB_As_expr*)malloc(sizeof(struct VB_As_expr));
	as_expr->expr = NULL;
	as_expr->expr_list = NULL;

	as_expr->list = create_id_list(id,1,size);
	as_expr->list->arr->id_type = id_type;
	as_expr->list->arr->list = NULL;

	as_expr->id_type = id_type;
	
	as_expr->type = ONE_ID;

}

struct VB_As_expr* create_as_array_init(char* id, enum VB_Id_type id_type, struct VB_Expr_list* list)
{
	int k = 0;
	struct VB_Expr* buf = list->first;
	struct VB_As_expr* as_expr = (struct VB_As_expr*)malloc(sizeof(struct VB_As_expr));
	as_expr->expr = NULL;
	//as_expr->expr_list = list;
as_expr->expr_list = NULL;

	
	

	while (buf!=NULL){
		k++;
		buf = buf->next;
	}


	as_expr->list = create_id_list(id,1,k);
	as_expr->list->arr->id_type = id_type;
	as_expr->list->arr->list = list;

	as_expr->id_type = id_type;
	
	as_expr->type = ID_INIT;

}





/*!
	Добавить элемент в список идентификаторов.
  \param id Идентификатор
  \return указатель на объект выражения.
*/
struct VB_Id_list* add_to_id_list(struct VB_Id_list* list, char* id, int isArray, int size)
{
	struct VB_Id_list* new_list = create_id_list(id,isArray,size);
	struct VB_Id_list* last_list = list;

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

	new_list->counter = ++(list->counter);

	return list;
}



#endif // H_PRT_DIM