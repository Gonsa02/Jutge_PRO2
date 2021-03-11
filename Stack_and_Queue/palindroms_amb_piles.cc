#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s;
	int n, add, i = 0;
	cin >> n;
	while (i < n/2) {
		cin >> add;
		s.push(add);	
		++i;
	}
	if (n%2 != 0) cin >> add, ++i;
	bool palindrome = true;
	while (palindrome and i < n) {
		cin >> add;
		if (s.top() != add) palindrome = false;
		s.pop();
		++i;
	}
	cout << (palindrome ? "SI" : "NO") << endl;
}
