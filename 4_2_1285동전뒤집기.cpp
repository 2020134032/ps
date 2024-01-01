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

	int res = 0;
	for (int i = 0; i < 1<<(2*N); i++) {
		int _res = 0;

		int flipped[40] = { 0 };
		for (int j = 0; j < 2*N; j++) {
			if (i & (1<<j)) flipped[j] = 1;
		}
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				int b = (flipped[y] + flipped[x+N] == 1 ? 1 : 0);
				_res += coin[y][x] ^ b;
				
				/*if (coin[y][x]) {
					if (b) continue;
					else _res++;
				}
				else {
					if (b) _res++;
					else continue;
				}*/
			}
		}
		res = res > _res ? res : _res;
	}
	cout << N*N - res;
	return 0;

}