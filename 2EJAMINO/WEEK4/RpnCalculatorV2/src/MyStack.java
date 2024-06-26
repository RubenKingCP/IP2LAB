import java.util.ArrayList;
import java.util.EmptyStackException;

public class MyStack<T> {
    private ArrayList<T> stack;

    public MyStack() {
        stack = new ArrayList<>();
    }

    public void push(T item){
        stack.add(item);
    }

    public T pop(){
        if(isEmpty()){
            throw new EmptyStackException();
        }
        return stack.remove(stack.size() - 1);
    }

    public T peek(){
        if(isEmpty()){
            throw new EmptyStackException();
        }
        return stack.get(stack.size() - 1);
    }
    public boolean isEmpty() {
        return stack.isEmpty();
    }

    public int size() {
        return stack.size();
    }
}
