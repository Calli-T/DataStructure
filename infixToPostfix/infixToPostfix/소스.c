#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_stack_size 100
#define max_expr_size 100

int top = -1;
int stack[max_stack_size];
char expr[max_expr_size] = "62/3-42*+";
int isp[] = { 0,19,12,12,13,13,13,0 };
int icp[] = { 20, 19,12,12,13,13,13,0 };
typedef enum {
	lparen, rparen, plus,
	minus, times, divide,
	mod, eos, operand
} precedence;

void push(int item);
int pop();
precedence get_token(char* symbol, int* n);
int eval(void);
void printToken(int token);
void convert();
void storeToken(int token, int n, char cvExpr[]);


// --------------------------------------------------------------------------






//---------------------------------------------------------------------------

int main() {
	scanf_s("%s", &expr, max_expr_size);
	convert();

	/*int a = eval();
	printf("%d\n", a);*/
	return 0;
}

//--------------------------------------------------

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
	case '\0': return eos;
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
void printToken(int token) {
	char list[] = { '(', ')', '+', '-', '*','/','%','\n' };
	printf("%c", list[token]);

}

void storeToken(int token, int n, char cvExpr[]) {
	char list[] = { '(', ')', '+', '-', '*','/','%','\n' };

	cvExpr[n++] = list[token];
	//cvExpr[n] = '\0';
}

void convert() {
	char symbol;
	precedence token;
	int n = 0;

	char cvExpr[max_expr_size];
	int cvIndex = 0;
	//int top = 0;
	//stack[0] = eos;
	for (token = get_token(&symbol, &n); token != eos; token = get_token(&symbol, &n)) {
		if (token == operand) {
			//printf("%c", symbol);

			cvExpr[cvIndex++] = symbol;
			//cvExpr[cvIndex] = '\0';
		}
		else if (token == rparen) {
			while (stack[top] != lparen) {
				//printToken(pop());
				storeToken(pop(), cvIndex, cvExpr);
			}
			pop();
		}
		else {
			while (isp[stack[top]] >= icp[token]) {
				//printToken(pop());
				storeToken(pop(), cvIndex, cvExpr);
			}
			push(token);
		}
	}

	while ((token = pop()) != eos) {
		//printToken(token);
		storeToken(pop(), cvIndex, cvExpr);
	}
	printf("%s", cvExpr);
}

//0--------------------------------------------------------------------0-//
//int exTop = -1;
//precedence exStack[max_stack_size];
//char infixExpr[max_expr_size];
//int isp[] = { 0,19,12,12,13,13,13,0 };
//int icp[] = { 20, 19,12,12,13,13,13,0 };
//
//void exPush(precedence item) {
//	if (max_stack_size - 1 <= top)
//		exit(1);
//	exStack[++exTop] = item;
//}
//precedence exPop() {
//	if (top == -1) {
//		exit(1);
//	}
//	//printf("%d\n", stack[top]);
//	return exStack[exTop--];
//}
//char printToken(int token) {
//	char list[] = { '(', ')', '+', '-','/','*', '%', '\0' };
//	return list[token];
//}
//
//void translate() {
//	char symbol;
//	precedence token;
//	int n = 0;
//	//int exTop = 0;
//	//stack[0] = eos;
//
//	for (token = get_token(&symbol, &n, infixExpr); token != eos; token = get_token(&symbol, &n, infixExpr)) {
//		if (token == operand)
//			printf("%c", symbol);
//		else if (token == rparen) {
//			while (exStack[exTop] != lparen)
//				printf("%c", printToken(exPop()));
//		}
//		else {
//			while (isp[exStack[exTop] >= icp[token]])
//				printf("%c", printToken(exPop()));
//			exPush(token);
//		}
//	}
//
//	while ((token = exPop()) != eos)
//		printf("%c",printToken(exPop()));
//	printf("\n");
//}