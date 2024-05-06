#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>

// LIMIT : 컴파일 시간에 값을 알 수 있도록 constexpr로 선언 - 성능 향상
constexpr int LM = 55;
constexpr int INF = LM * LM;
int R, C, visited[LM][LM];

struct Data {
	int r, c, lev;
}que[LM * LM];

int fr, re; // front, rear
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int dx, dy; // 도착점
int sx, sy; // 시작점

void push(int r, int c, int lev) {
	if (visited[r][c] <= lev) return;
	visited[r][c] = lev;
	que[re++] = { r, c, lev };
}

void input() {
	scanf("%d %d", &R, &C);
	char ch;
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			scanf(" %c", &ch);
			visited[i][j] = INF; // 갈 수 있는 곳은 INF로
			if (ch == '*') push(i, j, 0);
			else if (ch == 'S') sx = i, sy = j;
			else if (ch == 'D') {
				visited[i][j] = 0; // 불에 대해서는 갈 수 없도록
				dx = i, dy = j;
			}
			else if (ch == 'X') visited[i][j] = 0;
		}
	}
}


void bfs() {
	while (fr < re) {
		Data& t = que[fr++];
		for (int i = 0; i < 4; ++i) {
			push(t.r + dr[i], t.c + dc[i], t.lev + 1);
		}
	}
}


int main() {
	input();
	bfs(); // 불에 대한 bfs
	visited[dx][dy] = INF;
	fr = re = 0;

	push(sx, sy, 0);
	bfs();
	if (visited[dx][dy] == INF) puts("impossible");
	else printf("%d\n", visited[dx][dy]);
	return 0;
}