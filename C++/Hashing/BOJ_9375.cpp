#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int t;

int main() {

	cin >> t;

	for (register int i = 0; i < t; i++) {

		unordered_map<string, int> hash1;

		int n;
		cin >> n;

		string a, b;

		int res = 1;

		for (register int j = 0; j < n; j++) {
			cin >> a >> b;

			if (hash1.find(b) != hash1.end()) {
				int cnt = hash1[b];
				hash1[b] = cnt + 1;
			}

			else
				hash1[b] = 1;
		}

		for (auto iter = hash1.begin(); iter != hash1.end(); iter++) {
			res *= (iter->second) + 1;
		}

		cout << res - 1 << '\n';
	}

	return 0;
}