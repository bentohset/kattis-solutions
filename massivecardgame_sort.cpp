#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int>arr(N);
	for (int i = 0; i < N; i++) {
		int cards; cin >> cards;
		arr[i] = cards;
		//cout << arr[i]; test
	}
	//cout << '\n'; formatting for test
	stable_sort(arr.begin(), arr.end());

	//for (int i = 0; i < N; i++) cout << arr[i];	//print sorted array
	////cout << '\n';

	int Q; cin >> Q;

	//vector<int>counts(Q);
	for (int i = 0; i < Q; i++) {
		int lower, upper;
		cin >> lower >> upper;
		int firstIndex = lower_bound(arr.begin(), arr.end(), lower) - arr.begin();
		int lastIndex = upper_bound(arr.begin(), arr.end(), upper) - arr.begin();
		int freq = lastIndex - firstIndex;
		cout  << freq;
	}
	/*for (int i = 0; i < Q; i++)
		cout << counts[i] << '\n';*/
	return 0;
}
