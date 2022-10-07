/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package thefinalqueue;

import java.util.*;
/**
 *
 * @author 2021122760046
 */
public class Match {
    LinkedList<Warrior> teamA;
    LinkedList<Warrior> teamB;
    LinkedList<Warrior> deadA;
    LinkedList<Warrior> deadB;

    public Match(){
        teamA = new LinkedList();
        teamB = new LinkedList();
        deadA = new LinkedList();
        deadB = new LinkedList();
    }
    
    public Match(ArrayList teamA, ArrayList teamB){
        this.teamA = new LinkedList(teamA);
        this.teamB = new LinkedList(teamB);
        this.deadA = new LinkedList();
        this.deadB = new LinkedList();
    }
    
    public Warrior getTeamA(int i) {
        return (Warrior) this.teamA.get(i);
    }

    public void setTeamA(Warrior member) {
        this.teamA.add(member);
    }
    
    public Warrior getTeamB(int i) {
        return (Warrior) this.teamB.get(i);
    }

    public void setTeamB(Warrior member) {
        this.teamB.add(member);
    }
    
    private void check(){
        Iterator<Warrior> filaA = this.teamA.iterator();
        while( filaA.hasNext() ){
            Warrior status = filaA.next();
            if (status.getEnergiaAtual()<1) this.deadA.add(this.teamA.removeFirst());
        }
        
        Iterator<Warrior> filaB = this.teamB.iterator();
        while( filaB.hasNext() ){
            Warrior status = filaB.next();
            if (status.getEnergiaAtual()<1) this.deadB.add(this.teamB.removeFirst());
        }
    }

    public void fight(){
        int war1, war2;
        do{
            int random = (int) ( 10*Math.random() );
            Warrior warrior1 = (Warrior) this.teamA.get(0);
            Warrior warrior2 = (Warrior) this.teamB.get(0);
            
            if(random%2==1){
                if(warrior1.getReady()==1) warrior1.atacar(teamA, teamB);
                if(warrior2.getReady()==1) warrior2.atacar(teamB, teamA);           
            }
            else {
                if(warrior1.getReady()==1) warrior1.atacar(teamB, teamA);           
                if(warrior2.getReady()==1) warrior2.atacar(teamA, teamB);
            }
            this.check();
            
            war1 = this.teamA.size();
            war2 = this.teamB.size();
            if(war1!=0) this.teamA.addLast(this.teamA.removeFirst());
            if(war2!=0) this.teamB.addLast(this.teamB.removeFirst());
            
        } while(war1!=0 && war2!=0);
                
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
