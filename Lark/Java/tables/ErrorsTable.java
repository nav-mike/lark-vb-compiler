package tables;

import java.util.ArrayList;
import java.util.Iterator;
import main.CError;

/**
 * Таблица отловленных ошибок.
 * @version 1.0
 */
public class ErrorsTable {
    
    /* Поля класса. */
    /** Список всех отловленных ошибок. */
    private ArrayList<CError> errors;

    /**
     * Метод преобразования таблицы отловленных ошибок в строку.
     * @return Строка со всеми отловленными ошибками.
     */
    @Override
    public String toString() {
        
        String result = "";
        Iterator<CError> it = errors.iterator();
        
        while (it.hasNext()) {
            
            CError item = it.next();
            
            result += item.getErrorFunc() + "\t" + item.getErrorMessage() + "\n";
        }
        
        return result;
    }

    /**
     * Конструктор по умолчанию.
     * Создает пустую таблицу отловленных ошибок.
     */
    public ErrorsTable(ArrayList<CError> errors) {
        
        this.errors = errors;
    }
    
    /**
     * Метод получения ошибки по заданному индексу.
     * @param index Индекс искомой ошибки.
     * @return Ошибка, полученная по индексу.
     */
    public CError get (final int index) {
        
        return errors.get(index);
    }
    
    /**
     * Метод добавления ошибки в список.
     * @param item Добавляемая ошибка.
     */
    public void add (final CError item) {
        
        this.errors.add(item);
    }
    
    /**
     * Метод получения размера списка ошибок.
     * @return Размер списка ошибок.
     */
    public int size () {
        
        return this.errors.size();
    }
    
}
