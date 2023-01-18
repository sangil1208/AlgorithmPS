#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define HMAX 200100

typedef struct st1 {
	int value;
	int id;
}HEAP;

int N, M;
HEAP heap[HMAX];
int hn;
int heapIdx[HMAX];

int isHighPri(HEAP a, HEAP b)
{
	if (a.value < b.value) return 1;
	else if (a.value == b.value && a.id < b.id) return 1;

	return 0;
}

void push(HEAP* heap, int& hn, int id, int value, int* heapIdx) {
	register HEAP tmp;

	heap[++hn].value = value;
	heap[hn].id = id;
	heapIdx[id] = hn;
	for (register int i = hn; i > 1; i /= 2)
	{
		if (isHighPri(heap[i / 2], heap[i])) break;

		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;

		heapIdx[heap[i].id] = i;
		heapIdx[heap[i / 2].id] = i / 2;
	}
};

HEAP pop(HEAP* heap, int& hn, int* heapIdx) {
	register HEAP tmp, ret;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn].value = 0x7fff0000;
	heap[hn--].id = 0x7fff0000;

	for (register int i = 1; i * 2 <= hn;)
	{
		if (isHighPri(heap[i], heap[i * 2]) && isHighPri(heap[i], heap[i * 2 + 1])) break;
		else if (isHighPri(heap[i * 2], heap[i * 2 + 1]))
		{
			tmp = heap[i * 2];
			heap[i * 2] = heap[i];
			heap[i] = tmp;

			heapIdx[heap[i].id] = i;
			heapIdx[heap[i * 2].id] = i * 2;

			i = i * 2;
		}
		else
		{
			tmp = heap[i * 2 + 1];
			heap[i * 2 + 1] = heap[i];
			heap[i] = tmp;

			heapIdx[heap[i].id] = i;
			heapIdx[heap[i * 2 + 1].id] = i * 2 + 1;

			i = i * 2 + 1;
		}
	}

	return ret;
};
void update(HEAP* heap, int& hn, int id, int value, int* heapIdx) {
	HEAP tmp;
	int updatehn = heapIdx[id];

	heap[updatehn].value = value;

	for (int i = updatehn; i > 1; i /= 2)
	{
		if (isHighPri(heap[i / 2], heap[i])) break;

		tmp = heap[i];
		heap[i] = heap[i / 2];
		heap[i / 2] = tmp;

		heapIdx[heap[i].id] = i;
		heapIdx[heap[i / 2].id] = i / 2;
	}

	for (int i = updatehn; i * 2 <= hn;)
	{
		if (isHighPri(heap[i], heap[i * 2]) && isHighPri(heap[i], heap[i * 2 + 1])) break;
		else if (isHighPri(heap[i * 2], heap[i * 2 + 1]))
		{
			tmp = heap[i * 2];
			heap[i * 2] = heap[i];
			heap[i] = tmp;

			heapIdx[heap[i].id] = i;
			heapIdx[heap[i * 2].id] = i * 2;

			i = i * 2;
		}
		else
		{
			tmp = heap[i * 2 + 1];
			heap[i * 2 + 1] = heap[i];
			heap[i] = tmp;

			heapIdx[heap[i].id] = i;
			heapIdx[heap[i * 2 + 1].id] = i * 2 + 1;

			i = i * 2 + 1;
		}
	}
};

int main(void) {

	scanf("%d", &N);

	for (register int i = 0; i < HMAX; i++) {
		heap[i].id = heap[i].value = 0x7fff0000;
	}

	for (register int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		push(heap, hn, i + 1, input, heapIdx);
	}

	scanf("%d", &M);

	for (register int i = 0; i < M; i++) {
		int cmd;

		scanf("%d", &cmd);

		if (cmd == 2)
			printf("%d\n", heap[1].id);
		else {
			int Ai, v;
			scanf("%d %d", &Ai, &v);
			update(heap, hn, Ai, v, heapIdx);
		}
	}

	return 0;
}