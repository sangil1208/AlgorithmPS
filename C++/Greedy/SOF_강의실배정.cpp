#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main(int argc, char** argv) {

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), compare);

	int res = 1;
	int finish_time = v[0].second;

	for (int i = 1; i < n; i++) {
		if (finish_time <= v[i].first) {
			finish_time = v[i].second;
			res += 1;
		}
	}

	cout << res;

	return 0;
}