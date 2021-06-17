void freq_i(const T& x, node_arbreGen* node, int& num) const
{
    if (node != nullptr) {
	if (node -> info == x) ++num;
	for (int i = 0; i < node -> seg.size(); ++i) freq_i(x, node -> seg[i], num);
    }
}

int freq(const T& x) const
/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
{
   int num = 0;
   freq_i(x, primer_node, num);
   return num;
}
