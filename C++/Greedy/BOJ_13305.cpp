/*
1. int ���� �Ѿ�� �ڷ��� ���� �ذ�
2. Ž���ϸ鼭 cost�� �ּҰ��� min_element�� �̿��Ͽ� ���Ϸ� ������ n���� �������� min���� ���Ƽ� �ð��ʰ�
-> min ���� �����ϸ鼭 ���� �� �ֽ�ȭ�ϵ��� �Ͽ� �ð����⵵ ����
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