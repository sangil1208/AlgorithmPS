/*
���Ʈ���� ����. ���� ���̰� 100�̰�, ���� Ƚ���� 1000���Ϸ� �־����Ƿ�
max, min ���ϴ� �ð����⵵�� O(N), N�� �����ϹǷ� 10^6 ���� n^2�˰������� 1�ʳ� ��� ����
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		int n;
		cin >> n;
		vector <int>a;

		for (int i = 0; i < 100; i++) {
			int temp;
			cin >> temp;
			a.push_back(temp);
		}

		for (int i = 0; i < n; i++) {
			int temp_max = max_element(a.begin(), a.end()) - a.begin();
			int temp_min = min_element(a.begin(), a.end()) - a.begin();

			a[temp_max]--;
			a[temp_min]++;
		}

		int result = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());

		cout << '#' << test_case << ' ' << result << '\n';

	}
	return 0;
}