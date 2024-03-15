// import java.util.Stack;
import java.util.Scanner;

public class App {
    static String expression;
    static Scanner sc;

    static String getExpression(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Expression to evaluate:");
        var s = sc.nextLine();
        sc.close();
        return s;
    }
    
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        expression = getExpression();
        System.out.println("Rpn expression is : " + expression);
    }
}
