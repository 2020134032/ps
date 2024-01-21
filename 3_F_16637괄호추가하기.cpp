#include <iostream>
#include <vector>
#include<string>
using namespace std;

vector<int> num;
vector<char> op;
int N, res = -1e8;
string s;

int calc(int b, int c, char a) {
	if (a == '+') return b + c;
	if (a == '-') return b - c;
	if (a == '*') return b * c;
}

void go(int index, int sum) {
	if (index == op.size()) {
		res = sum > res ? sum : res;
		return;
	}
	go(index + 1, calc(sum, num[index + 1], op[index]));
	if (index + 2 <= op.size()) {
		int temp = calc(num[index + 1], num[index + 2], op[index + 1]);
		go(index + 2, calc(sum, temp, op[index]));
	}
}
int main() {
	cin >> N;
	cin >> s;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) num.push_back(s[i] - '0');
		else op.push_back(s[i]);
	}
	go(0, num[0]);
	cout << res;
	return 0;
}