/*
binary search, �ִ� ã���� ���� ����
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
�� �� �� �߰��ؼ� ����� �ӵ� ��� (�Է� ���� ���� �� �ð� ���� ���̳�)
*/

#define ri register int
#define ll long long int
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<int> a;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (ri i = 0; i < n; ++i) {
		int input;
		cin >> input;
		a.push_back(input);
	}

	int start = 0;
	int end = *max_element(a.begin(), a.end());
	int res = 0;

	while (start <= end) {
		int mid = (start + end) / 2;
		ll sum = 0;
		for (auto i : a) {
			if ((i - mid) > 0) sum += (i - mid);
		}
		if (sum < m) {
			end = mid - 1;
		}
		else {
			res = mid;
			start = mid + 1;
		}
	}

	cout << res;
	

	return 0;
}