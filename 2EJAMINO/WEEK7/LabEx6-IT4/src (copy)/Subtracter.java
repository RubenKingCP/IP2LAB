import java.util.Stack;

public class Subtracter extends Operation{
  Stack<Double> st;
  
  public Subtracter(Stack<Double> st) {
    this.st = st;
  }
  
  public void operate() {
    Double d = this.st.pop();
    this.st.push(Double.valueOf(((Double)this.st.pop()).doubleValue() - d.doubleValue()));
  }
}
