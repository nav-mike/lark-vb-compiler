package newtree;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Класс описывающий модуль, что по сути является пакетом/пространством имен.
 * @version 1.0
 */
public class Module {
    
    /* Поля класса. */
    /** Имя модуля. */
    private String id;
    /** Список реализованных функций/процедур. */
    private ArrayList<AbstractDeclaration> declList;

    /**
     * Конструктор с параметрами.
     * Создает модуль с заданными параметрами.
     * @param id Идентификатор модуля.
     * @param declList Список функций/процедур.
     */
    public Module(String id, ArrayList<AbstractDeclaration> declList) {
        this.id = id;
        this.declList = declList;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает модуль с процедурой Main.
     * @param id Идентификатор модуля.
     * @param item Процелура Main.
     */
    public Module(String id, AbstractDeclaration item) {
        
        this.id = id;
        this.declList = new ArrayList<>();
        this.declList.add(item);
    }
    
    /**
     * Метод добавления функции/процедуры в модуль.
     * @param item Добавляемая функция/процедура.
     */
    public void add (AbstractDeclaration item) {
        
        this.declList.add(item);
    }

    /**
     * Метод задания функций/процедур модуля.
     * @param item Процедура/фнукнция.
     */
    public void setDeclList (AbstractDeclaration item) {
        
        this.declList.clear();
        this.declList.add(item);
    }
    
    /**
     * Метод задания списка функций/процедур модуля.
     * @param declList Одномерный массив функций/процедур.
     */
    public void setDeclList (AbstractDeclaration[] declList) {
        
        this.declList.clear();
        this.declList.addAll(Arrays.asList(declList));
    }
    
    /**
     * Метод задания списка функций/процедур модуля.
     * @param declList Связный список функций/процедур.
     */
    public void setDeclList(ArrayList<AbstractDeclaration> declList) {
        this.declList = declList;
    }

    /**
     * Метод задания имени модуля.
     * @param id Имя модуля.
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * Метод получения имени модуля.
     * @return Имя модуля.
     */
    public String getId() {
        return id;
    }

    /**
     * Метод получения списка реализованных функций/процедур.
     * @return Связный список функций/процедур.
     */
    public ArrayList<AbstractDeclaration> getDeclList() {
        return declList;
    }
    
    /**
     * Метод получения списка реализованных функций/процедур.
     * @return Одномерный массив функций/процедур.
     */
    public AbstractDeclaration[] getDeclListAsArray() {
        
        return (AbstractDeclaration[]) this.declList.toArray();
    }
    
    /**
     * Метод получения функции/процедуры из списка по индексу.
     * @param index Индекс искомой функции/процедуры.
     * @return Функция/процедура полученная по индексу.
     */
    public AbstractDeclaration get (int index) {
        
        return declList.get(index);
    }
    
}
