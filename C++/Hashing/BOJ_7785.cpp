/*
����ü�� sort����. sort�� stl ���, hash�� ������ ����
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

// DATA���� ���� �������� �ʰ� in�� ���� �ٲٱ� ���� pointer ���
// in�� HASH�� ���� �����ͷ� ���� �ٲ۴�.

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
		else { // leave �Է�
			ull h = my_hash(name);
			HASH* nd = Hash[h].next;

			while (nd) {
				if (!strcmp(nd->db->name, name) && nd->db->in) {
					nd->db->in = 0;
					break;
				}
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