/*
브루트포스 문제. 가로 길이가 100이고, 덤프 횟수가 1000이하로 주어지므로
max, min 구하는 시간복잡도가 O(N), N번 수행하므로 10^6 으로 n^2알고리즘으로 1초내 통과 가능
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		int n;
		cin >> n;
		vector <int>a;

		for (int i = 0; i < 100; i++) {
			int temp;
			cin >> temp;
			a.push_back(temp);
		}

		for (int i = 0; i < n; i++) {
			int temp_max = max_element(a.begin(), a.end()) - a.begin();
			int temp_min = min_element(a.begin(), a.end()) - a.begin();

			a[temp_max]--;
			a[temp_min]++;
		}

		int result = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());

		cout << '#' << test_case << ' ' << result << '\n';

	}
	return 0;
}