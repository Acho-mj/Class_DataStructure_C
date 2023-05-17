#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;


Node* circular(Node* head) {
	Node* start = head;

	while (head->next != NULL) {
		head = head->next;
	}

	head->next = start;
	return start;
}

Node* push(Node* head, int data){
	Node* newNode = (Node *)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = head;

	head = newNode;
	return head;
}


void displayList(Node* node, char C){
	if (C == 'c') {
		Node* start = node;

		while (node->next != start) {
			printf("[%i] [%p]->%p\n", node->data, node, node->next);
			node = node->next;
		}
		printf("[%i] [%p]->%p\n", node->data, node, node->next);
	}
	else {
		while (node) {
			printf("[%i] [%p]->%p\n", node->data, node, node->next);
			node = node->next;
		}
		printf("\n");
	}
}

int main(){
	Node* head = NULL;

	head = push(head, 15);
	head = push(head, 14);
	head = push(head, 13);
	head = push(head, 22);
	head = push(head, 17);

	printf("Display linear linked list: \n");
	displayList(head, 's');

	circular(head);

	printf("Display circular linked list: \n");
	displayList(head, 'c');

	return 0;
}
