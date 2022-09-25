/*
각 빌딩 a마다, a-2, a-1, a+1, a+2 빌딩을 확인하여 확인한 네 빌딩이 모두 a보다 낮은 경우 조망을 확보하는 세대가 존재한다.
이 경우 중에서, 가장 높은 빌딩과의 차이가 조망권이 확보된 세대이다.
구현에서는 a에서 각 네 빌딩을 뺀 숫자가 최소인 것과의 차이로 구현. (가장 높은 빌딩과의 차이와 동일한 값)
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		int n;
		cin >> n;
		int a[1001];

		int result = 0;

		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			a[i] = temp;
		}

		for (int i = 2; i < n - 2; i++) {
			if ((a[i - 2] - a[i]) < 0 && (a[i + 2] - a[i]) < 0 && (a[i - 1] - a[i]) < 0 && (a[i + 1] - a[i]) < 0) {
				int temp = min({ (a[i] - a[i - 2]), (a[i] - a[i + 2]), (a[i] - a[i + 1]), (a[i] - a[i - 1]) });
				result += temp;
			}
		}

		cout << "#" << test_case << " " << result << '\n';


	}
	return 0;
}