public class Led{
    public String state;

    public Led(){
        state = "OFF";
    }

    public void on(){
        state = "ON";
    }

    public void off(){
        state = "OFF";
    }

    public boolean isOn(){
        if(state == "ON"){
            return true;
        }
        else return false;
    }

    public void toggle(Led led1){
        System.out.println("Button state : " + state);
        if(this.isOn()){
            led1.state = "OFF";
        }
        else {
            state = "ON";
        }
    }

    public void press(Led led1){
        toggle(led1);
        toggle(led1);
    }
}