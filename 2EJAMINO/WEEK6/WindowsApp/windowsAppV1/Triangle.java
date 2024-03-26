public class Triangle {
    private String name;

    public Triangle(String name){
        this.name = name;
        System.out.println("creating " + this.name);
    }

    public void draw(String window){
        System.out.println("drawing " + name + " on " + window);
    }
}
