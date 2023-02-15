#define MAX 4004000

#include <iostream>
#include <vector>

typedef long long int ll;

using namespace std;

vector<ll> arr;
ll tree[MAX];

void init(vector<ll>& arr, ll* tree, int node, int start, int end) {
	if (start == end)
		tree[node] = arr[start];
	else {
		init(arr, tree, node * 2, start, (start + end) / 2);
		init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

ll query(ll* tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	ll lsum = query(tree, node * 2, start, (start + end) / 2, left, right);
	ll rsum = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return lsum + rsum;
}

void update(vector<ll>& arr, ll* tree, int node, int start, int end, int index, ll val) {
	if (index < start || index > end)
		return;
	if (start == end) {
		arr[index] = val;
		tree[node] = val;
		return;
	}
	update(arr, tree, node * 2, start, (start + end) / 2, index, val);
	update(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}


int n, m;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (register int i = 0; i < n; i++) {
		arr.push_back(0);
	}

	for (register int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0) {
			if (b < c)
				cout << query(tree, 1, 0, n - 1, b - 1, c - 1) << '\n';
			else
				cout << query(tree, 1, 0, n - 1, c - 1, b - 1) << '\n';
		}
		else {
			update(arr, tree, 1, 0, n - 1, b - 1, c);
		}
	}

	return 0;
}