#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool compareColumn1(vector<int>& v1, vector<int>& v2) {		//compare etime first, if tied then stime
	if (v1[1] != v2[1]) return v1[1] < v2[1];
	else return v1[0] < v2[0];
}

int main(){
    fast_cin();
    int G, N; cin >> G >> N;    //G = no. of task to do in first day; N = no. of possible tasks
    //compare tasks and see if they can fit into day 0 to 24000
    //if doable tasks <= G, cout YES
    vector<vector<int>> arr(N,vector<int>(2));
    for (int i=0; i<N;i++){
        int stime,etime; cin >> stime >> etime;
        arr[i][0] = stime;
        arr[i][1] = etime;
    }
    sort(arr.begin(), arr.end(),compareColumn1);
    int count =1;
    int i = 0;
    int j = 1;
    while (i<N && j<N){                  //compare stime of next row with etime of current row
        if (arr[j][0] >= arr[i][1]){       //if within time range, change comparing row and iterate to next row
            i=j;
            j++;
            count++;
        }
        else{
            j++;
        }
    }
    if (count >= G) cout << "YES"<< endl;
    else cout << "NO"<< endl;

    return 0;
}