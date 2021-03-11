#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> s;
	char c;
	cin >> c;
	bool correct= true;
	while(correct and c != '.') {
		if (c == '(' or c == '[') s.push(c);
		else if (c == ')' and not s.empty() and s.top() == '(') s.pop();
		else if (c == ']' and not s.empty() and s.top() == '[') s.pop();
		else correct = false;
		cin >> c;
	}
	if (correct and s.empty()) cout << "Correcte" << endl;
	else cout << "Incorrecte" << endl;
} 
