/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package thefinalqueue;

import java.util.Iterator;
import java.util.LinkedList;

/**
 *
 * @author 2021122760224
 */
public class Leao extends Warrior {
    int id;

    public Leao(int faction, int peso, int idade, String nome) {
        super(faction, peso, idade, nome);
    }
  
    /**
     *
     * @param timeA
     * @param timeB
     */
    
    @Override
    public void atacar(LinkedList timeA, LinkedList timeB) {
        Iterator it = timeB.iterator();
        Warrior warrior2 = (Warrior) timeB.get(0);
        warrior2.loseEnergy(30);
        if (it.hasNext()){
            Warrior warriorProximo = (Warrior) timeB.get(1);
            warriorProximo.loseEnergy(15);
            it.next();
            if (it.hasNext()){
                Warrior warriorProximo2 = (Warrior) timeB.get(2);
                warriorProximo2.loseEnergy(15);           
            } 
        }       
    }
}
