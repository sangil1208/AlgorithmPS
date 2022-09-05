/*
2���� �迭�� �̿��� dp �����̴�.
n������ ��ģ����
���� ���̿��� 0���� ������ ����*2 + 1�� ������ ���� �� ���� �� �ִ�.

���� �� ���̿� ���� 0���� �����Ͱ� 1�γ������� ������ ���� �����ؼ� �̸� �̿��Ѵ�.

n�� 89�� ���� Ŀ���� int �ڷ����� ������ ����Ƿ� �迭 Ÿ���� long long���� ���־�� ���.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long cnt[91][2] = { 0 };

int main(void) {

	int n;
	cin >> n;

	cnt[1][0] = 0;
	cnt[1][1] = 1;
	cnt[2][0] = 1;
	cnt[2][1] = 0;

	for (int i = 3; i <= n; i++) {
		cnt[i][0] = cnt[i - 1][0] + cnt[i - 1][1];
		cnt[i][1] = cnt[i - 1][0];
	}

	cout << cnt[n][0] + cnt[n][1];

	return 0;
}