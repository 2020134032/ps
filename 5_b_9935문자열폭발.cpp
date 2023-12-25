#include <iostream>
#include <string>
using namespace std;

string input, target;

int main() {
	cin >> input >> target;

	int target_len = target.length();
	string res = "";
	for (int i = 0; i < input.length(); i++) 
	{
		res += input[i];
		if (input[i] == target[target_len - 1])
		{
			if (res.length() >= target_len)
			{
				int flag = 1;
				for (int j = 0; j < target_len; j++) 
				{
					if (target[target_len - 1 - j] != res[res.length() - 1 - j])
					{
						flag = 0;
						break;
					}
				}
				if(flag) res.erase(res.length() - target_len);
			}
		}
	}


	cout << (res.compare("") ? res : "FRULA");




	return 0;
}