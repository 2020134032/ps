#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

int N, L, R, A[50][50], visit[50][50];
int res = 0;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int sum = 0;
vector<pair<int, int>> v;

void dfs(int a, int b) {
	visit[a][b] = 1;
	v.push_back({ a,b });
	sum += A[a][b];
	for (int i = 0; i < 4; i++){
		int na = a + dy[i];
		int nb = b + dx[i];
		if (na < 0 || nb < 0 || na >= N || nb >= N || visit[na][nb]) continue;
		int diff = abs(A[na][nb] - A[a][b]);
		if (L <= diff && diff <= R) {
			dfs(na, nb);
		}

	}
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> A[i][j];
		}
	}

	while (1) {
		int opened = 0;
		fill(&visit[0][0], &visit[0][0] + 50 * 50, 0);
		res++;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (!visit[y][x]) {
					sum = 0;
					v.clear();
					dfs(y, x);
					if (v.size() == 1) continue;
					int calc = sum / v.size();
					opened = 1;
					for (auto t : v) {
						A[t.first][t.second] = calc;
					}
				}
			}
		}

		if (!opened) break;
	}

	cout << res-1;
	return 0;
}