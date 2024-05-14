import java.io.IOException;
import java.util.Scanner;

public class TextAnalyzerApp {
    private static Scanner myInput;
    private static String text;
    private static TextOperations operations;

    public static void menu(String choice){
        switch (choice) {
            case "ds":
                operations.showSentences(text);
                break;
            
            case "dw":
                System.out.println(operations.showWords(text));
                break;

            case "dSt":
                operations.getTextStats(text);
                break;
            
            default:
                operations.getWordStats(choice, text);
                break;
        }
    }

    public static String getChoice(){
        myInput = new Scanner(System.in);
        System.out.println("\nEnter word to get Stats (ds-display sentences, dw-display words, dSt-display Statistics,q-to quit):");
        return myInput.nextLine();
        
    }

    public static void main(String[] args) throws Exception {
        String choice = "";

        operations = new TextOperations();
        System.out.println("TextAnalayzerApp Report");
        try{
            text = operations.readFile("Text.txt");
        } catch(IOException e){
            System.out.println("File not found aborting!");
            return;
        }

        while (!(choice = getChoice()).equals("q")) {
            menu(choice);
        }

        System.out.println("TextAnalyzerApp terminated!");
    }
}
