#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main(int argc, char** argv) {

	int w, n;
	cin >> w >> n;

	int result = 0;

	vector <pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		if (w == 0)
			break;
		if (w >= v[i].first) {
			result += (v[i].first * v[i].second);
			w = w - v[i].first;
		}
		else {
			result += (w * v[i].second);
			w = 0;
		}
	}

	cout << result;

	return 0;
}