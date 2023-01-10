#include <iostream>
#include <vector>
using namespace std;

int main() {
	int P; cin >> P;
    while (P--){
        int K; cin >> K; cout << K << ' ';
        int count = 0;
        vector<int> array(20);
        for (int i = 1; i < 21; ++i){
            cin >> array[i];
            int j = i - 1;
            while (array[j+1] < array[j] && (j >= 0)) {
                swap(array[j + 1],array[j]);
                ++count;
                --j;
            }
        }
        cout << count << endl;
    }
    return 0;
}