#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(void) {

	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> n;

	vector<int> v;

	int res = 0;

	for (register int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	for (register int i = 0; i < n; i++) {
		int cur = v[i];
		int l = 0, r = n - 1;
		int sum = 0;
		while (l < r) {
			sum = v[l] + v[r];
			if (sum == cur) {
				if (l != i && r != i) {
					res += 1;
					break;
				}
				else if (l == i) l++;
				else if (r == i) r--;
			}
			else if (sum < cur) l++;
			else r--;
		}
	}

	cout << res;

	return 0;
}