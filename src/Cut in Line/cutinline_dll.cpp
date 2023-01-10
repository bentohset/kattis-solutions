#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main() {
	int N; cin >> N;		//size of list
	list<string> LA;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		LA.push_back(name);
	}
	int actions; cin >> actions;		//no. of actions
	for (int j = 0; j < actions; j++) {
		string actionName;
		cin >> actionName;
		if (actionName == "cut") { //cut1 cuts in front of cut2
			string cut1, cut2;
			cin >> cut1;
			cin >> cut2;
			auto it = find(LA.begin(),LA.end(), cut2);
			LA.insert(it, cut1);
		}
		if (actionName == "leave") {
			string leaver; cin >> leaver;
			LA.remove(leaver);
		}
	}
	while (!LA.empty()){
		cout << LA.front() << endl;
		LA.pop_front();
	}
	return 0;
}