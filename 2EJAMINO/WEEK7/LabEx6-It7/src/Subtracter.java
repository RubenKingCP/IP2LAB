import java.util.EmptyStackException;
import java.util.Stack;

public class Subtracter {
  Stack<Double> st;
  
  public Subtracter(Stack<Double> st) {
    this.st = st;
  }
  
  public void operate() {
    try{
      if(this.st.size() > 1){
        Double d = this.st.pop();
        this.st.push(this.st.pop() - d);
      }
      else throw new EmptyStackException();
    }
    catch(EmptyStackException e){
      new StackEmptyPopUp(this.st);
    } 
  }
}
