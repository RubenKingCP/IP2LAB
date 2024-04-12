import java.util.Stack;

public class Adder {
    Stack<Double> st;

    public Adder(Stack<Double> st){
        this.st = st;
    }

    public void operate() {
        this.st.push(this.st.pop() + this.st.pop());
    }
}
