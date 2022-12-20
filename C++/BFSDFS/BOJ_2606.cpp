#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <queue>

using namespace std;

int N, M, ANSWER;

typedef struct st {
	int node;
	struct st* next;
}NODE;

NODE HEAD[110]; //pool for node
NODE POOL[110 * 110]; //pool for connections between nodes
int pcnt;

int visit[110];

void init(int N) {
	pcnt = 0;
	for (int i = 1; i <= N; i++) HEAD[i].node = i;
	for (int i = 1; i <= N; i++) HEAD[i].next = 0;
	for (int i = 1; i <= N; i++) visit[i] = 0;

	ANSWER = 0;
}

void Make(int p, int c) {
	NODE* nd = &POOL[pcnt++];
	nd->node = c;

	nd->next = HEAD[p].next;
	HEAD[p].next = nd;
}

void bfs(int start) {
	queue<NODE*> q;
	visit[start] = 1;
	q.push(&HEAD[start]);

	while (!q.empty()) {
		int node = q.front()->node;
		q.pop();

		for (NODE* p = HEAD[node].next; p; p = p->next) {
			if (visit[p->node] == 0) {
				visit[p->node] = 1;
				ANSWER++;
				q.push(p);
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	init(N); /* B형 tc가 여러 개인 경우 대비 */

	for (int i = 0; i < M; i++)
	{
		int p, c;
		scanf("%d %d", &p, &c);

		//양방향 연결
		Make(p, c);
		Make(c, p);
	}

	bfs(1);

	printf("%d\n", ANSWER);

	return 0;
}