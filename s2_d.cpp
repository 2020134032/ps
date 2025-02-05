#include <iostream>
#include <string.h>
using namespace std;
int T, N, M;
bool team[101];
int map[101][101];
int dy[] = { -1,0,1,0,-1,1,1,-1 }, dx[] = { 0,1,0,-1,1,1,-1,-1 };

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {//for
		int sum = 0;
		cin >> N >> M;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				cin >> map[y][x];
			}
		}
		//
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (map[y][x] != -1 && !team[map[y][x]]) {
					for (int k = 0; k < 8; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];

						if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
						if (map[y][x] == map[ny][nx]) {
							team[map[y][x]] = true;
							sum++;
							break;
						}
					}
				}
			}
		}
		memset(team, 0, sizeof(team));
		cout << sum << "\n";


	}
	return 0;
}