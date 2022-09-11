#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char** argv) {

	int n, k;
	cin >> n >> k;

	vector<int> grade;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		grade.push_back(temp);
	}

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		int sum = accumulate(grade.begin() + a - 1, grade.begin() + b, 0);
		float result = float(sum) / (b - a + 1);
		printf("%.2f\n", result);
	}

	return 0;
}