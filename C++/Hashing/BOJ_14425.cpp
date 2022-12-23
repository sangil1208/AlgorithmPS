// 존재 여부 확인만 하면 되므로 pointer 없는 해시 사용?

#define _CRT_SECURE_NO_WARNINGS
#define MAX_TABLE 10100

#include <stdio.h>
#include <string.h>

typedef unsigned long long int ull;

int N, M;
int res;

typedef struct st {
    char name[501];
    struct st* next;
}SET;

SET HASH_TABLE[MAX_TABLE];
SET POOL[MAX_TABLE + 1000];

int pcnt = 0;

unsigned long long hash(const char* str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
    {
        hash = (((hash << 5) + hash) + c) % MAX_TABLE;
    }

    return hash % MAX_TABLE;
}

int main(void) {

    char input[501];

    scanf("%d %d", &N, &M);

    for (register int i = 0; i < N; i++) {

        scanf("%s", &input);

        ull h = hash(input);

        SET* data = &POOL[pcnt++];

        strcpy(data->name, input);

        data->next = HASH_TABLE[h].next;
        HASH_TABLE[h].next = data;
    }

    for (register int i = 0; i < M; i++) {
        scanf("%s", &input);

        ull h = hash(input);

        SET* nd = HASH_TABLE[h].next;

        while (nd) {
            if (!strcmp(nd->name, input)) {
                res++;
            }
            nd = nd->next;
        }
    }

    printf("%d", res);
}