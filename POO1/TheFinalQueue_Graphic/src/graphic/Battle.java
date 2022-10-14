/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package graphic;

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
    private int i;
    
    public Battle(Match match){
        ImageIcon reff = new ImageIcon("data\\cenario.png");
        this.bg = reff.getImage();
        this.match = match;
        this.i=0;
    }
    
    @Override
    public void paint(Graphics g){
        Graphics2D graficos = (Graphics2D) g;
        graficos.drawImage(this.bg, 0, 0, null);
        
        this.i=1;
        Iterator<Warrior> itA = match.getTeamA().iterator();
        itA.forEachRemaining((Warrior warrior) -> {
            warrior.setX(warrior.getX() + 100*i);
            graficos.drawImage(warrior.getIcon(), warrior.getX(), warrior.getY(), null);
            warrior.setX(512);
            this.i++;
        });
        
        this.i=1;
        Iterator<Warrior> itB = match.getTeamB().iterator();
        itB.forEachRemaining((warrior) -> {
            warrior.setX(warrior.getX() - 100*i);
            graficos.drawImage(warrior.getIcon(), warrior.getX(), warrior.getY(), null);
            warrior.setX(512);
            this.i++;
        });
        g.dispose();
    }
}
