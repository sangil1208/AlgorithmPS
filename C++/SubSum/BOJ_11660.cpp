#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#define ri register int
#include <cstdio>

using LL = long long;
constexpr int LM = (1 << 10) + 1;

int N, M;
LL sum[LM][LM];

void input() {
	scanf("%d %d", &N, &M);
	for (ri i = 1; i <= N; ++i) {
		for (ri j = 1; j <= N; ++j) {
			int input;
			scanf("%d", &input);
			sum[i][j] = input + sum[i][j - 1];
		}
	}
}

void process() {
	int x1, y1, x2, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	LL ret = 0;
	for (ri i = x1; i <= x2; ++i) {
		ret += (sum[i][y2] - sum[i][y1 - 1]);
	}
	printf("%lld\n", ret);
}
int main(void) {
	input();
	for (ri i = 0; i < M; ++i) {
		process();
	}
	return 0;
}