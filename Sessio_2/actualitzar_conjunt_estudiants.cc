#include <iostream>
#include <vector>
#include <algorithm>
#include "Cjt_estudiants.hh"
using namespace std;

int main() {
    Cjt_estudiants c1, c2;
    c1.llegir();
    c2.llegir();

    for (int i = 0; i < c2.mida(); ++i) {
	Estudiant e1 = c1.consultar_iessim(i+1);	
	Estudiant e2 = c2.consultar_iessim(i+1);	
	if (e1.te_nota()) {
	    if (e2.te_nota() and e2.consultar_nota() > e1.consultar_nota()) c1.modificar_iessim(i+1, e2);
	}
	else if (e2.te_nota()) c1.modificar_iessim(i+1, e2);
    }

    c1.escriure();
}
