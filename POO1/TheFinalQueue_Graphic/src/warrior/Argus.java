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
public class Argus extends Warrior {

    /**
     *
     * @param weight peso do Argus
     * @param age idade do Argus
     * @param name nome do Argus
     */
    public Argus(int weight, int age, String name) {
        super(weight, age, name);
        this.setMaxEnergy(60);
        this.setCurrentEnergy(60);
        this.setIcon("data\\Argus.png");
    }

    /**
     *
     * @param timeA LinkedList timeA
     * @param timeB LinkedList timeB
     */
    @Override
    public void atacar(LinkedList timeA, LinkedList timeB) {
        Warrior warrior = (Warrior) timeB.get(0);
        warrior.setCurrentEnergy(0);
    }
    
}
