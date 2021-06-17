#include "LlistaIOint.hh"
using namespace std;

int main() {
    Llista<int> c1,c2;

    llegir_llista_int(c1, -1);

    c2 = c1;
    escriure_llista_int(c2);
}
