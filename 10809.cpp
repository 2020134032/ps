#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n = 26;
	int arr[n];
	for (int i = 0; i < n;i++) {
		arr[i] = -1;
	}

	string str;
	getline(cin,str);

	for (int i = 0; i < str.length(); i++) {
		int alphabet = str[i] - 'a';
		
		if (arr[alphabet] == -1) {
			arr[alphabet] = i;
		}
	}
	for (int i = 0;i < 26;i++) {
		cout << arr[i] << " ";
	}




	return 0;
}
