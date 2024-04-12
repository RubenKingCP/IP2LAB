import java.util.Stack;

public class Multiplier extends Operation{
  Stack<Double> st;
  
  public Multiplier(Stack<Double> st) {
    this.st = st;
  }
  
  public void operate() {
    this.st.push(Double.valueOf(((Double)this.st.pop()).doubleValue() * ((Double)this.st.pop()).doubleValue()));
  }
}
