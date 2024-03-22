import java.util.Stack;

public class Calc2 {
    static Double num1;
    static Double num2;
    static Double sum;
    static Stack<Double> stack;
    
    public static Double add(Double num1, Double num2){
        Double sum;
        sum = num1 + num2;
        return sum;
    }

    public static void main(String args[]){
        stack = new Stack<Double>();
        num1 = 13.6;
        num2 = 23.7;
        stack.push(num1);
        stack.push(num2);
        sum = add(stack.pop(), stack.pop());
        stack.push(sum);
        System.out.println("Result : " + stack.peek());
    }
}