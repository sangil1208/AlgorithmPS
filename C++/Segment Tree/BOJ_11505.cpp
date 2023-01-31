// ���׸�Ʈ Ʈ���� ũ��� n*4 �� �ؾ� �����ϴ�.
#define MAX 4004000

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void init(vector<long long>& a, long long* tree, int node, int start, int end) {
	if (start == end)
		tree[node] = a[start] % 1000000007;
	else {
		init(a, tree, node * 2, start, (start + end) / 2);
		init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
	}
}

// start-end ���� Ʈ������ left, right������ �� ���ϱ�
long long query(long long* tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 1;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	long long l = query(tree, node * 2, start, (start + end) / 2, left, right) % 1000000007;
	long long r = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right) % 1000000007;
	return l * r % 1000000007;
}

void update(vector<long long>& a, long long* tree, int node, int start, int end, int index, long long val) {
	if (index < start || index > end) {
		return;
	}
	if (start == end) {
		a[index] = val;
		tree[node] = val % 1000000007;
		return;
	}

	update(a, tree, node * 2, start, (start + end) / 2, index, val);
	update(a, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
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
			cout << query(tree, 1, 0, n - 1, b - 1, c - 1) % 1000000007 << '\n';
		}
	}

	return 0;
}