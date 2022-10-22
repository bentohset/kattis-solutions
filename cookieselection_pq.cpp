#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
    fast_cin();
    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int> max;
    string cmd;
    while (cin>>cmd){
        if (cmd == "#"){
            if (max.empty() && min.empty()) continue;
            //query
            if (min.size()==max.size()){        //if same size, cout mintop
                cout << min.top() << endl;
                min.pop();
            }
            else{           //if diff size (max > min size) cout maxtop
                cout << max.top() << endl;
                max.pop();
            }
        }
        else{   //cmd == number
            int num = stoi(cmd);
            if (max.empty()) max.push(num);    //starting, if empty push to max
            else if (num > max.top()){         //if num > max, push to min
                min.push(num);
                if (min.size()>max.size()) {    //balance 2 pq
                    max.push(min.top());
                    min.pop();
                }
            }
            else {      // if num < max top
                max.push(num);
                if (max.size()> min.size()+1){    //balance 2 pq
                    min.push(max.top());
                    max.pop();

                }
            }
        }
    }
    return 0;
}