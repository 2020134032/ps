#include<iostream>
#include<string>
using namespace std;
int main() {
	int res[27] = {0};
	string S;
	cin >> S;
	for (int c : S) {	
		res[c - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << res[i] << " ";
	}


	return 0;
}