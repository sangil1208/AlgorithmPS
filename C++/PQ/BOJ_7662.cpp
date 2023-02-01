/*
���� �켱���� ť ������ ���� priority_queue ���̺귯���� Ȱ���ϸ�
�� �������� ������ �����ϱ� ������ maxq�� minq �� ���� �ʿ��ϴ�.
������ multiset�� �̿��ϸ�, �׻� ���ĵ� ���¸� �����ϰ�, �ϳ��� multiset���� �ּ�/�ִ밪 ������ �����ϴ�.
����, �ߺ� �� ���嵵 �����ϹǷ� �ߺ� ���� ���ؼ� key�� �ƴ� �ּҷ� �����Ѵٸ� �ߺ����� �ϳ��� ���� �����ϴ�.
�̷��� ������ �̿��ϸ� priority_queue���� multiset���� ���� �켱���� ť�� �����ϴ� ���� ȿ�����̴�.
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