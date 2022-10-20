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

//Classe FerisWolf herda de Guerreiro

public class FerisWolf extends Warrior {    
    
    //Construtor de FerisWolf
    public FerisWolf(int weight, int age, String name) {
        super(weight, age, name);
    }
    
    //Sobreescrita do método setCurrentEnergy de guerreiro, respeitando o limite (100)
    @Override
    public void setCurrentEnergy(int energiaAtual) {
        this.currentEnergy = energiaAtual;
    }
    
    /*Sobreescrita do método atacar de guerreiro
    Cria uma váriavel guerreiro, pegando o primeiro da lista do timeB
    Cria uma váriavel it do tipo Iterator, iterando sobre o timeA
    Enquanto há próximo na lista, verifica se a classe após o lobo é do seu mesmo tipo
    se for, adiciona na variavel quantidade
    após verificar todos os itens na lista, seta qt como qt*8 (energia que ele irá ganhar)
    chama o método loseEnergy, passando 40 (ataque padrão) + qt (se houver)
    */
    
    @Override
    public void atacar(LinkedList timeA, LinkedList timeB) {
        Warrior warrior = (Warrior) timeB.get(0);
        int qt=0;
        Iterator it = timeA.iterator();
        while (it.hasNext()){
            if (timeA.getClass().getSimpleName().equals("FehriWolf")){
                qt++;
            } else {
                break;
            }     
        }
        qt = qt*8;
        warrior.loseEnergy(40+qt);
    }
}
