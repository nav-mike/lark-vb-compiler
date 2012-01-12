// GTKTest.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <string.h>
#include <libxml/tree.h>
#include <stdio.h>
#include "tree_nodes.h"


void VBX_add_statement_list(xmlDocPtr doc, xmlNodePtr parent,struct VB_Stmt_list* list);

void VBX_add_statement(xmlDocPtr doc, xmlNodePtr parentList, struct VB_Stmt* stmt);

char* statement_type_to_string (enum VB_Stmt_type type);

/**
 * �������� XML �����
 * @param module ������ ������������ ������
 */
void VBX_createXML (struct VB_Module_stmt* module){

	xmlDocPtr doc;				// ������ XML �����
	xmlNodePtr root,mdlNode;	// �������� ���� � ���� ������
	
	doc = xmlNewDoc((const xmlChar *)"1.0");	// ������� ��������

	root = xmlNewDocNode(doc,NULL,(const xmlChar *)"tree",(const xmlChar *)"\n");			// ������� ������ xml �����

	xmlDocSetRootElement(doc,root);															// ������ ������ �����

	if (module != NULL){
		mdlNode = xmlNewTextChild(root,NULL,(const xmlChar *)"module",(const xmlChar *)"\n");	// ��������� ���� ������	

		xmlNewProp(mdlNode,(const xmlChar *)"name",(const xmlChar *)module->id);				// ������ ��� ��������

		VBX_add_statement_list(doc,mdlNode,module->stmt_list);		// �������� ���������� �������� ������
	}


	xmlSaveFile((const xmlChar *)"tree.xml",doc);	// ��������� ��������
}

void VBX_add_statement_list(xmlDocPtr doc, xmlNodePtr parent, struct VB_Stmt_list* list){
	
	if (list != NULL){
		struct VB_Stmt * item = list->first;

		xmlNodePtr listNode;

		listNode = xmlNewTextChild(parent,NULL,(const xmlChar *)"stmt_list",(const xmlChar *)"\n");

		while (item != NULL){
			VBX_add_statement(doc,listNode,item);
			item = item->next;
		}
	}
}

void VBX_add_statement(xmlDocPtr doc, xmlNodePtr parentList, struct VB_Stmt* stmt){

	xmlNewTextChild(parentList,NULL,(const xmlChar *)statement_type_to_string(stmt->type),(const xmlChar *)"\n");
}