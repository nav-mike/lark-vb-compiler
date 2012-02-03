package newtree;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

/**
 * Класс объявляемых переменных.
 * Возможно использование инициализируемого значения, но только если хэш
 * массивов (имя, размер) пуст и в контейнере переменных одна переменная.
 * @version 1.0
 */
public class AsExpression {
    
    /* Поля класса. */
    /** Список объявленных переменных. */
    private ArrayList<String> variables;
    /** Инициализирующее значение. */
    private Expression initData;
    /** Хэш массивов. */
    private HashMap<String, Integer> arrays;

    /**
     * Конструктор с параметрами.
     * Создает объект класса с заданным списком переменных.
     * @param variables Список объявленных переменных.
     */
    public AsExpression(ArrayList<String> variables) {
        
        this.variables = variables;
        this.initData = null;
        this.arrays = null;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает объект класса с заданным списком массивов.
     * @param arrays Список массивов.
     */
    public AsExpression (HashMap<String, Integer> arrays) {
        
        this.arrays = arrays;
        this.initData = null;
        this.variables = null;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает объект класс с заданной переменной и ее инициализирующем значением.
     * @param variable Объявленная переменная.
     * @param initData Инициализирующее значение.
     */
    public AsExpression (String variable, Expression initData) {
        
        this.variables = new ArrayList<>();
        this.variables.add(variable);
        this.initData = initData;
        this.arrays = null;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает объект класса с заданными переменными в виде одномерного массива.
     * @param variables Массив объявляемых переменных.
     */
    public AsExpression (String[] variables) {
        
        this.variables = new ArrayList<>(Arrays.asList(variables));
        this.arrays = null;
        this.initData = null;
    }

    /**
     * Метод получения списка объявленных массивов.
     * @return Список объявленных массивов.
     */
    public HashMap<String, Integer> getArrays() {
        return arrays;
    }

    /**
     * Метод получения инициализирующего значения.
     * @return Инициализирующее значение.
     */
    public Expression getInitData() {
        return initData;
    }

    /**
     * Метод получения списка объявленных переменных.
     * @return Список объявленных переменных.
     */
    public ArrayList<String> getVariables() {
        return variables;
    }
    
    /**
     * Метод получения списка объявленных переменных.
     * @return Список объявленных переменных в виде одномерного массива.
     */
    public String[] getVariablesAsArray () {
        
        return (String[]) this.variables.toArray();
    } 

    /**
     * Метод задания списка массивов.
     * @param arrays Список массивов.
     */
    public void setArrays(HashMap<String, Integer> arrays) {
        this.arrays = arrays;
    }

    /**
     * Метод задания инициализируещего значения.
     * @param initData Инициализирующее значение.
     */
    public void setInitData(Expression initData) {
        this.initData = initData;
    }

    /**
     * Метод задания списка объявленных переменных в виде связного списка.
     * @param variables Список объявленных переменных.
     */
    public void setVariables(ArrayList<String> variables) {
        this.variables = variables;
    }
    
    /**
     * Метод задания списка объявленных переменных в виде одномерного массива.
     * @param variables Список объявленных переменных.
     */
    public void setVariables (String[] variables) {
        
        this.variables.clear();
        this.variables.addAll(Arrays.asList(variables));
    }
    
    /**
     * Метод задания списка объявленных переменных в виде одного элемента.
     * @param variable Объявленная переменная.
     */
    public void setVariables (String variable) {
        
        this.variables.clear();
        this.variables.add(variable);
    }
    
}
