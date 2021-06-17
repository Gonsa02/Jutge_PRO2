#include "Llista.hh"
#include "LlistaIOint.hh"
#include <iostream>
using namespace std;

int main() {
    Llista<int> l;
    llegir_llista_int(l, -1);
    int x;
    cin >> x;
    l.esborrar_tots(x);
    escriure_llista_int(l);
}
