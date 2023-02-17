#define MAX 220
#include <iostream>

using namespace std;

int parent[MAX];

int find_parent(int* parent, int x) {
	if (parent[x] != x) {
		parent[x] = find_parent(parent, parent[x]);
	}

	return parent[x];
}

void union_parent(int* parent, int a, int b) {
	a = find_parent(parent, a);
	b = find_parent(parent, b);

	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int n, m;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (register int i = 0; i < MAX; i++) {
		parent[i] = i;
	}

	cin >> n;
	cin >> m;

	for (register int i = 1; i <= n; i++) {
		for (register int j = 1; j <= n; j++) {
			int input;
			cin >> input;
			if (input == 1) {
				union_parent(parent, i, j);
			}
		}
	}

	int prev;
	int res = 0;

	for (register int i = 0; i < m; i++) {
		int input;
		cin >> input;
		if (i != 0) {
			if (find_parent(parent, prev) != find_parent(parent, input)) {
				cout << "NO";
				return 0;
			}
		}
		prev = input;
	}

	cout << "YES";

	return 0;
}