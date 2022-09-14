#include <iostream>

using namespace std;

class queue
{
private:
    int sizeQueue;
    int headQueue, tailQueue;
    int* arrayQueue;
public:
    queue(int constructorSize) {
        sizeQueue = constructorSize;
        headQueue = tailQueue = 0;
        arrayQueue = new int[sizeQueue];
    }
    ~queue() {
        delete[] arrayQueue;
    }

    void addElement(int addedElement){
        if (headQueue == (tailQueue+1) % sizeQueue) {
            throw exception("Queue is full!");
        }
        else {
            arrayQueue[tailQueue] = addedElement;
            tailQueue = (tailQueue + 1) % sizeQueue;
        }
    }
    int extractElement() {
        if (headQueue == tailQueue) {
            throw exception("Queue is empty");
        }
        else {
            int tempHead = arrayQueue[headQueue];
            headQueue = (headQueue + 1) % sizeQueue;
            return tempHead;
        }
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    int tempSize, userChoice, tempValue, code;
    char ch;

    cout << "Enter the stack size: ";
    cin >> tempSize;

    queue mosQueue(tempSize);

    do {
        cout << "To add an element, enter 1, to extract 0: ";
        cin >> userChoice;

        //ch = userChoice;
        //code = static_cast<int>(ch);
        //if (ch == 27) // если клавиша esc
        //{
        //    break;
        //    exit(0);//Выход из програмы
        //}

        if (userChoice == 1 || userChoice == 0) {
            if (userChoice == 1) {
                try
                {
                    cout << "Enter a value: ";
                    cin >> tempValue;
                    mosQueue.addElement(tempValue);
                }
                catch (const exception& error)
                {
                    cerr << "Error: " << error.what() << endl;
                }
            }
            else {
                try {
                    cout << "The value is equal to: " << mosQueue.extractElement() << endl;
                }
                catch (const exception& error) {
                    cerr << "Error: " << error.what() << endl;
                }
            }
        }
    } while (true);
}
