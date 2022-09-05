/*
stack 자료구조를 이용해서 해결.
c++ 에서 stack은 #include <stack> 이후 stack <char> st;와 같이 사용
( 만 stack에 넣고, )가 나올때마다 (를 하나씩 빼면서 짝이 맞는지 확인.
)가 나왔는데 (가 없는 경우, 혹은 마지막에 stack에 (가 남아있는 경우 false이다.
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