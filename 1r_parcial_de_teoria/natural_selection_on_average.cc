#include <list>
using namespace std;

void seleccio(const list<double> &l, list<double> &sel) {
    double suma_total = 0;
    int i = 0;
    list<double>::const_iterator const_it = l.begin();
    sel.push_back(*const_it);
    suma_total += *const_it;    
    ++const_it, ++i;
    while (const_it != l.end()) {
	if (not(*const_it < (suma_total/i))) sel.push_back(*const_it);
	suma_total += *const_it;
	++i;
	++const_it;
    }
}
