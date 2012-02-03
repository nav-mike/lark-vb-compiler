/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package newtree;

import org.w3c.dom.Node;

/**
 * Интерфейс для работы с XML файлом исходного дерева
 * @author Alexander
 */
public interface XMLInterface {
    
    /**
     * Считать необходимые узлы из XML файла
     */
    public void readData(Node node);
}
