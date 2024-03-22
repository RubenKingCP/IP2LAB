
public class Buffer {
    private int totalGoods;

    public Buffer(){
        totalGoods = 0;
    }

    public void store(int numOfGoods){
        totalGoods += numOfGoods;
    }

    public void get(int numOfGoods){
        totalGoods -= numOfGoods;
    }

    public void showTotal(){
        System.out.println("Total good : " + totalGoods);
    }
}
