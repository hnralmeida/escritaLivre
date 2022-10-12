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
public abstract class Warrior {
    String name;
    int weight;
    int maxEnergy;
    int currentEnergy;
    int age;
    int ready;

    @Override
    public String toString() {
        return name + ", " + weight + ", " + age;
    }

    public Warrior(int peso, int idade, String nome) {
        this.name = nome;
        this.weight = peso;
        this.age = idade;
        this.maxEnergy = 100;
        this.currentEnergy = 100;
        this.ready = 1;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    public int getReady() {
        return this.ready;
    }

    public void setReady(int ready) {
        this.ready = ready;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public int getMaxEnergy() {
        return maxEnergy;
    }

    public void setMaxEnergy(int maxEnergy) {
        this.maxEnergy = maxEnergy;
    }

    public int getCurrentEnergy() {
        return currentEnergy;
    }

    public void setCurrentEnergy(int currentEnergy) {
        if(currentEnergy>100) currentEnergy = 100;
        this.currentEnergy = currentEnergy;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public abstract void atacar (LinkedList timeA, LinkedList timeB); 
    
    public void dies (LinkedList<Warrior> time, LinkedList<Warrior> dead){
        this.setCurrentEnergy(0);
        this.setMaxEnergy(0);
        this.setReady(0);
        dead.addLast(this);
    }
    
    public void killsWarrior (LinkedList<Warrior> timeA, LinkedList<Warrior> timeB, LinkedList<Warrior> deadB){
        Warrior warrior = (Warrior) timeB.removeFirst();
        warrior.dies(timeB, deadB);
    }
    
    public void loseEnergy (int i){
        int hp = this.getCurrentEnergy()-i;
        this.setCurrentEnergy(hp);
    }
}
