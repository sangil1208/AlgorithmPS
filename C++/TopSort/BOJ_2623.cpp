#define MAX 1100

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

int indeg[MAX];

vector<int> v[MAX];

int main(void) {
	cin >> n >> m;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (register int i = 1; i <= n; i++) {
		indeg[i] = 0;
	}

	for (register int i = 0; i < m; i++) {

		int a;
		cin >> a;

		int prev;

		for (register int j = 0; j < a; j++) {
			int input;
			cin >> input;
			if (j == 0) {
				prev = input;
				continue;
			}
			else {
				v[prev].push_back(input);
				indeg[input] += 1;
				prev = input;
			}
		}
	}

	queue<int> q;

	for (register int i = 1; i <= n; i++) {
		if (indeg[i] == 0)
			q.push(i);
	}

	vector<int> res;

	while (!q.empty()) {
		int cur = q.front();
		res.push_back(cur);
		q.pop();

		for (register int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			indeg[next]--;
			if (indeg[next] == 0)
				q.push(next);
		}
	}

	if (res.size() != n)
		cout << 0;
	else {
		for (register int i = 0; i < n; i++) {
			cout << res[i] << '\n';
		}
	}


	return 0;
}