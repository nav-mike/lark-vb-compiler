/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package newtree;

import org.w3c.dom.Node;

/**
 * Интерфейс для работы с XML файлом исходного дерева
 * @version 1.0
 */
public interface XMLInterface {
    
    /**
     * Считать необходимые узлы из XML файла
     */
    public void readData(Node node);
}
