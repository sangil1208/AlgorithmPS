/*
�� ���� a����, a-2, a-1, a+1, a+2 ������ Ȯ���Ͽ� Ȯ���� �� ������ ��� a���� ���� ��� ������ Ȯ���ϴ� ���밡 �����Ѵ�.
�� ��� �߿���, ���� ���� �������� ���̰� �������� Ȯ���� �����̴�.
���������� a���� �� �� ������ �� ���ڰ� �ּ��� �Ͱ��� ���̷� ����. (���� ���� �������� ���̿� ������ ��)
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		int n;
		cin >> n;
		int a[1001];

		int result = 0;

		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			a[i] = temp;
		}

		for (int i = 2; i < n - 2; i++) {
			if ((a[i - 2] - a[i]) < 0 && (a[i + 2] - a[i]) < 0 && (a[i - 1] - a[i]) < 0 && (a[i + 1] - a[i]) < 0) {
				int temp = min({ (a[i] - a[i - 2]), (a[i] - a[i + 2]), (a[i] - a[i + 1]), (a[i] - a[i - 1]) });
				result += temp;
			}
		}

		cout << "#" << test_case << " " << result << '\n';


	}
	return 0;
}