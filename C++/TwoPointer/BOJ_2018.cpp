#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>

int N;
int ret = 1;

void process() {
	int sum = 1;
	int start = 1;
	int end = 1;
	while (end != N) {
		if (sum == N) {
			++ret;
			++end;
			sum += end;
		}
		else if (sum > N) {
			sum -= start;
			++start;
		}
		else {
			++end;
			sum += end;
		}
	}
}

int main() {
	scanf("%d", &N);
	process();
	printf("%d", ret);
	return 0;
}