#define MAX 1100

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;


int indeg[MAX];
int cost[MAX];
int res[MAX];
vector<int> v[MAX];

int t;

int main(void) {
	cin >> t;

	for (register int i = 0; i < t; i++) {

		int n, k;
		cin >> n >> k;

		vector<int> tmp;

		for (register int i = 0; i <= n; i++) {
			indeg[i] = 0;
			cost[i] = 0;
			res[i] = 0;
			v[i] = tmp;
		}

		queue<pair<int, int>> q;

		for (register int i = 1; i <= n; i++) {
			int input_cost;
			cin >> input_cost;
			cost[i] = input_cost;
		}

		for (register int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			indeg[b] += 1;
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

		int w;

		cin >> w;

		cout << res[w] << endl;

	}

	return 0;
}
