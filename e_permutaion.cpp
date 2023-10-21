#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 1. next_permutation이용한 방법

void printV(vector<int>& v) {
	for (int i=0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

void reverseV(vector<int>& v) {
	if (v.size() <= 1)
		return;
	for (int i = 0; i < v.size() / 2;i++) {
		int temp = v[i];
		v[i] = v[v.size() - 1 - i];
		v[v.size() - 1 - i] = temp;
	}
		// 2- [0]까지 스왑하려면 i <1
		// 3- 0
		// 4- 1
		// 5- 1
		// 6- 2
		// 7- 2
}

int main() {
	int a[] = { 2, 3, 4, 5, 1};
	vector<int> v;

	for (int i : a) {
		cout << i << endl;
		v.push_back(i);
	} 

	do {
		printV(v);
	} while (next_permutation(v.begin(), v.begin() + 5));
	// 앞에 두개까지만 순열. 그리고 next permutation = 23451
	cout << "- next permutation after \"false\" " << '\n';
	printV(v);
	cout << " -will reverse -- " << '\n';
	reverseV(v);
	do {
		printV(v);
	} while (prev_permutation(v.begin(), v.end()));
	cout << " ------------ " << '\n';
	

	
	

	return 0;
}