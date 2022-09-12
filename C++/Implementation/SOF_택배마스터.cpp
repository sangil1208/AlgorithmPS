#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = x;
	}

	long long min = 99999999999;
	sort(a.begin(), a.end());
	do {
		int result = 0;
		int i = 0;
		int sum = 0;
		int cnt = 0;
		while (1) {
			i = i % n;
			if (sum + a[i] > m) {
				cnt += 1;
				result += sum;
				sum = 0;
				continue;
			}
			else {
				sum += a[i];
			}
			i++;
			if (cnt == k)
				break;
		}
		if (result < min)
			min = result;
	} while (next_permutation(a.begin(), a.end()));

	cout << min;

	return 0;
}