#include "Cjt_estudiants.hh"
#include <iostream>
using namespace std;

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &b)
{
    b = false;
    int pos = cerca_dicot(vest, 0, nest-1, est.consultar_DNI());
    if (est.consultar_DNI() == vest[pos].consultar_DNI()) b = true;
    if(not b) {
	++nest;
	for (int i = nest-1; i > pos; --i) vest[i] = vest[i-1];
	vest[pos] = est;
	if (est.te_nota()) {
	    suma_notes += est.consultar_nota();
	    ++nest_amb_nota;
	}
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool &b)
{
    b = false;
    int pos = cerca_dicot(vest, 0, nest-1, dni);
    if (pos>=0 and pos < nest and vest[pos].consultar_DNI() == dni) {
	b = true;
	if (vest[pos].te_nota()) {
	    --nest_amb_nota;
	    suma_notes -= vest[pos].consultar_nota();
	}
	for (int i = pos+1; i < nest; ++i) vest[i-1] = vest[i];
	--nest;
    }
}

