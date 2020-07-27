#include <stdio.h>
#include <stdlib.h>

typedef struct chain* pChain;
typedef struct {
	int data;
	pChain next;
} chain;

void Connection(chain* front, chain* tail) {
	front->next = (pChain)tail;
	tail->next = NULL;
}
void showChain(chain *first){
	chain* cur = first;
	while (cur != NULL) {
		printf("%d ", cur->data);
		(pChain)cur = cur->next;
	}
}
void insertChain(chain* left, chain* right, chain *mid) {
	left->next = mid;
	mid->next = right;
}
void deleteChain(chain* head, chain* trail, chain* x) {
	trail->next = x->next;
	if (x == head)
		head = head->next;
	//free(x);
}

int main() {

	chain first, second;
	first.data = 10;
	second.data = 20;
	Connection(&first, &second);
	pChain head = &first;

	showChain(&first);
	printf("\n");

	chain third;
	third.data = 30;
	Connection(&second, &third);

	showChain(&first);
	printf("\n");

	chain mid1, mid2;
	mid1.data = 15; mid2.data = 25;
	insertChain(&first, &second, &mid1);
	insertChain(&second, &third, &mid2);

	showChain(&first);
	printf("\n");

	return 0;
}

//int createChain(chain** kadena) {
//
//	int n;
//	int i;
//	scanf_s("%d", &n);
//	*kadena = (chain*)malloc(sizeof(chain) * n);
//	for (i = 0; i < n - 1; i++) {
//		(*kadena)[i].next = &(*kadena)[i + 1];
//	}
//	(*kadena)[i].next = NULL;
//
//	return n;
//}
//void insertChain(chain** kadena, int n, int x, chain mini) {//크기가 n인 연결리스트 kadena의 x번째 원소(0가능)뒤에 mini를 삽입한다
//	
//}
//
//int main() {
//
//	chain* kadena = NULL;// = (chain*)malloc(sizeof(chain) * n);
//	int chainSize = createChain(&kadena);
//	chain* cur;// = &kadena[0];
//	for (cur = &kadena[0]; cur != NULL; cur = cur->next) {
//		scanf_s("%d", &cur->data);
//	}
//	free(kadena);
//	for (cur = &kadena[0]; cur != NULL; cur = cur->next) {
//		printf("%d %d\n", *cur->data, cur->next);
//	}
//
//
//
//	return 0;
//}