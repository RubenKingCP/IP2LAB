import java.util.Stack;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        Stack<Double> st = new Stack<>();
        Operand op = new Operand(st);
        new CalculatorGui(op);`
        
    }
}
