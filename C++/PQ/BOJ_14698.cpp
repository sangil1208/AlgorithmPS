#define MAX 66
#define mod 1000000007

#include <iostream>
#include <climits>

typedef long long int ll;

using namespace std;

ll heap[MAX];
int hn;

int isHighPri(ll a, ll b) {
	if (a < b) return 1;
	return 0;
}

void push(ll* heap, int& hn, ll x) {

	register ll tmp;

	heap[++hn] = x;

	for (register ll i = hn; i > 1; i /= 2) {
		if (isHighPri(heap[i / 2], heap[i])) break;
		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;
	}
}

ll pop(ll* heap, int& hn) {

	register ll tmp, ret;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn--] = LLONG_MAX;

	for (register int i = 1; i * 2 <= hn;) {
		if (isHighPri(heap[i], heap[i * 2]) && isHighPri(heap[i], heap[i * 2 + 1]))
			break;
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

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;

	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		hn = 0;

		for (register int i = 0; i < n; i++) {
			ll input;
			cin >> input;
			push(heap, hn, input);
		}

		ll res = 1;

		while (hn > 1) {
			ll first = pop(heap, hn);
			ll second = pop(heap, hn);
			res *= (first * second) % mod;
			push(heap, hn, first * second);
			res %= mod;
		}

		cout << res << '\n';
	}

	return 0;
}