#define _CRT_SECURE_NO_WARNINGS
#define MAX_DATA 79943

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void initDB();
void addData(char* id, char* job, char* server);
int deleteData(int key, char* str);
int updateData(int key, char* str, int ukey, char* ustr);
int serchData(int key, char* str);

// key는 id = 0, job = 1, server = 2

typedef struct st {
	char d[3][25];
	int deleteFlag;
}DATA;

DATA POOL[50010]; // Data에 대한 memory pool. data가 최대 5만개라고 가정
int pcnt;

typedef struct st2 {
	DATA* data;
	struct st2* next;
}HASH; // Hash에서 data를 보고 있으므로, 포인터로 접근하여 deleteFlag 변경가능


HASH hash[3][MAX_DATA];
HASH MEMORY[150030]; // 3개의 index에 대해 모두 hash 만들면 POOL이 3배 필요
int hcnt;

// **Pointer로 구현하는 이유
// Hash table에 3종류의 string정보를 모두 복사하는건 비효율적이므로
// DB는 1개만 유지하고, 3개의 index에 대한 각각의 Hash table이 DB를 바라보도록 한다.

typedef unsigned long long int ll;

ll my_hash(char* str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_DATA;
	}

	return hash % MAX_DATA;
}

void initDB() { // TC 여러 개 일때 사용
	hcnt = pcnt = 0;
	for (register int i = 0; i < 3; i++)
		for (register int k = 0; k < MAX_DATA; k++)
			hash[i][k].next = 0; // 구조체 포인터 0으로 초기화? 문법 확인
}

void addData(char* id, char* job, char* server) {
	DATA* data = &POOL[pcnt++];
	strcpy(data->d[0], id);
	strcpy(data->d[1], job);
	strcpy(data->d[2], server);

	HASH* hashTable[3];
	ll h[3];

	h[0] = my_hash(id);
	h[1] = my_hash(job);
	h[2] = my_hash(server);

	hashTable[0] = &MEMORY[hcnt++];
	hashTable[0]->data = data;

	hashTable[1] = &MEMORY[hcnt++];
	hashTable[1]->data = data;

	hashTable[2] = &MEMORY[hcnt++];
	hashTable[2]->data = data; // 3개가 동일한 테이블 바라보도록

	for (register int i = 0; i < 3; i++)
	{
		hashTable[i]->next = hash[i][h[i]].next;
		hash[i][h[i]].next = hashTable[i];
	}
}

int deleteData(int key, char* str) {
	register int cnt;
	ll h = my_hash(str);

	HASH* p;
	DATA* tmp;
	cnt = 0;

	p = &hash[key][h];
	while (p->next) {
		tmp = p->next->data;
		if (!strcmp(tmp->d[key], str) && !tmp->deleteFlag) {
			tmp->deleteFlag = 1;
			p->next = p->next->next;

			cnt++;
		}
		else
			p = p->next;
	}

	return cnt;
}

int updateData(int key, char* str, int ukey, char* ustr) {
	register int cnt;
	ll h = my_hash(str);

	cnt = 0;

	for (register HASH* p = hash[key][h].next; p; p = p->next) {
		if (!strcmp(p->data->d[key], str) && !p->data->deleteFlag) {
			p->data->deleteFlag = 1;

			DATA data;

			for (register int i = 0; i < 3; i++) {
				if (i == ukey) continue;
				strcpy(data.d[i], p->data->d[1]);
			}

			strcpy(data.d[ukey], ustr);
			addData(data.d[0], data.d[1], data.d[2]);
			cnt++;
		}
	}
	return cnt; // 변경된 data 개수 return
}

int serchData(int key, char* str) {
	register int cnt;
	ll h = my_hash(str);
	cnt = 0;

	for (register HASH* p = hash[key][h].next; p; p->next)
		if (!strcmp(p->data->d[key], str)&&)
}