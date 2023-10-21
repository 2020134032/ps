#include <iostream>
#include <vector>
using namespace std;

const int n = 100;
char a[n][n];
int visited[n][n], N,M;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

void go(int y, int x, int depth) {
	depth++;
	visited[y][x] = depth;
	cout << "y:" << y << " x: " << x << " depth:" << depth<< endl;
	for (int i = 0; i < 4; i++) {
		int ny, nx;
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (a[ny][nx] == '0') continue;
		if (visited[ny][nx]) continue;
		go(ny, nx, depth);

	}
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0; j < M;j++) {
			cin >> a[i][j];//char character"1"
		}
	}
	go(0, 0,0);
	cout << visited[N-1][M-1] << endl;
	return 0;
}
