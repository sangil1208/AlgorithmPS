/*
BFS로 탐색하며 DIST그래프에 해당 좌표까지 방문하는 최단거리를 반복적으로 갱신.
다익스트라 방법으로도 풀이 가능 -> 다시 풀어보기
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<limits>

#define MAXN 100

using namespace std;

int n;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int graph[MAXN][MAXN];
int dist[MAXN][MAXN];

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (dist[x][y] + graph[nx][ny] < dist[nx][ny]) {
					dist[nx][ny] = graph[nx][ny] + dist[x][y];
					q.push({ nx, ny });
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char temp;
				cin >> temp;
				graph[i][j] = temp - '0';
				dist[i][j] = INT_MAX;
			}
		}

		dist[0][0] = graph[0][0];

		bfs(0, 0);

		cout << '#' << test_case << ' ' << dist[n - 1][n - 1] << '\n';

	}
	return 0;
}