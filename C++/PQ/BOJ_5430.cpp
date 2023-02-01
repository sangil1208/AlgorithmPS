/*
reverse 동작을 라이브러리나 반복문으로 처리하지 않고,
시간 감소를 위해 deque 자료구조(덱) 을 이용하여 reverse가 나올 경우 앞에서 제거/뒤에서 제거 방향만 바꿔주도록 한다.
덱이 비었는데 delete를 시도하면 error출력, 덱이 비었는데 delete를 시도하지 않으면 빈 덱 []를 출력하는 처리를 주의한다.
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int t;
	cin >> t;
	cin.ignore();

	for (int i = 0; i < t; i++) {
		string command;
		cin >> command;
		cin.ignore();

		int n;
		cin >> n;
		cin.ignore();

		string s;
		deque<int> dq;

		cin >> s;
		cin.ignore();

		string tmp = "";

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ',' || s[i] == ']') {
				if (tmp.size() != 0) {
					dq.push_back(stoi(tmp));
					tmp = "";
				}
			}
			else
				if (s[i] != '[')
					tmp += s[i];
		}

		int reverse = 0;
		int flag = 0;

		for (int i = 0; i < command.size(); i++) {
			if (command[i] == 'R') {
				if (reverse == 0)
					reverse = 1;
				else
					reverse = 0;
			}
			else {
				if (dq.size() == 0) {
					cout << "error" << endl;
					flag = 1;
					break;
				}
				if (reverse == 1) {
					dq.pop_back();
				}
				else {
					dq.pop_front();
				}
			}
		}

		if (flag == 1)
			continue;

		string result = "[";

		if (dq.size() == 0) {
			cout << "[]" << endl;
			continue;
		}

		if (reverse == 1) {
			for (int i = dq.size() - 1; i >= 0; i--) {
				int dq_tmp = dq[i];
				result += to_string(dq_tmp);
				if (i == 0)
					result += ']';
				else
					result += ',';
			}
		}
		else {
			for (int i = 0; i < dq.size(); i++) {
				int dq_temp = dq[i];
				result += to_string(dq_temp);
				if (i == dq.size() - 1)
					result += ']';
				else
					result += ',';
			}
		}

		cout << result << endl;
	}

	return 0;

}