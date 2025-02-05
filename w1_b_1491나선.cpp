#include <iostream>
using namespace std;
int N, M;
int dx[] = { 1,0,-1,0 };
int dy[] = {0, 1, 0, -1};
bool map[5001][5001];

//a~x 24
int main() {
	cin >> N >> M;
	int limit = N * M;
	int i = 0;
	int x = 0, y = 0;
	
	while (limit--) {
		if (limit == 0) {
			break;
		}
		map[x][y] = true;
		i = i % 4;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny]) {
			i++;
			limit++;
			continue;
		}
		x = nx; y = ny;
	}
	cout << x << " " << y;



	return 0;
}