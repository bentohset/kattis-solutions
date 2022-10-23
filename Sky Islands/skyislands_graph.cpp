#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<vector<int>> AL;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
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

int main(){
    fast_cin();
    int N,M; cin >> N >> M;
    if (M==0 && N>1){
        cout << "NO" << endl;
        return 0;
    }
    AL.assign(N,vector<int>());
    for (int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    visited.assign(N,0);
    dfs(0);
    for (int i=0 ; i<N; i++){
        if (visited[i] == false){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}