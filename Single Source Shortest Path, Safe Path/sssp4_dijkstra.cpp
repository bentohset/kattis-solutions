#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<vector<ii>> AL;
vector<int> dist;
queue<iii> que;

const int INF = 1e9;

int main(){
    fast_cin();
    int TC; cin>> TC;
    while (TC--){
        int V; cin >> V;
        AL.clear();
        AL.assign(V,vector<ii>());
        dist.clear();
        dist.assign(V,INF);
        for (int i=0; i<V; i++){
            int X; cin >> X;
            while (X--){
                int v,w; cin >> v >> w;
                AL[i].push_back(make_pair(v,w));
            }
        }
        int Q; cin >> Q;
        while (Q--){
            int s,t,k; cin >> s >> t >> k;
            //find SP from s to t within k nodes
            //modified dijkstra
            dist.assign(V, INF);
            dist[s] = 0;
            //use queue of tuple (jumps,node,weight)
            que.push({1, s, 0});
            while (!que.empty()) {               
                auto [jumps, u, d] = que.front(); que.pop();    
                //if jumps exceed distance, dont push into queue  
                //only include nodes in the queue that are less than k neighbours away from start
                if (jumps<k){      
                    for (auto &[v, w] : AL[u]) {              
                        if (d+w >= dist[v]) continue;
                        //higher weight might use lesser nodes, modify relaxation 
                        dist[v] = w+d;      
                        //push into q and increment jump counter            
                        que.push({jumps+1, v, dist[v]});                     
                    }
                }
            }
            if (dist[t]==INF) cout << -1 << endl;
            else cout << dist[t] << endl;
        }  
        cout << endl;
    }  
    return 0;
}
    
