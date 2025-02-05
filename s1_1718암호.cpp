#include <iostream>
using namespace std;
//³À´Ù ¤§ ¸¸µé±â

bool pat[20][20];
int n, m, baseblack,black,white;
int res = 1e8;
int a, b;
void generate(int k) {
	for (int y = 0; y + k * 3 - 1 < n; y++) {
		for (int x = 0; x + k*3-1 < m; x++) {
			black = white = 0;

			
			for (int i = y; i < y+k*3; i++) {
				for (int j = x; j < x+k*3; j++) {
					if (!pat[i][j]) white++;
				}
			}// white -> black
			int blackinsquare = 9 * k * k - white;
			for (int i = y+k; i < y + k * 2; i++) {
				for (int j = x+k; j < x + k * 3; j++) {
					if (pat[i][j]) { black++;  }
				}
			}
			white-= (2 * k * k - black); // ¾È ¹Ù²ãµµ µÆ¾úÀ» Áßº¹Á¦°Å 
			
			int cost = white * a + (black + baseblack - blackinsquare) * b;
			res = res < cost ? res : cost;
		}
	}
}

int main() {
	cin >> n >> m >> a >> b;
	int smaller = n < m ? n : m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			cin >> temp;
			if (temp == '#') {
				pat[i][j] = true;
				baseblack++;
			}
			else pat[i][j] = false;
		}
	}
	for (int i = 1; i * 3 <= smaller;i++) {
		generate(i);
	}
	cout << res;

	return 0;
}