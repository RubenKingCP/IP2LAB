import java.util.Scanner;

public class TextAnalyzerApp {

    public static void menu(String choice){
        switch(choice){
            case "ds":
                break;
            case "dw":
                break;
            case "dst":
                break;
            default:
                break;
        }
    }
    public static String getChoice(){
        Scanner myInput = new Scanner(System.in);
        System.out.println("\nEnter word to get Stats (ds-display sentences, dw-display words, dSt-display Statistics,q-to quit):");
        myInput.close();
        return myInput.nextLine(); 
    }
    

    public static void main(String[] args) throws Exception {
        
    }
}
