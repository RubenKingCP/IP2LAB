import java.util.Stack;

public class Subtracter implements Operation{
  Stack<Double> st;
  
  public Subtracter(Stack<Double> st) {
    this.st = st;
  }
  
  public void operate() {
    Double d = this.st.pop();
    this.st.push(this.st.pop() - d);
  }
}
