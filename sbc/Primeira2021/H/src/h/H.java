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
class bloco {

    private int N;
    private ArrayList numero;
    private int K;
    private ArrayList cor;

    public bloco(int N, int K) {
        this.K = K;
        this.N = N;
        this.numero = new ArrayList();
        this.cor = new ArrayList();
    }

    public int getK() {
        return K;
    }

    public void setK(int K) {
        this.K = K;
    }

    public int getNumero(int i) {
        return (int) numero.get(i);
    }

    public void setNumero(int i, Object element) {
        this.numero.set(i, element);
    }

    public void setNumero(int i) {
        this.numero.add(i);
    }

    public int getN() {
        return N;
    }

    public void setN(int N) {
        this.N = N;
    }

    public int getCor(int i) {
        return (int) cor.get(i);
    }

    public void setCor(int i) {
        this.cor.add(i);
    }

    public void swap(int i, int j) {
        //System.out.println(this.getNumero(i) + " " + this.getNumero(j));
        int aux;
        aux = this.getNumero(i);
        this.setNumero(i, this.getNumero(j));
        this.setNumero(j, aux);
        //System.out.println(this.getNumero(i) + " " + this.getNumero(j));
    }
}

public class H {

    public static void main(String[] args) {
        BufferedReader dado;
        int N, K, i, j, k;
        String s;

        dado = new BufferedReader(new InputStreamReader(System.in));

        try {
            s = dado.readLine();
            String[] tokens = s.split(" ");
            N = Integer.parseInt(tokens[0]);
            K = Integer.parseInt(tokens[1]);
            //System.out.println(N + " " + K);
            bloco b = new bloco(N, K);

            for (i = 0; i < N; i++) {
                dado = new BufferedReader(new InputStreamReader(System.in));
                s = dado.readLine();
                tokens = s.split(" ");
                b.setNumero(Integer.parseInt(tokens[0]));
                b.setCor(Integer.parseInt(tokens[1]));
                //System.out.println(b.getNumero(i) + " " + b.getCor(i));
            }

            for (i = 0; i < K; i++) {
                for (j = 0; j < N; j++) {
                    if (b.getCor(j) == i) {
                        for (k = 0; k < N; k++) {
                            if (b.getCor(k) == i) {
                                if ((int) b.getNumero(k) > (int) b.getNumero(j)) {
                                    b.swap(k, j);
                                }
                            }
                        }
                    }
                }
            }
            int flag = 1;
            /*
            for (i = 1; i < N; i++) {
                System.out.println("");
                System.out.print(b.getNumero(i) + " ");
                System.out.println("");
            }
            */
            for (i = 1; i < N; i++) {
                if (b.getNumero(i) < b.getNumero(i - 1)) {
                    flag = 0;
                }
            }
            if (flag == 1) {
                System.out.println("Y");
            } else {
                System.out.println("N");
            }

        } catch (IOException erro) {
            System.out.println("Erro na entrada de dados");
        }
    }

}
