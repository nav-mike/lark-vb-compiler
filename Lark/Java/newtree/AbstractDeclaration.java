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
    /** Номер строки в коде пользователя. */
    private int lineNumber;

    /**
     * Метод получения номера строки в коде пользователя.
     * @return Номер строки в коде пользователя.
     */
    public Integer getLineNumber() {
        return lineNumber;
    }

    /**
     * Метод задания номера строки в коде пользователя.
     * @param lineNumber Строка в коде пользователя.
     */
    public void setLineNumber(Integer lineNumber) {
        this.lineNumber = lineNumber;
    }

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
            paramList = new ArrayList();
            
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
    private static AbstractStatement createDimStmt(Node node){
        DimStatement newDim = new DimStatement();
        newDim.readData(node);
        return newDim;
    }
    
    /**
     * Получить из узла операцию Do .. Loop
     * @param node Исследуемый узел дерева
     * @return Полученная операция
     */
    private static AbstractStatement createDoLoopStmt(Node node){
        DoLoopStatement newDoLoop = new DoLoopStatement();
        newDoLoop.readData(node);
        return newDoLoop;
    }
    
    /**
     * Получить выражение из узла
     * @param node Исследуемый узел дерева
     * @return Полученная операция
     */   
    private static AbstractStatement createExprStmt(Node node){
        ExprStatement expr = new ExprStatement();
        expr.setExpr(Expression.createExpr(node));
        return expr;
    }
    
    /**
     * Получить из узла операцию FOR
     * @param node Исследуемый узел дерева
     * @return Полученная операция
     */      
    private static AbstractStatement createForStmt(Node node){
        ForStatement forStmt = new ForStatement();
        forStmt.readData(node);
        return forStmt;
    }
    
    /**
     * Получить из узла операцию IF
     * @param node Исследуемый узел дерева
     * @return Полученная операция
     */          
    private static AbstractStatement createIfStmt(Node node){
        IfStatement stmtIf = new IfStatement();
        stmtIf.readData(node);
        return stmtIf;
    }
    
    /**
     * Получить из узла операцию Return
     * @param node Исследуемый узел дерева
     * @return Полученная операция
     */              
    private static AbstractStatement createReturnStmt(Node node){
        ReturnStatement retStmt = new ReturnStatement();
        retStmt.readData(node);
        return retStmt;
    }
    
    /**
     * Получить из узла операцию While
     * @param node Исследуемый узел дерева
     * @return Полученная операция
     */                   
    private static AbstractStatement createWhileStmt(Node node){
        WhileStatement whileStmt = new WhileStatement();
        whileStmt.readData(node);
        return whileStmt;
    }
    
    /**
     * Считать одну операцию
     * @param node Узел дерева с операцией 
     */
    private static void readStatement(ArrayList<AbstractStatement> body, Node node) {
        
        String buffer;
        NamedNodeMap attributes = node.getAttributes();
        
        // Считывание типа операции.
        Node attr = attributes.getNamedItem("type");
        buffer = attr.getNodeValue();
        StatementType type = StatementType.fromString(buffer);      
        
        NodeList nodes = node.getChildNodes();
        
        for (int i = 0; i < nodes.getLength(); i++) {
                        
            // Добавляем в тело функции полученную операцию
            if (type == StatementType.DIM && "VB_Dim_stmt".equals(nodes.item(i).getNodeName())){
                body.add(createDimStmt(nodes.item(i)));

            } else if (type == StatementType.DO_LOOP){
                body.add(createDoLoopStmt(nodes.item(i)));

            } else if (type == StatementType.EXPRESSION){
                body.add(createExprStmt(nodes.item(i)));

            } else if (type == StatementType.FOR){
                body.add(createForStmt(nodes.item(i)));

            } else if (type == StatementType.IF){
                body.add(createIfStmt(nodes.item(i)));

            } else if (type == StatementType.RETURN){
                body.add(createReturnStmt(nodes.item(i)));

            } else if (type == StatementType.WHILE){
                body.add(createWhileStmt(nodes.item(i)));
            }      
        }
    }
    /**
     * Считывание тела процедуры или функции
     * @param node Узел с операциями
     */
    public static void readBody(ArrayList<AbstractStatement> body, Node node) {
        if (node.getChildNodes().getLength() > 0) {
            
            AbstractStatement buf;
            
            NodeList nodes = node.getChildNodes();
            
            for (int i = 0; i < nodes.getLength(); i++) {
                readStatement(body, nodes.item(i));
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
//            switch (nodes.item(i).getNodeName()) {
//                case "VB_Param_stmt_list":
//                    readParameters(nodes.item(i));
//                    break;
//                case "VB_Stmt_list":
//                    this.body = new ArrayList();
//                    readBody(body, nodes.item(i));
//                    break;
//            }
           if ("VB_Param_stmt_list".equals(nodes.item(i).getNodeName())) {
               
               readParameters(nodes.item(i));
           } else if ("VB_Stmt_list".equals(nodes.item(i).getNodeName())) {
               
               this.body = new ArrayList<AbstractStatement>();
               readBody(body, nodes.item(i));
           }
        }
    }
    
    /**
     * Считать данные из узла
     * @param node Узел дерева
     */
    @Override
    public void readData(Node node) {
        
        NamedNodeMap attributes = node.getAttributes();
        Node attr = attributes.getNamedItem("line_number");
        lineNumber = Integer.parseInt(attr.getNodeValue());

        // Считывание вложенных структур.
        NodeList nodes = node.getChildNodes();
        
        for (int i = 0; i < nodes.getLength(); i++) {
            
//            switch (nodes.item(i).getNodeName()) {
//                case "VB_Sub_stmt":
//                    readSubData(nodes.item(i),false);
//                    break;
//                case "VB_Func_stmt":
//                    readSubData(nodes.item(i),true);
//                    break;
//            }
            if ("VB_Sub_stmt".equals(nodes.item(i).getNodeName())) {
                
                readSubData(nodes.item(i), false);
            } else if ("VB_Func_stmt".equals(nodes.item(i).getNodeName())) {
                
                readSubData(nodes.item(i), true);
            }
                
        }
    }
    
}
