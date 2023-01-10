#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
  fast_cin();
  int N, K; cin >> N >> K;
  unordered_map<int,int> mp;
  priority_queue<int> pq;
  int n;
  while (cin >> n){   //insert into map, (element, freq)
    mp[n]++;
  }
  for (auto x: mp){   //insert frequencies into priority queue
    pq.push(x.second);
  }
  while (K--){
    int extract = pq.top();
    pq.pop();
    pq.push(extract-1);
  }
  cout << pq.top();
  return 0;
}

//always remove highest number and update their level, do K times