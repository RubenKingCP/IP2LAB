import java.util.Stack;

public class Adder {
    Stack<Double> st;

    public Adder(Stack<Double> st){
        this.st = st;
    }

    public void operate() {
        this.st.push(Double.valueOf(((Double)this.st.pop()).doubleValue() + ((Double)this.st.pop()).doubleValue()));
    }
}
