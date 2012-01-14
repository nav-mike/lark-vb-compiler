package main;

/**
 * Класс описания ошибки.
 * @version 1.0
 */
public class CError {
    
    /* Поля класса. */
    /** Функция, в которой находится ошибка. */
    private String errorFunc;
    /** Сообщение об ошибке. */
    private String errorMessage;

    /**
     * Метод задания сообщения об ошибке.
     * @param errorMessage Сообщение об ошибке.
     */
    public void setErrorMessage(String errorMessage) {
        this.errorMessage = errorMessage;
    }

    /**
     * Метод задания функции с ошибкой.
     * @param errorFunc Имя функции с ошибкой.
     */
    public void setErrorFunc(String errorFunc) {
        this.errorFunc = errorFunc;
    }

    /** 
     * Метод получение ошибок.
     * @return Получение сообщения об ошибке.
     */
    public String getErrorMessage() {
        return errorMessage;
    }

    /**
     * Метол получения функции, в котором мы ловим ошибку.
     * @return Функция с ошибкой.
     */
    public String getErrorFunc() {
        return errorFunc;
    }

    /**
     * Конструктор по умолчанию.
     * Инициализирует все null.s
     */
    public CError() {
        
        errorFunc = null;
        errorMessage = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param errorFunc Функция, в которой находится ошибка.
     * @param errorMessage Сообщение об ошибке.
     */
    public CError(String errorFunc, String errorMessage) {
        this.errorFunc = errorFunc;
        this.errorMessage = errorMessage;
    }
    
}
