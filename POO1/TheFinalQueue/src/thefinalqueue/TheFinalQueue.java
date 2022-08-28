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
import java.util.Scanner;

/**
 *
 * @2021122760046
 */
public class TheFinalQueue {

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
        try(FileInputStream file1 = new FileInputStream("lado1.txt");Scanner scan = new Scanner(file1)){
            while(scan.hasNextLine()){
                String line = scan.nextLine();
                String[] tokens = line.split(" ");
                int type = Integer.parseInt(tokens[0]);
                String name = tokens[1];
                int age = Integer.parseInt(tokens[2]);
                int weight = Integer.parseInt(tokens[3]);
                System.out.println(type + " " + name + " " + age + " " + weight);
            }
        }catch (FileNotFoundException erro) {
            System.out.print("Arquivo do Lado 1 não encontrado");
        }
        
        try(FileInputStream file2 = new FileInputStream("lado2.txt");Scanner scan = new Scanner(file2)){
            while(scan.hasNextLine()){
                String line = scan.nextLine();
                String[] tokens = line.split(" ");
                int type = Integer.parseInt(tokens[0]);
                String name = tokens[1];
                int age = Integer.parseInt(tokens[2]);
                int weight = Integer.parseInt(tokens[3]);
                System.out.println(type + " " + name + " " + age + " " + weight);
            }
            
        }catch (FileNotFoundException erro) {
            System.out.print("Arquivo do Lado 2 não encontrado");
        }
    }
}
