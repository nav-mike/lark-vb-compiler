package newtree;

import org.w3c.dom.Node;

/**
 * Класс оператора возврата из функции.
 * @version 1.0
 */
public class ReturnStatement extends AbstractStatement{

    /* Поля класса. */
    /** Выражение возврата из функции. */
    private Expression retData;

    /**
     * Метод получения выражения возврата.
     * @return Выражение возврата.
     */
    public Expression getRetData() {
        return retData;
    }

    /**
     * Метод задания выражения возврата.
     * @param retData Выражение возврата.
     */
    public void setRetData(Expression retData) {
        this.retData = retData;
    }

    /**
     * Конструктор с параметром.
     * Создает оператор с заданным выражением возврата из функции.
     * @param retData Выражение возврата.
     */
    public ReturnStatement(Expression retData) {
        
        super(SatementType.RETURN);
        this.retData = retData;
    }

    @Override
    public void readData(Node node) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
