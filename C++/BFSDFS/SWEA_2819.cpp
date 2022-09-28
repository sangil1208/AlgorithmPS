/*
모든 경우의수를 탐색하므로, bfs보다 dfs가 적합하다.
dfs의 인자에 현재 string을 넘겨주어 string이 길이가 7이 되면 set에 삽입.
set에는 중복 불가이므로 서로 다른 string 개수 찾을 수 있음.
중복 방문이 허용되므로 visited 확인은 필요하지 않고, 모든 시작점에 대해 dfs 수행함

+) dfs 호출시 x,y 순서를 y x로 거꾸로 해서 계속 틀렸다. 이런 사소한부분 꼼꼼히 코딩하기
*/


#include <iostream>
#include <set>
#include <string>

#define MAXN 4

using namespace std;

char graph[MAXN][MAXN];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

set<string> res;

void dfs(int x, int y, string s) {

	if (s.length() == 7) {
		res.insert(s);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
			dfs(nx, ny, s + graph[nx][ny]);
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; test_case++)
	{
		for (int x = 0; x < MAXN; x++) {
			for (int y = 0; y < MAXN; y++) {
				cin >> graph[x][y];
			}
		}

		for (int x = 0; x < MAXN; x++) {
			for (int y = 0; y < MAXN; y++) {
				dfs(x, y, "");
			}
		}

		cout << '#' << test_case << " " << res.size() << "\n";
		res.clear();

	}
	return 0;
}