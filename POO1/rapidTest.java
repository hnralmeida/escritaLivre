/*
 * Example Project
 * 
 */
package rapidproject;

import java.io.*;

/**
 *
 * @hnralmeida
 */
public class RapidProject {
    
    /**
     * testing functions
     */
    public static void main(String[] args) {
        System.out.println("Inicio");
        
        DataInputStream dado;
        String s = "";
        float a,n;
        try{
            System.out.println("Entre com a nota 1");
            dado = new DataInputStream(System.in);
            s = dado.readLine( );
            n = Float.parseFloat(s);
            System.out.println("Entre com a nota 2");
            dado = new DataInputStream(System.in);
            s = dado.readLine();
            a= Float.parseFloat(s);
        
            if ( (n) >(a) ) {
                System.out.println("Ayo n>a");
            }else{
                System.out.println("Hey a>n");
            }
        }
        catch (IOException erro){
            System.out.println("Erro na entrada de dados");
        }
        catch ( NumberFormatException erro ){
            System.out.println("Houve erro na conversão, digite apenas caracteres numericos");
        }

    }
    
}
