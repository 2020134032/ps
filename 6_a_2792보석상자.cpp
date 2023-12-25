#include <iostream>
using namespace std;

int n, m, vmax = 0, mval[300'001];
int low = 1, high;

bool check(int mid) {
	int need = 0;
	for (int i = 0; i < m;i++) {
		// (x + (y-1)) / y 
		// �� simple division ceiling function for positive nums.
		need += (mval[i] + mid - 1) / mid;
	}
	return n >= need;


}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> mval[i];
		vmax = mval[i] > vmax ? mval[i] : vmax;
	}
	high = vmax;
	int res;

	/* �̺�Ž��: 1�� ���� ���� mval ���̿��� ���� �ִٰ� �����ϰ�,
	�� ���� ������ mval���� ������ �ʿ��� �ο����� �����µ�
	n �� �ʿ��� �ο������� ũ�� (true��� ���� mid������ �����ϴٴ� ��)
	high�� �ٿ��� �� ���� �����ε� �������� Ȯ��
	*/
	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(mid)) {
			high = mid - 1;
			res = mid;
		}
		else {
			low = mid + 1;
		}
	}

	cout << res;

	return 0;
}