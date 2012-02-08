package tables;

import java.util.HashMap;

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
     * Конструктор по умолчанию.
     * Создает пустую таблицу.
     */
    public MethodsTable() {
        
        gIndex = 0;
        this.items = new HashMap<>();
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
