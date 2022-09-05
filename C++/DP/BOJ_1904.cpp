/*
규칙성 찾는게 중요한 문제.
1로 끝나는 것들은 바로 이전 값들에 1만 붙인 것들
0으로 끝나는 것들은 바로 전전 값들에 0만 붙인 것들
따라서 dp 테이블의 이전 값 + 전전 값을 더해 현재 테이블 값 구하면 된다.
하지만 long long으로도 저장이 안되는 값들이 중간에 저장될 수 있으니
각 테이블에 값을 저장할때 미리 나머지 연산 수행해줘야 한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long cnt[1000001] = { 0 };

int main(void) {

	int n;
	cin >> n;

	cnt[1] = 1;
	cnt[2] = 2;

	for (int i = 3; i <= n; i++) {
		cnt[i] = (cnt[i - 2] + cnt[i - 1]) % 15746;
	}

	cout << cnt[n];

	return 0;
}