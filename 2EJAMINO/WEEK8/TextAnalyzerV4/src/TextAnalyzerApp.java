import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class TextAnalyzerApp {
    static String text;
    static WordSentenceStatistics sentenceStatistics;
    static WordTextStatistics wordStatistics;
    static Scanner myInput;

    public static String readFile(String textFileName) throws IOException {
        StringBuilder sb = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader(textFileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                sb.append(line);
            }
        }
        return sb.toString();
    }

    public static void menu(String choice){
        switch(choice){
            case "ds":
                sentenceStatistics.displaySentences();
                break;
            case "dw":
                wordStatistics.showUniqueWords();
                break;
            case "dst":
                for(String word : wordStatistics.getHashSet()){
                    System.out.println("Word : " + word + " :stats");
                    wordStatistics.showWordStatistics(word);
                    sentenceStatistics.showWordSentenceStatistics(word);
                    System.out.println("\n");
                }
                break;
            default:
                wordStatistics.showWordStatistics(choice);
                sentenceStatistics.showWordSentenceStatistics(choice);
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

        System.out.println("TextAnalayzerApp Report");
        try{
            text = readFile("Text.txt");
        } catch(IOException e){
            System.out.println("File not found aborting!");
            return;
        }

        sentenceStatistics = new WordSentenceStatistics(text);
        wordStatistics = new WordTextStatistics(text);

        while (!(choice = getChoice()).equals("q")) {
            menu(choice);
        }

        myInput.close();
        System.out.println("TextAnalyzerApp terminated!");
    }
}
