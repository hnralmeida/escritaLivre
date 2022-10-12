/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package warrior;

import java.util.LinkedList;

/**
 *
 * @author 2021122760224
 */
public class Hydra extends Warrior {
    private int heads;
    
    public Hydra(int weight, int age, String name) {
        super(weight, age, name);
        this.heads = 1;
    }
    
    @Override
    public void atacar(LinkedList timeA, LinkedList timeB) {
         Warrior warrior = (Warrior) timeB.get(0);
         int dano=50+((this.heads-1)*10);
         warrior.loseEnergy(dano);
         if (warrior.getCurrentEnergy()< 1){
             this.heads++;
         }
    }
    
}
