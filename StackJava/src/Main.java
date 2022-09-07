import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);

        int value, r, bufSize;
        System.out.print("Количество элементов в стеке: ");
        bufSize = console.nextInt();
        Stack currentStack = new Stack(bufSize);

        do {
            System.out.print("Для добавления введите 1, для извлечения 0: ");
            r = console.nextInt();
            if (r == 1 || r == 0){
                if (r == 1){
                    System.out.print("Введите значение: ");
                    currentStack.push(console.nextInt());
                }
                else {
                    System.out.print("Значение равно: ");
                    currentStack.pop();
                }
            }
            else {
                System.out.println("Incorrect input!\\nДля добавление введите 1, для извлечения 0: \\n");
                r = console.nextInt();
            }
        }while(true);
    }
}