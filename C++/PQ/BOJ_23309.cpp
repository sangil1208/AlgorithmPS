#define MAX 2002000

#include <iostream>
#include <list>
#include <string>

using namespace std;

int n, m;

typedef struct st1 {
	int left;
	int right;
}NODE;

NODE POOL[MAX];

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	list<int> li;
	list<int>::iterator it;
	list<int>::iterator it_tmp;

	for (register int i = 0; i < n; i++) {
		int input;
		cin >> input;
		li.push_back(input);
	}

	for (it = li.begin(); it != li.end(); ++it) {
		it_tmp = it;
		NODE* node = &POOL[*it];
		if (it == li.begin()) {
			node->left = *(--li.end());
			node->right = *(++it_tmp);
		}
		else if (it == --li.end()) {
			node->left = *(--it_tmp);
			node->right = *(li.begin());
		}
		else {
			node->left = *(--it_tmp);
			it_tmp++;
			node->right = *(++it_tmp);
		}

	}

	for (register int i = 0; i < m; i++) {
		string input;
		cin >> input;

		if (input == "BN") {
			int a, b;
			cin >> a >> b;

			int next = POOL[a].right;

			cout << next << '\n';

			NODE* node = &POOL[b];
			node->left = a;
			node->right = next;

			POOL[next].left = b;
			POOL[a].right = b;
		}

		if (input == "BP") {
			int a, b;
			cin >> a >> b;

			int prev = POOL[a].left;

			cout << prev << '\n';

			NODE* node = &POOL[b];
			node->left = prev;
			node->right = a;

			POOL[prev].right = b;
			POOL[a].left = b;
		}

		if (input == "CN") {
			int a;
			cin >> a;

			int next = POOL[a].right;
			int nn = POOL[next].right;

			POOL[nn].left = a;
			POOL[a].right = nn;

			POOL[next].left = 0;
			POOL[next].right = 0;

			cout << next << '\n';

		}

		if (input == "CP") {
			int a;
			cin >> a;

			int prev = POOL[a].left;
			int pp = POOL[prev].left;

			POOL[pp].right = a;
			POOL[a].left = pp;

			POOL[prev].left = 0;
			POOL[prev].right = 0;

			cout << prev << '\n';
		}
	}

	return 0;
}