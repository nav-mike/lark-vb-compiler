package newtree;

import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;

/**
 * Новый класс выражения в дереве.
 * @version 1.0
 */
public class Expression implements XMLInterface{
    
    /* Поля класса. */
    /** Тип выражения. */
    protected int type;
    /** Тип выражения константы. */
    private DataType dtype;
    /** Выражение - константа. */
    public final static int CONST = 1;
    /** Выражение - идентификатор. */
    public final static int ID = 2;
    /** Выражение - математическая операция. */
    public final static int MATH = 3;
    
    /**
     * Метод задания типа выражения константы.
     * @param dtype Тип выражения константы.
     */
    public void setDtype(DataType dtype) {
        this.dtype = dtype;
    }
    
    /**
     * Метод получения типа выражения константы.
     * @return Тип выражения константы.
     */
    public DataType getDtype() {
        return dtype;
    }

    /**
     * Метод получения типа выражения.
     * @return Тип выражения.
     */
    public int getType() {
        return type;
    }

    /**
     * Метод задания типа выражения.
     * @param type Тип выражения.
     */
    public void setType(int type) {
        this.type = type;
    }

    /**
     * Конструктор по умолчанию.
     * Создается пустое выражение.
     */
    protected Expression() {
        
        type = -1;
    }

    /**
     * Конструктор с параметром.
     * Создает выражение определенного типа.
     * @param type Тип выражения.
     */
    protected Expression(int type) {
        
        this.type = type;
    }

    @Override
    public void readData(Node node) {
        
    }
        /**
     * Чтение данных из выражения
     * @param node Узел с выражением
     */
    public static Expression createExpr(Node node){

        Expression result = null;
        
        // Разберемся с аттрибутами
        NamedNodeMap attributes = node.getAttributes();
        Node attr = attributes.getNamedItem("type");
        String buffer = attr.getNodeValue();        
        
        if (buffer.equals("EXPR_ID")){
            result = new IdExpression();
        }
        else if (buffer.contains("CONST")){
            result = new ConstantExpression(0);
        }
        else if (buffer.equals("EXPR_READ")){
            result = new ReadExpression('0');
        }
        else if (buffer.equals("EXPR_READLN")){
            result = new ReadLineExpression("0");
        }
        else if (buffer.equals("EXPR_READLN")){
            result = new PrintExpression(null);
        }
        else if (buffer.equals("EXPR_PRINTLN")){
            result = new PrintLineExpression(null);
        }
        else if (buffer.equals("EXPR_BRK")){
            result = new IdExpression();
        }
        else{
            result = new MathExpression(null, null, 0);
        }
                
        return result;
    }
}



        
//attr = attributes.getNamedItem("id_type");
      
//        switch (buffer) {
//            case "DATA_INTEGER":
//                attr = attributes.getNamedItem("int_val");
//                buffer = attr.getNodeValue();
//                result = new ConstantExpression(Integer.parseInt(buffer));
//                result.setDtype(DataType.INTEGER);
//                break;
//            case "DATA_STRING":
//                attr = attributes.getNamedItem("expr_string");
//                buffer = attr.getNodeValue();
//                result = new ConstantExpression(buffer);
//                result.setDtype(DataType.STRING);
//                break;
//            case "DATA_BOOLEAN":
//                attr = attributes.getNamedItem("expr_string");
//                buffer = attr.getNodeValue();
//                if (buffer.equals("true"))
//                    result = new ConstantExpression(true);
//                else
//                    result = new ConstantExpression(false);
//                
//                result.setDtype(DataType.BOOLEAN);
//                break;
//        }