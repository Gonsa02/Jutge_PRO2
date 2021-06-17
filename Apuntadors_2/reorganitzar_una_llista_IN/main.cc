#include "LlistaIOint.hh"
#include <iostream>
using namespace std;

int main() {
    Llista<int> l;
    llegir_llista_int(l, -1);
    int x;
    cin >> x;
    l.reorganitzar_in(x);
    escriure_llista_int(l);
}
