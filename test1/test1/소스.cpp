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
		if (top >= max_size - 1) { //꽉찼나 확인
			stackFull();
		}
		else {
			element[++top] = item;
		}
	}
	int pop() {
		if (top == -1) {
			stackEmpty();
		}
		else {
			return element[top--];
		}
	}

	void stackFull() {
		cout << "스택이 가득차있습니다" << endl;
	}
	void stackEmpty() {
		cout << "스택이 비어있습니다" << endl;
	}

};

int main() {
	stack test1;
	
	for (int i = 0; i < 1000; i++)
		test1.push(i);

	for (int i = 0; i < 1000; i++)
		cout << test1.pop() << endl;

	test1.pop();

	return 0;
}