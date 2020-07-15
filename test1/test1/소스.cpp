#include <iostream>
#include <vector>

using namespace std;

class stack {

private:
	int top;
	int max_size;

	int* element;

public:
	stack() {
		this->top = -1;
		this->max_size = 1000;// 0;
		element = new int[max_size];
	}
	~stack() {
		delete[] element;
	}

	void push(int item) {
		if (top >= max_size - 1) { //��á�� Ȯ��
			stackFull();
		}
		else {
			element[++top] = item;
		}
	}
	int pop() {
		if (top == -1) {
			stackEmpty();
			exit(1);
		}
		else {
			return element[top--];
		}
	}

	void stackFull() {
		cout << "������ �������ֽ��ϴ�" << endl;//
	}
	void stackEmpty() {
		cout << "������ ����ֽ��ϴ�" << endl;
	}

};

//class queue {
//private:
//	int front;
//	int rear;
//	int max_size;
//
//	int* element;
//public:
//	queue() {
//		this->front = -1;
//		this->rear = -1;
//		this->max_size = 1000;//0;
//		element = new int[max_size];
//	}
//	~queue() {
//		delete[] element;
//	}
//
//	void push(int item) {
//		if (rear == max_size - 1) {
//			cout << "ť�� �������ֽ��ϴ�" << endl;
//		}
//		else {
//			element[++rear] = item;
//		}
//	}
//	int pop() {
//		if (front == rear) {
//			cout << "ť�� ����ֽ��ϴ�" << endl;
//			exit(1);
//		}
//		else {
//			return element[++front];
//		}
//	}
//};

template <typename T>
class queue {
private:
	int front;
	int rear;
	int max_size;

	T* element;
public:
	queue() {
		this->front = -1;
		this->rear = -1;
		this->max_size = 1000;//0;
		element = new T[max_size];
	}
	~queue() {
		delete[] element;
	}

	void addQ(T item) {
		if (rear == max_size - 1) {
			cout << "ť�� �������ֽ��ϴ�" << endl;
		}
		else {
			element[++rear] = item;
		}
	}
	T deleteQ() {
		if (front == rear) {
			cout << "ť�� ����ֽ��ϴ�" << endl;
			exit(1);
		}
		else {
			return element[++front];
		}
	}
};

int main() {
	stack test1;
	queue<int> test2;
	
	for (int i = 0; i < 1000; i++)
		test2.addQ(i);
	for (int i = 0; i < 1000; i++)
		cout << test2.deleteQ() << endl;
	test2.deleteQ();

	return 0;
}