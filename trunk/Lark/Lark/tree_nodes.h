//
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long int Number = 0;

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
	struct VB_Do_loop_stmt*   do_loop_stmt;   //!< ��������� �� ������������ � �������� ����.
	struct VB_Enum_stmt*      enum_stmt;      //!< ��������� �� ������������ � �������� ������������.
	struct VB_Sub_stmt*       sub_stmt;       //!< ��������� �� ������������ � �������� ���������.
	struct VB_Func_stmt*      func_stmt;      //!< ��������� �� ������������ � �������� �������.
	struct VB_Try_catch_stmt* try_catch_stmt; //!< ��������� �� ������������ � �������� ����� � ��������� ����������.
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
	enum VB_Expr_type	 type;			//!< ��� ���������.
	char*				 expr_string;	//!< ��� ��������������, ���� ������.
	int					 int_val;		//!< �������� ���������. ������������ ��� bool, int, char.
	struct VB_Expr*		 left_chld;		//!< ��������� �� ������ ����.
	struct VB_Expr*		 right_chld;		//!< ��������� �� ������� ����.
	struct VB_Expr_list* list;			//!< ��������� ��������� ��� �������
	struct VB_Expr*      next;           //!< ��������� �� ����������, ��� Expr_list.
	
	enum VB_Id_type		id_type;		//!< ��� �������������� 	????
};

/*! \enum VB_Type_of_expr
    ������������ ����� ���������. 
 */
enum VB_Expr_type
{
	ID,				//!< �������������
	EXPR_FUNC,		//!< ��������� ��� �������
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
	GET_ITEM,		//!< ��������� �������� �������
	BRK_EXPR		//!< ��������� �� ��������
};

/*! \struct VB_If_stmt
    ��������� ������ ��� �������� ��������� ��������� ��������.
 */
struct VB_If_stmt
{
	enum   VB_If_stmt_type  type;		//!< ��� ��������� ���������
	struct VB_Expr*			expr;		//!< �������
	struct VB_Stmt_list*	stmt_list;	//!< ��������� �� ������ �������� ��� �������� �������.
	struct VB_Stmt_list*	else_list;	//!< ��������� �� ������ �������� ��� ������ ������� (������ ���� � 1 ������).
	struct VB_End_if_stmt*	end_stmt;	//!< ��������� �� ������ �������� ��� ������ �������.
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
	struct VB_End_if_stmt*		end_stmt;	//!< ��������� �� ������ �������� ��� ������ �������.
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
	ARR_LIST	//!< ������������ ������ ��������
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
	struct VB_Expr_list* list;	//!< ������, �������� ����������� ������
	struct VB_Expr*	id;			//!< �������������		???	
};

/*! \struct VB_For_stmt_type
    ��� ����� For.
 */
enum VB_For_stmt_type
{
	SIMPLE,
	WITH_DECL,
	WITH_STEP,
	WITH_DECL_AND_STEP
};

/*! \struct VB_For_stmt
    ���������, ����������� �������� ����� For.
 */
struct VB_For_stmt
{
	enum VB_For_stmt_type type;			//!< ��� �������� For
	char*				 id;			//!< �������������
	int 				 from_val;		//!< ������ �������		
	int 				 to_val;		//!< ����� ������
	int 				 step_val;		//!< ���
	struct VB_Stmt_list* stmt_list;		//!< ���� �����
	struct VB_Stmt*		 next;			//!< ��������� ��������
	struct VB_Expr*		 new_id;		//!< ���� ���������� ��������� ��� �����
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

/*! \struct VB_Print_stmt
	��������� � ����������� ����� ������.
*/
struct VB_Print_stmt
{
	char* text; //!< ����� ���������.
};

/*! \struct VB_Println_stmt
	��������� � ��������� ������ � ����������� ����� ������.
*/
struct VB_Println_stmt
{
	char* text; //!< ����� ���������.
};

/*! \struct VB_Read_stmt
	���������� ������� �� ������������ ������.
*/
struct VB_Read_stmt
{
	char symbol;
};

/*! \struct VB_Readln_stmt
	���������� ������ �� ������������ ������.
*/
struct VB_Readln_stmt
{
	char* text;
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
	struct VB_Stmt_list*       stmt_list;		//!< ������������� ���
	struct VB_Stmt_list*       fin_stmt_list;	//!< 
	struct VB_Stmt*		       next;			//!< ��������� ��������
	struct VB_Catch_stmt_list* catch_list;      //!< ���� ���� ������������ ����������.
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
	������� �������� stmt � ���������� ��� �����.
  \param type ��� stmt.
  \param data ������ ��� ���������� �����.
  \return stmt.
*/
struct VB_Stmt* fill_stmt(enum VB_Stmt_type type, void* data)
{
	struct VB_Stmt* stmt = NULL;

	if (data != NULL)
	{
		stmt = (struct VB_Stmt*)malloc(sizeof(struct VB_Stmt));

		stmt->expr			 = NULL;
		stmt->dim_stmt		 = NULL;
		stmt->do_loop_stmt	 = NULL;
		stmt->enum_stmt		 = NULL;
		stmt->for_stmt		 = NULL;
		stmt->func_stmt		 = NULL;
		stmt->if_stmt		 = NULL;
		stmt->next			 = NULL;
		stmt->print_stmt	 = NULL;
		stmt->println_stmt	 = NULL;
		stmt->read_stmt		 = NULL;
		stmt->readkey_stmt	 = NULL;
		stmt->readln_stmt	 = NULL;
		stmt->sub_stmt		 = NULL;
		stmt->throw_stmt	 = NULL;
		stmt->try_catch_stmt = NULL;
		stmt->while_stmt	 = NULL;

		stmt->type = type;

		switch (type)
		{
		case(ENDL):
			break;
		case(STMT_EXPR):
			stmt->expr = (struct VB_Expr*)data;
			break;
		case(IF):
			stmt->if_stmt = (struct VB_If_stmt*)data;
			break;
		case(DIM):
			stmt->dim_stmt = (struct VB_Dim_stmt*)data;
			break;
		case(FOR):
			stmt->for_stmt = (struct VB_For_stmt*)data;
			break;
		case(WHILE):
			stmt->while_stmt = (struct VB_While_stmt*)data;
			break;
		case(DO_LOOP):
			stmt->do_loop_stmt = (struct VB_Do_loop_stmt*)data;
			break;
		case(ENUM):
			stmt->enum_stmt = (struct VB_Enum_stmt*)data;
			break;
		case(SUB):
			stmt->sub_stmt = (struct VB_Sub_stmt*)data;
			break;
		case(FUNC):
			stmt->func_stmt = (struct VB_Func_stmt*)data;
			break;
		case(TRY_CATCH):
			stmt->try_catch_stmt = (struct VB_Try_catch_stmt*)data;
			break;
		case(THROW):
			stmt->throw_stmt = (struct VB_Throw_stmt*)data;
			break;
		case(PRINT):
			stmt->print_stmt = (struct VB_Print_stmt*)data;
			break;
		case(PRINTLN):
			stmt->println_stmt = (struct VB_Println_stmt*)data;
			break;
		case(READ):
			stmt->read_stmt = (struct VB_Read_stmt*)data;
			break;
		case(READLN):
			stmt->readln_stmt = (struct VB_Readln_stmt*)data;
			break;
		}
	}
	return stmt;
}

/*!
	������� �������� �������� �� ���������.
  \param expr ���������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Expr (struct VB_Expr* expr)
{
	return fill_stmt(STMT_EXPR,(void*)expr);
}

/*!
	������� �������� �������� �� �������� ��������.
  \param if_stmt �������� ��������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_If (struct VB_If_stmt* if_stmt)
{
	return fill_stmt(IF,(void*)if_stmt);
}

/*!
	������� �������� �������� �� ������������� ����������.
  \param dim_stmt ������������� ���������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Dim (struct VB_Dim_stmt* dim_stmt)
{
	return fill_stmt(DIM,(void*)dim_stmt);
}

/*!
	������� �������� �������� �� �����.
  \param for_stmt ����.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_For (struct VB_For_stmt* for_stmt)
{
	return fill_stmt(FOR,(void*)for_stmt);
}

/*!
	������� �������� �������� �� �����.
  \param while_stmt ����.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_While (struct VB_While_stmt* while_stmt)
{
	return fill_stmt(WHILE,(void*)while_stmt);
}

/*!
	������� �������� �������� �� �����.
  \param do_loop_stmt ����.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Do_Loop (struct VB_Do_loop_stmt* do_loop_stmt)
{
	return fill_stmt(DO_LOOP,(void*)do_loop_stmt);
}

/*!
	������� �������� �������� �� ������������.
  \param enum_stmt ������������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Enum (struct VB_Enum_stmt* enum_stmt)
{
	return fill_stmt(ENUM,(void*)enum_stmt);
}

/*!
	������� �������� �������� �� ���������.
  \param sub_stmt ���������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Sub (struct VB_Sub_stmt* sub_stmt)
{
	return fill_stmt(SUB,(void*)sub_stmt);
}

/*!
	������� �������� �������� �� �������.
  \param func_stmt �������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Func (struct VB_Func_stmt* func_stmt)
{
	return fill_stmt(FUNC,(void*)func_stmt);
}

/*!
	������� �������� �������� �� ����������.
  \param try_catch_stmt ����������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Try_Catch (struct VB_Try_catch_stmt* try_catch_stmt)
{
	return fill_stmt(TRY_CATCH,(void*)try_catch_stmt);
}

/*!
	������� �������� ������� ����������.
  \param throw_stmt ����������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Throw(struct VB_Throw_stmt* throw_stmt)
{
	return fill_stmt(THROW,(void*)throw_stmt);
}

/*!
	������� �������� �������� �� ������ �������.
  \param print_stmt ������ �������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Print (struct VB_Print_stmt* print_stmt)
{
	return fill_stmt(PRINT,(void*)print_stmt);
}

/*!
	������� �������� �������� �� ������ ������.
  \param println_stmt ������ ������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Println (struct VB_Println_stmt* println_stmt)
{
	return fill_stmt(PRINTLN,(void*)println_stmt);
}

/*!
	������� �������� �������� �� ������ ������.
  \param readln_stmt ������ ������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Readln (struct VB_Readln_stmt* readln_stmt)
{
	return fill_stmt(READLN,(void*)readln_stmt);
}

/*!
	������� �������� �������� �� ������ �������.
  \param read_stmt ������ �������.
  \return ����� ��������.
*/
struct VB_Stmt* create_VB_Stmt_Read (struct VB_Read_stmt* read_stmt)
{
	return fill_stmt(READ,(void*)read_stmt);
}

/* ������������� ��������� ���������:
	if_stmt: IF expr THEN ENDL stmt_list end_if_stmt
		   | IF expr ENDL stmt_list end_if_stmt
		   | IF expr THEN stmt_list_inline END_IF ENDL
		   | IF expr THEN stmt_list_inline ELSE stmt_list_inline END_IF ENDL
		   ;
*/
/*!
	������� ������� �������� ��������� �� ������ ������� ����������.
  \param expr �������.
  \param stmt_list �������� ��� ������������� �������.
  \param end_if_stmt �������� ��� ������ �������.
  \return ����� �������� ���������.
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
	������� ������� �������� ��������� �� ������ ������� ����������.
  \param expr �������.
  \param stmt_list �������� ��� ������������� �������.
  \param end_if_stmt �������� ��� ������ �������.
  \return ����� �������� ���������.
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
	������� �������� ����� ���������.
  \param expr ���������.
  \return ���� ���������.
*/
struct VB_Expr_list* create_Expr_list (struct VB_Expr* expr)
{
	struct VB_Expr_list* list = NULL;

	list = (struct VB_Expr_list*)malloc(sizeof(struct VB_Expr_list));

	list->first = expr;
	list->last = expr;

	return list;
}

/*!
	������� ��������� ����� ���������.
  \param expr_list ���� ���������.
  \param expr ����������� ���������.
*/
struct VB_Expr_list* add_Expr_to_list (struct VB_Expr_list* expr_list, struct VB_Expr* expr)
{
	expr_list->last->next = expr;
	expr_list->last = expr;

	return expr_list;
}

/*!
	������� �������� ������� ��� ��� �������������.
  \param id ��� �������.
  \param int_const ������ �������.
  \param type ��� �������.
  \return ����� ���� �������.
*/
struct VB_Array_expr* create_Array (char* id, int int_const, enum VB_Id_type type)
{
	struct VB_Array_expr* arr = NULL;

	arr = (struct VB_Array_expr*)malloc(sizeof(struct VB_Array_expr));

	arr->id_type = type;
	arr->is_init = 0;
	arr->size = int_const;
	arr->id = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));
	strcpy(arr->id->expr_string,id);

	return arr;
}

/*!
	������� �������� ������� � ��� ��������������.
  \param id ��� �������.
  \param type ��� �������.
  \param list �������������.
  \return ����� ���� �������.
*/
struct VB_Array_expr* create_Array_with_init (char* id, enum VB_Id_type type, struct VB_Expr_list* list)
{
	struct VB_Array_expr* result = NULL;

	result = (struct VB_Array_expr*)malloc(sizeof(struct VB_Array_expr));

	result->id_type = type;
	result->list = list;
	result->is_init = 1;
	result->id = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));
	strcpy(result->id->expr_string, id);

	return result;
}

/*!
	������� �������� ���� ������: ������ ����������.
  \param string ����� ����������.
  \return ���� ������ - ������ ����������.
*/
struct VB_Throw_stmt* create_Throw (char* string)
{
	struct VB_Throw_stmt* th = NULL;

	th = (struct VB_Throw_stmt*)malloc(sizeof(struct VB_Throw_stmt));
	strcpy(th->string, string);

	return th;
}

/*!
	������� �������� Console.Write()
  \param text ����� � �������.
  \return ���� ������ - ����� � ����������� �����.
*/
struct VB_Print_stmt* create_Print (char* text)
{
	struct VB_Print_stmt* print = NULL;

	print = (struct VB_Print_stmt*)malloc(sizeof(struct VB_Print_stmt));

	strcpy(print->text,text);

	return print;
}

/*!
	������� �������� Console.WriteLine()
  \param text ����� � �������.
  \return ���� ������ - ����� � ����������� ����� � ��������� ������.
*/
struct VB_Println_stmt* create_Println (char* text)
{
	struct VB_Println_stmt* println = NULL;

	println = (struct VB_Println_stmt*)malloc(sizeof(struct VB_Println_stmt));

	strcpy(println->text,text);

	return println;
}

/*!
	������� �������� Console.Read().
  \return ���� ������ - ���������� ������� � ������������ ������.
*/
struct VB_Read_stmt* create_Read ()
{
	struct VB_Read_stmt* read = NULL;

	read = (struct VB_Read_stmt*)malloc(sizeof(struct VB_Read_stmt));

	return read;
}

/*!
	������� �������� Console.ReadLine().
  \return ���� ������ - ���������� ������ � ������������ ������.
*/
struct VB_Readln_stmt* create_Readln ()
{
	struct VB_Readln_stmt* readln = NULL;

	readln = (struct VB_Readln_stmt*)malloc(sizeof(struct VB_Readln_stmt));

	return readln;
}

/*!
	������� �������� ����� ��������� �������������� ����������.
  \param id ��� ����������.
  \param stmt_list ���� ���������� ��������� ����������.
  \return ����� ���� ������ - ���� ��������� ����������.
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
	������� �������� ����� ������ ��������� ������������� ���������.
  \param catch_stmt ���� ��������� �������������� ����������.
  \return ����� ���� ������ ��������� ������������� ���������.
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
	������� ���������� ������ ����� ��������� �������������� ����������.
  \param catch_stmt_list ���������� ���� ������ ��������� ������������� ����������.
  \param catch_stmt ���� ��������� �������������� ����������.
  \return ����� ���� ������ ��������� ������������� ���������.
*/
struct VB_Catch_stmt_list* add_new_Catch_stmt (struct VB_Catch_stmt_list* catch_stmt_list,
	struct VB_Catch_stmt* catch_stmt)
{
	catch_stmt_list->last->next = catch_stmt;
	catch_stmt_list->last = catch_stmt;

	return catch_stmt_list;
}

/*!
	������� �������� ����� ����� ������ - ��������� ����������.
  \param stmt_list ������������� ���.
  \param catch_stmt_list ��������� ����������.
  \param f_stmt_list �������� ����� ����������.
  \return ���� ������ - ��������� ����������.
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
	������� �������� ��������� ��������������.
  \param name ��� ��������������.
  \return ��������� �� ������ ���������.
*/
struct VB_Expr* create_id_expr(char* name)
{
	struct VB_Expr* result = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));

	result->type = ID;
	result->expr_string = name;

	return result;
}

/*!
	������� �������� ��������� ������ �������.
  \param name ��� ��������������.
  \param params ���������.
  \return ��������� �� ������ ���������.
*/
struct VB_Expr* create_func_expr(char* name, struct VB_Expr_list* params)
{
	struct VB_Expr* result = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));

	result->type = FUNC;
	result->expr_string = name;
	result->list = params;

	return result;
}

/*!
	������� �������� ��������� �� ��������.
*/
struct VB_Expr* create_brackets_actions(char* name, struct VB_Expr_list* params)
{
	struct VB_Expr* result = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));
	
	result->type = BRK_EXPR;
	result->expr_string = name;
	result->list = params;

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

	result->type = type;
	result->int_val = value;

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

	result->type = STRING_CONST;
	strcpy(result->expr_string,string);

	return result;
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

	result->type = type;
	result->left_chld = left;
	result->right_chld = right;

	return result;
}

/*!
	������� �������� ��������� ���������� ����������.
  \param list ������������ ����������.
  \return ��������� �� ������ ���������.
*/
struct VB_Dim_stmt* create_dim_stmt(struct VB_As_Expr_list* list)
{
	struct VB_Dim_stmt* dim_stmt = (struct VB_Dim_stmt*)malloc(sizeof(struct VB_Dim_stmt));
	
	dim_stmt->list = list;
	dim_stmt->next = NULL;

	return dim_stmt;
}

/*!
	������� �������� ������ ������������������ ����������� �����������.
  \param expr ��������� ����������� ����������.
  \param arr ��������� ����������� �������.
  \return ��������� �� ������ ���������.
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
	������� ���������� ���������� � ������ ������������������ ����������� �����������.
  \param list ������� ������
  \param expr ���������� ��������� 
  \param arr ����������� ������
  \return ��������� �� ������ ���������.
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

	as_expr->type = type;
	as_expr->id_type = id_type;

	if (type == ID_LIST)
	{
		as_expr->list = list;
		as_expr->expr = NULL;
		as_expr->id = NULL;	
	}
	else
	{
		as_expr->expr = expr;
		strcpy(as_expr->id->expr_string,id);	
	}

	return as_expr;
}

/*!
	�������� ������ ���������������.
  \param id �������������
  \return ��������� �� ������ ���������.
*/
struct VB_Id_list* create_id_list(char* id)
{
	struct VB_Id_list* list = (struct VB_Id_list*)malloc(sizeof(struct VB_Id_list));

	strcpy(list->id->expr_string,id);
	list->next = NULL;

	return list;
}

/*!
	�������� ������� � ������ ���������������.
  \param id �������������
  \return ��������� �� ������ ���������.
*/
struct VB_Id_list* add_to_id_list(struct VB_Id_list* list,char* id)
{
	struct VB_Id_list* new_list = (struct VB_Id_list*)malloc(sizeof(struct VB_Id_list));

	strcpy(new_list->id->expr_string,id);
	new_list->next = NULL;

	list->next = new_list;

	return list;
}


struct VB_Sub_stmt * create_sub_stmt(char * id, struct VB_Stmt_list * list, struct VB_Id_list * params)
{
    return NULL;
}

struct VB_Param_list * create_param_list()
{
    return NULL;
}

struct VB_Param_list *add_to_param_list()
{
    return NULL;
}

struct VB_Param_stmt* create_param_stmt()
{
    return NULL;
}

/*!
	������� ��������� For:
	" For i = 0 To 10
		��������
	  Next"

  \param id ��������
  \param start ��������� ��������
  \param end �������� ��������
  \param body ���� �����
  \return ��������� �� ������ For.
*/
struct VB_For_stmt * create_for_stmt(char* id, int start, int end, struct VB_Stmt_list* body)
{
	struct VB_For_stmt* result = (struct VB_For_stmt*)malloc(sizeof(struct VB_For_stmt));

	result->type = SIMPLE;
	result->id = id;
	result->from_val = start;
	result->to_val = end;
	result->step_val = 1;
	result->stmt_list = body;
	result->next = NULL;

    return result;
}

/*!
	������� ��������� For:
	" For i = 0 To 10 Step 2
		��������
	  Next"

  \param id ��������
  \param start ��������� ��������
  \param end �������� ��������
  \param step ��� ���������
  \param body ���� �����
  \return ��������� �� ������ For.
*/
struct VB_For_stmt * create_for_with_step_stmt(char* id, int start, int end, int step, struct VB_Stmt_list* body)
{
	struct VB_For_stmt* result = (struct VB_For_stmt*)malloc(sizeof(struct VB_For_stmt));

	result->type = WITH_STEP;
	result->id = id;
	result->from_val = start;
	result->to_val = end;
	result->step_val = step;
	result->stmt_list = body;
	result->next = NULL;

    return result;
}

/*!
	������� ��������� For:
	" For i As Integer = 0 To 10
		��������
	  Next"

  \param id ��������
  \param ��� ���������
  \param start ��������� ��������
  \param end �������� ��������
  \param body ���� �����
  \return ��������� �� ������ For.
*/
struct VB_For_stmt * create_for_with_decl_stmt(char* id, enum VB_Id_type type, int start, int end, struct VB_Stmt_list* body)
{
	struct VB_For_stmt* result = (struct VB_For_stmt*)malloc(sizeof(struct VB_For_stmt));

	result->type = WITH_DECL;
	result->new_id = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));
	result->new_id->expr_string = id;
	result->new_id->type = type;
	result->from_val = start;
	result->to_val = end;
	result->step_val = 1;
	result->stmt_list = body;
	result->next = NULL;

    return result;
}

/*!
	������� ��������� For:
	" For i As Integer = 0 To 10 Step 2
		��������
	  Next"

  \param id ��������
  \param ��� ���������
  \param start ��������� ��������
  \param end �������� ��������
  \param step ��� ���������
  \param body ���� �����
  \return ��������� �� ������ For.
*/
struct VB_For_stmt * create_for_with_decl_with_step_stmt(char* id, enum VB_Id_type type, int start, int end, int step, struct VB_Stmt_list* body)
{
	struct VB_For_stmt* result = (struct VB_For_stmt*)malloc(sizeof(struct VB_For_stmt));

	result->type = WITH_DECL_AND_STEP;
	result->new_id = (struct VB_Expr*)malloc(sizeof(struct VB_Expr));
	result->new_id->expr_string = id;
	result->new_id->type = type;
	result->from_val = start;
	result->to_val = end;
	result->step_val = step;
	result->stmt_list = body;
	result->next = NULL;

    return result;
}

/*!
	������� ��������� While:
	" While counter < 20
		counter += 1
	  End While"
  \param expr �������
  \param body ���� �����
  \return ��������� �� ������ While.
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
	������� ��������� Do..Loop..Until:
	"Do Until number = 10
        number += 1
    Loop"

  \param expr �������
  \param body ���� �����
  \return ��������� �� ������ Do..Loop..Until.
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
	������� ��������� Enum:
	"Enum filePermissions
		create = 1
		read = 2
		write = 4
		delete = 8
	End Enum"

  \param id ��� ������������ 
  \param list ������ ���������
  \return ��������� �� ������ Enum.
*/
struct VB_Enum_stmt * create_enum_stmt(char* id, struct VB_Enum_expr_list* list)
{
	struct VB_Enum_stmt* result = (struct VB_Enum_stmt*)malloc(sizeof(struct VB_Enum_stmt));

	result->id = id;
	result->list = list;
	result->next = NULL;

    return result;
}

/*!
	������� ������ ��������� ������������
  \param first_expr ������ ������� ������
  \return ��������� �� ������ ������.
*/
struct VB_Enum_expr_list * create_enum_list(struct VB_Enum_expr* first_expr)
{
	struct VB_Enum_expr_list* result = (struct VB_Enum_expr_list*)malloc(sizeof(struct VB_Enum_expr_list));

	result->first = first_expr;
	result->last = first_expr;

    return result;
}

/*!
	�������� ������� ������������ � ������
  \param first_expr ������ ������� ������
  \return ��������� �� ������ ������.
*/
struct VB_Enum_expr_list * add_to_enum_list(struct VB_Enum_expr_list* list, struct VB_Enum_expr* new_expr)
{
	list->last->next = new_expr;
	list->last = new_expr;

    return list;
}

/*!
	������� ������� ������������ number>0 && number<MAX_INT (� Java) && number_N != number_M
  \param first_expr ������ ������� ������
  \return ��������� �� ������� Enum.
*/
struct VB_Enum_expr * create_enum_expr(char* id, int number)
{
	struct VB_Enum_expr* result = (struct VB_Enum_expr*)malloc(sizeof(struct VB_Enum_expr));

	result->id = id;
	result->next = NULL;

	if (number >= 0)
	{
		result->is_init = 1;
		result->value = number;
	}

    return result;
}

struct VB_For_stmt * create_func_stmt()
{
    return NULL;
}
