#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int hand(int n) {
	if (n == 1)
		return 0;
	else
		return hand(n - 1) + n - 1;
}

int main() {
	int k;
	printf("\nk�� �Է����ּ��� : ");
	scanf("%d", &k);
	printf("%d���� �Ǽ��ϴ� ��� = %d", k, hand(k));
}