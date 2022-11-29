#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

int main(){
    fast_cin();
    ll n,m; cin >> n >> m;      //n == number of nights, m == number of slimes after n nights
    int ans = 0;
    while (m>0){
        if (m%2 == 0) m=m/2;
        else if (m%2 == 1) {
            m = m/2;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}