/*
��Ģ�� ã�°� �߿��� ����.
1�� ������ �͵��� �ٷ� ���� ���鿡 1�� ���� �͵�
0���� ������ �͵��� �ٷ� ���� ���鿡 0�� ���� �͵�
���� dp ���̺��� ���� �� + ���� ���� ���� ���� ���̺� �� ���ϸ� �ȴ�.
������ long long���ε� ������ �ȵǴ� ������ �߰��� ����� �� ������
�� ���̺� ���� �����Ҷ� �̸� ������ ���� ��������� �Ѵ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long cnt[1000001] = { 0 };

int main(void) {

	int n;
	cin >> n;

	cnt[1] = 1;
	cnt[2] = 2;

	for (int i = 3; i <= n; i++) {
		cnt[i] = (cnt[i - 2] + cnt[i - 1]) % 15746;
	}

	cout << cnt[n];

	return 0;
}