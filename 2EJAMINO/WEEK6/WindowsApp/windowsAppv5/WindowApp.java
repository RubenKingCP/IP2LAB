public class WindowApp {
    private static Window win1;
    private static Window win2;
    public static void main(String[] args) {
        //Create window
        win1 = new Window("win1");

        //Add two circles
        win1.add(new Circle("c11"));
        win1.add(new Circle("c12"));

        //Add two squares
        win1.add(new Rectangle("r11"));
        win1.add(new Rectangle("r12"));

        //Add triangle
        win1.add(new Triangle("tr11"));

        //Make an empty line
        System.out.println("");

        //Create second window
        win2 = new Window("win2");

        //Add two circles
        win2.add(new Circle("c21"));
        win2.add(new Circle("c22"));

        //Add two squares
        win2.add(new Rectangle("r11"));
        win2.add(new Rectangle("r22"));

        //Add triangle
        win2.add(new Triangle("tr21"));
        win2.add(new Triangle("tr22"));

        //Bring to front
        System.out.println("");

        win1.bringToFront();
        
    }
}
