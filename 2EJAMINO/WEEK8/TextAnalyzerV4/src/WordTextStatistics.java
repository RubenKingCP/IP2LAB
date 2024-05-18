import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;

public class WordTextStatistics {
    private String[] words;
    private HashSet<String> uniqueWords;
    private HashMap<String, Integer> wordCount;
    private List<String[]> sentences;

    public WordTextStatistics(String text) {
        words = text.split("[,.\\s]+");
        sentences = new ArrayList<>();
        for (String sentence : text.split("[.!?]")) {
            sentences.add(sentence.trim().split("[\\s,]+"));
        }
        uniqueWords = new HashSet<>();
        wordCount = new HashMap<>();
        processWords();
    }

    private void processWords() {
        for (String word : words) {
            uniqueWords.add(word);
            wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
        }
    }

    public void showUniqueWords(){
        System.out.println(uniqueWords);
    }

    public int getTotalAppearances(String word) {
        return wordCount.getOrDefault(word, 0);
    }

    public int getSentencesWithWord(String word) {
        int count = 0;
        for (String[] sentence : sentences) {
            for (String w : sentence) {
                if (w.equals(word)) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }

    public int getFirstSentenceAppearance(String word) {
        for (int i = 0; i < sentences.size(); i++) {
            for (String w : sentences.get(i)) {
                if (w.equals(word)) {
                    //To make it more user friendly add one
                    return i + 1;
                }
            }
        }
        return -1;
    }

    public int getSentenceWithMaxAppearances(String word) {
        int maxCount = 0;
        int sentenceIndex = -1;
        for (int i = 0; i < sentences.size(); i++) {
            int count = 0;
            for (String w : sentences.get(i)) {
                if (w.equals(word)) {
                    count++;
                }
            }
            if (count > maxCount) {
                maxCount = count;
                sentenceIndex = i;
            }
        }
        //User frinedly add one
        return sentenceIndex + 1;
    }

    public void showWordStatistics(String word){
        if(!uniqueWords.contains(word)){
            System.out.println("<" + word + "> doesn't appeared in text!");
            return;
        }
        System.out.println("Times appeared in different sentences : " + getSentencesWithWord(word));
        System.out.println("First time appeared in sentence : " + getFirstSentenceAppearance(word));
        System.out.println("Appeared the most in sentence : " + getSentenceWithMaxAppearances(word));
    }

    public HashSet<String> getHashSet(){
        return uniqueWords;
    }
}
