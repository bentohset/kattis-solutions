#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

unordered_map<string, vector<string>> AL;
unordered_map<string, int> visited;
bool cyclepresent;

void dfs(string u) {
    visited[u] = 1; //explored
    for (auto& v : AL[u]){
        if (visited[v]==0){ //unvisited
            dfs(v);
        }
        else if (visited[v]==1){    //explored
            cyclepresent = true;
        }
    }
    visited[u] = 2;     //fully visited
}
//check if cyclic
int main(){
    fast_cin();
    int n; cin >> n;
    while (n--){
        string o, d; cin >> o >> d;
        AL[o].push_back(d);
    }
    string start;
    while(cin >> start){
        if (cin.eof()) break;
        cyclepresent = false;
        visited.clear();
        dfs(start);
        if (cyclepresent) cout << start << " safe" << endl;
        else cout << start << " trapped" << endl;
    }
    return 0;
}