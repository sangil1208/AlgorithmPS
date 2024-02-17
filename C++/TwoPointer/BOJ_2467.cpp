#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#define ri register int
#include <cstdio>

constexpr int NM = 100005;
int N, A[NM];
int ans, retA, retB;

inline int abs(int a) { return a < 0 ? -a : a; }

void input() {
	scanf("%d", &N);
	for (ri i = 1; i <= N; ++i) {
		scanf("%d", A + i);
	}
}

void process() {
	int l = 1, r = N;
	int sum = abs(A[l] + A[r]);
	int ans = sum;
	retA = A[l], retB = A[r];
	while (l < r) {
		sum = A[l] + A[r];
		if (abs(sum) <= ans) {
			ans = abs(sum);
			retA = A[l], retB = A[r];
		}
		if (sum == 0) break;
		if (sum < 0) ++l;
		else --r;
	}
}

int main() {
	input();
	process();
	printf("%d %d", retA, retB);
	return 0;
}