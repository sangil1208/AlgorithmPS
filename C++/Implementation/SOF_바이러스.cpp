#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	long long k;
	long long p;
	long long n;

	cin >> k >> p >> n;

	n = n;

	long long result;
	result = k;

	for (long long i = 0; i < n; i++) {
		result = (result * p) % 1000000007;
	}

	cout << result % 1000000007;

	return 0;
}