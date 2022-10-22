#include <iostream>
using namespace std;

typedef long long ll; //shorten name to ll, 64bit

int main() {
    int T; cin >> T;
    while (T--) {       //loop thru number of planets, T
        ll P, R, F; cin >> P >> R >> F;    //check for overflow, int cannot handle value of 10^9
        int year = 0;
        while (P <= F) {    //still survive
            ++year;     //go to another year
            P *= R;     //R cannot be 1
        }
        cout << year << '\n';
    }
    return 0;
}