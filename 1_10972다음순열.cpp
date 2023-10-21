#include<iostream>
#include<algorithm>

using namespace std;

template<typename It> //iterator (pointer)
bool my_next_permutation(It begin, It end) {
	/*https://stackoverflow.com/questions/11483060/stdnext-permutation-implementation-explanation
	*
	* 1234, 1243, 1324,1342
	* for any index i, notice if every element right to i is in decreasing order, it is time we move on to the next sequence. 
	* e.g.) 1'2'43 -> all element next to 2 is decreasing in decreasing order
	* the condition *i < *(i+1) indicates we need to 'swap' i with the least biggest element that is right to index i.
	* e.g.) 1'2'43 -> 3 is the least biggest element than 2
	* swapped -> 1'3'42 (notice how even after swapping next to the index i is in decreasing order.)
	* now reverse(i+1,end)
	* we get next permutation
	*/
	if (begin == end)
		return false;

	It i = end;
	i--;
	if (begin == i)
		return false;

	i--;
	while( !(*i < *(i+1)) ){
		i--;
		if (i < begin)
			return false;
	}
	It k = end;
	while (!(*i < *(--k)))
		;//pass
	swap(*i, *k);
	reverse(i + 1, end);
	return true;

}

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	} // fill

	if (my_next_permutation(arr, arr+n)) {
		for (int i = 0;i < n;i++) {
			cout << arr[i] << " ";
		}
	}
	else
		cout << -1;
		
	return 0;
}