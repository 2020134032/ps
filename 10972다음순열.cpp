#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	} // fill

	if (next_permutation(arr, arr+n)) {
		for (int i = 0;i < n;i++) {
			cout << arr[i] << " ";
		}
	}
	else
		cout << -1;
		
	return 0;
}