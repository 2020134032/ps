#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

const int n = 100;
char a[n][n];
int visited[n][n], N,M;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

void bfs(int y, int x) {
	visited[y][x] = 1;
	
	queue<pair<int, int>> q;
	q.push({y,x});
	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny, nx;
			ny = y + dy[i];
			nx = x + dx[i];
		
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue; //항상 오버플로 부터 체크하고, 갈수 있는지 없는지 판단할것
			if (a[ny][nx] == '0') continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	

	}
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0; j < M;j++) {
			cin >> a[i][j];//char character"1"
		}
	}
	bfs(0, 0);
	cout << visited[N-1][M-1] << endl;
	return 0;
}
