import javax.swing.JFrame;

import java.awt.Color;
import java.awt.Font;

public class CalculatorGui extends JFrame{
    
    public CalculatorGui(String title){
        super(title);
        this.setLayout(null);
        this.setFont(new Font("TimesRoman", Font.PLAIN, 16));
        this.getContentPane().setBackground(Color.BLUE);

        this.setSize(283, 280);
        this.setLocation(40, 80);
        this.setVisible(true);
        this.setResizable(true);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}
