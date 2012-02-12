package newtree;

import java.util.ArrayList;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс оператора возврата из функции.
 * @version 1.0
 */
public class ReturnStatement extends AbstractStatement{

    /* Поля класса. */
    /** Выражение возврата из функции. */
    private Expression retData;

    /**
     * Конструктор по умолчанию.
     */
    public ReturnStatement(){
        super(StatementType.RETURN);
        retData = null;
    }
    
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
        
        super(StatementType.RETURN);
        this.retData = retData;
    }

    /**
     * Считать данные из XML файла.
     * @param node Узел XML дерева.
     */
    @Override
    public void readData(Node node) {
        
        // Берем подузел с выражением
        NodeList nodes = node.getChildNodes();
        
        for (int i = 0; i < nodes.getLength(); i++) {
            if (nodes.item(i).getNodeName().equals("VB_Expr")) {                    
                this.retData = Expression.createExpr(nodes.item(i));
            }
        }
    }
    
}
