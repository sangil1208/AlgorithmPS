#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>

// LIMIT : 컴파일 시간에 값을 알 수 있도록 constexpr로 선언 - 성능 향상
constexpr int LM = 55;
int R, C;
int map[LM][LM];
int visited[LM][LM], vcnt;
struct Data {
	int r, c, lev;
}que[LM * LM];
int fr, re; // front, rear
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void input() {
	scanf("%d %d", &R, &C);
	char ch;
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			scanf(" %c", &ch);
			map[i][j] = (ch == 'L'); // L이라면 지도에 1로 표시
		}
	}
}

void push(int r, int c, int lev) {
	if (map[r][c] == 0 || visited[r][c] == vcnt) return;
	visited[r][c] = vcnt;
	que[re++] = { r, c, lev };
}

int bfs(int sr, int sc) {
	++vcnt;
	fr = re = 0;
	push(sr, sc, 0);
	while (fr < re) {
		Data& t = que[fr++];
		for (int i = 0; i < 4; ++i) {
			push(t.r + dr[i], t.c + dc[i], t.lev + 1);
		}
	}
	return que[re - 1].lev;
}

int process() {
	int ans = 0;
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			if (map[i][j]) { // 모든 land기준
				int ret = bfs(i, j);
				if (ret > ans) ans = ret;
			}
		}
	}
	return ans;
}

int main() {
	input();
	int ans = process();
	printf("%d\n", ans);
	return 0;
}