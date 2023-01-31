// 세그먼트 트리의 크기는 n*4 로 해야 안전하다.
#define MAX 400400

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void init_min(vector<long long>& a, long long* tree, int node, int start, int end) {
	if (start == end)
		tree[node] = a[start];
	else {
		init_min(a, tree, node * 2, start, (start + end) / 2);
		init_min(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}

// start-end 구간 트리에서 left, right구간의 합 구하기
long long query_min(long long* tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return LLONG_MAX;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	long long l = query_min(tree, node * 2, start, (start + end) / 2, left, right);
	long long r = query_min(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return min(l, r);
}

void init_max(vector<long long>& a, long long* tree, int node, int start, int end) {
	if (start == end)
		tree[node] = a[start];
	else {
		init_max(a, tree, node * 2, start, (start + end) / 2);
		init_max(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	}
}

// start-end 구간 트리에서 left, right구간의 합 구하기
long long query_max(long long* tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return LLONG_MIN;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	long long l = query_max(tree, node * 2, start, (start + end) / 2, left, right);
	long long r = query_max(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return max(l, r);
}


long long n, m;
long long tree_max[400400];
long long tree_min[400400];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	vector<long long> v;

	for (register int i = 0; i < n; i++) {
		long long input;
		cin >> input;
		v.push_back(input);
	}

	init_max(v, tree_max, 1, 0, n - 1);
	init_min(v, tree_min, 1, 0, n - 1);


	for (register int i = 0; i < m; i++) {
		long long a, b;
		cin >> a >> b;

		cout << query_min(tree_min, 1, 0, n - 1, a - 1, b - 1) << ' ';
		cout << query_max(tree_max, 1, 0, n - 1, a - 1, b - 1) << '\n';
	}

	return 0;
}