void  reorganitzar_in(const T& x)
/* Pre: p.i. = L */
/* Post: el p.i. conté els mateixos elements que L però
reorganitzats de manera que primer apareixen els més petits
o iguals que x, en el mateix ordre que en L, seguits pels 
més grans que x, en el mateix ordre que en L.
L'element actual del p.i. és el primer del més grans que x, si
existeix, sinó es situa a la dreta de tot */
{
    Llista<T> l;
    if (longitud == 0) return;
    l.longitud = longitud;
    l.act = l.primer_node = l.ultim_node = NULL;
    node_llista *ult_menors = NULL;
    node_llista* it = primer_node;

    while (it != NULL) {
	if (it -> info <= x) {
	    if (l.primer_node == NULL) {
		l.primer_node = new node_llista;	
		l.primer_node -> ant = NULL;
		ult_menors = l.primer_node;
	    }
	    else {
		ult_menors -> seg = new node_llista;	
		ult_menors -> seg -> ant = ult_menors;
		ult_menors = ult_menors -> seg;
	    }
	    ult_menors -> info = it -> info;
	}
	else {
	    if (l.ultim_node == NULL) {
		l.ultim_node = l.act = new node_llista;
		l.act -> ant = NULL;
	    }
	    else {
		l.ultim_node -> seg = new node_llista;
		l.ultim_node -> seg -> ant = l.ultim_node;
		l.ultim_node = l.ultim_node -> seg;
	    }
	    l.ultim_node -> info = it -> info;
	}
	it = it -> seg;
    }
    if (l.primer_node == NULL) l.primer_node = l.act;
    else if (l.act == NULL) l.ultim_node = ult_menors;
    else {
	ult_menors -> seg = l.act;
	l.act -> ant = ult_menors;
    }
    l.ultim_node -> seg = NULL;
    *this = l;
}
