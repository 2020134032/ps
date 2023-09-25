#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();

	string str1,str2 ;
	getline(cin, str1, '*');
	getline(cin, str2);
	//cout << str1 << " " << str2;

	int str1len = str1.length();
	int str2len = str2.length();

	for (int i = 0; i < n;i++) {
		string input;
		//getline(cin, input);
		cin >> input;
		cin.ignore();
		if (input.length() < str1len +str2len) {
			cout << "NE\n";
		} 
		else if (input.substr(0, str1len) == str1 && input.substr(input.length() - str2len) == str2)
			cout << "DA\n";
		else
			cout << "NE\n";
	}


	return 0;
}