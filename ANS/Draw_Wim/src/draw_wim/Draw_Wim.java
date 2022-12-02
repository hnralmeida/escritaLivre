package draw_wim;

import javax.swing.*;

/**
 *
 * @author User
 */
public class Draw_Wim {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        JFrame frame = new JFrame("Web Browser");
        frame.add(new IU10());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}
