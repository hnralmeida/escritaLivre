/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package thefinalqueue;

import java.util.ArrayList;
import java.util.LinkedList;

/**
 *
 * @author 2021122760224
 */
public abstract class Warrior {
    private String nome;
    private final int tipo;
    private int peso;
    private int energiaMaxima;
    private int energiaAtual;
    private int idade;
    

    public Warrior(int tipo, int peso, int idade, String nome) {
        this.nome = nome;
        this.peso = peso;
        this.idade = idade;
        this.tipo= tipo;
    }

    public abstract void atacar (LinkedList timeA, LinkedList timeB);
}
