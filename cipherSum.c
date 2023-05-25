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
	printf("\n i을 입력해주세요 : ");
	scanf("%d", &i);
	printf("%d의 각 자리수의 합은 %d입니다.\n", i, cipherSum(i));
}