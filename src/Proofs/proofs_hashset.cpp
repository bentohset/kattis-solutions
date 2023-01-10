#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

int main(){
    fast_cin();
    int n; cin >> n;
    unordered_set<string> proven;
    for (int line = 1; line <= n+1; ++line){
        string l; getline(cin, l);
        stringstream ss(l);
        string token;   //token is assumption
        while (ss >> token && token!= "->"){
            if (proven.find(token) == proven.end()){
                cout << line-1 << endl;
                return 0;
            }
        }
        string conclusion;
        ss >> conclusion;
        proven.insert(conclusion);
    }
    cout << "correct" << endl;
    return 0;
}