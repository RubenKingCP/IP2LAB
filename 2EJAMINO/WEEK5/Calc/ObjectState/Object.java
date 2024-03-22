public class Object {
    private String state;

    public Object(){
        state = "OFF";
    }

    public void press(Object obj1){
        toggleState(obj1);
        toggleState(obj1);
        System.out.println("Object pressed successfully");;
    }

    public void toggleState(Object obj1){
        System.out.println("Obj1 status : " + obj1.getState());
        if(obj1.getState() == "OFF"){
            obj1.setStateOn();
        }
        else if(obj1.getState() == "ON"){
            obj1.setStateOff();
        }
    }

    public String getState(){
        return state;
    }

    public void setStateOn(){
        state = "ON";
    }

    public void setStateOff(){
        state = "OFF";
    }
}
