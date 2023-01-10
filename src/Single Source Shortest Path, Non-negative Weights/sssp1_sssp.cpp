#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<vector<ii>> AL;
vector<int> dist;
const int INF = 1e9;

int main(){
    fast_cin();
    bool end = true;            //if input is 0 0 0 0, update this var to end loop
    while(end){
        int n,m,q,s; cin >> n >> m >> q >> s;
        if (n ==0 && m==0 && q==0 && s==0){
            end = false;
            break;
        }
        AL.clear();
        AL.assign(n,vector<ii>());
        dist.clear();
        dist.assign(n,INF);
        while (m--){
            int u, v, w; cin >> u >> v >> w;
            AL[u].push_back(make_pair(v,w));
        }
        //modified dijkstra
        priority_queue<ii,vector<ii>,greater<ii>> pq;           //pair of (distance,vertex)
        dist[s]=0;
        pq.push({0,s});
        while (!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();
            if (d>dist[u]) continue;
            for (auto &[v,w]:AL[u]){
                if (dist[u]+w >= dist[v]) continue;
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
            }
        }
        while(q--){
            int x; cin >> x;
            if (dist[x]==INF) cout << "Impossible" << endl;
            else cout << dist[x] << endl;
        }
    }
    return 0;
}