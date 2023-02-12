/*
n�� ��� ������ dp�� ���� table�� ����� n�� ũ��� ���� �޸� �ʰ� �߻�
���� dp�� �ʿ��� index�鿡 ���� ������ �����ϱ� ���� hash map�� ���
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