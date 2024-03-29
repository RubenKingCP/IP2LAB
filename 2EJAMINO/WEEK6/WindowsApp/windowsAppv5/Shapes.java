public abstract class Shapes {
    public String name;
    public Shapes(String name){
        this.name = name;
        System.out.println(name);
    }
    
    abstract void draw(String window);
}