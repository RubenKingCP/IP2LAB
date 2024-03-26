
import java.util.Stack;

public class Adder3 {
    static void operate(Stack<Double> st){
        var n1 = st.pop();
        var n2 = st.pop();
        var sum = n1 + n2;
        st.push(sum);  
    }
}


