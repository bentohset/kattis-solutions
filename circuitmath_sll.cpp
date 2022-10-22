#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);

    int n; cin >> n;
    vector<bool> val(n, false);
    for (int i = 0; i < n; i++) {
        char TF; cin >> TF;
        val[i] = (TF == 'T');
    }

    stack<char> s;
    char token;
    while (cin >> token) {          //need to press ctrl+z == signify end of input
        bool operand1, operand2;
        if (token == '-') {     //negation
            operand1 = s.top(); s.pop();
            s.push(!operand1);          //push back negation of s1
        }
        else if ((token == '*') || (token == '+')) {        //* == OR, + == AND
            operand2 = s.top(); s.pop();
            operand1 = s.top(); s.pop();
            if (token == '*') s.push(operand1 & operand2);
            else s.push(operand1 | operand2);
        }
        else {      //input is an alphabet
            s.push(val[token - 'A']);   //'A' is index 0, if token is A - 'A'==0; B-'A' == 1

        }
    }
    cout << (s.top() ? 'T' : 'F') << endl;          //if top is T print T; if top is F print F
    return 0;
}