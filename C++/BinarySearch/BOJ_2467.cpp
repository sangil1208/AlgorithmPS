#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int n;

int main(void) {

	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> n;

	vector<int> v(n);

	for (register int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int min = INT_MAX;

	int a, b;

	int le = 0;
	int re = n - 1;

	while (le < re) {
		int tmp = v[le] + v[re];

		if (tmp == 0) {
			a = v[le];
			b = v[re];
			break;
		}

		if (abs(tmp) < min) {
			a = v[le];
			b = v[re];
			min = abs(tmp);
		}

		if (tmp < 0) {
			le++;
		}
		else if (tmp > 0) {
			re--;
		}
	}

	cout << a << ' ' << b;

	return 0;
}