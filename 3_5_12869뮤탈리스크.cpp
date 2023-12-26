#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, visited[61][61][61], dp[61][61][61];
vector<int> scv;


int fact(const int n) {
	if (n == 3) return 6;
	else return n;
}



int go(int n, int one, int two, int three){
	//기저사례
	if (visited[one][two][three]) {
		return dp[one][two][three];
	}
	// 메모이제이션 체크
	else if (one <= 1 && two <= 3 && three <= 9) {
		return visited[one][two][three] = dp[one][two][three] = 1;
	}
	//로직
	int attack[] = { 1,3,9 };
	int minv = 981273645;
	for (int i = 0; i < fact(n);i++) {
		int arr[3];
		arr[0] = max(0, one - attack[0]);
		arr[1] = max(0, two - attack[1]);
		arr[2] = max(0, three - attack[2]);
		sort(arr, arr + 3);
		minv = min(minv, go(n, arr[0], arr[1], arr[2])+1);

		next_permutation(attack, attack + 3);
	}
	return visited[one][two][three] = dp[one][two][three] = minv;
	



}

int main() {
	visited[0][0][0] = 1;
	dp[0][0][0] = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		scv.push_back(temp);
	}

	if (N == 1) {
		cout << go(1, 0, 0, scv[0]);
	}
	else if (N == 2) {
		cout << go(2, 0, scv[0], scv[1]);
	}else {
		cout << go(3, scv[0], scv[1], scv[2]);
	}
	return 0;

}
