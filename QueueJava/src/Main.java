import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);

        int value, r, bufSize;
        System.out.print("Количество элементов в стеке: ");
        bufSize = console.nextInt();
        QueueCustom currentQueue = new QueueCustom(bufSize);

        do {
            System.out.print("Для добавления введите 1, для извлечения 0: ");
            r = console.nextInt();
            if (r == 1 || r == 0){
                if (r == 1){
                    System.out.print("Введите значение: ");
                    currentQueue.insert(console.nextInt());
                }
                else {
                    System.out.print("Значение равно: ");
                    System.out.println(currentQueue.remove());
                }
            }
            else {
                System.out.println("Incorrect input!\\nДля добавление введите 1, для извлечения 0: \\n");
                r = console.nextInt();
            }
        }while(true);
    }
}