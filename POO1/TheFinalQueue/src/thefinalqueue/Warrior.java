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

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getPeso() {
        return peso;
    }

    public void setPeso(int peso) {
        this.peso = peso;
    }

    public int getEnergiaMaxima() {
        return energiaMaxima;
    }

    public void setEnergiaMaxima(int energiaMaxima) {
        this.energiaMaxima = energiaMaxima;
    }

    public int getEnergiaAtual() {
        return energiaAtual;
    }

    public void setEnergiaAtual(int energiaAtual) {
        this.energiaAtual = energiaAtual;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }
    

    public Warrior(int tipo, int peso, int idade, String nome) {
        this.nome = nome;
        this.peso = peso;
        this.idade = idade;
        this.tipo= tipo;
    }

    public abstract void atacar (LinkedList timeA, LinkedList timeB);
}
