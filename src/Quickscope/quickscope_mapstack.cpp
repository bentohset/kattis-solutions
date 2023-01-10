//stack of unordered sets
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <set>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
    fast_cin();
    int N; cin >> N;
    unordered_map<string, stack<string>> mp;        //map of id and latest type
    stack<unordered_map<string,string>> st;     //stack with layers of id and type
    unordered_map<string,string> empt;
    st.push(empt);
    while (N--){
        string cmd; cin >> cmd;
        if (cmd == "DECLARE"){
            string id, type; cin >> id >> type;
            if (st.top().count(id)) {
                cout << "MULTIPLE DECLARATION" << endl;
                return 0;
            }
            else {
                mp[id].push(type);
                st.top()[id] = type;
            }
        }
        if (cmd == "TYPEOF"){
            string id; cin >> id;
            if (mp[id].empty()) cout << "UNDECLARED"<< endl;
            else cout << mp[id].top() << endl;
        }

        if (cmd == "{"){            //add new layer in stack of maps
            unordered_map<string, string> b;
            st.push(b);
        }
        if (cmd == "}"){        //run thru current layer of stack and delete its elements in the map also, then pop
            for (auto key: st.top()){
                mp[key.first].pop();
            }
            st.pop();
        }
    }
    return 0;
}