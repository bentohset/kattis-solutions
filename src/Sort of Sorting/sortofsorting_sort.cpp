#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b){
	if (a[0] != b[0]) return a[0] < b[0];
	return a[1] < b[1];
}

int main(){
	int n;
	while (cin>>n){
		vector<string> names(n);
		for (int i = 0; i < names.size(); i++) cin >> names[i];

		stable_sort(names.begin(),names.end(), compare);

		for (string name: names) cout << name << endl;
		cout << endl;
	}
	return 0;
}