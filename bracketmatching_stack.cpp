#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
    fast_cin();
    int n; cin >> n;
    string str; cin >> str; cout << str << endl;
    stack<char> stack;
    for (char c : str){
        if (c == '{' || c == '[' || c== '('){
            stack.push(c);
        }
        else if ((c == '}' && stack.top()=='{') || (c == ']' && stack.top()=='[')|| (c == ')'&& stack.top()== '(')) 
            stack.pop();
        else {
            stack.push(c);
        }
    }
    if (stack.empty()){
        cout << "Valid";
    }
    else cout << "Invalid";
}