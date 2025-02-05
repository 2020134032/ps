#include <iostream>
#define MOD 1000000009

using namespace std;

/*
1 = 1 //1
2 = 2, 1+1 //2
3= 3, 2+1,1+2 , 1+1+1 // 4
4= 1+3, 3+1, 2+2 //7
5= 11111, 1112,1121,1211,2111,113,131,311,122,212,221,23,32// 13 7/6
*/

long long e[100'001] = {0};
long long o[100'001] = { 0 };

int main() {
	e[0] = 0;
	e[1] = 0;
	e[2] = 1;
	e[3] = 2;
	o[0] = 0;
	o[1] = 1;
	o[2] = 1;
	o[3] = 2;
	size_t T;
	cin >> T;
	int max = -1;
	int ar[100'000];
	for (size_t i = 1; i <= T; i++) {
		int n;cin >> n;
		ar[i] = n;
		if (n > max) max = n;
	}
	for (size_t i = 4; i <= max; i++) {
		o[i] = (e[i - 1] + e[i - 2] + e[i - 3]) % MOD;
		e[i] = (o[i - 1] + o[i - 2] + o[i - 3]) % MOD;
	}
	for (size_t i = 1; i <= T; i++) {
		int n = ar[i];
		cout << o[n] << " " << e[n] << '\n';
	}



	return 0;
}