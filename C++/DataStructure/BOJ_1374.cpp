#include <iostream>
#include <vector>
#include <algorithm>

#define HMAX 100100

using namespace std;

int heap[HMAX];
int hn;
int N;

int isHighPri(int a, int b) {
	if (a < b) return 1;
	return 0;
}

void push(int* heap, int& hn, int x) {
	register int tmp;

	heap[++hn] = x;

	for (register int i = hn; i > 1; i /= 2) {
		if (isHighPri(heap[i / 2], heap[i])) break;

		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;
	}
}

int pop(int* heap, int& hn) {
	register int ret, tmp;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn--] = 0x7fff0000;

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

int main(void) {

	cin >> N;

	vector<pair<int, int>> v;

	for (register int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v.push_back(make_pair(b, c));
	}

	sort(v.begin(), v.end());

	push(heap, hn, v[0].second);

	for (register int i = 1; i < N; i++) {
		push(heap, hn, v[i].second);
		if (v[i].first >= heap[1])
			pop(heap, hn);
	}

	cout << hn;

	return 0;

}