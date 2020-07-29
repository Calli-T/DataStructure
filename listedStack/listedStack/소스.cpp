#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int key;
}element;
struct stack {
	element data;
	struct stack* link;
};
struct stack* top;

void push(element item) {
	struct stack* temp =
		(struct stack*)malloc(sizeof(struct stack));
	if (temp == NULL) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	temp->data = item;
	temp->link = top;
	top = temp;
}
element pop() {
	struct stack* temp = top;
	element item;
	if (temp == NULL) {
		fprintf(stderr, "The stack is empty\n");
		exit(1);
	}
	item = temp->data;
	top = temp->link;
	free(temp);

	return item;
}

int main() {
	element ins;
	top = NULL;

	ins.key = 1;
	push(ins);
	ins.key = 2;
	push(ins);
	ins.key = 3;
	push(ins);

	printf("%d\n", pop().key);
	printf("%d\n", pop().key);
	printf("%d\n", pop().key);

	return  0;
}