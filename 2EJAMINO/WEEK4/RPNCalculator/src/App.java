import java.util.Scanner;
import java.util.Stack;

public class App {
    static final int OPERAND = 1;
    static String expression;
    static Scanner sc;
    static Stack<Integer> stack;
    static String operand;
    static int inputType;

    static String getExpression() {
        sc = new Scanner(System.in);
        System.out.print("Expression to evaluate:");
        var s = sc.nextLine();
        return s;
    }

    private static int getOp(String input){
        if(Character.isDigit(input.charAt(0))){
            return 1;
        } 
        return input.charAt(0);
    }
    public static void main(String[] args) throws Exception {
        sc = new Scanner(System.in);
        System.out.println("Rpn Caclulator");
        while(sc.hasNext()){
            var s = sc.next();
            inputType = getOp(s);
            System.out.println("Rpn expression is : " + s + " with type: " + inputType);
        }
        

        sc.close();
    }
}
