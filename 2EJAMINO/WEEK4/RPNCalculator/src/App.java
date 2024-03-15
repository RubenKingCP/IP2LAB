import java.util.Scanner;

public class App {
    static String expression;
    static Scanner sc;

    static String getExpression() {
        sc = new Scanner(System.in);
        System.out.print("Expression to evaluate:");
        var s = sc.nextLine();
        return s;
    }

    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        expression = getExpression();
        
        System.out.println("Rpn expression is : " + expression);
        
        // Close the Scanner object after you're done using it
    }
}
