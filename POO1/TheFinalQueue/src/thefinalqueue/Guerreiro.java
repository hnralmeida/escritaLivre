/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package thefinalqueue;

import java.util.ArrayList;

/**
 *
 * @author 2021122760224
 */
public abstract class Guerreiro {
    private String nome;
    private final int tipo;
    private int peso;
    private int energiaMaxima;
    private final int energiaAtual = 100;
    private int idade;
    

    public Guerreiro(int tipo, int peso, int idade, String nome) {
        this.nome = nome;
        this.peso = peso;
        this.idade = idade;
        this.tipo= tipo;
    }
   

    public abstract void atacar (ArrayList timeA, ArrayList timeB);
}
