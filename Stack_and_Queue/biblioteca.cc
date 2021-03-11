#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n, op;
    cin >> n >> op;
    vector<stack<string>> v(n);
    while (op != -4) {
	int category;
	if (op == -1) {
	    string title;
	    cin >> title >> category;
	    v[category-1].push(title);
	}
	else if(op == -2) {
	    int del;
	    cin >> del >> category;
	    for (int i = 0; i < del; ++i) v[category-1].pop();
	}
	else if (op == -3) {
	    cin >> category;
	    cout << "Pila de la categoria " << category << endl;
	    stack<string> s(v[category-1]);
	    while (not s.empty()) {
		cout << s.top() << endl;
		s.pop();
	    }
	    cout << endl;
	}
	cin >> op;
    }
}
