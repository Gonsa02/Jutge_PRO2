void  reorganitzar_in(const T& x)
/* Pre: p.i. = L */
/* Post: el p.i. conté els mateixos elements que L però
reorganitzats de manera que primer apareixen els més petits
o iguals que x, en el mateix ordre que en L, seguits pels 
més grans que x, en el mateix ordre que en L.
L'element actual del p.i. és el primer del més grans que x, si
existeix, sinó es situa a la dreta de tot */
{
    node_llista* act = primer_node;
    // Localitzem el node amb la info = x i el deixem apuntat per act
    while (act != nullptr and act -> info != x) act = act -> seg;
    node_llista* iterador = primer_node;
    bool first_half = true;
    while (act != nullptr and iterador != nullptr) {
	if (iterador -> info == x and first_half) {
	    first_half = false;
	    iterador = iterador -> seg;
	}
	else {
	    if ((iterador -> info < x and first_half) or (iterador -> info > x and not first_half)) iterador = iterador -> seg;
	    else if (iterador -> info <= x and not first_half) {
		node_llista* aux = iterador;
		iterador = iterador -> seg;
		aux -> ant -> seg = aux -> seg;
		if (aux -> seg != nullptr) aux -> seg -> ant = aux -> ant;
		else ultim_node = aux -> ant;
		// aux -> seg = node amb x
		aux -> seg = act;
		// aux -> ant = node anterior al node amb x
		aux -> ant = act -> ant;
		// arreglem els punters que hi ha entre el node amb x i el que abans era l'anterior
		if (aux -> ant != nullptr) aux -> ant -> seg = aux;
		else primer_node = aux;
		aux -> seg -> ant = aux;
	    }
	    else if (iterador -> info > x and first_half) {
		node_llista* aux = iterador;
		iterador = iterador -> seg;
		if (aux -> ant != nullptr) aux -> ant -> seg = aux -> seg;
		else primer_node = iterador;
		aux -> seg -> ant = aux -> ant;
		aux -> ant = ultim_node;
		aux -> seg = nullptr;
		aux -> ant -> seg = aux;
		ultim_node = aux;
	    }
	}
    }
    while (act != nullptr and act -> info <= x) act = act -> seg;
    if (act == nullptr) act = primer_node;
}
