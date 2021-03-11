#include "Estudiant.hh"
#include <vector>

pair<int,int>  max_min_vest(const vector<Estudiant>& v)
/* Pre: v no conte repeticions de dni  */
/* Post: si existeix a v algun estudiant amb nota, la primera component del
resultat es la posicio de l'estudiant de nota maxima de v i la segona
component es la posicio de l'estudiant de nota minima de v (si hi ha
empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
hi ha cap estudiant amb nota, totes dues components valen -1 */
{
   pair<int,int> p;
   p.first = -1;
   p.second = -1;
   pair<double,double> nota;
   nota.first = -1;
   nota.second = -1;
   for (int i = 0; i < v.size(); ++i) {
	   if (v[i].te_nota()) {
		  if (p.first == -1 or v[i].consultar_nota() > nota.first) {
			  p.first = i;
			  nota.first = v[i].consultar_nota();
		  }
		  else if (v[i].consultar_nota() == nota.first and v[i].consultar_DNI() < v[p.first].consultar_DNI()) {
			  p.first = i;
			  nota.first = v[i].consultar_nota();
		  }
		  if (p.second == -1 or v[i].consultar_nota() < nota.second) {
			  p.second = i;
			  nota.second = v[i].consultar_nota();
		  }
		  else if (v[i].consultar_nota() == nota.second and v[i].consultar_DNI() < v[p.second].consultar_DNI()) {
			  p.second = i;
			  nota.second = v[i].consultar_nota();
		  }
	   }
   }
   return p;
}
