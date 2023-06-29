#include <stdio.h>
#include <stdlib.h>


/* 재귀함수와 Node 연결리스트 */
typedef struct node {
	int data;
	struct node* next;
}node;

// 연결리스트 start : 1-2-3-4-5-6
node* push(node* head, int data){
	node* newnode = (node *)malloc(sizeof(node));

	newnode->data = data;
	newnode->next = head;

	head = newnode;
	return head;
}
void fun(struct node* start) {
	if (start == NULL)
		return;
	printf("%d ", start->data);

	if(start->next != NULL)
		fun(start->next->next); // 재귀함수 
	printf("%d ", start->data);
}


void fun1(struct node* head) {
	if (head == NULL)
		return;

	fun1(head->next); // 재귀함수 
	printf("%d ", head->data);
}

int main() {
	node* head = NULL;
	
	head = push(head, 6);
	head = push(head, 5);
	head = push(head, 4);
	head = push(head, 3);
	head = push(head, 2);
	head = push(head, 1);
	
	fun1(head);
	printf("\n\n");
	fun(head);
}