public class Stack {
    public Stack()
    {
        top = -1;
        array = new int[10];
    }
    public Stack(int N) {
        top = -1;
        array = new int[N];
    }

    private int[] array;
    private int top;
    private int N;

    public
    public void push(int a){
        if(top == N-1){
            System.out.println("Стек переполнен!!!");
        }
        else {
            top++;
            array[top] = a;
        }
    }

    public void pop(){
        if(top >= 0){
            System.out.println(array[top--]);
        }
        else{
            System.out.println("Стек пуст!!!");
        }
    }
}
