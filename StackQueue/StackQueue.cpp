#include <iostream>
using namespace std;
int N = 10; //укажем размер массива


class stack { //создадим класс stack
private: //эти члены класса будут закрытыми:
	int* arrStack; //сделаем указатель на массив
	int top; //переменная для вершины стека

public: // поскольку эти члены класса stack являются открытыми, то к ним можно получить
	//доступ напрямую из функции main()
	stack() //конструктор без параметров
{
	top = -1;
	arrStack = new int[N];
}
	  stack(int m) //конструктор с одним параметром
	  {
		  top = -1;
		  arrStack = new int[m];
	  }
	  ~stack() //деструктор
	  {
		  delete[] arrStack;
	  }
	  void push(int a) //функция добавления элемента
	  {
		  if (top == N - 1) //значение вершины равно размеру массива(стека)?
			  cout << "Стэк переполнен!!!" << endl;
		  else
		  {
			  top++;
			  arrStack[top] = a; //увеличиваем значение вершины и кладем это значение в массив
		  }
	  }
	  void pop() //функция извлечения элемента
	  {
		  if (top >= 0) //переменная вершины больше либо равна 0?
		  {
			  cout << arrStack[top]; //извлекаем значение
			  top--; //уменьшаем значение вершины на 1
		  }
		  else //иначе происходит ошибка
			  cout << "Стэк пуст!!!";
	  }
};

class queue { //создаем класс “Очередь”
private: //эти члены класса будут закрытыми
	int* arrQueue; //сделаем указатель на массив
	int head; //переменная для начала очереди(головы)
	int tail; //переменная для конца очереди(хвоста)
public: //эти члены класса будут открытыми
	queue()
	{
		head = 0;
		tail = 0;
		arrQueue = new int[N];
	}
	queue(int m)
	{
		head = 0;
		tail = 0;
		arrQueue = new int[m];
	}
	~queue() //деструктор для освобождения памяти
	{
		delete[] arrQueue;
	}
	void add_item(int a) //функция добавления элемента
	{
		if (head == (tail + 1) % N) //проверяем наличие места в очереди
			cout << "Очередь переполнена!!!" << endl;
		else
		{
			arrQueue[tail] = a; //записываем значение в массив
			tail = (tail + 1) % N; //присваиваем нашему “хвосту” номер последнего эл - та
		}
	}
	void extract_item() //функция извлечения элемента
	{
		if (head != tail) //проверяем наличие элементов в очереди
		{
			cout << arrQueue[head]; //выводим на экран последний в очереди элемент
			head = (head + 1) % N; //присваиваем нашей “голове” номер следующего эл - та
		}
		else
			cout << "Очередь пуста!!!";
	}
};

int main() {

	setlocale(LC_ALL, "Russian");

	int chooseAlg;
	int znachStack, znachQueue, inputField; //укажем логический тип данных для проверки логических условий
	cout << "Для активации Стека, введите 1, для активации Очереди введите 0: ";
	cin >> chooseAlg;
	
	switch (chooseAlg)
	{
	case 1:
	{
		cout << "Сколько будет элементов в стэке: ";
		cin >> N;
		stack one(N);
		do {
			cout << "Для добавление введите 1, для извлечения 0: ";
			cin >> inputField;
			if (inputField == 1 || inputField == 0)
			{
				if (inputField == 1)
				{
					cout << "Введите значение: ";
					cin >> znachStack;
					one.push(znachStack);
				}
				else
				{
					cout << "Значение равно: ";
					one.pop();
					cout << endl;
				}
			}
			else
			{
				cout << "Incorrect input!\nДля добавление введите 1, для извлечения 0: \n";
				cin >> inputField;
			}

		} while (true);
		break;
	}
	case 0:
	{
		cout << "Сколько будет элементов в Очереди: ";
		cin >> N;
		N++;
		queue currentQueue(N);
		do {
			cout << "Для добавление введите 1, для извлечения 0: ";
			cin >> inputField;
			if (inputField == 1 || inputField == 0)
			{
				if (inputField == 1)
				{
					cout << "Введите значение: ";
					cin >> znachQueue;
					currentQueue.add_item(znachQueue);
				}
				else
				{
					cout << "Значение равно: ";
					currentQueue.extract_item();
					cout << endl;
				}
			}
			else
			{
				cout << "Incorrect input!\nДля добавление введите 1, для извлечения 0: \n";
				cin >> inputField;
			}

		} while (true);
		break;
	}
	default:
		cout << "Incorrect input!!!" << endl;
	}

	
	return 0;
}
