#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
    fast_cin();
    int N; cin >> N;
    vector<int> difficulty;
    for (int i=0; i<N; i++){
        int w; cin >> w;
        difficulty.push_back(w);
    }
    //find lowest difficulty of city
    //sum remaining difficulties with that minimum difficulty
    sort(difficulty.begin(), difficulty.end());
    ll sum = 0;
    for (int i=1; i<N; i++){
        sum+= difficulty[0]+difficulty[i];
    }
    cout << sum << endl;
    return 0;
}