import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

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
        readFile("src/Text.txt");

        //Split string into lines
        lineList = str.split("\\. ");

        
    }
}
