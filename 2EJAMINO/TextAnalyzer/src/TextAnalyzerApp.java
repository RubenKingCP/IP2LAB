
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
    public static void main(String[] args) throws Exception {
        //Read file
        readFile("Text.txt");

        //Split string into lines
        lineList = str.split("\\. ");

        //Initiate hashmaps
        HashMap<String, Integer> wordCount = new HashMap<String, Integer>();
        HashMap<String, Integer> trackLineAppeared = new HashMap<String, Integer>();
        HashMap<String, Integer> maxWordCountLine = new HashMap<String, Integer>();
        

        //Split each line into words
        for(int i = 0; i < lineList.length; i++){
            String[] lineWordList = lineList[i].split("[,.\\s]+");

            //HashMap to track each apperance in sentence
            HashMap<String, Integer> lineWordMap = new HashMap<String, Integer>();
            HashMap<String, Integer> tmpWordCount = new HashMap<String, Integer>();
            for(String lineWord : lineWordList) {
                //Check if it appeared in previous instance
                if(!wordCount.containsKey(lineWord)){
                    //Add word to wordCount
                    wordCount.put(lineWord, 1);
                    //Check first time appeared
                    trackLineAppeared.put(lineWord, i);
                }
                else{
                    //Increase total word counter
                    wordCount.put(lineWord, wordCount.get(lineWord) + 1);
                }

                //Check if word appeared 
                if(!lineWordMap.containsKey(lineWord)){
                    lineWordMap.put(lineWord, 1);
                    //Add word to line word count
                    tmpWordCount.put(lineWord, 1);
                }
                else
                    lineWordMap.put(lineWord, lineWordMap.get(lineWord) + 1);
                    //Increase line word counter
                    tmpWordCount.put(lineWord, tmpWordCount.get(lineWord) + 1);
            }

            //Print line and all key pair values
            System.out.println("Line " + i + ": " + lineList[i]);
            lineWordMap.forEach((key, value) -> System.out.println("    " + key + ": " + value));

            //Compare this line wordCount with the previous one
            tmpWordCount.forEach((key, value) -> {
                if(!maxWordCountLine.containsKey(key)){
                    maxWordCountLine.put(key, value);
                } else if(value > maxWordCountLine.get(key)) {
                    maxWordCountLine.put(key, value);
                }
            });
        }

        //Print total amount of times a word appeared
        System.out.println("Total amount of times: ");
        wordCount.forEach((key, value) -> System.out.println("  " + key + ": " + value));

        //Check in which line first appeared
        trackLineAppeared.forEach((key, value) -> System.out.println("First time " + key + " appeared in line : " + value));

        //Show most amount of words appeared in one line
        System.out.println("Most amount of words in one line");
        maxWordCountLine.forEach((key, value) -> System.out.println("   " + key + " : " + value));
    }
}
