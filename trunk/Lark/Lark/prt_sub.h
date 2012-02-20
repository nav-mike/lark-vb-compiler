//
//

#ifndef H_PRT_SUB
#define H_PRT_SUB


/*! \struct VB_Sub_stmt
    Процедура
 */
struct VB_Sub_stmt
{
	char*		 			id;			//!< Имя поля
	struct VB_Param_list*	param_list;	//!< Список параметров
	struct VB_Stmt_list* 	stmt_list;	//!< Тело процедуры
	struct VB_Stmt*			next;		//!< Следующий оператор
	       int              line_number; //!< Line of this statement.
};

/*! \struct VB_Param_list
    Список параметров процедуры
 */
struct VB_Param_list
{
	struct VB_Param_stmt* first;	//!< Указатель на первый элемент списка
	struct VB_Param_stmt* last;		//!< Указатель на последний элемент списка
	       int            line_number; //! Line of this statement.
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
	       int            line_number; //!< Line of this statement.
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
	int					    line_number; //!< Line of this statement.

	int is_array_return;


};


struct VB_Func_stmt * create_func_stmt(char* id, struct VB_Param_list* params, enum VB_Id_type type,
									   struct VB_Stmt_list* body, int is_array_ret)
{
	struct VB_Func_stmt* result = (struct VB_Func_stmt*)malloc(sizeof(struct VB_Func_stmt));
	result->id = (char*)malloc(sizeof(char)*strlen(id));

	strcpy(result->id,id);
	result->id_type = type;
	result->param_list = params;
	result->stmt_list = body;
	result->next = NULL;
	result->expr = NULL;
	result->line_number = get_location();
	result->is_array_return = is_array_ret;
    return result;
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
	result->line_number = get_location();

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
	result->line_number = get_location();

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
struct VB_Param_stmt* create_param_stmt(int is_by_ref, char* id, enum VB_Id_type type)
{
	struct VB_Param_stmt* result = (struct VB_Param_stmt*)malloc(sizeof(struct VB_Param_stmt));
	result->id = (char*)malloc(sizeof(char)*strlen(id));

	strcpy(result->id,id);
	result->id_type = type;
	result->next = NULL;
	result->is_by_ref = is_by_ref;
	result->line_number = get_location();

    return result;
}

#endif // H_PRT_SUB