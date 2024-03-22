import java.util.Stack;

public class Adder5 {
    private Stack<Double> st;

    public Adder5(Stack<Double> st){
        this.st = st;
    }

    public void operate(){
        var n1 = st.pop();
        var n2 = st.pop();
        var n3 = n1 + n2;
        st.push(n3);
    }
}
