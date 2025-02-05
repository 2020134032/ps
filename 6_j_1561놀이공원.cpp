#include <iostream>
using namespace std;

long long ride[10001];
int main() {
	long long N, M;
	cin >> N >> M;
	if (N <= M) { cout << N; return 0; }

	for (int i = 0; i < M; i++) {
		cin >> ride[i];
	}

	long long l = 0, r = N * 30;
	while (l < r) {
		long long mid = (l + r) / 2;
		long long sum = M;
		for (int i = 0; i < M; i++) {
			sum += mid / ride[i];
		}
		if (N <= sum) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	} // r == m
	long long sum = M;
	for (int i = 0; i <M ; i++) {
		sum += (r - 1) / ride[i];
	}
	for (int i = 0; i < M; i++) {
		if (r % ride[i] == 0) {
			sum++;
			if (sum == N) {
				cout << i + 1; return 0;
			}
		}
	}
	//return 0;
}
