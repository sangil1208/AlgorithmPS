/*
map�� value�� �������� �����ϱ�
-> map�� ����(pair<int, int>)�� �ű� ��, ������ cmp �Լ��� �ۼ��Ͽ� ���͸� sort
*/


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

typedef long long int ll;
using namespace std;

int n;

bool cmp(const pair<ll, int>& a, const pair<ll, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	map<ll, int> m;

	for (register int i = 0; i < n; i++) {
		ll input;
		cin >> input;
		m[input] += 1;
	}

	vector<pair<ll, int>> v(m.begin(), m.end());

	sort(v.begin(), v.end(), cmp);

	cout << v[0].first;

	return 0;
}