#include <iostream>
using namespace std;

int main() {

	int n, f;
	cin >> n >> f;
	for (int i = 0; i < n; ++i) {
		int x, total = 0;
		cin >> x;
		while (x != f) {
			total += x;
			cin >> x;
		}
		string s;
		getline(cin, s);
		cout << "La suma de la secuencia " << i+1 << " es " << total << endl;
	}
}
