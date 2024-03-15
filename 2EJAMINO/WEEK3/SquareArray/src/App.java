

public class App {
    public static void main(String[] args) throws Exception {
        Square stack[] = new Square[10];

        for(int i = 10; i > 0; i--){
            stack[10 - i] =  new Square(i+1);
        }

        for(int i = 0; i < 10; i++){
            stack[i].showArea();
        }
    }
}
