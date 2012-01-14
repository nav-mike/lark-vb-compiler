// GTKTest.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <string.h>
#include <libxml/tree.h>
#include <stdio.h>
#include "tree_nodes.h"

/**
 * �������� ���� - ������ ��������.
 */
void VBX_add_statement_list(xmlNodePtr parent,struct VB_Stmt_list* list);

/**
 * �������� ���� - ������ ����������.
 */
void VBX_add_decl_list(xmlDocPtr doc, xmlNodePtr parent, struct VB_Decl_stmt_list* list);

/**
 * �������� ���� - expr.
 */
void VBX_add_expr(xmlNodePtr node, struct VB_Expr* expr);

/**
 * �������� ���� - if.
 */
void VBX_add_if(xmlNodePtr node, struct VB_If_stmt* stmt);

void VBX_add_dim(xmlNodePtr node, struct VB_Dim_stmt* stmt);


void VBX_add_sub(xmlNodePtr node, struct VB_Sub_stmt* stmt);

void VBX_add_func(xmlNodePtr node, struct VB_Func_stmt* stmt);

void VBX_add_end_if(xmlNodePtr node, struct VB_End_if_stmt* stmt);

/**
 * �������� ���� - stmt - ���� �� ��������� ����� stmt_list
 */
void VBX_add_statement(xmlNodePtr parentList, struct VB_Stmt* stmt);

/**
 * �������� ���� - decl_stmt - ���� �� ��������� ����� ������ ����������
 */
void VBX_add_declaration(xmlDocPtr doc, xmlNodePtr parentList, struct VB_Decl_stmt* stmt);

/**
 * �������� ������ � ����� ���������
 */
char* VBX_expression_type_to_string (enum VB_Expr_type type);

/**
 * �������� ������ � ����� ��������������
 */
char* VBX_id_type_to_string (enum VB_Id_type type);

/**
 * �������� �������� ��������� ��� ������� � ������
 */
void VBX_add_param(xmlNodePtr node, struct VB_Param_stmt * stmt);

/**
 * �������� XML �����
 * @param module ������ ������������ ������
 */
void VBX_createXML (struct VB_Module_stmt* module){

	xmlDocPtr doc;				// ������ XML �����
	xmlNodePtr mdlNode;			// �������� ���� � ���� ������
	
	doc = xmlNewDoc((const xmlChar *)"1.0");	// ������� ��������

	if (module != NULL){
		mdlNode = xmlNewDocNode(doc,NULL,(const xmlChar *)"VB_Module_stmt",(const xmlChar *)"\n");	// ��������� ���� ������	
		
		xmlDocSetRootElement(doc,mdlNode);															// ������ ������ �����
		
		xmlNewProp(mdlNode,(const xmlChar *)"id",(const xmlChar *)module->id);				// ������ ��� ��������

		if (module->stmt_list != NULL)
			VBX_add_statement_list(mdlNode,module->stmt_list);		// �������� ���������� �������� ������� Main
		
		if (module->decl_list != NULL)
			VBX_add_decl_list(doc,mdlNode,module->decl_list);		// �������� ���������� �������� ������ ����������� �������
	}

	xmlSaveFile((const xmlChar *)"tree.xml",doc);	// ��������� ��������
}

/**
 * �������� ���� - ������ ��������.
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
 * �������� ���� - ������ ����������.
 */
void VBX_add_decl_list(xmlDocPtr doc, xmlNodePtr parent, struct VB_Decl_stmt_list* list){
	
	if (list != NULL){
		struct VB_Decl_stmt * item = list->first;

		xmlNodePtr listNode;

		listNode = xmlNewTextChild(parent,NULL,(const xmlChar *)"VB_Decl_stmt_list",NULL);

		while (item != NULL){
			VBX_add_declaration(doc,listNode,item);
			item = item->next;
		}
	}
}

/**
 * �������� ���� - stmt - ���� �� ��������� ����� stmt_list
 */
void VBX_add_statement(xmlNodePtr parentList, struct VB_Stmt* stmt){

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
		VBX_add_dim(xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_If_stmt",NULL),
			(struct VB_Dim_stmt*)stmt->value);
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
 * �������� ���� - decl_stmt - ���� �� ��������� ����� ������ ����������
 */
void VBX_add_declaration(xmlDocPtr doc, xmlNodePtr parentList, struct VB_Decl_stmt* stmt){
	
	xmlNodePtr decl_node;

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
 * �������� ���� - expr.
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
 * �������� ��������� � ������
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
 * �������� �������� ��������� ��� ������� � ������
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
 * �������� ���� - if.
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

/**
 * �������� ������ � ����� ���������
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
 * �������� ������ � ����� ��������������
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




