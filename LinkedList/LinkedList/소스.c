#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* link;
};
typedef struct node* kadena;

void showChain(kadena chain){

	/*kadena tmp = chain;
	printf("%d\n", tmp->data);
	do{
		tmp = tmp->link;
		printf("%d\n", tmp->data);
	} while (tmp->link != NULL);

	printf("\n");*/
	kadena tmp;
	for (tmp = chain; tmp != NULL; tmp = tmp->link)
		printf("%d\n", tmp->data);
	printf("\n");

}
void connectChain(kadena head, kadena tail) {
	head->link = tail;
	tail->link = NULL;
}
void insertChain(kadena left, kadena right, kadena mid) {
	left->link = mid;
	mid->link = right;
}
void deleteChain(kadena *start, kadena before, kadena A) {
	if (before != NULL)
		before->link = A->link;
	else *start = (*start)->link;
	free(A);
}
kadena make_tail_chain(kadena tail) {
	
	kadena unknown = (struct node*)malloc(sizeof(struct node));
	scanf_s("%d", &unknown->data);
	tail->link = unknown;
	unknown->link = NULL;

	return unknown;

}

int main() {
	struct node* chainHead = NULL;
	struct node* A, * B, * C;
	kadena chainTail;
	A = (struct node*)malloc(sizeof(struct node));
	B = (struct node*)malloc(sizeof(struct node));
	C = (struct node*)malloc(sizeof(struct node));
	A->data = 10; A->link = NULL;
	B->data = 20; B->link = NULL;
	C->data = 30; C->link = NULL;

	connectChain(A, B);
	chainHead = A;
	showChain(chainHead);

	insertChain(A, B, C);
	showChain(chainHead);

	deleteChain(&chainHead, NULL, A);
	showChain(chainHead);

	insertChain(C, NULL, B);
	deleteChain(&chainHead, NULL, C);
	showChain(chainHead);
	
	chainTail = B;
	chainTail = make_tail_chain(chainTail);
	chainTail = make_tail_chain(chainTail);
	chainTail = make_tail_chain(chainTail);
	chainTail = make_tail_chain(chainTail);
	chainTail = make_tail_chain(chainTail);
	
	printf("\n");
	showChain(chainHead);
	


	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct chain* pChain;
//typedef struct {
//	int data;
//	pChain next;
//} chain;
//
//void Connection(chain* front, chain* tail) {
//	front->next = (pChain)tail;
//	tail->next = NULL;
//}
//void showChain(chain *first){
//	chain* cur = first;
//	while (cur != NULL) {
//		printf("%d ", cur->data);
//		(pChain)cur = cur->next;
//	}
//}
//void insertChain(chain* left, chain* right, chain *mid) {
//	left->next = mid;
//	mid->next = right;
//}
//void deleteChain(chain* head, chain* trail, chain* x) {
//	trail->next = x->next;
//	if (x == head)
//		head = head->next;
//	//free(x);
//}
//
//int main() {
//
//	chain first, second;
//	first.data = 10;
//	second.data = 20;
//	Connection(&first, &second);
//	pChain head = &first;
//
//	showChain(&first);
//	printf("\n");
//
//	chain third;
//	third.data = 30;
//	Connection(&second, &third);
//
//	showChain(&first);
//	printf("\n");
//
//	chain mid1, mid2;
//	mid1.data = 15; mid2.data = 25;
//	insertChain(&first, &second, &mid1);
//	insertChain(&second, &third, &mid2);
//
//	showChain(&first);
//	printf("\n");
//
//	return 0;
//}

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