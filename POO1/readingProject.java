/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package readingproject;

import java.io.*;
import java.util.Scanner;

/**
 *
 * @author hnralmeida
 */
public class ReadingProject {

    /**
     * testing functions
     */
    public static void main(String[] args) {
      
        try{
            FileInputStream file = new FileInputStream("arq.txt");
            Scanner scan = new Scanner(file);
            int num1 = scan.nextInt();
            int num2 = scan.nextInt();
            double num3 = scan.nextDouble();
            
            System.out.println(num2+num1);
            System.out.println(num3);
            
            scan.close();
        }catch (FileNotFoundException erro) {
            System.out.print("Arquivo não encontrado");
        }
        
    }
    
}
