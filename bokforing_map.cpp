#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
    fast_cin();
    int N, Q; cin >> N >> Q;
    map<int,int> mp;
    int base;
    while (Q--){
        string cmd; cin >> cmd;
        if (cmd == "SET"){
            int i, x; cin >> i >> x;
            mp[i] = x;
        }
        else if (cmd == "RESTART"){
            int x; cin >> x;
            base = x;
            mp.clear();
        }
        else{       //print
            int x; cin >> x;
            if (mp.find(x) == mp.end()){
                cout << base << endl;
            }
            else cout << mp[x] << endl;
        }
    }
    return 0;
}

