#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

typedef struct NODE {
	int value;
	int parent;
	vector<int> children;
};

NODE POOL[60];
int pcnt;

int leaf = 0;

int findleaf(NODE* node) {

	if (node->children.size() == 0)
		return 0;
	for (int i = 0; i < node->children.size(); i++) {
		if (findleaf(&POOL[node->children[i]]) == 0) leaf++;
	}

	return leaf;
}

int main(void) {


	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N;

	for (register int i = 0; i < 60; i++) {
		NODE* node = &POOL[pcnt++];
		node->value = 0;
	}

	int root = 0;

	for (register int i = 0; i < N; i++) {
		int input;
		cin >> input;

		if (input == -1)
			root = i + 1;
		else {
			POOL[input + 1].children.push_back(i + 1);
			POOL[i + 1].parent = input + 1;
		}
	}


	int rm_num;
	cin >> rm_num;
	rm_num += 1;

	if (rm_num == root) {
		cout << 0;
		return 0;
	}

	findleaf(&POOL[root]);

	leaf = 0;

	int rm_parent = POOL[rm_num].parent;
	POOL[rm_parent].children.erase(remove(POOL[rm_parent].children.begin(), POOL[rm_parent].children.end(), rm_num), POOL[rm_parent].children.end());

	if (POOL[root].children.size() == 0)
		cout << 1;
	else {
		int erase_leaf = findleaf(&POOL[root]);
		cout << erase_leaf;
	}

	return 0;
}