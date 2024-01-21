#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());

	int res = 0;
	int head = v[0].first;
	int tail = v[0].second;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first <= tail) {
			tail = tail > v[i].second ? tail : v[i].second;
		}
		else {
			res += tail - head;
			head = v[i].first;
			tail = v[i].second;
		}
	}
	res += tail - head;
	cout << res;
	return 0;
}