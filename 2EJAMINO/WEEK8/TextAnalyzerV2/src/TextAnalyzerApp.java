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
                    appearedInLine.put(word, 1);
                    linesWordAppeared.put(word, linesWordAppeared.get(word) + 1);
                }
            }
        }

        linesWordAppeared.forEach((key, value) -> System.out.println("  " + key + " appeared in : " + value + " lines"));

    }
    public static void main(String[] args) throws Exception {
        //Read file
        readFile("src/Text.txt");
        linesAppeared(str);
    }
}
