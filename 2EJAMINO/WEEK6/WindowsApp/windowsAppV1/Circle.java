public class Circle {
    private String name;

    public Circle(String name){
        this.name = name;
        System.out.println("creating " + this.name);
    }

    public void draw(String window){
        System.out.println("drawing " + name + " on " + window);
    }
}
