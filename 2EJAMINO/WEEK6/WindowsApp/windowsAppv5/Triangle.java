public class Triangle extends Shapes {

    public Triangle(String name){
        super(name);
    }

    void draw(String window){
        System.out.println("Drawing " + name + " on " + window);
    }
}
