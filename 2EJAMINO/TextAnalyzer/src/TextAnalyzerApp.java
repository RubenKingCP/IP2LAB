
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;

public class TextAnalyzerApp {
    private static StringBuilder sb;
    private static String str;
    private static String[] lineList;
    private static String[] wordList;

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
    public static void main(String[] args) throws Exception {
        //Read file
        readFile("Text.txt");

        // //Split string to words
        wordList = str.split("[,.\\s]+");

        //Hashmap to track number of apperances
        HashMap<String, Integer> wordMap = new HashMap<String, Integer>();
        for(String word : wordList) {
            if(!wordMap.containsKey(word))
                wordMap.put(word, 1);
            else
                wordMap.put(word, wordMap.get(word) + 1);
        } 
        //Print the values
        wordMap.forEach((key, value) -> System.out.println(key + ": " + value));
        

        //Line part
        //Split string into lines
        lineList = str.split("\\. ");
        HashMap<String, Integer> trackHighestCount = new HashMap<String, Integer>();
        HashMap<String, Integer> trackLineAppeared = new HashMap<String, Integer>();
        HashMap<String, Integer> trackLineHighestCount = new HashMap<String, Integer>();

        //Split each line into words
        for(int i = 0; i < lineList.length; i++){
            String[] lineWordList = lineList[i].split("[,.\\s]+");

            //HashMap to track each apperance in sentence
            HashMap<String, Integer> lineWordMap = new HashMap<String, Integer>();
            for(String lineWord : lineWordList) {
                //Check if it appeared in previous instance
                if(!trackHighestCount.containsKey(lineWord)){
                    //Get highest count and its line
                    trackHighestCount.put(lineWord, 1);
                    //Check first time appeared
                    trackLineAppeared.put(lineWord, i);
                }
                else{
                    trackHighestCount.put(lineWord, trackHighestCount.get(lineWord) + 1);
                    trackLineHighestCount.put(lineWord, i);
                }

                //Check if word appeared 
                if(!lineWordMap.containsKey(lineWord) && lineWord != " ")
                    lineWordMap.put(lineWord, 1);
                else
                    lineWordMap.put(lineWord, lineWordMap.get(lineWord) + 1);
            }

            //Print line and all key pair values
            System.out.println("Line " + i + ": " + lineList[i]);
            lineWordMap.forEach((key, value) -> System.out.println("    " + key + ": " + value));
        }

        //TODO: DEBUG
        // trackHighestCount.forEach((key, value) -> System.out.println("Highest times " + key + " appeared : " + value));

        //Gte in which line it appeared the most
        //TODO: FIX
        // trackLineHighestCount.forEach((key, value) -> System.out.println("Highest times " + key + " appeared in line : " + value));

        //Check in which line first appeared
        trackLineAppeared.forEach((key, value) -> System.out.println("First time " + key + " appeared in line : " + value));
    }
}

//Iteration 1
//Read text from file and store in String


