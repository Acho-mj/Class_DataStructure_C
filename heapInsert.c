#include <stdio.h>
#include <stdlib.h>

// heap�� ���� 1���� �迭�� heap ������ ������ ����ü�� ��� ����
typedef struct {
	int heap[100];
	int heap_size;
}heapType;

heapType* createHeap() {
	heapType* h = (heapType*)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}

// heap�� item�� �����ϴ� ����
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

	getchar(); return 0;
}

