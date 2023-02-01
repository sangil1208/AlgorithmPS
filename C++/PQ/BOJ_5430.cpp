/*
reverse ������ ���̺귯���� �ݺ������� ó������ �ʰ�,
�ð� ���Ҹ� ���� deque �ڷᱸ��(��) �� �̿��Ͽ� reverse�� ���� ��� �տ��� ����/�ڿ��� ���� ���⸸ �ٲ��ֵ��� �Ѵ�.
���� ����µ� delete�� �õ��ϸ� error���, ���� ����µ� delete�� �õ����� ������ �� �� []�� ����ϴ� ó���� �����Ѵ�.
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