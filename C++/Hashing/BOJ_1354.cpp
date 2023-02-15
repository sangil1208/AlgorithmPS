#include <iostream>
#include <unordered_map>

typedef long long int ll;

using namespace std;

ll n, p, q, x, y;
unordered_map<ll, ll> dp;

ll func(ll n) {
	if (dp[n] != 0)
		return dp[n];
	else {
		ll left = ll(n / p) - x;
		ll right = ll(n / q) - y;
		if (left < 0)
			left = 0;
		if (right < 0)
			right = 0;
		dp[n] = func(left) + func(right);
		return dp[n];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> p >> q >> x >> y;

	dp[0] = 1;

	cout << func(n);

	return 0;
}