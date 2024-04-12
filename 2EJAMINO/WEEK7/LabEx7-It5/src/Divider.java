
import java.util.Stack;

public class Divider implements Operation{
  Stack<Double> st;
  
  public Divider(Stack<Double> st) {
    this.st = st;
  }
  
  public void operate() {
    Double d = this.st.pop();
    if (d.doubleValue() != 0.0D)
      this.st.push(this.st.pop() / d); 
  }
}
