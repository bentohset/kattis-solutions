#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

double euDist(ll x1, ll y1, ll x2, ll y2) {		//calculate euclidian distance between 2 coordinates
	ll x = x2 - x1;
	ll y = y2 - y1;
	double dist = sqrt(pow(x, 2) + pow(y, 2));
	//cout << dist << endl;
	return dist;
}

bool compareColumn(vector<ll>& v1, vector<ll>& v2) {		//compare last column
	return v1[3] < v2[3];
}

bool compareColumn1(vector<ll>& v1, vector<ll>& v2) {		//compare first column
	return v1[0] < v2[0];
}

bool compareColumn2(vector<ll>& v1, vector<ll>& v2) {		//compare second column
	return v1[1] < v2[1];
}

bool compareColumn3(vector<ll>& v1, vector<ll>& v2) {
	if (v1[0] != v2[0]) return v1[0] < v2[0];
	else return v1[1] < v2[1];
}

int main() {
	ll P; ll N;  //P = total no. of players; N = total number of pings
	cin >> P >> N;
	vector<vector<ll>> arr(N, vector<ll> (4));			//array of pings
	vector<vector<ll>> pairings;	//array for pair of players who cross paths
	for (ll i = 0; i < N; ++i) {		//input 2d array
		ll player, x, y, time; cin >> player >> x >> y >> time;
		arr[i][0] = player;
		arr[i][1] = x;
		arr[i][2] = y;
		arr[i][3] = time;
	}

	sort(arr.begin(), arr.end(), compareColumn); //sort pings by time (last column)
	//cout << "sorted!" << endl;
	//for (int i = 0; i < N; i++) {		//print array for checking
	//	for (int j = 0; j < 4; j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	ll limit = 0;
	for (ll i = 1; i < N; i++) {					//if pairs cross paths, add to new array "pairings"
		if (i - limit == 5) limit++;
		for (ll j = i - 1; j >= limit; --j) {
			if (arr[i][0] != arr[j][0] && arr[i][3] - arr[j][3] <= 10 && euDist(arr[j][1], arr[j][2], arr[i][1], arr[i][2]) <= 1000) {
				vector<ll>rows;
				ll p1 = arr[i][0];
				ll p2 = arr[j][0];
				//cout << p1 << ' ' << p2 << endl;
				if (p1 > p2) {
					ll temp = p2;
					p2 = p1;
					p1 = temp;
					rows.push_back(p1);
					rows.push_back(p2);
					pairings.push_back(rows);
				}
				else{
					rows.push_back(p1);
					rows.push_back(p2);
					pairings.push_back(rows);
				}
			}
		}
	}
	
	sort(pairings.begin(), pairings.end(), compareColumn3);		//sort pairings
	//sort(pairings.begin(), pairings.end(), compareColumn2);
	pairings.erase(unique(pairings.begin(), pairings.end()), pairings.end());

	cout << pairings.size() << endl;

	for (ll i = 0; i < pairings.size(); i++) {			//print array
		for (ll j = 0; j < pairings[0].size(); j++) {
			cout << pairings[i][j] << " ";
		}
		cout << endl;
	}
}