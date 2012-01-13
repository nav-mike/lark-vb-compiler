// GTKTest.cpp: определяет точку входа для консольного приложения.
//

#include <string.h>
#include <libxml/tree.h>
#include <stdio.h>
#include "tree_nodes.h"

/**
 * Добавить узел - список операций.
 */
void VBX_add_statement_list(xmlDocPtr doc, xmlNodePtr parent,struct VB_Stmt_list* list);

/**
 * Добавить узел - список объявлений.
 */
void VBX_add_decl_list(xmlDocPtr doc, xmlNodePtr parent, struct VB_Decl_stmt_list* list);

/**
 * Добавить узел - expr.
 */
void VBX_add_expr(xmlNodePtr node, struct VB_Expr* expr);

/**
 * Добавить узел - if.
 */
void VBX_add_if(xmlNodePtr node, struct VBX_add_if* stmt);

/**
 * Добавить узел - stmt - один из элементов всего stmt_list
 */
void VBX_add_statement(xmlDocPtr doc, xmlNodePtr parentList, struct VB_Stmt* stmt);

/**
 * Получить строку с типом выражения
 */
char* VBX_expression_type_to_string (enum VB_Expr_type type);

/**
 * Получить строку с типом идентификатора
 */
char* VBX_id_type_to_string (enum VB_Id_type type);

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
			VBX_add_statement_list(doc,mdlNode,module->stmt_list);		// Начинаем рекурсивно обходить функции Main
		
		if (module->decl_list != NULL)
			VBX_add_decl_list(doc,mdlNode,module->decl_list);		// Начинаем рекурсивно обходить дерево определений функций
	}

	xmlSaveFile((const xmlChar *)"tree.xml",doc);	// Сохраняем документ
}

/**
 * Добавить узел - список операций.
 */
void VBX_add_statement_list(xmlDocPtr doc, xmlNodePtr parent, struct VB_Stmt_list* list){
	
	if (list != NULL){
		struct VB_Stmt * item = list->first;

		xmlNodePtr listNode;

		listNode = xmlNewTextChild(parent,NULL,(const xmlChar *)"VB_Stmt_list",NULL);

		while (item != NULL){
			VBX_add_statement(doc,listNode,item);
			item = item->next;
		}
	}
}

/**
 * Добавить узел - список объявлений.
 */
void VBX_add_decl_list(xmlDocPtr doc, xmlNodePtr parent, struct VB_Decl_stmt_list* list){
	
	if (list != NULL){
		struct VB_Decl_stmt * item = list->first;

		xmlNodePtr listNode;

		listNode = xmlNewTextChild(parent,NULL,(const xmlChar *)"VB_Decl_stmt_list",NULL);

		while (item != NULL){
			//VBX_add_statement(doc,listNode,item);
			item = item->next;
		}
	}
}

/**
 * Добавить узел - stmt - один из элементов всего stmt_list
 */
void VBX_add_statement(xmlDocPtr doc, xmlNodePtr parentList, struct VB_Stmt* stmt){

	xmlNodePtr stmt_node;

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
		//VBX_add_expr_prop(stmt_node,(struct VB_Dim_stmt*)stmt->value);
		break;
	case(FOR_E):
		//VBX_add_expr_prop(stmt_node,(struct VB_For_stmt*)stmt->value);
		break;
	case(WHILE_E):
		//VBX_add_expr_prop(stmt_node,(struct VB_While_stmt*)stmt->value);
		break;
	case(DO_LOOP_E):
		//VBX_add_expr_prop(stmt_node,(struct VB_Do_loop_stmt*)stmt->value);
		break;
	case(ENUM_D):
		//VBX_add_expr_prop(stmt_node,(struct VB_Enum_expr*)stmt->value);
		break;
	case(SUB_D):
		//VBX_add_expr_prop(stmt_node,(struct VB_Sub_stmt*)stmt->value);
		break;
	case(FUNC_D):
		//VBX_add_expr_prop(stmt_node,(struct VB_Func_stmt*)stmt->value);
		break;
	case(TRY_CATCH_E):
		//VBX_add_expr_prop(stmt_node,(struct VB_Try_catch_stmt*)stmt->value);
		break;
	case(THROW_E):
		//VBX_add_expr_prop(stmt_node,(struct VB_Throw_stmt*)stmt->value);
		break;
	case(PRINT_E):
		//VBX_add_expr_prop(stmt_node,(struct VB_Print_stmt*)stmt->value);
		break;
	case(PRINTLN_E):
		//VBX_add_expr_prop(stmt_node,(struct VB_Println_stmt*)stmt->value);
		break;
	case(READ_E):
		//VBX_add_expr_prop(stmt_node,(struct VB_Read_stmt*)stmt->value);
		break;
	case(READLN_E):
		//VBX_add_expr_prop(stmt_node,(struct VB_Readln_stmt*)stmt->value);
		break;
	}

}

/**
 * Добавить узел - expr.
 */
void VBX_add_expr(xmlNodePtr node, struct VB_Expr* expr){

	char buf[16];

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

	if (expr->next != NULL){
		VBX_add_expr(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Expr",NULL),
			expr->next);
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
 * Добавить узел - if.
 */
void VBX_add_if(xmlNodePtr node, struct VBX_add_if* stmt){

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





