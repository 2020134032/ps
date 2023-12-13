#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int N;
vector<int> pp; 
vector<vector<int>> adj;
int visited[11];
int arr[20], result=9e8;

pair<int, int> dfs(int here, int val) {
		visited[here] = 1;
		pair<int, int> ret = { 1,pp[here-1] };
		for(int there : adj[here-1]){
			if (arr[there] != val || visited[there]) continue;
			pair<int, int> _temp = dfs(there, val);
			ret.first += _temp.first;
			ret.second += _temp.second;
	}
		return ret;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		pp.push_back(temp);
	}

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		vector<int> v;
		for (int j = 0; j < temp; j++) {
			int temp2;
			cin >> temp2;
			v.push_back(temp2);
		}
		adj.push_back(v);
	}

	for (int i = 1; i < (1 << N)-1; i++) {

		 fill(arr, arr + 20, 0);fill(visited, visited + 11, 0);
		int idx1, idx2;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				arr[j + 1] = 1; idx1 = j + 1;
			}
			else idx2 = j + 1;
		}

		pair<int, int> p1= dfs(idx1, 1);
		pair<int, int> p2= dfs(idx2, 0);
		if (p1.first + p2.first == N) result = min(result, abs(p1.second - p2.second));
	}
	cout << (result == 9e8 ? -1 : result) << "\n";

	return 0;
}