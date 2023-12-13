#include <iostream>
#include <vector>
using namespace std;

int N, L, R, A[55][55], visited[55][55];
int result;
int dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1};

int main() {

	cin >> N>> L>> R;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> A[i][j];
		}
	} //

	for (int y = 0;y < N;y++) {
		for (int x = 0;x < N;x++) {
			if()
			dfs(y,x)
		}
	} //

	return 0;
}