#include <iostream>
#include <vector>
#include <algorithm>

#define NMAX 300300

using namespace std;

int n, m;

typedef struct st2 {
	int m;
	int v;
}DATA;

DATA heap[NMAX];
int hn;

int isHighPri(DATA a, DATA b) {
	if (a.v > b.v) return 1;
	if (a.v == b.v && a.m < b.m) return 1;
	return 0;
}

void push(DATA* heap, int& hn, int m, int v) {

	register DATA tmp;

	heap[++hn].m = m;
	heap[hn].v = v;

	for (register int i = hn; i > 1; i /= 2) {
		if (isHighPri(heap[i / 2], heap[i])) break;

		else {
			tmp = heap[i / 2];
			heap[i / 2] = heap[i];
			heap[i] = tmp;
		}
	}
}

DATA pop(DATA* heap, int& hn) {
	register DATA tmp, ret;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn].m = 0x7fff0000;
	heap[hn--].v = 0x80000000;

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

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;

	cin >> n >> k;

	vector <pair<int, int>> jew;

	for (register int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		jew.push_back(make_pair(m, v));
	}

	sort(jew.begin(), jew.end());

	vector<int> bags;

	for (register int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bags.push_back(c);
	}

	sort(bags.begin(), bags.end());

	long long result = 0;
	int idx = 0;

	for (register int i = 0; i < bags.size(); i++) {

		while (idx < n && jew[idx].first <= bags[i]) {
			push(heap, hn, jew[idx].first, jew[idx].second);
			idx++;
		}

		if (hn > 0)
			result += pop(heap, hn).v;
	}

	cout << result;

	return 0;
}