#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int N;
stack<pair<int, int>> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	long long res = 0; // ¼öÁ¤ int -> ll
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		int dup = 1;

		while (!s.empty() && s.top().first < a) {
			res += s.top().second; s.pop();
		}
		if (!s.empty() && s.top().first == a) {
			dup += s.top().second; // = -> +=
			res += s.top().second;
			s.pop();
		}
		if (!s.empty()) res++;

		s.push({ a,dup });

	}



	cout << res;



	return 0;
}