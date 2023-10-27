#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<vector<char>> map;
string result;

string go(int y, int x, int side) {
	if (side == 1) return string(1, map[y][x]);

	string s1, s2, s3, s4;

	int next = side / 2;

	s1 = go(y, x, side / 2);
	s2 = go(y, x + next, side / 2);
	s3 = go(y + next, x, side / 2);
	s4 = go(y + next, x + next, side / 2);
	if (s1.length() == 1 && s1 == s2 && s2 == s3 && s3 == s4) return s1;
	else return "(" + s1 + s2 + s3 + s4 + ")";

}



int main() {

	cin >> N;
	map.resize(N);
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < N; j++) {
			char t;
			cin >> t;
			map[i].push_back(t);
			
		}
	}

	cout << go(0,0,N);

	return 0;
}