/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kimetsu;

/**
 *
 * @author 2021122760046
 */
public abstract class Oni {
    final private String nome;
    private int poder;
    protected int energia;
    private static int qtd=0;
    

    public String getNome() {
        return nome;
    }
    
    public int getPoder() {
        return poder;
    }

    public void setPoder(int poder) {
        this.poder = poder;
    }

    public int getEnergia() {
        return energia;
    }

    public void setEnergia(int energia) {
        this.energia = energia;
    }
    
    public abstract void atacar(Oni obj);

    public Oni(String name, int power, int energy) {
        this.nome = name;
        this.poder = power;
        this.energia = energy;
        Oni.qtd++;
    }
    
    public void perderEnergia(int power){
        this.energia = this.energia - power;
    }
    
    public static int getQt() {
        return Oni.qtd;
    }
    
    public int check(){
        if(this.energia < 0){
            this.energia = 0;
            return 0;
        }
        return 1;
    }
}
