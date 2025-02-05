#include <iostream>
#include <queue>
#include<vector>
using namespace std;

bool tab[101];
int lst[101];
queue<int> qs[101];
int res;
int main() {
	int N, K;
	cin >> N >> K;

	if (K <= N) { cout << 0; return 0; }

	for (int i = 0; i < K; i++) {
		cin >> lst[i];
		qs[lst[i]].push(i);
	}
	vector<int> plugged;
	for (int i = 0; i < K;i++) {
		int nn = lst[i]; qs[nn].pop();
		if (tab[nn]) { continue; }
		if (plugged.size() < N) {
			plugged.push_back(nn);
			tab[nn] = true;
		}
		else { // 자리없고 내 숫자가 없을때
			int latest = -1;
			int latestIndex=0;
			for (int j = 0; j < plugged.size();j++) {
				int number = plugged[j];
				if (qs[number].empty()) {
					latestIndex = j;
					break;
				}
				if (qs[number].front() > latest) {
					latest = qs[number].front();
					latestIndex = j;
				}
			}
			tab[plugged[latestIndex]] = false;
			res++;
			plugged.erase(plugged.begin()+latestIndex);
			plugged.push_back(nn);
			tab[nn] = true;
		}
	}
	cout << res;
	return 0;
}