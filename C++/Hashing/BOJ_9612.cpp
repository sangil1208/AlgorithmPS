#define _CRT_SECURE_NO_WARNINGS
#define MAX_TABLE 1601

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long int ull;

typedef struct st {
	int cnt;
	char word[21];
	struct st* next;
}HASH;

HASH Hash[MAX_TABLE];
HASH POOL[MAX_TABLE];
int pcnt;


ull mhash(const char* str)
{
	ull hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}

int main(void) {

	int N;

	char res_s[21];
	int res_n = 0;

	scanf("%d", &N);

	for (register int i = 0; i < N; i++) {
		char input[21];
		scanf("%s", input);

		ull h = mhash(input);

		HASH* nd = &Hash[h];

		if (nd->next) {
			nd = nd->next;
			while (nd) {
				if (!strcmp(nd->word, input)) {
					nd->cnt = nd->cnt + 1;

					if (nd->cnt > res_n) {
						strcpy(res_s, input);
						res_n = nd->cnt;
					}

					else if ((nd->cnt == res_n) && (strcmp(res_s, input) < 0)) {
						strcpy(res_s, input);
					}

				}
				nd = nd->next;
			}
		}

		else {
			HASH* nd = &POOL[pcnt++];

			strcpy(nd->word, input);

			nd->cnt = 1;

			nd->next = Hash[h].next;
			Hash[h].next = nd;
		}
	}

	printf("%s %d", res_s, res_n);

	return 0;
}