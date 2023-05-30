#include <stdio.h>
#include <stdlib.h>

// heap에 대한 1차원 배열과 heap 원소의 개수를 구조체로 묶어서 선언
typedef struct {
	int heap[100];
	int heap_size;
}heapType;

heapType* createHeap() {
	heapType* h = (heapType*)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}

// heap에 item을 삽입하는 연산
void insertHeap(heapType* h, int item) {
	int i;
	h->heap_size = h->heap_size + 1;
	i = h->heap_size;
	while ((i != 1) && (item > h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

// heap에서 item을 삭제하는 연산
int deleteHeap(heapType* h) {
	int parent, child;
	int item, temp;

	item = h->heap[1];
	temp = h->heap[h->heap_size];
	h->heap_size = h->heap_size - 1;

	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1]))
			child++;
		if (temp >= h->heap[child])
			break;
		else {
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;
		}
	}
	h->heap[parent] = temp;
	return item;
}

void printHeap(heapType* h) {
	int i;
	printf("Heap : ");
	for (i = 1; i <= h->heap_size; i++)
		printf("%d ", h->heap[i]);
}

int main() {
	int i, n, item;
	heapType* heap = createHeap();

	insertHeap(heap, 10);
	insertHeap(heap, 45);
	insertHeap(heap, 19);
	insertHeap(heap, 11);
	insertHeap(heap, 96);

	printHeap(heap);

	n = heap->heap_size;
	for (i = 1; i <= n; i++) {
		item = deleteHeap(heap);
		printf("\n delete : [%d] ", item);
	}

	getchar(); return 0;
}

/* 결과
Heap : 96 45 19 10 11
 delete : [96]
 delete : [45]
 delete : [19]
 delete : [11]
 delete : [10]
*/
