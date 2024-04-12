import java.util.Stack;

public class App {
    static Stack<Double> st;
    public static void main(String[] args) throws Exception {
        st = new Stack<Double>();
    
        new CalculatorGui(st);
        
    }
}
