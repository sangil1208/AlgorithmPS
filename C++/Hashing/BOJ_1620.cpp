/*
문자열 저장 시 hashing

해싱 함수는 B형 reference code 활용

string 관련 라이브러리 사용시 속도 저하, 문자열 비교 및 복사는 직접 구현
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_TABLE 100003 // 이 숫자는 N보다 큰 소수로 설정
// 먼저 문제를 다 푼 후, 소수 바꿔가면서 성능 가장 좋은 N 찾기

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int ull;

int N, M;

typedef struct st {
	int index;
	char name[21];
	struct st* next;
}POKEMON;

POKEMON HASH_TABLE[MAX_TABLE];
POKEMON POOL[100000 + 5000];

int pcnt;
int i = 1;

POKEMON ARR[100000 + 5000];

ull hash(const char* str) // reference code 참조
{
	ull hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}

void mystrcpy(char* a, const char* b) { // 암기. 직접 구현 필요
	while (*a++ = *b++);
}

int mystrcmp(const char* a, const char* b) { // 암기. 직접 구현 필요
	while (*a && *a == *b) ++a, ++b;
	return *a - *b;
}

int change(char* str)
{
	int i, len;
	int sum, mul;

	sum = 0;
	mul = 1;

	for (i = 0; str[i]; i++);
	len = i;

	for (i = len - 1; i >= 0; i--)
	{
		sum += (str[i] - '0') * mul;
		mul *= 10;
	}

	return sum;
}

int main(void) {

	char str[21];

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%s", str);

		ull h = hash(str);
		POKEMON* nd = &POOL[pcnt++];

		nd->index = i;
		mystrcpy(nd->name, str);

		nd->next = HASH_TABLE[h].next;
		HASH_TABLE[h].next = nd; /* name에 해당하는 key에 연결 */

		mystrcpy(ARR[i].name, str); /* 순서대로 저장 */
	}

	for (int i = 0; i < M; i++)
	{
		scanf("%s", str);

		if ('0' < str[0] && str[0] <= '9')
		{
			int index = change(str);

			printf("%s\n", ARR[index].name); /* ARR에 순서대로 저장했기 때문에 그대로 출력 */
		}
		else
		{
			ull h = hash(str);
			POKEMON* nd = HASH_TABLE[h].next;

			while (nd)
			{
				if (!mystrcmp(nd->name, str))
				{
					printf("%d\n", nd->index);
					break;
				}

				nd = nd->next;
			}
		}
	}

	return 0;

}