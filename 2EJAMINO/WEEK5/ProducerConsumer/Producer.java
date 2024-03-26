public class Producer {
    Buffer buf;

    public Producer(Buffer buf){
        this.buf = buf;
    }

    public Good produce(int numOfGoods){
        return new Good(numOfGoods);
    }

    public void store(Good g){
        buf.store(g);
    }
}