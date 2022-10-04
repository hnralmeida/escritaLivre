/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package thefinalqueue;

import java.util.LinkedList;

/**
 *
 * @author 2021122760224
 */
public class Cyclope extends Warrior {
    int id;

    public Cyclope(int faction, int peso, int idade, String nome) {
        super(faction, peso, idade, nome);
    }

    @Override
    public void atacar(LinkedList timeA, LinkedList timeB) {
        Warrior warrior2 = (Warrior) timeB.get(0);
        warrior2.loseEnergy(40);
        warrior2.ready = 0;
    }    
}
