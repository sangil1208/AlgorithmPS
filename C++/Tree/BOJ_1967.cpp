#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

typedef struct NODE {
	int num;
	vector<pair<NODE*, int>> children;
};

NODE POOL[10100];
int pcnt;

int longest = 0;

// 각 노드마다 해당 노드가 root일때 잎사이 경로 합

int FindTreeRad(NODE* root) {
	if (root->children.size() == 0)
		return 0;

	vector<int> costs;

	for (int i = 0; i < root->children.size(); i++)
		costs.push_back(FindTreeRad(root->children[i].first) + root->children[i].second);

	if (costs.size() > 1) {
		sort(costs.begin(), costs.end(), greater<>());
		longest = max(longest, costs[0] + costs[1]);
	}

	return costs[0];
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N;

	for (register int i = 0; i < N; i++) {
		NODE* node = &POOL[++pcnt];
		node->num = i + 1;
	}

	for (register int i = 1; i < N; i++) {
		int a, b, c;

		cin >> a >> b >> c;

		POOL[a].children.push_back(make_pair(&POOL[b], c));
	}

	// 최장길이 부분 트리의 길이는
	// 루트-리프 최대거리인 FindTreeRad와 리프-리프 최대거리인 longest의 최대값 
	int result = max(FindTreeRad(&POOL[1]), longest);

	cout << result;

	return 0;
}