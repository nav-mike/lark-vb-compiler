package main;

import org.w3c.dom.Node;

/**
 * Класс процедуры.
 * @version 1.0
 */
public class JVBSubStmt {
    
    /* Поля класса. */
    /** Имя процедуры. */
    private String id;
    /** Список параметров. */
    private JVBParamList paramList;
    /** Тело процедуры. */
    private JVBStmtList stmtList;
    /** Следующий оператор. */
    private JVBStmt next;

    JVBSubStmt(Node item) {
        throw new UnsupportedOperationException("Not yet implemented");
    }

    /** 
     * Метод получения имени процедуры.
     * @return Имя процедуры.
     */
    public String getId() {
        return id;
    }

    /**
     * Метод получения следующего оператора.
     * @return Следующий оператор.
     */
    public JVBStmt getNext() {
        return next;
    }

    /**
     * Метод получения списка параметров.
     * @return Список параметров.
     */
    public JVBParamList getParamList() {
        return paramList;
    }

    /**
     * Метод получения тела процелуры.
     * @return Тело процедуры.
     */
    public JVBStmtList getStmtList() {
        return stmtList;
    }

    /**
     * Метод задания имени поля.
     * @param id Имя поля.
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * Метод задания следующего оператора.
     * @param next Следующий оператор.
     */
    public void setNext(JVBStmt next) {
        this.next = next;
    }

    /**
     * Метод задания списка параметров.
     * @param paramList Список параметров.
     */
    public void setParamList(JVBParamList paramList) {
        this.paramList = paramList;
    }

    /**
     * Метод задания тела процедуры.
     * @param stmtList Тело процедуры.
     */
    public void setStmtList(JVBStmtList stmtList) {
        this.stmtList = stmtList;
    }
    
}
