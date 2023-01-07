#include <stdio.h>

typedef struct st {
	int value;
	int id;
}HEAP;

HEAP heap[16];
int heapIdx[16];
int hn;

int isMin(HEAP a, HEAP b) {
	if (a.value < b.value) return 1;
	else if (a.value == b.value && a.id < b.id) return 1;

	return 0;
}

HEAP pop(HEAP* heap, int& hn, int* heapIdx) {
	register HEAP tmp, ret;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn].id = 0x7fff0000;
	heap[hn--].value = 0x7fff0000;

	for (register int i = 1; i * 2 <= hn;) {
		if (isMin(heap[i], heap[i * 2]) && isMin(heap[i], heap[i * 2 + 1])) break;

		else if (isMin(heap[i * 2], heap[i * 2 + 1])) {
			tmp = heap[i * 2];
			heap[i * 2] = heap[i];
			heap[i] = tmp;

			heapIdx[heap[i].id] = i;
			heapIdx[heap[i * 2].id] = i * 2;

			i = i * 2;
		}

		else {
			tmp = heap[i * 2 + 1];
			heap[i * 2 + 1] = heap[i];
			heap[i] = tmp;

			heapIdx[heap[i].id] = i;
			heapIdx[heap[i * 2 + 1].id] = i * 2 + 1;

			i = i * 2 + 1;
		}
	}

	return ret;
}

void push(HEAP* heap, int& hn, int value, int id, int* heapIdx) {
	register HEAP tmp;

	heap[++hn].id = id;
	heap[hn].value = value;
	heapIdx[id] = hn;

	for (register int i = hn; i > 1; i /= 2) {
		if (isMin(heap[i / 2], heap[i])) break;

		else {
			tmp = heap[i / 2];
			heap[i / 2] = heap[i];
			heap[i] = tmp;

			heapIdx[heap[i / 2].id] = i / 2;
			heapIdx[heap[i].id] = i;
			// IDÀÇ heap index
		}
	}
}


int deleteId(HEAP* heap, int& hn, int id, int* heapIdx) {
	HEAP tmp;
	int ret;
	int delhn = heapIdx[id];

	ret = heap[delhn].value;
	heap[delhn].value = -1;

	for (int i = delhn; i > 1; i /= 2) {
		if (isMin(heap[i / 2], heap[i])) break;

		tmp = heap[i];
		heap[i] = heap[i / 2];
		heap[i / 2] = tmp;

		heapIdx[heap[i].id] = i;
		heapIdx[heap[i / 2].id] = i / 2;
	}

	pop(heap, hn, heapIdx);

	return ret;
}