#include <iostream>
using namespace std;

int a, b, c, N, M;
int map[300][300];
int res = 1e9;
int ad(int ii, int jj,int t) {
	int sum=0;
	if (t == 1) {
		for (int i = ii; i < ii+a; i++) {
			for (int j = jj; j < jj+b+c ; j++) {
				sum += map[i][j];
			}
		}
	}
	else if (t == 2) {
		for (int i = ii; i < ii+a ; i++) {
			for (int j = jj; j < jj + c; j++) {
				sum += map[i][j];
			}
		}
		for (int i = ii+a; i < ii + a+b; i++) {
			for (int j = jj+c; j < jj + c+a; j++) {
				sum += map[i][j];
			}
		}
	}
	else if (t == 3) {
		for (int i = ii; i < ii + a; i++) {
			for (int j = jj; j < jj + b; j++) {
				sum += map[i][j];
			}
		}
		for (int i = ii + a; i < ii + a + c; i++) {
			for (int j = jj + b; j < jj + b+a; j++) {
				sum += map[i][j];
			}
		}
	}
	return sum;
}
int main() {
	cin >> N >> M >> a >> b >> c;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i +a <= N ; i++) {
		for (int j = 0; j +b+c <=M ; j++) {
			int s = ad(i, j,1);
			res = res < s ? res : s;
		}
	}
	for (int i = 0; i + a+b <= N; i++) {
		for (int j = 0; j +a+c  <= M; j++) {
			int s = ad(i, j, 2);
			res = res < s ? res : s;
		}
	}
	for (int i = 0; i + a+c <= N; i++) {
		for (int j = 0; j + b+a <= M; j++) {
			int s = ad(i, j, 3);
			res = res < s ? res : s;
		}
	}
	cout << res;
}