package finderros;

import features.MySet;
import java.util.ArrayList;
import main.CError;
import main.JVBArrayExpr;
import main.JVBAsExpr;
import main.JVBAsExprList;
import main.JVBDeclStmt;
import main.JVBDimStmt;
import main.JVBIdList;
import main.JVBModuleStmt;
import main.JVBParamList;
import main.JVBParamStmt;
import main.JVBStmt;
import main.JVBStmtList;
import main.JVBStmtType;

/**
 * Класс проверки текста программы на наличие множественной инициализации.
 * @author alexander
 */
public class FindMultiDeclaration {
    
    /* Поля класса. */
    /** Множество локальных переменных. */
    private static MySet<String> lVar;
    /** Множество имен используемых функций. */
    private static MySet<String> funcs;
    /** Массив ошибок. */
    private static ArrayList<CError> errors;
    
    /**
     * Метод перебора массива в операторе определения переменных.
     * Функция проверяет массив, на наличие его имени в списке уже объявленных
     * переменных.
     * @param expr Массив.
     */
    private static void iterateArrays (JVBArrayExpr expr) {
        
        if (expr == null) return;
        
        if (!lVar.add(expr.getId()) ||
                funcs.contains(expr.getId())) {
            
            String text = "Multiple declaration of variable \""
                                    + expr.getId() + "\"!";
            System.out.println(text);
            errors.add(new CError("", text));
        }
        
    } // End iterateArrays
    
    /**
     * Метод перебора отдельных переменных (не массивов).
     * Функция проверяет переменные, на наличие их в списке уже объявленных
     * переменных.
     * @param expr Набор списков переменных.
     */
    private static void iterateIdLists (JVBAsExpr expr) {
        
        if (expr == null) return;
        
        if (expr.getList() == null) return;
        
        JVBIdList ids = expr.getList();
        
        while (ids != null) {
                                
            if (ids.getId() != null) {
                    
                if (!lVar.add(ids.getId().getExprString()) ||
                        funcs.contains(ids.getId().getExprString())) {

                    String text = "Multiple declaration of variable \""
                            + ids.getId().getExprString() + "\"!";
                    System.out.println(text);
                    errors.add(new CError("", text));
                }
            }

            ids = ids.getNext();
        }
        
    } // End iterateIdList
    
    /**
     * Метод фиксирования объявления для входных параметров функции.
     * @param list Список входных параметров.
     */
    private static void addParamsToSet (JVBParamList list) {
        
        if (list == null) return;
        
        JVBParamStmt item = list.getFirst();
        
        while (item != null) {
            
            if (!lVar.add(item.getId()) || funcs.contains(item.getId())) {
                
                String text = "Multiple declaration of variable \"" +
                        item.getId() + "\"!";
                System.out.println(text);
                errors.add(new CError("", text));
            }
        }
        
    } // End addParamsToSet
    
    /**
     * Метод поиска имен всех используемых функций/процедур.
     * Функция записывает имена всех реализованных функций/процедур.
     * @param module Модуль программы.
     */
    private static void addFuncSubNames (JVBModuleStmt module) {
        
        if (module.getDeclStmtList() == null) return;
        
        JVBDeclStmt item = module.getDeclStmtList().getFirst();
        
        while (item != null) {
            
            if (item.getFuncStmt() != null)
                if (!funcs.add(item.getFuncStmt().getId())) {
                    
                    String text = "Multiple declaration of function \"" +
                            item.getFuncStmt().getId() + "\"!";
                    System.out.println(text);
                    errors.add(new CError(item.getFuncStmt().getId(), text));
                }
            else if (item.getSubStmt() != null)
                if (!funcs.add(item.getSubStmt().getId())) {
                    
                    String text = "Multiple declaration of procedure \"" +
                            item.getSubStmt().getId() + "\"!";
                    System.out.println(text);
                    errors.add(new CError(item.getSubStmt().getId(), text));
                }
                
        }
        
        
    } // End addFuncSubNames
    
    /**
     * Метод перебора всего модуля для отлова ошибки множественной инициализации.
     * @param module Модуль программы.
     */
    public static void iterateWholeModule (JVBModuleStmt module) {
        
        // Считывание имен всех функций/процедур.
        addFuncSubNames(module);
        
        // Проверка функции Main.
        fillSet(module.getMainStmt());
        lVar.clear();
        
        // Проверка всех других функций/процедур.
        if (module.getDeclStmtList() == null) return;
        JVBDeclStmt item = module.getDeclStmtList().getFirst();
        
        while (item != null) {
            
            if (item.getFuncStmt() != null) {
                
                addParamsToSet(item.getFuncStmt().getParamList());
                fillSet(item.getFuncStmt().getStmtList());
            } else if (item.getSubStmt() != null) {
                
                addParamsToSet(item.getSubStmt().getParamList());
                fillSet(item.getSubStmt().getStmtList());
            }
            
            lVar.clear();
        }
        
    } // End iterateWholeModule
    
    /**
     * Метод перебора функции/процедуры и проверки всех переменных
     *  на множественное объявление.
     * @param flist Тело функции/процедуры.
     */
    private static void fillSet (JVBStmtList flist) {
        
        JVBStmt item = flist.getFirst();
        
        while (item != null) {
            
            if (item.getType() == JVBStmtType.DIM_E) {
                
                JVBDimStmt dim = (JVBDimStmt)item.getValue();

                if (dim.getList() != null) {
                    
                    JVBAsExprList list = dim.getList();
                    iterateArrays(list.getArr());

                    iterateIdLists(list.getAsExpr());
                }
            }
            
            item = item.getNext();
        }
    } // End fillSet
    
} // End Class
