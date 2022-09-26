/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package thefinalqueue;

import java.util.*;
import java.lang.Math;   

/**
 *
 * @author 2021122760046
 */
public class Match {
    LinkedList teamA;
    LinkedList teamB;
    LinkedList deadA;
    LinkedList deadB;
    int readyA;
    int readyB;
    
    public Match(){
        teamA = new LinkedList();
        teamB = new LinkedList();
        deadA = new LinkedList();
        deadB = new LinkedList();
        readyA = 1;
        readyB = 1;
    }
    
    public Match(ArrayList teamA, ArrayList teamB){
        this.teamA = new LinkedList(teamA);
        this.teamB = new LinkedList(teamB);
        this.deadA = new LinkedList();
        this.deadB = new LinkedList();
        this.readyA = 1;
        this.readyB = 1;
    }
    
    public Warrior getTeamA(int i) {
        return (Warrior) this.teamA.get(i);
    }

    public void setTeamA(Warrior member) {
        this.teamA.add(member);
    }
    
    private void dropTeamA(int i) {
        this.teamA.remove(i);
    }

    public Warrior getTeamB(int i) {
        return (Warrior) this.teamB.get(i);
    }

    public void setTeamB(Warrior member) {
        this.teamB.add(member);
    }
    
    private void dropTeamB(int i) {
        this.teamB.remove(i);
    }

    public Warrior getDeadA(int i) {
        return (Warrior) this.deadA.get(i);
    }

    private void setDeadA(int i) {
        this.deadA.add(this.getTeamA(i));
        this.dropTeamA(i);
    }

    public Warrior getDeadB(int i) {
        return (Warrior) this.deadB.get(i);
    }

    private void setDeadB(int i) {
        this.deadB.add(this.getTeamB(i));
        this.dropTeamB(i);
    }

    public int getReadyA() {
        return readyA;
    }

    public void setReadyA(int readyA) {
        this.readyA = readyA;
    }

    public int getReadyB() {
        return readyB;
    }

    public void setReadyB(int readyB) {
        this.readyB = readyB;
    }
    
    public void fight(){
        int war1, war2;
        while(this.readyA==1 && this.readyB==1){
            int random = (int) Math.random();
            Warrior warrior1 = (Warrior) this.teamA.get(0);
            Warrior warrior2 = (Warrior) this.teamB.get(0);
            if(random%2==1){
                if(this.readyA==1) warrior1.atacar(teamA, teamB);
                if(this.readyB==1) warrior2.atacar(teamB, teamA);           
            }
            else {
                if(this.readyB==1) warrior1.atacar(teamB, teamA);           
                if(this.readyA==1) warrior2.atacar(teamA, teamB);
            }
            war1 = this.teamA.size();
            war2 = this.teamB.size();
            if(war1!=0){
                this.readyA=1;
                this.teamA.removeFirst();
                this.teamA.addLast(war1);
            }
            if(war2!=0){
                this.readyB=1;
                this.teamB.removeFirst();
                this.teamB.addLast(war1);
            }   
        }        
        if(this.teamB.isEmpty()){
            Warrior aux1 = (Warrior) this.teamA.getLast();
            Warrior aux2 = (Warrior) this.deadB.getLast();
            System.out.println("Lado1 venceram");
            System.out.println(aux2.toString() );
            System.out.println(aux1.toString() );
        }else{
            Warrior aux1 = (Warrior) this.deadA.getLast();
            Warrior aux2 = (Warrior) this.teamB.getLast();
            System.out.println("Lado2 venceram");
            System.out.println(aux1.toString() );
            System.out.println(aux2.toString() );
        }
    }
}
