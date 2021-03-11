#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
#include <iostream>
using namespace std;

double redondear(double r)
{  
  return int(10.*(r + 0.05)) / 10.0;
}

int main(){
    Cjt_estudiants c;
    c.llegir();
    int n;
    cin >> n;
    while (n != -6) {

	if (n == -1) {
	    Estudiant e;
	    e.llegir();
	    if (not c.existeix_estudiant(e.consultar_DNI())) {
		if (c.mida() < c.mida_maxima()) c.afegir_estudiant(e);
		else cout << "el conjunto esta lleno" << endl << endl;
	    }
	    else cout << "el estudiante " << e.consultar_DNI() <<" ya estaba" << endl << endl;
	}
	else if (n == -2) {
	    int dni;
	    cin >> dni;
	    if (c.existeix_estudiant(dni)) {
		Estudiant e = c.consultar_estudiant(dni);
		if (e.te_nota()) cout << "el estudiante " << e.consultar_DNI() << " tiene nota " << e.consultar_nota() << endl;
		else cout << "el estudiante " << e.consultar_DNI() << " no tiene nota" << endl;
	    } 
	    else cout << "el estudiante " << dni << " no esta" << endl;
	    cout << endl;
	}
	else if (n == -3) {
	    int dni;
	    double nota;
	    cin >> dni >> nota;
	    if (c.existeix_estudiant(dni)) {
		Estudiant e = c.consultar_estudiant(dni);
		if (e.te_nota()) e.modificar_nota(nota);
		else e.afegir_nota(nota);
		c.modificar_estudiant(e);
	    }
	    else cout << "el estudiante " << dni << " no esta" << endl << endl;
	}
	else if (n == -4) {
	    int num_est = c.mida();
	    for (int i = 1; i <= num_est; ++i) {
		Estudiant e = c.consultar_iessim(i);
		if (e.te_nota()) {
		    e.modificar_nota(redondear(e.consultar_nota()));
		    c.modificar_iessim(i, e);
		}
	    }
	}
	else if (n == -5) {
	    c.escriure();
	    cout << endl;
	}
	cin >> n;
    }
}
