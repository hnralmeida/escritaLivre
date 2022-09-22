/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package h;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

/**
 *
 * @author 2021122760046
 */
public class H {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        BufferedReader dado;
        ArrayList bloco = new ArrayList();
        ArrayList cor = new ArrayList();

        int N, K, i;
        String s;

        dado = new BufferedReader(new InputStreamReader(System.in));

        try {
            s = dado.readLine();
            String[] tokens = s.split(" ");
            N = Integer.parseInt(tokens[0]);
            K = Integer.parseInt(tokens[1]);
            System.out.println(N + " " + K);

            for(i=0; i<N; i++){
                dado = new BufferedReader(new InputStreamReader(System.in));
                s = dado.readLine();
                tokens = s.split(" ");
                bloco.add(Integer.parseInt(tokens[0]));
                cor.add(Integer.parseInt(tokens[1]));
                System.out.println(bloco.get(i) + " " + cor.get(i));
                
            }

        } catch (IOException erro) {
            System.out.println("Erro na entrada de dados");
        } 
    }
    
}
