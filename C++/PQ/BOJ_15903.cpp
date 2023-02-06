#define MAX 1100

#include <iostream>

using namespace std;

long long heap[MAX];
int hn;

void push(long long* heap, int& hn, long long x) {
	register long long tmp;

	heap[++hn] = x;

	for (register int i = hn; i > 1; i /= 2) {
		if (heap[i / 2] < heap[i]) break;
		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;
	}
}

long long pop(long long* heap, int& hn) {
	register long long ret, tmp;

	ret = heap[1];
	heap[1] = heap[hn--];

	for (register int i = 1; i * 2 <= hn;) {
		if (heap[i] < heap[i * 2] && heap[i] < heap[i * 2 + 1]) break;
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

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (register int i = 0; i < n; i++) {
		int input;
		cin >> input;
		push(heap, hn, input);
	}

	for (register int i = 0; i < m; i++) {
		long long a = pop(heap, hn);
		long long b = pop(heap, hn);
		push(heap, hn, a + b);
		push(heap, hn, a + b);
	}

	long long res = 0;

	for (register int i = 1; i <= hn; i++) {
		res += heap[i];
	}

	cout << res;

	return 0;
}