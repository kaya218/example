#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct stackNode {
	element data;
	struct stackNode* next;
} stackNode;

void push(element item, stackNode** top) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->next = *top;
	*top = temp;
}

element pop(stackNode** top) {
	element item;
	stackNode* temp = *top;
	item = temp->data;
	*top = (*top)->next;
	free(temp);
	return item;
}

void reverse_stack(stackNode** top) {
	stackNode* temp1 = NULL;	// 임시 스택 1
	stackNode* temp2 = NULL;	// 임시 스택 2

	// 모든 원소들을 새로운 스택에 pop, push 3번 반복하면 역순으로 저장된다.
	while(*top!=NULL)
		push(pop(top), &temp1);
	while(temp1!=NULL)
		push(pop(&temp1), &temp2);
	while(temp2!=NULL)
		push(pop(&temp2), top);
}

void printStack(stackNode* top) {
	stackNode* p = top;
	printf("STACK [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("]\n");
}

int main(void) {
	int data;
	stackNode* top = NULL;
	push(1, &top); push(2, &top), push(3, &top);
	printStack(top);
	printf("=====Reverse=====\n");
	reverse_stack(&top);
	printStack(top);
	return 0;
}
