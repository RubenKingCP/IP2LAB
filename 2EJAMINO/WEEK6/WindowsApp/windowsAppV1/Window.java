public class Window {
    private String name;
    private Circle [] circles;
    private Rectangle [] squares;
    private Triangle [] triangles;
    private int circleIndex = 0;
    private int squareIndex = 0;
    private int triangleIndex = 0;

    public Window(String name){
        this.name = name;
        circles = new Circle[100];
        squares = new Rectangle[100];
        triangles = new Triangle[100];

        System.out.println("creating " + this.name);
        draw();
    }

    public void draw(){
        System.out.println("drawing " + name + " on screen");
    }

    public void addCircle(Circle c){
        //Adds new circle to array
        circles[circleIndex++] = c;
        //draw circle
        c.draw(name);
    }

    public void addTriangle(Triangle t){
        //Adds new triangle to array
        triangles[triangleIndex++] = t;
        //draw triangle
        t.draw(name);
    }

    public void addRectangle(Rectangle sq){
        //Adds new sqaure to array
        squares[squareIndex++] = sq;
        //draw square
        sq.draw(name);
    }
}
