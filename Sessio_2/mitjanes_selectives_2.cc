#include "Estudiant.hh"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const Estudiant& a, const Estudiant& b) {
    if (a.consultar_nota() != b.consultar_nota()) return a.consultar_nota() > b.consultar_nota();
    return a.consultar_DNI() < b.consultar_DNI();
}

int main() {
    int num_e, num_not, num_assig;
    cin >> num_e >> num_not >> num_assig;
    vector<int> assig(num_assig);
    vector<Estudiant> e(num_e);
    for (int i = 0; i < num_assig; ++i) cin >> assig[i];
    for (int i = 0; i < num_e; ++i) {
	int dni;
	cin >> dni;
	double nota = 0;
	vector<double> notes(num_not);
	for (int i = 0; i < num_not; ++i) cin >> notes[i];
	for (int i = 0; i < assig.size(); ++i) nota += notes[assig[i]-1];
	nota /= assig.size();
	e[i] = Estudiant(dni);
	e[i].afegir_nota(nota);
    }
    sort(e.begin(), e.end(), compare);
    for (int i = 0; i < num_e; ++i) e[i].escriure();
}
