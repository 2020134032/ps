#include<iostream>
using namespace std;

int T, map[51][51], K, M, N, X, Y;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
bool visited[51][51];

void dfs(int y, int x);
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		int	res = 0;
		fill(&map[0][0], &map[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++)
		{
			cin >> X >> Y;
			map[Y][X] = 1;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!visited[i][j] && map[i][j]) { //map ���鼭 �Ȱ����� üũ.
					res++;
					dfs(i, j);
				}
			}
		}

		cout << res<<"\n";
	}
	return 0;
}

void dfs(int y, int x) {
	// ������ visitüũ
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int  nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || !map[ny][nx]) continue; // 1 �迭 ���� ������
		if (visited[ny][nx]) continue; // �� ���� �ƴ���
		dfs(ny, nx);
	}
}