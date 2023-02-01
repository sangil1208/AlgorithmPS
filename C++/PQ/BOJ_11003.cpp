// Delete �Լ����� ���� ��带 �ְ� �켱������ �ٲٰ� �� ���� �ø� �� pop�ؾ��Ѵ�.
// �� ������ ���� ������ ���� ���ԵǹǷ� min heap�� �ְ� �켱������ INT_MAX�� �ؾ���

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