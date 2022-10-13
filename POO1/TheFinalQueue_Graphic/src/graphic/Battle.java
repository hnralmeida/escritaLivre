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
    
    public Battle(Match match){
        ImageIcon reff = new ImageIcon("data\\cenario.png");
        this.bg = reff.getImage();
        this.match = match;
    }
    
    @Override
    public void paint(Graphics g){
        Graphics2D graficos = (Graphics2D) g;
        graficos.drawImage(this.bg, 0, 0, null);
        Iterator<Warrior> itA = match.getTeamA().iterator();
        itA.forEachRemaining((warrior) -> {
            graficos.drawImage(warrior.getIcon(), warrior.getX(), warrior.getY(), null);
        });
        
        Iterator<Warrior> itB = match.getTeamB().iterator();
        itB.forEachRemaining((warrior) -> {
            graficos.drawImage(warrior.getIcon(), warrior.getX(), warrior.getY(), null);
        });
        g.dispose();
    }
}
