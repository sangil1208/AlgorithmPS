#define MAX 200200

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

int n;

typedef struct st1 {
	ll d;
	ll p;
}HEAP;

HEAP heap[MAX];
int hn;

int isHighPri(HEAP a, HEAP b) {
	if (a.p < b.p) return 1;
	return 0;
}

void push(HEAP* heap, int& hn, ll d, ll p) {
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
	heap[hn].d = LLONG_MAX;
	heap[hn--].p = LLONG_MAX;

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

	cin >> n;

	vector<pair<int, int>> v;

	ll res = 0;

	for (register int i = 0; i < n; i++) {
		ll d, p;
		cin >> d >> p;
		v.emplace_back(d, p);
	}

	sort(v.begin(), v.end());

	for (auto i : v) {
		push(heap, hn, i.first, i.second);
		if (hn > i.first)
			pop(heap, hn);
	}

	while (hn) {
		HEAP tmp = pop(heap, hn);
		res += tmp.p;
	}

	cout << res;

	return 0;

}

/*
기존 로직은 순회강연, 과제 문제와 동일한 방식
-> 이 방식으로 하면 hn에 대해 tmp.d만큼 이중반복
둘다 최대값이 n이므로 n^2알고리즘이 됨. 다른방법 생각

https://hello70825.tistory.com/295
가장 작은 점수를 버리는 방식
*/