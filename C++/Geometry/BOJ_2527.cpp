#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#define ri register int
#include <cstdio>

struct Rect {
	int sr, sc, er, ec;
}a, b, c;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int main() {
	for (ri i = 0; i < 4; ++i) {
		scanf("%d%d%d%d", &a.sr, &a.sc, &a.er, &a.ec);
		scanf("%d%d%d%d", &b.sr, &b.sc, &b.er, &b.ec);

		// c는 교차하는 사각형
		c.sr = max(a.sr, b.sr), c.sc = max(a.sc, b.sc);
		c.er = min(a.er, b.er), c.ec = min(a.ec, b.ec);

		if (c.sr > c.er || c.sc > c.ec) puts("d");
		else if (c.sr < c.er && c.sc < c.ec) puts("a");
		else if (c.sr == c.er && c.sc == c.ec) puts("c");
		else puts("b");
	}
	return 0;
}