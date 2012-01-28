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
//import javax.lang.model.element.Element;
import javax.swing.JTable;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;
import org.w3c.dom.Element;
        
        
/**
 * 
 * @version 2.0
 */
public class JLark {
    
    /** Список элементов таблицы констант. */
    static private HashMap<Integer, SConstant> m_constantsTable = new HashMap<Integer, SConstant>();
    /** Таблица методов класса. */
    static private HashMap<SConstant, SFunction> m_functionsTable = new HashMap<SConstant, SFunction>();
    /** Список ошибок. */
    static private ArrayList<CError> m_errorList = new ArrayList<CError>();
    
    /** Корень получаемого дерева. */
    static private JVBModuleStmt m_module;
    
    static private int currentIndex = 0;
    
    public static Document doc;
    
    static private int index(){
        return ++currentIndex;
    }
    
    /**
     * Функция считывания XML файла.
     * @param filename Имя файла.
     */
    private static JVBModuleStmt readXML (String filename) throws ParserConfigurationException, SAXException, IOException {
        
        JVBModuleStmt result = null;
        DocumentBuilderFactory f = DocumentBuilderFactory.newInstance();
        f.setValidating(false);
        DocumentBuilder builder = f.newDocumentBuilder();
        Document doc = builder.parse(new File(filename));
        
        NodeList nodes = doc.getChildNodes();
        
        for (int i = 0; i < nodes.getLength(); i++) {
            
            if ("VB_Module_stmt".equals(nodes.item(i).getNodeName()))
                result = new JVBModuleStmt(nodes.item(i));
        }
        
       
        return result;
        
    }
    
    /**
     * Парсим модуль 
     * @param module Собсно сам модуль 
     */
    public static void parseModule(JVBModuleStmt module){
        
    }
    
    /**
     * Создание таблиц констант и методов
     */
    public static void addTreeNodeToCTable(Object node){
        if (node == null)
            return;
        
        // Если повстречали модуль
        if(node.getClass() == JVBModuleStmt.class){
            parseModule((JVBModuleStmt)node);  
        }
    }
    
    /**
     * Заполнить список элементов таблицы констант
     */
    static private void fillSConstantList(){
        
        SConstant codeConst = new SConstant(index(), ConstantType.CONSTANT_Utf8, "Code", -1, null,null);
                // Добавлям в таблицу ИМЯ МОДУЛЯ
        SConstant CTableItem = new SConstant(index(), ConstantType.CONSTANT_Utf8, 
                m_module.getName(), -1, null,null);

        // Создаем ссылку на класс с данным именем модуля
        SConstant classItem  = new SConstant(index(), ConstantType.CONSTANT_Class, 
                Integer.toString(CTableItem.getId()), CTableItem.getId(), CTableItem, null);

        // Добавляем их в таблицу
        addToCTable(CTableItem);
        addToCTable(classItem);
        addToCTable(codeConst);
    }
    
    /**
     * Функция добавления константы в таблицу констант.
     * @param constant Добавляемая константа.
     */
    static private void addToCTable(SConstant constant){
        
        if (!m_constantsTable.containsValue(constant))
            m_constantsTable.put(constant.getId(), constant);
        
    }
    
    /**
     * Сохраним данные в файл для проверки
     * @throws ParserConfigurationException
     * @throws SAXException
     * @throws IOException
     * @throws TransformerConfigurationException
     * @throws TransformerException 
     */
    public static void saveToXML() throws ParserConfigurationException, SAXException, IOException, TransformerConfigurationException, TransformerException {
        DocumentBuilderFactory fact = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = fact.newDocumentBuilder();
        doc = builder.newDocument();

        m_module.write(null);
        
        TransformerFactory transformerFactory = TransformerFactory.newInstance();
        Transformer transformer = transformerFactory.newTransformer();
        DOMSource source = new DOMSource(doc);
        StreamResult result = new StreamResult(new File("JavaTree.xml"));

        transformer.transform(source, result);
    }
    public static String readXMLLine(BufferedReader buf) throws IOException{
        String result = "";
        char ch;
        do{
            ch = (char)buf.read();
            
            if (ch != '\n')
                result += ch;
            
        }while(ch != '>');
        
        return result;
    }
    
    
    public static void verifyTree(){
        try{
            BufferedReader first = new BufferedReader(new FileReader(new File("tree.xml").getAbsoluteFile()));
            BufferedReader second = new BufferedReader(new FileReader(new File("JavaTree.xml").getAbsoluteFile()));
            
            String firstBuf = "0";
            String secondBuf = "0";
            
            int i = 1;
            boolean isError = false;
            
            while(firstBuf != null && secondBuf != null && isError == false){
                firstBuf = readXMLLine(first);
                secondBuf = readXMLLine(second);
                
                if (i!=1){
                    if (firstBuf != null && secondBuf != null && firstBuf.equals(secondBuf) == false){
                        isError = true;

                        System.out.println("\nError on " + Integer.toString(i) + " string!\n");
                    }
                    else
                        i++;
                }
                else
                    i++;
            }
            
            first.close();
            second.close();
            
            if (isError == false)
                System.out.println("\nNo errors!\n");
            
        } catch (IOException e){
            throw new RuntimeException(e);
        }
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        // Считываем данные из xml файла
        try {
            m_module = readXML("tree.xml");
        } catch (ParserConfigurationException ex) {
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SAXException ex) {
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        try {
            saveToXML();
        } catch (ParserConfigurationException ex){
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SAXException ex){
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex){
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        } catch (TransformerConfigurationException ex){
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        } catch (TransformerException ex){
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        verifyTree();
        
        fillSConstantList();
        addTreeNodeToCTable(m_module);
        
    }
}

//        TableConstant tc = new TableConstant();
//        JTable[] tables = new JTable[2];
//        String[] titles = new String[2];
//        for (int i = 1; i < currentIndex + 1; i++) {
//            tc.addRow(m_constantsTable.get(i).getType().toString(), m_constantsTable.get(i).getUtfConst());
//        }
//        tables[0] = tc.getTable();
//        tables[1] = tc.getTable();
//        titles[0] = "Таблица констант";
//        titles[1] = "Таблица qweqwe";
//        IntFrame intFrame = new IntFrame(tables, titles);