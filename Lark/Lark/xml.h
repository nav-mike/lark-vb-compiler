// GTKTest.cpp: определяет точку входа для консольного приложения.
//

#include <string.h>
#include <libxml/tree.h>
#include <stdio.h>
#include "tree_nodes.h"

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

void VBX_add_dim(xmlNodePtr node, struct VB_Dim_stmt* stmt);

void VBX_add_for(xmlNodePtr node, struct VB_For_stmt* stmt);

void VBX_add_while(xmlNodePtr node, struct VB_While_stmt* stmt);

void VBX_add_do_loop(xmlNodePtr node, struct VB_Do_loop_stmt* stmt);

void VBX_add_try_catch(xmlNodePtr node, struct VB_Try_catch_stmt* stmt);

void VBX_add_throw(xmlNodePtr node, struct VB_Throw_stmt* stmt);


void VBX_add_sub(xmlNodePtr node, struct VB_Sub_stmt* stmt);

void VBX_add_func(xmlNodePtr node, struct VB_Func_stmt* stmt);

void VBX_add_end_if(xmlNodePtr node, struct VB_End_if_stmt* stmt);

void VBX_add_as_expr_list(xmlNodePtr node, struct VB_As_Expr_list* list);

void VBX_add_array_expr(xmlNodePtr node, struct VB_Array_expr * expr);

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
	
	doc = xmlNewDoc((const xmlChar *)"1.0");	// Создаем документ

	if (module != NULL){
		mdlNode = xmlNewDocNode(doc,NULL,(const xmlChar *)"VB_Module_stmt",(const xmlChar *)"\n");	// Добавляем узел модуля	
		
		xmlDocSetRootElement(doc,mdlNode);															// Задаем корень файлу
		
		xmlNewProp(mdlNode,(const xmlChar *)"id",(const xmlChar *)module->id);				// Задаем ему свойства

		if (module->stmt_list != NULL)
			VBX_add_statement_list(mdlNode,module->stmt_list);		// Начинаем рекурсивно обходить функции Main
		
		if (module->decl_list != NULL)
			VBX_add_decl_list(mdlNode,module->decl_list);		// Начинаем рекурсивно обходить дерево определений функций
	}

	xmlSaveFile((const xmlChar *)"tree.xml",doc);	// Сохраняем документ
}

/**
 * Добавить узел - список операций.
 */
void VBX_add_statement_list(xmlNodePtr parent, struct VB_Stmt_list* list){
	
	if (list != NULL){
		struct VB_Stmt * item = list->first;

		xmlNodePtr listNode;

		listNode = xmlNewTextChild(parent,NULL,(const xmlChar *)"VB_Stmt_list",NULL);

		while (item != NULL){
			VBX_add_statement(listNode,item);
			item = item->next;
		}
	}
}

/**
 * Добавить узел - список объявлений.
 */
void VBX_add_decl_list(xmlNodePtr parent, struct VB_Decl_stmt_list* list){
	
	if (list != NULL){
		struct VB_Decl_stmt * item = list->first;

		xmlNodePtr listNode;

		listNode = xmlNewTextChild(parent,NULL,(const xmlChar *)"VB_Decl_stmt_list",NULL);

		while (item != NULL){
			VBX_add_declaration(listNode,item);
			item = item->next;
		}
	}
}

/**
 * Добавить узел - stmt - один из элементов всего stmt_list
 */
void VBX_add_statement(xmlNodePtr parentList, struct VB_Stmt* stmt){

	switch(stmt->type)
	{
	case (STMT_EXPR_E):
		VBX_add_expr(
			xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_Expr",NULL),
			(struct VB_Expr*)stmt->value);
		break;
	case(IF_E):
		VBX_add_if(
			xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_If_stmt",NULL),
			(struct VB_If_stmt*)stmt->value);
		break;
	case(DIM_E):
		VBX_add_dim(xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_Dim_stmt",NULL),
			(struct VB_Dim_stmt*)stmt->value);
		break;
	case(FOR_E):
		VBX_add_for(xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_For_stmt",NULL),
			(struct VB_For_stmt*)stmt->value);
		break;
	case(WHILE_E):
		VBX_add_while(xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_While_stmt",NULL),
			(struct VB_While_stmt*)stmt->value);
		break;
	case(DO_LOOP_E):
		VBX_add_do_loop(xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_Do_loop_stmt",NULL),
			(struct VB_Do_loop_stmt*)stmt->value);
		break;
	case(TRY_CATCH_E):
		VBX_add_try_catch(xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_Try_catch_stmt",NULL),
			(struct VB_Try_catch_stmt*)stmt->value);
		break;
	case(THROW_E):
		VBX_add_throw(xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_Throw_stmt",NULL),
			(struct VB_Throw_stmt*)stmt->value);
		break;
	}

}

/**
 * Добавить узел - decl_stmt - один из элементов всего списка объявлений
 */
void VBX_add_declaration(xmlNodePtr parentList, struct VB_Decl_stmt* stmt){
	
	switch(stmt->type)
	{
	case(ENUM_D):
//		VBX_add_enum(
//			xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_Enum_expr",NULL),
//			(struct VB_Enum_expr*)stmt->value);
		break;
	case(SUB_D):
		VBX_add_sub(
			xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_Sub_stmt",NULL),
			stmt->sub_stmt);
		break;
	case(FUNC_D):
		VBX_add_func(
			xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_Func_stmt",NULL),
			stmt->func_stmt);
		break;
	}
}


/**
 * Добавить узел - expr.
 */
void VBX_add_expr(xmlNodePtr node, struct VB_Expr* expr){

	xmlNewProp(node,(const xmlChar *)"expr_string",(const xmlChar *)expr->expr_string);

	xmlNewProp(node,(const xmlChar *)"id_type",(const xmlChar *)VBX_id_type_to_string(expr->id_type));

	xmlNewProp(node,(const xmlChar *)"type",(const xmlChar *)VBX_expression_type_to_string(expr->type));
	
	if (expr->left_chld != NULL){
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr",NULL),
			expr->left_chld);
	}

	if (expr->right_chld != NULL){
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr",NULL),
			expr->right_chld);
	}

	if (expr->list != NULL){

		struct VB_Expr * item = expr->list->first;

		while (item != NULL){
			VBX_add_expr(
				xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr",NULL),item);
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

	if (stmt->param_list != NULL)
		param_stmt = stmt->param_list->first;

	if (stmt->stmt_list != NULL)
		stmt_item = stmt->stmt_list->first;

	xmlNewProp(node,(const xmlChar *)"id",(const xmlChar *)stmt->id);

	param_node = xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Param_stmt_list",NULL);

	while (param_stmt != NULL){
		VBX_add_param(
			xmlNewTextChild(param_node,NULL,(const xmlChar *)"VB_Param_stmt",NULL),param_stmt);
		param_stmt = param_stmt->next;
	}

	stmt_node = xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Stmt_list",NULL);

	while (stmt_item != NULL){
		VBX_add_statement(
			xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_Stmt",NULL),stmt_item);
		stmt_item = stmt_item->next;
	}
}

/**
 * Добавить параметр процедуры или функции в дерево
 */
void VBX_add_param(xmlNodePtr node, struct VB_Param_stmt * stmt){

	xmlNewProp(node,(const xmlChar *)"id",(const xmlChar *)stmt->id);

	xmlNewProp(node,(const xmlChar *)"id_type",(const xmlChar *)VBX_id_type_to_string(stmt->id_type));

	if (stmt->is_by_ref)
		xmlNewProp(node,(const xmlChar *)"is_by_ref",(const xmlChar *)"1");
	else
		xmlNewProp(node,(const xmlChar *)"is_by_ref",(const xmlChar *)"0");
}


void VBX_add_func(xmlNodePtr node, struct VB_Func_stmt* stmt){
	
	struct VB_Param_stmt * param_stmt = NULL;
	struct VB_Stmt * stmt_item = NULL;
	xmlNodePtr param_node;
	xmlNodePtr stmt_node;

	if (stmt->param_list != NULL)
		param_stmt = stmt->param_list->first;

	if (stmt->stmt_list != NULL)
		stmt_item = stmt->stmt_list->first;

	xmlNewProp(node,(const xmlChar *)"id",(const xmlChar *)stmt->id);

	param_node = xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Param_stmt_list",NULL);

	while (param_stmt != NULL){
		VBX_add_param(
			xmlNewTextChild(param_node,NULL,(const xmlChar *)"VB_Param_stmt",NULL),param_stmt);
		param_stmt = param_stmt->next;
	}

	stmt_node = xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Stmt_list",NULL);

	while (stmt_item != NULL){
		VBX_add_statement(
			xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_Stmt",NULL),stmt_item);
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
	
	if (stmt->type == IF_THEN)
		xmlNewProp(node,(const xmlChar *)"type",(const xmlChar *)"IF_THEN");
	else
		xmlNewProp(node,(const xmlChar *)"type",(const xmlChar *)"IF_THEN_ELSE");

	if (stmt->else_list != NULL)
		VBX_add_statement_list(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Stmt_list__else_list",NULL),stmt->else_list);

	if (stmt->end_stmt != NULL)
		VBX_add_end_if(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_End_if_stmt",NULL),stmt->end_stmt);

	if (stmt->expr != NULL)
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr",NULL),stmt->expr);

	if (stmt->stmt_list != NULL)
		VBX_add_statement_list(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Stmt_list__stmt_list",NULL),stmt->stmt_list);
}


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
	
	if (list->arr != NULL)
		VBX_add_array_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Array_expr",NULL),list->arr);

	if (list->as_expr != NULL)
		VBX_add_as_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_As_expr",NULL),list->as_expr);
}

void VBX_add_array_expr(xmlNodePtr node,struct VB_Array_expr * expr){

	char buf[10];
	struct VB_Expr * item = NULL;

	xmlNewProp(node,(const xmlChar *)"id",(const xmlChar *)expr->id);

	xmlNewProp(node,(const xmlChar *)"id_type",(const xmlChar *)VBX_id_type_to_string(expr->id_type));

	if (expr->is_init)
		xmlNewProp(node,(const xmlChar *)"is_init",(const xmlChar *)"1");
	else
		xmlNewProp(node,(const xmlChar *)"is_init",(const xmlChar *)"0");

	itoa(expr->size,buf,10);

	xmlNewProp(node,(const xmlChar *)"size",(const xmlChar *)buf);

	if (expr->list != NULL)
		item = expr->list->first;

	while (item != NULL){
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr",NULL),item);
		item = item->next;
	}
}

void VBX_add_as_expr(xmlNodePtr node,struct VB_As_expr * expr){
	
	char type[10];
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

	if (expr->id != NULL)
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr__id",NULL),expr->id);

	if (expr->expr != NULL)
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr__expr",NULL),expr->expr);

	list = expr->list;

	if (list != NULL){
		listNode = xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Id_list",NULL);
		itoa(list->counter,type,10);
		xmlNewProp(listNode,(const xmlChar *)"counter",(const xmlChar *)type);
	}

	while(list != NULL){
		VBX_add_expr(
			xmlNewTextChild(listNode,NULL,(const xmlChar *)"VB_Expr",NULL),list->id);
		list = list->next;
	}
}

void VBX_add_for(xmlNodePtr node, struct VB_For_stmt* stmt){
	
	char buf[10];

	xmlNewProp(node,(const xmlChar *)"id",(const xmlChar *)stmt->id);

	itoa(stmt->from_val,buf,10);

	xmlNewProp(node,(const xmlChar *)"from_val",(const xmlChar *)buf);
	
	itoa(stmt->step_val,buf,10);

	xmlNewProp(node,(const xmlChar *)"step_val",(const xmlChar *)buf);

	itoa(stmt->to_val,buf,10);

	xmlNewProp(node,(const xmlChar *)"to_val",(const xmlChar *)buf);
		
	switch(stmt->type)
	{
	case (SIMPLE):
		strcpy(buf,"SIMPLE\0");
		break;
	case (WITH_DECL):
		strcpy(buf,"WITH_DECL\0");
		break;
	case (WITH_STEP):
		strcpy(buf,"WITH_STEP\0");
		break;
	case (WITH_DECL_AND_STEP):
		strcpy(buf,"WITH_DECL_AND_STEP\0");
		break;
	}

	xmlNewProp(node,(const xmlChar *)"type",(const xmlChar *)buf);

	if (stmt->new_id != NULL)
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr",NULL),stmt->new_id);
	
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
	
	char buf[12];

	switch(stmt->type)
	{
	case (DO_WHILE):
		strcpy(buf,"DO_WHILE\0");
		break;
	case (DO_UNTIL):
		strcpy(buf,"DO_UNTIL\0");
		break;
	case (LOOP_WHILE):
		strcpy(buf,"LOOP_WHILE\0");
		break;
	case (LOOP_UNTIL):
		strcpy(buf,"LOOP_UNTIL\0");
		break;
	}

	xmlNewProp(node,(const xmlChar *)"type",(const xmlChar *)buf);

	if (stmt->expr != NULL)
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr",NULL),stmt->expr);

	if (stmt->stmt_list != NULL)
		VBX_add_statement_list(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Stmt_list",NULL),stmt->stmt_list);
}

void VBX_add_try_catch(xmlNodePtr node, struct VB_Try_catch_stmt* stmt){

	
}

void VBX_add_throw(xmlNodePtr node, struct VB_Throw_stmt* stmt){
	
}

/**
 * Получить строку с типом выражения
 */
char* VBX_expression_type_to_string (enum VB_Expr_type type)
{
	switch(type)
	{
    case (EXPR_FUNC):
        return "EXPR FUNC";
	case (ASSIGN):
		return "ASSIGN";
	case (BOOLEAN_CONST_E):
		return "BOOLEAN CONST";
	case (BRK_EXPR):
		return "BRK_EXPR";
	case (CHAR_CONST_E):
		return "CHAR CONST";
	case (DIV):
		return "DIV";
	case (EQUAL_E):
		return "EQUAL_E";
	case (GET_ITEM):
		return "GET_ITEM";
	case (ID_E):
		return "ID_E";
	case (INT_CONST_E):
		return "INT_CONST_E";
	case (INT_DIV):
		return ("INT_DIV");
	case (LESS):
		return "LESS";
	case (LESS_OR_EQUAL_E):
		return "LESS_OR_EQUAL_E";
	case (MINUS):
		return "MINUS";
	case (MORE):
		return "MORE";
	case (MORE_OR_EQUAL_E):
		return "MORE_OR_EQUAL_E";
	case (MUL):
		return "MUL";
	case (NONEQUAL_E):
		return "NONEQUAL_E";
	case (PLUS):
		return "PLUS";
	case (POWER):
		return "^";
	case (STRING_CONST_E):
		return "STRING_CONST_E";
	case (UMINUS_E):
		return "UMINUS_E";
	case (READ_E):
		return "READ_E";
	case (READLN_E):
		return "READLN_E";
	case (PRINT_E):
		return "PRINT_E";
	case (PRINTLN_E):
		return "PRINTLN_E";
	}

	return "";
}

/**
 * Получить строку с типом идентификатора
 */
char* VBX_id_type_to_string (enum VB_Id_type type)
{
	switch (type)
	{
	case (BOOLEAN_E):
		return "BOOLEAN_E";
	case (CHAR_E):
		return "CHAR_E";
	case (INTEGER_E):
		return "INTEGER_E";
	case (STRING_E):
		return "STRING_E";
	}

	return "";
}





