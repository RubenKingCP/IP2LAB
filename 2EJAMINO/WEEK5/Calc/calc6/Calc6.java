
import java.util.Stack;

public class Calc6 {
    static Double num1;
    static Double num2;
    static Stack<Double> stack;
    
    public static Double add(Double num1, Double num2){
        Double sum;
        sum = num1 + num2;
        return sum;
    }

    public static void main(String args[]){
        stack = new Stack<Double>();
        num1 = 0.0;
        num2 = 23.3;
        stack.push(num1);
        stack.push(num2);
        var operations = new Operations(stack);
        operations.div();
        System.out.println("Result : " + stack.peek());
    }
}