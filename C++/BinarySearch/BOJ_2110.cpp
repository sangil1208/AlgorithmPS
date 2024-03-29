#define ri register int
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c;
	cin >> n >> c;

	for (ri i = 0; i < n; ++i) {
		int input;
		cin >> input;
		v.emplace_back(input);
	}

	sort(v.begin(), v.end());

	int start = 1;
	int end = v[n - 1];
	int res = 0;

	while (start <= end) {
		int mid = (start + end) / 2;

		int cur = 0;
		int cnt = 1;
		for (ri i = 1; i < n; ++i) {
			if (v[cur] + mid <= v[i]) {
				cur = i;
				cnt += 1;
			}
		}

		if (cnt >= c) {
			start = mid + 1;
			res = mid;
		}
		else end = mid - 1;
	}

	cout << res;
	return 0;
}