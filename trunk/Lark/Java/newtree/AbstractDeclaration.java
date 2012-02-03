package newtree;

import java.util.ArrayList;
import java.util.Arrays;
import main.*;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс описывающий процедуру/функцию.
 * @version 1.0
 */
/*
 * TODO: Примечание. Список конструкторов, если потребуется можно расширить.
 */
public class AbstractDeclaration implements XMLInterface{
    
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
     * Конструктор по умолчанию
     */
    public AbstractDeclaration(){
        name = null;
        retType = DataType.NONE;
    }
    
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
    
    /**
     * Считывание параметров процедуры или функции
     * @param node Узел с параметрами
     */
    private void readParameters(Node node) {
        if (node.getChildNodes().getLength() > 0) {
            paramList = new ArrayList<>();
            
            ParamStatement buf;
            
            NodeList nodes = node.getChildNodes();
            
            for (int i = 0; i < nodes.getLength(); i++) {
                buf = new ParamStatement();
                buf.readData(nodes.item(i));
                paramList.add(buf);
            }
        }
    }
    
    /**
     * Получить из узла операцию Dim
     * @param node Исследуемый узел дерева
     * @return Полученная операция
     */
    private AbstractStatement createDimStmt(Node node){
        return null;
    }
    
    /**
     * Получить из узла операцию Do .. Loop
     * @param node Исследуемый узел дерева
     * @return Полученная операция
     */
    private AbstractStatement createDoLoopStmt(Node node){
        return null;
    }
    
    /**
     * Получить выражение из узла
     * @param node Исследуемый узел дерева
     * @return Полученная операция
     */   
    private AbstractStatement createExprStmt(Node node){
        return null;
    }
    
    /**
     * Получить из узла операцию FOR
     * @param node Исследуемый узел дерева
     * @return Полученная операция
     */      
    private AbstractStatement createForStmt(Node node){
        return null;
    }
    
    /**
     * Получить из узла операцию IF
     * @param node Исследуемый узел дерева
     * @return Полученная операция
     */          
    private AbstractStatement createIfStmt(Node node){
        return null;
    }
    
    /**
     * Получить из узла операцию Return
     * @param node Исследуемый узел дерева
     * @return Полученная операция
     */              
    private AbstractStatement createReturnStmt(Node node){
        return null;
    }
    
    /**
     * Получить из узла операцию While
     * @param node Исследуемый узел дерева
     * @return Полученная операция
     */                   
    private AbstractStatement createWhileStmt(Node node){
        return null;
    }
    
    /**
     * Считать одну операцию
     * @param node Узел дерева с операцией 
     */
    private void readStatement(Node node) {
        
        String buffer;
        NamedNodeMap attributes = node.getAttributes();
        
        // Считывание типа операции.
        Node attr = attributes.getNamedItem("type");
        buffer = attr.getNodeValue();
        SatementType type = SatementType.fromString(buffer);      
        
        // Добавляем в тело функции полученную операцию
        if (type == SatementType.DIM){
            body.add(createDimStmt(node));
            
        } else if (type == SatementType.DO_LOOP){
            body.add(createDoLoopStmt(node));
            
        } else if (type == SatementType.EXPRESSION){
            body.add(createExprStmt(node));
            
        } else if (type == SatementType.FOR){
            body.add(createForStmt(node));
            
        } else if (type == SatementType.IF){
            body.add(createIfStmt(node));
            
        } else if (type == SatementType.RETURN){
            body.add(createReturnStmt(node));
            
        } else if (type == SatementType.WHILE){
            body.add(createWhileStmt(node));
        }      
    }
    
    /**
     * Считывание тела процедуры или функции
     * @param node Узел с операциями
     */
    private void readBody(Node node) {
        if (node.getChildNodes().getLength() > 0) {
            body = new ArrayList<>();
            
            AbstractStatement buf;
            
            NodeList nodes = node.getChildNodes();
            
            for (int i = 0; i < nodes.getLength(); i++) {
                readStatement(nodes.item(i));
            }
        }
    }
    
    /**
     * Считать данные для процедуры
     * @param node Узел дерева
     */
    private void readSubData(Node node, boolean isFunc) {
        
        NamedNodeMap attributes = node.getAttributes();
        
        // Считывание идентификатора.
        Node attr = attributes.getNamedItem("id");
        name = attr.getNodeValue();
        
        // Считывание типа возвращаемого значения.
        if (isFunc == true) {
            attr = attributes.getNamedItem("id_type");
            retType = DataType.fromString(attr.getNodeValue());
        }

        // Считывание вложенных структур.
        NodeList nodes = node.getChildNodes();
        
       for (int i = 0; i < nodes.getLength(); i++) {
            switch (nodes.item(i).getNodeName()) {
                case "VB_Param_stmt_list":
                    readParameters(nodes.item(i));
                    break;
                case "VB_Stmt_list":
                    readBody(nodes.item(i));
                    break;
            }
        }
    }
    
    /**
     * Считать данные из узла
     * @param node Узел дерева
     */
    @Override
    public void readData(Node node) {

        // Считывание вложенных структур.
        NodeList nodes = node.getChildNodes();
        
        for (int i = 0; i < nodes.getLength(); i++) {
            
            switch (nodes.item(i).getNodeName()) {
                case "VB_Sub_stmt":
                    readSubData(nodes.item(i),false);
                    break;
                case "VB_Func_stmt":
                    readSubData(nodes.item(i),true);
                    break;
            }
                
        }
    }
    
}
