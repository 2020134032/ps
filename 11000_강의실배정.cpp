#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct compare1 {
	bool operator()(pair<int, int> x, pair<int,int> y) {
		if (x.first < y.first) {
			return false;
		}
		else if (x.first == y.first && x.second < y.second) return false;
		else return true;
	}
};
struct compare2 {
	bool operator()(pair<int, int> x, pair<int, int> y) {
		if (x.second < y.second) {
			return false;
		}
		else return true;
	}
};

priority_queue< pair<int, int> , vector<pair<int, int>>, compare1> h;
priority_queue< pair<int, int> , vector<pair<int, int>>, compare2> rooms;
int main() {
	int N;
	int res = 1;
	cin >> N;
	for (size_t i = 0; i < N; i++) {
		pair<int, int> temp;
		cin >> temp.first >> temp.second;
		h.push(temp);
	}

	rooms.push(h.top());
	h.pop();
	for (int i = 1; i < N; i++) {
		if (rooms.top().second <= h.top().first) {
			rooms.pop();
			rooms.push(h.top());
			h.pop();
		}
		else {
			res++;
			rooms.push(h.top());
			h.pop();
		}
	}

	cout << res << endl;



	return 0;
}