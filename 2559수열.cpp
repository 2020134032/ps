#include <iostream>
using namespace std;

int main() {
	int n, k, max=0, sum=0;
	cin >> n >> k;

	int* arr = new int[n];

	for (int i = 0; i < k;i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	max = sum;

	if (n == k) {
		cout << max;
		return 0;
	} 
	for (int i = k; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		sum -= arr[i - k];
		max = sum > max ? sum : max;
	}
	cout << max;

	return 0;
	

}