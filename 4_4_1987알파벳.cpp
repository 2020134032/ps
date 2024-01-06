#include <iostream>
using namespace std;

char rc[20][20];
int R, C, res;
int dy[] = {-1,0,1,0};
int dx[] = {0 ,1, 0 ,-1};
bool visit[26];


void dfs(int y, int x, int depth) {
	visit[(int)(rc[y][x] - 'A')] = true;
	res = res > depth ? res : depth;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0 || nx<0 || ny>=R || nx>=C) continue;
		if (visit[(int)(rc[ny][nx] - 'A')]) continue;
		dfs(ny, nx, depth + 1);
		visit[(int)(rc[ny][nx]-'A')] = false; //ฟ๘บน
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++){
			char temp;
			cin >> temp;
			rc[i][j] = temp;
		}
	}

	dfs(0, 0, 1);
	
	cout << res;
	return 0;
}