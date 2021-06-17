bool buscar_i(const T& x, node_arbreGen* node) const
{
    if (node != nullptr) {
	if (node -> info == x) return true;
	else {
	    vector<node_arbreGen*> v = node -> seg;
	    for (int i = 0; i < v.size(); ++i) {
		bool found = buscar_i(x, v[i]);
		if (found) return true;
	    }
	}
    }
    return false;
}

bool buscar(const T& x) const
/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
{
    return buscar_i((x), primer_node);
}
