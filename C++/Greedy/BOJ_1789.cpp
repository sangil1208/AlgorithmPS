/*
그리디 문제로, 서로 다른 자연수 n개의 합이 s이므로, n개의 최댓값은 가장 작은 자연수 1부터 하나씩 증가하며 s에서 빼서 구할 수 있다.
1부터 차례대로 자연수를 s 에서 뺀 횟수를 구한다.
더이상 자연수를 뺄 수 없을 때 종료한다.

s의 범위가 약 21억을 넘기때문에, int 보다 큰 자료형을 사용해야한다.
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	long long s;
	cin >> s;

	long long result = 0;
	long long i = 1;

	while (1) {
		if (s >= i) {
			result += 1;
			s -= i;
			i += 1;
		}
		else
			break;
	}

	cout << result;

	return 0;

}