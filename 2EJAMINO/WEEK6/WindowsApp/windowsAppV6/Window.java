import java.awt.Graphics;

public class Window {
    private String name;
    private Shapes [] shapes;
    private int shapesIndex = 0;
    private Graphics g;

    public Window(String name){
        this.name = name;
        shapes = new Shapes[100];
        draw();
    }

    public void draw(){
        System.out.println("drawing " + name + " on screen");
    }

    public void add(Shapes sh){
        //Adds new circle to array
        shapes[shapesIndex++] = sh;
        //draw circle
        sh.draw(g);
    }

    public void bringToFront() throws NullPointerException{
        draw();

        // for(int i = 0; i < shapesIndex; i++){
        //     shapes[i].draw(name);
        // }
        
        for(Shapes sh : shapes){
            if(sh != null){
                sh.draw(g);
            }
            else {
                break;
            }
        }
    }
}
