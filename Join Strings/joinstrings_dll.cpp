#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
    fast_cin();
    int N; cin >> N;
    vector<list<string>> lst(N);
    for (int i=0; i< N; i++){
        string s; cin >> s;
        lst[i].push_back(s);
    }

    int x = N-1;
    //a = a+b
    //b = ''
    while (x--){
        int a, b; cin >> a >> b;
        a--; b--;
        lst[a].splice(lst[a].end(),lst[b]);
    }
    for (int i=0; i< N; i++){
        for (string s: lst[i]){
            cout << s;
        }
    }
    return 0;
}