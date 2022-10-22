#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int main(){
    fast_cin();
    int N; cin >> N;
    map<int, priority_queue<int>> pool;
    while (N--){
        string cmd; cin >> cmd;
        if (cmd == "add"){
            int E, G; cin >> E >> G;
            if (pool.find(E) == pool.end()){        //if energy cost doesnt exist in pool, create new pq and add key,value
                priority_queue<int> pq;
                pq.push(G);
                pool[E] = pq;
            }
            else pool[E].push(G);           //if energy alr exists, find key and push new value into pq
            
        }
        else{       //if cmd== query
            int X; cin >> X;
            ll gold = 0;
            
            while (X>0){
                auto it = pool.upper_bound(X);
                if (it != pool.begin()) it--;
                
                //cout << "it=" << it->first << endl;
                if (it==pool.end() || X < it->first) break;
                X = X - it->first;
                //cout << "x= " << X << endl;
                gold = gold + pool[it->first].top();
                //cout << "gold=" << gold << endl;
                pool[it->first].pop();
                if (pool[it->first].empty()) pool.erase(it);
            }
            cout << gold << endl;       
        }
    }
    return 0;
}