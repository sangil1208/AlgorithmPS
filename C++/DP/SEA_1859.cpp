/* #include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <cstdio>

using namespace std;

int t;

int main(void){
    cin >> t;

    while(t>0){
        int n;
        int res = 0;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i<n ; i++){
            scanf("%d", &v[i]);
        }

        int start = 0;
        int max_index = max_element(v.begin(), v.end()) - v.begin();
        int max = *max_element(v.begin(), v.end());

        while(1){

            for (int i = start; i<max_index; i++){
                res += v[max_index]-v[i];
            }

            v[max_index] = 0;

            start = max_index+1;
            max_index = max_element(v.begin(), v.end()) - v.begin();
            max = *max_element(v.begin(), v.end());

            if (max <= v[max_index+1]){
                break;
            }
        }

        t--;
        cout << res;
    }
    return 0;

} */

#include <iostream>
#include <algorithm>

using namespace std;

int* a;
pair<int, int>* b;
int* c;
int n, m;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력받기
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a, a + n);

	cin >> m;
	c = new int[m] {0, };
	b = new pair<int,int>[m];
	for (int i = 0; i < m; ++i) {
		cin >> b[i].first;
		b[i].second = i;
	}

	sort(b, b + m);

	//계산하기
	int j = 0;
	for (int i = 0; i < m; ++i) {
		if (i > 0 && b[i].first == b[i - 1].first) {
			c[b[i].second] = c[b[i - 1].second];
			continue;
		}

		while (j < n && b[i].first > a[j]) {
			++j;
		}
		while (j < n && b[i].first == a[j]) {
			++j;
			++c[b[i].second];
		}
	}

	//출력하기
	for (int i = 0; i < m; ++i) {
		cout << c[i] << ' ';
	}

	return 0;
}