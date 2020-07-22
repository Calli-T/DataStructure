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

//enum class precedence {
//	lparen, rparen, plus,
//	minus, times, divide,
//	mod, eos, operand
//};
//precedence get_token(char* symbol, int* n, char expr[]) {
//
//	*symbol = expr[(*n)++];
//
//	switch (*symbol) {
//
//	case '(': return precedence::lparen;
//	case ')': return precedence::rparen;
//	case '+': return precedence::plus;
//	case '-': return precedence::minus;
//	case '/': return precedence::divide;
//	case '*': return precedence::times;
//	case '%': return precedence::mod;
//	case ' ': return precedence::eos;
//	default : return precedence::operand;
//
//	}
//
//}
//
//char get_symbol(precedence& token) {
//	switch (token) {
//	case precedence::lparen: return '(';
//	case precedence::rparen: return ')';
//	case precedence::plus: return '+';
//	case precedence::minus: return '-';
//	case precedence::divide: return '/';
//	case precedence::times: return '*';
//	case precedence::mod: return '%';
//	case precedence::eos: return '\0';
//	}
//}

/*char expr[] = "branching Path";
	char symbol;
	int n = 0;
	precedence token = get_token(&symbol, &n, expr);
	if (token == precedence::operand)
		cout << "피연산자";*/

/*void toPostfix(char expr[]) {

	stack<precedence> st;
	char symbol;
	precedence token;
	int n = 0;
	int idx = 0;
	vector<char> postfix;

	//st.push(precedence::eos);
	for (token = get_token(&symbol, &n, expr);
		token != precedence::eos;
		token = get_token(&symbol, &n, expr)) {

		if (token == precedence::operand)
			postfix.push_back(symbol);
		else if (token == precedence::rparen) {
			while (st.Top() != precedence::lparen) {
				precedence tmp = st.pop();
				postfix.push_back(get_symbol(tmp));
			}
			st.pop();
		}
		else {
			while (true) {
				precedence now = st.Top();
				int tmp1 = get_priority(now, true);
				int tmp2 = get_priority(token, false);
				if (tmp1 < tmp2) break;

				precedence tmp = st.pop();
				postfix.push_back(get_symbol(tmp));
			}
			st.push(token);
		}
	}

	while ((token = st.pop()) != precedence::eos) {
		postfix.push_back(get_symbol(token));
	}

	//cout << postfix.size() << endl;
	for (int i = 0; i < postfix.size(); i++)
		cout << postfix[i];

}*/
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

int main() {

	/*char expr[100];
	cin.getline(expr, 100);*/
	string infix;
	cin >> infix;

	infix = toPostfix(infix);
	cout << infix;


}