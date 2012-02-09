package finderros;

import java.util.Iterator;
import main.CError;
import newtree.AbstractDeclaration;
import newtree.AbstractStatement;
import newtree.DataType;
import newtree.DoLoopStatement;
import newtree.Expression;
import newtree.ForStatement;
import newtree.IfStatement;
import newtree.ReturnStatement;
import newtree.StatementType;
import newtree.WhileStatement;

/**
 * Класс проверки функции на наличие возврата и правильность его типа.
 * @version 1.0
 */
public class CheckValidReturn {
    
    /**
     * Функция проверки функции/процедуры на наличие и правильность типа возврата.
     * @param func Проверяемая функция/процедура.
     * @return Объект класса ошибки или null.
     */
    public static CError checkFunction (AbstractDeclaration func) {
        
        if (func.getRetType() == DataType.NONE) {
            if (!checkProcedureForHasReturn(func))
                return new CError(func.getName(), "Процедура содержит return!");
            else return null;
        }
        
        return findReturnInMainCode(func);
    }
    
    /**
     * Метод проверки условного оператора на наличие возврата из процедуры.
     * @param item Условный оператор.
     * @return false если условный оператор содержит возврат из процедуры.
     */
    private static boolean checkIf (IfStatement item) {
        // Проверка положительной ветки.
        for (int i = 0; i < item.getBodyMain().size(); i++) {
            
            if (item.getFromMain(i).getStmtType() == StatementType.RETURN)
                return false;
        }
        // Проверка отрицательной ветки.
        for (int i = 0; i < item.getBodyAlter().size(); i++) {
            
            if (item.getFromAlter(i).getStmtType() == StatementType.RETURN)
                return false;
        }
        
        return true;
    }
    
    /**
     * Метод проверки цикла For на наличие возврата из функции.
     * @param item Проверяемы цикл.
     * @return false если условный оператор содержит возврат из процедуры.
     */
    private static boolean checkFor (ForStatement item) {
        
        for (int i = 0; i < item.getBody().size(); i++) {
            
            if (item.get(i).getStmtType() == StatementType.RETURN)
                return false;
        }
        
        return true;
    }
    
    /**
     * Метод проверки цикла While на наличие возврата из функции.
     * @param item Проверяемый цикл.
     * @return false если условный оператор содержит возврат из процедуры.
     */
    private static boolean checkWhile (WhileStatement item) {
        
        for (int i = 0; i < item.getBody().size(); i++) {
            
            if (item.getItem(i).getStmtType() == StatementType.RETURN)
                return false;
        }
        
        return true;
    }
    
    /**
     * Метод проверки цикла Do...Loop на наличие возврата из функции.
     * @param item Проверяемый цикл.
     * @return false если условный оператор содержит возврат из процедуры.
     */
    private static boolean checkDoLoop (DoLoopStatement item) {
        
        for (int i = 0; i < item.getBody().size(); i++) {
            
            if (item.get(i).getStmtType() == StatementType.RETURN)
                return false;
        }
        
        return true;
    }
    
    /**
     * Метод проверки тела процедуры на наличие возврата из функции.
     * @param item Проверяемая процедура.
     * @return false если тело процедуры содержит возврат из функции.
     */
    private static boolean checkBody (AbstractStatement item) {
        
        if (item.getStmtType() == StatementType.RETURN)
            return false;
        else if (item.getStmtType() == StatementType.IF)
            return checkIf((IfStatement)item);
        else if (item.getStmtType() == StatementType.FOR)
            return checkFor((ForStatement)item);
        else if (item.getStmtType() == StatementType.DO_LOOP)
            return checkDoLoop((DoLoopStatement)item);
        
        return true;
    }
    
    /**
     * Метод проверки процедуры на наличие возврата.
     * @param sub Проверяемая процедура.
     * @return false если процедура содержит возврат.
     */
    private static boolean checkProcedureForHasReturn (AbstractDeclaration sub) {
        
        boolean result = true;
        
        for (int i = 0; i < sub.getBody().size(); i++) {
            
            result = checkBody(sub.getFromBody(i));
            
            if (!result)
                break;
        }
        
        return result;
    }
    
    /**
     * Метод проверки функции на наличие return.
     * @param item Проверяемая функция.
     * @return Объект класса ошибки или null.
     */
    private static CError findReturnInMainCode (AbstractDeclaration item) {
        
        boolean isFinded = false;
        int i = 0;
        AbstractStatement buffer = null;
        
        Iterator<AbstractStatement> j = item.getBody().iterator();
        
        while (j.hasNext()) {
            
             buffer = j.next();
            if (buffer.getStmtType() == StatementType.RETURN) {
                
                isFinded = true;
                break;
                
            }
            i++;
        }
        
        if (isFinded) {
            
            for (int t = i + 1; t < item.getBody().size(); t++) {

                item.getBody().remove(t);
            }
            
            return checkDataType(((ReturnStatement)buffer).getRetData(), item);
        } else {
            
            return new CError(item.getName(), "У функции отсутствует возврат!");
        }
        
    }
    
    /**
     * Метод проверки типа возвращаемого значения функции.
     * @param expr Проверяемое выражение.
     * @param item Проверяемая функция.
     * @return Объект класса ошибки или null.
     */
    private static CError checkDataType (Expression expr, AbstractDeclaration item) {
        
        if (expr.getDtype() == item.getRetType())
            return null;
        
        return new CError(item.getName(), "Неверный тип возвращаемого значения функции!");
    }
    
}
