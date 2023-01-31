// 세그먼트 트리의 크기는 n*4 로 해야 안전하다.
#define MAX 4001000

#include <iostream>
#include <vector>

using namespace std;

void init(vector<long long>& a, long long* tree, int node, int start, int end) {
	if (start == end)
		tree[node] = a[start];
	else {
		init(a, tree, node * 2, start, (start + end) / 2);
		init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

// start-end 구간 트리에서 left, right구간의 합 구하기
long long query(long long* tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	long long lsum = query(tree, node * 2, start, (start + end) / 2, left, right);
	long long rsum = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return lsum + rsum;
}

void update(vector<long long>& a, long long* tree, int node, int start, int end, int index, long long val) {
	if (index < start || index > end) {
		return;
	}
	if (start == end) {
		a[index] = val;
		tree[node] = val;
		return;
	}

	update(a, tree, node * 2, start, (start + end) / 2, index, val);
	update(a, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long n, m, k;
long long tree[MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	vector<long long> v;

	for (register int i = 0; i < n; i++) {
		long long input;
		cin >> input;
		v.push_back(input);
	}

	init(v, tree, 1, 0, n - 1);

	for (register int i = 0; i < m + k; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(v, tree, 1, 0, n - 1, b - 1, c);
		}
		else {
			cout << query(tree, 1, 0, n - 1, b - 1, c - 1) << '\n';
		}
	}

	return 0;
}