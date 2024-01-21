#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int N;

int main() {
	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int arrive, dur;
		cin >> arrive >> dur;
		v.push_back({ arrive,dur });
	}

	sort(v.begin(), v.end());

	int sum = 0;

	for (int i = 0; i < v.size(); i++) {
		if (sum < v[i].first) {
			sum = v[i].first + v[i].second;
			continue;
		}
		else {
			sum += v[i].second;
		}
	}

	cout << sum;
}