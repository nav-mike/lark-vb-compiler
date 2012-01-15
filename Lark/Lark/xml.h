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
void VBX_add_decl_list(xmlNodePtr parent, struct VB_Decl_stmt_list* list);

/**
 * �������� ���� - expr.
 */
void VBX_add_expr(xmlNodePtr node, struct VB_Expr* expr);

/**
 * �������� ���� - if.
 */
void VBX_add_if(xmlNodePtr node, struct VB_If_stmt* stmt);

/**
 * �������� ���� - Dim
 */
void VBX_add_dim(xmlNodePtr node, struct VB_Dim_stmt* stmt);

/**
 * �������� ���� - For
 */
void VBX_add_for(xmlNodePtr node, struct VB_For_stmt* stmt);

/**
 * �������� ���� - While
 */
void VBX_add_while(xmlNodePtr node, struct VB_While_stmt* stmt);

/**
 * �������� ���� - Do...Loop
 */
void VBX_add_do_loop(xmlNodePtr node, struct VB_Do_loop_stmt* stmt);

/**
 * �������� ���� - Try...Catch
 */
void VBX_add_try_catch(xmlNodePtr node, struct VB_Try_catch_stmt* stmt);

/**
 * �������� ���� - Throw
 */
void VBX_add_throw(xmlNodePtr node, struct VB_Throw_stmt* stmt);

/**
 * �������� ���� - Sub
 */
void VBX_add_sub(xmlNodePtr node, struct VB_Sub_stmt* stmt);

/**
 * �������� ���� - Func
 */
void VBX_add_func(xmlNodePtr node, struct VB_Func_stmt* stmt);

/**
 * �������� ���� - EndIf
 */
void VBX_add_end_if(xmlNodePtr node, struct VB_End_if_stmt* stmt);

/**
 * �������� ���� - expr_list
 */
void VBX_add_as_expr_list(xmlNodePtr node, struct VB_As_Expr_list* list);

/**
 * �������� ���� - array_expr
 */
void VBX_add_array_expr(xmlNodePtr node, struct VB_Array_expr * expr);

/**
 * �������� ���� - as_expr
 */
void VBX_add_as_expr(xmlNodePtr node, struct VB_As_expr * expr);

/**
 * �������� ���� - stmt - ���� �� ��������� ����� stmt_list
 */
void VBX_add_statement(xmlNodePtr parentList, struct VB_Stmt* stmt);

/**
 * �������� ���� - decl_stmt - ���� �� ��������� ����� ������ ����������
 */
void VBX_add_declaration(xmlNodePtr parentList, struct VB_Decl_stmt* stmt);

/**
 * �������� ������ � ����� ���������
 */
char* VBX_expression_type_to_string (enum VB_Expr_type type);


char* statement_type_to_string (enum VB_Stmt_type type);

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
			VBX_add_statement_list(
			xmlNewTextChild(mdlNode,NULL,(const xmlChar *)"VB_Stmt_list",NULL),
			module->stmt_list);		// �������� ���������� �������� ������� Main
		
		if (module->decl_list != NULL)
			VBX_add_decl_list(mdlNode,module->decl_list);		// �������� ���������� �������� ������ ����������� �������
	}

	xmlSaveFile((const xmlChar *)"tree.xml",doc);	// ��������� ��������
}

/**
 * �������� ���� - ������ ��������.
 */
void VBX_add_statement_list(xmlNodePtr parent, struct VB_Stmt_list* list){
	
	if (list != NULL){
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
 * �������� ���� - ������ ����������.
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
 * �������� ���� - stmt - ���� �� ��������� ����� stmt_list
 */
void VBX_add_statement(xmlNodePtr parentList, struct VB_Stmt* stmt){

	xmlNodePtr stmt_node;

	stmt_node = xmlNewTextChild(parentList,NULL,(const xmlChar *)"VB_Stmt",NULL);

	xmlNewProp(stmt_node,(const xmlChar *)"type",(const xmlChar *)statement_type_to_string(stmt->type));

	switch(stmt->type)
	{
	case (STMT_EXPR_E):
		VBX_add_expr(
			xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_Expr",NULL),
			(struct VB_Expr*)stmt->value);
		break;
	case(IF_E):
		VBX_add_if(
			xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_If_stmt",NULL),
			(struct VB_If_stmt*)stmt->value);
		break;
	case(DIM_E):
		VBX_add_dim(xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_Dim_stmt",NULL),
			(struct VB_Dim_stmt*)stmt->value);
		break;
	case(FOR_E):
		VBX_add_for(xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_For_stmt",NULL),
			(struct VB_For_stmt*)stmt->value);
		break;
	case(WHILE_E):
		VBX_add_while(xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_While_stmt",NULL),
			(struct VB_While_stmt*)stmt->value);
		break;
	case(DO_LOOP_E):
		VBX_add_do_loop(xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_Do_loop_stmt",NULL),
			(struct VB_Do_loop_stmt*)stmt->value);
		break;
	case(TRY_CATCH_E):
		VBX_add_try_catch(xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_Try_catch_stmt",NULL),
			(struct VB_Try_catch_stmt*)stmt->value);
		break;
	case(THROW_E):
		VBX_add_throw(xmlNewTextChild(stmt_node,NULL,(const xmlChar *)"VB_Throw_stmt",NULL),
			(struct VB_Throw_stmt*)stmt->value);
		break;
	}

}

/**
 * �������� ���� - decl_stmt - ���� �� ��������� ����� ������ ����������
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
 * �������� ���� - expr.
 */
void VBX_add_expr(xmlNodePtr node, struct VB_Expr* expr) {

	char buf[15];

	itoa(expr->int_val,buf,10);

	xmlNewProp(node,(const xmlChar *)"expr_string",(const xmlChar *)expr->expr_string);

	xmlNewProp(node,(const xmlChar *)"id_type",(const xmlChar *)VBX_id_type_to_string(expr->id_type));

	xmlNewProp(node,(const xmlChar *)"type",(const xmlChar *)VBX_expression_type_to_string(expr->type));

	xmlNewProp(node,(const xmlChar *)"int_val",(const xmlChar *)buf);
	
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
		VBX_add_statement(stmt_node,stmt_item);
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
		VBX_add_statement(stmt_node,stmt_item);
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

		VBX_add_expr(
			xmlNewTextChild(listNode,NULL,(const xmlChar *)"VB_Expr",NULL),list->id);
	}

	list = list->next;

	while(list != NULL){
		listNode = xmlNewTextChild(listNode,NULL,(const xmlChar *)"VB_Id_list",NULL);
		itoa(list->counter,type,10);
		xmlNewProp(listNode,(const xmlChar *)"counter",(const xmlChar *)type);

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

	struct VB_Catch_stmt* ct_stmt = NULL;

	xmlNodePtr ct_list_node,ct_stmt_node;

	if (stmt->fin_stmt_list != NULL)
		VBX_add_statement_list(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Stmt_list__fin_stmt_list",NULL),stmt->fin_stmt_list);

	if (stmt->stmt_list != NULL)
		VBX_add_statement_list(
			xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Stmt_list__stmt_list",NULL),stmt->stmt_list);


	if (stmt->catch_list != NULL){
		ct_stmt = stmt->catch_list->first;

		ct_list_node = xmlNewTextChild(node,NULL,(const xmlChar *)"VB_Catch_stmt_list",NULL);

		while(ct_stmt !=NULL){

			ct_stmt_node = xmlNewTextChild(ct_list_node,NULL,(const xmlChar *)"VB_Catch_stmt",NULL);

			xmlNewProp(ct_stmt_node,(const xmlChar *)"id",(const xmlChar *)ct_stmt->id);

			if (ct_stmt->stmt_list != NULL)
				VBX_add_statement_list(
					xmlNewTextChild(ct_stmt_node,NULL,(const xmlChar *)"VB_Stmt_list",NULL),ct_stmt->stmt_list);

			ct_stmt = ct_stmt->next;
		}
	}
}

void VBX_add_throw(xmlNodePtr node, struct VB_Throw_stmt* stmt){
	
	xmlNewProp(node,(const xmlChar *)"string",(const xmlChar *)stmt->string);
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