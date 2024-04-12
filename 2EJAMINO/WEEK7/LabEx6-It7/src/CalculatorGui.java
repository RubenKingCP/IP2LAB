import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;

public class CalculatorGui extends JFrame {
    private JTextField display;
    private final static int startX = 95;

    public CalculatorGui(String title) {
        super(title);
        initUI();
    }

    private void initUI() {
        getContentPane().setBackground(Color.BLUE);
        setLayout(null); // Not recommended, but keeping it for simplicity

        display = new JTextField("0");
        display.setEditable(false);
        display.setBounds(45, 45, 600, 150);
        add(display);

        //First row
        addButton(".", startX, 630);
        addButton("0", startX + 100, 630);
        addButton("C", startX + 200, 630);

        //Second row
        addButton("1", startX, 530);
        addButton("2", startX + 100, 530);
        addButton("3", startX + 200, 530);

        //Third row
        addButton("4", startX, 430);
        addButton("5", startX + 100, 430);
        addButton("6", startX + 200, 430);

        //Fourth row
        addButton("7", startX , 330);
        addButton("8", startX + 100, 330);
        addButton("9", startX + 200, 330);


        // Placeholder for additional buttons
        addButton("Enter", startX + 300, 630); 
        addPlusButton("+", startX + 300, 530);
        addSubButton("-", startX + 300, 430);
        addDivButton("/", startX + 300, 330);
        addMulButton("*", startX + 300, 230);
        addButton("BackSpace", startX, 230);

        setSize(700, 800);
        setLocationRelativeTo(null);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    private void addButton(String label, int x, int y) {
        JButton button = new JButton(label);
        button.setBounds(x, y, 80 , 80);
        button.addActionListener(new ButtonNumberHandler(label));
        add(button);
    }

    private void addSubButton(String label, int x, int y){
        JButton button = new JButton(label);
        button.setBounds(x, y, 80, 80);
        button.addActionListener(new ButtonSubHandler());
        add(button);
    }

    private void addMulButton(String label, int x, int y){
        JButton button = new JButton(label);
        button.setBounds(x, y, 80, 80);
        button.addActionListener(new ButtonMulHandler());
        add(button);
    }

    private void addDivButton(String label, int x, int y){
        JButton button = new JButton(label);
        button.setBounds(x, y, 80, 80);
        button.addActionListener(new ButtonDivHandler());
        add(button);
    }

    private void addPlusButton(String label, int x, int y){
        JButton button = new JButton(label);
        button.setBounds(x, y, 80, 80);
        button.addActionListener(new ButtonPlusHandler());
        add(button);
    }

    
    class ButtonNumberHandler implements ActionListener {
        private String digit;

        public ButtonNumberHandler(String digit) {
            this.digit = digit;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            display.setText(display.getText() + digit);
        }
    }

    class ButtonPlusHandler implements ActionListener{
        public ButtonPlusHandler(){

        }

        @Override
        public void actionPerformed(ActionEvent buttonPlusPushed){
            display.setText("Added");
        }
    }

    class ButtonSubHandler implements ActionListener{
        public ButtonSubHandler(){

        }

        @Override
        public void actionPerformed(ActionEvent buttonPlusPushed){
            display.setText("Subbed");
        }
    }

    class ButtonMulHandler implements ActionListener{
        public ButtonMulHandler(){

        }

        @Override
        public void actionPerformed(ActionEvent buttonPlusPushed){
            display.setText("Multiplied");
        }
    }

    class ButtonDivHandler implements ActionListener{
        public ButtonDivHandler(){

        }

        @Override
        public void actionPerformed(ActionEvent buttonPlusPushed){
            display.setText("Divided");
        }
    }
}
