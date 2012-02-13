/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codegen;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import main.JLark;
import newtree.*;


/**
 * Класс для генерации кода дерева.
 * @version 1.0
 */
public class CodeGenerator {

    /** Имя файла для сгенерированного кода. */
    private File m_classFile;
    
    /** Модуль. Корень дерева с кодом. */
    private Module m_mdl;

    /**
     * Основной конструктор создания class файла.
     * @param mdl Модуль, класс которого создаем
     */
    public CodeGenerator(Module mdl) {
        
        m_mdl = mdl;
        
        m_classFile = new File(m_mdl.getId()+".class");
        
        try{
            m_classFile.createNewFile();
            FileWriter fstream = new FileWriter(m_classFile);
            
            try (BufferedWriter out = new BufferedWriter(fstream)) {
                out.write("TEST");
            }
        } catch (IOException ex) {
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        }         
    } 
}
