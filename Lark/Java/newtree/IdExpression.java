package newtree;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Класс выражения идентификатора.
 * @version 1.0
 */
public class IdExpression extends Expression {
    
    /* Поля класса. */
    /** Передаваемые параметры функции/процедуры или индекс массива. */
    private ArrayList<Expression> body;
    /** Тип идентификатора. */
    private int idType;
    /** Если идентификатор является массивом. */
    private boolean array = false;

    /**
     * Указаение, является ли идентификатор массивом.
     * @param array Флаг, является ли идентификатор массивом.
     */
    public void setArray(boolean array) {
        this.array = array;
    }

    /**
     * Проверка, является ли идентификатор массивом.
     * @return true, если идентифактор является массивом.
     */
    public boolean isArray() {
        return array;
    }

    /**
     * Метод задания типа идентификатора.
     * @param idType Тип идентифкатора.
     */
    public void setIdType(int idType) {
        this.idType = idType;
    }

    /**
     * Метод получения типа идентификатора.
     * @return Тип идентификатора.
     */
    public int getIdType() {
        return idType;
    }
    
    /* Тип текущего идентификатора. */
    /** Идентификатор - вызов функции. */
    public static final int CALLFUNCTION = 0x3;
    /** Идентификатор - обращение к элементу массива. */
    public static final int GETITEM = 0x4;
    /** Идентификатор - переменная. */
    public static final int VARIABLE = 0x5;
    
    /** Имя идентификатора. */
    private String name;

    /**
     * Получить имя идентификатора.
     * @return Строка с именем.
     */
    public String getName() {
        return name;
    }

    /**
     * Задать имя идентификатора.
     * @param name Строка с новым именем
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Конструктор по умолчанию.
     * Создает пустой идентификатор.
     */
    public IdExpression() {
        
        super(ID);
       body = new ArrayList();
    }

    /**
     * Конструктор с параметром.
     * Создает идентификатор с заданными параметрами функции/процедуры или 
     * индексом массива.
     * @param body Список параметров функции/процедуры или индекс массива.
     */
    public IdExpression(ArrayList<Expression> body) {
        
        super(ID);
        this.body = body;
    }
    
    /**
     * Конструктор с параметром.
     * Создает идентификатор с заданным индексом массива.
     * @param item Иденкс массива.
     */
    public IdExpression(Expression item) {
        
        super(ID);
        this.body = new ArrayList();
        
        this.body.add(item);
    }
    
    /**
     * Конструктор с параметрами.
     * Создает идентификатор с заданным списком параметров процедуры/функции.
     * @param list Список параметров процедуры/функции.
     */
    public IdExpression(Expression[] list) {
        
        super(ID);
        body = new ArrayList(Arrays.asList(list));
    }

    /**
     * Метод получения списка параметров функции/процедуры или индекса массива.
     * @return Список параметров функции/процедуры или индекса массива.
     */
    public ArrayList<Expression> getBody() {
        return body;
    }

    /**
     * Метод задания списка параметров функции/процедуры или индекса массива.
     * @param body Список параметров функции/процедуры или индекса массива.
     */
    public void setBody(ArrayList<Expression> body) {
        
        this.body.clear();
        this.body = body;
    }
    
    /**
     * Метод задания списка параметров функции/процедуры.
     * @param array Список параметров функции/процедуры.
     */
    public void setBody(Expression[] array) {
        
        this.body.clear();
        this.body.addAll(Arrays.asList(array));
    }
    
    /**
     * Метод задания индекса массива.
     * @param item Индекс массива.
     */
    public void setBody(Expression item) {
        
        this.body.set(0, item);
    }
    
    /**
     * Метод получения индекса массива.
     * @return Индекс массива.
     */
    public Expression getArrayIndex () {
        
        return this.body.get(0);
    }
    
    /**
     * Метод получения списка параметров процедуры/функции в виде массива.
     * @return Список параметров процедуры/функции в виде массива.
     */
    public Expression[] getBodyAsArray () {
        
        return (Expression[]) this.body.toArray();
    }
    
}
