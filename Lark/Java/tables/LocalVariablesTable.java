package tables;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;
import newtree.DataType;

/**
 * Класс таблицы локальных переменных.
 * Хранит локальные переменные для функции/процедуры.
 * @version 1.0
 */
public class LocalVariablesTable {
    
    /* Поля класса. */
    /** Список локальных переменных. */
    private HashMap<Integer,LocalVariablesTableItem> items;
    /** Индекс новой локальной переменной. */
    private int gIndex;
    
    /**
     * Метод проверки наличия локальной переменной в таблице.
     * @param name Имя локальной переменной.
     * @return true, если локальная переменная присутствует в таблице.
     */
    public boolean contains (String name) {
        
        boolean flag = false;
        
        Set<Integer> set = items.keySet();
        Iterator<Integer> it = set.iterator();
        
        while (it.hasNext()) {
            
            Integer i = it.next();
            
            if (items.get(i).getName().equals(name)) {
                
                flag = true;
                break;
            }
        }
        
        return flag;
    }
    
    /**
     * Метод проверки наличия локальной переменной в таблице.
     * @param item Проверяемая локальная переменная.
     * @return true, если локальная переменная присутствует.
     */
    public boolean contains (LocalVariablesTableItem item) {
        
        boolean flag = false;
        
        Set<Integer> set = items.keySet();
        Iterator<Integer> it = set.iterator();
        
        while (it.hasNext()) {
            
            Integer i = it.next();
            
            if (items.get(i).getName().equals(item.getName())) {
                
                flag = true;
                break;
            }
        }
        
        return flag;
    }
    
    /**
     * Метод получения типа локальной перемнной по имени.
     * @param name Имя локальной переменной.
     * @return Тип локальной переменной.
     */
    public DataType getTypeFor (String name) {
        
        DataType td = DataType.NONE;
        
        Set<Integer> set = items.keySet();
        Iterator<Integer> it = set.iterator();
        
        while (it.hasNext()) {
            
            Integer i = it.next();
            
            if (items.get(i).getName().equals(name)) {
                
                td = items.get(i).getType();
                break;
            }
        }
        
        return td;
    }

    /**
     * Метод преобразования таблицы локальных переменных в строку.
     * @return Строка - таблица локальных переменных.
     */
    @Override
    public String toString() {
        
        String result = "";
        
        for (int i = 0; i < items.size(); i++) {
            
            result += Integer.toString(i) + "\t" + items.get(i).toString() + "\n";
        }
        
        return result;
    }

    /**
     * Конструктор по умолчанию.
     * Создает пустую таблицу.
     */
    public LocalVariablesTable() {
        
        this.items = new HashMap();
        gIndex = 0;
    }
    
    /**
     * Метод добавления локальной переменной в таблицу.
     * @param item Локальная переменная.
     */
    public void add (LocalVariablesTableItem item) {
        
        item.setNumber(++gIndex);
        this.items.put(gIndex, item);
    }
    
    /**
     * Метод получения локальной переменной по индексу.
     * @param index Индекс локальной переменной.
     * @return Локальная переменная, полученная по индексу.
     */
    public LocalVariablesTableItem get (int index) {
        
        return this.items.get(index);
    }
    
    /**
     * Метод получения номера локальной переменной по имени.
     * @param name Имя локальной переменной.
     * @return Номер локальной переменной, полученный по имени.
     */
    public int getNumberByName (String name) {
        
        Set<Integer> keys = items.keySet();
        Iterator<Integer> i = keys.iterator();
        int result = -1;
        
        while (i.hasNext() && result == -1){
            Integer buf = i.next();
            
            if (items.get(buf).getName().equals(name)){
                result = items.get(buf).getNumber();
            }
        }
        
        return result;
    }
    
    /**
     * Метод проверяющий, является ли данная локальная переменная массивом.
     * @param lvname Имя локальной переменной.
     * @return true, если локальная переменная является массивом.
     */
    public boolean itemIsArray (String lvname) {
        
        boolean flag = false;
        
        Set<Integer> set = items.keySet();
        Iterator<Integer> it = set.iterator();
        
        while (it.hasNext()) {
            
            Integer i = it.next();
            
            if (items.get(i).getName().equals(lvname)) {
                
                if (items.get(i).getArraySize() != -1)
                    flag = true;
                
                break;
            }
        }
        
        return flag;
    }
    
    /**
     * Метод очистки списка локальных переменных.
     */
    public void clear () {
        
        this.items.clear();
    }
    
    /**
     * Метод получения размера списка.
     * @return Размер списка.
     */
    public int size () {
        
        return this.items.size();
    }
    
    /**
     * Метод удаления элемента таблицы.
     * @param index Индекс удаляемого элемента.
     */
    public void remove (int index) {
        
        this.remove(index);
    }
    
}
