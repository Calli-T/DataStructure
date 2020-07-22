#include <stdio.h>
#include <stdlib.h>

#define max_stack_size 100
#define max_expr_size 100
int top = -1;
int stack[max_stack_size];
char expr[max_expr_size] = "62/3-42*+";
void push(int item) {
	if (max_stack_size - 1 <= top)
		exit(1);
	stack[++top] = item;
}
int pop() {
	if (top == -1) {
		exit(1);
	}
	//printf("%d\n", stack[top]);
	return stack[top--];
}

typedef enum {
	lparen, rparen, plus,
	minus, times, divide,
	mod, eos, operand
} precedence;
precedence get_token(char* symbol, int* n) {

	*symbol = expr[(*n)++];
	switch (*symbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case ' ': return eos;
	default: return operand;
	}
}

int eval(void) {

	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	top = -1;
	token = get_token(&symbol, &n);

	while (token != eos) {
		if (token == operand)
			push(symbol - 48);
		else {
			op2 = pop();
			op1 = pop();
			switch (token) {
			case plus: push(op1 + op2); break;
			case minus: push(op1 - op2); break;
			case times: push(op1 * op2); break;
			case divide: push(op1 / op2); break;
			case mod: push(op1 % op2); break;
			}
		}
		token = get_token(&symbol, &n);
	}

	return pop();
}

int main() {
	//scanf_s("%s", &expr, max_expr_size);
	int a = eval();
	printf("%d\n", a);
	return 0;
}