#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>
#include <string>

using namespace std;
vector<int> v;

int main(void) {

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	
	sort(v.begin(), v.end());

	int target = 1;

	for (int i : v) {
		if (target < i) break;
		target += i;
	}

	cout << target;

	return 0;
}