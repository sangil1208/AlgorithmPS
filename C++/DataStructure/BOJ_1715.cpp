/*
우선순위 큐 문제
두 숫자를 pop후 합산한 값을 다시 push한다.
edge case는 최소 비교횟수 = 0회 (입력 숫자가 하나일때)
*/


#define _CRT_SECURE_NO_WARNINGS
#define MAX 100100

#include <stdio.h>

int N;

int heap[MAX];
int hn;

void heapPush(int* heap, int& hn, int x) {
	heap[++hn] = x;

	for (register int i = hn; i > 1; i /= 2) {

		if (heap[i] >= heap[i / 2]) break;

		else {
			int tmp;
			tmp = heap[i / 2];
			heap[i / 2] = heap[i];
			heap[i] = tmp;
		}
	}
}

int heapPop(int* heap, int& hn) {
	int ret, tmp;
	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn--] = 0x7fff0000;

	for (register int i = 1; i * 2 <= hn;) {

		if ((heap[i] < heap[i * 2]) && (heap[i] < heap[i * 2 + 1])) break;

		else {
			if (heap[i * 2] < heap[i * 2 + 1]) {
				tmp = heap[i * 2];
				heap[i * 2] = heap[i];
				heap[i] = tmp;

				i = i * 2;
			}
			else {
				tmp = heap[i * 2 + 1];
				heap[i * 2 + 1] = heap[i];
				heap[i] = tmp;

				i = i * 2 + 1;
			}
		}
	}

	return ret;
}

int main(void) {
	scanf("%d", &N);

	for (register int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);

		heapPush(heap, hn, input);
	}

	int result = 0;

	int pair = 0;
	int pairSum = 0;

	while (hn) {
		int a;
		pair++;

		a = heapPop(heap, hn);
		result += a;
		pairSum += a;

		if (pair == 2) {
			if (hn)
				heapPush(heap, hn, pairSum);
			pairSum = 0;
			pair = 0;
		}
	}

	if (N == 1)
		printf("%d", 0);
	else
		printf("%d", result);

	return 0;
}