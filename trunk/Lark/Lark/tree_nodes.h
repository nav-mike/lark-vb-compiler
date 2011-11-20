//
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*! \struct VB_Module_stmt
    ��������� ������ ��� �������� ����� ������.
 */
struct VB_Module_stmt
{
	char* id;                       //!< ������������� ������
	struct VB_Stmt_list* stmt_list; //!< ������ �������� ������
};

/*! \struct VB_Stmt_list
    ���������, ����������� ������ ��������.
 */
struct VB_Stmt_list
{
	struct VB_Stmt* first;		//!< ��������� �� ������ ������� ������
	struct VB_Stmt* last;		//!< ��������� �� ��������� ������� ������
};

/*! \struct VB_Stmt
    ���������, ����������� ��������.
 */
struct VB_Stmt
{
	enum VB_Stmt_type	      type;	          //!< ��� ��������.
	struct VB_Expr*		      expr;	          //!< ��������� �� ������������ � �������� ���������.
	struct VB_If_stmt*        if_stmt;        //!< ��������� �� ������������ � �������� �������.
	struct VB_Dim_stmt*       dim_stmt;       //!< ��������� �� ������������ � �������� �������������.
	struct VB_For_stmt*       for_stmt;       //!< ��������� �� ������������ � �������� ����.
	struct VB_While_stmt*     while_stmt;     //!< ��������� �� ������������ � �������� ����.
	struct VB_Do_Loop_stmt*   do_loop_stmt;   //!< ��������� �� ������������ � �������� ����.
	struct VB_Enum_stmt*      enum_stmt;      //!< ��������� �� ������������ � �������� ������������.
	struct VB_Sub_stmt*       sub_stmt;       //!< ��������� �� ������������ � �������� ���������.
	struct VB_Func_stmt*      func_stmt;      //!< ��������� �� ������������ � �������� �������.
	struct VB_Try_Catch_stmt* try_catch_stmt; //!< ��������� �� ������������ � �������� ����� � ��������� ����������.
	struct VB_Throw_stmt*     throw_stmt;     //!< ��������� �� ������������ � �������� ������ ����������.
	struct VB_Print_stmt*     print_stmt;     //!< ��������� �� ������������ � �������� ������ �������.
	struct VB_Println_stmt*   println_stmt;   //!< ��������� �� ������������ � �������� ������ ������.
	struct VB_Read_stmt*      read_stmt;      //!< ��������� �� ������������ � �������� ���������� �������.
	struct VB_Readln_stmt*    readln_stmt;    //!< ��������� �� ������������ � �������� ���������� ������.
	struct VB_Readkey_stmt*   readkey_stmt;   //!< ��������� �� ������������ � �������� ���������� ������� �������.
	struct VB_Stmt*		      next;	          //!< ��������� �� ��������� ������� ������������������ ����������.
};

/*! \enum VB_Type_of_expr
    ������������ ����� ��������. 
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
    ���������, ����������� ������ ���������.
 */
struct VB_Expr_list
{
	struct VB_Expr* first;  //!< ��������� �� ������ ������� ������
	struct VB_Expr* last;   //!< ��������� �� ��������� ������� ������
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
	struct VB_Expr_list list;			//!< ��������� ��������� ��� �������
	
	enum VB_Id_type		id_type;		//!< ��� �������������� 	????
};

/*! \enum VB_Type_of_expr
    ������������ ����� ���������. 
 */
enum VB_Expr_type
{
	ID,				//!< �������������
	EXPR_FUNC,			//!< ��������� ��� �������
	CHAR_CONST,		//!< ���������� ���������
	INT_CONST,		//!< ������������� ���������
	STRING_CONST,	//!< ��������� ���������
	BOOLEAN_CONST,	//!< ������� ���������
	ASSIGN,			//!< �������� ������������
	PLUS,			//!< �������� ��������
	MINUS,			//!< �������� ���������
	MUL,			//!< �������� ���������
	INT_DIV,		//!< �������� �������������� �������
	DIV,			//!< �������� �������
	POWER,			//!< �������� ���������� � �������
	MORE,			//!< �������� "������"
	LESS,			//!< �������� "������"
	MORE_OR_EQUAL,	//!< �������� "������ ��� �����"
	LESS_OR_EQUAL,	//!< �������� "������ ��� �����"
	NONEQUAL,		//!< �������� "�������"
	EQUAL,			//!< �������� "�����"
	UMINUS,			//!< �������� �������� ������
	UPLUS,			//!< �������� �������� �����
	GET_ITEM		//!< ��������� �������� �������
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

/*! \struct VB_End_if_stmt
    ��������� ������ ��� �������� ������ ����� ��������� ��������� ��������.
 */
struct VB_End_if_stmt
{
	enum VB_End_if_stmt_type 	type;		//!< ��� ��������� ���������
	struct VB_Stmt_list*		stmt_list;	//!< ��������� �� ������ �������� ��� �������� �������.
	struct VB_Expr*				expr;		//!< �������
	struct VB_End_if_stmt*		end_stmt;	//!< ��������� �� ������ �������� ��� ������ ������� �������.
	struct VB_Stmt*				next;		//!< ��������� �� ��������� ������� ������������������ ����������.
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

/*! \struct VB_Dim_stmt
    ���������, ����������� �������� ���������� ����������.
 */
struct VB_Dim_stmt
{
	struct VB_As_Expr_list* list;		//!< ��������� �� ������� ������ ����������� ����������
	struct VB_Stmt*			next;		//!< ��������� ��������
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

/*! \enum VB_As_Stmt_list
    ������������, ���������� ��� ������ ������������������ ����������� ����������
 */
enum VB_As_Expr_list_type
{
	EXPR,		//!< ������������ �������������
	ARRAY,		//!< ������������ ������
	EXPR_LIST,	//!< ������������ ������ ���������������
	EXPR_ARR	//!< ������������ ������ ��������
};

/*! \struct VB_As_stmt
    ��������� ������ ��� �������� ����������� ���������� ������ ����.
 */
struct VB_As_expr
{ 
	enum	VB_As_expr_type	type;		//!< ��� 
	struct	VB_Id_list*		list;		//!< ������ ���������������
	enum	VB_Id_type		id_type;	//!< ��� ������������� ��������������
	struct	VB_Expr*		expr;		//!< ���������������� ��������
	struct 	VB_Expr*		id;			//!< �������������
};

enum VB_As_expr_type
{
	ID_LIST,	//!< ������ ���������������
	ONE_ID,		//!< ���� ������������
	ID_INIT		//!< ������������������ �������������
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

/*! \struct VB_Id_list
    ������ ���������������.
 */
struct VB_Id_list
{
	struct VB_Expr* id;					//!< ��� �������� ��������������
	struct VB_Id_list* next;	//!� ��������� �� ��������� �������������
};

/*! \struct VB_Array_expr
    ���������, �������� ������ ��� ����������� �������.
 */
struct VB_Array_expr
{
	int is_init;				//!< ���������������� �� ������.
	int size;					//!< ������ �������
	enum VB_Id_type	id_type;	//!< ��� ������������� �������������� ��� ������
	struct VB_Expr_list list;	//!< ������, �������� ����������� ������
	struct VB_Expr*	id;			//!< �������������		???	
};

/*! \struct VB_For_stmt
    ���������, ����������� �������� ����� For.
 */
struct VB_For_stmt
{
	struct VB_Expr*		 id;			//!< �������������
	int 				 from_val;		//!< ������ �������		
	int 				 to_val;		//!< ����� ������
	int 				 step_val;		//!< ���
	struct VB_Stmt_list* stmt_list;		//!< ���� �����
	struct VB_Stmt*		 next;			//!< ��������� ��������
};

/*! \struct VB_While_stmt
    ���������, ����������� �������� ����� While.
 */
struct VB_While_stmt
{
	struct VB_Stmt_list* stmt_list;	//!< ���� �����
	struct VB_Expr*		 expr;		//!< �������
	struct VB_Stmt*		 next;		//!< ��������� ��������
};

/*! \struct VB_Do_loop_stmt
    ���������, ����������� �������� ����� Do...Loop.
 */
struct VB_Do_loop_stmt
{
	enum VB_Do_loop_type type;		//!< ���
	struct VB_Stmt_list* stmt_list;	//!< ���� �����
	struct VB_Expr*		 expr;		//!< �������
	struct VB_Stmt*		 next;		//!< ��������� ��������
};

/*! \struct VB_Do_loop_type
    ��� ����� Do...Loop.
 */
enum VB_Do_loop_type
{
	DO_WHILE,
	DO_UNTIL,
	LOOP_WHILE,
	LOOP_UNTIL
};

/*! \struct VB_Enum_stmt
    ���������, ����������� ������������ Enum
 */
struct VB_Enum_stmt
{
	char*		 			  id;		//!< ��� ����
	struct VB_Enum_expr_list* list;		//!< ������ �����
	struct VB_Stmt*			  next;		//!< ��������� ��������
};

/*! \struct VB_Enum_expr_list
    ������� ������ ��������� Enum
 */
struct VB_Enum_expr_list
{
	struct VB_Enum_expr*	first;	//!< ��������� �� ������ ������� ������
	struct VB_Enum_expr*	last;	//!< ��������� �� ��������� ������� ������
};

/*! \struct VB_Enum_expr
    ������� ������������ Enum
 */
struct VB_Enum_expr
{
	int 				 is_init;	//!< ���������������� ��				
	char*				 id;		//!< ���
	int					 value;		//!< ��������
	struct VB_Enum_expr* next;		//!< ��������� �������
};

/*! \struct VB_Sub_stmt
    ���������
 */
struct VB_Sub_stmt
{
	int 					has_params;	//!< ���� �� ���������
	char*		 			id;			//!< ��� ����
	struct VB_Param_list*	param_list;	//!< ������ ����������
	struct VB_Stmt_list* 	stmt_list;	//!< ���� ���������
	struct VB_Stmt*			next;		//!< ��������� ��������
};

/*! \struct VB_Param_list
    ������ ���������� ���������
 */
struct VB_Param_list
{
	struct VB_Param_stmt* first;	//!< ��������� �� ������ ������� ������
	struct VB_Param_stmt* last;		//!< ��������� �� ��������� ������� ������
};

/*! \struct VB_Param_stmt
    �������� ���������
 */
struct VB_Param_stmt
{
	int  is_by_ref;			//!< �������� �� ������
	char* id;					//!< ��� ��������
	enum VB_Id_type	id_type;	//!< ��� ���������
	struct VB_Param_stmt* next;	//!< ��������� 
};

/*! \struct VB_Func_stmt
    �������
 */
struct VB_Func_stmt
{
	char* id;						//!< ��� �������
	enum VB_Id_type	id_type;		//!< ��� ������������� ��������
	struct VB_Stmt_list* stmt_list;	//!< ���� ���������
	struct VB_Expr*	expr;			//!< ������������ ��������
	struct VB_Param_list*	param_list;	//!< ������ ����������
	struct VB_Stmt*			next;		//!< ��������� ��������
};

/*! \struct VB_Try_catch_stmt
    Try...cath
 */
struct VB_Try_catch_stmt
{
	struct VB_Stmt_list* stmt_list;		//!< ������������� ���
	struct VB_Stmt_list* fin_stmt_list;	//!< 
	struct VB_Stmt*		 next;			//!< ��������� ��������
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
   ������������� ����������
 */
struct VB_Throw_stmt
{
	char* 			string;		//!< ������
	struct VB_Stmt*	next;		//!< ��������� ��������
};

/** ������� ������������� ��������. */

/* ������������� ������:
	module_stmt: MODULE ID ENDL stmt_list END_MODULE ENDL ;
*/
/*!
	������� �������� ���� ������: ������.
  \param id ��� ������.
  \param list ������ ��������� ������.
  \return ����� ������.
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

/* ������������� ������ ��������:
	stmt_list: stmt
		 | stmt_list stmt ;
*/
/*!
	������� �������� ���� ������: ������ ��������.
  \param stmt ��������.
  \return ����� ������ ��������.
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
	������� ��������� ���� ������: ���������� � ������ ��������� ��������.
  \param list ������ ��������.
  \param stmt ��������.
  \return ����� ������ ��������.
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

/* ������������� ���������:
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
	������� �������� �������� �� ���������.
  \param expr ���������.
  \return ����� ��������.
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
	������� �������� �������� �� �������� ��������.
  \param if_stmt �������� ��������.
  \return ����� ��������.
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
	������� �������� �������� �� ������������� ����������.
  \param dim_stmt ������������� ���������.
  \return ����� ��������.
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
	������� �������� �������� �� �����.
  \param for_stmt ����.
  \return ����� ��������.
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
	������� �������� �������� �� �����.
  \param while_stmt ����.
  \return ����� ��������.
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
	������� �������� �������� �� �����.
  \param do_loop_stmt ����.
  \return ����� ��������.
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
	������� �������� �������� �� ������������.
  \param enum_stmt ������������.
  \return ����� ��������.
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
	������� �������� �������� �� ���������.
  \param sub_stmt ���������.
  \return ����� ��������.
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
	������� �������� �������� �� �������.
  \param func_stmt �������.
  \return ����� ��������.
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
	������� �������� �������� �� ����������.
  \param try_catch_stmt ����������.
  \return ����� ��������.
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
	������� �������� �������� �� ������ �������.
  \param print_stmt ������ �������.
  \return ����� ��������.
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
	������� �������� �������� �� ������ ������.
  \param println_stmt ������ ������.
  \return ����� ��������.
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
	������� �������� �������� �� ������ ������.
  \param readln_stmt ������ ������.
  \return ����� ��������.
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