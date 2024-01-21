#include <iostream>
using namespace std;

bool num[2000'001];

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		num[temp] = true;
	}
	int x; cin >> x;

	int res = 0;
	for (int i = 1; i < (x + 1) / 2; i++) {
		if (num[i] && num[x - i]) res++;
	}
	cout << res;


	return 0;
}