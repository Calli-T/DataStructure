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
	T Top(void) {
		return element[top];
	}

};

bool isSymbol(char& a) {
	switch (a) {
	case '(': return true;
	case ')': return true;
	case '+': return true;
	case '-': return true;
	case '*': return true;
	case '/': return true;
	case ' ': return true;
	case '%': return true;
	default: return false;
	}
}
int get_priority(char& token, bool inStack) {

	int isp[] = { 0,19,12,12,13,13,13,0 };
	int icp[] = { 20,19,12,12,13,13,13,0 };

	if (inStack == true) {

		switch (token) {
		case '(': return isp[0];
		case ')': return isp[1];
		case '+': return isp[2];
		case '-': return isp[3];
		case '/': return isp[4];
		case '*': return isp[5];
		case '%': return isp[6];
		case ' ': return isp[7];
		}

	}
	else {

		switch (token) {
		case '(': return icp[0];
		case ')': return icp[1];
		case '+': return icp[2];
		case '-': return icp[3];
		case '/': return icp[4];
		case '*': return icp[5];
		case '%': return icp[6];
		case ' ': return icp[7];
		}

	}
}

string toPostfix(string expr) {
	string cpy;
	cpy.resize(100);
	char token;
	int index = 0;
	stack<char> st;

	st.push(' ');
	for (int i = 0; i < expr.size(); i++) {

		if (isSymbol(expr[i]) == false) {
			cpy[index] = expr[i];
			index++;

		}
		else if (expr[i] == ')') {
			while ((token = st.Top()) != '(') {
				cpy[index] = st.pop();
				index++;
			}
			st.pop();

		}
		else {
			while (true) {
				char now = st.Top();
				int tmp1 = get_priority(now, true);
				int tmp2 = get_priority(expr[i], false);
				if (tmp1 < tmp2) break;

				cpy[index] = st.pop();
				index++;
			}

			st.push(expr[i]);
		}
	}

	while ((token = st.pop()) != ' ') {
		cpy[index] = token;
		index++;
	}

	return cpy;
}

int calcPostfix(string postfix) {

	stack<int> st;
	int tmp1, tmp2;
	int ans = 0;

	for (int i = 0; i < postfix.size(); i++) {
		if (isSymbol(postfix[i]) == false)
			st.push(((postfix[i]) - 48));
		else {
			tmp1 = st.pop();
			tmp2 = st.pop();
			//cout << tmp1 << " " << tmp2 << endl;
			switch (postfix[i]) {
			case '+':st.push(tmp1 + tmp2); break;
			case '-':st.push(tmp1 - tmp2); break;
			case '*':st.push(tmp1 * tmp2); break;
			case '/':st.push(tmp1 / tmp2); break;
			case '%':st.push(tmp1 % tmp2); break;
			}
			ans = st.Top();
		}
	}

	return ans;
}

int main() {

	string infix, postfix;
	cin >> infix;

	postfix = toPostfix(infix);
	cout << calcPostfix(postfix);

}