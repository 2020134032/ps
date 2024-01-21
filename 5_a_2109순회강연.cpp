#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;


int n;
priority_queue <int, vector<int>, greater<int>> pq;

int main() {
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0;i < n;i++) {
		int money, day;
		cin >> money >> day;
		v.push_back({ day, money });
	}
	sort(v.begin(), v.end());

	int sum = 0;

	for (int i = 0; i < v.size();i++) {

		sum += v[i].second;
		pq.push(v[i].second);
		if (pq.size() > v[i].first) {
			sum -= pq.top();
			pq.pop();
		}

	}
	cout << sum;
	return 0;
}