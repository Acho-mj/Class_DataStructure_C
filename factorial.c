#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

long int fact(int n) {
	if (n == 1)
		return 1;
	else
		return n * fact(n - 1);
}

int main() {
	int n;
	printf("n을 입력하세요 : ");
	scanf("%d", &n);
	printf("%d ! = %d", n, fact(n));
}