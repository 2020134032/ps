#include<iostream>
#include <string.h>
using namespace std;

int map[100][100], map2[100][100];
bool place[100][100];
int N, L;
int res = 0;

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			map2[j][i] = map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {

		int h = map[i][0];
		int l = 0;
		for (int j = 0; j < N; j++) {

			if (map[i][j] == h) {
				l++;
			}
			else if (map[i][j] == h + 1 && l >= L) {
				int flag = 0;
				for (int a = 0;a < L;a++) {
					if (place[i][j - 1 - a]) {
						flag = 1;
						break;
					}
					place[i][j - 1 - a] = 1;
				}
				l = 1;
				h += 1;
				if (flag) { break; }
			}
			else if (map[i][j] == h - 1 && j + L - 1 < N) {
				int check = 0;
				for (int a = 0; a < L; a++) {
					if (map[i][j + a] == h - 1) {
						check++;
					}
				}if (check == L) {
					for (int a = 0; a < L; a++) {
						place[i][j + a] = 1;
					}
					j += L - 1;
					h -= 1;
					l = 1;
				}
				else {
					break;
				}
			}
			else break;
			if (j == N - 1) {
				res++;break;
			}
		}
	}
	///
	memset(place, 0, sizeof(place));

	for (int i = 0; i < N; i++) {

		int h = map2[i][0];
		int l = 0;
		for (int j = 0; j < N; j++) {

			if (map2[i][j] == h) {
				l++;
				if (j == N - 1) {
					res++;break;
				}
			}
			else if (map2[i][j] == h + 1 && l >= L) {
				int flag = 0;
				for (int a = 0;a < L;a++) {
					if (place[i][j - 1 - a]) {
						flag = 1;
						break;
					}
					place[i][j - 1 - a] = 1;
				}
				l = 1;
				h += 1;
				if (flag) { break; }
				if (j == N - 1) {
					res++;break;
				}
			}
			else if (map2[i][j] == h - 1 && j + L - 1 < N) {
				int check = 0;
				for (int a = 0; a < L; a++) {
					if (map2[i][j + a] == h - 1) {
						check++;
					}
				}if (check == L) {
					for (int a = 0; a < L; a++) {
						place[i][j + a] = 1;
					}
					j += L - 1;
					h -= 1;
					l = 1;
					if (j == N - 1) {
						res++;break;
					}
				}
				else {
					break;
				}
			}
			else break;
		}
	}

	cout << res;
	return 0;
}