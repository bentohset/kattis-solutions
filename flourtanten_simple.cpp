#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ll n; cin >> n;
	ll max;
	ll happ=0;
	vector<ll>arr(n);
	arr[0] = 0;

	for (ll j = 1; j < n; ++j) {
		ll num; cin >> num;
		if (num == 0) {
			cin >> num;
		}
		arr[j] = num;		//input into array with Bjorn in front
		happ += num * (j + 1);		//calculate happinness when Bjorn in front
	}
	max = happ;
	for (ll i = 1; i < n; ++i) {
		happ -= arr[i];		//when Bjorn swaps to the next position, total happiness drops by the same value
		if (happ > max) {
			max = happ;
		}
	}
	cout << max;
}
