// GTKTest.cpp: определяет точку входа для консольного приложения.
//

#include <string.h>
#include <libxml/tree.h>
#include <stdio.h>
#include "tree_nodes.h"

char* id_type_to_string (enum VB_Id_type type);

/**
 * Добавить узел - список операций.
 */
void VBX_add_statement_list(xmlNodePtr parent,struct VB_Stmt_list* list);

/**
 * Добавить узел - список объявлений.
 */
void VBX_add_decl_list(xmlNodePtr parent, struct VB_Decl_stmt_list* list);

/**
 * Добавить узел - expr.
 */
void VBX_add_expr(xmlNodePtr node, struct VB_Expr* expr);

/**
 * Добавить узел - if.
 */
void VBX_add_if(xmlNodePtr node, struct VB_If_stmt* stmt);

/**
 * Добавить узел - Dim
 */
void VBX_add_dim(xmlNodePtr node, struct VB_Dim_stmt* stmt);

/**
 * Добавить узел - For
 */
void VBX_add_for(xmlNodePtr node, struct VB_For_stmt* stmt);

/**
 * Добавить узел - While
 */
void VBX_add_while(xmlNodePtr node, struct VB_While_stmt* stmt);

/**
 * Добавить узел - Do...Loop
 */
void VBX_add_do_loop(xmlNodePtr node, struct VB_Do_loop_stmt* stmt);

/**
 * Добавить узел - Try...Catch
 */
void VBX_add_try_catch(xmlNodePtr node, struct VB_Try_catch_stmt* stmt);

/**
 * Добавить узел - Throw
 */
void VBX_add_throw(xmlNodePtr node, struct VB_Throw_stmt* stmt);

/**
 * Добавить узел - Sub
 */
void VBX_add_sub(xmlNodePtr node, struct VB_Sub_stmt* stmt);

/**
 * Добавить узел - Func
 */
void VBX_add_func(xmlNodePtr node, struct VB_Func_stmt* stmt);

void VBX_add_return(xmlNodePtr node, struct VB_Return_stmt* stmt);

/**
 * Добавить узел - EndIf
 */
void VBX_add_end_if(xmlNodePtr node, struct VB_End_if_stmt* stmt);

/**
 * Добавить узел - expr_list
 */
void VBX_add_as_expr_list(xmlNodePtr node, struct VB_As_Expr_list* list);

/**
 * Добавить узел - array_expr
 */
void VBX_add_array_expr(xmlNodePtr node, struct VB_Array_expr * expr);

/**
 * Добавить узел - as_expr
 */
void VBX_add_as_expr(xmlNodePtr node, struct VB_As_expr * expr);

/**
 * Добавить узел - stmt - один из элементов всего stmt_list
 */
void VBX_add_statement(xmlNodePtr parentList, struct VB_Stmt* stmt);

/**
 * Добавить узел - decl_stmt - один из элементов всего списка объявлений
 */
void VBX_add_declaration(xmlNodePtr parentList, struct VB_Decl_stmt* stmt);

/**
 * Получить строку с типом выражения
 */
char* VBX_expression_type_to_string (enum VB_Expr_type type);




/**
 * Получить строку с типом идентификатора
 */
char* VBX_id_type_to_string (enum VB_Id_type type);

/**
 * Добавить параметр процедуры или функции в дерево
 */
void VBX_add_param(xmlNodePtr node, struct VB_Param_stmt * stmt);

/**
 * Создание XML файла
 * @param module Корень разбираемого дерева
 */
void VBX_createXML (struct VB_Module_stmt* module){

	xmlDocPtr doc;				// Объект XML файла
	xmlNodePtr mdlNode;			// Корневой узел и узел модуля
	char buf[10];
	
	doc = xmlNewDoc((const xmlChar *)"1.0");	// Создаем документ

	if (module != NULL){
		mdlNode = xmlNewDocNode(doc,NULL,(const xmlChar *)"VB_Module_stmt",NULL);	// Добавляем узел модуля	
		
		xmlDocSetRootElement(doc,mdlNode);															// Задаем корень файлу
		
		xmlNewProp(mdlNode,(const xmlChar *)"id",(const xmlChar *)module->id);				// Задаем ему свойства

		itoa(module->line_number,buf,10);
		xmlNewProp(mdlNode,(const xmlChar *)"line_number",(const xmlChar *)buf);

		if (module->stmt_list != NULL)
			VBX_add_statement_list(
			xmlNewTextChild(mdlNode,NULL,(const xmlChar *)"VB_Stmt_list",NULL),
			module->stmt_list);		// Начинаем рекурсивно обходить функции Main
		
		if (module->decl_list != NULL)
			VBX_add_decl_list(mdlNode,module->decl_list);		// Начинаем рекурсивно обходить дерево определений функций
	}

	xmlSaveFile((const xmlChar *)"tree.xml",doc);	// Сохраняем документ
}


/**
 * Добавить узел - список операций.
 */
void VBX_add_statement_list(xmlNodePtr parent, struct VB_Stmt_list* list){
	
	if (list->first != NULL){
		struct VB_Stmt * item = list->first;

	//	xmlNodePtr listNode;

	//	listNode = xmlNewTextChild(parent,NULL,(const xmlChar *)"VB_Stmt_list",NULL);

		while (item != NULL){
			VBX_add_statement(parent,item);
			item = item->next;
		}
	}
}

/**
 * Добавить узел - список объявлений.
 */
void VBX_add_decl_list(xmlNodePtr parent, struct VB_Decl_stmt_list* list){

	char buf[15];
	
	if (list != NULL){
		struct VB_Decl_stmt * item = list->first;

		xmlNodePtr listNode, decl_node;

		listNode = xmlNewTextChild(parent,NULL,(const xmlChar *)"VB_Decl_stmt_list",NULL);

		while (item != NULL){
			decl_node = xmlNewTextChild(listNode,NULL,(const xmlChar *)"VB_Decl_stmt",NULL);

			xmlNewProp(decl_node,(const xmlChar *)"type",(const xmlChar *)statement_type_to_string(item->type));

			itoa(item->line_number,buf,10);
			xmlNewProp(decl_node,(const xmlChar *)"line_number",(const xmlChar*)buf);

			VBX_add_declaration(decl_node,item);

			item = item->next;
		}
	}
}

/**
 * Добавить узел - stmt - один из элементов всего stmt_list
 */
void VBX_add_statement(xmlNodePtr parentList, struct VB_Stmt* stmt){

	xmlNodePtr stmt_node, buf_node;
	char buf[15];

	stmt_node = xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_Stmt",NULL);

	xmlNewProp(stmt_node,(const xmlChar *)"type",(const xmlChar *)statement_type_to_string(stmt->type));
	
	itoa(stmt->line_number,buf,10);
	xmlNewProp(stmt_node,(const xmlChar *)"line_number",(const xmlChar *)buf);

	switch(stmt->type)
	{
	case (STMT_EXPR):
		buf_node = xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_Expr",NULL);
		/*itoa(((struct VB_Expr*)stmt->value)->line_number,buf,10);
		xmlNewProp(buf_node,(const xmlChar *)"line_number",(const xmlChar *)buf);*/
		VBX_add_expr(buf_node,(struct VB_Expr*)stmt->value);
		break;
	case(STMT_IF):
		buf_node = xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_If_stmt",NULL);
		//itoa(((struct VB_If_stmt*)stmt->value)->line_number,buf,10);
		//xmlNewProp(buf_node,(const xmlChar *)"line_number",(const xmlChar *)buf);
		VBX_add_if(buf_node
			,
			(struct VB_If_stmt*)stmt->value);
		break;
	case(STMT_DIM):
		buf_node = xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_Dim_stmt",NULL);
		itoa(((struct VB_Dim_stmt*)stmt->value)->line_number,buf,10);
		xmlNewProp(buf_node,(const xmlChar *)"line_number",(const xmlChar *)buf);
		VBX_add_dim(buf_node,
			(struct VB_Dim_stmt*)stmt->value);
		break;
	case(STMT_FOR):
		buf_node = xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_For_stmt",NULL);
		/*itoa(((struct VB_For_stmt*)stmt->value)->line_number,buf,10);
		xmlNewProp(buf_node,(const xmlChar *)"line_number",(const xmlChar *)buf);*/
		VBX_add_for(buf_node,
			(struct VB_For_stmt*)stmt->value);
		break;
	case(STMT_WHILE):
		buf_node = xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_While_stmt",NULL);
		itoa(((struct VB_While_stmt*)stmt->value)->line_number,buf,10);
		xmlNewProp(buf_node,(const xmlChar *)"line_number",(const xmlChar *)buf);
		VBX_add_while(buf_node,
			(struct VB_While_stmt*)stmt->value);
		break;
	case(STMT_DO_LOOP):
		buf_node = xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_Do_loop_stmt",NULL);
		//itoa(((struct VB_Do_loop_stmt*)stmt->value)->line_number,buf,10);
		//xmlNewProp(buf_node,(const xmlChar *)"line_number",(const xmlChar *)buf);
		VBX_add_do_loop(buf_node,
			(struct VB_Do_loop_stmt*)stmt->value);
		break;
	case(STMT_RETURN):
		buf_node = xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_Return_stmt",NULL);
		itoa(((struct VB_Return_stmt*)stmt->value)->line_number,buf,10);
		xmlNewProp(buf_node,(const xmlChar *)"line_number",(const xmlChar *)buf);
		VBX_add_return(buf_node,
			(struct VB_Return_stmt*)stmt->value);
		break;
	}


}

/**
 * Добавить узел - decl_stmt - один из элементов всего списка объявлений
 */
void VBX_add_declaration(xmlNodePtr parentList, struct VB_Decl_stmt* stmt){
	
	switch(stmt->type)
	{
	case(DECL_SUB): 
		VBX_add_sub(
			xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_Sub_stmt",NULL),
			stmt->sub_stmt);
		break;
	case(DECL_FUNC): 
		VBX_add_func(
			xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_Func_stmt",NULL),
			stmt->func_stmt);
		break;
	}
}


/**
 * Добавить узел - expr.
 */
void VBX_add_expr(xmlNodePtr node, struct VB_Expr* expr) {

	char buf[15];

	itoa(expr->int_val,buf,10);

	xmlNewProp(node,(const xmlChar *)"expr_string",(const xmlChar *)expr->expr_string);

	xmlNewProp(node,(const xmlChar *)"id_type",(const xmlChar *)VBX_id_type_to_string(expr->id_type));

	xmlNewProp(node,(const xmlChar *)"int_val",(const xmlChar *)buf);

	xmlNewProp(node,(const xmlChar *)"type",(const xmlChar *)VBX_expression_type_to_string(expr->type));

	itoa(expr->line_number,buf,10);
	xmlNewProp(node,(const xmlChar *)"line_number",(const xmlChar*)buf);
	
//	if (expr->type == EXPR_ID)
//		xmlNewProp(node,(const xmlChar *)"string_val",(const xmlChar *)expr->string_val);

	if (expr->left_chld != NULL){
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr__left_chld",NULL),
			expr->left_chld);
	}

	if (expr->right_chld != NULL){
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr__right_chld",NULL),
			expr->right_chld);
	}

	if (expr->list != NULL && expr->type == EXPR_BRK){

		struct VB_Expr * item = expr->list->first;

		xmlNodePtr list_node = xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr_list",NULL);

		while (item != NULL){
			VBX_add_expr(
				xmlNewTextChild(list_node,NULL,(const xmlChar *)"VB_Expr",NULL),item);
			item = item->next;
		}

	}
}

/**
 * Добавить процедуру в дерево
 */
void VBX_add_sub(xmlNodePtr node, struct VB_Sub_stmt* stmt){

	struct VB_Param_stmt * param_stmt = NULL;
	struct VB_Stmt * stmt_item = NULL;
	xmlNodePtr param_node;
	xmlNodePtr stmt_node;
	char buf[15];

	if (stmt->param_list != NULL)
		param_stmt = stmt->param_list->first;

	if (stmt->stmt_list != NULL)
		stmt_item = stmt->stmt_list->first;

	xmlNewProp(node,(const xmlChar *)"id",(const xmlChar *)stmt->id);

	itoa(stmt->line_number,buf,10);
	xmlNewProp(node,(const xmlChar *)"line_number",(const xmlChar *)buf);

	param_node = xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Param_stmt_list",NULL);

	while (param_stmt != NULL){
		VBX_add_param(
			xmlNewTextChild(param_node,NULL,(const xmlChar *)"VB_Param_stmt",NULL),param_stmt);
		param_stmt = param_stmt->next;
	}

	stmt_node = xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Stmt_list",NULL);

	while (stmt_item != NULL){
		VBX_add_statement(stmt_node,stmt_item);
		stmt_item = stmt_item->next;
	}
}

/**
 * Добавить параметр процедуры или функции в дерево
 */
void VBX_add_param(xmlNodePtr node, struct VB_Param_stmt * stmt){

	char buf[15];

	xmlNewProp(node,(const xmlChar *)"id",(const xmlChar *)stmt->id);

	xmlNewProp(node,(const xmlChar *)"id_type",(const xmlChar *)VBX_id_type_to_string(stmt->id_type));

	if (stmt->is_by_ref)
		xmlNewProp(node,(const xmlChar *)"is_by_ref",(const xmlChar *)"1");
	else
		xmlNewProp(node,(const xmlChar *)"is_by_ref",(const xmlChar *)"0");

	itoa(stmt->line_number,buf,10);
	xmlNewProp(node,(const xmlChar *)"line_number",(const xmlChar *)buf);
}


void VBX_add_func(xmlNodePtr node, struct VB_Func_stmt* stmt){
	
	struct VB_Param_stmt * param_stmt = NULL;
	struct VB_Stmt * stmt_item = NULL;
	xmlNodePtr param_node;
	xmlNodePtr stmt_node;
	char buf[15];

	if (stmt->param_list != NULL)
		param_stmt = stmt->param_list->first;

	if (stmt->stmt_list != NULL)
		stmt_item = stmt->stmt_list->first;

	
	xmlNewProp(node,(const xmlChar *)"id",(const xmlChar *)stmt->id);

	xmlNewProp(node,(const xmlChar *)"id_type",(const xmlChar *)VBX_id_type_to_string(stmt->id_type));

	itoa(stmt->line_number,buf,10);
	xmlNewProp(node,(const xmlChar *)"line_number",(const xmlChar *)buf);
	
	param_node = xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Param_stmt_list",NULL);

	while (param_stmt != NULL){
		VBX_add_param(
			xmlNewTextChild(param_node,NULL,(const xmlChar *)"VB_Param_stmt",NULL),param_stmt);
		param_stmt = param_stmt->next;
	}

	stmt_node = xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Stmt_list",NULL);

	while (stmt_item != NULL){
		VBX_add_statement(stmt_node,stmt_item);
		stmt_item = stmt_item->next;
	}

	if (stmt->expr != NULL)
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr",NULL),stmt->expr);
}

/**
 * Добавить узел - if.
 */
void VBX_add_if(xmlNodePtr node, struct VB_If_stmt* stmt){
	
	char buf[15];

	if (stmt->type == IF_THEN)
		xmlNewProp(node,(const xmlChar *)"type",(const xmlChar *)"IF_THEN");
	else
		xmlNewProp(node,(const xmlChar *)"type",(const xmlChar *)"IF_THEN_ELSE");

	itoa(stmt->line_number,buf,10);
	xmlNewProp(node,(const xmlChar *)"line_number",(const xmlChar *)buf);

	if (stmt->else_list != NULL)
		VBX_add_statement_list(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Stmt_list__else_list",NULL),stmt->else_list);

	if (stmt->expr != NULL)
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr",NULL),stmt->expr);

	if (stmt->stmt_list != NULL)
		VBX_add_statement_list(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Stmt_list__stmt_list",NULL),stmt->stmt_list);
}

//! \depricated
void VBX_add_end_if(xmlNodePtr node, struct VB_End_if_stmt* stmt){

}

void VBX_add_dim(xmlNodePtr node, struct VB_Dim_stmt* stmt){
	
	if (stmt->list != NULL)
		VBX_add_as_expr_list(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_As_Expr_list",NULL),stmt->list);
}

void VBX_add_as_expr_list(xmlNodePtr node,struct VB_As_Expr_list* list){
		
	char type[10];

	switch(list->type)
	{
	case (EXPR):
		strcpy(type,"EXPR\0");
		break;
	case (ARRAY):
		strcpy(type,"ARRAY\0");
		break;
	case (EXPR_LIST):
		strcpy(type,"EXPR_LIST\0");
		break;
	case (ARR_LIST):
		strcpy(type,"ARR_LIST\0");
		break;
	}

	xmlNewProp(node,(const xmlChar *)"type",(const xmlChar *)type);

	strcpy(type,"");
	itoa(list->line_number,type,10);
	xmlNewProp(node,(const xmlChar *)"line_number",(const xmlChar*)type);
	
	if (list->as_expr != NULL)
		VBX_add_as_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_As_expr",NULL),list->as_expr);

	if (list->next != NULL)
		VBX_add_as_expr_list(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_As_Expr_list",NULL),list->next);
}

void VBX_add_array_expr(xmlNodePtr node,struct VB_Array_expr * expr){

	char buf[100];
	struct VB_Expr * item = NULL;

	xmlNewProp(node,(const xmlChar *)"id",(const xmlChar *)expr->id);

	xmlNewProp(node,(const xmlChar *)"id_type",(const xmlChar *)VBX_id_type_to_string(expr->id_type));

	if (expr->list != NULL)
		xmlNewProp(node,(const xmlChar *)"is_init",(const xmlChar *)"1");
	else
		xmlNewProp(node,(const xmlChar *)"is_init",(const xmlChar *)"0");

	itoa(expr->size,buf,10);

	xmlNewProp(node,(const xmlChar *)"size",(const xmlChar *)buf);

	itoa(expr->line_number,buf,10);
	xmlNewProp(node,(const xmlChar *)"line_number",(const xmlChar *)buf);

	if (expr->list != NULL){
		item = expr->list->first;

		while (item != NULL){
			VBX_add_expr(
				xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr",NULL),item);
			item = item->next;
		}
	}
}

void VBX_add_as_expr(xmlNodePtr node,struct VB_As_expr * expr){
	
	char type[15];
	struct VB_Id_list * list = NULL;

	xmlNodePtr listNode;

	xmlNewProp(node,(const xmlChar *)"id_type",(const xmlChar *)VBX_id_type_to_string(expr->id_type));
	
	switch(expr->type)
	{
	case(ID_LIST):
		strcpy(type,"ID_LIST\0");
		break;
	case(ONE_ID):
		strcpy(type,"ONE_ID\0");
		break;
	case(ID_INIT):
		strcpy(type,"ID_INIT\0");
		break;
	}

	xmlNewProp(node,(const xmlChar *)"type",(const xmlChar *)type);

	itoa(expr->line_number,type,10);
	xmlNewProp(node,(const xmlChar *)"line_number",(const xmlChar *)type);

//	if (expr->id != NULL)
//		VBX_add_expr(
//			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr__id",NULL),expr->id);

	if (expr->expr != NULL)
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr__expr",NULL),expr->expr);

	list = expr->list;

	if (list != NULL){
		listNode = xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Id_list",NULL);
		itoa(list->counter,type,10);
		xmlNewProp(listNode,(const xmlChar *)"counter",(const xmlChar *)type);

		if (list->id != NULL)
			VBX_add_expr(
				xmlNewTextChild(listNode,NULL,(const xmlChar *)"VB_Expr",NULL),list->id);

		if (list->arr != NULL)
			VBX_add_array_expr(
				xmlNewTextChild(listNode,NULL,(const xmlChar *)"VB_Array_expr",NULL),list->arr);
	}

	list = list->next;

	while(list != NULL){
		listNode = xmlNewTextChild(listNode,NULL,(const xmlChar *)"VB_Id_list",NULL);
		itoa(list->counter,type,10);
		xmlNewProp(listNode,(const xmlChar *)"counter",(const xmlChar *)type);

		if (list->id != NULL)
			VBX_add_expr(
				xmlNewTextChild(listNode,NULL,(const xmlChar *)"VB_Expr",NULL),list->id);

		if (list->arr != NULL)
			VBX_add_array_expr(
				xmlNewTextChild(listNode,NULL,(const xmlChar *)"VB_Array_expr",NULL),list->arr);

		list = list->next;
	}
}

void VBX_add_for(xmlNodePtr node, struct VB_For_stmt* stmt){
	
	char * buf = (char*)malloc(sizeof(char)*15);

	itoa(stmt->from_val,buf,10);

	xmlNewProp(node,(const xmlChar *)"from_val",(const xmlChar *)buf);

	xmlNewProp(node,(const xmlChar *)"id",(const xmlChar *)stmt->id);
	
	itoa(stmt->step_val,buf,10);

	xmlNewProp(node,(const xmlChar *)"step_val",(const xmlChar *)buf);

	itoa(stmt->to_val,buf,10);

	xmlNewProp(node,(const xmlChar *)"to_val",(const xmlChar *)buf);
		
	strcpy(buf,VBX_for_type_to_string(stmt->type));

	xmlNewProp(node,(const xmlChar *)"type",(const xmlChar *)buf);

	itoa(stmt->line_number,buf,10);
	xmlNewProp(node,(const xmlChar *)"line_number",(const xmlChar *)buf);

	if (stmt->new_id != NULL){
		//VBX_add_expr(
		//	xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr",NULL),stmt->new_id);

		xmlNewProp(node,(const xmlChar *)"new_id",(const xmlChar *)stmt->new_id);

		xmlNewProp(node,(const xmlChar *)"new_id_type",(const xmlChar *)id_type_to_string(stmt->new_id_type));  
	}
	
	if (stmt->stmt_list != NULL)
		VBX_add_statement_list(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Stmt_list",NULL),stmt->stmt_list);
}

void VBX_add_while(xmlNodePtr node, struct VB_While_stmt* stmt){
	
	if (stmt->expr != NULL)
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr",NULL),stmt->expr);

	if (stmt->stmt_list != NULL)
		VBX_add_statement_list(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Stmt_list",NULL),stmt->stmt_list);
}

void VBX_add_do_loop(xmlNodePtr node, struct VB_Do_loop_stmt* stmt){
	
	char * buf = (char*)malloc(sizeof(char) * 15);

	strcpy(buf, VBX_do_loop_type_to_string(stmt->type));

	xmlNewProp(node,(const xmlChar *)"type",(const xmlChar *)buf);

	itoa(stmt->line_number,buf,10);
	xmlNewProp(node,(const xmlChar *)"line_number",(const xmlChar *)buf);

	if (stmt->expr != NULL)
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr",NULL),stmt->expr);

	if (stmt->stmt_list != NULL)
		VBX_add_statement_list(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Stmt_list",NULL),stmt->stmt_list);
}

void VBX_add_return(xmlNodePtr node, struct VB_Return_stmt* stmt){
	
	if (stmt->expr != NULL)
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr",NULL),stmt->expr);
}