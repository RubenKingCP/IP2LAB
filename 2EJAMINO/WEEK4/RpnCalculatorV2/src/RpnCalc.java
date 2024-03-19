import java.util.Scanner;

public class RpnCalc {
    static final int OPERAND = 1;
    static Scanner sc;
    static MyStack<Double> stack;

    static String getExpression() {
        sc = new Scanner(System.in);
        System.out.print("Expression to evaluate: ");
        return sc.nextLine();
    }

    private static int getInputType(String input) {
        if (Character.isDigit(input.charAt(0)) || input.charAt(0) == '.') {
            return OPERAND;
        }
        return input.charAt(0);
    }

    static void pushOperand(String s) {
        stack.push(Double.parseDouble(s));
    }

    private static void performAddition() {
        stack.push(stack.pop() + stack.pop());
    }

    private static void performSubtraction() {
        double subtrahend = stack.pop();
        double minuend = stack.pop();
        stack.push(minuend - subtrahend);
    }

    private static void performMultiplication() {
        stack.push(stack.pop() * stack.pop());
    }

    private static void performDivision() {
        double divisor = stack.pop();
        double numerator = stack.pop();

        if (divisor == 0) {
            stack.push(numerator);
            stack.push(divisor);
            return;
        }
        stack.push(numerator / divisor);
    }

    private static void printResult() {
        System.out.println("Result = " + stack.peek());
    }

    public static void main(String[] args) {
        stack = new MyStack<>();
        System.out.println("RPN Calculator");

        String expression = getExpression();
        Scanner inputScanner = new Scanner(expression);

        while (inputScanner.hasNext()) {
            String token = inputScanner.next();
            int inputType = getInputType(token);

            switch (inputType) {
                case OPERAND:
                    pushOperand(token);
                    break;
                case '+':
                    performAddition();
                    break;
                case '-':
                    performSubtraction();
                    break;
                case '*':
                    performMultiplication();
                    break;
                case '/':
                    performDivision();
                    break;
                case '=':
                    printResult();
                    break;
                default:
                    break;
            }
        }

        inputScanner.close();
    }
}
