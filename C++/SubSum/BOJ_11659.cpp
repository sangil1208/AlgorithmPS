#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#define ri register int
#define ll long long int
#include <cstdio>

int N, M;
constexpr int MAX = 100010;
int A[MAX];
ll S[MAX];

void input() {
	scanf("%d %d", &N, &M);
	ri input;
	scanf("%d", &input);
	A[1] = input;
	S[1] = input;
	for (ri i = 2; i <= N; ++i) {
		scanf("%d", &input);
		A[i] = input;
		S[i] = S[i - 1] + A[i];
	}
}

void process() {
	int a, b;
	for (ri i = 0; i < M; ++i) {
		scanf("%d %d", &a, &b);
		printf("%d\n", S[b] - S[a - 1]);
	}
}

int main() {
	input();
	process();
	return 0;
}