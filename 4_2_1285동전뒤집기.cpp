#include<iostream>
using namespace std;

int N;
int coin[20][20];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;
			coin[i][j] = temp == 'H' ? 1 : 0;
		}
	} //

	int res = 1e9;
	for (int i = 0; i < 1<<N; i++) {

		int copy[20][20];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				copy[i][j] = coin[i][j];
			}
		}
		int _res = 0;

		for (int j = 0; j < N; j++) {
			if (i & 1 << j) {
				for (int y = 0; y <N; y++) copy[y][j] ^= 1; //flip
			}
		}
		for (int y = 0; y < N; y++) {
			int sum = 0;
			for (int x = 0; x < N; x++) {
				sum += copy[y][x];
			}
			_res += sum < N - sum ? sum : N - sum;
		}
		res = res < _res ? res : _res;
	}
	cout << res;
	return 0;

}