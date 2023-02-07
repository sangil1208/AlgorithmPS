// 종만북 783p 구현 참고

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int NUMBERS = 10;
int toNum(char ch) { return ch - '0'; } // 숫자 0~9 저장

/*
string을 인자로 전달 시, 매 함수 호출마다 해당 값을 복사해서 사용한다.
하지만 &을 사용해 전달하면, string을 복사하여 사용하지 않는다 (메모리 절약)
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
			// 해당 자식 노드가 없으면 생성
			if (children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(key, index + 1);
		}
	}

	// key에 해당하는 문자열을 접두어로 가지고 있는지 확인하고
	// 가지고 있다면 해당 접두어가 끝나는 부분의 위치를 반환.


	bool find(string& key, int depth) {
		if (key[depth] == '\0')
			return true;
		int next = toNum(key[depth]);
		if (children[next] == NULL)
			return false;
		return children[next]->find(key, depth + 1);
	}

	// key에 해당하는 문자열이 포함되어 있는지 확인하는 코드
	// 해당 key의 문자열이 있다면 true를 반환하고 없으면 false를 반환.
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
				// 동일한 문자열 포함하지 않고, INPUT이 지금까지 나온 문자열의 접두사도 아닐때
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

