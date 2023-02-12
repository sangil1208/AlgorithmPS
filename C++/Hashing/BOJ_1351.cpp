/*
n의 모든 범위를 dp를 위해 table을 만들면 n의 크기로 인해 메모리 초과 발생
따라서 dp에 필요한 index들에 대한 정보만 저장하기 위해 hash map을 사용
*/

#include <iostream>
#include <unordered_map>

typedef unsigned long long int ll;

using namespace std;

ll n;
int p, q;
unordered_map<ll, ll> dp;

ll func(ll n) {
	if (dp[n] != 0)
		return dp[n];
	else {
		dp[n] = func(n / p) + func(n / q);
		return dp[n];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> p >> q;

	dp[0] = 1;

	cout << func(n);

	return 0;
}