/*
Union - find �˰��� �����̴�.
�ð� ���⵵ ���Ҹ� ���� Ư�� ����� �θ� ��带 ��Ʈ ���� �ٷ� �����ϴ� ��ξ��� ����� ����ߴ�.
�̸� ����ϸ� ��Ʈ ��忡 �� ���� ������ �� �־� find �Լ� ���⵵�� �����Ѵ�.
���� C�� C++ ����� stream�� ����ȭ�� ���� ����� �ӵ��� ������Ű�� ����

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

�� ������ ����ߴ�. �� ���� ��� �Ŀ��� C++ ����¸� ���ǰ�, C ��Ÿ�� ����� ���� ���� �߻��Ѵ�.
����, endl�� ���� ���� ��°� �Բ� ��� ���۸� ���� ���ұ��� ���� �ϹǷ� �����̰� �߻��Ѵ�.
���� �˰��� ���� Ǯ ���� ���� �ӵ� ����� ���� '\n'���� �����ϴ°��� ����.
*/


#include<iostream>

using namespace std;

int parent[1000001];
int n, m;

int findParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int c, a, b;
		cin >> c >> a >> b;

		if (c == 0) {
			unionParent(a, b);
		}
		else {
			if (findParent(a) == findParent(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}

	}

	return 0;
}