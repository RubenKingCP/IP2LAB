import java.awt.Color;
import java.awt.Dimension;

import javax.swing.JFrame;

public class WindowApp {

    private static JFrame frame;

    private Window win1;

    private Window win2;

    public static void createWindow(){
        frame = new JFrame();
        frame.setSize(new Dimension(600, 600));
        frame.getContentPane().setBackground(Color.BLACK);
        frame.setVisible(true);
    }

    public void addWin(Window win){
        frame.add(win);
    }

    public static void main(String[] args) {
        //Create window
        createWindow();

        
    }
}
