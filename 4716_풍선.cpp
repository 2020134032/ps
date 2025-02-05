#include <iostream>
#include <queue>

using namespace std;

int res = 0;

struct st {
	int k;
	int da;
	int db;
	int diff;
};

struct compare {
	bool operator() (st first, st second) {
		if (first.diff > second.diff) return false;
		else return true;
	}
};



int main(){
	int N=1, A=1, B =1;
	cin >> N >> A >> B;
	while (N != 0 || A != 0 || B != 0) {
		res = 0;
		priority_queue<st, vector<st>, compare> heap;
		

		for (size_t i = 0; i < N; i++) {
			st temp;
			cin >> temp.k >> temp.da >> temp.db;
			temp.diff = temp.da - temp.db;
			if (temp.diff < 0) temp.diff = -temp.diff;
			heap.push(temp);
		}

		while (!heap.empty()) {
			st temp = heap.top();
			for (size_t i = 0; i < temp.k; i++) {
				if (temp.da < temp.db) {
					res += temp.da;
					A--;
					if (A < 0) res += temp.diff;
				}
				else {
					res += temp.db;
					B--;
					if (B < 0) res += temp.diff;
				}
			}
			

			heap.pop();
		}
		cout << res << endl;
		cin >> N >> A >> B;
	}




	return 0;
}
