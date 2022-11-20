#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

class UnionFind {                         
private:
  vector<int> p, rank, setSize;                       
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                         
    setSize.assign(N, 1);                    
    numSets = N;                              
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                
    int x = findSet(i), y = findSet(j);        
    if (rank[x] > rank[y]) swap(x, y);          
    p[x] = y;                                   
    if (rank[x] == rank[y]) ++rank[y];         
    setSize[y] += setSize[x];                
    --numSets;                                
  }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main(){
    fast_cin();
    int T; cin >> T;
    while (T--){
        int M, C; cin >> M >> C;
        int E = C*(C-1)/2;
        vector<tuple<int,int,int>> EL(E);
        for (int x = 0; x < E; x++){
            int i, j, D; cin >> i >> j >> D;
            EL[x] = {D,i,j};
        }
        //kuskal's algorithm
        sort(EL.begin(), EL.end());
        int mst_cost = 0; 
        int taken=0;
        UnionFind UF(C);
        for (int i=0; i<E; i++){
            auto [w,u,v] = EL[i];
            if (UF.isSameSet(u,v)) continue;
            mst_cost += w;
            UF.unionSet(u,v);
            ++taken;
            if (taken== C-1) break;
        }
        //if minimum distance is less than or equal to milk minus C, yes
        if (mst_cost<=M-C) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}