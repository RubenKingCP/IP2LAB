public class ObjectState {
    private static Led obj1;
    private static Led obj2;
    public static void main(String[] args) {
        obj1 = new Led();
        obj2 = new Led();
        obj2.press(obj1);

        System.out.println("ObjectState finished successfully");
    }
}