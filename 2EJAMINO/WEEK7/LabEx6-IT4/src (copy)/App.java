import java.util.Stack;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        Stack<Double> st = new Stack<>();
        Operand op = new Operand(st);
        Adder add = new Adder(st);
        Divider div = new Divider(st);
        Multiplier mul = new Multiplier(st);
        ResultPresenter rp = new ResultPresenter(st);
        Subtracter sub = new Subtracter(st);

        new CalculatorGui(op, add, sub, mul, div, rp);
        
    }
}
