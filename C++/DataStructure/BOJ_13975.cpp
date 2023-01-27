#define _CRT_SECURE_NO_WARNINGS
#define HMAX 1000100

#include <iostream>

using namespace std;

typedef long long int ll;

int t;

ll heap[HMAX];
int hn;

void push(ll* heap, int& hn, ll x) {
	heap[++hn] = x;

	for (register int i = hn; i > 1; i /= 2) {

		if (heap[i] >= heap[i / 2]) break;

		else {
			ll tmp;
			tmp = heap[i / 2];
			heap[i / 2] = heap[i];
			heap[i] = tmp;
		}
	}
}

ll pop(ll* heap, int& hn) {
	ll ret, tmp;
	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn--] = 0x7fffffffffffffff;

	for (register int i = 1; i * 2 <= hn;) {

		if ((heap[i] < heap[i * 2]) && (heap[i] < heap[i * 2 + 1])) break;

		else {
			if (heap[i * 2] < heap[i * 2 + 1]) {
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
	}

	return ret;
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> t;

	for (register int i = 0; i < t; i++) {

		hn = 0;
		int k;

		cin >> k;

		for (register int i = 0; i < k; i++) {

			int input;

			cin >> input;

			push(heap, hn, input);
		}


		ll pair = 0;
		ll pairsum = 0;
		ll sum = 0;

		while (hn > 0) {
			if (pair != 2) {
				pairsum += pop(heap, hn);
				pair += 1;
			}
			if (pair == 2) {
				sum += pairsum;
				pair = 0;
				push(heap, hn, pairsum);
				pairsum = 0;
			}
		}

		cout << sum << '\n';
	}

	return 0;
}