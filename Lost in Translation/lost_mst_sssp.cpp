#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef tuple<int,int,int> iii;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int INF = 1e9;

int main(){
    fast_cin();
    unordered_map<string,int> idx;      //to enumerate languages
    int v, e; cin >> v >> e;
    vector<vii> AL(v+1, vii());
    vector<int> taken(v+1,0);
    // store languages(string) into map as indices(integer) for ez graphing
    for (int i=1; i<=v; i++){
        string a;
        cin >> a;
        idx[a] = i;
    }
    string lang1, lang2;
    int cost;
    while(e--){
        cin >> lang1 >> lang2 >> cost;
        int i = idx[lang1];
        int j = idx[lang2];
        AL[i].push_back({j,cost});
        AL[j].push_back({i,cost});
    }
    // find min spanning tree but focus on shortest path
    // if graph is connected return cost, else impossible
    // mix of prim's algo and sssp
    priority_queue<iii, vector<iii>, greater<iii>> pq;      // min pq of tuple (distance, cost, node), sort by min distance then cost
    pq.push({0,0,0});
    int res = 0;
    while (!pq.empty()){
        auto [d,w,u] = pq.top(); pq.pop();
        if(taken[u]) continue;
        res += w;
        taken[u] = 1; 
        for (auto &[v, w] : AL[u]){               
            if (taken[v]) continue;       
            pq.push({d+1,w, v});            //increment distance by 1 for priority
        }
    }
    bool connected = true;
    // check if all nodes are taken implying connected
    for (auto i: taken){
        if (!i) connected = false;
    }
    // if connected return res, else impossible
    if (connected) cout << res << endl;
    else cout << "Impossible" << endl;
    return 0;
}