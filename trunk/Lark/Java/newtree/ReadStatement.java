package newtree;

/**
 * Класс оператора чтения одного символа из стандартного потока ввода.
 * @version 1.0
 */
public class ReadStatement extends AbstractStatement {
    
    /* Поля класса. */
    /** Считанный символ из стандартного потока ввода. */
    private Character data;

    /**
     * Метод получения символа, считанного из стандартного потока ввода.
     * @return Символ, полученный из стандартного потока ввода.
     */
    public Character getData() {
        return data;
    }

    /**
     * Метод задания символа, считанного из стандартного потока ввода.
     * @param data Символ, полученный из стандартного потока ввода.
     */
    public void setData(Character data) {
        this.data = data;
    }

    /**
     * Конструктор с параметром.
     * Создает оператор считывания символа из стандартного потока ввода,
     * с заданным символом.
     * @param data Символ, полученный из стандартного потока ввода.
     */
    public ReadStatement(Character data) {
        
        super(READ);
        this.data = data;
    }
    
}
