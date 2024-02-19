#define ri register int
#define MAX 2020

#include <iostream>
#include <vector>

using namespace std;

vector<int> v[MAX];
bool visited[MAX];

int n, m;
int res;

void dfs(int start, int cnt) {
	if (cnt == 5 || res == 1) {
		res = 1;
		return;
	}
	visited[start] = true;
	for (auto i : v[start]) {
		if (visited[i] == false) {
			dfs(i, cnt + 1);
		}
	}
	// 왜 다시 false 처리하는지 생각 (다른 분기에서 다시 사용 가능하도록 초기화)
	visited[start] = false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (ri i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}

	res = 0;

	for (ri i = 0; i < n; ++i) {
		dfs(i, 1);
		if (res == 1) break;
	}

	cout << res;

	return 0;
}