#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int N;

int heap[1550 * 1550];
int hn;

int isHighPri(int a, int b) {
	if (a > b) return 1;
	return 0;
}

void push(int* heap, int& hn, int x) {
	register int tmp;

	heap[++hn] = x;

	for (register int i = hn; i > 1; i /= 2) {
		if (isHighPri(heap[i / 2], heap[i])) break;

		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;
	}
}

int pop(int* heap, int& hn) {
	register int ret, tmp;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn--] = 0x80000000;

	for (register int i = 1; i * 2 <= hn;) {
		if (isHighPri(heap[i], heap[i * 2]) && isHighPri(heap[i], heap[i * 2 + 1])) break;
		else if (isHighPri(heap[i * 2], heap[i * 2 + 1])) {
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

	return ret;
}

int main(void) {

	scanf("%d", &N);

	for (register int i = 0; i < N * N; i++) {
		int input;
		scanf("%d", &input);

		push(heap, hn, input);
	}

	for (register int i = 0; i < N; i++) {
		int res;
		res = pop(heap, hn);
		if (i == N - 1)
			printf("%d", res);
	}

	return 0;
}
