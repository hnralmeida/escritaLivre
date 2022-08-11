/*
 * Example Project
 * 
 */
package rapidproject;

import java.io.*;

/**
 *
 * @author hnralmeida
 */
public class RapidProject {

    /**
     * testing functions
     */
    public static void main(String[] args) {
        BufferedReader dado;
        float a, n, media;
        String s = "";
        
        try {
            System.out.println("Entre com a nota 1");
            dado = new BufferedReader(new InputStreamReader(System.in));
            s = dado.readLine();
            n = Float.parseFloat(s);
            
            System.out.println("Entre com a nota 2");
            dado = new BufferedReader(new InputStreamReader(System.in));
            s = dado.readLine();
            a = Float.parseFloat(s);
            
            media = (a + n) / 2;
            System.out.println("Média: " + media);
        } catch (IOException erro) {
            System.out.println("Erro na entrada de dados");
        } catch (NumberFormatException erro) {
            System.out.println("Houve erro na conversão, digite apenas caracteres numericos");
        }

    }

}
