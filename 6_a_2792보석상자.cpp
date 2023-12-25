#include <iostream>
using namespace std;

int n, m, vmax = 0, mval[300'001];
int low = 1, high;

bool check(int mid) {
	int need = 0;
	for (int i = 0; i < m;i++) {
		// (x + (y-1)) / y 
		// 는 simple division ceiling function for positive nums.
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

	/* 이분탐색: 1과 가장 높은 mval 사이에서 답이 있다고 유추하고,
	그 값을 각각의 mval으로 나누면 필요한 인원수가 나오는데
	n 이 필요한 인원수보다 크면 (true라는 것은 mid값으로 가능하다는 뜻)
	high를 줄여서 더 작은 값으로도 가능한지 확인
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