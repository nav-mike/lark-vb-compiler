// GTKTest.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <string.h>
#include <libxml/tree.h>
#include <stdio.h>
#include "tree_nodes.h"

/**
 * �������� ������ ���� XML �����
 * @param stmt ������� ��������
 */
void VBX_createNode(struct VB_Stmt * stmt);

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

	mdlNode = xmlNewTextChild(root,NULL,(const xmlChar *)"module",(const xmlChar *)"\n");	// ��������� ���� ������	

	xmlNewProp(mdlNode,(const xmlChar *)"name",(const xmlChar *)module->id);				// ������ ��� ��������

	VBX_createNode(doc,module->stmt_list->first);		// �������� ���������� �������� ������

	xmlSaveFile((const xmlChar *)"tree.xml",doc);	// ��������� ��������
}

/** �������� ������ ���� XML ����� */
void VBX_createNode(xmlDocPtr doc, struct VB_Stmt * stmt){
	
}