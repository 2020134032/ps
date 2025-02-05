#include <iostream>
using namespace std;

bool map[5][5];
int dy[] = {-2,-2,-1, 1, 2,2,1,-1};
int dx[] = {-1, 1, 2, 2,1,-1,-2,-2 };

int main() {
	char c;
	int res = 0;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {

			cin >> c;
			if (c == 'k') {
				res++;
				if (map[y][x]) { cout << "invalid"; return 0; }
				map[y][x] = true;
				for (int i = 0; i < 8; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
					map[ny][nx] = true;
				}
			}
		}
	}
	if (res == 9) cout << "valid";
	else cout << "invalid";
	return 0;
}