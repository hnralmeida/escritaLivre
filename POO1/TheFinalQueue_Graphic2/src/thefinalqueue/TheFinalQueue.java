/*
*   =========================================================================================
*   AUTORES: 	
*   			Henrique Almeida de Oliveira
                        Luiz Eduardo Marchiori

*   Disciplina: Programacao Orientada a Objetos
*   Trabalho de POO1 - The Final Queue
*   =========================================================================================
*/
package thefinalqueue;

import java.io.*;
import Users/User/Downloads/Java%20FX/javafx-sdk-19/lib/javafx.web.jar!/;
/**
 *
 * @2021122760046
 */
public class TheFinalQueue extends Application{

    /**
     * @brief Age of Mythology – The Final Queue
     * @param args the command line arguments
     * cria uma variável teste com o tipo Match (LinkedList), cria uma luta
     * com os arquivos de texto - lado1 e lado2
     */
    public static void main(String[] args) {
        // tenta
        try{
            Match teste = new Match("lado1.txt", "lado2.txt");
            teste.fight();
        }catch (FileNotFoundException erro) {
            //exceção de não achar o arquivo
            System.out.print("Arquivos não encontrados");
        }catch(IOException erro){
            // tipo de tratamento de qualquer erro que houver
            System.out.println(erro);
        }
    }
}
