// heap�� sibling�� ���� �ʿ䰡 ����. �ڽİ� �θ� �켱���� ���踸 �����Ǹ� ok

// heap rebalancing? -> pop���Ŀ� �ʿ�
// �켱���� ���� ���� (heap�� ù ��° ����) pop 
// -> ���� ù ��° ���� ���� ������ ���� ������ ����
// ������ ���ҿ��� �켱������ ���� ���� �� ����? -> 
// �̰� ���ϰ� 0 ����Ǿ� ������ �ڽ� ���� ��� ���ϴٰ� 0���� �ٲ� �� ����. ���� ������ ó�� ����.
// ���� �ڽĳ�� �ΰ��� ���� �ڽ��� �켱���� ���� ���ٸ� ����. �ƴ϶�� ����

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int heap[101000];
int hn; // �ʱⰪ 0, heap�� ������� Ȯ���ϱ� ���� ���

int abs(int x) {
	return (x > 0) ? x : -x;
}

int isMin(int a, int b) {
	if (abs(a) < abs(b)) return 1;
	if (abs(a) == abs(b) && a < b) return 1;

	return 0;
}

int pop(int* heap, int& hn) {

	// register�� �Լ� �� ��������, �ݺ����� ���
	register int tmp, ret;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn--] = 0x7fff0000; // int �ִ밪

	for (register int i = 1; i * 2 <= hn;) {

		if (isMin(heap[i], heap[i * 2]) && isMin(heap[i], heap[i * 2 + 1])) break; // ���뷱�� x

		else if (isMin(heap[i * 2], heap[i * 2 + 1])) { // ���� �ڽ��� �� ����(�켱���� �� ������)
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

void push(int* heap, int& hn, int x) {
	register int tmp;

	heap[++hn] = x;

	for (register int i = hn; i > 1; i /= 2) {
		if (isMin(heap[i / 2], heap[i])) break;

		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;
	}
}

int main(void) {
	int N;

	scanf("%d", &N);

	for (register int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);

		if (a == 0) {
			if (hn == 0)
				printf("%d\n", 0);
			else
				printf("%d\n", pop(heap, hn));
		}
		else {
			push(heap, hn, a);
		}
	}
	return 0;
}