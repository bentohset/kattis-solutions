#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int main(){
    fast_cin();
    int n; cin >> n;
    vector<int> res;
    vector<int> sorted;
    map<int,int> mp;
    int count = 0;
    for (int i =0; i < n;i++){
        int job; cin >> job;
        res.push_back(job);
    }
    sorted = res;
    stable_sort(sorted.begin(),sorted.end());
    for (int i =0; i< n; i++){
        mp[res[i]] = i;
    }
    for (int i =0; i<n; i++){
        if (res[i]!=sorted[i]){
            count++;
            int curPos = res[i];
            int corPos = mp[sorted[i]];
            swap(res[i],res[corPos]);
            mp[curPos] = corPos;
            mp[sorted[i]] = i;
        }
    }
    cout << count << endl;
    return 0;
}