#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, h;


int main(void) {

	cin >> n >> h;

	vector<int> up;
	vector<int> down;

	for (register int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (i % 2 == 0)
			down.push_back(input);
		else
			up.push_back(input);
	}

	sort(down.begin(), down.end());
	sort(up.begin(), up.end());

	int min = 200200;
	int mincnt = 0;

	for (register int i = 1; i <= h; i++) {
		int down_idx = lower_bound(down.begin(), down.end(), i) - down.begin();
		int up_idx = lower_bound(up.begin(), up.end(), h - i + 1) - up.begin();

		int d = down.size() - down_idx;
		int u = up.size() - up_idx;

		if (d + u < min) {
			min = d + u;
			mincnt = 0;
		}
		if (d + u == min)
			mincnt += 1;
	}

	cout << min << ' ' << mincnt << endl;

	return 0;
}