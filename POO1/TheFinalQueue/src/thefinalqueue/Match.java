/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package thefinalqueue;

import java.io.FileInputStream;
import java.io.IOException;
import warrior.Warrior;
import java.util.*;
import warrior.Anubite;
import warrior.Argus;
import warrior.Cyclope;
import warrior.FehriWolf;
import warrior.Hydra;
import warrior.Leao;
import warrior.Mumia;
import warrior.Prometeano;
import warrior.Satiro;
import warrior.Valkyrie;
/**
 *
 * @author 2021122760046
 */
public class Match {
    LinkedList<Warrior> teamA;
    LinkedList<Warrior> teamB;
    LinkedList<Warrior> deadA;
    LinkedList<Warrior> deadB;

    public Match(String timeA, String timeB) throws IOException{
        teamA = new LinkedList();
        teamB = new LinkedList();
        deadA = new LinkedList();
        deadB = new LinkedList();
        this.init(timeA, timeB);
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
    
    private void init(String timeA, String timeB) throws IOException{
        FileInputStream file1 = new FileInputStream(timeA);
        Scanner scan1 = new Scanner(file1);
        while(scan1.hasNextLine()){
            String line = scan1.nextLine();
            String[] tokens = line.split(" ");
            int type = Integer.parseInt(tokens[0]);
            String name = tokens[1];
            int age = Integer.parseInt(tokens[2]);
            int weight = Integer.parseInt(tokens[3]);
            switch(type){
                case 1: this.teamA.add(new Cyclope(weight, age, name)); break;
                case 2: this.teamA.add(new Leao(weight, age, name)); break;
                case 3: this.teamA.add(new Hydra(weight, age, name)); break;
                case 4: this.teamA.add(new Valkyrie(weight, age, name)); break;
                case 5: this.teamA.add(new FehriWolf(weight, age, name)); break;
                default: System.out.println("Tipo não identificado para (" + type + ") ("+ name + ", " + 
                            age + ", " + weight + ")");break;
            }
        }
            
        
        FileInputStream file2 = new FileInputStream(timeB);
        Scanner scan2 = new Scanner(file2);
        while(scan2.hasNextLine()){
            String line = scan2.nextLine();
            String[] tokens = line.split(" ");
            int type = Integer.parseInt(tokens[0]);
            String name = tokens[1];
            int age = Integer.parseInt(tokens[2]);
            int weight = Integer.parseInt(tokens[3]);
            switch(type){
                case 1: this.teamB.add(new Prometeano(weight, age, name)); break;
                case 2: this.teamB.add(new Satiro(weight, age, name)); break;
                case 3: this.teamB.add(new Argus(weight, age, name)); break;
                case 4: this.teamB.add(new Anubite(weight, age, name)); break;
                case 5: this.teamB.add(new Mumia(weight, age, name)); break;
                default: System.out.println("Tipo não identificado para (" + type + ") ("+ name + ", " + 
                            age + ", " + weight + ")"); break;
            }
        }
        int weighttotal=0;
        for (int i = 0; i < teamA.size(); i++) {
            weighttotal += teamA.get(i).getWeight();
        }
        System.out.println("Gregos e Nórdicos pesam  (" + weighttotal + ") unidades ");
        
        weighttotal=0;
        for (int i = 0; i < teamB.size(); i++) {
            weighttotal += teamB.get(i).getWeight();
        }
        System.out.println("Atlantes e Egípcios pesam  (" + weighttotal + ") unidades ");
        
        String nome= "";
        int idadeMax=0;
        int aux;
        for (int i = 0; i < teamA.size(); i++) {
          aux= teamA.get(i).getAge();
          if (idadeMax < aux){
              nome = teamA.get(i).getName();
              idadeMax= aux;
          }    
       }
        String nome2= "";
        int idadeMax2=0;
        int aux2;
        for (int i = 0; i < teamB.size(); i++) {
           aux2= teamB.get(i).getAge();
           if (idadeMax2 < aux2){
               nome2 = teamB.get(i).getName();
               idadeMax2= aux2;
           }    
        }
        
        if (idadeMax > idadeMax2){
            System.out.println("" + nome + " é o mais velho (" + idadeMax + ")");
        } else {
            System.out.println("" + nome2 + " é o mais velho (" + idadeMax2 + ")");
        }
    }
    
    private void check(){
        // Separa os atacantes de cada fila
        Warrior attackerA = this.teamA.get(0);
        Warrior attackerB = this.teamB.get(0);

        // Verifica se há na fila mortos, remove eles e os coloca na primeira 
        // posição para ser devidamente eliminados 
        if(!this.teamA.isEmpty()){
            for(int i = 0; i< this.teamA.size(); i++){
                if (this.teamA.get(i).getCurrentEnergy()<1){
                    this.teamA.addFirst(this.teamA.remove(i));
                    attackerB.killsWarrior(this.teamB, this.teamA, this.deadA);
                }
            }
        }
        
        if(!this.teamB.isEmpty()){
            for(int i = 0; i< this.teamB.size(); i++){
                if (this.teamB.get(i).getCurrentEnergy()<1){
                    this.teamB.addFirst(this.teamB.remove(i));
                    attackerA.killsWarrior(this.teamA, this.teamB, this.deadB);
                }
            }
        }
    }

    public void fight(){
        
        int war1, war2;
        do{
            // Define o primeiro Warrior de cada fila como apto a batalhar
            
            Warrior warrior1 = (Warrior) this.teamA.get(0);
            Warrior warrior2 = (Warrior) this.teamB.get(0);
            warrior1.setReady(1);
            warrior2.setReady(1);
            
            // Escole quem vai atacar primeiro e realiza os ataques da rodada
            int random = (int) ( 10*Math.random() );
            if(random%2==1){
                if(warrior1.getReady()==1) warrior1.atacar(teamA, teamB);
                if(warrior2.getReady()==1 && warrior2.getCurrentEnergy()>0) warrior2.atacar(teamB, teamA);           
            }
            else {
                if(warrior2.getReady()==1) warrior2.atacar(teamB, teamA);           
                if(warrior1.getReady()==1 && warrior1.getCurrentEnergy()>0) warrior1.atacar(teamA, teamB);
            }
            
            // Verifica se existem mortos nas filas
            this.check();
            
            // Verifica a quantidade de Guerreiro e passa o primeiro para o ultimo
            // Acontece só se tiver ao menos 1 guerreiro
            war1 = this.teamA.size();
            war2 = this.teamB.size();
            if(war1!=0) this.teamA.addLast(this.teamA.removeFirst());
            if(war2!=0) this.teamB.addLast(this.teamB.removeFirst());
            // Se alguma fila estiver com 0 Warrior, termina o programa
        } while(war1!=0 && war2!=0);
                
        // Quando a batalha termina, verifica qual fila está vazia (Perdeu)
        // e indica ultimo golpe
        if(this.teamB.isEmpty()){
            Warrior aux1 = (Warrior) this.teamA.getLast();
            Warrior aux2 = (Warrior) this.deadB.getLast();
            System.out.println("Gregos e Nordicos venceram");
            System.out.println(aux2.toString() );
            System.out.println(aux1.toString() );
        }else{
            Warrior aux1 = (Warrior) this.deadA.getLast();
            Warrior aux2 = (Warrior) this.teamB.getLast();
            System.out.println("Atlantes e Egipicios venceram");
            System.out.println(aux1.toString() );
            System.out.println(aux2.toString() );
        }
    }
}
