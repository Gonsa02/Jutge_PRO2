Llista  reorganitzar_out(const T& x) const
/* Pre: cert */
/* Post: el resultat és una llista que conté els mateixos 
elements que el p.i. tal que tots els més petits o iguals 
que x al p.i. precedeixen als més grans que x al p.i. però 
sempre respectant l'ordre que hi havia entre ells al p.i. 
L'element actual de la llista retornada és el primer dels 
més grans que x, si existeix, sinó es situa a la detra del 
tot. El p.i. no es modifica */
{
    Llista l;
    l.longitud = longitud;
    l.act = l.primer_node = l.ultim_node = nullptr;
    node_llista* aux = nullptr;
    node_llista* aux_act = primer_node;

    while (aux_act != nullptr) {
	if (aux_act -> info <= x) {
	    if (l.primer_node == nullptr) {
		aux = l.primer_node = new node_llista;
		l.primer_node -> ant = nullptr;
	    }
	    else {
		aux -> seg = new node_llista;
		aux -> seg -> ant = aux;
		aux = aux -> seg;
	    }
	    aux -> info = aux_act -> info;
	}
	else {
	    if (l.ultim_node == nullptr) {
		l.ultim_node = l.act = new node_llista; 
		l.ultim_node -> seg = nullptr;
	    }
	    else {
		l.ultim_node -> seg = new node_llista;
		l.ultim_node -> seg -> ant = l.ultim_node;
		l.ultim_node = l.ultim_node -> seg;
	    }
	    l.ultim_node -> info = aux_act -> info;
	}
	aux_act = aux_act -> seg;
    }
    if (l.primer_node == nullptr) l.primer_node = l.act;
    else if (l.act == nullptr) l.ultim_node = aux;
    else {
	aux -> seg = l.act;
	l.act -> ant = aux;
    }
    return l;
}
