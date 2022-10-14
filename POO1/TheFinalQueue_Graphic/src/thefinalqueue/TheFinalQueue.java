/*
*   =========================================================================================
*   AUTORES: 	
*   			Henrique Almeida de Oliveira
*   Disciplina: Programacao Orientada a Objetos
*   Rascunho do Trabalho de POO1
*   =========================================================================================
*/
package thefinalqueue;

import graphic.Container;
import java.io.*;
/**
 *
 * @2021122760046
 */
public class TheFinalQueue {

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) {
        try{
            Match teste = new Match("lado1.txt", "lado2.txt");
            Container tela = new Container(teste);
            teste.fight(tela);
        }catch (FileNotFoundException erro) {
            System.out.print("Arquivos não encontrados");
        }catch (InterruptedException erro){
            System.out.println("Esse "+ erro);
        }catch(IOException erro){
            System.out.println("Esse "+ erro);
        }
    }
}
