package main;

import java.util.ArrayList;
import java.util.Iterator;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        BufferedReader dado;
        String s;
        dado = new BufferedReader(new InputStreamReader(System.in));
        
        Scanner scan = new Scanner(System.in);
        Scanner line = new Scanner(System.in);
        int faltas = line.nextInt();
        int resposta, adicional;
        ArrayList vetor = new ArrayList();
        for (int i = 0; i < faltas; i++) {
            String linha = scan.nextLine();
            String[] nums = linha.split(" ");
            int minuto = Integer.parseInt(nums[0]);
            String[] tempo = nums[1].split("T");
            int hora = Integer.parseInt(tempo[0]);
            if (hora == 1) {
                if (minuto > 45) {
                    adicional = minuto - 45;
                    resposta = 45;
                } else {
                    resposta = minuto;
                    adicional = 0;
                }
            } else {
                if (minuto > 45) {
                    adicional = minuto - 45;
                    resposta = 90;
                } else {
                    resposta = minuto + 45;
                    adicional = 0;
                }
            }
            vetor.add(resposta);
            vetor.add(adicional);
        }
        Iterator it = vetor.iterator();
        while (it.hasNext()) {
            int g = (int) it.next();
            int h = (int) it.next();
            if (h == 0) {
                System.out.println(g);
            } else {
                System.out.println(g + "+" + h);
            }
        }
    }
}
