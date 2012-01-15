/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package main;

import guidebug.IntFrame;
import guidebug.TableConstant;
import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JTable;

/**
 *
 * @author Mikhail Navrotskiy
 */
public class JLark {

    /** Список элементов таблицы констант. */
    static private HashMap<Integer, SConstant> m_constantsList = new HashMap<Integer, SConstant>();
    /** Таблица методов класса. */
    static private HashMap<SConstant, SFunction> m_functionsList = new HashMap<SConstant, SFunction>();
    /** Список ошибок. */
    static private ArrayList<CError> m_errorList = new ArrayList<CError>();
    
    /** Корень получаемого дерева. */
    static private JVBModuleStmt m_module;
    
    /**
     * Заполнить список элементов таблицы констант
     */
    static private void fillSConstantList(Object attr){
        
        SConstant sc = null;
        
        if (attr.getClass() == JVBModuleStmt.class) {
            
       //     sc = new SConstant(m_constantsList.size(), ConstantType.CONSTANT_Utf8, null, intConst, sc, sc)
        }
            
        addToCList(sc);
        
    }
    
    /**
     * Функция добавления ошибки в список.
     * @param error Добавляемая ошибка.
     */
    static private void addToEList (CError error) {
        
        m_errorList.add(error);
    }
            
    /**
     * Функция добавления константы в таблицу констант.
     * @param constant Добавляемая константа.
     */
    static private void addToCList(SConstant constant){
        
        if (constant.getId() > 0 && constant.getId() == m_constantsList.size())
            m_constantsList.put(constant.getId(), constant);
        
    }
    
    /**
     * Функция добавления функции в таблицу функции.
     * @param function Добавляемая функция.
     */
    static private void AddToFList (SFunction function) {
        
        m_functionsList.put(function.getMethodRef(), function);
    }
        
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       
        
        TableConstant tc = new TableConstant();
        JTable[] tables = new JTable[1];
        String[] titles = new String[1];
        tc.addRow("UTF-8", "mass");
        tables[0] = tc.getTable();
        titles[0] = "Таблица констант";
        IntFrame intFrame = new IntFrame(tables, titles);
        //        try {
        //            String line;
        //        OutputStream stdin = null;
        //        InputStream stderr = null;
        //        InputStream stdout = null;
        //
        //          // launch EXE and grab stdin/stdout and stderr
        //          Process process = Runtime.getRuntime ().exec ("__lark__.exe test.txt");
        ////          stdin = process.getOutputStream ();
        //          stderr = process.getErrorStream ();
        //          stdout = process.getInputStream ();
        //
        ////          // "write" the parms into stdin
        ////          line = "param1" + "\n";
        ////          stdin.write(line.getBytes() );
        ////          stdin.flush();
        ////
        ////          line = "param2" + "\n";
        ////          stdin.write(line.getBytes() );
        ////          stdin.flush();
        ////
        ////          line = "param3" + "\n";
        ////          stdin.write(line.getBytes() );
        ////          stdin.flush();
        ////
        ////          stdin.close();
        ////
        //          // clean up if any output in stdout
        //          BufferedReader brCleanUp =
        //            new BufferedReader (new InputStreamReader (stdout));
        //          while ((line = brCleanUp.readLine ()) != null) {
        //            System.out.println ("[Stdout] " + line);
        //          }
        //          brCleanUp.close();
        //
        //          // clean up if any output in stderr
        //          brCleanUp =
        //            new BufferedReader (new InputStreamReader (stderr));
        //          while ((line = brCleanUp.readLine ()) != null) {
        //            System.out.println ("[Stderr] " + line);
        //          }
        //          brCleanUp.close();
        //        } catch (IOException ex) {
        //            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        //        }
    }
    
}
