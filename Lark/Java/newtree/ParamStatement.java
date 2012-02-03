package newtree;

import main.JVBIdType;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;

/**
 * Класс, описывающий параметр функции.
 * @version 1.0
 */
public class ParamStatement implements XMLInterface{
    
    /* Поля класса. */
    /** Имя параметра. */
    private String name;
    /** Является ли параметр массивом.*/
    private boolean isArray;
    /** Тип параметра. */
    private DataType type;

    /**
     * Конструктор по умолчанию
     */
    public ParamStatement(){
        this.name = null;
        this.isArray = false;
        this.type = DataType.NONE;
    }
    
    
    /**
     * Конструктор с параметрами.
     * Создает параметр функции по заданным входным данным.
     * @param name Имя параметра.
     * @param isArray Флаг: массив ли это.
     * @param type Тип параметра.
     */
    public ParamStatement(String name, boolean isArray, DataType type) {
        this.name = name;
        this.isArray = isArray;
        this.type = type;
    }

    /**
     * Метод полчения имени параметра.
     * @return Имя параметра.
     */
    public String getName() {
        return name;
    }

    /**
     * Метод получения типа параметра.
     * @return Тип параметра.
     */
    public DataType getType() {
        return type;
    }

    /**
     * Метод полчучения флага: массив ли это.
     * @return Флаг: массив ли это.
     */
    public boolean isIsArray() {
        return isArray;
    }

    /**
     * Метод задания флага: массив ли это.
     * @param isArray Флаг: массив ли это.
     */
    public void setIsArray(boolean isArray) {
        this.isArray = isArray;
    }

    /**
     * Метод задания имени параметра.
     * @param name Имя параметра.
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Метод задания типа параметра.
     * @param type Тип параметра.
     */
    public void setType(DataType type) {
        this.type = type;
    }

    @Override
    public void readData(Node node) {
        
        String buffer;
        
        NamedNodeMap attributes = node.getAttributes();
        // Считывание передачи по ссылке.
        Node attr = attributes.getNamedItem("is_by_ref");
        buffer = attr.getNodeValue();
                  
        if (buffer.equals("0"))
            isArray = false;
        else
            isArray = true;
        
        // Считывание имени параметра.
        attr = attributes.getNamedItem("id");
        buffer = attr.getNodeValue();
        name = buffer;
        
        // Считывание типа параметра.
        attr = attributes.getNamedItem("id_type");
        buffer = attr.getNodeValue();
        type = DataType.fromString(buffer);
    }
    
}
