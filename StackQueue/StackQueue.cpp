#include <iostream>
using namespace std;
int N = 10; //������ ������ �������


class stack { //�������� ����� stack
private: //��� ����� ������ ����� ���������:
	int* arrStack; //������� ��������� �� ������
	int top; //���������� ��� ������� �����

public: // ��������� ��� ����� ������ stack �������� ���������, �� � ��� ����� ��������
	//������ �������� �� ������� main()
	stack() //����������� ��� ����������
{
	top = -1;
	arrStack = new int[N];
}
	  stack(int m) //����������� � ����� ����������
	  {
		  top = -1;
		  arrStack = new int[m];
	  }
	  ~stack() //����������
	  {
		  delete[] arrStack;
	  }
	  void push(int a) //������� ���������� ��������
	  {
		  if (top == N - 1) //�������� ������� ����� ������� �������(�����)?
			  cout << "���� ����������!!!" << endl;
		  else
		  {
			  top++;
			  arrStack[top] = a; //����������� �������� ������� � ������ ��� �������� � ������
		  }
	  }
	  void pop() //������� ���������� ��������
	  {
		  if (top >= 0) //���������� ������� ������ ���� ����� 0?
		  {
			  cout << arrStack[top]; //��������� ��������
			  top--; //��������� �������� ������� �� 1
		  }
		  else //����� ���������� ������
			  cout << "���� ����!!!";
	  }
};

class queue { //������� ����� ���������
private: //��� ����� ������ ����� ���������
	int* arrQueue; //������� ��������� �� ������
	int head; //���������� ��� ������ �������(������)
	int tail; //���������� ��� ����� �������(������)
public: //��� ����� ������ ����� ���������
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
	~queue() //���������� ��� ������������ ������
	{
		delete[] arrQueue;
	}
	void add_item(int a) //������� ���������� ��������
	{
		if (head == (tail + 1) % N) //��������� ������� ����� � �������
			cout << "������� �����������!!!" << endl;
		else
		{
			arrQueue[tail] = a; //���������� �������� � ������
			tail = (tail + 1) % N; //����������� ������ ������� ����� ���������� �� - ��
		}
	}
	void extract_item() //������� ���������� ��������
	{
		if (head != tail) //��������� ������� ��������� � �������
		{
			cout << arrQueue[head]; //������� �� ����� ��������� � ������� �������
			head = (head + 1) % N; //����������� ����� ������� ����� ���������� �� - ��
		}
		else
			cout << "������� �����!!!";
	}
};

int main() {

	setlocale(LC_ALL, "Russian");

	int chooseAlg;
	int znachStack, znachQueue, inputField; //������ ���������� ��� ������ ��� �������� ���������� �������
	cout << "��� ��������� �����, ������� 1, ��� ��������� ������� ������� 0: ";
	cin >> chooseAlg;
	
	switch (chooseAlg)
	{
	case 1:
	{
		cout << "������� ����� ��������� � �����: ";
		cin >> N;
		stack one(N);
		do {
			cout << "��� ���������� ������� 1, ��� ���������� 0: ";
			cin >> inputField;
			if (inputField == 1 || inputField == 0)
			{
				if (inputField == 1)
				{
					cout << "������� ��������: ";
					cin >> znachStack;
					one.push(znachStack);
				}
				else
				{
					cout << "�������� �����: ";
					one.pop();
					cout << endl;
				}
			}
			else
			{
				cout << "Incorrect input!\n��� ���������� ������� 1, ��� ���������� 0: \n";
				cin >> inputField;
			}

		} while (true);
		break;
	}
	case 0:
	{
		cout << "������� ����� ��������� � �������: ";
		cin >> N;
		N++;
		queue currentQueue(N);
		do {
			cout << "��� ���������� ������� 1, ��� ���������� 0: ";
			cin >> inputField;
			if (inputField == 1 || inputField == 0)
			{
				if (inputField == 1)
				{
					cout << "������� ��������: ";
					cin >> znachQueue;
					currentQueue.add_item(znachQueue);
				}
				else
				{
					cout << "�������� �����: ";
					currentQueue.extract_item();
					cout << endl;
				}
			}
			else
			{
				cout << "Incorrect input!\n��� ���������� ������� 1, ��� ���������� 0: \n";
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
