#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
int main(){
    fast_cin();
    //always annoy the most generous fren, then update their level, keep doing this until K times.
    int h, c; cin >> h >> c;
    priority_queue<ii, vector<ii>,greater<ii>> pq;  //store - first: next possible a+d, second: d
    ll res = INT_MIN;
    for (int i=1; i<= c; i++){
        ll a,d; cin >> a >> d;
        res = max(res,a);
        ii temp = make_pair(a+d,d); 
        pq.push(temp);
    }
    while (h-- && !pq.empty()){     //update level to new a+d
        ll curA = pq.top().first;
        ll curD = pq.top().second;          //find min a+d
        pq.pop();
        res = max(res,curA);           //update max if higher current annoyance with prev value of a
        ii temp = make_pair(curA+curD,curD);
        pq.push(temp);
    }
    cout << res << endl;
    return 0;
}