public class Circle extends Shapes{
    
    public Circle(String name){
        super(name);
    }

    void draw(String window){
        System.out.println("Drawing " + name + " on " + window);
    }
}
