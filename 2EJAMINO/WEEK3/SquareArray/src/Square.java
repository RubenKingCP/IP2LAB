

public class Square {
    private int side;
    private int area;

    public Square(int side){
        this.side = side;
        this.area = this.side * this.side;
    }

    public void showArea(){
        System.out.println("CurArea: " + this.area);
    }
}