package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author paccode
 */
public class Main {
    
    public static double transFour(double N, double base){
        double num=0, cof, resto, fator=0;
        resto = Math.floor(N/base);
        cof = N-resto;
        num = cof;
        do{
            System.out.println(num);
            fator++;
            resto = Math.floor(resto/(base*Math.pow(base, fator)));
            cof = N-resto-num;
            num = num+cof*Math.pow(10, fator);            
        }while(Math.pow(base, fator)<N);
        
        return num;
    }
    
    public static int contaFour(double num){
        String s = String.valueOf(num);
        int i, four=0;
        for(i=0; i<s.length(); i++){
            //System.out.println(s.charAt(i));
            if(s.charAt(i)=='4') four++;
        }
        return four;
    }

    public static void main(String[] args) {
        BufferedReader dado;
        double N, i, transFourmed, maior=5;
        String s;

        dado = new BufferedReader(new InputStreamReader(System.in));

        try {
            s = dado.readLine();
            N = Double.parseDouble(s);
            for(i=5; i<N; i++){
                transFourmed = transFour(N, i);
                if ( contaFour(transFourmed) > maior){
                    maior = i;
                }
            }
            System.out.println((int)maior);
        }catch (IOException erro) {
            System.out.println("Erro na entrada de dados");
        }
    }
    
}
