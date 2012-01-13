package jlark;

/**
 * Класс для хранения корня дерева.
 * @version 1.0
 */
public class JVBModuleStmt {
    
    /* Поля класса. */
    /** Идентификатор модуля. */
    private String m_id;
    /** Список операций функции Main. */
    private JVBStmtList m_stmtList;
    /** Список глобальных функций и переменных модуля. */
    private JVBDeclStmtList m_declList;
    
    /**
     * Метод задания модулю имени.
     * @param name Новое имя модуля.
     */
    public void setName (String name) {
        
        m_id = name;
    }
    
    /**
     * Метод получения имени модуля.
     * @return Имя текущего модуля.
     */
    public String getName () {
        
        return m_id;
    }
    
    /**
     * Метод задания списка операций функции Main.
     * @param list Новый список операций функции Main.
     */
    public void setMainStmt (JVBStmtList list) {
        
        m_stmtList = list;
    }
    
    /**
     * Метод получения списка операций функции Main.
     * @return Список операций функции Main.
     */
    public JVBStmtList getMainStmt () {
        
        return m_stmtList;
    }
    
    /**
     * Метод задания списка глобальных функций и переменных модуля.
     * @param list Новый списк глобальных функций и переменных модуля.
     */
    public void setDeclStmtList (JVBDeclStmtList list) {
        
        m_declList = list;
    }
    
    /**
     * Метод получения списка глобальных функций и переменных модуля.
     * @return Список глобальных функций и переменных модуля.
     */
    public JVBDeclStmtList getDeclStmtList () {
        
        return m_declList;
    }
}
