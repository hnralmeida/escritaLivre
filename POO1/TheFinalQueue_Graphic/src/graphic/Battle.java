/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package graphic;

import java.awt.Color;
import java.awt.Font;
import javax.swing.JPanel;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.util.Iterator;
import javax.swing.ImageIcon;
import thefinalqueue.Match;
import warrior.Warrior;

/**
 *
 * @author User
 */
public class Battle extends JPanel{
    private final Image bg;
    private final Match match;
    private int init;
    private int i;
    
    public Battle(Match match){
        ImageIcon reff = new ImageIcon("data\\cenario.png");
        this.bg = reff.getImage();
        this.match = match;
        this.i=0;
        this.init=1;
    }
    
    @Override
    public void paint(Graphics g){
        Graphics2D graficos = (Graphics2D) g;
        graficos.drawImage(this.bg, 0, 0, null);
        
        if (init==1) {
            Font font = new Font("Bitstream Vera Sans", Font.BOLD, 70);
            g.setFont(font);
            g.setColor(Color.yellow);
            ImageIcon ready = new ImageIcon("data\\gold.png");
            graficos.drawImage(ready.getImage(), 210, 210, null);
            g.drawString("Get", 450,350);
            g.drawString("Ready", 410,420);
            this.init=0;
        }
        
        Font font = new Font("Bitstream Vera Sans", Font.BOLD, 10);
        g.setFont(font);
        g.setColor(Color.white);
        this.i=1;
        Iterator<Warrior> itA = match.getTeamA().iterator();
        itA.forEachRemaining((Warrior warrior) -> {
            // Ajustando posição para este warrior
            warrior.setX(warrior.getX() + 100*i);
            
            // Barra de vida
            ImageIcon healthBar = new ImageIcon("data\\Objective_Health_Bar.png");
            graficos.drawImage(healthBar.getImage(), warrior.getX(), warrior.getY()-20, null);
            
            ImageIcon hp = new ImageIcon("data\\Health_Bar.png");
            if(warrior.getCurrentEnergy()!=warrior.getMaxEnergy()){
                Image currentHP = hp.getImage().getScaledInstance(
                        hp.getIconWidth()*warrior.getCurrentEnergy()/warrior.getMaxEnergy(), 
                        hp.getIconHeight(), 
                        Image.SCALE_SMOOTH);
                hp = new ImageIcon(currentHP);
            }
            graficos.drawImage(hp.getImage(), warrior.getX(), warrior.getY()-20, null);
            g.drawString(warrior.getCurrentEnergy()+"/"+warrior.getMaxEnergy(), warrior.getX()+25, warrior.getY()-8);
            
            // Guerreiro
            graficos.drawImage(warrior.getIcon(), warrior.getX(), warrior.getY(), null);
            
            // Posição padrão
            warrior.setX(500);
            this.i++;
        });
        
        this.i=1;
        Iterator<Warrior> itB = match.getTeamB().iterator();
        itB.forEachRemaining((warrior) -> {
            if(warrior.getCurrentEnergy()>0){
                // Ajustando posição
                warrior.setX(warrior.getX() - 100*i);

                // Barra de vida
                ImageIcon healthBar = new ImageIcon("data\\Objective_Health_Bar.png");
                graficos.drawImage(healthBar.getImage(), warrior.getX(), warrior.getY()-20, null);

                ImageIcon hp = new ImageIcon("data\\Health_Bar.png");
                if(warrior.getCurrentEnergy()!=warrior.getMaxEnergy()){
                    Image currentHP = hp.getImage().getScaledInstance(
                            hp.getIconWidth()*warrior.getCurrentEnergy()/warrior.getMaxEnergy(), 
                            hp.getIconHeight(), 
                            Image.SCALE_SMOOTH);
                    hp = new ImageIcon(currentHP);
                }
                graficos.drawImage(hp.getImage(), warrior.getX(), warrior.getY()-20, null);
                g.drawString(warrior.getCurrentEnergy()+"/"+warrior.getMaxEnergy(), warrior.getX()+25, warrior.getY()-8);

                // Guerreiro
                graficos.drawImage(warrior.getIcon(), warrior.getX(), warrior.getY(), null);

                // Padrão
                warrior.setX(500);
                this.i++;
            }
        });
        g.dispose();
    }
}
