package newtree;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс объявляемых переменных.
 * Возможно использование инициализируемого значения, но только если хэш
 * массивов (имя, размер) пуст и в контейнере переменных одна переменная.
 * @version 1.0
 */
public class AsExpression implements XMLInterface{
        
    /* Поля класса. */
    /** Список объявленных переменных. */
    private ArrayList<String> variables;
    
    /** Инициализирующее значение. */
    private Expression initData;
    
    /** Хэш массивов. */
    private HashMap<String, Integer> arrays;
    
    private ArrayList<Expression> arrayInit = null;
    
    private DataType type;

    public void setType(DataType type) {
        this.type = type;
    }

    public DataType getType() {
        return type;
    }

    AsExpression(){
        variables = null;
        initData = null;
        arrays = null;
        arrayInit = null;
        type = null;  
    }
    
    
    /**
     * Конструктор с параметрами.
     * Создает объект класса с заданным списком переменных.
     * @param variables Список объявленных переменных.
     */
    public AsExpression(DataType type, ArrayList<String> variables) {
        
        this.variables = variables;
        this.type = type;
        this.initData = null;
        this.arrays = null;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает объект класса с заданным списком массивов.
     * @param arrays Список массивов.
     */
    public AsExpression (DataType type, HashMap<String, Integer> arrays) {
        
        this.arrays = arrays;
        this.type = type;
        this.initData = null;
        this.variables = null;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает объект класс с заданной переменной и ее инициализирующем значением.
     * @param variable Объявленная переменная.
     * @param initData Инициализирующее значение.
     */
    public AsExpression (DataType type, String variable, Expression initData) {
        
        this.type = type;
        this.variables = new ArrayList();
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
        
        this.variables = new ArrayList(Arrays.asList(variables));
        this.arrays = null;
        this.initData = null;
    }

    
    public AsExpression (DataType type,HashMap<String, Integer> arrays, ArrayList<Expression> arrayInit) {
        
        this.type = type;
        this.arrays = arrays;
        this.arrayInit = arrayInit;
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
    
    /**
     * Чтение данных из списка операторов
     * @param node Узел. из которого читаем
     */
    public void readFromIdList(Node node){
        
        // Считывание вложенных структур.
        NodeList nodes = node.getChildNodes();
        NamedNodeMap attributes;
        Node attr;
                
        for (int i = 0; i < nodes.getLength(); i++) {
            // Если это список идентификаторов.
//            switch (nodes.item(i).getNodeName()) {
//                case "VB_Expr":
//                    
//                    if (variables == null)
//                        variables = new ArrayList();
//                    
//                    attributes = nodes.item(i).getAttributes();
//                    attr = attributes.getNamedItem("expr_string");
//                    variables.add(attr.getNodeValue());
//                    break;
//                    
//               case "VB_Array_expr":
//                   
//                    if (arrays == null)
//                        arrays = new HashMap();
//
//                    attributes = nodes.item(i).getAttributes();
//                    attr = attributes.getNamedItem("id");
//                    String name = attr.getNodeValue();
//
//                    attr = attributes.getNamedItem("size");
//                    int size = Integer.parseInt(attr.getNodeValue());
//
//                    arrays.put(name, size);
//                    
//                    getArrayInitData(nodes.item(i));
//                    break;
//                    
//                case "VB_Id_list":
//                    readFromIdList(nodes.item(i));
//                    break;
//            }
            if ("VB_Expr".equals(nodes.item(i).getNodeName())) {
                
                if (variables == null)
                    variables = new ArrayList();

                attributes = nodes.item(i).getAttributes();
                attr = attributes.getNamedItem("expr_string");
                variables.add(attr.getNodeValue());
            } else if ("VB_Array_expr".equals(nodes.item(i).getNodeName())) {
                
                if (arrays == null)
                    arrays = new HashMap();

                attributes = nodes.item(i).getAttributes();
                attr = attributes.getNamedItem("id");
                String name = attr.getNodeValue();

                attr = attributes.getNamedItem("size");
                int size = Integer.parseInt(attr.getNodeValue());

                arrays.put(name, size);

                getArrayInitData(nodes.item(i));
            } else if ("VB_Id_list".equals(nodes.item(i).getNodeName())) {
                
                readFromIdList(nodes.item(i));
            }
        }
        
    }
     
    public void getArrayInitData(Node node){
        NodeList nodes = node.getChildNodes();
                    
        if (arrayInit == null && nodes.getLength() != 0)
            arrayInit = new ArrayList();
            
        for (int i = 0; i < nodes.getLength(); i++) {
            this.arrayInit.add(Expression.createExpr(nodes.item(i)));
        }
    }

    /**
     * Чтение данных из узла
     * @param node 
     */
    @Override
    public void readData(Node node) {
        NamedNodeMap attributes = node.getAttributes();
       
        // Считывание типа.
        Node attr = attributes.getNamedItem("id_type");
        type = DataType.fromString(attr.getNodeValue());

        // Считывание вложенных структур.
        NodeList nodes = node.getChildNodes();

        for (int i = 0; i < nodes.getLength(); i++) {
            // Если это список идентификаторов.
//            switch (nodes.item(i).getNodeName()) {
//                case "VB_Expr__expr":
//                    initData = Expression.createExpr(nodes.item(i));
//                    break;
//
//                case "VB_Id_list":
//                    readFromIdList(nodes.item(i));
//                    break;
//            }
            if ("VB_Expr__expr".equals(nodes.item(i).getNodeName())) {
                
                initData = Expression.createExpr(nodes.item(i));
            } else if ("VB_Id_list".equals(nodes.item(i).getNodeName())) {
                
                readFromIdList(nodes.item(i));
            }
        }
    }
    
}
