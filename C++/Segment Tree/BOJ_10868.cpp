#define MAX 400400

#include <iostream>
#include <vector>
#include <climits>

typedef long long int ll;
using namespace std;

void init(vector<ll>& a, ll* tree, int node, int start, int end) {
	if (start == end) {
		tree[node] = a[start];
	}
	else {
		init(a, tree, node * 2, start, (start + end) / 2);
		init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}

ll query(ll* tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return LLONG_MAX;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	ll lmin = query(tree, node * 2, start, (start + end) / 2, left, right);
	ll rmin = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);

	return min(lmin, rmin);
}

int n, m;

ll tree[MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	vector<ll> a;

	for (register int i = 0; i < n; i++) {
		ll input;
		cin >> input;
		a.push_back(input);
	}

	init(a, tree, 1, 0, n - 1);

	for (register int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		cout << query(tree, 1, 0, n - 1, l - 1, r - 1) << '\n';
	}

	return 0;
}