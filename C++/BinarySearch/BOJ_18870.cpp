/*
몇 번째로 큰 수 인지 확인하기 위해, 정렬 후 각 값에 대해 index를 확인하는 작업은 이중 for문으로 n^2시간복잡도이다.
하지만 n이 백만이므로, n^2 알고리즘으로는 통과할 수 없다.

따라서 정렬 후, 정렬 전 각 요소에 대해 정렬된 배열에서 몇 번째 있는지 확인하기 위해 이진 탐색을 사용한다.
이진 탐색은 탐색 대상 배열이 정렬되어 있을때만 사용 가능하며, logN의 복잡도를 가진다.
따라서 모든 요소에 대해 탐색을 수행해도, N*logN으로 n=1000000에 대해서도 통과할 수 있다.

정렬 후 같은 값이 여러개라면, 몇 번째인지 확인하는데 오류가 생길 수 있다. EX) 0 0 0 0 1 1 1 1이라면, 1이 다섯번째라고 판단되지만 사실 두번째로 큰 수이다.
따라서 정렬 후, 중복값을 제거 한 후 이진탐색을 수행한다.

벡터 정렬은 sort(v.begin(), v.end())로 수행하며
중복값 제거는 v.erase(unique(v.begin(), v.end()), v.end())로 수행한다.
unique를 수행하면 제거된 중복값인 쓰레기값이 벡터 뒤에 append된다. unique함수는 쓰레기값의 초기 위치를 반환한다.
따라서 쓰레기값의 초기 위치부터 쓰레기값의 끝까지 지워주는 작업을 통해 중복값을 제거할 수 있다.

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