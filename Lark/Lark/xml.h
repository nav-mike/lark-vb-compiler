// GTKTest.cpp: определяет точку входа для консольного приложения.
//

#include <string.h>
#include <libxml/tree.h>
#include <stdio.h>
#include "tree_nodes.h"

/**
 * Создание нового узла XML файла
 * @param stmt Текущий оператор
 */
void VBX_createNode(struct VB_Stmt * stmt);

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

	mdlNode = xmlNewTextChild(root,NULL,(const xmlChar *)"module",(const xmlChar *)"\n");	// Добавляем узел модуля	

	xmlNewProp(mdlNode,(const xmlChar *)"name",(const xmlChar *)module->id);				// Задаем ему свойства

	VBX_createNode(doc,module->stmt_list->first);		// Начинаем рекурсивно обходить дерево

	xmlSaveFile((const xmlChar *)"tree.xml",doc);	// Сохраняем документ
}

/** Создание нового узла XML файла */
void VBX_createNode(xmlDocPtr doc, struct VB_Stmt * stmt){
	
}