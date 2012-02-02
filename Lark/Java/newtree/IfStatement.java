package newtree;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Класс условного оператора.
 * @version 1.0
 */
public class IfStatement extends AbstractStatement {
    
    /* Поля класса. */
    /** Условие условного оператора. */
    private Expression condition;
    /** Операторы выполняемые при истинном условии. */
    private ArrayList<AbstractStatement> bodyMain;
    /** Операторы выполняемые при ложном условии. */
    private ArrayList<AbstractStatement> bodyAlter;
    
    /**
     * Метод получения оператора зи спика операторов, выполняемых при ложности
     * условия по индексу.
     * @param index Индекс получаемого оператора.
     * @return Оператор, получаемый по индексу.
     */
    public AbstractStatement getFromAlter (int index) {
        
        return bodyAlter.get(index);
    }
    
    /**
     * Метод получения оператора из списка операторов, выполняемых при истинности
     * условия по индексу.
     * @param index Индекс получаемого оператора.
     * @return Оператор, полченный по индексу.
     */
    public AbstractStatement getFromMain (int index) {
        
        return bodyMain.get(index);
    }

    /**
     * Конструктор с параметрами.
     * Создает условный оператор с заданными условием и списками операторов при
     * истинности и ложности условия.
     * Входной список при истинности условия задается в виде одного оператора.
     * Входной список при ложности условия задается в виде массива операторов.
     * @param condition Проверяемое условие.
     * @param itemMain Оператор, выполняемый при истинности условия.
     * @param bodyAlter Массив операторов, выполняемый при ложности условия.
     */
    public IfStatement (Expression condition, AbstractStatement itemMain,
            AbstractStatement[] bodyAlter) {
        
        super(IF);
        this.condition = condition;
        this.bodyMain = new ArrayList();
        this.bodyMain.add(itemMain);
        this.bodyAlter = new ArrayList(Arrays.asList(bodyAlter));
    }
    
    /**
     * Конструктор с параметрами.
     * Создает условный оператор с заданными условием и списками операторов при
     * истинности и ложности условия.
     * Входной список при истинности условия задается в виде массива операторов.
     * Входной список при ложности условия задается в виде одного оператора.
     * @param condition Проверяемое условие.
     * @param bodyMain Массив операторов, выполняемых при истинности условия.
     * @param itemAlter Оператор, выполняемый при ложности условия.
     */
    public IfStatement (Expression condition, AbstractStatement[] bodyMain, AbstractStatement itemAlter) {
        
        super(IF);
        this.condition = condition;
        this.bodyMain = new ArrayList(Arrays.asList(bodyMain));
        this.bodyAlter = new ArrayList();
        this.bodyAlter.add(itemAlter);
    }
    
    /**
     * Конструктор с параметрами.
     * Создает условный оператор с заданным условием и списками операторов при 
     * истинности и ложности условия.
     * Входные списки задаются при помощи одного оператора.
     * Используется, если все ветки условного оператора содержат по одному действию.
     * @param condition Проверяемое условие.
     * @param itemMain Оператор, выполняемый при истинности условия.
     * @param itemAlter Оператор, выполняемый при истинности условия.
     */
    public IfStatement (Expression condition, AbstractStatement itemMain, AbstractStatement itemAlter) {
        
        super(IF);
        this.condition = condition;
        this.bodyMain = new ArrayList();
        this.bodyMain.add(itemMain);
        this.bodyAlter = new ArrayList();
        this.bodyAlter.add(itemMain);
    }
    
    /**
     * Конструктор с параметрами.
     * Создает условный оператор с заданным условием и списками операторов при
     * истинности и ложности условий.
     * Входные списки заданы в виде массивов.
     * @param condition Проверяемое условие.
     * @param bodyMain Массив операторов, выполянемых при истинности условия.
     * @param bodyAlter  Массив операторов, выполняемых при ложности условия.
     */
    public IfStatement (Expression condition, AbstractStatement[] bodyMain, AbstractStatement[] bodyAlter) {
        
        super(IF);
        this.condition = condition;
        this.bodyMain = new ArrayList(Arrays.asList(bodyMain));
        this.bodyAlter = new ArrayList(Arrays.asList(bodyAlter));
    }
    
    /**
     * Конструктор с параметрами.
     * Создает условный оператор с заданным условием и списками операторов при
     * истинности и ложности условий.
     * @param condition Проверяемое условие.
     * @param bodyMain Список операторов, выполняемых при истинности условия.
     * @param bodyAlter Список операторов, выполняемых при ложности условия.
     */
    public IfStatement(Expression condition, ArrayList<AbstractStatement> bodyMain, ArrayList<AbstractStatement> bodyAlter) {
        
        super(IF);
        this.condition = condition;
        this.bodyMain = bodyMain;
        this.bodyAlter = bodyAlter;
    }
    
    /**
     * Метод получения списка операторов, выполняемых при ложности условия
     * в виде массива.
     * @return Массив операторов, выполняемых при ложности условия.
     */
    public AbstractStatement[] getBodyAlterAsArray () {
        
        return (AbstractStatement[]) bodyAlter.toArray();
    }
    
    /**
     * Метод получения списка операторов, выполняемых при истинности условия
     * в виде массива.
     * @return Массив операторов, выполняемых при истинности условия.
     */
    public AbstractStatement[] getBodyMainAsArray () {
        
        return (AbstractStatement[]) bodyMain.toArray();
    }
    
    /**
     * Метод задания списка операторов, выполняемых при ложности условия, если
     * список должен состоять только из одного оператора.
     * @param item Оператор, из которого должен состоять список.
     */
    public void setBodyAlter (AbstractStatement item) {
        
        bodyAlter.clear();
        bodyAlter.add(item);
    }
    
    /**
     * Метод задания списка операторов, выполняемых при истинности условия, если
     * список должен состоять только из одного оператора.
     * @param item Оператор, из которого состоит список.
     */
    public void setBodyMain (AbstractStatement item) {
        
        bodyMain.clear();
        bodyMain.add(item);
    }
    
    /**
     * Метод очищения списка операторов, выполянемых при ложности условия.
     */
    public void clearAlter () {
        
        bodyAlter.clear();
    }
    
    /**
     * Метод очищения списка операторов, выполняемых при истинности условия.
     */
    public void clearMain () {
        
        bodyMain.clear();
    }
    
    /**
     * Метод добавления одного оператора в список операторов, выполняемых
     * при ложности условия.
     * @param item Добавляемый оператор.
     */
    public void addStatementToAlter (AbstractStatement item) {
        
        bodyAlter.add(item);
    }
    
    /**
     * Метод добавления одного оператора в список операторов, выполняемых
     * при истинности условия.
     * @param item Добавляемый оператор.
     */
    public void addStatementToMain (AbstractStatement item) {
        
        bodyMain.add(item);
    }
    
    /**
     * Метод задания операторов, выполняемых при ложном условии.
     * @param bodyAlter Массив операторов, выполняемых при ложном условии.
     */
    public void setBoayAlter(AbstractStatement[] bodyAlter) {
        
        this.bodyAlter.clear();
        this.bodyAlter.addAll(Arrays.asList(bodyAlter));
    }
    
    /**
     * Метод задания операторов, выполняемых при истинном условии.
     * @param bodyMain Массив операторов, выполняемых при истинном условии.
     */
    public void setBodyMain (AbstractStatement[] bodyMain) {
        
        this.bodyMain.clear();
        this.bodyMain.addAll(Arrays.asList(bodyMain));
    }

    /**
     * Метод задания операторов, выполянемых при ложном условии.
     * @param bodyAlter Операторы, выполняемы при ложном условии.
     */
    public void setBodyAlter(ArrayList<AbstractStatement> bodyAlter) {
        this.bodyAlter = bodyAlter;
    }

    /**
     * Метод задания операторов выполняемых при истинном условии.
     * @param bodyMain Операторы выполняемые при истинном условии.
     */
    public void setBodyMain(ArrayList<AbstractStatement> bodyMain) {
        this.bodyMain = bodyMain;
    }

    /**
     * Метод получения операторов выполняемых при ложном условии.
     * @return Операторы, выполняемые при ложном условии.
     */
    public ArrayList<AbstractStatement> getBodyAlter() {
        return bodyAlter;
    }

    /**
     * Метод получения операторов выполняемых при истинном условии.
     * @return Операторы, выполняемые при истинном условии.
     */
    public ArrayList<AbstractStatement> getBodyMain() {
        return bodyMain;
    }

    /**
     * Метод задания условия оператора.
     * @param condition Условие оператора.
     */
    public void setCondition(Expression condition) {
        this.condition = condition;
    }

    /**
     * Метод получения условия оператора.
     * @return Условие оператора.
     */
    public Expression getCondition() {
        return condition;
    }
    
}
