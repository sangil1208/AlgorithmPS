#define MAX 550

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int indeg[MAX];
int cost[MAX];
int res[MAX];
vector<int> v[MAX];

int n;

int main(void) {
	cin >> n;

	queue<pair<int, int>> q;

	int t = 0;

	for (register int i = 1; i <= n; i++) {
		int input_cost;
		cin >> input_cost;
		cost[i] = input_cost;
		while (1) {
			int b;
			cin >> b;
			if (b == -1)
				break;
			else {
				indeg[i] += 1;
				v[b].push_back(i);
			}
		}
	}

	for (register int i = 1; i <= n; i++) {
		if (indeg[i] == 0) {
			q.emplace(i, cost[i]);
			res[i] = cost[i];
		}
	}

	while (!q.empty()) {
		int id = q.front().first;
		int c = q.front().second;

		q.pop();

		for (register int i = 0; i < v[id].size(); i++) {
			int next = v[id][i];
			indeg[next] -= 1;
			if (indeg[next] == 0) {
				q.emplace(next, cost[next]);
			}
			res[next] = max(res[next], res[id] + cost[next]);
		}
	}

	for (register int i = 1; i <= n; i++) {
		cout << res[i] << '\n';
	}

	return 0;
}