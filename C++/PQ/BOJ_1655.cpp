#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int N;

int minHeap[100100];
int minHn;

int maxHeap[100100];
int maxHn;

int maxPop(int* heap, int& hn) {
	register int tmp, ret;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn--] = -10001;

	for (register int i = 1; i * 2 <= hn;) {

		if (heap[i] > heap[i * 2] && heap[i] > heap[i * 2 + 1]) break;

		else if (heap[i * 2] > heap[i * 2 + 1]) {
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

void maxPush(int* heap, int& hn, int x) {
	register int tmp;

	heap[++hn] = x;

	for (register int i = hn; i > 1; i /= 2) {
		if (heap[i / 2] > heap[i]) break;

		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;
	}
}

int minPop(int* heap, int& hn) {
	register int tmp, ret;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn--] = 10001;

	for (register int i = 1; i * 2 <= hn;) {

		if (heap[i] < heap[i * 2] && heap[i] < heap[i * 2 + 1]) break;

		else if (heap[i * 2] < heap[i * 2 + 1]) {
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

void minPush(int* heap, int& hn, int x) {
	register int tmp;

	heap[++hn] = x;

	for (register int i = hn; i > 1; i /= 2) {
		if (heap[i / 2] < heap[i]) break;

		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;
	}
}

int main(void) {

	int a;

	scanf("%d", &N);

	scanf("%d", &a);
	minPush(minHeap, minHn, a);
	printf("%d\n", a);

	for (register int i = 1; i < N; i++) {

		scanf("%d", &a);

		if (minHn == maxHn) {

			if (a < maxHeap[1]) {
				//짝수일때 하나 더 넣어서 홀수 되었으니 minHeap에서 출력
				minPush(minHeap, minHn, maxPop(maxHeap, maxHn));
				maxPush(maxHeap, maxHn, a);
				printf("%d\n", minHeap[1]);
			}
			else {
				minPush(minHeap, minHn, a);
				printf("%d\n", minHeap[1]);
			}

		}

		else {
			// 현재 홀수개이므로 하나 넣으면 짝수, min max 중 더 작은 max에서 pop
			if (minHeap[1] < a) {
				maxPush(maxHeap, maxHn, minPop(minHeap, minHn));
				minPush(minHeap, minHn, a);
				printf("%d\n", maxHeap[1]);
			}
			else {
				maxPush(maxHeap, maxHn, a);
				printf("%d\n", maxHeap[1]);
			}
		}
	}

	return 0;
}