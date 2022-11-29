#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_cin();
	int N, t; cin >> N >> t;
	vector<int> arr;
	for (int i = 0; i < N; ++i) {
		int x; cin >> x;
		arr.push_back(x);
	}
	if (t == 1) {
		//if any sum of 2 integers in array == 7777 && 2 integers not equal, cout << yes
		//else cout << no
		unordered_set<int> set;
		for (auto i: arr){
			int temp = 7777-i;
			if (set.find(temp)!= set.end()){
				cout << "Yes" << endl;
				return 0;
			}
			set.insert(i);
		}
		cout << "No" << endl;
		return 0;
	}

	if (t == 2) {
		//if array is unique, cout << unique
		//else cout << duplicate
		stable_sort(arr.begin(),arr.end());
		bool flag = false;
		for (int i=0; i<arr.size(); i++){
			if (arr[i] == arr[i+1]) flag = true;
		}
		if (flag) cout << "Contains duplicate" << endl;
		else cout << "Unique" << endl;
		return 0;
	}

	if (t == 3) {
		//if an integer recurs >N/2 times, cout << integer
		//else cout << -1
		int freq = N/2;
		unordered_map<int,int> mp;
		for (auto i: arr){
			mp[i]++;
		}
		for (auto i: mp){
			if (i.second > freq){
				cout << i.first << endl;
				return 0;
			}
		}
		cout << -1 << endl;
	}

	if (t == 4) {
		stable_sort(arr.begin(),arr.end());
		//if odd(N), cout << median middle value
		if (N%2 == 1){
			int midIdx = (N-1)/2;
			cout << arr[midIdx];
		}
		//if even(N), cout << median1 << ' ' << median2
		else if (N%2 == 0){
			int midIdx = N/2;
			cout << arr[midIdx-1] << ' ' << arr[midIdx];
		}
		return 0;
	}

	else if (t == 5) {
		//if 100 <=A[i]<=999, sort(arr), cout<<arr
		stable_sort(arr.begin(),arr.end());
		auto lb = lower_bound(arr.begin(), arr.end(), 100);
		auto ub = upper_bound(arr.begin(), arr.end(), 999);
		for (auto it =  lb; it != ub; ++it) cout << *it << ' ';
		return 0;
	}
}
