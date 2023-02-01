/*
이중 우선순위 큐 구현을 위해 priority_queue 라이브러리를 활용하면
한 방향으로 삭제만 가능하기 때문에 maxq와 minq 두 개가 필요하다.
하지만 multiset을 이용하면, 항상 정렬된 상태를 유지하고, 하나의 multiset에서 최소/최대값 삭제가 가능하다.
또한, 중복 값 저장도 가능하므로 중복 값에 대해서 key가 아닌 주소로 제거한다면 중복값중 하나만 제거 가능하다.
이러한 성질을 이용하면 priority_queue보다 multiset으로 이중 우선순위 큐를 구현하는 것이 효율적이다.
*/

#include <iostream>
#include <set>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		multiset<int> ms;
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			char command;
			int x;
			cin >> command >> x;
			if (command == 'I')
				ms.insert(x);
			else {
				if (x == 1 && !ms.empty()) {
					auto iter = ms.end();
					iter--;
					ms.erase(iter);
				}
				else if (x == -1 && !ms.empty()) {
					auto iter = ms.begin();
					ms.erase(iter);
				}
			}
		}

		if (ms.empty())
			cout << "EMPTY\n";
		else {
			int max, min;
			auto iter = ms.end();
			iter--;
			max = *iter;
			iter = ms.begin();
			min = *iter;
			cout << max << " " << min << "\n";
		}
	}

	return 0;
}