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
public class Hydra extends Warrior {
    private int heads;
    
    public Hydra(String nome, int peso, int idade) {
        super(nome, peso, idade);
        this.heads = 1;
    }
    
    @Override
    public void atacar(LinkedList timeA, LinkedList timeB) {
         Warrior warrior2 = (Warrior) timeB.get(0);
         int dano=50+((this.heads-1)*10);
         warrior2.loseEnergy(dano);
         if (warrior2.getEnergiaAtual()< 1){
             this.heads++;
         }
    }
    
}
