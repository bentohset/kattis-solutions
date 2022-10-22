#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

int main(){
    fast_cin();
    int N,M; ll P; cin >> N >> M >> P;
    vector<int> crank(N);
    for (auto& cranki : crank) cin >> cranki;
    vector<int> back(M);
    for (auto& backi : back) cin >> backi;

    vector<double> ratios;
    for (int i=0; i<N;i++){
        for (int j=0; j<M;j++){
            double ratio = (double)crank[i]/back[j];
            ratios.push_back(ratio);
        }
    }
    bool ride = true;
    sort(ratios.begin(), ratios.end(), greater<double>());
    /* for (int i=0; i< ratios.size();i++){
        cout << ratios[i]<< endl;} */

    for (int i=0; i< ratios.size()-1;i++){
        if ((100.0*(ratios[i]-ratios[i+1])/ratios[i+1])>P) {
            //out << 100.0*(ratios[i]-ratios[i+1])/ratios[i+1] << endl;
            ride = false;
        }
    }
    if (ride) cout << "Ride on!" << endl;
    else cout << "Time to change gears!" << endl;
    return 0;
}