/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package main;

import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Mikhail Navrotskiy
 */
public class JLark {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            String line;
        OutputStream stdin = null;
        InputStream stderr = null;
        InputStream stdout = null;

          // launch EXE and grab stdin/stdout and stderr
          Process process = Runtime.getRuntime ().exec ("__lark__.exe test.txt");
//          stdin = process.getOutputStream ();
          stderr = process.getErrorStream ();
          stdout = process.getInputStream ();

//          // "write" the parms into stdin
//          line = "param1" + "\n";
//          stdin.write(line.getBytes() );
//          stdin.flush();
//
//          line = "param2" + "\n";
//          stdin.write(line.getBytes() );
//          stdin.flush();
//
//          line = "param3" + "\n";
//          stdin.write(line.getBytes() );
//          stdin.flush();
//
//          stdin.close();
//
          // clean up if any output in stdout
          BufferedReader brCleanUp =
            new BufferedReader (new InputStreamReader (stdout));
          while ((line = brCleanUp.readLine ()) != null) {
            System.out.println ("[Stdout] " + line);
          }
          brCleanUp.close();

          // clean up if any output in stderr
          brCleanUp =
            new BufferedReader (new InputStreamReader (stderr));
          while ((line = brCleanUp.readLine ()) != null) {
            System.out.println ("[Stderr] " + line);
          }
          brCleanUp.close();
        } catch (IOException ex) {
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
