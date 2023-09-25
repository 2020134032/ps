#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//��͸� �̿��� ���

int a[] = {1, 2, 3, 4};
int n = 4, r = 3;
//n - �տ��� �? r-��ܰ����
// ���ǻ���:  ������� ������ ����!

void print() {
	for (int i = 0; i < r; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";

}

void spaces(int w) {
	for (int i=0; i < w;i++) {
		cout << " * ";
	}
}

void makePermutation(int n, int r, int depth) {
	if (r == depth) {
		print();
		return;
	}
	for (int i = depth; i < n; i++) {
	//	spaces(depth); cout<< i << " -> " << depth << "\n";
		swap(a[i], a[depth]);

	//	spaces(depth);
		makePermutation(n, r, depth + 1);
		
	//	spaces(depth); cout << i << " <- " << depth << "\n";
		swap(a[i], a[depth]);
	}
	return;
}

int main() {

	makePermutation(n, r, 0);

	return 0;
}