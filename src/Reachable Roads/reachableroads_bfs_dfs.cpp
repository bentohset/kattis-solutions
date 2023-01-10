#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<vector<int>> AL;
vector<bool> visited;

void dfs(int u) {
    visited[u] = 1;
    for (auto& v : AL[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int>q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        int s = q.front();
        q.pop();
        for(auto adj: AL[s]){
            if(!visited[adj]){
                visited[adj]=true;
                q.push(adj);
            }
        }
    }
}
//count connected components
int main(){
    fast_cin();
    int n; cin >> n;
    while (n--){
        int m; cin >> m;
        int r ; cin >> r;
        AL.assign(m,vector<int>());
        while (r--){
            int a, b; cin >> a >> b;
            AL[a].push_back(b);
            AL[b].push_back(a);
        }
        visited.clear();
        visited.assign(m,0);
        int CC = 0;
        for (int u=0; u<m; u++){
            if (!visited[u]){
                ++CC;
                dfs(u);
            }
        }
        cout << CC-1 << endl;
    }
    return 0;
}