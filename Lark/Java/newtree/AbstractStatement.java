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
