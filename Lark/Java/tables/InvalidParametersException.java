package tables;

/**
 * Класс исключения.
 * Исключение выбрасывается, когда используются неверные параметры.
 * А именно константы неверного типа в классе ConstantsTableItem.
 * @version 1.0
 */
public class InvalidParametersException extends Exception {

    /**
     * Конструктор с параметром.
     * @param string Сообщение исключения.
     */
    InvalidParametersException(String string) {
        super(string);
    }
    
}
