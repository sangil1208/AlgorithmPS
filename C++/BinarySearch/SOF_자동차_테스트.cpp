#define ri register int
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int bs(int s, int e, int target) {
	int start = s;
	int end = e;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (v[mid] == target)
			return mid; // index return
		else if (v[mid] < target) start = mid + 1;
		else end = mid - 1;
	}
	return -1;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;

	for (ri i = 0; i < n; ++i) {
		int input;
		cin >> input;
		v.emplace_back(input);
	}

	sort(v.begin(), v.end());

	int start = 0;
	int end = n - 1;

	for (ri i = 0; i < q; ++i) {
		int input;
		cin >> input;
		int pos = bs(start, end, input); // inputÀÇ indexÀ§Ä¡
		if (pos == -1) cout << 0 << endl;
		else cout << pos * (n - pos - 1) << endl;
	}
	return 0;
}