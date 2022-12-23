/*
구조체도 sort가능. sort만 stl 사용, hash는 구현한 버전
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_TABLE 1000003

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef unsigned long long int ull;

int N;

typedef struct st {
	char name[6];
	int in;
}DATA;


DATA dbList[1001000];
DATA enterList[1001000];

typedef struct st2 {
	DATA* db;
	struct st2* next;
}HASH;

// DATA값에 직접 접근하지 않고 in의 값을 바꾸기 위해 pointer 사용
// in을 HASH를 통해 포인터로 값을 바꾼다.

HASH Hash[MAX_TABLE];
HASH POOL[MAX_TABLE];
int pcnt;

ull my_hash(const char* str)
{
	ull hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}

bool compare(const DATA& d1, const DATA& d2) {
	if (strcmp(d1.name, d2.name) > 0)
		return 1;
	else
		return 0;
}


int main() {
	int count, inCnt;
	char name[6], cmd[6];

	scanf("%d", &N);

	count = 0;

	for (int i = 0; i < N; i++) {
		scanf("%s %s", name, cmd);
		if (!strcmp(cmd, (char*)"enter")) {
			strcpy(dbList[count].name, name);
			dbList[count].in = 1;

			ull h = my_hash(name);

			HASH* nd = &POOL[pcnt++];
			nd->db = &dbList[count];

			nd->next = Hash[h].next;
			Hash[h].next = nd;

			count++;
		}
		else { // leave 입력
			ull h = my_hash(name);

			// in flag = 0을 통해 삭제된것 처럼 보이게 하는것보다 (HASH* nd = Hash[h].next;)
			// 실제로 노드를 삭제하면 탐색을 줄일 수 있다.

			HASH* nd = &Hash[h]; //head 자체의 주소를 받는다

			while (nd->next) {
				if (!strcmp(nd->next->db->name, name)) {
					nd->next->db->in = 0;
					nd->next = nd->next->next;
					break;
				} // 이건 next를 직접적으로 바꾼다 (in=0 하면서 연결을 끊어버린다.)
				// enterList에서 무시하기 위해 연결을 끊어도 in=0으로 바꿔야 한다.
				nd = nd->next;
			}
		}
	}

	inCnt = 0;
	for (int i = 0; i < pcnt; i++)
		if (dbList[i].in) enterList[inCnt++] = dbList[i];

	sort(enterList, enterList + inCnt, compare);

	for (int i = 0; i < inCnt; i++) printf("%s\n", enterList[i].name);

	return 0;
}