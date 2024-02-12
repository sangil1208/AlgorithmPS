#define ri register int
#define ll long long int
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	ll b;
	cin >> n >> b;

	for (ri i = 0; i < n; ++i) {
		int input;
		cin >> input;
		v.emplace_back(input);
	}

	sort(v.begin(), v.end());

	ll start = 1;
	ll end = 2e9;
	ll res = 0;
	while (start <= end) {
		ll mid = (start + end) / 2;
		ll budget = b;
		for (auto i : v) {
			if (i >= mid) break;
			budget -= pow((mid - i), 2);
		}
		if (budget == 0) {
			res = mid;
			break;
		}
		else if (budget > 0) {
			start = mid + 1;
			res = mid;
		}
		else {
			end = mid - 1;
		}
	}

	cout << res;

	return 0;
}