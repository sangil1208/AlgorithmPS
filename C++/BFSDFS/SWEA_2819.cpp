/*
��� ����Ǽ��� Ž���ϹǷ�, bfs���� dfs�� �����ϴ�.
dfs�� ���ڿ� ���� string�� �Ѱ��־� string�� ���̰� 7�� �Ǹ� set�� ����.
set���� �ߺ� �Ұ��̹Ƿ� ���� �ٸ� string ���� ã�� �� ����.
�ߺ� �湮�� ���ǹǷ� visited Ȯ���� �ʿ����� �ʰ�, ��� �������� ���� dfs ������

+) dfs ȣ��� x,y ������ y x�� �Ųٷ� �ؼ� ��� Ʋ�ȴ�. �̷� ����Ѻκ� �Ĳ��� �ڵ��ϱ�
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