#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

//Kahn's algorithm for toposort
int topoSort(int startingLab, int n, vector<int> inDegree, vector<vector<int>> AL, vector<int>lab){
    //greedily process all steps in certain lab before alternating to other lab
    //vector of queues - lab 1 in q[1], lab 2 in q[2] aka q[lab[i]]
    vector<queue<int>> q;
    q.assign(2,queue<int>());

    //push all indegree=0 into queue
    for (int i=0; i<n; i++){
        if (inDegree[i]==0){
            q[lab[i]].push(i);
        }
    }

    int currentLab = startingLab;
    int alternate = 0;    // only when jump from 1 lab to another, increase counter
    while(!q[0].empty() || !q[1].empty()){      //until all nodes are processed
        while(!q[currentLab].empty()){
            int s = q[currentLab].front();
            q[currentLab].pop();
            for (auto adj: AL[s]){
                if (--inDegree[adj]==0){
                    q[lab[adj]].push(adj);
                }
            }
        }
        //swap current lab when everything in currentlab is processed
        if (currentLab == 0) currentLab = 1;
        else currentLab = 0;
        alternate++;
    }
    return alternate-1;     //dont include last jump, deduct 1
}

int main(){
    fast_cin();
    int T; cin >> T;    //no. of test cases
    while(T--){
        int n, m; 
        cin >> n >> m;
        
        // indexing for lab id for nodes
        vector<int> lab(n);
        for (int i=0; i<n; i++){
            int x; cin >> x;        //lab number
            x--;      //change to 0-based indexing
            lab[i] = x;
        }

        //input into adjacency list DS
        vector<vector<int>> AL;
        AL.assign(n,vector<int>());
        vector<int> inDegree(n,0);
        for (int i=0;i<m;i++){
            int u, v;
            cin >> u >> v;
            u--;v--;        //change to 0-based indexing
            // can only move from u to v
            AL[u].push_back(v);
            inDegree[v]++;
        }

        //find min no. of times painting needs to be transported between labs (do as much work in one lab then pass to next and so on)
        //if neighbour is same lab cannot traverse, prioritises indegree=0 nodes aka toposort
        //compare between starting in lab1 and starting in lab2
        int start1 = topoSort(0,n,inDegree,AL,lab);
        int start2 = topoSort(1,n,inDegree,AL,lab);
        cout << min(start1, start2) << endl;
    }
    return 0;
}