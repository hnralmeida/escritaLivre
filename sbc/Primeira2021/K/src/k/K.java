/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package k;

import java.io.*;
import java.util.Scanner;

/**
 *
 * @author 2021122760046
 */
public class K {

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
        try(FileInputStream file1 = new FileInputStream("entrada.txt");
                Scanner scan = new Scanner(file1)){
            String line = scan.nextLine();
            String[] tokens = line.split(" ");
            int T_rest = Integer.parseInt(tokens[0]);
            int D_fly = Integer.parseInt(tokens[1]);
            int M_num = Integer.parseInt(tokens[2]);
            int Y[] = new int[M_num];
            int i=0, meal=0;
            
            while(scan.hasNextLine()){
                Y[i] = scan.nextInt();
                i++;
            }
           
            int fly[] = new int[D_fly];

            for(i=0; i<D_fly; i++){
                if( (meal<M_num) && (i==Y[meal]) ){
                    fly[i]=1;
                    meal++;
                }else{
                    fly[i]=0;
                }
            }
            i=0; meal=0;
            
            while( (meal<D_fly) && (i<T_rest) ){
                if( fly[meal]==1 ){
                    i=0;
                }else{
                    i++;
                }
                meal++;
            }
            
            PrintWriter arq = new PrintWriter("saida.txt");
            
            int j;
            for(j=0; j<D_fly; j++){
                System.out.println(fly[j]);
            }
            
            if(i>=T_rest){
                arq.println("Y");
                System.out.println("Y");
                
            }else{
                arq.println("N");
                System.out.println("N");
            }
            arq.close();
        }catch (FileNotFoundException erro) {
            System.out.print("Arquivo do Lado 1 não encontrado");
        }
        
        
    }
    
}
