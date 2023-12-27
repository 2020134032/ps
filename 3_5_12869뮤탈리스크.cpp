//#include <iostream>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//int res;
//int N, scv[3] = { 0,0,0 };
//int visited[61][61][61];
//
//
//int fact(const int n) {
//	if (n == 3) return 6;
//	else return n;//1,2,6
//}
//
//struct A {
//	int na, nb, nc;
//};
//queue<A> q;
//
//int solve(int scv[]) {
//	visited[0][0][0] = 1;
//	q.push({ 0,0,0 });
//	
//	int flag = 0;
//	while (q.size()){
//		int a = q.front().na;
//		int b = q.front().nb;
//		int c = q.front().nc;
//		q.pop();
//
//		int attack[] = { 1,3,9 };
//		for (int i = 0; i < fact(N);i++) {
//			int arr[3];
//			arr[0] = min(scv[2], a + attack[0]);
//			arr[1] = min(scv[1], b + attack[1]);
//			arr[2] = min(scv[2], c + attack[2]);
//			if (arr[0] >= scv[0] && arr[1] >= scv[1] && arr[2] >= scv[2]) {
//				return visited[a][b][c];
//			}
//			
//			if (visited[arr[0]][arr[1]][arr[2]]) continue;
//			visited[arr[0]][arr[1]][arr[2]] = visited[a][b][c] + 1;
//			q.push({ arr[0],arr[1],arr[2] });
//
//			next_permutation(attack, attack + 3);
//
//		}
//	}
//	return 0;
//
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	cin >> N;
//	for (int i = 0; i < N; i++) cin >> scv[i];
//	sort(scv, scv + 3);
//	cout << solve(scv) << "\n";
//	return 0;
//} nope

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



int go(int n, int one, int two, int three) {
	if (visited[one][two][three]) {
		return dp[one][two][three];
	}
	else if (one <= 1 && two <= 3 && three <= 9) {
		return visited[one][two][three] = dp[one][two][three] = 1;
	}

	int attack[] = { 1,3,9 };
	int minv = 981273645;
	for (int i = 0; i < fact(n);i++) {
		int arr[3];
		arr[0] = max(0, one - attack[0]);
		arr[1] = max(0, two - attack[1]);
		arr[2] = max(0, three - attack[2]);
		sort(arr, arr + 3);
		minv = min(minv, go(n, arr[0], arr[1], arr[2]) + 1);

		next_permutation(attack, attack + 3);
	}
	visited[one][two][three] = dp[one][two][three] = minv;
	return minv;



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
	}
	else {
		cout << go(3, scv[0], scv[1], scv[2]);
	}
	return 0;

}
