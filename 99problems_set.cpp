#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
    fast_cin();
    int N, Q; cin >> N >> Q;
    multiset<int> s;
    while (N--){
        int D; cin >> D;
        s.insert(D);
    }
    while (Q--){
        int T, Di; cin >> T >> Di;
        if (T == 1){
            auto it  = s.upper_bound(Di);
            if (it == s.end()) cout << -1 << endl;
            else{
                cout << *it << endl;
                s.erase(it);
            }
        }
        if (T == 2){
            auto it = s.upper_bound(Di);
            if (it != s.begin()) --it;
            if (Di < *it || it == s.end()) cout << -1 << endl;
            else{
                cout << *it << endl;
                s.erase(it);
            }
        }
    }
    return 0;
}