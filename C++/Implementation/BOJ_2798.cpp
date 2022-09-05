#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {

	int n, m;
	int result = 0;

	vector <int> a;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}


	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int temp = a[i] + a[j] + a[k];
				if (temp <= m && result <= temp) {
					result = temp;
				}
			}
		}
	}

	cout << result;

	return 0;

}