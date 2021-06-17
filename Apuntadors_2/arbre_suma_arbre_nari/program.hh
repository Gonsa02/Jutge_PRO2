int arbsuma_i(node_arbreNari* node, node_arbreNari* &node_suma) const
{
    if (node == nullptr) return 0;
    else {
	int sum = node -> info;
	node_suma = new node_arbreNari;
	node_suma -> seg = vector<node_arbreNari*>(node -> seg.size());

	for (int i = 0; i < node -> seg.size(); ++i) {
	    node_arbreNari* nou = nullptr;
	    sum += arbsuma_i(node -> seg[i], nou);
	    node_suma -> seg[i] = nou;
	}
	node_suma -> info = sum;
	return sum;
    }
}

void arbsuma(ArbreNari& asum) const
/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
{
    asum.N = this -> N;
    arbsuma_i(primer_node, asum.primer_node);
}
