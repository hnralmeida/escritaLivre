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
public class Cyclope extends Warrior {
    
    public Cyclope(int peso, int idade, String nome) {
        super(peso, idade, nome);
    }

    @Override
    public void atacar(LinkedList timeA, LinkedList timeB) {
        Warrior warrior = (Warrior) timeB.get(0);
        warrior.loseEnergy(40);
        warrior.ready = 0;
    }    
}
