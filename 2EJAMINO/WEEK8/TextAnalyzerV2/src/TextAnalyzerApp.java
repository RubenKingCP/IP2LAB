import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedHashMap;


public class TextAnalyzerApp {
    private static StringBuilder sb;
    private static String str;

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


    public static void firstLineAppeared(String str){
        //Split str into lines
        String [] lines = str.split("\\. ");

        //Hashmap to put words in
        HashMap<String, Integer> lineFirstAppeared = new HashMap<>();
        for(int i = 0; i < lines.length ; i++){
            //Split line into words
            String [] words = lines[i].split("[,.\\s]+");
            for(String word : words){
                if(!lineFirstAppeared.containsKey(word)){
                    lineFirstAppeared.put(word, i);
                }
            }
        }

        //Print the first line appeared
        System.out.println("First line appeared:");
        lineFirstAppeared.forEach((key, value) -> System.out.println("   " + key + " : " + value));
    }

    public static void mostWordsInLineAppeared(String str){
        //Split str into lines
        String [] lines = str.split("\\. ");

        //Hashmap to store max values
        HashMap<String, Integer> mostTimesAppeared = new HashMap<String, Integer>();
        //Hashmap to store in which line it appeared
        HashMap<String, Integer> lineMostTimesAppeared = new HashMap<String, Integer>();
        for(int i = 0; i < lines.length; i++){
            //Set final variables
            int lineIndex = i;
            //Split line into words
            String [] words = lines[i].split("[,.\\s]+");
            //Hashmap to track amount of times a word appeared in line
            HashMap<String, Integer> timesAppearedInLine = new HashMap<String, Integer>();
            for(String word : words){
                if(!timesAppearedInLine.containsKey(word)){
                    timesAppearedInLine.put(word, 1);
                } else {
                    timesAppearedInLine.put(word, timesAppearedInLine.get(word) + 1);
                }
            }

            //Compare key values of hashmaps
            timesAppearedInLine.forEach((key, value) -> {
                if (!mostTimesAppeared.containsKey(key)) {
                    mostTimesAppeared.put(key, value);
                    lineMostTimesAppeared.put(key, lineIndex);
                } else {
                    // If the current value is greater than the existing value, update the counts
                    if (value > mostTimesAppeared.get(key)) {
                        mostTimesAppeared.put(key, value);
                        lineMostTimesAppeared.put(key, lineIndex);
                    }
                }
            });
        }

        //Print in which line the most words appeared
        System.out.println("Most times word appeared in line :");
        lineMostTimesAppeared.forEach((key, value) -> System.out.println("  " + key + " : " + value));
    }

    public static void wordStatsPerLine(String str) {
        // Split string into lines
        String[] lines = str.split("\\. ");
    
        HashMap<String, HashMap<String, Integer>> lineStats = new LinkedHashMap<>();
        for (int i = 0; i < lines.length; i++) {
            // Split line into words
            String[] words = lines[i].split("[,.\\s]+");
    
            // Hashmap to store the number of times each word appears in the line
            HashMap<String, Integer> wordsAppearedInLine = new HashMap<>();
            for (String word : words) {
                wordsAppearedInLine.put(word, wordsAppearedInLine.getOrDefault(word, 0) + 1);
            }
    
            // Add words per line hashmap to main hashmap
            lineStats.put("Line " + (i + 1), wordsAppearedInLine);
        }
    
        // Print word statistics per line
        lineStats.forEach((lineNumber, wordStats) -> {
            System.out.println(lineNumber + ":");
            wordStats.forEach((word, frequency) -> {
                System.out.println("    " + word + " : " + frequency);
            });
        });
    }
    

    public static void main(String[] args) throws Exception {
        //Read file
        readFile("src/Text.txt");
        //Show in which lines a word appeared
        linesAppeared(str);
        //Show total amount of words
        totalWordAppearances(str);
        //Show the first line the word appeared
        firstLineAppeared(str);
        //Show in which line the most instances of a word appeared
        mostWordsInLineAppeared(str);

        wordStatsPerLine(str);
    }
}
