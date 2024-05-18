import java.util.ArrayList;
import java.util.LinkedHashMap;


public class WordSentenceStatistics {
    private String[] sentences;
    
    public WordSentenceStatistics(String text){
        sentences = text.split("\\. ");
         
    }

    public void displaySentences(){
        int curSentence = 0;
        for(String sentence : sentences){
            System.out.println("<" + curSentence + "> " + sentence);
        }
    }
    
    public void showWordSentenceStatistics(String word) {
        LinkedHashMap<String, ArrayList<Integer>> stats = new LinkedHashMap<>();
        int curSentence = 1;
        for (String sentence : sentences) {
            ArrayList<Integer> positions = new ArrayList<>();
            String[] wordsOfSentence = sentence.split("[,\\s]+");
            for (int i = 0; i < wordsOfSentence.length; i++) {
                if (wordsOfSentence[i].equalsIgnoreCase(word)) {
                    positions.add(i + 1);
                }
            }
            stats.put("Sentence " + curSentence++, positions);
        }

        stats.forEach((key, value) -> {
            if (!value.isEmpty()) {
                System.out.println(key + " : " + value + "  Times appeared: " + value.size());
            }
        });
    }
}