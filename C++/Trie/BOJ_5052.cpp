// ������ 783p ���� ����

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int NUMBERS = 10;
int toNum(char ch) { return ch - '0'; } // ���� 0~9 ����

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

	void insert(const char* key) {
		if (*key == '\0')
			terminal = true;
		else {
			int next = toNum(*key);
			// �ش� �ڽ� ��尡 ������ ����
			if (children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(key + 1);
		}
	}

	// key�� �ش��ϴ� ���ڿ��� ���ξ�� ������ �ִ��� Ȯ���ϰ�
	// ������ �ִٸ� �ش� ���ξ ������ �κ��� ��ġ�� ��ȯ.
	TrieNode* find(const char* key) {
		if (*key == '\0') return this;
		int next = toNum(*key);
		if (children[next] == NULL) return NULL;
		return children[next]->find(key + 1);
	}

	// key�� �ش��ϴ� ���ڿ��� ���ԵǾ� �ִ��� Ȯ���ϴ� �ڵ�
	// �ش� key�� ���ڿ��� �ִٸ� true�� ��ȯ�ϰ� ������ false�� ��ȯ.
	bool exist(const char* key) {
		if (terminal) {
			return true;
		}

		int next = toNum(*key);
		if (children[next] == NULL) {
			return false;
		}
		return children[next]->exist(key + 1);
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
			if (!root->exist(input.c_str()) && root->find(input.c_str()) == NULL) {
				// ������ ���ڿ� �������� �ʰ�, INPUT�� ���ݱ��� ���� ���ڿ��� ���λ絵 �ƴҶ�
				root->insert(input.c_str());
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

