#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

#define MAX 200200

using namespace std;

int parent[MAX];
int friend_num[MAX];

int find_parent(int* parent, int x) {
	if (parent[x] != x) {
		parent[x] = find_parent(parent, parent[x]);
	}

	return parent[x];
}

void union_parent(int* parent, int* friend_num, int a, int b) {
	a = find_parent(parent, a);
	b = find_parent(parent, b);

	if (a < b) {
		parent[b] = a;
		friend_num[a] += friend_num[b];
	}
	else {
		parent[a] = b;
		friend_num[b] += friend_num[a];
	}
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (register int i = 0; i < t; i++) {
		int f;
		cin >> f;

		int num = 1;

		unordered_map<string, int> um;

		for (register int j = 0; j < MAX; j++) {
			parent[j] = j;
			friend_num[j] = 0;
		}

		for (register int j = 0; j < f; j++) {
			string a, b;

			cin >> a >> b;

			if (um[a] != 0 && um[b] != 0)
				;

			if (um[a] == 0) {
				um[a] = num++;
				friend_num[um[a]] = 1;
			}
			if (um[b] == 0) {
				um[b] = num++;
				friend_num[um[b]] = 1;
			}

			if (find_parent(parent, um[a]) != find_parent(parent, um[b]))
				union_parent(parent, friend_num, um[a], um[b]);

			int res = find_parent(parent, um[a]);

			cout << friend_num[res] << "\n";

		}
	}

	return 0;
}
