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
    
    /**
     *
     * @param weight peso do Cyclope
     * @param age idade do Cyclope
     * @param name nome do Cyclope
     */
    public Cyclope(int weight, int age, String name) {
        super(weight, age, name);
        this.setIcon("data\\Cyclope.png");
    }

    /**
     *
     * @param timeA LinkedList timeA 
     * @param timeB LinkedList timeB
     */
    @Override
    public void atacar(LinkedList timeA, LinkedList timeB) {
        Warrior warrior = (Warrior) timeB.get(0);
        warrior.loseEnergy(40);
        warrior.setReady(0);
    }    
}
