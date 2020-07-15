#include <stdio.h>
#include <stdlib.h>

#define max_stack_size 100
int top = -1;
int stack[max_stack_size];

void push(int item) {
	if (max_stack_size - 1 <= top)
		exit(1);
	stack[++top] = item;
}
int pop() {
	if (top == -1)
		exit(1);
	return stack[top--];
}

int main() {

	push(3);
	printf("%d\n", pop());

	return 0;
}