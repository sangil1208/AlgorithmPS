/*
BOJ 1015
�ּҰ� ã�������� i�� ���� 1�� ������Ű�鼭, �ش� �ּҰ��� index�� j�� ã�´�.
��� �迭�� index j�� �ش��ϴ� ���� i�� �����Ѵ�.
�̷��� �ϸ� �ּҰ����� ���ʴ�� ������ �ű� ���� ��� �迭�� ����ȴ�.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;

vector <int> a;


int main(void) {

	cin >> n;

	vector <int> result(n);


	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}


	for (int i = 0; i < n; i++) {
		int min = *min_element(a.begin(), a.end());
		for (int j = 0; j < n; j++) {
			if (a[j] == min) {
				result[j] = i;
				a[j] = 1001;
				break;
			}
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}


	return 0;
}