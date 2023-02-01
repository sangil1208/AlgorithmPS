/*
이중 우선순위 큐 문제, tc가 여러개이므로 새 tc마다 초기화 필요.
heapNumber 포인터로 heap 원소 관리하므로, heapNumber 초기화로 tc 초기화 가능
각 함수에서 heapNumber 범위 내에서만 비교 및 교환 발생하도록 구현하였으니
hn초기화만으로 가능
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX 10000

#include <stdio.h>

int T;

int maxHeap[MAX];
int maxHn;

int minHeap[MAX];
int minHn;

int maxPop(int* maxHeap, int& maxHn) {
	register int ret, tmp;
	ret = maxHeap[1];
	maxHeap[1] = maxHeap[maxHn];
	maxHeap[maxHn--] = 0x80000000;

	for (register int i = 1; i * 2 <= maxHn;) {
		if ((maxHeap[i] > maxHeap[i * 2]) && (maxHeap[i] > maxHeap[i * 2 + 1])) break;
		else if (maxHeap[i * 2] > maxHeap[i * 2 + 1]) {
			tmp = maxHeap[i * 2];
			maxHeap[i * 2] = maxHeap[i];
			maxHeap[i] = tmp;

			i = i * 2;
		}
		else {
			tmp = maxHeap[i * 2 + 1];
			maxHeap[i * 2 + 1] = maxHeap[i];
			maxHeap[i] = tmp;

			i = i * 2 + 1;
		}
	}

	return ret;
}

void maxPush(int* maxHeap, int& maxHn, int x) {

	register int tmp;

	maxHeap[++maxHn] = x;

	for (register int i = maxHn; i > 1; i /= 2) {
		if (maxHeap[i] <= maxHeap[i / 2]) break;
		else {
			tmp = maxHeap[i / 2];
			maxHeap[i / 2] = maxHeap[i];
			maxHeap[i] = tmp;
		}
	}
}


int minPop(int* minHeap, int& minHn) {
	register int ret, tmp;
	ret = minHeap[1];
	minHeap[1] = minHeap[minHn];
	minHeap[minHn--] = 0x7fff0000;

	for (register int i = 1; i * 2 <= minHn;) {
		if ((minHeap[i] < minHeap[i * 2]) && (minHeap[i] < minHeap[i * 2 + 1])) break;
		else if (minHeap[i * 2] < minHeap[i * 2 + 1]) {
			tmp = minHeap[i * 2];
			minHeap[i * 2] = minHeap[i];
			minHeap[i] = tmp;

			i = i * 2;
		}
		else {
			tmp = minHeap[i * 2 + 1];
			minHeap[i * 2 + 1] = minHeap[i];
			minHeap[i] = tmp;

			i = i * 2 + 1;
		}
	}

	return ret;
}

void minPush(int* minHeap, int& minHn, int x) {

	register int tmp;

	minHeap[++minHn] = x;

	for (register int i = minHn; i > 1; i /= 2) {
		if (minHeap[i] >= minHeap[i / 2]) break;
		else {
			tmp = minHeap[i / 2];
			minHeap[i / 2] = minHeap[i];
			minHeap[i] = tmp;
		}
	}
}
int main(void) {

	scanf("%d", &T);

	for (register int i = 0; i < T; i++) {
		maxHn = minHn = 0;
		register int n;
		scanf("%d", &n);

		printf("%d\n", n / 2 + 1);

		register int input;
		scanf("%d", &input);

		minPush(minHeap, minHn, input);
		printf("%d ", minHeap[1]);

		for (register int i = 1; i < n; i++) {

			scanf("%d", &input);

			if (maxHn == minHn) {
				if (maxHeap[1] > input) {
					minPush(minHeap, minHn, maxPop(maxHeap, maxHn));
					maxPush(maxHeap, maxHn, input);
				}
				else {
					minPush(minHeap, minHn, input);
				}
				printf("%d ", minHeap[1]);
			}
			else {
				if (minHeap[1] < input) {
					maxPush(maxHeap, maxHn, minPop(minHeap, minHn));
					minPush(minHeap, minHn, input);
				}
				else {
					maxPush(maxHeap, maxHn, input);
				}
			}
		}

		printf("\n");


	}

	return 0;
}
