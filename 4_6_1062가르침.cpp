#include <iostream>
#include <string>
using namespace std;
int N, K;
int words[50];
int res=0;
string s;

void check(int mask) {
	int cnt = 0;
	for (int word : words) {
		if (word && (word & mask) == word)cnt++;
	}
	res = res > cnt ? res : cnt;
}
void go(int index, int k, int masking) {
	if (k > K|| index >=26) return;
	if (k == K) {
		check(masking);
		return; }
	go(index + 1, k + 1, masking | (1 << index));
	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a')
	go(index + 1, k, masking);
}


int main() {
	cin >> N >> K;
	if (K < 5) {cout << 0; return 0;}
	else if (K == 26) { cout << N; return 0; }
	//else
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (char c : s) {
			words[i] |= (1 << (c - 'a')); // turn on c th bit of words[i], making a pattern
		}
	}
	go(0, 0, 0);
	cout << res;
	
	return 0;
}