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

//Valkyrie herda de guerreiro
public class Valkyrie extends Warrior {

    //Construtor de Valkyrie
    public Valkyrie(int weight, int age, String name) {
        super(weight, age, name);
    }
   
    /**
     *
     * @param energiaAtual
     */
    
    //Sobreescrita do método setCurrentEnergy de guerreiro, validando o máximo de vida como (100)
    @Override
    public void setCurrentEnergy(int energiaAtual){
        this.currentEnergy = energiaAtual;  
    }
    
    /*Sobreescrita do método atacar de guerreiro
    cria dois iterators, um do timeA e outro do timeB
    Valk ataca e o guerreiro do timeB perde 20 de hp
    se a valk tiver alguém atrás dela na fila, cura ele em 20 de hp (obdecendo o limite de hp) 
    */
    @Override
    public void atacar(LinkedList timeA, LinkedList timeB) {
        Warrior warrior = (Warrior) timeB.get(0);
        warrior.loseEnergy(20);
        Iterator it = timeA.iterator();
        if (it.hasNext()){
            Warrior warrior2= (Warrior) timeA.get(1);
            warrior2.setCurrentEnergy(warrior2.getCurrentEnergy() + 20);
        }        
    }
}
