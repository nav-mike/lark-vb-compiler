// GTKTest.cpp: определяет точку входа для консольного приложения.
//

#include <string.h>
#include <libxml/tree.h>
#include <stdio.h>
#include "tree_nodes.h"


void VBX_add_statement_list(xmlDocPtr doc, xmlNodePtr parent,struct VB_Stmt_list* list);

void VBX_add_statement(xmlDocPtr doc, xmlNodePtr parentList, struct VB_Stmt* stmt);

char* statement_type_to_string (enum VB_Stmt_type type);

/**
 * Создание XML файла
 * @param module Корень разбираемого дерева
 */
void VBX_createXML (struct VB_Module_stmt* module){

	xmlDocPtr doc;				// Объект XML файла
	xmlNodePtr root,mdlNode;	// Корневой узел и узел модуля
	
	doc = xmlNewDoc((const xmlChar *)"1.0");	// Создаем документ

	root = xmlNewDocNode(doc,NULL,(const xmlChar *)"tree",(const xmlChar *)"\n");			// Создаем корень xml файла

	xmlDocSetRootElement(doc,root);															// Задаем корень файлу

	if (module != NULL){
		mdlNode = xmlNewTextChild(root,NULL,(const xmlChar *)"module",(const xmlChar *)"\n");	// Добавляем узел модуля	

		xmlNewProp(mdlNode,(const xmlChar *)"name",(const xmlChar *)module->id);				// Задаем ему свойства

		VBX_add_statement_list(doc,mdlNode,module->stmt_list);		// Начинаем рекурсивно обходить дерево
	}


	xmlSaveFile((const xmlChar *)"tree.xml",doc);	// Сохраняем документ
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