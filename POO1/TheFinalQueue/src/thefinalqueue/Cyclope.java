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
public class Cyclope extends Nordico {
    int id;

    public Cyclope(int tipo, int peso, int idade, String nome) {
        super(tipo, peso, idade, nome);
    }

    @Override
    public void atacar(LinkedList timeA, LinkedList timeB) {
        Warrior warrior1 = (Warrior) timeA.get(0);
        Warrior warrior2 = (Warrior) timeB.get(0);
        int at = warrior2.getEnergiaAtual() - 40;
        warrior2.setEnergiaAtual(at);
        
    }    
}
