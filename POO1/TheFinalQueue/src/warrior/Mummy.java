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
public class Mummy extends Warrior {

    public Mummy(int weight, int age, String name) {
        super(weight, age, name);
    }
    
    @Override
    public void dies (LinkedList<Warrior> time, LinkedList<Warrior> dead){
        time.addLast(new Anubite(60, 0, this.getName()));
        time.addLast(new Anubite(60, 0, this.getName()));
        time.addLast(new Anubite(60, 0, this.getName()));
        time.addLast(new Anubite(60, 0, this.getName()));
        super.dies(time, dead);
    }
    
    @Override
    public void killsWarrior (LinkedList<Warrior> timeA, LinkedList<Warrior> timeB, LinkedList<Warrior> deadB){
        timeA.add(new Undead(timeB.get(0).getWeight(), timeB.get(0).getAge(), timeB.get(0).getName()));
        super.killsWarrior(timeA, timeB, deadB);
    }

    @Override
    public void atacar(LinkedList timeA, LinkedList timeB) {
        Warrior warrior = (Warrior) timeB.get(0);
        warrior.loseEnergy(50);
    }
    
}
