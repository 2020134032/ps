#include <iostream>
#include <string>
using namespace std;

int N;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {

		string ps;
		cin >> ps;

		int valid = 0;

		for (char& c : ps) {
			if (c == '(') valid++;
			else {
				valid--;
				if (valid < 0)
					break;
			}
		}
		if (valid == 0) cout << "YES\n";
		else cout << "NO\n";
	}


	return 0;
}