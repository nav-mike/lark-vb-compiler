package newtree;

import java.util.ArrayList;
import java.util.Arrays;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс оператора цикла Do...Loop.
 * @version 1.0
 */
public class DoLoopStatement extends AbstractStatement {
        
    /* Поля класса. */
    /** Условие выполнения цикла. */
    private Expression condition;
    /** Тело цикла. */
    private ArrayList<AbstractStatement> body;
    /** Тип цикла. */
    private DoLoopType type;

    /**
     * Получить тип цикла
     * @return Тип
     */
    public DoLoopType getType() {
        return type;
    }

    /**
     * Задать тип циклу.
     * @param type Новый тип.
     */
    public void setType(DoLoopType type) {
        this.type = type;
    }

    /**
     * Конструктор по умолчанию.
     */
    public DoLoopStatement(){
        super(StatementType.DO_LOOP);
        condition = null;
        body = null;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает оператор с заданными условием и телом цикла.
     * Тело цикла заданно в виде одного оператора.
     * @param condition Условие выполнения цикла.
     * @param item Тело цикла, заданное в виде одномерного массива.
     */
    public DoLoopStatement (Expression condition, AbstractStatement item) {
        
        super(StatementType.DO_LOOP);
        this.condition = condition;
        this.body = new ArrayList();
        this.body.add(item);
    }
    
    /**
     * Конструктор с параметрами.
     * Создает оператор с заданными условием и телом цикла.
     * Тело цикла заданно в виде одномерного массива.
     * @param condition Условие выполнения цикла.
     * @param body Тело цикла, заданное в виде одномерного массива.
     */
    public DoLoopStatement (Expression condition, AbstractStatement[] body) {
        
        super(StatementType.DO_LOOP);
        this.condition = condition;
        this.body = new ArrayList(Arrays.asList(body));
    }

    /**
     * Конструктор с параметрами.
     * Создает оператор с заданными условием и телом цикла.
     * Тело цкила заданно в виде двусвязного списка.
     * @param condition Условие выполнения цикла.
     * @param body Тело цикла, заданное в виде двусвязного списка.
     */
    public DoLoopStatement(Expression condition, ArrayList<AbstractStatement> body) {
        
        super(StatementType.DO_LOOP);
        this.condition = condition;
        this.body = body;
    }

    /**
     * Метод задания условия выполнения цикла.
     * @param condition Условие выполнения цикла.
     */
    public void setCondition(Expression condition) {
        this.condition = condition;
    }
    
    /**
     * Метод задания тела цикла.
     * @param body Тело цикла, заданное в виде массива.
     */
    public void setBody (AbstractStatement[] body) {
        
        this.body.clear();
        this.body.addAll(Arrays.asList(body));
    }
    
    /**
     * Метод задания тела цикла.
     * @param item Тело цикла, представленное в виде одного оператора.
     */
    public void setBody (AbstractStatement item) {
        
        this.body.clear();
        this.body.add(item);
    }

    /**
     * Метод задания тела цикла.
     * @param body Тело цикла, заданное в виде связного списка.
     */
    public void setBody(ArrayList<AbstractStatement> body) {
        this.body = body;
    }

    /**
     * Метод получения условия выполнения цикла.
     * @return Условие выполнения цикла.
     */
    public Expression getCondition() {
        return condition;
    }

    /**
     * Метод получения тела цикла в виде связного списка.
     * @return Тело цикла в виде связного цикла.
     */
    public ArrayList<AbstractStatement> getBody() {
        return body;
    }
    
    /**
     * Метод получения тела цикла в виде массива.
     * @return Тело цикла в виде массива.
     */
    public AbstractStatement[] getBodyAsArray () {
        
        return (AbstractStatement[]) this.body.toArray();
    }
    
    /**
     * Метод получения одного оператора из тела цикла по индексу.
     * @param index Индекс, по которому получается элемент.
     * @return Оператор, получаемый по индексу.
     */
    public AbstractStatement get (int index) {
        
        return body.get(index);
    }

    @Override
    public void readData(Node node) {
        
        NamedNodeMap attributes = node.getAttributes();
        Node attr = attributes.getNamedItem("type");
        this.setType(DoLoopType.fromString(attr.getNodeValue()));
        
        attr = attributes.getNamedItem("line_number");
        lineNumber = Integer.parseInt(attr.getNodeValue());
                
        // Берем все подузлы дерева if и считываем данные 
        NodeList nodes = node.getChildNodes();
        
        for (int i = 0; i < nodes.getLength(); i++) {
//            switch (nodes.item(i).getNodeName()) {
//                case "VB_Expr":
//                    this.condition = Expression.createExpr(nodes.item(i));
//                    break;
//                    
//                case "VB_Stmt_list":
//                    this.body = new ArrayList();
//                    AbstractDeclaration.readBody(this.body, nodes.item(i));
//                    break;
//            }
            if ("VB_Expr".equals(nodes.item(i).getNodeName())) {
                
                this.condition = Expression.createExpr(nodes.item(i));
            } else if ("VB_Stmt_list".equals(nodes.item(i).getNodeName())) {
                
                this.body = new ArrayList<AbstractStatement>();
                AbstractDeclaration.readBody(this.body, nodes.item(i));
            }
        }
    }
    
}
