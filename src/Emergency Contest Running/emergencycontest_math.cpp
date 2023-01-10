#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int main(){
    fast_cin();
    ll n, k; cin >> n >> k;
    ll e = n-1;         //no. of edges
    ll path = k;
    if (e/k>1){
        //if e/k > 1, at least one additional path exists
        path+= e%k +1;      //edges with no additional path (remaining on the right) + 1 (shortened path) + k (remaining on the left)
    }
    else{
        //if e/k <= 1, no additional paths so shortest path is no. of edges
        path = e;
    }
    cout << path << endl;
    return 0;
}