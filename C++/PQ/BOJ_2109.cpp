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
�켱���� ť �����ٸ� ����
-> deadline ���� �� ������� greedy Ž��
n^2�ð� �ҿ�, n�� 10�� �̻� �����϶� �ð��ʰ�

p,d �� ����� vector ���� -> nlogn
-> deadline ���� ������� pq�� ����
pq�� hn���� ��
hn�� ���� deadline���� ũ��, �ּҰ��� pop�Ѵ�.

heap�� ���� ������ p(���� �� �ִ� ��)�� ���� �������� pop�ϵ���
���� dl���� hn�� ũ��, ������ �ϳ��� ���� ���� ���� �ؾ���
(�����ð��� 1���� �۾��� �����ϹǷ�, ���� dl�� 3�̸� �ִ� 3�� �۾� ���డ��
dl�� 3�ε� hn�� 4�̸� hn���� ���� ������ ���� �ִ� ���� pop�ؾ���
*/