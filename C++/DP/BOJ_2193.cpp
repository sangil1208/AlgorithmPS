/*
2차원 배열을 이용한 dp 문제이다.
n길이의 이친수는
이전 길이에서 0으로 끝난거 개수*2 + 1로 끝난거 개수 로 구할 수 있다.

따라서 각 길이에 대해 0으로 끝난것과 1로끝난것의 개수를 따로 저장해서 이를 이용한다.

n이 89와 같이 커지면 int 자료형의 범위를 벗어나므로 배열 타입을 long long으로 해주어야 통과.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long cnt[91][2] = { 0 };

int main(void) {

	int n;
	cin >> n;

	cnt[1][0] = 0;
	cnt[1][1] = 1;
	cnt[2][0] = 1;
	cnt[2][1] = 0;

	for (int i = 3; i <= n; i++) {
		cnt[i][0] = cnt[i - 1][0] + cnt[i - 1][1];
		cnt[i][1] = cnt[i - 1][0];
	}

	cout << cnt[n][0] + cnt[n][1];

	return 0;
}