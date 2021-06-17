 void esborrar_tots(const T& x)
 /* Pre: parametre implicit = P */
 /* Post: s'han eliminat del parametre implicit totes les aparicions d'x (la
    resta d'elements queda en el mateix ordre que a P); si el punt d'interes de P
    referenciava a una aparicio d'x, passa a referenciar al primer element
    diferent d'x posterior a aquesta (si no hi ha cap element diferent d'x, passa
    a la dreta el tot); en cas contrari, el punt d'interes no canvia */
{
    node_llista *it, *aux;
    it = aux = primer_node;
    while (it != NULL) {
	if (it -> info == x) {
	    if (act == it) act = act -> seg;
	    
	    node_llista *anterior = it;
	    it = it -> seg;

	    if (anterior == primer_node) primer_node = aux = it;
	    else if (anterior == ultim_node) {
		ultim_node = aux;
		aux -> seg = NULL;
	    }
	    else {
		aux -> seg = it;
		it -> ant = aux;
	    }
	    delete anterior;
	    --longitud;
	}
	else {
	    aux = it;
	    it = it -> seg;
	}
    }
}
