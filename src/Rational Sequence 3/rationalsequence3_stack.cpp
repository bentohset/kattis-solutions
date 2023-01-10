#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int parent(int i) { return i>>1; } //same as i/2
int left(int i) { return i<<1; } //same as i*2
int right(int i) { return (i<<1)+1; } //same as i*2+1

int main(){
    fast_cin();
    int P; cin >> P;
    while (P--){
        int K, N; cin >> K >> N;
        int p = 1;
        int q = 1;
        stack<char> s;
        while (N>1){                //input traversal order from bottom up into a stack
            int par = parent(N);
            if (N == left(par)) s.push('L');
            else if (N==right(par)) s.push('R');
            N = parent(N);
        }
        while (!s.empty()){         //reverse traversal order to top down
            if (s.top() == 'L') q= p+q;             //if traverse left, q
            else if (s.top() == 'R') p = q+p;       //if traverse right, p
            s.pop();
        }
        cout << K << " " << p << "/" << q << endl;
    }
    return 0;
}