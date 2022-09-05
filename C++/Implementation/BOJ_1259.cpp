#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {

	while (1) {

		int flag = 0;
		string s;
		vector <int> a;

		cin >> s;

		if (s == "0") {
			break;
		}

		for (int i = 0; i < s.size(); i++) {
			int x = s[i] - '0';
			a.push_back(x);
		}


		for (int i = 0; i < a.size(); i++) {
			if (a[i] == a[a.size() - 1 - i]) {
				continue;
			}
			else {
				flag = 1;
				break;
			}

		}

		if (flag == 1)
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
	return 0;
}