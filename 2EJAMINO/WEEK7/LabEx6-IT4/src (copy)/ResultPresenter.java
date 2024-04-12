import java.util.Stack;

public class ResultPresenter extends Operation{
    Stack<Double> st;
  
    public ResultPresenter(Stack<Double> st) {
      this.st = st;
    }
    
    public void operate() {
      String str = ((Double)this.st.pop()).toString();
      System.out.println(str);
    }
}
