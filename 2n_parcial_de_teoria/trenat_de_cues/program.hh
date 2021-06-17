void trenat(Cua &c)
 /* Pre: p.i. = C1, c = C2 */
 /* Post: el p.i. passa a ser el resultat de trenar C1 i C2; c passa a ser buida */
{
    if (primer_node == NULL) {
	primer_node = c.primer_node;
	ultim_node = c.ultim_node;
	longitud = 0;
    }
    else {
	node_cua* n1 = primer_node;
	node_cua* n2 = c.primer_node;
	node_cua *seg_n1, *seg_n2;

	while (n1 != nullptr and n2 != nullptr) {
	    seg_n1 = n1 -> seguent;
	    seg_n2 = n2 -> seguent;

	    n2 -> seguent = seg_n1;
	    n1 -> seguent = n2;
	    if (seg_n1 == NULL) n2 -> seguent = seg_n2;

	    n1 = seg_n1;
	    n2 = seg_n2;
	}
    }
    longitud += c.longitud;
    c.primer_node = NULL;
    c.ultim_node = NULL;
    c.longitud = 0;
}
