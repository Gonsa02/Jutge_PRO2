void sub_arrel_rec(node_arbre* m, node_arbre* &ns, const T& x, int dist, int& min_dist) {
    if (m != NULL) {
	if (min_dist == -1 or dist < min_dist) {
	    if (m->info == x) {
		min_dist = dist;
		ns = m;
	    }
	    ++dist;
	    sub_arrel_rec(m->segE, ns, x, dist, min_dist);
	    sub_arrel_rec(m->segD, ns, x, dist, min_dist);
	}
    }
}

/* Pre: p.i. = A, asub es buit */
/* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
   si A no conte x, asub es buit */
void sub_arrel(Arbre& asub, const T& x) {
    int dist = 0;
    int min_dist = -1;
    node_arbre* aux;
    sub_arrel_rec(primer_node, aux, x, dist, min_dist);
    asub.primer_node = copia_node_arbre(aux);
}
