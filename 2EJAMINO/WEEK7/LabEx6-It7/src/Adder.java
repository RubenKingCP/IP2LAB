import java.util.EmptyStackException;
import java.util.Stack;

public class Adder {
    Stack<Double> st;

    public Adder(Stack<Double> st){
        this.st = st;
    }

    public void operate() {
        try{
            if(st.size() > 1){
                this.st.push(this.st.pop() + this.st.pop());
            }
            else{
                throw new EmptyStackException();
            }
        }
        catch(EmptyStackException e){
            new StackEmptyPopUp(this.st);
        }
    }
}
