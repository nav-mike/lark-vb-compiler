package newtree;

import java.util.ArrayList;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

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
            
            IdExpression id = new IdExpression();
            attr = attributes.getNamedItem("expr_string");
            buffer = attr.getNodeValue();
            id.setName(buffer);
            
            result = id;
        }
        else if (buffer.equals("EXPR_BRK")){
            IdExpression id = new IdExpression();
            attr = attributes.getNamedItem("expr_string");
            buffer = attr.getNodeValue();
            id.setName(buffer);
            
            NodeList nodes = node.getChildNodes();
            ArrayList<Expression> params = new ArrayList<>();
            
            Node list_node = nodes.item(0);
            NodeList list_items = list_node.getChildNodes();
            
            for (int i = 0; i < list_items.getLength(); i++) {
                params.add(createExpr(list_items.item(i)));
            }
            id.setBody(params);
            
            result = id;
        }
        else if (buffer.contains("CONST")){
            switch (buffer) {
                case "EXPR_INT_CONST":
                    attr = attributes.getNamedItem("int_val");
                    buffer = attr.getNodeValue();
                    result = new ConstantExpression(Integer.parseInt(buffer));
                    result.setDtype(DataType.INTEGER);
                    break;
                    
                case "EXPR_BOOLEAN_CONST":
                    attr = attributes.getNamedItem("expr_string");
                    buffer = attr.getNodeValue();
                    if (buffer.equals("true"))
                        result = new ConstantExpression(true);
                    else
                        result = new ConstantExpression(false);

                    result.setDtype(DataType.BOOLEAN);
                    break;
                    
                case "EXPR_STRING_CONST":
                    attr = attributes.getNamedItem("expr_string");
                    buffer = attr.getNodeValue();
                    result = new ConstantExpression(buffer);
                    result.setDtype(DataType.STRING);                    
                    break;
            }
        }
        else if (buffer.equals("EXPR_READ")){
            result = new ReadExpression('-');
        }
        else if (buffer.equals("EXPR_READLN")){
            result = new ReadLineExpression("-");
        }
        else if (buffer.equals("EXPR_PRINT") || buffer.equals("EXPR_PRINTLN")){

            NodeList nodes = node.getChildNodes();
            Expression left = null;
            
            for (int i=0; i < nodes.getLength(); i++){
                if (nodes.item(i).getNodeName().equals("VB_Expr__left_chld"))
                    left = Expression.createExpr(nodes.item(i));
            }
            
            if (buffer.equals("EXPR_PRINT"))
                result = new PrintExpression(left);
            else
                result = new PrintLineExpression(left);
        }
        else{
            Expression left = null, right = null;
            
            NodeList nodes = node.getChildNodes();
            
            for (int i=0; i < nodes.getLength(); i++){
                if (nodes.item(i).getNodeName().equals("VB_Expr__right_chld"))
                    left = Expression.createExpr(nodes.item(i));
                
                if (nodes.item(i).getNodeName().equals("VB_Expr__left_chld"))
                    right = Expression.createExpr(nodes.item(i));
            }            
            
            attr = attributes.getNamedItem("expr_string");
            buffer = attr.getNodeValue();
                    
            result = new MathExpression(left, right, MathExprType.fromString(buffer));
        }
                
        return result;
    }
}