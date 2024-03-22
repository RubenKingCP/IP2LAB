import java.util.Stack;

public class Operations {
    private Stack<Double> st;
    private Double n1, n2;

    public Operations(Stack<Double> st){
        this.st = st;
        this.n1 = st.pop();
        this.n2 = st.pop();
    }

    public void add(){
        var n3 = n1 + n2;
        st.push(n3);
    }

    public void mul(){
        var n3 = n1 * n2;
        st.push(n3);
    }

    public void sub(){
        var n3 = n1 - n2;
        st.push(n3);
    }

    public void div(){
        if(n2 == 0.0){
            System.out.println("0 divisor... Try Another Operation");
            st.push(n2);
            st.push(n1);
            return;
        }

        var n3 = n1 / n2;
        st.push(n3);
    }
}
