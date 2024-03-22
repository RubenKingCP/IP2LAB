import java.util.Scanner;

public class Producer {
    private Scanner sc;
    private int goodsActive;

    public void produce(){
        sc = new Scanner(System.in);
        goodsActive += Integer.parseInt(sc.nextLine());
    }

    public void store(Buffer buf){
        buf.store(goodsActive);
        goodsActive = 0;
    }
}
