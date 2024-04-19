import java.util.Stack;

public class Multiplier {
  Stack<Double> st;
  
  public Multiplier(Stack<Double> st) {
    this.st = st;
  }
  
  public void operate() {
    this.st.push(this.st.pop() * this.st.pop());
  }
}
