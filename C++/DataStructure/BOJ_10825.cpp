#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct st {
	char name[11];
	int kor;
	int eng;
	int math;
}STUDENT;

STUDENT Heap[100100];
int pcnt;

int hn;

int N;


int isHighPri(STUDENT stu1, STUDENT stu2) {
	if (stu1.kor != stu2.kor)
		if (stu1.kor < stu2.kor)
			return 0;
		else
			return 1;
	else {
		if (stu1.eng != stu2.eng)
			if (stu1.eng < stu2.eng)
				return 1;
			else
				return 0;
		else {
			if (stu1.math != stu2.math)
				if (stu1.math < stu2.math)
					return 0;
				else
					return 1;
			else {
				if (strcmp(stu1.name, stu2.name) > 0)
					return 0;
				else
					return 1;
			}
		}
	}

}

STUDENT pop(STUDENT* heap, int& hn) {
	register STUDENT tmp;
	register STUDENT ret;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn].kor = 0;
	heap[hn].eng = 0x7fff0000;
	heap[hn].math = 0;
	strcpy(heap[hn--].name, "zzzzzzzzzz");

	for (register int i = 1; i * 2 <= hn;) {
		if (isHighPri(heap[i], heap[i * 2]) && isHighPri(heap[i], heap[i * 2 + 1])) break;

		else if (isHighPri(heap[i * 2], heap[i * 2 + 1])) {
			tmp = heap[i * 2];
			heap[i * 2] = heap[i];
			heap[i] = tmp;

			i = i * 2;
		}

		else {
			tmp = heap[i * 2 + 1];
			heap[i * 2 + 1] = heap[i];
			heap[i] = tmp;

			i = i * 2 + 1;
		}
	}

	return ret;
}

void push(STUDENT* heap, int& hn, STUDENT x) {
	register STUDENT tmp;

	heap[++hn] = x;

	for (register int i = hn; i > 1; i /= 2) {
		if (isHighPri(heap[i / 2], heap[i])) break;

		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;
	}
}

int main(void) {
	scanf("%d", &N);

	for (register int i = 0; i < N; i++) {
		STUDENT x;
		int kor, eng, math;
		char str[11];

		scanf("%s %d %d %d", str, &kor, &eng, &math);

		x.kor = kor;
		x.eng = eng;
		x.math = math;
		strcpy(x.name, str);

		push(Heap, hn, x);
	}

	for (register int i = 0; i < N; i++) {
		STUDENT tmp = pop(Heap, hn);
		printf("%s\n", tmp.name);
	}

	return 0;
}