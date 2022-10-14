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
public class Prometean extends Warrior {

    public Prometean(int weight, int age, String name) {
        super(weight, age, name);
    }

    @Override
    public void dies (LinkedList<Warrior> time, LinkedList<Warrior> dead){
        if(this.getMaxEnergy()>1){
            time.addLast(new Prometean(this.getWeight(), this.getAge(), this.getName()));
            time.getLast().setMaxEnergy(this.getMaxEnergy()/2);
            time.getLast().setCurrentEnergy(this.getMaxEnergy());

            time.addLast(new Prometean(this.getWeight(), this.getAge(), this.getName()));
            time.getLast().setMaxEnergy(this.getMaxEnergy()/2);
            time.getLast().setCurrentEnergy(this.getMaxEnergy());
        }
        super.dies(time, dead);
    }
    
    @Override
    public void atacar(LinkedList timeA, LinkedList timeB) {
        Warrior warrior = (Warrior) timeB.get(0);
        warrior.loseEnergy(10);
    }
    
}
