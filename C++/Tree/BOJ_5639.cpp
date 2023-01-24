#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct NODE {
	int value;
	NODE* left;
	NODE* right;
};

NODE POOL[10100];
int pcnt;

void insertNode(NODE* tree, NODE* node) {
	if (node->value < tree->value) {
		if (tree->left == NULL) {
			tree->left = node;
			return;
		}
		else
			insertNode(tree->left, node);
	}
	else if (node->value > tree->value) {
		if (tree->right == NULL) {
			tree->right = node;
			return;
		}
		else
			insertNode(tree->right, node);
	}
}

void postOrder(NODE* root) {

	if (root->left != NULL)
		postOrder(root->left);

	if (root->right != NULL)
		postOrder(root->right);

	cout << root->value << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;
	int input;

	vector<int> nodes;

	while (cin >> input) {
		if (input == EOF) break;
		nodes.push_back(input);
	}

	NODE* node = &POOL[++pcnt];
	node->value = nodes[0];

	for (register int i = 1; i < nodes.size(); i++) {
		NODE* node = &POOL[++pcnt];
		node->value = nodes[i];
		insertNode(&POOL[1], &POOL[pcnt]);
	}

	postOrder(&POOL[1]);


	return 0;
}