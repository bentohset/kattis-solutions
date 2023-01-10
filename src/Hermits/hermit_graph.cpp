#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool sortsecond(const vector<int>& a, const vector<int>& b){
    return a[1] < b[1];
}

int main(){
    fast_cin();
    int N; cin >> N;
    vector<vector<int>> weight;     //vector of [city,weight]
    vector<vector<ii>> AL(N);
    for (int i=0; i<N; i++){
        int w; cin >> w;
        vector<int> v;
        v.push_back(i+1);
        v.push_back(w);
        weight.push_back(v);
    }
    int M; cin >> M;
    for (int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        AL[a-1].push_back(make_pair(b, weight[b-1][1]));
        AL[b-1].push_back(make_pair(a, weight[a-1][1]));
    }
    //sum weights for adjacent nodes
    for (int i=0; i<N; i++){
        for (int j=0; j< AL[i].size(); j++){
            weight[i][1] += AL[i][j].second;
        }
    }
    stable_sort(weight.begin(),weight.end(),sortsecond);
    cout << weight[0][0] << endl;
    return 0;
}
//find lowest weight after summing connected vertices