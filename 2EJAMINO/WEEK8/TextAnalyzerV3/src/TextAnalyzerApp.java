import java.util.Scanner;

public class TextAnalyzerApp {

    public static void menu(String choice){
        switch (choice) {
            case "ds":
                System.out.println("ds works");
                break;
            
            case "dw":
                System.out.println("dw works");

                break;

            case "dSt":
                System.out.println("dSt works");
                
                break;
            
            default:
                break;
        }
    }

    public static String getChoice(){
        Scanner myInput = new Scanner(System.in);
        System.out.println("Enter word to get Stats (ds-display sentences, dw-display words, dSt-display Statistics,q-to quit):");
        String myInputWord = myInput.nextLine();
        System.out.println(myInputWord);
        return myInputWord;
    }

    public static void main(String[] args) throws Exception {
        String choice = "";
        while (!(choice = getChoice()).equals("q")) {
            menu(choice);
        }
    }
}
