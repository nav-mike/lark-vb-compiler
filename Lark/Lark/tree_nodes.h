//
//
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "data_types.h"

void yyerror (char const* s);

#include "prt_decl.h"
#include "prt_decl_list.h"
#include "prt_module.h"
#include "prt_stmt.h"
#include "prt_stmt_list.h"
#include "prt_expr.h"
#include "prt_expr_list.h"
#include "prt_dim.h"
#include "prt_do_loop.h"
#include "prt_for.h"
#include "prt_if.h"
#include "prt_return.h"
#include "prt_sub.h"
#include "prt_while.h"