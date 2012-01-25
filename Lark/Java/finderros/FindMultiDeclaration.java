package finderros;

import features.MySet;
import main.JVBDimStmt;
import main.JVBStmt;
import main.JVBStmtList;
import main.JVBStmtType;

/**
 * Класс проверки текста программы на наличие множественной инициализации.
 * @author alexander
 */
public class FindMultiDeclaration {
    
    /* Поля класса. */
    /** Множество локальных переменных. */
    private static MySet<String> lVar;
    
    private static void fillSet (JVBStmtList flist) {
        
        JVBStmt item = flist.getFirst();
        
        while (item != null) {
            
            if (item.getType() == JVBStmtType.DIM_E) {
                
                JVBDimStmt dim = (JVBDimStmt)item.getValue();
                // TODO: перебрать внутренний лист.
            }
            
            item = item.getNext();
        }
    }
    
}
