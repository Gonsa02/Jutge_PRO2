#include <iostream>
#include <list>
using namespace std;

void esborrar(list<int>& l, int n, bool& found) {
    list<int>::iterator it = l.begin();
    while (not found and it != l.end()) {
	if (*it == n) it = l.erase(it), found = true;
	else ++it;
    }
}

void recalcular_min_max(const list<int>& l, int& min, int& max) {
    list<int>::const_iterator const_it = l.begin();
    min = *const_it;
    max = *const_it;
    ++const_it;
    while (const_it != l.end()) {
	if (*const_it < min) min = *const_it;
	if (*const_it > max) max = *const_it;
	++const_it;
    }
}

int main() {
    list<int> l;
    int codi, nombre, min, max, suma_total = 0;
    cin >> codi >> nombre;
    while (codi != 0 or nombre != 0) {
	if (codi == -1) {
	    if (l.empty()) max = min = nombre;
	    l.push_back(nombre);
	    if (nombre < min) min = nombre;
	    if (nombre > max) max = nombre;
	    suma_total += nombre;
	}
	else if (codi == -2) {
	    bool found = false;
	    esborrar(l, nombre, found);
	    if (found) {
		if (l.size() > 0 and (nombre == min or nombre == max)) recalcular_min_max(l, min, max);
		suma_total -= nombre;
	    }
	}
	double mitjana = double(suma_total)/l.size();
	if (l.size() > 0) cout << min << ' ' << max << ' ' << mitjana << endl;
	else cout << '0' << endl;
	cin >> codi >> nombre;
    }
}
