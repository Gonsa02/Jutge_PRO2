#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;
    string operation, politician;
    while (cin >> operation >> politician) {
	map<string,int>::iterator it = m.find(politician);
	if (operation == "a") {
	    if (it == m.end()) m.insert(make_pair(politician,1));
	    else it -> second++;
	}
	else if (operation == "f") {
	    if (it == m.end()) cout << "0" << endl;
	    else cout << it -> second << endl;
	}
	else if (operation == "e") {
	    if (it != m.end()) {
		if (it -> second != 0) it -> second--;
		else m.erase(it);
	    }
	}
    }
}
