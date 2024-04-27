import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;

public class TextAnalyzerApp {
    private static StringBuilder sb;
    private static String str;
    private static String[] lineList;

    public static void readFile(String text) throws IOException{
        int ch;
        sb = new StringBuilder();

        FileReader fr = null;

        try{
            fr = new FileReader(text);
        }
        catch(FileNotFoundException fe){
            System.out.println("No file found");
        } 

        while((ch =fr.read())!=-1){
            sb.append((char)ch);
        }

        str = sb.toString();
    }

    public static void linesAppeared(String str){
        //Split string into lines
        String [] lines = str.split("\\. ");//Added to remove the empty space in front of new lines

        //Iniate hashmap
        HashMap<String, Integer> linesWordAppeared = new HashMap<String, Integer>();
        for(String line : lines){
            //Split line into words
            String [] wordsInLineList = line.split("[.,\\s]+");

            //Hashmap to check fro new word encounter
            HashMap<String, Integer> appearedInLine = new HashMap<String, Integer>();
            for(String word : wordsInLineList){
                //If word hasnt been met before add it to hashmap
                if(!linesWordAppeared.containsKey(word)){
                    linesWordAppeared.put(word, 1);
                } 
                //If word appeared before add one to encounter if apperead in this line
                else if(!appearedInLine.containsKey(word)){
                    //Put it in hashmap as to not count it again
                    appearedInLine.put(word, 1);
                    //Increase appeared counter
                    linesWordAppeared.put(word, linesWordAppeared.get(word) + 1);
                }
            }
        }

        //Print amount of lines appeared
        System.out.println("Total amount of lines appeared in:");
        linesWordAppeared.forEach((key, value) -> System.out.println("  " + key + " : " + value));

    }

    public static void totalWordAppearances(String str){
        String [] words = str.split("[,.\\s]+");

        //Hashmap to count words
        HashMap<String, Integer> countWords = new HashMap<String, Integer>();
        for(String word : words){
            //Check if word has been seen
            if(!countWords.containsKey(word)){
                //Put in map
                countWords.put(word, 1);
            } else {
                //Increase counter
                countWords.put(word, countWords.get(word) + 1);
            }
        }

        //Print total times
        System.out.println("Total times appeared:");
        countWords.forEach((key, value) -> System.out.println("  " + key + " : " + value));
    }

    public static void main(String[] args) throws Exception {
        //Read file
        readFile("src/Text.txt");
        linesAppeared(str);
        totalWordAppearances(str);
    }
}
