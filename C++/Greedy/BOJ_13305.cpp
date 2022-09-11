/*
1. int 범위 넘어가는 자료형 문제 해결
2. 탐색하면서 cost의 최소값을 min_element를 이용하여 구하려 했지만 n개수 많아지면 min연산 많아서 시간초과
-> min 값을 갱신하면서 비교한 후 최신화하도록 하여 시간복잡도 감소
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {

	long long n;

	cin >> n;

	vector <long long> dist;
	vector <long long> cost;

	for (int i = 0; i < n - 1; i++) {
		long long x;
		cin >> x;
		dist.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		cost.push_back(x);
	}

	long long result = 0;
	long long min_cost = 1000000001;

	for (int i = 0; i < n - 1; i++) {
		if (cost[i] < min_cost)
			min_cost = cost[i];
		result += min_cost * dist[i];
	}

	cout << result;

	return 0;
}