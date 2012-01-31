package main;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * Класс класса.
 * @author Mikhail Navrotskiy
 */
public class SClass {
    
    public SConstant constClass; 
            
    /** Список элементов таблицы констант. */
    public HashMap<Integer, SConstant> m_constantsTable;
    
    /** Таблица методов класса. */
    public HashMap<String, SFunction> m_functionsTable;
    
    /** Список ошибок. */
    public ArrayList<CError> m_errorList;
    
    /** Текущий индекс */
    public int constIndex = 1;

    public SClass() {
        m_constantsTable = new HashMap<Integer, SConstant>();
    }
    
    /**
     * Добавить новую константу в таблицу
     * @param type Тип конс
     * @param type Тип константы.
     * @param utfConst Строковое значение.
     * @param intConst Целое значение.
     * @param first Ссылка на другую константу.
     * @param second Ссылка на другую константу.
     * @return Ссылка на константу
     */
    public SConstant addNewConstant(ConstantType type, String utfConst, int intConst, SConstant first, SConstant second){
        
        SConstant newConst = new SConstant(constIndex,type, utfConst, intConst, first, second);
        
        m_constantsTable.put(new Integer(constIndex), newConst);
        
        constIndex++;
        
        return newConst;
    }
}
