#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int fact(int x) {
	if (x <= 1) return 1;
	return x * fact(x - 1);
}

int main(void) {

	int n, k;

	cin >> n >> k;

	int result;

	result = fact(n) / (fact(n - k) * fact(k));

	cout << result;

	return 0;

}