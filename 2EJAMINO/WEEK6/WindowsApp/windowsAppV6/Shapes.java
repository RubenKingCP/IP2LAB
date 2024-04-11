import java.awt.Graphics;

public abstract class Shapes {
    private int x;
    private int y;
    private int width;
    private int height;

    public Shapes(int x, int y, int width, int height){
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }
    
    abstract void draw(Graphics g);
}