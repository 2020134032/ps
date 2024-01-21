#include<iostream>
using namespace std;

int N, res;
bool cn[4000'001];
int prime[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cn[0] = cn[1] = true;
	for (int i = 4; i < N + 1; i += 2) {
		cn[i] = true;
	}
	for (int i = 3; i*i< N+1; i += 2) {
		if (cn[i]) continue;
		for (int j = i*i; j <= N; j+= 2*i) {
			cn[j] = true;
		}
	}
	/// collecting primes
	int ii=0;
	for (int i = 2; i <= N; i++) {
		if (!cn[i]) prime[ii++] = i;
	} // [0] [1] [2] <-- ii== 2
	  //  2   3  
	int hi = 0, lo = 0, sum = 0;

	while (true) {
		if (hi == ii+1) break;
		else if(sum < N) {
			sum += prime[hi++];
		}
		else if (sum == N) {
			res++; sum += prime[hi++];
		}
		else { sum -= prime[lo]; lo++; }
		
	}
	cout << res;
	return 0;
}