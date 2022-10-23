#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
    fast_cin();
    int n; cin >> n;
    deque<int> deque;
    vector<int> res;
    for (int i=0; i<n; i++){
        int x; cin >> x;
        deque.push_back(x);
    }
    sort(deque.begin(), deque.end());       //sort smallest to largest
    for (int i=0;i<n/2;i++){                //put elements into array in zig zag order (non-increasing difference)
        res.push_back(deque.front());
        res.push_back(deque.back());
        deque.pop_front();
        deque.pop_back();
    }
    if (deque.size()==1) res.push_back(deque.front());      //account for middle element
    reverse(res.begin(), res.end());        //reverse into non-decreasing order
    for (auto i: res) cout << i << " ";
    return 0;
}