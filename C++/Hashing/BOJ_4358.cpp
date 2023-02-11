/*
cout.precision()은 사실 소수점 아래 부분의 출력 범위만 설정하는 게 아니고

실수의 정수부와 소수부를 합친, 전체의 출력 범위를 설정하는 함수입니다.



만약, 이걸 소수점 아래 숫자의 출력 범위만 설정하게 쓰려면

함수 위에 cout << fixed; 라는 라인을 추가
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