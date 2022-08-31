/*
BOJ 2217
단순히 사용 가능한 로프 길이 중에 최소값*로프 개수를 하는것?
-> 로프 개수만큼 반드시 사용하는 것이 아니므로 틀림
1개부터 N개까지 각각 로프 개수를 사용했을때 최대값을 구하기.
내림차순 정렬 후, 로프 1개 사용시 가장 큰거(맨 앞) 1개만 사용
로프 2개 사용시 2 * 2번째 값 (둘중에 작은걸로 곱해야하므로)
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
int result = 0;

vector<int> len;

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		len.push_back(x);
	};

	sort(len.begin(), len.end());
	reverse(len.begin(), len.end());


	for (int i = 0; i < n; i++) {
		if (result < len[i] * (i + 1)) {
			result = len[i] * (i + 1);
		};
	};

	cout << result;

	return 0;
}