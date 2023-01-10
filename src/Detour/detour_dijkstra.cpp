#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int INF = 1e9;

int main(){
    fast_cin();
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> AL(n);
    vector<tuple<int,int,int>> EL(m);
    while (m--){
        int a,b,d;
        cin >> a >> b >> d;
        AL[a].push_back({b,d});
        AL[b].push_back({a,d});
        EL.push_back({a,b,d});
    }
    //modified dijkstra to find distance from 1 (amsterdam)
    vector<int> dist(n, INF); 
    dist[1] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0,1});
    while (!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();
        if (d>dist[u]) continue;
        for (auto &[v,w]: AL[u]){
            if (dist[u] +w >= dist[v]) continue;
            dist[v] = dist[u]+w;
            pq.push({dist[v],v});
        }
    }
    //create new AL without shortest path from each node to the dest
    //remove if dist[v] = dist[u] - weight for edge (u->v), shortest path to dest
    vector<vector<int>> AL2(n);     //bfs no need weight
    for (auto &[u,v,w]: EL){
        if (dist[u]!=dist[v]-w) AL2[v].push_back(u);
        if (dist[v]!=dist[u]-w) AL2[u].push_back(v);
    }
    //bfs to store parent array and print traversal
    vector<int> p(n,-1);
    vector<int> vis(n,0);
    queue <int> q;
    q.push(0);
    vis[0] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if (u == 1) break;
        for (auto v: AL2[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            p[v] = u;
            q.push(v);
        }
    }

    // if no path to 1 is found
    if (p[1] == -1) cout << "impossible" << endl;
    //print traversal path in reverse order
    else{
        stack<int> ans;
        int start = 1;
        while (p[start] != -1){
            ans.push(start);
            start = p[start];
        }
        ans.push(start);
        cout << ans.size() << " ";
        while(!ans.empty()){
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }
    return 0;
}