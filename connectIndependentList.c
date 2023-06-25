#include <stdio.h>
#include <stdlib.h>

//독립된 노드를 연결해주는 프로그램


struct Node {
	double data;
	struct Node *next;
};

void print_list(struct Node* n){
	while (n != NULL) {
		printf(" %lf -> ", n->data);
		n = n->next;
	}
	printf("NULL \n");
}


int main(){
	struct Node *head = NULL;
	struct Node *second = NULL;
	struct Node *third = NULL;
	struct Node *forth = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	forth = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1; 
	head->next = second; 

	second->data = 2;
	second->next = third;

	third->data = 3; 
	third->next = forth;

	forth->data = 4;
	forth->next = NULL;


	print_list(head);

	free(head);
	free(second);
	free(third);

	return 0;
}