/*
BOJ 1015
최소값 찾을때마다 i의 값을 1씩 증가시키면서, 해당 최소값의 index인 j를 찾는다.
결과 배열의 index j에 해당하는 값에 i를 저장한다.
이렇게 하면 최소값부터 차례대로 순서를 매긴 값이 결과 배열에 저장된다.
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