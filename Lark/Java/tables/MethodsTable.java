package tables;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

/**
 * Класс таблица методов класса.
 * @version 1.0
 */
public class MethodsTable {
    
    /* Поля класса. */
    /** Список методов класса. */
    private HashMap<Integer,MethodsTableItem> items;
    /** Количество методов в классе. */
    private int gIndex;
    
    /**
     * Метод проверки наличия метода в таблице.
     * @param item Проверяемый метод.
     * @return true, если метод присутствует.
     */
    public boolean contains (MethodsTableItem item) {
        
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
     * Вернуть номер метода из таблицы констант по имени.
     * @param name Имя метода
     * @return Номер метода в таблице констант
     */
    public int getTableNumberByName(String name){
        int num = -1;
        
        Set<Integer> set = items.keySet();
        Iterator<Integer> it = set.iterator();
        
        while (it.hasNext()) {
            
            Integer i = it.next();
            
            if (items.get(i).getName().equals(name)) {
                
                num = items.get(i).getConstsTableNum();
                break;
            }
        }
        
        return num;
    }
    
    /**
     * Вернуть метод по имени.
     * @param name Имя метода
     * @return Номер метода в таблице констант
     */
    public MethodsTableItem getMethodByName(String name){
        MethodsTableItem result = null;
        
        Set<Integer> set = items.keySet();
        Iterator<Integer> it = set.iterator();
        
        while (it.hasNext()) {
            
            Integer i = it.next();
            
            if (items.get(i).getName().equals(name)) {
                
                result = items.get(i);
                break;
            }
        }
        
        return result;
    }

    /**
     * Метод преобразования таблицы методов класса в строку.
     * @return Строка - таблица методов класса.
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
    public MethodsTable() {
        
        gIndex = 0;
        this.items = new HashMap();
    }
    
    /**
     * Метод очистки таблицы.
     */
    public void clear () {
        
        this.gIndex = 0;
        this.items.clear();
    }
    
    /**
     * Метод получения размера таблицы методов.
     * @return Размер таблицы.
     */
    public int size () {
        
        return items.size();
    }
    
    /**
     * Метод удаления метода из таблицы.
     * @param index Индекс удаляемого метода.
     */
    public void remove (int index) {
        
        items.remove(index);
    }
    
    /**
     * Метод получения метода по индексу.
     * @param index Индекс метода.
     * @return Метод полученный по индексу.
     */
    public MethodsTableItem get (int index) {
        
        return this.items.get(index);
    }
    
    /**
     * Метод добавления метода в таблицу методов.
     * @param item Добавляемый метод.
     */
    public void add (MethodsTableItem item) {
        
        item.setNumber(++gIndex);
        this.items.put(gIndex, item);
    }
    
}
