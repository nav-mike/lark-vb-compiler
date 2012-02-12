package newtree;

import java.util.ArrayList;
import java.util.Arrays;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс оператора цикла For.
 * @version 1.0
 */
public class ForStatement extends AbstractStatement {
    
    /* Поля класса. */
    /** Существующий итератор. */ // TODO: (?)
    private String existedIterator;
    /** Новый итератор. */
    private Expression newIterator;
    /** Стартовое значение счетчика цикла. */
    private int startValue;
    /** Конечное значение счетчика цикла. */
    private int endValue;
    /** Величина шага счетчика цикла. */
    private int stepValue;
    /** Тело цикла. */
    private ArrayList<AbstractStatement> body;
    /** Тип цикла. */
    private ForStmtType type;

    /**
     * Получить тип цикла.
     * @return Тип.
     */
    public ForStmtType getType() {
        return type;
    }

    /**
     * Задать тип циклу.
     * @param type Тип цикла.
     */
    public void setType(ForStmtType type) {
        this.type = type;
    }
    
    
    
    /**
     * Консртруктор по умолчанию.
     */
    public ForStatement(){
        super(StatementType.FOR);
    }
    
    /**
     * Конструктор с параметрами.
     * Создает цикл с заданными параметрами и счетчик не создается в заголовке
     * цикла.
     * @param newIterator Счетчик, создаваемый в цикле.
     * @param startValue Начальное значение счетчика.
     * @param endValue Конечное значение счетчика.
     * @param stepValue Величина шага счетчика.
     * @param body Тело цикла, заданное одним оператором.
     */
    public ForStatement (String existedIterator, int startValue, int endValue,
            int stepValue, AbstractStatement item) {
        
        super(StatementType.FOR);
        this.body = new ArrayList(); this.body.add(item);
        this.endValue = endValue;
        this.existedIterator = existedIterator;
        this.newIterator = null;
        this.startValue = startValue;
        this.stepValue = stepValue;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает цикл с заданными параметрами и счетчик не создается в заголовке
     * цикла.
     * @param newIterator Счетчик, создаваемый в цикле.
     * @param startValue Начальное значение счетчика.
     * @param endValue Конечное значение счетчика.
     * @param stepValue Величина шага счетчика.
     * @param body Тело цикла, заданное одномерным массивом.
     */
    public ForStatement (String existedIterator, int startValue, int endValue,
            int stepValue, AbstractStatement[] body) {

        super(StatementType.FOR);
        this.existedIterator = existedIterator;
        this.newIterator = null;
        this.startValue = startValue;
        this.endValue = endValue;
        this.stepValue = stepValue;
        this.body = new ArrayList(Arrays.asList(body));
    }
    
    /**
     * Конструктор с параметрами.
     * Создает цикл с заданными параметрами и счетчик не создается в заголовке
     * цикла.
     * @param newIterator Счетчик, создаваемый в цикле.
     * @param startValue Начальное значение счетчика.
     * @param endValue Конечное значение счетчика.
     * @param stepValue Величина шага счетчика.
     * @param body Тело цикла, заданное двусвязным списком.
     */
    public ForStatement(String existedIterator, int startValue, int endValue,
            int stepValue, ArrayList<AbstractStatement> body) {
        
        super(StatementType.FOR);
        this.existedIterator = existedIterator;
        this.newIterator = null;
        this.startValue = startValue;
        this.endValue = endValue;
        this.stepValue = stepValue;
        this.body = body;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает цикл с заданными параметрами и счетчик создается в заголовке цикла.
     * @param newIterator Счетчик, создаваемый в цикле.
     * @param startValue Начальное значение счетчика.
     * @param endValue Конечное значение счетчика.
     * @param stepValue Величина шага счетчика.
     * @param body Тело цикла, заданное одним оператором.
     */
    public ForStatement (Expression newIterator, int startValue, int endValue,
            int stepValue, AbstractStatement item) {
        
        super(StatementType.FOR);
        this.body = new ArrayList(); this.body.add(item);
        this.endValue = endValue;
        this.existedIterator = null;
        this.newIterator = newIterator;
        this.startValue = startValue;
        this.stepValue = stepValue;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает цикл с заданными параметрами и счетчик создается в заголовке цикла.
     * @param newIterator Счетчик, создаваемый в цикле.
     * @param startValue Начальное значение счетчика.
     * @param endValue Конечное значение счетчика.
     * @param stepValue Величина шага счетчика.
     * @param body Тело цикла, заданное одномерным массивом.
     */
    public ForStatement (Expression newIterator, int startValue, int endValue,
            int stepValue, AbstractStatement[] body) {

        super(StatementType.FOR);
        this.existedIterator = null;
        this.newIterator = newIterator;
        this.startValue = startValue;
        this.endValue = endValue;
        this.stepValue = stepValue;
        this.body = new ArrayList(Arrays.asList(body));
    }

    /**
     * Конструктор с параметрами.
     * Создает цикл с заданными параметрами и счетчик создается в заголовке цикла.
     * @param newIterator Счетчик, создаваемый в цикле.
     * @param startValue Начальное значение счетчика.
     * @param endValue Конечное значение счетчика.
     * @param stepValue Величина шага счетчика.
     * @param body Тело цикла.
     */
    public ForStatement(Expression newIterator, int startValue, int endValue,
            int stepValue, ArrayList<AbstractStatement> body) {

        super(StatementType.FOR);
        this.existedIterator = null;
        this.newIterator = newIterator;
        this.startValue = startValue;
        this.endValue = endValue;
        this.stepValue = stepValue;
        this.body = body;
    }

    /**
     * Метод задания величны шага счетчика.
     * @param stepValue Велична шага счетчика.
     */
    public void setStepValue(int stepValue) {
        this.stepValue = stepValue;
    }

    /**
     * Метод задания начального значения счетчика.
     * @param startValue Начальное значение счетчика.
     */
    public void setStartValue(int startValue) {
        this.startValue = startValue;
    }

    /**
     * Метод задания новой счетчика, созданного в цикле.
     * @param newIterator Счетчик, созданный в цикле.
     */
    public void setNewIterator(Expression newIterator) {
        this.newIterator = newIterator;
    }

    /**
     * Метод задания имени ранее созданной переменной: счетчика.
     * @param existedIterator Имя ранее созданного счетчика.
     */
    public void setExistedIterator(String existedIterator) {
        this.existedIterator = existedIterator;
    }

    /**
     * Метод задания ограничения счетчика.
     * @param endValue Ограничение счетчика.
     */
    public void setEndValue(int endValue) {
        this.endValue = endValue;
    }

    /**
     * Метод задания тела цикла.
     * Тело цикла задается двусвязным циклом.
     * @param body Тело цикла, заданное двусвязным списком.
     */
    public void setBody(ArrayList<AbstractStatement> body) {
        this.body = body;
    }
    
    /**
     * Метод задания тела цикла.
     * Тело цикла задается одномерным массивом.
     * @param body Тело цикла, заданное одномерным массивом.
     */
    public void setBody (AbstractStatement[] body) {
        
        this.body.clear();
        this.body.addAll(Arrays.asList(body));
    }
    
    /**
     * Метод задания тела цикла.
     * Тело цикла задается одним оператором.
     * @param item Тело цикла, заданное одним оператором.
     */
    public void setBody (AbstractStatement item) {
        
        this.body.clear();
        this.body.add(item);
    }
    
    /**
     * Метод получения оператора из тела цикла по индексу.
     * @param index Индекс получаемого оператора.
     * @return Оператор, полученный по индексу.
     */
    public AbstractStatement get (int index) {
        
        return body.get(index);
    }

    /**
     * Метод получения величины шага счетчика.
     * @return Величина шага счетчика.
     */
    public int getStepValue() {
        return stepValue;
    }

    /**
     * Метод получения начального значения счетчика.
     * @return Начальное значение счетчика.
     */
    public int getStartValue() {
        return startValue;
    }

    /**
     * Метод получения счетчика, созданного внутри цикла.
     * @return Счетчик, созданный внутри цикла.
     */
    public Expression getNewIterator() {
        return newIterator;
    }

    /**
     * Получения имени используемого счетчика (не созданного внутри цикла).
     * @return Имя используемого счетчика.
     */
    public String getExistedIterator() {
        return existedIterator;
    }

    /** 
     * Метод получения тела цикла в виде связного списка.
     * @return Тело цикла в виде связного списка.
     */
    public ArrayList<AbstractStatement> getBody() {
        return body;
    }
    
    /**
     * Метод получения тела цикла в виде одномерного массива.
     * @return Тело цикла в виде одномерного массива.
     */
    public AbstractStatement[] getBodyAsArray () {
        
        return (AbstractStatement[]) this.body.toArray();
    }

    /**
     * Метод получения конечного значения переменной цкла - счетчика.
     * @return Конечное значение счетчика.
     */
    public int getEndValue() {
        return endValue;
    }

    /**
     * Считать данные из XML файла.
     * @param node 
     */
    @Override
    public void readData(Node node) {
        
        NamedNodeMap attributes = node.getAttributes();
        Node attr = attributes.getNamedItem("type");
        this.setType(ForStmtType.fromString(attr.getNodeValue()));
         
        attr = attributes.getNamedItem("id");
        this.existedIterator = attr.getNodeValue();
        
        attr = attributes.getNamedItem("to_val");
        this.endValue = Integer.parseInt(attr.getNodeValue());
                
        attr = attributes.getNamedItem("from_val");
        this.startValue = Integer.parseInt(attr.getNodeValue());
        
        attr = attributes.getNamedItem("step_val");
        this.stepValue = Integer.parseInt(attr.getNodeValue());
        
        if (getType() == ForStmtType.WITH_DECL || getType() == ForStmtType.WITH_DECL_AND_STEP){
            IdExpression newId = new IdExpression();
            
            attr = attributes.getNamedItem("new_id");
            newId.setName(attr.getNodeValue());
            
            attr = attributes.getNamedItem("new_id_type");
            newId.setDtype(DataType.fromString(attr.getNodeValue()));
            
            this.newIterator = newId;
        }
        else{
            this.newIterator = null;
        }
            
            
        // Берем все подузлы дерева if и считываем данные 
        NodeList nodes = node.getChildNodes();
        
        for (int i = 0; i < nodes.getLength(); i++) {
            switch (nodes.item(i).getNodeName()) {                    
                case "VB_Stmt_list":
                    this.body = new ArrayList<>();
                    AbstractDeclaration.readBody(this.body, nodes.item(i));
                    break;
            }
        }
    }
    
}
