#include <iostream>
#include <deque>
#include <queue>
#include <map>

using namespace std;

int main(void) {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {

		map<pair<int, int>, int> dict;
		int k;
		cin >> k;

		priority_queue<int, deque<pair<int, int>>, less<int>> pq1;
		priority_queue<int, deque<int>, greater<int>> pq2;

		int cnt = 0;
		for (int j = 0; j < k; j++) {
			char command;
			int x;
			cin >> command >> x;
			if (command == 'I') {
				pq1.push(x, cnt);
				pq2.push(x);
				dict.insert(make_pair(make_pair(x, cnt), 0));
				cnt++;
			}
			else {
				if (x == 1 && !pq1.empty()) {
					dict[pair<int, int>(pq1.top(), cnt)] = 1;
					pq1.pop();
				}
				else if (x == -1 && !pq2.empty()) {
					dict[pq2.top()] = 1;
					pq2.pop();
				}

				int temp;
				while (!pq1.empty() && dict[pair<int, int>(pq1.top(), cnt)] == 1) {
					temp = pq1.top();
					dict[temp] = 0;
					pq1.pop();
				}
				dict[temp] = 1;
				while (!pq2.empty() && dict[pq2.top()] == 1) {
					dict[temp] = 0;
					pq2.pop();
				}
			}
		}

		if (pq1.empty() && pq2.empty())
			cout << "EMPTY\n";
		else
			cout << pq1.top() << " " << pq2.top() << '\n';
	}

	return 0;
}