/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package graphic;

import java.awt.Graphics;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import thefinalqueue.Match;

/**
 *
 * @author User
 */
public class Container extends JFrame{
    public Container(Match match){
        this.add(new VisualBattle(match));
        setTitle("The Final Queue");
        setSize((1280), (720));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        this.setResizable(false);
        setVisible(true);
    }
}