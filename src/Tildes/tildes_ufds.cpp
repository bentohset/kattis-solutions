#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef vector<int> vi;

class UnionFind {                            
private:
  vi p, rank, setSize;                         
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

  int numDisjointSets() { return numSets; }    
  int sizeOfSet(int i) { return setSize[findSet(i)]; } 

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;              
    int x = findSet(i), y = findSet(j);         
    if (rank[x] > rank[y]) swap(x, y);          
    p[x] = y;                                  
    if (rank[x] == rank[y]) ++rank[y];          
    setSize[y] += setSize[x];                  
    --numSets;                                 
  }
};

int main(){
    fast_cin();
    int n,q; cin >> n >> q;
    UnionFind UF(n);
    while(q--){
        string cmd; cin >> cmd;
        if (cmd == "t"){
            int a, b; cin >> a >> b; --a; --b;
            UF.unionSet(a,b); 
        }
        else{
            int a; cin >> a; --a;
            cout << UF.sizeOfSet(a) << endl;
        }
    }
    return 0;
}