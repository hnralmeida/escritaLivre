/*
*   =========================================================================================
*   AUTORES: 	
*   			Henrique Almeida de Oliveira
*   Disciplina: Programacao Orientada a Objetos
*   Rascunho do Trabalho de POO1
*   =========================================================================================
*/
package thefinalqueue;

import java.io.*;
/**
 *
 * @2021122760046
 */
public class TheFinalQueue {

    /**
     * @brief Age of Mythology – The Final Queue
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try{
            Match teste = new Match("lado1.txt", "lado2.txt");
            teste.fight();
        }catch (FileNotFoundException erro) {
            System.out.print("Arquivos não encontrados");
        }catch(IOException erro){
            System.out.println("Esse "+ erro);
        }
    }
}
