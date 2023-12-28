#include<iostream>
#include<queue>
#include <utility>
using namespace std;
int Y, X, res=0;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int land[50][50] = {};


int bfs(int y, int x) {
	int visit[50][50] = {};
	visit[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y,x });
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int na = a + dy[i];
			int nb = b + dx[i];
			if (na < 0 || nb < 0 || na >= Y || nb >= X || !land[na][nb]) continue;
			if (!visit[na][nb]) {
				visit[na][nb] = visit[a][b] + 1;
				res = max(res, visit[na][nb]); //res is global
				q.push({ na,nb });
			}
		}

	}return res;
}

int main() {
	cin >> Y >> X;
	for (int i = 0; i < Y; i++){
		for (int j = 0; j < X; j++){
			char temp;
			cin >> temp;
			if (temp == 'L') {
				land[i][j] = 1;
			}
		}
	}//
	int res = 0;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (land[i][j]){
				bfs(i, j);
			}
		}
	}


cout << res - 1;



	return 0;
}