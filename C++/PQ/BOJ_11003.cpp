// Delete 함수에서 지울 노드를 최고 우선순위로 바꾸고 맨 위로 올린 후 pop해야한다.
// 이 문제는 음수 범위도 값에 포함되므로 min heap의 최고 우선순위를 INT_MAX로 해야함

#define MAX 5005000

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

typedef struct st1 {
	int value;
	int id;
}HEAP;

HEAP heap[MAX];
int heapIdx[MAX];
int hn;

void push(HEAP* heap, int& hn, int x, int id, int* heapIdx) {
	register HEAP tmp;

	heap[++hn].value = x;
	heap[hn].id = id;
	heapIdx[id] = hn;

	for (register int i = hn; i > 1; i /= 2) {
		if (heap[i].value > heap[i / 2].value) break;

		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;

		heapIdx[heap[i].id] = i;
		heapIdx[heap[i / 2].id] = i / 2;
	}
}

HEAP pop(HEAP* heap, int& hn, int* heapIdx) {
	register HEAP ret, tmp;

	ret = heap[1];
	heap[1] = heap[hn];
	heapIdx[heap[hn].id] = 1;
	heap[hn].value = INT_MAX;
	heap[hn--].id = INT_MAX;

	for (register int i = 1; i * 2 <= hn;) {
		if (heap[i].value < heap[i * 2].value && heap[i].value < heap[i * 2 + 1].value) break;

		else if (heap[i * 2].value < heap[i * 2 + 1].value) {
			tmp = heap[i * 2];
			heap[i * 2] = heap[i];
			heap[i] = tmp;
			heapIdx[heap[i * 2].id] = i * 2;
			heapIdx[heap[i].id] = i;

			i = i * 2;
		}

		else {
			tmp = heap[i * 2 + 1];
			heap[i * 2 + 1] = heap[i];
			heap[i] = tmp;
			heapIdx[heap[i * 2 + 1].id] = i * 2 + 1;
			heapIdx[heap[i].id] = i;

			i = i * 2 + 1;
		}
	}

	return ret;
}

void deleteData(HEAP* heap, int& hn, int id, int* heapIdx) {

	register HEAP tmp;

	int delhn = heapIdx[id];
	heap[delhn].value = INT_MIN;

	for (register int i = delhn; i > 1; i /= 2) {
		if (heap[i / 2].value < heap[i].value) break;
		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;

		heapIdx[heap[i].id] = i;
		heapIdx[heap[i / 2].id] = i / 2;
	}

	pop(heap, hn, heapIdx);
}

int n, l;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> l;

	vector<int> res;

	for (register int i = 1; i <= n; i++) {
		int input;
		cin >> input;
		push(heap, hn, input, i, heapIdx);
		if (i <= l) {
			res.push_back(heap[1].value);
		}
		else {
			deleteData(heap, hn, i - l, heapIdx);
			res.push_back(heap[1].value);
		}
	}

	for (register int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}

	return 0;
}