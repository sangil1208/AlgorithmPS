#define MAX 100100

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef struct st1 {
	int start;
	int end;
}HEAP;

HEAP heap[MAX];
int hn;

int isHighPri(HEAP a, HEAP b) {
	if (a.end < b.end)
		return 1;
	return 0;
}

void push(HEAP* heap, int& hn, int start, int end) {
	register HEAP tmp;

	heap[++hn].start = start;
	heap[hn].end = end;

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
	heap[hn].start = INT_MAX;
	heap[hn--].end = INT_MAX;

	for (register int i = 1; i * 2 <= hn;) {
		if (isHighPri(heap[i], heap[i * 2]) && isHighPri(heap[i], heap[i * 2 + 1]))
			break;
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

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> v;

	cin >> n;

	for (register int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.emplace_back(a, b);
	}

	sort(v.begin(), v.end());

	push(heap, hn, v[0].first, v[0].second);

	for (register int i = 1; i < n; i++) {
		if (v[i].first < heap[1].end)
			push(heap, hn, v[i].first, v[i].second);
		else {
			push(heap, hn, v[i].first, v[i].second);
			pop(heap, hn);
		}
	}

	cout << hn;

	return 0;
}