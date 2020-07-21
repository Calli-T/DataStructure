#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class stack {

private:
	int top;
	int max_size;

	T* element;

public:
	stack() {
		this->top = -1;
		this->max_size = 1000;// 0;
		element = new T[max_size];
	}
	~stack() {
		delete[] element;
	}

	void push(T item) {
		if (top >= max_size - 1) { //꽉찼나 확인
			stackFull();
		}
		else {
			element[++top] = item;
		}
	}
	T pop() {
		if (top == -1) {
			stackEmpty();
			exit(1);
		}
		else {
			return element[top--];
		}
	}

	void stackFull() {
		cout << "스택이 가득차있습니다" << endl;//
	}
	void stackEmpty() {
		cout << "스택이 비어있습니다" << endl;
	}

};

enum class precedence {
	lparen, rparen, plus,
	minus, times, divide,
	mod, eos, operand
};
precedence get_token(char* symbol, int* n, char expr) {

	*symbol = expr[(*n)++];

	switch (*symbol) {

	case '(': return precedence::lparen;
	case ')': return precedence::rparen;
	case '+': return precedence::plus;
	case '-': return precedence::minus;
	case '/': return precedence::divide;
	case '*': return precedence::times;
	case '%': return precedence::mod;
	case ' ': return precedence::eos;
	default : return precedence::operand;

	}

}

/*char expr[] = "branching Path";
	char symbol;
	int n = 0;
	precedence token = get_token(&symbol, &n, expr);
	if (token == precedence::operand)
		cout << "피연산자";*/

int main() {

	char expr[100];
	cin.getline(expr, 100);
	cout << expr;
	
	stack<precedence> st;

}