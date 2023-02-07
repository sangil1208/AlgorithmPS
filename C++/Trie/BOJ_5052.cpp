// ������ 783p ���� ����

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int NUMBERS = 10;
int toNum(char ch) { return ch - '0'; } // ���� 0~9 ����

/*
string�� ���ڷ� ���� ��, �� �Լ� ȣ�⸶�� �ش� ���� �����ؼ� ����Ѵ�.
������ &�� ����� �����ϸ�, string�� �����Ͽ� ������� �ʴ´� (�޸� ����)
*/
struct TrieNode {

	TrieNode* children[NUMBERS];

	bool terminal;

	TrieNode() : terminal(false) {
		memset(children, 0, sizeof(children));
	}

	~TrieNode() {
		for (int i = 0; i < NUMBERS; ++i)
			if (children[i])
				delete children[i];
	}

	void insert(string& key, int index) {
		if (key[index] == '\0')
			terminal = true;
		else {
			int next = toNum(key[index]);
			// �ش� �ڽ� ��尡 ������ ����
			if (children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(key, index + 1);
		}
	}

	// key�� �ش��ϴ� ���ڿ��� ���ξ�� ������ �ִ��� Ȯ���ϰ�
	// ������ �ִٸ� �ش� ���ξ ������ �κ��� ��ġ�� ��ȯ.


	bool find(string& key, int depth) {
		if (key[depth] == '\0')
			return true;
		int next = toNum(key[depth]);
		if (children[next] == NULL)
			return false;
		return children[next]->find(key, depth + 1);
	}

	// key�� �ش��ϴ� ���ڿ��� ���ԵǾ� �ִ��� Ȯ���ϴ� �ڵ�
	// �ش� key�� ���ڿ��� �ִٸ� true�� ��ȯ�ϰ� ������ false�� ��ȯ.
	bool exist(string& key, int depth) {
		if (terminal)
			return true;
		int next = toNum(key[depth]);
		if (children[next] == NULL)
			return false;
		return children[next]->exist(key, depth + 1);
	}

};

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string res = "YES";

		TrieNode* root = new TrieNode();

		for (register int i = 0; i < n; i++) {
			string input;
			cin >> input;
			if (!root->exist(input, 0) && !root->find(input, 0)) {
				// ������ ���ڿ� �������� �ʰ�, INPUT�� ���ݱ��� ���� ���ڿ��� ���λ絵 �ƴҶ�
				root->insert(input, 0);
			}
			else {
				res = "NO";
			}
		}

		delete root;

		cout << res << '\n';
	}
	return 0;
}

