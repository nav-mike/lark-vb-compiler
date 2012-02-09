//
//

#ifndef H_PRT_DECL
#define H_PRT_DECL

#include "data_types.h"

/*! \struct VB_Decl_stmt
    ��������� ��� ���������� �������� � �������.
 */
struct VB_Decl_stmt
{
	enum   VB_Decl_type	    type;	    //!< ��� ��������.
	struct VB_Sub_stmt*     sub_stmt;   //!< ��������� �� ������������ � �������� ���������.
	struct VB_Func_stmt*    func_stmt;  //!< ��������� �� ������������ � �������� �������.
	struct VB_Decl_stmt*	next;		//!< ��������� ������� � ������
};

/*!
	������� �������� ���������� ����-����.
*/
struct VB_Decl_stmt* fill_decl_stmt(enum VB_Decl_type type, void* data)
{
	struct VB_Decl_stmt* stmt = NULL;

	if (data != NULL)
	{
		stmt = (struct VB_Decl_stmt*)malloc(sizeof(struct VB_Decl_stmt));

		stmt->func_stmt = NULL;
		stmt->next = NULL;
		stmt->sub_stmt = NULL;

		stmt->type = type;

		switch(type)
		{
			case(DECL_SUB):
				stmt->sub_stmt = (struct VB_Sub_stmt*)data;
				break;
			case(DECL_FUNC):
				stmt->func_stmt = (struct VB_Func_stmt*)data;
				break;
		}
	}
	return stmt;
}

#endif // H_PRT_DECL