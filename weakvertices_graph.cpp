#include <iostream>
#include <vector>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)



int main(){
    fast_cin();
    int n; //no. of graphs
    while (cin >> n && n!=-1){
        vector<vector<int>> graph(n, vector<int>(n));
        for (int i = 0; i < n; i++){        //input into graph
            for (int j = 0; j < n; j++){
                cin >> graph[i][j];
            }
        }
        for (int i=0; i < n; i++){
            bool weak = true;
            for (int j = 0; j < n; j++){
                for (int k = 0; k < n; k++){
                    if (graph[i][j] == 1 && graph[i][k] == 1 && graph[j][k] == 1 && i!=j && i!=k && j!=k) weak = false;
                }
            }
            if (weak) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}