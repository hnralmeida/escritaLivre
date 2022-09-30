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
public class Leao extends Grego {
    int id;

    public Leao(String nome, int peso, int idade, int tipo) {
        super(nome, peso, idade, tipo);
    }

    @Override
    public void atacar(LinkedList timeA, LinkedList timeB, int damage) {
        Iterator it = timeB.iterator();
        Warrior warrior1 = (Warrior) timeA.get(0);
        Warrior warrior2 = (Warrior) timeB.get(0);
        super.atacar(warrior1, warrior2, 30);
        if (it.hasNext()){
            Warrior warriorProximo = (Warrior) timeB.get(1);
            super.atacar(warrior1, warriorProximo, 15);
            if (it.hasNext()){
                Warrior warriorProximo2 = (Warrior) timeB.get(2);
                super.atacar(warrior1, warriorProximo2, 5);             
            } 
        }       
    }
}
