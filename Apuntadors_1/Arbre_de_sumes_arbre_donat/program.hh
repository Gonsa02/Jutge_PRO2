void arb_sumes_i(node_arbre* node, node_arbre* &node_sum, int &suma) const {
    if (node == nullptr) suma = 0;
    else {
	suma = node -> info;

	int sum_e, sum_d;
	node_arbre *nE, *nD;
	nE = nD = nullptr;
	arb_sumes_i(node->segE, nE, sum_e);
	arb_sumes_i(node->segD, nD, sum_d);

	suma += sum_e + sum_d;
	node_sum = new node_arbre;

	node_sum->info = suma;
	node_sum->segE = nE;
	node_sum->segD = nD;
    }
}

void arb_sumes(Arbre<int> &asum) const
/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
{
    int suma;
    node_arbre *primer = nullptr;
    arb_sumes_i(primer_node, primer, suma);
    asum.primer_node = primer;
}
