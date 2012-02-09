package tables;

import java.util.HashMap;

/**
 * Класс таблицы констант.
 * Хранит все методы главного класса.
 * @version 1.0
 */
public class ConstantsTable {
    
    /* Поля класса. */
    /** Карта всех констант класса. */
    private HashMap<Integer, ConstantsTableItem> items;
    /** Текущий индекс локальной переменной. */
    private int gIndex;

    /** 
     * Метод преобразования информации из объекта класса в строку.
     * @return Строка с всей таблицей констант.
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
     * Создает пустую таблицу констант.
     */
    public ConstantsTable() {
        
        this.items = new HashMap();
        gIndex = 0;
    }
    
    /**
     * Метод получения константы по индексу.
     * @param index Индекс получаемой константы.
     * @return Константа, полученная по индексу.
     */
    public ConstantsTableItem get (int index) {
        
        return items.get(index);
    }
    
    /**
     * Метод добавления константы в таблицу.
     * @param item Добавляемая константа.
     */
    public void add (ConstantsTableItem item) {
        
        item.setNumber(++gIndex);
        this.items.put(gIndex, item);
    }
    
    /**
     *  Метод удаления константы по индексу.
     * @param index Индекс удаляемой константы.
     */
    public void remove (int index) {
        
        this.items.remove(index);
    }
    
    /**
     * Метод очищения списка констант.
     */
    public void clear () {
        
        this.items.clear();
        gIndex = 0;
    }
    
    /**
     * Метод получения размера списка констант.
     * @return Размер списка констант.
     */
    public int size () {
        
        return this.items.size();
    }
    
}
