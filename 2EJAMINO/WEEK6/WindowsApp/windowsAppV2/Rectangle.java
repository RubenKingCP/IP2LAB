public class Rectangle {
    private String name;

    public Rectangle(String name){
        this.name = name;
        System.out.println("creating " + this.name);
    }

    public void draw(String window){
        System.out.println("drawing " + name + " on " + window);
    }
}
