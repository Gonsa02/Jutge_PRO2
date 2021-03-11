#include "Estudiant.hh"
#include <iostream>
#include <vector>
using namespace std;

/* Leer vector */
void leer_vector_est(vector<Estudiant>& v) {// version accion
  int numEst;
  cin >> numEst;
  v = vector<Estudiant> (numEst);
  
  for (int i=0; i<numEst;++i)
    v[i].llegir();
}

/* Escribir vector */
void escribir_vector_est(const vector<Estudiant>& v) {
  for (int i=0; i<v.size();++i)
    v[i].escriure();
}

//Pre: A l'entrada hi ha un vector que conte Estudiants
//Post: Retorna un vecto amb la classe Estudant en la que nomes hi ha l'estudiant i la nota maxima de cada estudiant
vector<Estudiant> simpl_vec(const vector<Estudiant>& v) {
  vector<Estudiant> v_s;
  int i = 0;
  while (i < v.size()) {
    Estudiant e(v[i].consultar_DNI());
    if (v[i].te_nota()) e.afegir_nota(v[i].consultar_nota());
    ++i;
    while(i < v.size() and v[i].consultar_DNI() == e.consultar_DNI()) {
      if (v[i].te_nota() and not e.te_nota()) e.afegir_nota(v[i].consultar_nota());
      else if (v[i].te_nota() and v[i].consultar_nota() > e.consultar_nota()) e.modificar_nota(v[i].consultar_nota());
      ++i;
    }
   v_s.push_back(e);
  }
  return v_s;
}

int main() {
  vector<Estudiant> vec;
  leer_vector_est(vec);
  vector<Estudiant> vec_simp = simpl_vec(vec);
  escribir_vector_est(vec_simp);
}
