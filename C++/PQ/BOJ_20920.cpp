#define MAX 100100

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct st1 {
	int cnt;
	int len;
	string s;
}HEAP;

HEAP heap[MAX];
int hn;

int isHighPri(HEAP a, HEAP b) {
	if (a.cnt > b.cnt)
		return 1;
	if (a.cnt == b.cnt && a.len > b.len)
		return 1;
	if (a.cnt == b.cnt && a.len == b.len && a.s.compare(b.s) < 0)
		return 1;
	return 0;
}

void push(HEAP* heap, int& hn, int cnt, int len, string s) {
	register HEAP tmp;

	heap[++hn].cnt = cnt;
	heap[hn].len = len;
	heap[hn].s = s;

	for (register int i = hn; i > 1; i /= 2) {
		if (isHighPri(heap[i / 2], heap[i])) break;
		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;
	}
}


HEAP pop(HEAP* heap, int& hn) {
	register HEAP ret, tmp;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn].cnt = -1;
	heap[hn].len = -1;
	heap[hn--].s = "zzzzzzzzzzz";

	for (register int i = 1; i * 2 <= hn;) {
		if (isHighPri(heap[i], heap[i * 2]) && isHighPri(heap[i], heap[i * 2 + 1])) break;
		else if (isHighPri(heap[i * 2], heap[i * 2 + 1])) {
			tmp = heap[i * 2];
			heap[i * 2] = heap[i];
			heap[i] = tmp;

			i = i * 2;
		}
		else {
			tmp = heap[i * 2 + 1];
			heap[i * 2 + 1] = heap[i];
			heap[i] = tmp;

			i = i * 2 + 1;
		}
	}

	return ret;
}

int n, m;

unordered_map<string, int> um;
unordered_map<string, int> flag;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<string> v;

	cin >> n >> m;

	for (register int i = 0; i < n; i++) {
		string input;
		cin >> input;

		if (input.size() >= m) {
			um[input] += 1;
			v.push_back(input);
		}
	}

	for (register int i = 0; i < v.size(); i++) {
		if (flag[v[i]] != 1) {
			push(heap, hn, um[v[i]], v[i].size(), v[i]);
			flag[v[i]] = 1;
		}
	}

	int popn = hn;

	for (register int i = 0; i < popn; i++) {
		cout << pop(heap, hn).s << '\n';
	}

	return 0;
}