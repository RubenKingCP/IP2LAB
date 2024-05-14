import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;

public class TextOperations {

    public String readFile(String textFileName) throws IOException {
        StringBuilder sb = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader(textFileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                sb.append(line);
            }
        }
        return sb.toString();
    }

    public void showSentences(String text) {
        int sentenceNumber = 1;
        String[] sentences = text.split("\\.\\s*");
        for (String sentence : sentences) {
            System.out.println("[" + sentenceNumber++ + "] " + sentence);
        }
    }

    public HashSet<String> showWords(String text) {
        HashSet<String> uniqueWords = new HashSet<>();
        String[] words = text.split("[.,\\s]+");
        for (String word : words) {
            uniqueWords.add(word.toLowerCase());
        }
        return uniqueWords;
    }

    public boolean getGeneralWordStats(String word, String text) {
        String[] sentences = text.split("\\.");
        int numOfTimesAppeared = 0;
        int numOfSentencesAppeared = 0;
        int sentenceAppeared = 0;
        int currentLine = 0;

        if (!showWords(text).contains(word)) {
            System.out.println("<" + word + "> is not included in text");
            return false;
        }
        boolean wordAppeared = false;

        for (String sentence : sentences) {
            String[] wordsInSentence = sentence.split("[.,\\s]+");
            boolean appearedInLine = false;
            for (String wordInSentence : wordsInSentence) {
                if (wordInSentence.equals(word)) {
                    numOfTimesAppeared++;
                    if (!appearedInLine) {
                        numOfSentencesAppeared++;
                        appearedInLine = true;
                    }
                    if (!wordAppeared) {
                        sentenceAppeared = currentLine;
                        wordAppeared = true;
                    }
                }
            }
            currentLine++;
        }

        System.out.printf("numOfSentences: %d     numOfOccurrences: %d      firstSentenceIndex: %d%n",
                numOfSentencesAppeared, numOfTimesAppeared, sentenceAppeared);
        return true;
    }

    public void getSentenceWordStats(String word, String text) {
        String[] sentences = text.split("\\.\\s*");
        int currentSentence = 0;
        for (String sentence : sentences) {
            String[] wordsInSentence = sentence.split("[.,\\s]+");
            int numOfOccurrences = 0;
            ArrayList<Integer> positions = new ArrayList<>();
            for (int i = 0; i < wordsInSentence.length; i++) {
                if (wordsInSentence[i].equalsIgnoreCase(word)) {
                    positions.add(i);
                    numOfOccurrences++;
                }
            }
            currentSentence++;
            System.out.printf("%d=   numOfOccurrences: %d     positions: %s, ", currentSentence,
                    numOfOccurrences, positions);
        }
        System.out.println();
    }

    public void getWordStats(String word, String text) {
        if(getGeneralWordStats(word, text)){
            System.out.print("wordSentenceStats: {");
            getSentenceWordStats(word, text);
            System.out.println("}");
        }
    }

    public void getTextStats(String text) {
        System.out.println("Word statistics");
        HashSet<String> uniqueWords = showWords(text);
        for (String word : uniqueWords) {
            System.out.printf("{%s=%n", word);
            getWordStats(word, text);
            System.out.println("}");
        }
    }
}
