/*
BOJ 2217
�ܼ��� ��� ������ ���� ���� �߿� �ּҰ�*���� ������ �ϴ°�?
-> ���� ������ŭ �ݵ�� ����ϴ� ���� �ƴϹǷ� Ʋ��
1������ N������ ���� ���� ������ ��������� �ִ밪�� ���ϱ�.
�������� ���� ��, ���� 1�� ���� ���� ū��(�� ��) 1���� ���
���� 2�� ���� 2 * 2��° �� (���߿� �����ɷ� ���ؾ��ϹǷ�)
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