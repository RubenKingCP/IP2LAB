import java.util.Stack;

public class ResultPresenter {
    Stack<Double> st;
  
    public ResultPresenter(Stack<Double> st) {
      this.st = st;
    }
    
    public void operate() {
      String str = (this.st.peek()).toString();
      System.out.println(str);
    }
}
