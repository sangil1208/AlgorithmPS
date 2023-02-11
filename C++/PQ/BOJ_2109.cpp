#define MAX 11000
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef struct st1 {
	int d;
	int p;
}HEAP;

HEAP heap[MAX];
int hn;

int isHighPri(HEAP a, HEAP b) {
	if (a.p < b.p) return 1;
	return 0;
}

void push(HEAP* heap, int& hn, int d, int p) {

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

	register HEAP ret, tmp;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn].d = INT_MAX;
	heap[hn--].p = INT_MAX;

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

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector<pair<int, int>> v;

	for (register int i = 0; i < n; i++) {
		int p, d;
		cin >> p >> d;
		v.emplace_back(d, p);
	}

	sort(v.begin(), v.end());

	for (register int i = 0; i < n; i++) {
		push(heap, hn, v[i].first, v[i].second);
		if (hn > v[i].first)
			pop(heap, hn);
	}

	int res = 0;

	while (hn) {
		res += pop(heap, hn).p;
	}

	cout << res;

	return 0;
}

/*
우선순위 큐 스케줄링 문제
-> deadline 가장 먼 순서대로 greedy 탐색
n^2시간 소요, n이 10만 이상 범위일때 시간초과

p,d 값 저장된 vector 정렬 -> nlogn
-> deadline 작은 순서대로 pq에 삽입
pq의 hn으로 비교
hn이 현재 deadline보다 크면, 최소값을 pop한다.

heap의 정렬 기준은 p(얻을 수 있는 값)이 가장 작은것을 pop하도록
현재 dl보다 hn이 크면, 힙에서 하나를 빼서 값을 같게 해야함
(단위시간당 1개의 작업을 수행하므로, 만약 dl이 3이면 최대 3개 작업 수행가능
dl이 3인데 hn이 4이면 hn에서 가장 보상을 적게 주는 값을 pop해야함
*/