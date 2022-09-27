/*
단순 bfs문제. 하지만 bfs함수에 visited나 graph를 포인터로 넘기지 않으려면 테스트 케이스마다 graph와 visited초기화하도록 코드 작성해야함.
*/

#include<iostream>
#include<queue>

using namespace std;

int n = 16;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int graph[16][16];
int visited[16][16];

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
				if (visited[nx][ny] == 0 && (graph[nx][ny] == 0 || graph[nx][ny] == 3)) {
					visited[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 1;
	int nothing;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		pair<int, int> start;
		pair<int, int> end;

		cin >> nothing;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char temp;
				cin >> temp;
				graph[i][j] = temp - '0';
				visited[i][j] = 0;
				if (temp == '2') {
					start.first = i;
					start.second = j;
				}
				if (temp == '3') {
					end.first = i;
					end.second = j;
				}
			}
		}

		visited[start.first][start.second] = 1;
		bfs(start.first, start.second);

		if (visited[end.first][end.second] == 1) {
			cout << '#' << test_case << ' ' << 1 << '\n';
		}
		else {
			cout << '#' << test_case << ' ' << 0 << '\n';
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << visited[i][j];
			}
			cout << '\n';
		}

	}
	return 0;
}