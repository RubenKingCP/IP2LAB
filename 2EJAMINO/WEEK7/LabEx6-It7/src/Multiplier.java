import java.util.EmptyStackException;
import java.util.Stack;

public class Multiplier {
  Stack<Double> st;
  
  public Multiplier(Stack<Double> st) {
    this.st = st;
  }
  
  public void operate() {
    try{
      if(this.st.size() > 1){
        this.st.push(this.st.pop() * this.st.pop());
      }
      else throw new EmptyStackException();
    }
    catch(EmptyStackException e){
      new StackEmptyPopUp(this.st);
    }
  }
}
