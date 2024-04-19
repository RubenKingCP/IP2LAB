import java.util.Stack;

public class Operand {
    Stack<Double> st;

    private StringBuffer sb = new StringBuffer();

    public Operand(Stack<Double> st){
        this.st = st;
    }

    public void show(){
        System.out.println(this.sb);
    }

    public void addDigit(char digit){
        this.sb.append(digit);
        show();
    }

    public void deleteLastDigit() {
        if (this.sb.length() > 0) {
          this.sb.deleteCharAt(this.sb.length() - 1);
          show();
        } 
    }

    public void complete() {
        if (this.sb.length() > 0) {
          this.st.push(Double.parseDouble(this.sb.toString()));
          this.sb.delete(0, this.sb.length());
          show();
        } 
    }

    public void reset(){
        this.sb.delete(0, this.sb.length());
        st.clear();
    }

    public String getString(){
        return this.sb.toString();
    }

    public Operand(){};
}
