public class Stack {

    private int[] array;
    private int top;
    private int sizeStack;
    public Stack()
    {
        top = -1;
        array = new int[10];
    }
    public Stack(int sizeStack) {
        top = -1;
        array = new int[sizeStack];
        this.sizeStack = sizeStack;
    }

    //public
    public void push(int addedElement){
        if(top == sizeStack-1){
            System.out.println("Стек переполнен!!!");
        }
        else {
            top++;
            array[top] = addedElement;
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
