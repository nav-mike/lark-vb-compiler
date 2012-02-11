package newtree;

import java.util.ArrayList;
import org.w3c.dom.Node;

/**
 * Класс, описывающий оператор цикла while.
 * @version 1.0
 */
public class WhileStatement extends AbstractStatement{
    
    /* Поля класса. */
    /** Условие выполнения цикла. */
    private Expression condition;
    /** Тело цикла. */
    private ArrayList<AbstractStatement> body;

    public WhileStatement(Expression condition, ArrayList<AbstractStatement> body) {
        
        super(StatementType.WHILE);
        this.condition = condition;
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
     * Метод задания условия выполнения цикла.
     * @param condition Условие выполнения цикла.
     */
    public void setCondition(Expression condition) {
        this.condition = condition;
    }

    /**
     * Метод получения тела цикла в виде связного списка.
     * @return Тело цикла.
     */
    public ArrayList<AbstractStatement> getBody() {
        return body;
    }

    /**
     * Метод задания тела цикла в виде связного списка.
     * @param body Тело цикла.
     */
    public void setBody(ArrayList<AbstractStatement> body) {
        this.body = body;
    }
    
    /**
     * Метод задания тела цикла в виде массива.
     * @param body Тело цикла.
     */
    public void setBody(AbstractStatement[] body) {
        
        this.body.clear();
        for (int i = 0; i < body.length; i++) {
            
            this.body.add(body[0]);
        }
    }
    
    /**
     * Метод получения тела цикла в виде одномерного массива.
     * @return Тело цикла.
     */
    public AbstractStatement[] getBodyAsArray () {
        
        return (AbstractStatement[]) body.toArray();
    }
    
    /**
     * Метод получения одного оператора из тела цикла по индексу.
     * @param index Индекс требуемого тела цикла.
     * @return Оператор по заданному индексу.
     */
    public AbstractStatement getItem (int index) {
        
        return this.body.get(index);
    }

    @Override
    public void readData(Node node) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
