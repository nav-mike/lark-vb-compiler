package newtree;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Класс описывающий процедуру/функцию.
 * @version 1.0
 */
/*
 * TODO: Примечание. Список конструкторов, если потребуется можно расширить.
 */
public class AbstractDeclaration {
    
    /* Поля класса. */
    /** Имя функции/процедуры. */
    private String name;
    /** Тип возвращаемого значения. NONE для процедуры. */
    private DataType retType;
    /** Список параметров. */
    private ArrayList<ParamStatement> paramList;
    /** Тело функции/процедуры. */
    private ArrayList<AbstractStatement> body;

    /**
     * Конструктор с параметрами.
     * Создает функцию/процедуру с заданными параметрами.
     * @param name Имя функции/процедуры.
     * @param retType Тип возвращаемого значения.
     * @param paramList Список параметров функции/процедуры.
     * @param body Тело функции/процедуры.
     */
    public AbstractDeclaration(String name, DataType retType, ArrayList<ParamStatement> paramList, ArrayList<AbstractStatement> body) {
        this.name = name;
        this.retType = retType;
        this.paramList = paramList;
        this.body = body;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает процедуру с заданными параметрами.
     * @param name Имя процедуры.
     * @param paramList Список параметров процедуры.
     * @param body Тело процедуры.
     */
    public AbstractDeclaration(String name, ArrayList<ParamStatement> paramList, ArrayList<AbstractStatement> body) {
        this.name = name;
        this.retType = DataType.NONE;
        this.paramList = paramList;
        this.body = body;
    }

    /**
     * Метод задания списка входных параметров в виде двусвязного списка.
     * @param paramList Список входных параметров.
     */
    public void setParamList(ArrayList<ParamStatement> paramList) {
        this.paramList = paramList;
    }
    
    /**
     * Метод добавления параметра в список параметров.
     * @param item Новый, добавляемый параметр.
     */
    public void addToParamList (ParamStatement item) {
        
        this.paramList.add(item);
    }
    
    /**
     * Метод задания списка входных параметров в виде одного параметра.
     * @param item Входной параметр.
     */
    public void setParamList (ParamStatement item) {
        
        this.paramList.clear();
        this.paramList.add(item);
    }
    
    /**
     * Метод задания списка входных параметров в виде одномерного массива.
     * @param paramList Список входных параметров.
     */
    public void setParamList (ParamStatement[] paramList) {
        
        this.paramList.clear();
        this.paramList.addAll(Arrays.asList(paramList));
    }

    /**
     * Метод задания типа возвращаемого значения.
     * @param retType Тип возвращаемого значения.
     */
    public void setRetType(DataType retType) {
        this.retType = retType;
    }

    /**
     * Метод задания имени функции/процедуры.
     * @param name Имя функции/процедуры.
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Метод задания тела функции/процедуры в виде двусвязного списка.
     * @param body Тело функции/процедуры.
     */
    public void setBody(ArrayList<AbstractStatement> body) {
        this.body = body;
    }
    
    /**
     * Метод задания тела функции/процедуры в виде одномерного массива.
     * @param body Тело функции/процедуры.
     */
    public void setBody (AbstractStatement[] body) {
        
        this.body.clear();
        this.body.addAll(Arrays.asList(body));
    }
    
    /**
     * Метод задания тела функции/процедуры в виде одного оператора.
     * @param item Тело функции/процедуры.
     */
    public void setBody (AbstractStatement item) {
        
        this.body.clear();
        this.body.add(item);
    }
    
    /**
     * Метод добавления оператора в тело функции.
     * @param item Добавляемый оператор.
     */
    public void addToBody (AbstractStatement item) {
        
        this.body.add(item);
    }

    /**
     * Метод получения тела функции/процедуры в виде двусвязного списка.
     * @return Тело функции/процедуры в виде двусвязного списка.
     */
    public ArrayList<AbstractStatement> getBody() {
        return body;
    }
    
    /**
     * Метод получения тела функции/процедуры в виде одномерного массива.
     * @return Тело функции/процедуры в виде одномерного массива.
     */
    public AbstractStatement[] getBodyAsArray () {
        
        return (AbstractStatement[]) this.body.toArray();
    }
    
    /**
     * Метод получения оператора из тела функции/процедуры пр индексу.
     * @param index Индекс получаемого оператора.
     * @return Опертор, полученный по индексу.
     */
    public AbstractStatement getFromBody (int index) {
        
        return this.body.get(index);
    }

    /**
     * Метод получения имени функции/процедуры.
     * @return Имя функции/процедуры.
     */
    public String getName() {
        return name;
    }

    /**
     * Метод получения списка параметров функции/процедуры в виде связного 
     * списка.
     * @return Список параметров функции/процедуры.
     */
    public ArrayList<ParamStatement> getParamList() {
        return paramList;
    }
    
    /**
     * Метод получения списка параметров функции/процедуры в виде одномерного
     * массива.
     * @return Список параметров функции.
     */
    public ParamStatement[] getParamListAsArray () {
        
        return (ParamStatement[]) this.paramList.toArray();
    }
    
    /**
     * Метод получения входного параметра функции/процедуры по индексу.
     * @param index Индекс искомого параметра.
     * @return Искомый по индексу параметр.
     */
    public ParamStatement getFromParamList (int index) {
        
        return paramList.get(index);
    }

    /**
     * Метод получения типа возвращаемого значения.
     * @return Тип возвращаемого значения.
     */
    public DataType getRetType() {
        return retType;
    }
    
}
