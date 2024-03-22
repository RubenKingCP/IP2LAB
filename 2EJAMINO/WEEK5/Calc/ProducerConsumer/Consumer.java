import java.util.Scanner;

public class Consumer {
    private Scanner sc;
    private Buffer buf;
    private int goodsActive;

    public Consumer(){
        goodsActive = 0;
    }

    public void get(Buffer buf){
        sc = new Scanner(System.in);
        goodsActive += Integer.parseInt(sc.nextLine());
    }

    public void consume(){
        goodsActive = 0;
    }

    public void showGoods(){
        System.out.println("There are " + goodsActive + "left");
    }
}
