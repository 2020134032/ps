#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int isPalindrome(string a) {
	if (a.length() == 0 || a.length() == 1)
		return 1;
	for (int i = 0; i < a.length() / 2; i++) {
		if (a[i] != a[a.length() - 1 - i]) {
			return 0;
		}
	}
	return 1;
}
int main() {
	string a;

	getline(cin, a);
	while(a != "0") {
		
		if (isPalindrome(a)) {
			cout << "yes" << endl;
		}
		else
			cout << "no" << endl;
		getline(cin, a);
	}
	return 0;
}