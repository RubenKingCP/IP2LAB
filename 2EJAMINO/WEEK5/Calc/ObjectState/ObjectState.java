public class ObjectState {
    private static Object obj1;
    private static Object obj2;
    public static void main(String[] args) {
        obj1 = new Object();
        obj2 = new Object();
        obj2.press(obj1);

        System.out.println("ObjectState finished successfully");
    }
}