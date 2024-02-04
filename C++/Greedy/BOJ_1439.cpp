#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {

	string input;
	cin >> input;

	int res = 0;
	int zeros = 0;
	int ones = 0;
	int before = -1;

	for (auto i : input) {
		int num = i - '0';
		if (num == 1) {
			if (num != before) {
				ones += 1;
			}
		}
		else {
			if (num != before) {
				zeros += 1;
			}
		}
		before = num;
	}

	cout << min(zeros, ones) << endl;

	return 0;
}