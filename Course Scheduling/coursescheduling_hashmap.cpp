#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int main(){
    fast_cin();
    int n; cin >> n;
    unordered_map<string, set<string>> mp;
    while (n--){
        string first, last, course;
        cin >> first >> last >> course;
        string fullname = first + last;
        mp[course].insert(fullname);           //use both first and last
    }
    vector<string> res;
    for (auto courses: mp) res.push_back(courses.first);
    stable_sort(res.begin(), res.end());
    for (auto i: res){
        cout << i <<' ' << mp[i].size() << endl;
    }
    return 0;
}