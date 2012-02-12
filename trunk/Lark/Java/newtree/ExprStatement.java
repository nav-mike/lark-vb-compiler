/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package newtree;

import org.w3c.dom.Node;

/**
 * Класс, описыващий какое-либо выражение.
 * @version 1.0
 */
public class ExprStatement extends AbstractStatement{
    
    /* Поля класса. */
    /** Хранящееся выражение. */
    private Expression expr_data;

    /**
     * Конструктор по умолчанию.
     */
    public ExprStatement(){
        super(StatementType.EXPRESSION);
        
        expr_data = null;
    }
    
    /**
     * Получить выражение.
     * @return Хранящееся в операции выражение.
     */
    public Expression getExpr() {
        return expr_data;
    }

    /**
     * Задать выражение.
     * @param expr_data Заносимое в операцию выражение.
     */
    public void setExpr(Expression expr_data) {
        this.expr_data = expr_data;
    }

    /**
     * Чтение данных из XML файла.
     * @param node Узел XML верева.
     */
    @Override
    public void readData(Node node) {
        
    }
}
