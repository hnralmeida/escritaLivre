/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package warrior;

import java.awt.Image;
import java.util.LinkedList;
import javax.swing.ImageIcon;

/**
 *
 * @author 2021122760224
 */
public abstract class Warrior {
    private String name;
    private int weight;
    private int maxEnergy;
    private int currentEnergy;
    private int age;
    private int ready;
    
    // Parte Grafica
    private int x,y;
    private Image icon;
    private int width, height;

    
    public Warrior(int weight, int age, String name) {
        this.name = name;
        this.weight = weight;
        this.age = age;
        this.maxEnergy = 100;
        this.currentEnergy = 100;
        this.ready = 1;
        this.y = 525;
        this.x = 500;
    }
        
    /**
     * 
     * @return largura
     * 
     */
    public int getWidth() {
        return width;
    }

    
    /**
     * 
     * @return altura
     * 
     */
    public int getHeight() {
        return height;
    }

    
    /**
     * 
     *  
     * @return x
     */
    public int getX() {
        return x;
    }
 
    /**
     * 
     * @param x x da funcao grafica
     *  
     */
    public void setX(int x) {
        this.x = x;
    }

    /**
     * 
     * 
     * @return y da funcao grafica
     */
    public int getY() {
        return y;
    }

    /**
     * 
     * @param y seta o y na funcao grafica
     *  
     */
    public void setY(int y) {
        this.y = y;
    }

    /**
     * 
     * 
     * @return icone 
     */
    public Image getIcon() {
        return icon;
    }

    /**
     * 
     * @param path string 
     *  
     */
    public void setIcon(String path) {
        ImageIcon reff = new ImageIcon(path);
        this.icon = reff.getImage();
        width = this.icon.getWidth(null);
        this.height = this.icon.getHeight(null);
    }

    @Override
    public String toString() {
        return name + ", " + weight + ", " + age;
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
