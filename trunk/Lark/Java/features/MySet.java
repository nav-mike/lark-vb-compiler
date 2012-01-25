package features;

import java.util.Collection;
import java.util.Iterator;
import java.util.Set;
import java.util.Vector;

/**
 * Класс множества.
 * @author Mikhail Navrotskiy
 */
public class MySet<T> implements Set{
    
    /* Поля класса. */
    /** Массив элементов. */
    private Vector<T> values;

    /**
     * Метод получения размера множества.
     * @return Размер множества.
     */
    @Override
    public int size() {
        
        return values.size();
    }

    /**
     * Метод проверки множества на пустоту.
     * @return true, если множество пустое.
     */
    @Override
    public boolean isEmpty() {
        
        return values.isEmpty();
    }

    /**
     * Метод проверки, содержится ли данный элемент в множестве.
     * @param o Проверяемый элемент.
     * @return true, если элемент содержится.
     */
    @Override
    public boolean contains(Object o) {
        
        return values.contains(o);
    }

    /**
     * Метод получения итератора на множество.
     * @return Итератор на множество.
     */
    @Override
    public Iterator iterator() {
        
        return values.iterator();
    }

    /**
     * Метод получения массива из множества.
     * @return Массив элементов множества.
     */
    @Override
    public Object[] toArray() {
        
        return values.toArray();
    }

    /**
     * Метод получения массива из множества.
     * @param a Входной массив.
     * @return Выходной массив.
     */
    @Override
    public Object[] toArray(Object[] a) {
        
        return values.toArray(a);
    }

    /**
     * Метод добавления элемента в множество.
     * @param e Добавляемый элемент.
     * @return true, если добавлено.
     */
    @Override
    public boolean add(Object e) {
        
        if (contains(e)) return false;
        
        return values.add((T)e);
    }

    /**
     * Метод удаления элемента из множества.
     * @param o Удаляемый элемент.
     * @return true, если элемент удален.
     */
    @Override
    public boolean remove(Object o) {
        
        return values.remove(o);
    }

    /**
     * Метод проверки совпадения элементов множества с коллекцией.
     * @param c Коллеция.
     * @return true, если совпадают.
     */
    @Override
    public boolean containsAll(Collection c) {
        
        return values.containsAll(c);
    }

    /**
     * Метод добавления коллекции в множество.
     * @param c Коллекция.
     * @return true, если произошло добавление.
     */
    @Override
    public boolean addAll(Collection c) {
        
        if (containsAll(c)) return false;
        
        else {
            
            Iterator it = c.iterator();
            
            while (it.hasNext()) {
                
                add(it.next());
            }
        }
        
        return true;
    }

    /**
     * @deprecated 
     * @param c
     * @return 
     */
    @Override
    public boolean retainAll(Collection c) {return true;}

    /**
     * Метод удаления всех указанных элементов из коллекции.
     * @param c Коллекция.
     * @return true, если удаление прошло успешно.
     */
    @Override
    public boolean removeAll(Collection c) {
        
        return values.removeAll(c);
    }

    /**
     * Метод очищения множества.
     */
    @Override
    public void clear() {
        
        values.clear();
    }
    
}
