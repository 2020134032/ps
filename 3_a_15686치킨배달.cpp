#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, M,result=912345678;
vector<pair<int, int>> home, ck;
vector<vector<int>> combs, cdistance;

void generate_comb(vector<int> singlecomb, int start) {
	if (singlecomb.size() == M) {
		int thisComb = 0; // addup
		
		for (vector<int> distancesForHome : cdistance) {

			int ckDforthisHome=918273465;
			for (int index : singlecomb) {
				ckDforthisHome = min(ckDforthisHome, distancesForHome[index]);
			}
			thisComb += ckDforthisHome;
		}

		result = min(result, thisComb);
		return;
	}

	for (int i = start + 1; i < ck.size(); i++) {
		singlecomb.push_back(i);
		generate_comb(singlecomb, i);
		singlecomb.pop_back();
	}

	return;
}

int main() {
	cin >> N>> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) home.push_back({ i,j });
			else if (temp == 2) ck.push_back({ i,j });
		}
	}

	for (pair<int, int> home_yx : home) {
		vector<int> distanceforsinglehome;
		for (pair<int, int> ck_yx : ck) {
			int distance = abs(home_yx.first - ck_yx.first) + abs(home_yx.second - ck_yx.second);
			distanceforsinglehome.push_back(distance);
		}
		cdistance.push_back(distanceforsinglehome);
	}// 미리 거리 계산 후 저장
	

	vector<int> temp;
	generate_comb(temp, -1);
	cout << result;
	


	return 0;
}