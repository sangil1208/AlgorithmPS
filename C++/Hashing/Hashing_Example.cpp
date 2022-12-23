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

// key�� id = 0, job = 1, server = 2

typedef struct st {
	char d[3][25];
	int deleteFlag;
}DATA;

DATA POOL[50010]; // Data�� ���� memory pool. data�� �ִ� 5������� ����
int pcnt;

typedef struct st2 {
	DATA* data;
	struct st2* next;
}HASH; // Hash���� data�� ���� �����Ƿ�, �����ͷ� �����Ͽ� deleteFlag ���氡��


HASH hash[3][MAX_DATA];
HASH MEMORY[150030]; // 3���� index�� ���� ��� hash ����� POOL�� 3�� �ʿ�
int hcnt;

// **Pointer�� �����ϴ� ����
// Hash table�� 3������ string������ ��� �����ϴ°� ��ȿ�����̹Ƿ�
// DB�� 1���� �����ϰ�, 3���� index�� ���� ������ Hash table�� DB�� �ٶ󺸵��� �Ѵ�.

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

void initDB() { // TC ���� �� �϶� ���
	hcnt = pcnt = 0;
	for (register int i = 0; i < 3; i++)
		for (register int k = 0; k < MAX_DATA; k++)
			hash[i][k].next = 0; // ����ü ������ 0���� �ʱ�ȭ? ���� Ȯ��
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
	hashTable[2]->data = data; // 3���� ������ ���̺� �ٶ󺸵���

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
	return cnt; // ����� data ���� return
}

int serchData(int key, char* str) {
	register int cnt;
	ll h = my_hash(str);
	cnt = 0;

	for (register HASH* p = hash[key][h].next; p; p->next)
		if (!strcmp(p->data->d[key], str)&&)
}