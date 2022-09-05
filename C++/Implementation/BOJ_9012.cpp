/*
stack �ڷᱸ���� �̿��ؼ� �ذ�.
c++ ���� stack�� #include <stack> ���� stack <char> st;�� ���� ���
( �� stack�� �ְ�, )�� ���ö����� (�� �ϳ��� ���鼭 ¦�� �´��� Ȯ��.
)�� ���Դµ� (�� ���� ���, Ȥ�� �������� stack�� (�� �����ִ� ��� false�̴�.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main(void) {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int flag = 0;
		stack<char> st;
		string s;
		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '(')
				st.push(s[j]);
			else {
				if (!st.empty())
					st.pop();
				else {
					cout << "NO" << endl;
					flag = 1;
					break;
				}
			}
		}

		if (flag == 1)
			continue;

		if (st.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}