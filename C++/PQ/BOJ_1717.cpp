/*
Union - find 알고리즘 문제이다.
시간 복잡도 감소를 위해 특정 노드의 부모 노드를 루트 노드로 바로 저장하는 경로압축 기법을 사용했다.
이를 사용하면 루트 노드에 더 빨리 접근할 수 있엇 find 함수 복잡도가 감소한다.
또한 C와 C++ 입출력 stream간 동기화를 끊어 입출력 속도를 증가시키기 위해

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

위 구문을 사용했다. 위 구문 사용 후에는 C++ 입출력만 허용되고, C 스타일 입출력 사용시 오류 발생한다.
또한, endl은 개행 문자 출력과 함께 출력 버퍼를 비우는 역할까지 같이 하므로 딜레이가 발생한다.
따라서 알고리즘 문제 풀 때는 실행 속도 향상을 위해 '\n'으로 개행하는것이 좋다.
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