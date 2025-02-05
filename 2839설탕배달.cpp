#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	// 3 - 1 0
	// 4 - 0
	// 5 - 0 1
	// 6 - 2
	// 7 - 0
	// 8 - 1 1
	// 9 - 3
	// 10 - 

	int a[5001];
	for (size_t i = 0; i < 5001; i++) {
		a[i] = -1;
	}

	a[3] = 1; 
	a[5] = 1;
	a[6] = 2; 
	a[8] = 2;
	a[9] = 3;
	a[10] = 2;
	a[11] = 3;
	a[12] = 4;

	for (size_t i = 13; i <= N; i++) {
		if (i % 15 == 0) {
			a[i] = i / 15 * 3;
			continue;
		}
		a[i] = a[i - 3] < a[i - 5] ? a[i - 3] + 1 : a[i - 5] + 1;
	}

	cout << a[N] << endl;

	return 0;
}