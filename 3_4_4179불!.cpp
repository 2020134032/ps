#include <iostream>
#include <queue>
using namespace std;
struct A {
	int first, second;
	bool fire;
};

int R, C;
const int MM = 1000;
int visit[MM][MM];
int player[MM][MM];
int alive = 1;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

queue<A> q;
int bfs(int a, int b, bool fire) {
	int res = 0;
	visit[a][b] = 1;
	player[a][b] = true;
	if (q.empty()) q.push({ a,b,false });
	while (!q.empty()) {
		res++;
		
		bool isPlayer = false;
		if (player[a][b]) {
			isPlayer = true;
			if (fire) {
				res--;
				a = q.front().first; b = q.front().second; fire = q.front().fire;
				q.pop();
				continue;
			}
		}
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
				player[na][nb] = player[a][b] +1;
				alive++; q.push({ na,nb,false });
			}
			else { //fire
				if (!visit[na][nb] || player[na][nb]) {
					if (player[na][nb]) {
						player[na][nb] = 0;
						alive--;
					}
						q.push({ na,nb,true });
					if (alive <= 0) return -1;
				}
			}
		}
		a = q.front().first; b = q.front().second; fire = q.front().fire;
		q.pop();
	}
	return -1;

}
int main() {
	cin >> R >> C;
	A start;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char temp;
			cin >> temp;
			if (temp == '#') visit[i][j] = 1;
			else if	(temp == 'F') {
				q.push({ i,j,true });
				visit[i][j] = 1;
			}
			
			else if (temp == 'J') start = { i,j,false };
		}
	}

	int res = bfs(start.first, start.second, false);

	if (res == -1) cout << "IMPOSSIBLE";
	else cout << res;


	return 0;
}