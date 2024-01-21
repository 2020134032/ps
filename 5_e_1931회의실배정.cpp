#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int st, fin;
		cin >> st >> fin;
		v.push_back({ fin,st });
	}

	sort(v.begin(), v.end());
	int res = 0;
	int current = -1;
	for (int i = 0; i < N; i++) {
		if (current <= v[i].second) {
			res++;
			current = v[i].first;
		}
	}

	cout << res;
	return 0;
}