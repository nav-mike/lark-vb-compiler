package finderros;

/*
 * TODO: Рассмотреть возможность оптимизации данного класса.
 * Смущает ситуация, при которой придется много раз обходить дерево.
 */

import features.MySet;
import main.*;

/**
 * Класс поиска необъявленных переменных.
 * @author Mikhail Navrotskiy
 */
public class FindUndeclaredIdentifier {
    
    /* Поля класса. */
    /** Множество всех функций/процедур модуля. */
    private static MySet<String> functions;
    /** Множество локальных переменных. */
    private static MySet<String> lvars;
    
    /**
     * Функция заполнения множества функций.
     * @param module Модуль программы.
     */
    private static void fillFunctionsSet (JVBModuleStmt module) {
        
        if (module.getDeclStmtList() == null)
            return;
        
        JVBDeclStmt item = module.getDeclStmtList().getFirst();
        
        while (item != null) {
            
            if (item.getFuncStmt() != null)
                functions.add(item.getFuncStmt().getId());
            else if (item.getSubStmt() != null)
                functions.add(item.getSubStmt().getId());
            
            item = item.getNext();
        }
        
    }
    
    /**
     * Метод проверки используемости функций/процедур.
     * @param list Тело функции/процедуры.
     */
    private static void checkUsedFunction (JVBStmtList list) {
        
        JVBStmt item = list.getFirst();
        
        while (item != null) {
            
            if (item.getType() == JVBStmtType.STMT_EXPR_E &&
                ((JVBExpr)item.getValue()).getExprType() == JVBExprType.ID_E) {
                
                JVBExpr expr = (JVBExpr)item.getValue();
                
                if (functions.contains(expr.getExprString()))
                    expr.setDecl(true);
            }
        }
    }
    
    /**
     * Метод обхода всего дерева и поиск использования функций/процедур.
     * @param module Модуль программы.
     */
    private static void iteratorAllFunction (JVBModuleStmt module) {
        
        // Обход Main.
        checkUsedFunction(module.getMainStmt());
        
        // Обход функций/процедур.
        if (module.getDeclStmtList() != null) {
            
            JVBDeclStmt item = module.getDeclStmtList().getFirst();
            
            while (item != null) {
                
                if (item.getFuncStmt() !=  null)
                    checkUsedFunction(item.getFuncStmt().getStmtList());
                else if (item.getSubStmt() != null)
                    checkUsedFunction(item.getSubStmt().getStmtList());
                
                item = item.getNext();
            }
        }
        
    }
    
}
