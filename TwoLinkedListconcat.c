#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int element;

// 노드 타입 선언
typedef struct node {
	int data;
	struct node* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

// concat_list 함수 선언
ListNode* concat_list(ListNode* head1, ListNode* head2) {
	ListNode* last = head1;

	while (last->link != NULL) {
		last = last->link;
	}
	last->link = head2;
	return head1;
}

int main(void) {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);
	print_list(head1);

	head2 = insert_first(head2, 40);
	head2 = insert_first(head2, 50);
	print_list(head2);

	ListNode* total = concat_list(head1, head2);
	print_list(total);
	return 0;
}
