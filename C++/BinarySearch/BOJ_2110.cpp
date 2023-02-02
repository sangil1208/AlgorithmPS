// 이코테 560p 참고
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;

int main(void) {
	cin >> n >> c;

	vector<int> v;

	for (register int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	int start = 1;
	int end = v[v.size() - 1] - v[0];

	int result = 0;

	while (start <= end) {
		int mid = (start + end) / 2; // mid는 간격을 의미한다.

		int cur = 0;
		int cnt = 1;

		for (int i = 1; i < v.size(); i++) {
			if (v[cur] + mid <= v[i]) {
				cur = i;
				cnt += 1;
			}
		}

		if (cnt >= c) {
			start = mid + 1;
			result = mid;
		}

		else {
			end = mid - 1;
		}

	}

	cout << result;

	return 0;
}