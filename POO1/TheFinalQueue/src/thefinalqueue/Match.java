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
    ArrayList teamA;
    ArrayList teamB;
    ArrayList deadA;
    ArrayList deadB;
    int readyA;
    int readyB;
    
    public Match(){
        teamA = new ArrayList();
        teamB = new ArrayList();
        deadA = new ArrayList();
        deadB = new ArrayList();
        readyA = 1;
        readyB = 1;
    }
    
    public Match(ArrayList teamA, ArrayList teamB){
        this.teamA = new ArrayList(teamA);
        this.teamB = new ArrayList(teamB);
        this.deadA = new ArrayList();
        this.deadB = new ArrayList();
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
        
    }
    
}
