/*
cout.precision()�� ��� �Ҽ��� �Ʒ� �κ��� ��� ������ �����ϴ� �� �ƴϰ�

�Ǽ��� �����ο� �Ҽ��θ� ��ģ, ��ü�� ��� ������ �����ϴ� �Լ��Դϴ�.



����, �̰� �Ҽ��� �Ʒ� ������ ��� ������ �����ϰ� ������

�Լ� ���� cout << fixed; ��� ������ �߰�
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, double> m;

	string input;

	double cnt = 0;

	while (getline(cin, input)) {
		m[input] += 1;
		cnt += 1;
	}

	cout << fixed;
	cout.precision(4);

	for (auto i : m) {
		double p = (i.second / cnt) * 100;
		cout << i.first << ' ' << p << '\n';
	}

	return 0;
}