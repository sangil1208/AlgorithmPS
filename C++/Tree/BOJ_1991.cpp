#include <iostream>

using namespace std;

int N;
struct TreeNode {
	char data;
	TreeNode* left;
	TreeNode* right;
};

TreeNode POOL[30];
int pcnt;

void Preorder(TreeNode* root) {
	cout << root->data;

	if (root->left != NULL)
		Preorder(root->left);

	if (root->right != NULL)
		Preorder(root->right);
}

void Inorder(TreeNode* root) {

	if (root->left != NULL)
		Inorder(root->left);

	cout << root->data;

	if (root->right != NULL)
		Inorder(root->right);

}

void Postorder(TreeNode* root) {

	if (root->left != NULL)
		Postorder(root->left);

	if (root->right != NULL)
		Postorder(root->right);

	cout << root->data;
}
int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (register int i = 0; i < N; i++) {
		TreeNode* node = &POOL[++pcnt];
		node->data = 65 + i;
	}

	for (register int i = 0; i < N; i++) {
		char n, l, r;
		cin >> n >> l >> r;

		if (l != '.')
			POOL[n - 64].left = &POOL[l - 64];
		if (r != '.')
			POOL[n - 64].right = &POOL[r - 64];
	}


	Preorder(&POOL[1]);
	cout << '\n';

	Inorder(&POOL[1]);
	cout << '\n';

	Postorder(&POOL[1]);
	cout << '\n';

	return 0;
}