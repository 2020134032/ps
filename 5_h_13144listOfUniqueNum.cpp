#include <iostream>
using namespace std;

bool set[100'001];
int num[100'001];

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	int lo = 0, hi = 0;
	long long res = 0;

	while (hi<N) {
		/*if (hi == N) {
			long long t = hi - lo;
			res += t * (t + 1) / 2;
			break;
		}*/
		if (!set[num[hi]]) {
			set[num[hi]] = 1;
			hi++; 
		}
		else {
			//hi--;
			//set[num[hi]] = 0;
			res += hi - lo;
			set[num[lo]] = 0;
			lo++;
			//hi = lo > hi ? lo : hi;
		}
	}
	long long t = hi - lo;
	res += t * (t + 1) / 2;

	cout << res;

	return 0;
}