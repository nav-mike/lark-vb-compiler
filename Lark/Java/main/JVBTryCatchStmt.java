package main;

import org.w3c.dom.Element;
/**
 * Класс обработки исключения.
 * @version 1.0
 */
public class JVBTryCatchStmt implements XMLInterface{
    
    /* Поля класса. */
    /** Отлавливаемый код. */
    private JVBStmtList stmtList;
    /** Код в finally. */
    private JVBStmtList finStmtList;
    /** Следующий оператор. */
    private JVBStmt next;
    /** Блок всех обработчиков исключения. */
    private JVBCatchStmtList catchList;

    /**
     * Метод получения блока всех обработчиков исключения.
     * @return Блок всех обработчиков исключения.
     */
    public JVBCatchStmtList getCatchList() {
        return catchList;
    }

    /**
     * Метод полчения кода finally.
     * @return Блок кода finally.
     */
    public JVBStmtList getFinStmtList() {
        return finStmtList;
    }

    /**
     * Метод получения следующего оператора.
     * @return Следующий оператор.
     */
    public JVBStmt getNext() {
        return next;
    }

    /**
     * Метод получения отлавливаемого кода.
     * @return Отлавливаемый код.
     */
    public JVBStmtList getStmtList() {
        return stmtList;
    }

    /**
     * Метод задания блока всех обработчиков исключений.
     * @param catchList Блок всех обработчиков исключений.
     */
    public void setCatchList(JVBCatchStmtList catchList) {
        this.catchList = catchList;
    }

    /**
     * Метод задания кода finally.
     * @param finStmtList Код finally.
     */
    public void setFinStmtList(JVBStmtList finStmtList) {
        this.finStmtList = finStmtList;
    }

    /**
     * Метод задания следующего оператора.
     * @param next Следующий оператор.
     */
    public void setNext(JVBStmt next) {
        this.next = next;
    }

    /**
     * Метод задания отлавливаемого кода.
     * @param stmtList Отлавливаемый код.
     */
    public void setStmtList(JVBStmtList stmtList) {
        this.stmtList = stmtList;
    }

    @Override
    public void write(Element parent) {
  //      throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
