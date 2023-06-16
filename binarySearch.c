#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef int element;
int cnt = 0;	// 이진 검색의 연산 횟수

void binarySearch(element a[], int begin, int end, element key) {
	int middle;
	cnt++;						// 이진 검색 연산 횟수 1 증가
	if (begin == end) {			// 검색 범위가 한 개인 경우
		if (key == a[begin]) printf("%3d번째에 검색 성공 \n", cnt);
		else printf("%3d번째에 검색 실패! \n", cnt);
		return;
	}

	middle = (begin + end) / 2;  // 검색 범위가 이진 분할되는 기준 위치 설정
	if (key == a[middle])  printf("%3d번째에 검색 성공 \n", cnt);
	else if (key < a[middle] && (middle - 1 >= begin))
		binarySearch(a, begin, middle - 1, key);
	else if (key > a[middle] && (middle + 1 <= end))
		binarySearch(a, middle + 1, end, key);
	else printf("%3d번째에 검색 실패 \n", cnt);
}

int main(void) {
	element a[] = { 1, 2, 8, 9, 11, 19, 29 }, key;
	int i, size = sizeof(a) / sizeof(a[0]); //배열 원소의 개수
	char more;
	extern int cnt;

	printf("\n\t<< 검색 대상 자료 >>\n");
	for (i = 0; i < size; i++) printf("%5d", a[i]); puts("");
	do {
		cnt = 0;
		printf("\n\n검색할 키를 입력하세요 : ");  scanf("%d", &key);
		printf("\n%3d를 검색 ->> ", key);
		binarySearch(a, 0, size - 1, key);

		printf("\n\n검색을 계속하려면 y를 누르세요>> "); scanf("  %c", &more);
	} while (more == 'y');

	getchar();  return 0;
}