#define NMAX 40000

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int heap[NMAX];
int hn;

void push(int* heap, int& hn, int x) {
	register int tmp;

	heap[++hn] = x;

	for (register int i = hn; i > 1; i /= 2) {
		if (heap[i / 2] < heap[i]) break;
		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;
	}
}

int pop(int* heap, int& hn) {
	register int ret, tmp;
	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn--] = INT_MAX;

	for (register int i = 1; i * 2 <= hn;) {
		if ((heap[i] < heap[i * 2]) && (heap[i] < heap[i * 2 + 1])) break;
		else if (heap[i * 2] < heap[i * 2 + 1]) {
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

int n, m;
vector<int> v[NMAX];
int indeg[NMAX];

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (register int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		indeg[b] += 1;
	}

	for (register int i = 1; i <= n; i++) {
		if (indeg[i] == 0)
			push(heap, hn, i);
	}

	while (hn) {
		int pd = pop(heap, hn);
		cout << pd << ' ';
		for (register int i = 0; i < v[pd].size(); i++) {
			indeg[v[pd][i]] -= 1;
			if (indeg[v[pd][i]] == 0)
				push(heap, hn, v[pd][i]);
		}
	}

	return 0;
}