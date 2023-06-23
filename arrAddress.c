#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// A[10][10]의 주소값을 10진수로
int main() {
	int A[100][1000];
	printf("%d", 4 * (&A[10][10] - &A[0][0]));
}