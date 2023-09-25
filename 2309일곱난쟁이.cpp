#include <iostream>
#include <algorithm>
using namespace std;

void result(int i, int j, int a[]) {
	for (int p = 0; p < 9;p++) {
		if (p == i || p == j) {
			continue;
		}
		else {
			cout << a[p] << '\n';
		}
	}

}

int main() {
	int nine[9];
	int sum = -100;
	for (int i = 0; i < 9;i++) {
		cin >> nine[i];
		sum += nine[i];
	}
	
	sort(nine, nine+9);

	for(int i = 0; i < 8;i++) {
		for (int j = i; j < 9; j++) {
			if (nine[i] + nine[j] == sum) {
				result(i, j,nine);
				return 0;
			}	
		}
	}


	return 0;
}