#include<iostream>
using namespace std;

int N;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int minheight = 100, maxheight = 0;
int** map;
int** visit;

void dfs(int y, int x, int threshold) {
	visit[y][x] = 1;
	for (int j = 0;j < 4;j++) {
		int ny = y + dy[j];
		int nx = x + dx[j];
		if (ny<0 || nx<0 || ny>=N || nx>=N || map[ny][nx] <= threshold) continue;
		if (visit[ny][nx]) continue;
		dfs(ny, nx, threshold);
	}
}

void reset(int** a, int n) {
	for (int i = 0;i < n;i++) {
		for (int j=0; j < n; j++) {
			a[i][j] = 0;
		}
	}
}

int main() {
	cin >> N;

	map = new int*[N];
	visit = new int*[N];

	int minheight=100, maxheight=1;

	for (int i = 0;i < N;i++) {

		int* col = new int[N];
		int* v = new int[N];
		for (int j = 0; j < N;j++) {
			char temp;
			cin >> temp;
			col[j] = temp - '0';
			minheight = minheight< col[j] ? minheight : col[j];
			maxheight = maxheight> col[j] ? maxheight : col[j];
			v[j] = 0;

		}
		map[i] = col;
		visit[i] = v;
	}

	int maxres = 0;
	cout << minheight << " " << maxheight;
	for (int i = minheight; i < maxheight;i++) {

		int tempres = 0;
		reset(visit,N);
		for (int y = 0;y < N;y++) {
			for (int x = 0;x < N;x++) {
				if (map[y][x] > i && !visit[y][x]) {
					dfs(y, x,i);
					tempres++;
				}
			}
		} 
		cout << "maxres:" << maxres << " tempres: " << tempres << endl;
		maxres = maxres > tempres ? maxres : tempres;
		
	}
	
	cout << maxres<<endl;





	return 0;
}