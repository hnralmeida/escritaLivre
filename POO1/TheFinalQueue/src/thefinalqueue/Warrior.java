/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package thefinalqueue;

import java.util.LinkedList;

/**
 *
 * @author 2021122760224
 */
public abstract class Warrior {
    String nome;
    int peso;
    int energiaMaxima;
    int energiaAtual;
    int idade;
    int ready;

    public Warrior(int peso, int idade, String nome) {
        this.nome = nome;
        this.peso = peso;
        this.idade = idade;
        this.energiaMaxima = 100;
        this.energiaAtual = 100;
        this.ready = 1;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
    
    public int getReady() {
        return this.ready;
    }

    public void setReady(int ready) {
        this.ready = ready;
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
        if(energiaAtual>100) energiaAtual = 100;
        this.energiaAtual = energiaAtual;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public abstract void atacar (LinkedList timeA, LinkedList timeB); 
    
    public void dies (LinkedList time, LinkedList dead){
        this.setEnergiaAtual(0);
        this.setEnergiaMaxima(0);
        dead.addLast(this);
    }
    
    public void killsWarrior (LinkedList timeA, LinkedList timeB, LinkedList deadB){
        Warrior warrior = (Warrior) timeB.removeFirst();
        warrior.dies(timeB, deadB);
    }
    
    public void loseEnergy (int i){
        int hp = this.getEnergiaAtual()-i;
        this.setEnergiaAtual(hp);
    }
}
