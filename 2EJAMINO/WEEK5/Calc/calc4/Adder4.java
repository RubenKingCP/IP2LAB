
import java.util.Stack;

public class Adder4 {
    private Stack<Double> st;
    private Double sum;

    public Adder4(Stack<Double> st){
        this.st = st;    
    }

    public Double add(){
        sum = st.pop() + st.pop();
        return sum;
    }
}
