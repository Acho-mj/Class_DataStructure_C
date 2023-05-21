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
	printf("\nk을 입력해주세요 : ");
	scanf("%d", &k);
	printf("%d명이 악수하는 경우 = %d", k, hand(k));
}