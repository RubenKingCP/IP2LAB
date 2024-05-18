public class Example {
    public static void checkWords(String word, String text){
        String [] lines = text.split("\\. ");
        int timesAppeared = 0;
        int sentenceAppeared = 0;

        // if(!showWords(text).contains(word)){
        //     System.out.println("word not included");
        //     return;
        // }




        //APO EDO TIS ALLAGES mairy
        int currentLine = 0;
        boolean wordAppeared = false;


        for(String line : lines){
            String [] wordsInLine = line.split("[,.\\s]+");

            boolean appearedInLine = false;

            for(String wordInLine : wordsInLine){
                if(wordInLine.equals(word)){
                    timesAppeared++;

                    if(appearedInLine == false){
                        sentenceAppeared++;
                        appearedInLine = true;
                    }

                    if(wordAppeared == false){
                        sentenceAppeared = currentLine;
                        wordAppeared = true;
                    }

                }
            }

            currentLine++;
        }
        System.out.printf("numOfSentences: %d     numOfOccurrences: %d      firstSentenceIndex: %d%n",
                sentenceAppeared, timesAppeared, sentenceAppeared);

    }

    public static void main(String[] args) {
        checkWords("hello", "hello hello hello one tho three one hello. hello. hello. hello. hello hello hello hello.");
    }
}
