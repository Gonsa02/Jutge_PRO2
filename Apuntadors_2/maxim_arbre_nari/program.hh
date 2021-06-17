static void maxim_rec(node_arbreNari* node, T& max) {
    if (node != nullptr) {
	for (int i = 0; i < node -> seg.size(); ++i) maxim_rec(node -> seg[i], max);
	if (max < node -> info) max = node -> info;
    }
}

T maxim() const
/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
{
    T max = primer_node -> info;
    maxim_rec(primer_node, max);
    return max;
}
