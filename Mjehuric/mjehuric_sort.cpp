#include <iostream>
using namespace std;

int main() {
	int n = 5;
	int A[5];
	for (int i = 0; i < n; ++i) cin >> A[i];

	for (int j=0; j<n-1; ++j){
		for (int i = 0; i < n-j-1; ++i){
			if (A[i] > A[i+1]) {
				swap(A[i], A[i+1]);
				for (int k = 0; k < n; ++k)
					cout << A[k] << ' ';
				cout << " \n";
			}
		}
	}
}

