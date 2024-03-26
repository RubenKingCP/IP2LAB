import java.util.ArrayList;

public class Window {
    private String name;
    private ArrayList<Circle> circles;
    private ArrayList<Rectangle> squares;
    private ArrayList<Triangle> triangles;

    public Window(String name){
        this.name = name;
        circles = new ArrayList<Circle>();
        squares = new ArrayList<Rectangle>();
        triangles = new ArrayList<Triangle>();

        System.out.println("creating " + this.name);
        draw();
    }

    public void draw(){
        System.out.println("drawing " + name + " on screen");
    }

    public void add(Circle c){
        //Adds new circle to array
        circles.add(c);
        //draw circle
        c.draw(name);
    }

    public void add(Triangle t){
        //Adds new triangle to array
        triangles.add(t);
        //draw triangle
        t.draw(name);
    }

    public void add(Rectangle sq){
        //Adds new sqaure to array
        squares.add(sq);
        //draw square
        sq.draw(name);
    }
}
