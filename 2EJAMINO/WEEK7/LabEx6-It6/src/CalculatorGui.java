import java.awt.Button;
import java.awt.Color;
import java.awt.Font;
import java.awt.Frame;
import java.awt.TextField;
import java.awt.event.*;

public class CalculatorGui extends Frame {
    public static Operand op;
    public static Adder add;
    public static Subtracter sub;
    public static ResultPresenter rp;
    public Button button0, button1, button2, button3, button4;
    public Button button5, button6, button7, button8, button9;
    public Button buttonPlus, buttonMinus, buttonResultPresenter, buttonMul, buttonDiv;
    public Button buttonEnter, buttonBackSpace, buttonClear,buttonClearAll;
    public static Frame window;
    public static TextField display;

    public CalculatorGui(Operand op2, Adder add2, Subtracter sub2, Multiplier mult, Divider div2,
    ResultPresenter rp2) {
        CalculatorGui.op = op2;
        CalculatorGui.add = add2;
        CalculatorGui.sub = sub2;
        CalculatorGui.rp = rp2;
        window = new Frame("LabEx5-It6");
        window.setLayout(null);
        window.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        window.setBackground(Color.WHITE);

        button0 = new Button("0");
        button0.setBounds(64, 265, 35, 28);
        button0.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        button0.setForeground(Color.blue);
        button0.addActionListener(new Button0Handler());
        CalculatorGui.window.add(button0);

        button1 = new Button("1");
        button1.setBounds(64, 232, 35, 28);
        button1.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        button1.setForeground(Color.blue);
        button1.addActionListener(new Button1Handler());
        CalculatorGui.window.add(button1);

        button2 = new Button("2");
        button2.setBounds(104, 232, 35, 28);
        button2.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        button2.setForeground(Color.blue);
        button2.addActionListener(new Button2Handler());
        CalculatorGui.window.add(button2);

        button3 = new Button("3");
        button3.setBounds(144, 232, 35, 28);
        button3.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        button3.setForeground(Color.blue);
        button3.addActionListener(new Button3Handler());
        CalculatorGui.window.add(button3);
        
        button4 = new Button("4");
        button4.setBounds(64, 199, 35, 28);
        button4.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        button4.setForeground(Color.blue);
        button4.addActionListener(new Button4Handler());
        CalculatorGui.window.add(button4);

        button5 = new Button("5");
        button5.setBounds(104, 199, 35, 28);
        button1.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        button5.setForeground(Color.blue);
        button5.addActionListener(new Button5Handler());
        CalculatorGui.window.add(button5);

        button6 = new Button("6");
        button6.setBounds(144, 199, 35, 28);
        button6.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        button6.setForeground(Color.blue);
        button6.addActionListener(new Button6Handler());
        CalculatorGui.window.add(button6);

        button7 = new Button("7");
        button7.setBounds(64, 166, 35, 28);
        button7.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        button7.setForeground(Color.blue);
        button7.addActionListener(new Button7Handler());
        CalculatorGui.window.add(button7);

        button8 = new Button("8");
        button8.setBounds(104, 166, 35, 28);
        button8.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        button8.setForeground(Color.blue);
        button8.addActionListener(new Button8Handler());
        CalculatorGui.window.add(button8);

        button9 = new Button("9");
        button9.setBounds(144, 166, 35, 28);
        button9.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        button9.setForeground(Color.blue);
        button9.addActionListener(new Button9Handler());
        CalculatorGui.window.add(button9);

        buttonEnter = new Button("ENTER");
        buttonEnter.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        buttonEnter.setBackground(Color.red);
        buttonEnter.setForeground(Color.white);
        buttonEnter.setBounds(204, 100, 56, 28);
        buttonEnter.addActionListener(new ButtonEnterHandler());
        CalculatorGui.window.add(buttonEnter);
        
        buttonBackSpace = new Button("BackSpace");
        buttonBackSpace.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        buttonBackSpace.setForeground(Color.red);
        buttonBackSpace.setBounds(64, 100, 75, 28);
        buttonBackSpace.addActionListener(new ButtonBackSpaceHandler());
        CalculatorGui.window.add(buttonBackSpace);

        buttonClearAll = new Button("C");
        buttonClearAll.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        buttonClearAll.setForeground(Color.red);
        buttonClearAll.setBounds(144, 133, 35, 28);
        buttonClearAll.addActionListener(new ButtonClearAllHandler());
        CalculatorGui.window.add(buttonClearAll);

        buttonClear = new Button("CE");
        buttonClear.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        buttonClear.setForeground(Color.red);
        buttonClear.setBounds(144, 100, 35, 28);
        buttonClear.addActionListener(new ButtonClearHandler());
        CalculatorGui.window.add(buttonClear);

        buttonPlus = new Button("+");
        buttonPlus.setBounds(195, 265, 35, 28);
        buttonPlus.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        buttonPlus.setForeground(Color.blue);
        buttonPlus.addActionListener(new ButtonPlusHandler());
        CalculatorGui.window.add(buttonPlus);

        buttonMinus = new Button("-");
        buttonMinus.setBounds(195, 232, 35, 28);
        buttonMinus.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        buttonMinus.setForeground(Color.blue);
        buttonMinus.addActionListener(new ButtonMinusHandler());
        CalculatorGui.window.add(buttonMinus);

        buttonMul = new Button("*");
        buttonMul.setBounds(195, 199, 35, 28);
        buttonMul.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        buttonMul.setForeground(Color.blue);

        CalculatorGui.window.add(buttonMul);

        buttonDiv = new Button("/");
        buttonDiv.setBounds(195, 166, 35, 28);
        buttonDiv.setFont(new Font("TImesRoman", Font.PLAIN, 14));
        buttonDiv.setForeground(Color.BLUE);

        CalculatorGui.window.add(buttonDiv);
        
        buttonResultPresenter = new Button("=");
        buttonResultPresenter.setBounds(235, 265, 35, 28);
        buttonResultPresenter.setFont(new Font("TimesRoman", Font.PLAIN, 14));
        buttonResultPresenter.setForeground(Color.blue);
        buttonResultPresenter.addActionListener(new ButtonResultPresenterHandler());
        CalculatorGui.window.add(buttonResultPresenter);
        
        //D I S P L A Y S E T T I N G S
        display = new TextField("0");
        display.setEditable(false);
        display.setBounds(13, 55, 257, 30);
        //W I N D O W S E T T I N G S
        window.add(display);window.setSize(283,320);
        window.setLocation(40,80);
        //window.show();
        window.setVisible(true);
        window.setResizable(false);
        window.addWindowListener(new CloseWindowAndExit());
        }
    }

    class CloseWindowAndExit extends WindowAdapter{
        public void windowClosing(WindowEvent closeWindowAndExit){
        System.exit(0);
    }

    }
    class Button0Handler implements ActionListener{
        public Button0Handler() { }
        public void actionPerformed(ActionEvent pushingButton0){
        CalculatorGui.op.addDigit('0'); }
    }

    class Button1Handler implements ActionListener{
        public Button1Handler() { }
        public void actionPerformed(ActionEvent pushingButton1)
        { CalculatorGui.op.addDigit('1'); }
    }

    class Button2Handler implements ActionListener{
        public Button2Handler() { }
        public void actionPerformed(ActionEvent pushingButton2)
        { CalculatorGui.op.addDigit('2'); }
    }

    class Button3Handler implements ActionListener{
        public Button3Handler() { }
        public void actionPerformed(ActionEvent pushingButton3)
        { CalculatorGui.op.addDigit('3'); }
    }

    class Button4Handler implements ActionListener{
        public Button4Handler() { }
        public void actionPerformed(ActionEvent pushingButton4)
        { CalculatorGui.op.addDigit('4'); }
    }

    class Button5Handler implements ActionListener{public Button5Handler() { }
        public void actionPerformed(ActionEvent pushingButton5)
        { CalculatorGui.op.addDigit('5'); }
    }

    class Button6Handler implements ActionListener{
        public Button6Handler() { }
        public void actionPerformed(ActionEvent pushingButton6)
        { CalculatorGui.op.addDigit('6'); }
    }

    class Button7Handler implements ActionListener{
        public Button7Handler() { }
        public void actionPerformed(ActionEvent pushingButton7)
        { CalculatorGui.op.addDigit('7'); }
    }

    class Button8Handler implements ActionListener{
        public Button8Handler() { }
        public void actionPerformed(ActionEvent pushingButton8)
        { CalculatorGui.op.addDigit('8'); }
    }

    class Button9Handler implements ActionListener{
        public Button9Handler() { }
        public void actionPerformed(ActionEvent pushingButton9)
        { CalculatorGui.op.addDigit('9'); }
    }

    class ButtonEnterHandler implements ActionListener{
        public ButtonEnterHandler() { }
        public void actionPerformed(ActionEvent pushingButtonEnter)
        { CalculatorGui.op.complete(); }
    }

    class ButtonBackSpaceHandler implements ActionListener{
        public ButtonBackSpaceHandler() { }
        public void actionPerformed(ActionEvent pushingButtonBackSpace)
        { CalculatorGui.op.deleteLastDigit(); }
    }

    class ButtonClearAllHandler implements ActionListener{
        public ButtonClearAllHandler() { }public void actionPerformed(ActionEvent pushingButtonClearAll){
            CalculatorGui.op.reset();
        }
    }

    class ButtonClearHandler implements ActionListener{
        public ButtonClearHandler() { }
        public void actionPerformed(ActionEvent pushingButtonClear)
        { 
            CalculatorGui.op.reset(); 
        }
    }

    class ButtonPlusHandler implements ActionListener{
        public ButtonPlusHandler() { }
        public void actionPerformed(ActionEvent pushingButtonPlus){
             CalculatorGui.add.operate(); 
            }
        }

    class ButtonMulHandler implements ActionListener{
        public ButtonMulHandler(){}

        public void actionPerformed(ActionEvent pushingButtonMul){
            //TODO Add the mul classs as operator and use it same for the div 
        }
    }

    class ButtonMinusHandler implements ActionListener{
        public ButtonMinusHandler() { }
        public void actionPerformed(ActionEvent pushingButtonMinus){ 
            CalculatorGui.sub.operate(); 
        }
    }

    class ButtonResultPresenterHandler implements ActionListener{
        public ButtonResultPresenterHandler() { }
        public void actionPerformed(ActionEvent pushingButtonResultPresenter){ 
            CalculatorGui.rp.operate();
        }
    }