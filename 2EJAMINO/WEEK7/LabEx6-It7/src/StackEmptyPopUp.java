import java.util.Stack;

import javax.swing.JOptionPane;

public class StackEmptyPopUp {

    public StackEmptyPopUp(Stack<Double> st){
        if(st.size() == 0){
            JOptionPane.showMessageDialog(null, "Empty stack!", "Stack error", JOptionPane.INFORMATION_MESSAGE);
        }
        else {
            JOptionPane.showMessageDialog(null, "Only one element in stack!", "Stack error", JOptionPane.INFORMATION_MESSAGE);
        }
    }
}
