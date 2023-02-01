#define MAX 1100

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef struct st1 {
	int d;
	int w;
}HEAP;

HEAP heap[MAX];
int hn;

int isHighPri(HEAP a, HEAP b) {
	if (a.w > b.w)
		return 1;
	return 0;
}

void push(HEAP* heap, int& hn, int d, int w) {
	register HEAP tmp;

	heap[++hn].d = d;
	heap[hn].w = w;

	for (register int i = hn; i > 1; i /= 2) {
		if (isHighPri(heap[i / 2], heap[i])) break;
		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;
	}
}

HEAP pop(HEAP* heap, int& hn) {
	register HEAP tmp, ret;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn].d = INT_MIN;
	heap[hn--].w = INT_MIN;

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

int n;

int flag[MAX];

int main(void) {
	cin >> n;

	vector<pair<int, int>> v;
	int res = 0;

	for (register int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		push(heap, hn, a, b);
	}

	for (register int i = 1; i <= n; i++) {
		HEAP tmp = pop(heap, hn);
		int day = tmp.d;

		for (register int i = day; i >= 1; i--) {
			if (flag[i] != 1) {
				res += tmp.w;
				flag[i] = 1;
				break;
			}
		}
	}

	cout << res;

	return 0;
}