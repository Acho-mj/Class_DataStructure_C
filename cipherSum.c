#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int cipherSum(int n) {
	if (n < 10) {
		return n;
	}else {
		return n % 10 + cipherSum(n / 10);
	}
}

int main() {
	int i;
	printf("\n i�� �Է����ּ��� : ");
	scanf("%d", &i);
	printf("%d�� �� �ڸ����� ���� %d�Դϴ�.\n", i, cipherSum(i));
}