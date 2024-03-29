public class Rectangle extends Shapes{

    public Rectangle(String name){
        super(name);
    }

    public void draw(String window){
        System.out.println("Drawing " + name + " on " + window);
    }
}
