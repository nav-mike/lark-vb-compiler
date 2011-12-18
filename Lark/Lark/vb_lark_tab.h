typedef union
{
	int		b_const;
	int		i_const;
	char	c_const;
	char*	s_const;
	
	char* 	Id;
	
	struct VB_Module_stmt*		Module;
	struct VB_Stmt_list*		List;
	struct VB_Stmt*				Stmt;
	struct VB_Expr*				Expr;
	struct VB_Expr_list*		Expr_l;
	struct VB_If_stmt*			If_stmt;
	struct VB_End_if_stmt*		End_if;
	struct VB_Dim_stmt*			Dim;
	struct VB_As_Expr_list*		As_l;
    struct VB_As_expr*			As_expr_str;
	struct VB_Id_list*			Id_l;
	struct VB_Array_expr*		Arr;
	struct VB_For_stmt*			For;
	struct VB_While_stmt*		While;
	struct VB_Do_loop_stmt*		Do_loop;
	struct VB_Enum_stmt*		Enum;
	struct VB_Enum_expr_list*	Enum_l;
	struct VB_Enum_expr*		Enum_e;
	struct VB_Sub_stmt*			Sub;
	struct VB_Param_list*		Param_l;
	struct VB_Param_stmt*		Param;
	struct VB_Func_stmt*		Func;
	struct VB_Try_catch_stmt*	Try_catch;
	struct VB_Catch_stmt_list*	Catch_l;
	struct VB_Catch_stmt*		Catch;
	struct VB_Throw_stmt*		Throw;
	
	struct VB_Decl_stmt_list*	Decl_l;
	struct VB_Decl_stmt*		Decl;
	
	enum VB_Id_type				Id_type;

	struct VB_Print_stmt*			console_print;
	struct VB_Println_stmt*			console_println;
	struct VB_Read_stmt*			console_read;
	struct VB_Readln_stmt*			console_readln;
} YYSTYPE;
#define	BOOLEAN_CONST	258
#define	INT_CONST	259
#define	STRING_CONST	260
#define	CHAR_CONST	261
#define	ID	262
#define	ENDL	263
#define	DIM	264
#define	AS	265
#define	IF	266
#define	THEN	267
#define	ELSE	268
#define	ELSEIF	269
#define	END_IF	270
#define	FUNCTION	271
#define	BYVAL	272
#define	RETURN	273
#define	END_FUNCTION	274
#define	SUB	275
#define	END_SUB	276
#define	TRY	277
#define	CATCH	278
#define	END_TRY	279
#define	THROW	280
#define	NEW	281
#define	CASE	282
#define	CONST	283
#define	SELECT	284
#define	WHILE	285
#define	UNTIL	286
#define	MODULE	287
#define	DO	288
#define	ENUM	289
#define	END_ENUM	290
#define	END_MODULE	291
#define	END_SELECT	292
#define	END_WHILE	293
#define	LOOP	294
#define	FOR_EACH	295
#define	FOR	296
#define	TO	297
#define	NEXT	298
#define	IN	299
#define	MOD	300
#define	STEP	301
#define	EXCEPTION	302
#define	INTEGER	303
#define	CHAR	304
#define	STRING_T	305
#define	BOOLEAN	306
#define	CONSOLE	307
#define	WRITE	308
#define	WRITELINE	309
#define	READ	310
#define	READLINE	311
#define	SYSTEM	312
#define	FINALLY	313
#define	TRUE	314
#define	FALSE	315
#define	SUB_MAIN_ENDL	316
#define	MORE_OR_EQUAL	317
#define	LESS_OR_EQUAL	318
#define	NONEQUAL	319
#define	EQUAL	320
#define	UMINUS	321


extern YYSTYPE yylval;
