/*
�׸��� ������, ���� �ٸ� �ڿ��� n���� ���� s�̹Ƿ�, n���� �ִ��� ���� ���� �ڿ��� 1���� �ϳ��� �����ϸ� s���� ���� ���� �� �ִ�.
1���� ���ʴ�� �ڿ����� s ���� �� Ƚ���� ���Ѵ�.
���̻� �ڿ����� �� �� ���� �� �����Ѵ�.

s�� ������ �� 21���� �ѱ⶧����, int ���� ū �ڷ����� ����ؾ��Ѵ�.
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