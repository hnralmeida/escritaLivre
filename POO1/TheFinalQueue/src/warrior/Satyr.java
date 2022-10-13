/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package warrior;

import java.util.Iterator;
import java.util.LinkedList;

/**
 *
 * @author 2021122760224
 */
public class Satyr extends Warrior {

    public Satyr(int weight, int age, String name) {
        super(weight, age, name);
    }

    @Override
    public void atacar(LinkedList timeA, LinkedList timeB) {
        Iterator it = timeB.iterator();
        Warrior warrior;
        while (it.hasNext()){
            warrior= (Warrior) it.next();
            warrior.loseEnergy(5);
        }
        
    }
    
}
