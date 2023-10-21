#include <iostream>
#include <vector>
using namespace std;

const int n = 3;
int a[n][n], visited[n][n];

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

void go(int y, int x) {
	visited[y][x] = 1;
	cout << "y:" << y << " x: " << x << endl;
	for (int i = 0; i < 4; i++) {
		int ny, nx;
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (a[ny][nx] == 0) continue;
		if (visited[ny][nx]) continue;
		go(ny, nx);

	}
}

/*void dfs(int u) {
	visited[u] = 1;
	for( int i : adj[u]){
		if (visited[i]==0){
			dfs(i)
		}
}*/

int main() {
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < n;j++) {
			cin >> a[i][j];
		}
	}
	go(0, 0);
	return 0;
}
