#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int R, C;
const int MM = 1000;
int visit[MM][MM];
int player[MM][MM];
bool p[MM][MM];
int alive = 1;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

queue<pair<int, int>> q;

int bfs(int a, int b) {
	visit[a][b] = 1;
	player[a][b] = 1;
	q.push({ a,b });
	bool wasP = false;
	while (!q.empty()) {
		a = q.front().first; b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int na = a + dy[i];
			int nb = b + dx[i];
			if (na < 0 || nb < 0 || na >= R || nb >= C) {
				if (player[a][b]) return player[a][b];
				else continue;
			}
			if (player[a][b]) {
				if (visit[na][nb]) continue;
				visit[na][nb] = 1;
				player[na][nb] = player[a][b] + 1;
				alive++; q.push({ na,nb });
				wasP = true;
			}
			else { //fire
				if (wasP && alive <= 0) return -1;
				wasP = false;
				if (!visit[na][nb] || player[na][nb]) {
					if (player[na][nb]) {
						p[na][nb] = true;
						alive--;
					}
						q.push({ na,nb });
						visit[na][nb] = 1;

				}
			}
		}
		if (wasP && player[a][b] && p[a][b]) player[a][b] = 0;

	}
	return -1;

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
	pair<int, int> start;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char temp;
			cin >> temp;
			if (temp == '#') visit[i][j] = 1;
			else if (temp == 'F') {
				q.push({ i,j });
				visit[i][j] = 1;
			}

			else if (temp == 'J') start = { i,j };
		}
	}

	int res = bfs(start.first, start.second);

	if (res == -1) cout << "IMPOSSIBLE";
	else cout << res;


	return 0;
}