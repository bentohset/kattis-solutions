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
	}
	stable_sort(arr.begin(), arr.end());

	int Q; cin >> Q;

	for (int i = 0; i < Q; i++) {
		int lower, upper;
		cin >> lower >> upper;
		int firstIndex = lower_bound(arr.begin(), arr.end(), lower) - arr.begin();
		int lastIndex = upper_bound(arr.begin(), arr.end(), upper) - arr.begin();
		int freq = lastIndex - firstIndex;
		cout  << freq;
	}
	return 0;
}
