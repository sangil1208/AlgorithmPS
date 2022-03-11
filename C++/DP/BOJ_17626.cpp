/*
시간이 매우 짧고, 이전 문제의 해를 이용해서 해결할 수 있는 문제이기 때문에 DP를 생각했다.
특정 수에서 해당 수보다 작은 제곱수들을 각각 뺀 값의 배열 요소에서 1을 더한 값들의 최소값을 구한다.
모든 자연수는 넷 혹은 그 이하의 제곱수의 합으로 표현할 수 있다고 증명되어 있으므로, 4에 대한 check를 할 필요는 없다.
*/


#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int arr[50001];

int main(void) {

	fill_n(arr, 50001, INT_MAX);

	int n;
	cin >> n;

	arr[1] = 1;

	for (int i = 1; i <= n; i++) {
		if (int(sqrt(i))*int(sqrt(i)) == i) {
			arr[i] = 1;
		}
		else {
			int j = 1;
			while (j * j < i) {
				arr[i] = min(arr[i], arr[i - j*j] + 1);
				j++;
			}
		}
	}

	cout << arr[n];

	return 0;
}