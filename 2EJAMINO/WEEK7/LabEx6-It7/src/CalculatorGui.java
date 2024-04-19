import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.EmptyStackException;
import java.util.Stack;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;

public class CalculatorGui extends JFrame {
    Stack<Double> st;
    Operand op;
    Adder add;
    Subtracter sub;
    Multiplier mul;
    Divider div;
    ResultPresenter rp;
    private JTextField display;
    private JTextField stackSizeField;
    private final static int startX = 140;

    public CalculatorGui(Stack<Double> st) {
        super("Rpn Calc");
        this.st = st;
        initClasses();
        initUI();
    }

    private void initClasses(){
        op = new Operand(st);
        add = new Adder(st);
        sub = new Subtracter(st);
        mul = new Multiplier(st);
        div = new Divider(st);
        rp = new ResultPresenter(st);
    }

    private void initUI() {
        getContentPane().setBackground(Color.BLUE);
        setLayout(null); // Not recommended, but keeping it for simplicity

        display = new JTextField("0");
        display.setEditable(false);
        display.setBounds(45, 45, 600, 150);
        display.setHorizontalAlignment(JTextField.CENTER);
        display.setFont(new Font("Arial", Font.BOLD, 30));
        add(display);
    
        // New JTextField for stack size
        stackSizeField = new JTextField("Stack Size: " + st.size());
        stackSizeField.setEditable(false);
        stackSizeField.setBounds(300, 0, 100, 30);
        stackSizeField.setHorizontalAlignment(JTextField.CENTER);
        stackSizeField.setFont(new Font("Arial", Font.BOLD, 12));
        add(stackSizeField);

        //First row
        addButton(".", startX, 630);
        addButton("0", startX + 100, 630);
        addClearButton("C", startX + 200, 630);

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


        // Operation buttons
        addEnterButton("Enter", startX + 300, 630); 
        addPlusButton("+", startX + 300, 530);
        addSubButton("-", startX + 300, 430);
        addDivButton("/", startX + 300, 330);
        addMulButton("*", startX + 300, 230);
        addBackSpaceButton("BackSpace", startX, 230);
        addPresentResultButton("=", startX + 200, 230);

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

    private void addPresentResultButton(String label, int x, int y) {
        JButton button = new JButton(label);
        button.setBounds(x, y, 80 , 80);
        button.addActionListener(new ButtonPresentResultHandler());
        add(button);
    }

    private void addClearButton(String label, int x, int y) {
        JButton button = new JButton(label);
        button.setBounds(x, y, 80 , 80);
        button.addActionListener(new ButtonClearHandler());
        add(button);
    }

    private void addBackSpaceButton(String label, int x, int y){
        JButton button = new JButton(label);
        button.setBounds(x, y, 180 , 80);
        button.addActionListener(new ButtonBackSpaceHandler());
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

    private void addEnterButton(String label, int x, int y) {
        JButton button = new JButton(label);
        button.setBounds(x, y, 80 , 80);
        button.addActionListener(new ButtonEnterHandler());
        add(button);
    }

    private void updateStackSizeField() {
        if (st != null) {
            stackSizeField.setText("Stack size: " + st.size());
        } else {
            stackSizeField.setText("Stack size: 0");
        }
    }

    class ButtonNumberHandler implements ActionListener {
        private String digit;

        public ButtonNumberHandler(String digit) {
            this.digit = digit;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            op.addDigit(digit.charAt(0));
            display.setText(op.getString());
        }
    }

    class ButtonPlusHandler implements ActionListener{
        public ButtonPlusHandler(){

        }

        @Override
        public void actionPerformed(ActionEvent buttonPlusPushed){
            add.operate();
            updateStackSizeField();
        }
    }

    class ButtonSubHandler implements ActionListener{
        public ButtonSubHandler(){

        }

        @Override
        public void actionPerformed(ActionEvent buttonPlusPushed){
            sub.operate();
            updateStackSizeField();
        }
    }

    class ButtonMulHandler implements ActionListener{
        public ButtonMulHandler(){

        }

        @Override
        public void actionPerformed(ActionEvent buttonPlusPushed){
            mul.operate();
            updateStackSizeField();
        }
    }

    class ButtonDivHandler implements ActionListener{
        public ButtonDivHandler(){

        }

        @Override
        public void actionPerformed(ActionEvent buttonPlusPushed){
            div.operate();
            updateStackSizeField();
        }
    }

    class ButtonBackSpaceHandler implements ActionListener{
        public ButtonBackSpaceHandler(){

        }

        @Override
        public void actionPerformed(ActionEvent buttonPlusPushed){
            op.deleteLastDigit();
            
        }
    }

    class ButtonEnterHandler implements ActionListener{
        public ButtonEnterHandler(){

        }

        @Override
        public void actionPerformed(ActionEvent buttonEnterPushed){
            op.complete();
            display.setText("0");
            updateStackSizeField();
        }
    }

    class ButtonClearHandler implements ActionListener{
        public ButtonClearHandler(){

        }

        @Override
        public void actionPerformed(ActionEvent buttonEnterPushed){
            op.reset();
            display.setText("0");
            updateStackSizeField();
        }
    }

    class ButtonPresentResultHandler implements ActionListener{
        public ButtonPresentResultHandler(){

        }

        @Override
        public void actionPerformed(ActionEvent buttonEqualsPushed){
            rp.operate();
            try{
                display.setText(st.peek().toString());
            }
            catch(EmptyStackException e){
                
            }
            updateStackSizeField();
        }
    }
    
}
