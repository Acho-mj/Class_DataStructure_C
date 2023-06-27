#include <stdio.h>
#include <stdlib.h>

/* �� ������ ��带 �� ó������ �̵� */
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

// ����Ʈ�� �׸� ���
void printList(Node* head)
{
	while (head) {
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("\n");
}

// ��� �̵�
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