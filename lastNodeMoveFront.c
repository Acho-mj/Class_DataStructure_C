#include <stdio.h>
#include <stdlib.h>

/* 맨 마지막 노드를 맨 처음으로 이동 */
typedef struct node { 
	int data;
	struct node* next;
} Node;

Node* push(Node* head, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = head;

	head = newNode;
	return head;
}

// 리스트의 항목 출력
void printList(Node* head)
{
	while (head) {
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("\n");
}

// 노드 이동
Node* move(Node* head) {
	Node* p, * q;
	if (head == NULL || (head->next == NULL))
		return head;
	p = head; q = NULL;
	while (p->next != NULL) {
		q = p;
		p = p->next;
	}
	q->next = NULL;
	p->next = head;
	head = p;
	return head;
}

int main() {
	Node* head = NULL;
	head = push(head, 6);
	head = push(head, 5);
	head = push(head, 4);
	head = push(head, 3);
	head = push(head, 2);
	head = push(head, 1);
	printList(head);

	head = move(head);
	printList(head);
}