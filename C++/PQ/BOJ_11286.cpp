// heap은 sibling과 비교할 필요가 없다. 자식과 부모간 우선순위 관계만 유지되면 ok

// heap rebalancing? -> pop이후에 필요
// 우선순위 가장 높은 (heap의 첫 번째 원소) pop 
// -> 이후 첫 번째 원소 값을 마지막 원소 값으로 변경
// 마지막 원소에는 우선순위가 가장 낮은 값 저장? -> 
// 이거 안하고 0 저장되어 있으면 자식 노드와 모두 비교하다가 0과도 바뀔 수 있음. 없는 값으로 처리 위해.
// 이후 자식노드 두개와 비교해 자신이 우선순위 가장 높다면 유지. 아니라면 변경

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int heap[101000];
int hn; // 초기값 0, heap이 비었는지 확인하기 위해 사용

int abs(int x) {
	return (x > 0) ? x : -x;
}

int isMin(int a, int b) {
	if (abs(a) < abs(b)) return 1;
	if (abs(a) == abs(b) && a < b) return 1;

	return 0;
}

int pop(int* heap, int& hn) {

	// register는 함수 내 지역변수, 반복문에 사용
	register int tmp, ret;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn--] = 0x7fff0000; // int 최대값

	for (register int i = 1; i * 2 <= hn;) {

		if (isMin(heap[i], heap[i * 2]) && isMin(heap[i], heap[i * 2 + 1])) break; // 리밸런싱 x

		else if (isMin(heap[i * 2], heap[i * 2 + 1])) { // 왼쪽 자식이 더 작음(우선순위 더 높으면)
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