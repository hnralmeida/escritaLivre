package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.ArrayList;

/**
 *
 * @author PacCode
 */
public class Main {

    public static void main(String[] args) {
        BufferedReader dado;
        int N, i, notas;
        String s, nome;
        ArrayList turma = new ArrayList();
        dado = new BufferedReader(new InputStreamReader(System.in));
        try {
            s = dado.readLine();
            String[] tokens = s.split(" ");
            N = Integer.parseInt(tokens[0]);
            //System.out.println(N + " " + K);
            for (i = 0; i < N; i++) {
                nome = dado.readLine();
                s = dado.readLine();
                tokens = s.split(" ");
                notas = tokens.length;
                switch (notas) {
                    case 1 ->  {
                        Aluno n = new Aluno(nome, Double.parseDouble(tokens[0]));
                        turma.add(n);
                    }
                    case 2 ->  {
                        Aluno n = new Aluno(nome, Double.parseDouble(tokens[0]), Double.parseDouble(tokens[1]));
                        turma.add(n);
                    }
                    case 3 ->  {
                        Aluno n = new Aluno(nome, Double.parseDouble(tokens[0]), Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]));
                        turma.add(n);
                    }
                    case 4 ->  {
                        Aluno n = new Aluno(nome, Double.parseDouble(tokens[0]), Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]), Double.parseDouble(tokens[3]));
                        turma.add(n);
                    }
                    default -> {
                    }
                }
            }
            turma.stream().forEach(aluno -> System.out.println(aluno));
        } catch (IOException erro) {
            System.out.println("Erro na entrada de dados");
        }
    }
}
class Aluno {
    private final double media;
    private final String nome;
    
    public Aluno(String nome, double p1) {
        this.nome = nome;
        this.media = (p1) / 2;
    }
    public Aluno(String nome, double p1, double p2) {
        this.nome = nome;
        this.media = (p1 + p2) / 2;
    }
    public Aluno(String nome, double p1, double p2, double t1) {
        this.nome = nome;
        this.media = (p1 + p2 + t1) / 3;
    }
    public Aluno(String nome, double p1, double p2, double t1, double ps) {
        this.nome = nome;
        double ignore;
        if (ps > p1) {
            ignore = p1;
        } else if (ps > p2) {
            ignore = p2;
        } else if (ps > t1) {
            ignore = t1;
        } else {
            ignore = ps;
        }
        this.media = (p1 + p2 + t1 + ps - ignore) / 3;
    }
    @Override
    public String toString() {
        DecimalFormat df = new DecimalFormat();
        df.applyPattern("0.0");
        DecimalFormatSymbols sym = DecimalFormatSymbols.getInstance();
        sym.setDecimalSeparator('.');
        df.setDecimalFormatSymbols(sym);
        return (nome + ": " + df.format(media));
    }
}