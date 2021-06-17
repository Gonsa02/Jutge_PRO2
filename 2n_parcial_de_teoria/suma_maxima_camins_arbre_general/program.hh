T max_suma_cami_i(node_arbreGen* a) const
{
    if (a == nullptr) return 0;
    else {
	T max = 0;
	for (int i = 0; i < a -> seg.size(); ++i) {
	    T aux = max_suma_cami_i(a -> seg[i]);
	    if (aux > max) max = aux;
	}
	return a -> info + max;
    }
}

T max_suma_cami() const
 /* Pre: el parametre implicit no es buit */
 /* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
{
   return max_suma_cami_i(primer_node);
}
