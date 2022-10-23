#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
#include <unordered_set>
#include <stack>
using namespace std;

unordered_set<string> visited;
unordered_map<string,vector<string>> AL;
stack<string> ans;

void dfs(string u){
    visited.insert(u);
    for (auto& v: AL[u]){
        if (visited.find(v)==visited.end())
            dfs(v);
    }
    ans.push(u);
}
//output connected nodes
int main(){
    int n; cin >> n;
    for (int i=0; i<=n; i++){
        string line; getline(cin,line);
        //cout << line << endl;
        stringstream ss(line);
        string f;
        ss >> f; f.pop_back();
        //cout << f << endl;
        string dependency;
        while (ss >> dependency){
            AL[dependency].push_back(f);
            //cout << f << "->" << dependency << endl;
        }
    }
    string c; cin >> c;
    visited.clear();
    dfs(c);
    while (!ans.empty()){
        cout << ans.top()<< endl;
        ans.pop();
    }
    
    return 0;
}