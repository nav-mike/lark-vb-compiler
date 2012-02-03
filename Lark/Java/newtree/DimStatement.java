package newtree;

import java.util.ArrayList;
import java.util.Arrays;
import org.w3c.dom.Node;

/**
 * Класс, описыващий блок объявления переменных.
 * @version 1.0
 */
public class DimStatement extends AbstractStatement {
    
    /* Поля класса. */
    /** Список объявлений переменных. */
    private ArrayList<AsExpression> bodyMain;

    /**
     * Конструктор с параметрами.
     * Создает объект класса с заданным списком объявлений переменных.
     * @param bodyMain Список объявленных переменных в виде связного списка.
     */
    public DimStatement(ArrayList<AsExpression> bodyMain) {
        
        super(SatementType.DIM);
        this.bodyMain = bodyMain;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает объект класса с заданным списком объявлений переменных.
     * @param bodyMain Список объявлений переменных в виде одномерного массива.
     */
    public DimStatement (AsExpression[] bodyMain) {
        
        super(SatementType.DIM);
        this.bodyMain = new ArrayList<>(Arrays.asList(bodyMain));
    }
    
    /**
     * Конструтктор с параметрами.
     * Создает объект класса с заданным списком объявлений переменных.
     * @param item Список объявлений переменных в виде одного оператора.
     */
    public DimStatement (AsExpression item) {
        
        super(SatementType.DIM);
        this.bodyMain = new ArrayList<>();
        this.bodyMain.add(item);
    }

    /**
     * Метод получения списка объявлений переменных в виде двусвязного списка.
     * @return Список объявлений переменных в виде двусвязного списка.
     */
    public ArrayList<AsExpression> getBodyMain() {
        return bodyMain;
    }
    
    /**
     * Метод получения списка объявлений переменных в виде одномерного массива.
     * @return Список объявлений переменных в виде одномерного массива.
     */
    public AsExpression[] getBodyMainAsArray () {
        
        return (AsExpression[]) bodyMain.toArray();
    }

    /**
     * Метод задания списка объявлений переменных в виде связного списка.
     * @param bodyMain Список объявлений в виде связного списка.
     */
    public void setBodyMain(ArrayList<AsExpression> bodyMain) {
        this.bodyMain = bodyMain;
    }
    
    /**
     * Метод задания списка объявлений переменных в виде одномерного массива.
     * @param bodyMain Список объявлений в виде одномерного массива.
     */
    public void setBodyMain (AsExpression[] bodyMain) {
        
        this.bodyMain.clear();
        this.bodyMain.addAll(Arrays.asList(bodyMain));
    }
    
    /**
     * Метод задания списка объявлений переменных в виде одного оператора.
     * @param item Список объявлений в виде одного оператора.
     */
    public void setBodyMain (AsExpression item) {
        
        this.bodyMain.clear();
        this.bodyMain.add(item);
    }

    @Override
    public void readData(Node node) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
