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
public class Mumia extends Warrior {

    /**
     *
     * @param weight peso da Mumia
     * @param age idade da Mumia
     * @param name nome da Mumia
     */
    public Mumia(int weight, int age, String name) {
        super(weight, age, name);
        this.setIcon("data\\Mummy.png");
    }
    
    /**
     *
     * @param time LinkedList time de Guerreiro
     * @param dead LinkedList mortos de Guerreiro
     */
    @Override
    public void dies (LinkedList<Warrior> time, LinkedList<Warrior> dead){
        time.addLast(new Anubite(60, 0, this.getName()));
        time.addLast(new Anubite(60, 0, this.getName()));
        time.addLast(new Anubite(60, 0, this.getName()));
        time.addLast(new Anubite(60, 0, this.getName()));
        super.dies(time, dead);
    }
    
    /**
     *
     * @param timeA Linked List time A de guerreiros
     * @param timeB Linked List time B de guerreiros
     * @param deadB Linked List mortos do timeB de guerreiros
     */
    @Override
    public void killsWarrior (LinkedList<Warrior> timeA, LinkedList<Warrior> timeB, LinkedList<Warrior> deadB){
        timeA.add(new Undead(timeB.get(0).getWeight(), timeB.get(0).getAge(), timeB.get(0).getName()));
        super.killsWarrior(timeA, timeB, deadB);
    }

    /**
     *
     * @param timeA LinkedList timeA
     * @param timeB LinkedList timeB
     */
    @Override
    public void atacar(LinkedList timeA, LinkedList timeB) {
        Warrior warrior = (Warrior) timeB.get(0);
        warrior.loseEnergy(50);
    }
    
}
