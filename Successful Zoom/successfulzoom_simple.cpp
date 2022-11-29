#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

long long determineK(vector<ll>arr, ll n) {
	ll k = 1;
	while (k <= n / 2) {		//exits loop if less than 2 integers looped through
		ll j = 1;
		while (arr[k*j-1] < arr[k*(j+1)-1]) {		//while next elem is more than prev elem (ascending), iterate through array
			++j;
			if (j >= n/k) {
				return k;
			}
		}
		++k;					//increase k by 1 if elem is descending
	}
	return 0;
}

int main() {
	ll n; cin >> n;
	vector<ll> arr(n);		//create array to store integers
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];		//array of integers created
	}
	ll output = determineK(arr, n);
	if (output == 0) {
		cout << "ABORT!";
	}
	else {
		cout << output;
	}
}

