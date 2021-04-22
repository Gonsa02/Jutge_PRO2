#include <iostream>
#include <set>
using namespace std;

int main() {
    set<string> cap, aux, totes;
    string nom;
    while (cin >> nom and nom != ".") cap.insert(nom);
    totes = cap;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	aux = totes;
	while (cin >> nom and nom != ".") {
	    cap.erase(nom);
	    aux.erase(nom);
	}
	for (set<string>::const_iterator const_it = aux.begin(); const_it != aux.end(); ++const_it) totes.erase(*const_it);
    }
    cout << "Totes les activitats:";
    for (set<string>::const_iterator it = totes.begin(); it != totes.end(); ++it)
	cout << " " << *it;
    cout << endl;
    cout << "Cap activitat:";
    for (set<string>::const_iterator it = cap.begin(); it != cap.end(); ++it)
	cout << " " << *it;
    cout << endl;
}
