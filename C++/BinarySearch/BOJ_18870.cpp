/*
�� ��°�� ū �� ���� Ȯ���ϱ� ����, ���� �� �� ���� ���� index�� Ȯ���ϴ� �۾��� ���� for������ n^2�ð����⵵�̴�.
������ n�� �鸸�̹Ƿ�, n^2 �˰������δ� ����� �� ����.

���� ���� ��, ���� �� �� ��ҿ� ���� ���ĵ� �迭���� �� ��° �ִ��� Ȯ���ϱ� ���� ���� Ž���� ����Ѵ�.
���� Ž���� Ž�� ��� �迭�� ���ĵǾ� �������� ��� �����ϸ�, logN�� ���⵵�� ������.
���� ��� ��ҿ� ���� Ž���� �����ص�, N*logN���� n=1000000�� ���ؼ��� ����� �� �ִ�.

���� �� ���� ���� ���������, �� ��°���� Ȯ���ϴµ� ������ ���� �� �ִ�. EX) 0 0 0 0 1 1 1 1�̶��, 1�� �ټ���°��� �Ǵܵ����� ��� �ι�°�� ū ���̴�.
���� ���� ��, �ߺ����� ���� �� �� ����Ž���� �����Ѵ�.

���� ������ sort(v.begin(), v.end())�� �����ϸ�
�ߺ��� ���Ŵ� v.erase(unique(v.begin(), v.end()), v.end())�� �����Ѵ�.
unique�� �����ϸ� ���ŵ� �ߺ����� �����Ⱚ�� ���� �ڿ� append�ȴ�. unique�Լ��� �����Ⱚ�� �ʱ� ��ġ�� ��ȯ�Ѵ�.
���� �����Ⱚ�� �ʱ� ��ġ���� �����Ⱚ�� ������ �����ִ� �۾��� ���� �ߺ����� ������ �� �ִ�.

*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> a;
vector<int> a_sorted;

int binarySearch(vector<int>& arr, int target, int start, int end) {
	if (start > end) return -1;
	int mid = (start + end) / 2;
	if (arr[mid] == target) return mid;
	else if (arr[mid] > target) return binarySearch(arr, target, start, mid - 1);
	else return binarySearch(arr, target, mid + 1, end);
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
		a_sorted.push_back(x);
	}

	sort(a_sorted.begin(), a_sorted.end());
	a_sorted.erase(unique(a_sorted.begin(), a_sorted.end()), a_sorted.end());


	for (int i = 0; i < a.size(); i++) {
		cout << binarySearch(a_sorted, a[i], 0, a_sorted.size() - 1) << " ";
	}

	return 0;
}