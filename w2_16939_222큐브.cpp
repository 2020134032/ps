#include <iostream>
using namespace std;

int U[4][3] = { {3,14,5},{4,6,17},{2,18,21},{1,22,13} };
int F[4][3] = { {5,3,14},{7,16,9},{8,10,19},{6,17,4} };
int R[4][3] = { {17,4,6},{19,8,10},{20,12,23},{18,21,2} };

int c[24];
void editminus1(int a[][3]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] -= 1;
		}
	}
}

void go(int a[][3]) {
	for (int i = 0; i < 4; i++) {
		int temp0[3] = { c[a[0][0]],c[a[0][1]],c[a[0][2]] };
		for (int j = 0; j < 3; j++) {
			c[a[j][0]] = c[a[j + 1][0]];
			c[a[j][1]] = c[a[j + 1][1]];
			c[a[j][2]] = c[a[j + 1][2]];
		}
		c[a[3][0]] = temp0[0];
		c[a[3][1]] = temp0[1];
		c[a[3][2]] = temp0[2];
		/*debug
		//cout << "\n"<<i<<" ";
		//for (int p = 0; p < 24; p++) {
		//	cout << c[p] << " ";
		}*/
		// one turn
		if (i == 0 || i == 2) {
			int fla = 0;
			//check
			for (int k = 0; k < 24; k += 4) {
				if (c[k] != c[k + 1] || c[k + 1] != c[k + 2] || c[k + 2] != c[k + 3]) {
					fla = 1;
					break;
				}
			}
			if (fla == 0) {
				cout << "1"; exit(0);
			}
		}
	}
}
	
	int main() {
		for (int i = 0; i < 24; i++) {
			cin >> c[i];
		}
		editminus1(U);editminus1(F);editminus1(R);
		go(U);
		go(F);
		go(R);
	
		cout << 0;
		return 0;
	}