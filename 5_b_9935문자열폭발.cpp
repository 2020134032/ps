#include <iostream>
#include <string>
using namespace std;

string input,target;

int main() {
	getline(cin, input);
	getline(cin, target);

	string res = "";
	for(int i = 0; i< input.length(); i++){
		res += input[i];
		if (res.length() >= target.length()) {
			while (res.substr(res.length() - target.length()).compare(target) == 0) {
				res.replace(res.length() - target.length(), target.length(), "");
				if (res.length() < target.length()) break;
			}
		}
	}
	

	cout << (res.compare("") ? res:"FRULA");
	



	return 0;
}