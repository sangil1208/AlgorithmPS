#define MAX 11000
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;

typedef struct st1 {
	int p;
	int d;
}HEAP;

HEAP heap[MAX];
int hn;

int isHighPri(HEAP a, HEAP b) {
	if (a.p > b.p) return 1;
	if (a.p == b.p && a.d > b.d) return 1;
	return 0;
}

void push(HEAP* heap, int& hn, int p, int d) {
	register HEAP tmp;

	heap[++hn].p = p;
	heap[hn].d = d;

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
	heap[hn--].p = INT_MIN;

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

int visited[MAX];

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int res = 0;

	for (register int i = 0; i < n; i++) {
		int p, d;
		cin >> p >> d;
		push(heap, hn, p, d);
	}

	while (hn) {

		HEAP tmp = pop(heap, hn);

		for (register int i = tmp.d; i >= 1; i--) {
			if (visited[i] == 0) {
				visited[i] = 1;
				res += tmp.p;
				break;
			}
		}
	}

	cout << res;


	return 0;
}