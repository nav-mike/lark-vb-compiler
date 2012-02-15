package newtree;

import org.w3c.dom.Node;

/**
 * Класс абстрактного оператора.
 * Суперкласс для всех типов операторов.
 * @version 1.0
 */
public abstract class AbstractStatement implements XMLInterface{
    
    /* Поля класса. */
    /** Тип оператора. */
    protected StatementType stmtType;
    /** Номер строки в коде пользователя. */
    protected int lineNumber;

    /**
     * Метод получения номера строки в коде пользователя.
     * @return Номер строки в коде пользователя.
     */
    public Integer getLineNumber() {
        return lineNumber;
    }

    /**
     * Метод задания номера строки в коде пользователя.
     * @param lineNumber Номер строки в коде пользователя.
     */
    public void setLineNumber(Integer lineNumber) {
        this.lineNumber = lineNumber;
    }

    /**
     * Конструктор с параметром.
     * Создает оператор заданного типа.
     * @param stmtType Тип оператора.
     */
    protected AbstractStatement(StatementType stmtType) {
        this.stmtType = stmtType;
    }

    /**
     * Метод получения типа оператора.
     * @return Тип оператора.
     */
    public StatementType getStmtType() {
        return stmtType;
    }

    /**
     * Метод задания типа оператора.
     * @param stmtType Тип оператора.
     */
    public void setStmtType(StatementType stmtType) {
        this.stmtType = stmtType;
    }

    @Override
    public abstract void readData(Node node);
    
}
